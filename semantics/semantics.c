/**
 * Compiladores 2008/2009
 *
 * Pedro Miguel de Almeida Verruma
 * verruma@student.dei.uc.pt
 * Nº 2006128853
 */

#include "semantics.h"


// **************************************************************************************************************************


char * data_type_to_string(is_data_type idt) {
    switch(idt) {
        case d_INTEGER: return "Integer";
        case d_BOOLEAN: return "Boolean";
        case d_CHAR: return "Char";
        case d_STRING: return "String";
        case d_REAL: return "Real";
    }

}


// **************************************************************************************************************************


int check_program(is_program * ip) {
    int errors = 0;

    errors += check_program_heading(ip->program_heading);
    errors += check_program_block(ip->program_block);

    return errors;
}




int check_program_heading(is_program_heading * iph) {
    return 0;
}




int check_program_block(is_program_block * ipb) {
    int errors = 0;

    errors += check_variable_declaration_part(ipb->variable_declaration_part, GLOBAL_SCOPE); // GLOBALSCOPE vars
    errors += check_function_list(ipb->function_list);
    errors += check_statement_list(ipb->statement_list, GLOBAL_SCOPE); // All these statements are in the global scope

    return errors;
}


// **************************************************************************************************************************


int check_variable_declaration_part(is_variable_declaration_part * ivdp, unsigned scope_id) {
    int errors = 0;

    is_variable_declaration_part *temp;
    for (temp = ivdp; temp != NULL; temp = temp->next) {
        errors += check_variable_declaration(temp->variable_declaration, scope_id);
    }

    return errors;
}




int check_variable_declaration(is_variable_declaration * ivd, unsigned scope_id) {
    is_var_name_list *temp;

    for (temp = ivd->var_name_list; temp != NULL; temp = temp->next) {
        table_element *new_element = insert_el(temp->var_name->var_name, ivd->data_type, scope_id);
        if (new_element == NULL) {
            printf("ERROR at line %u: symbol '%s' already defined!\n", temp->var_name->line_number, temp->var_name->var_name);
            return 1;
        }
    }

    return 0;
}


// **************************************************************************************************************************


int check_function_list(is_function_list * ifl) {
    int errors = 0;
    is_function_list *temp;


    // Check functions declarations
    for (temp = ifl; temp != NULL; temp = temp->next) {

        function_element *new_element = insert_function_symbol(temp->function->function_name->var_name);
        if (new_element == NULL) {
            printf("ERROR at line %u: symbol %s already defined!\n", temp->function->line_number, temp->function->function_name->var_name);
            return 1;
        }

        // Function name is also a variable (but a super global one!)
        table_element *new_element2 = insert_el(temp->function->function_name->var_name, temp->function->data_type, SUPER_GLOBAL);
        if (new_element2 == NULL) {
            printf("ERROR at line %u: function '%s()' already defined!\n", temp->function->line_number, temp->function->function_name->var_name);
            return 1;
        }

        errors += check_function_argument_list(temp->function->function_argument_list, temp->function->function_name, new_element->id);
        errors += check_variable_declaration_part(temp->function->variable_declaration_part, new_element->id);
    }

    // Check function body
    for (temp = ifl; temp != NULL; temp = temp->next) {
        errors += check_function(temp->function);
    }

    return errors;
}




int check_function(is_function * if_) {
    int errors = 0;

    function_element *new_element = search_function_symbol(if_->function_name->var_name);
    function_return_var_name = new_element->name;

    errors += check_statement_list(if_->statement_list, new_element->id); /* Pass local scope id */

    if (function_return_assignment == FALSE) {
        printf("ERROR at line %u: function '%s()' doesn't have a return statement (%s := <value>)!\n", if_->line_number, if_->function_name->var_name, if_->function_name->var_name);
        errors += 1;
    }

    function_return_assignment = FALSE;

    return errors;
}




int check_function_argument_list(is_function_argument_list * ifa, is_var_name * function_name, unsigned scope_id) {
    int errors = 0;

    is_function_argument_list *temp;
    for (temp = ifa; temp != NULL; temp = temp->next) {
        errors += check_function_argument(temp->function_argument, function_name, scope_id);
    }

    return errors;
}




int check_function_argument(is_function_argument * ifa, is_var_name * function_name, unsigned scope_id) {
    function_element *fe = search_function_symbol(function_name->var_name);

    is_var_name_list *temp;
    for (temp = ifa->var_name_list; temp != NULL; temp=temp->next) {

        table_element *new_element = insert_el(temp->var_name->var_name, ifa->data_type, fe->id);
        if (new_element == NULL) {
            printf("ERROR at line %u: symbol '%s' already defined!\n", ifa->line_number, temp->var_name->var_name);
            return 1;
        }

        // Update number_argument
        fe->number_arguments++;

        // Add variable position to function symbol
        function_argument_id *fai = (function_argument_id *) malloc(sizeof(function_argument_id));
        fai->id = element_position(temp->var_name->var_name, scope_id);

        if (fe->function_argument_id == NULL) {
            fe->function_argument_id = fai;
        } else {
            function_argument_id *temp;
            for (temp = fe->function_argument_id; temp->next != NULL; temp = temp->next);
            temp->next = fai;
        }
    }
}


// **************************************************************************************************************************


int check_statement_list(is_statement_list * isl, unsigned scope_id) {
    int errors = 0;

    is_statement_list * temp;
    for (temp = isl; temp != NULL; temp = temp->next) {
        errors += check_statement(temp->statement, scope_id);
    }

    return errors;
}




int check_statement(is_statement * is, unsigned scope_id) {
    int errors = 0;

    switch(is->statement_type) {
        case d_ASSIGNMENT: errors += check_assignment_statement(is->data_d1.assignment_statement, scope_id); break;
        case d_WRITELN: errors += check_writeln_statement(is->data_d1.writeln_statement, scope_id); break;
        case d_IF: errors += check_if_statement(is->data_d1.if_statement, scope_id); break;
        case d_WHILE: errors += check_while_statement(is->data_d1.while_statement, scope_id); break;
    }

    return errors;
}




int check_assignment_statement(is_assignment_statement * ias, unsigned scope_id){    
    int errors = 0;

    if (check_var_name(ias->var_name, scope_id) == 0) { // Valid symbol, change to assignment state
        table_element *te = search_el(ias->var_name->var_name, scope_id);
        assignment_data_type = te->data_type;
    } else {
        return 1; // Invalid symbol
    }

    // Check if exists at least one assignemnt for the return value
    if (scope_id > 1) { // Inside function
        if (strcmp(function_return_var_name, ias->var_name->var_name) == 0) {
            function_return_assignment = TRUE;
        }
    }

    assignment_state = ON;
    errors += check_expression(ias->expression, scope_id);
    assignment_state = OFF;

    return errors;
}



int check_function_call(is_function_call * ifc, unsigned scope_id) {
    int errors = 0;

    // Check function name
    errors += check_var_name(ifc->var_name, scope_id);

    function_element *fe = search_function_symbol(ifc->var_name->var_name);

    if (fe != NULL) {

        if (errors == 0) {
            /* Check if a := sum(); have the same type, sum is also a variable */
            table_element *te = search_el(ifc->var_name->var_name, scope_id);

            if (assignment_data_type == d_INTEGER && te->data_type == d_REAL) {
                printf("WARNING at line %u: mixing data types, '%s()' return %s but is being assign to %s!\n", ifc->line_number, ifc->var_name->var_name, data_type_to_string(te->data_type), data_type_to_string(assignment_data_type));
            } else if (assignment_data_type == d_REAL && te->data_type == d_INTEGER) {

            } else if (assignment_data_type != te->data_type) {
                printf("ERROR at line %u: mixing data types, '%s()' return %s but is being assign to %s!\n", ifc->line_number, ifc->var_name->var_name, data_type_to_string(te->data_type), data_type_to_string(assignment_data_type));
                return errors + 1;
            }

            errors += check_function_call_argument_list(ifc->function_call_argument_list, ifc, scope_id);
        }
    } else {

        printf("ERROR at line %u: function '%s()' doesn't exist!\n", ifc->line_number, ifc->var_name->var_name);
        errors += 1;
    }

    return errors;
}



int check_function_call_argument_list(is_function_call_argument_list * ifca, is_function_call * ifc, unsigned scope_id) {
    int errors = 0, number_arguments = 0;

    function_element *fe = search_function_symbol(ifc->var_name->var_name);

    table_element *te;
    is_function_call_argument_list *temp;
    function_argument_id * argument_list = fe->function_argument_id;
    int assignment_state_temp;

    for (temp = ifca; temp != NULL; temp = temp->next) {

        //temp_expression_data_type = expression_data_type;
        expression_state = ON;

        assignment_state_temp = assignment_state; // Save state
        assignment_state = OFF;

        errors += check_expression(temp->expression, scope_id);

        assignment_state = assignment_state_temp; // Return to previous state

        if (errors == 0) {
            if (argument_list != NULL) {
                te = get_element(argument_list->id);

                if (expression_data_type != te->data_type) {
                    printf("ERROR at line %u: argument #%d of '%s()' must be %s but is %s!\n", ifc->line_number, number_arguments + 1, ifc->var_name->var_name, data_type_to_string(te->data_type), data_type_to_string(expression_data_type));
                    errors += 1;
                }

                argument_list = argument_list->next;
            }
        }

        expression_data_type = d_NULL;
        expression_state = OFF;
        number_arguments++;
    }

    if (fe->number_arguments != number_arguments) {
        printf("ERROR at line %u: wrong number of arguments, '%s()' needs %d, %d provided! \n", ifc->line_number, ifc->var_name->var_name, fe->number_arguments, number_arguments);
        errors += 1;
    }
    return errors;
}



int check_writeln_statement(is_writeln_statement * iws, unsigned scope_id){
    int errors = 0;

    is_writeln_argument_list * temp;
    for (temp = iws->writeln_argument_list; temp != NULL; temp = temp->next) {
        switch(temp->writeln_argument->argument_type) {

            case d_ARG_STRING: errors += check_string(temp->writeln_argument->data_d3.string); break;

            case d_ARG_EXPRESSION:
                expression_state = ON;
                errors += check_expression(temp->writeln_argument->data_d3.expression, scope_id);
                temp->writeln_argument->data_d3.expression->data_type = expression_data_type;
                expression_data_type = d_NULL;
                expression_state = OFF;
                break;
        }
    }

    return errors;
}




int check_string(is_string *is) {
    return 0;
}




int check_expression(is_expression *ie, unsigned scope_id) {
    int errors = 0;

    switch(ie->expression_type) {
        case d_EXP_INFIX_EXPRESSION:
            errors += check_infix_expression(ie->data_d2.infix_expression, scope_id);
            break;

        case d_EXP_VAR_NAME:
            errors += check_var_name(ie->data_d2.var_name, scope_id);
            break;

        case d_EXP_DIGIT_SEQUENCE:
            errors += check_digit_sequence(ie->data_d2.digit_sequence, ie->line_number);
            break;

        case d_EXP_BOOLEAN:
            errors += check_boolean(ie->data_d2.boolean, ie->line_number);
            break;

        case d_EXP_FUNCTION_CALL:
            function_call_state = ON;
            errors += check_function_call(ie->data_d2.function_call, scope_id);
            function_call_state = OFF;
            break;
    }

    return errors;
}




int check_var_name_list(is_var_name_list * ivnl, unsigned scope_id) {
    int errors = 0;

    is_var_name_list *temp;
    for (temp = ivnl; temp != NULL; temp=temp->next) {
        errors += check_var_name(temp->var_name, scope_id);
    }

    return errors;
}




int check_var_name(is_var_name * ivn, unsigned scope_id) {
    table_element *te = search_el(ivn->var_name, scope_id);

    if (te == NULL) {
        printf("ERROR at line %u: symbol '%s' not declared!\n", ivn->line_number, ivn->var_name);
        return 1;
    }

    if (expression_state == ON) {
        if (expression_data_type == d_NULL) {
            expression_data_type = te->data_type;
        } else {

            if (expression_data_type == d_INTEGER && te->data_type == d_REAL) {
                printf("WARNING at line %u: mixing data types, '%s' %s with %s at expression level!\n", ivn->line_number, ivn->var_name, data_type_to_string(te->data_type), data_type_to_string(expression_data_type));
            } else if (expression_data_type == d_REAL && te->data_type == d_INTEGER) {
                // r + i, no problem
            } else {
                if (expression_data_type != te->data_type) {
                    printf("ERROR at line %u: mixing data types, '%s' %s with %s at expression level!\n", ivn->line_number, ivn->var_name, data_type_to_string(te->data_type), data_type_to_string(expression_data_type));
                    return 1;
                }
            }

        }
    }

    if (assignment_state == ON) {
        if (assignment_data_type == d_INTEGER && te->data_type == d_REAL) {
            printf("WARNING at line %u: symbol '%s' is not %s! (Precision loss)\n", ivn->line_number, ivn->var_name, data_type_to_string(assignment_data_type));
        } else if (assignment_data_type == d_REAL && te->data_type == d_INTEGER) {
            // Saving real := int, no problem
        } else {
            if (assignment_data_type != te->data_type) {

                if (search_function_symbol(ivn->var_name) == NULL) {
                    printf("ERROR at line %u: symbol '%s' is being assign to %s but is %s!\n", ivn->line_number, ivn->var_name, data_type_to_string(assignment_data_type), data_type_to_string(te->data_type));
                } else {
                    printf("ERROR at line %u: function '%s()' is being assign to %s but is %s!\n", ivn->line_number, ivn->var_name, data_type_to_string(assignment_data_type), data_type_to_string(te->data_type));
                }

                return 1;
            }
        }
    }

    return 0;
}




int check_digit_sequence(is_digit_sequence * ids, unsigned line_number) {
    is_data_type converted_data_type = ids->type == d_DIGSEQ_INTEGER ? d_INTEGER : d_REAL;

    if (expression_state == ON) {
        if (expression_data_type == d_NULL) {
            expression_data_type = converted_data_type;
        } else {
            if (expression_data_type != converted_data_type) {
                if (expression_data_type == d_BOOLEAN) {
                    printf("ERROR at line %u: mixing data types, Boolean with %s at expression level!\n", line_number, data_type_to_string(converted_data_type));
                    return 1;
                } else if (!(expression_data_type == d_REAL && converted_data_type == d_INTEGER)) {
                    if (converted_data_type == d_INTEGER) {
                        printf("WARNING at line %u: mixing data types, '%d' (%s) with %s at expression level!\n", line_number, ids->data.digit_sequence, data_type_to_string(converted_data_type), data_type_to_string(expression_data_type));
                    } else {
                        printf("WARNING at line %u: mixing data types, '%f' (%s) with %s at expression level!\n", line_number, ids->data.float_digit_sequence, data_type_to_string(converted_data_type), data_type_to_string(expression_data_type));
                    }
                }
            }
        }
    }

    if (assignment_state == ON) {
        if (assignment_data_type == d_INTEGER && ids->type == d_DIGSEQ_FLOAT) { // Send Warning
            printf("WARNING at line %u: symbol '%f' is not %s! (Precision loss)\n", line_number, ids->data.float_digit_sequence, data_type_to_string(assignment_data_type));
        }
        
        if (assignment_data_type == d_BOOLEAN) { // Error, can assign number to boolean
            printf("ERROR at line %u: can't assign %s to Boolean!\n", line_number, data_type_to_string(converted_data_type));
            return 1;
        }
    }

    return 0;
}




int check_boolean(unsigned boolean, unsigned line_number) {

    if (expression_state == ON) {
        if (expression_data_type == d_NULL) {
            expression_data_type = d_BOOLEAN;
        } else {
            if (expression_data_type != d_BOOLEAN) {
                printf("ERROR at line %u: mixing data types, Boolean with %s at expression level!\n", line_number, data_type_to_string(expression_data_type));
                return 1;
            }
        }
    }


    if (assignment_state == ON) {
        if (assignment_data_type != d_BOOLEAN) {
            if (boolean == 1) {
                printf("ERROR at line %u: symbol 'true' is not %s!\n", line_number, data_type_to_string(assignment_data_type));
            } else {
                printf("ERROR at line %u: symbol 'false' is not %s!\n", line_number, data_type_to_string(assignment_data_type));
            }

            return 1;
        }
    }

    return 0;
}



int check_infix_expression(is_infix_expression * iie, unsigned scope_id) {
    int errors = 0;

    errors += check_expression(iie->expression1, scope_id);
    errors += check_expression(iie->expression2, scope_id);

    return errors;
}




int check_if_statement(is_if_statement * iis, unsigned scope_id){
    int errors = 0;
    
    errors += check_logical_expression(iis->logical_expression, scope_id);

    // 'then' block
    if (iis->then_block_type == d_SINGLE_STATEMENT) {
        errors += check_statement(iis->then_block.statement, scope_id);
    } else {
        is_statement_list *temp;
        for (temp = iis->then_block.statement_list; temp != NULL; temp = temp->next) {
            errors += check_statement(temp->statement, scope_id);
        }
    }

    // 'else' block
    if (iis->have_else_block == d_TRUE) {
        if (iis->else_block_type == d_SINGLE_STATEMENT) {
            errors += check_statement(iis->else_block.statement, scope_id);
        } else {
            is_statement_list *temp;
            for (temp = iis->else_block.statement_list; temp != NULL; temp = temp->next) {
                errors += check_statement(temp->statement, scope_id);
            }
        }
    }

    return errors;
}




int check_logical_expression(is_logical_expression * ile, unsigned scope_id) {
    int errors = 0;

    switch (ile->logical_type) {
        case d_LOG_INTERNAL_LOGICAL: errors += check_internal_logical_expression(ile->data_d4.internal_logical_expression, scope_id); break;
        case d_LOG_INFIX_LOGICAL: errors += check_infix_logical_expression(ile->data_d4.infix_logical_expression, scope_id); break;
    }

    return errors;
}



int check_infix_logical_expression(is_infix_logical_expression * iile, unsigned scope_id) {
    int errors = 0;

    errors += check_logical_expression(iile->logical_expression1, scope_id);
    errors += check_logical_expression(iile->logical_expression2, scope_id);

    return errors;
}


int check_internal_logical_expression(is_internal_logical_expression * iile, unsigned scope_id) {
    int errors = 0;

    is_data_type type1, type2;

    expression_state = ON;
    errors += check_expression(iile->expression1, scope_id);
    type1 = expression_data_type;
    expression_data_type = d_NULL;
    expression_state = OFF;

    if ((iile->expression2 != NULL) && (errors == 0)) {
        expression_state = ON;
        errors += check_expression(iile->expression2, scope_id);
        type2 = expression_data_type;
        expression_data_type = d_NULL;
        expression_state = OFF;

        if ((type1 == d_BOOLEAN || type2 == d_BOOLEAN) && (type1 != type2) && (errors == 0)) {
            printf("ERROR at line %u: mixing data types, %s with %s at logical level!\n", iile->expression1->line_number, data_type_to_string(type1), data_type_to_string(type2));
            return errors + 1;
        }
        
    }

    return errors;
}



int check_while_statement(is_while_statement * iws, unsigned scope_id){
    int errors = 0;
    
    errors += check_logical_expression(iws->logical_expression, scope_id);

    is_statement_list *temp;
    for (temp = iws->statement_list; temp != NULL; temp = temp->next) {
        errors += check_statement(temp->statement, scope_id);
    }
    
    return errors;
}

