/**
 * Compiladores 2008/2009
 *
 * Pedro Miguel de Almeida Verruma
 * verruma@student.dei.uc.pt
 * Nº 2006128853
 */

#include "translate.h"


redirect *redirect_list;


void translate_program (is_program * ip) {
    FILE *fp;
    fp = fopen("running/result.c", "w");

    translate_header(fp);
    translate_program_heading(fp, ip->program_heading);
    translate_program_block(fp, ip->program_block);
    translate_redirect(fp);
    translate_footer(fp);

    fclose(fp);
}




void translate_program_heading(FILE * fp, is_program_heading * iph) {
    fprintf(fp, "\t/* Program name: %s */\n\n", iph->var_name->var_name);
}




void translate_program_block(FILE * fp, is_program_block * ipb) {
    fprintf(fp, "\t/* Global Variables */\n\n");
    translate_variable_declaration_part(fp, ipb->variable_declaration_part, GLOBAL_SCOPE);

    fprintf(fp, "\n\t/* Functions */\n");
    translate_function_list(fp, ipb->function_list);

    fprintf(fp, "\n\t/* Statements */\n\n");
    translate_statement_list(fp, ipb->statement_list, GLOBAL_SCOPE);
}




void translate_variable_declaration_part(FILE * fp, is_variable_declaration_part * ivdp, unsigned scope_id) {
    is_variable_declaration_part *temp;

    for (temp = ivdp; temp != NULL; temp = temp->next) {
        translate_variable_declaration(fp, temp->variable_declaration, scope_id);
    }
}




void translate_variable_declaration(FILE * fp, is_variable_declaration * ivd, unsigned scope_id) {
    is_var_name_list *temp;

    for (temp = ivd->var_name_list; temp != NULL; temp = temp->next) {

        if (scope_id > 1) {

            table_element *te = search_el(temp->var_name->var_name, scope_id);

            switch(te->data_type) {
                case d_INTEGER: fprintf(fp, "\tsp->locals[%d] = (int *) malloc(sizeof(int)); /* var: %s */\n", element_position(temp->var_name->var_name, scope_id), temp->var_name->var_name); break;
                case d_BOOLEAN: fprintf(fp, "\tsp->locals[%d] = (boolean *) malloc(sizeof(boolean)); /* var: %s */\n", element_position(temp->var_name->var_name, scope_id), temp->var_name->var_name); break;
                case d_REAL: fprintf(fp, "\tsp->locals[%d] = (float *) malloc(sizeof(float)); /* var: %s */\n", element_position(temp->var_name->var_name, scope_id), temp->var_name->var_name); break;
            }

        } else {

            /* Print type */
            switch(ivd->data_type) {
                case d_INTEGER: fprintf(fp, "\tint"); break;
                case d_BOOLEAN: fprintf(fp, "\tboolean"); break;
                case d_REAL:    fprintf(fp, "\tfloat"); break;
            }

            /* Print var name */
            fprintf(fp, " v%d; /* %s */\n", element_position(temp->var_name->var_name, scope_id), temp->var_name->var_name);
        }

    }

}


// **************************************************************************************************************************


void translate_function_list(FILE * fp, is_function_list * ifl) {
    is_function_list *temp;
    for (temp = ifl; temp != NULL; temp = temp->next) {
        translate_function(fp, temp->function);
    }
}


void translate_function(FILE * fp, is_function * if_) {
    function_element *fe = search_function_symbol(if_->function_name->var_name);

    fprintf(fp, "\n\t/* %s() ******************************************************* */\n", if_->function_name->var_name);

    // Start
    translate_function_argument_list(fp, if_->function_argument_list, fe->id); /* Arguments used when calling this function */

    fprintf(fp, "\tgoto skip_%s;\n", if_->function_name->var_name);
    fprintf(fp, "\tstart_%s:\n", if_->function_name->var_name);
	fprintf(fp, "\tfp = sp;\n");
	fprintf(fp, "\tsp = (frame*) malloc(sizeof(frame));\n");
	fprintf(fp, "\tsp->parent = fp;\n");
	fprintf(fp, "\tsp->return_address = r;\n\n");

    // Body
    translate_data_type(fp, if_->data_type);
    fprintf(fp, " v%d; /* %s (return value) */\n", element_position(if_->function_name->var_name, fe->id), if_->function_name->var_name);

    switch(if_->data_type) {
        case d_INTEGER: fprintf(fp, "\tsp->locals[%d] = (int *) malloc(sizeof(int));\n", element_position(if_->function_name->var_name, fe->id)); break;
        case d_BOOLEAN: fprintf(fp, "\tsp->locals[%d] = (boolean *) malloc(sizeof(boolean));\n", element_position(if_->function_name->var_name, fe->id)); break;
        case d_REAL: fprintf(fp, "\tsp->locals[%d] = (float *) malloc(sizeof(float));\n", element_position(if_->function_name->var_name, fe->id)); break;
    }

    translate_function_argument_list_to_local(fp, if_->function_argument_list, fe->id);
    fprintf(fp, "\n");
    translate_variable_declaration_part(fp, if_->variable_declaration_part, fe->id);
    fprintf(fp, "\n");
    translate_statement_list(fp, if_->statement_list, fe->id);

    // Pass local return to global return
    fprintf(fp, "\n\tv%d = ", element_position(if_->function_name->var_name, fe->id));

    switch(if_->data_type) {
        case d_INTEGER: fprintf(fp, "((int) sp->locals[%d]);\n\n", element_position(if_->function_name->var_name, fe->id)); break;
        case d_BOOLEAN: fprintf(fp, "((boolean) sp->locals[%d]);\n\n", element_position(if_->function_name->var_name, fe->id)); break;
        case d_REAL: fprintf(fp, "*((float *) sp->locals[%d]);\n\n", element_position(if_->function_name->var_name, fe->id)); break;
    }

    // End
	fprintf(fp, "\n\tr = sp->return_address;\n");
	fprintf(fp, "\tsp = sp->parent;\n");
	fprintf(fp, "\tfp = sp->parent;\n");
    fprintf(fp, "\tgoto redirect;\n");
    fprintf(fp, "\tskip_%s:; /* NOOP is needed because a label can't point to a var dec (eg: int v1;) */\n", if_->function_name->var_name);
}


void translate_function_argument_list(FILE * fp, is_function_argument_list * ifal, unsigned scope_id) {
    is_function_argument_list *temp;
    for (temp = ifal; temp != NULL; temp = temp->next) {
        translate_function_argument(fp, temp->function_argument, scope_id);
    }
}


void translate_function_argument(FILE * fp, is_function_argument * ifa, unsigned scope_id) {
    is_var_name_list *temp;
    for (temp = ifa->var_name_list; temp != NULL; temp = temp->next) {
        translate_single_variable_declaration(fp, temp->var_name, ifa->data_type, scope_id);
    }
}


void translate_function_argument_list_to_local(FILE * fp, is_function_argument_list * ifal, unsigned scope_id) { // Convert global variables into local
    is_function_argument_list *temp;
    is_var_name_list *temp2;

    for (temp = ifal; temp != NULL; temp = temp->next) {
        for (temp2 = temp->function_argument->var_name_list; temp2 != NULL; temp2 = temp2->next) {

            table_element *te = search_el(temp2->var_name->var_name, scope_id);

            unsigned element_position_value = element_position(temp2->var_name->var_name, scope_id);

            switch(te->data_type) {

                case d_INTEGER:
                    fprintf(fp, "\tsp->locals[%d] = (int *) malloc(sizeof(int)); /* argument: %s */\n", element_position_value, temp2->var_name->var_name);
                    fprintf(fp, "\tsp->locals[%d] = (int *) v%d;\n", element_position_value, element_position_value);
                    break;

                case d_BOOLEAN:
                    fprintf(fp, "\tsp->locals[%d] = (boolean *) malloc(sizeof(boolean)); /* argument: %s */\n", element_position_value, temp2->var_name->var_name);
                    fprintf(fp, "\tsp->locals[%d] = (boolean *) v%d;\n", element_position_value, element_position_value);
                    break;

                case d_REAL:
                    fprintf(fp, "\tsp->locals[%d] = (float *) malloc(sizeof(float)); /* argument: %s */\n", element_position_value, temp2->var_name->var_name);
                    fprintf(fp, "\tsp->locals[%d] = &v%d;\n", element_position_value, element_position_value);
                    break;
            }
        }
    }    
}

// **************************************************************************************************************************

void translate_statement_list(FILE * fp, is_statement_list * isl, unsigned scope_id) {
    is_statement_list *temp;
    for (temp = isl; temp != NULL; temp = temp->next) {
        translate_statement(fp, temp->statement, scope_id);
    }
}




void translate_statement(FILE * fp, is_statement * is, unsigned scope_id) {
    switch(is->statement_type) {
        case d_ASSIGNMENT: translate_assignment_statement(fp, is->data_d1.assignment_statement, scope_id); break;
        case d_WRITELN: translate_writeln_statement(fp, is->data_d1.writeln_statement, scope_id); break;
        case d_IF: translate_if_statement(fp, is->data_d1.if_statement, scope_id); break;
        case d_WHILE: translate_while_statement(fp, is->data_d1.while_statement, scope_id); break;
    }
}




void translate_while_statement(FILE * fp, is_while_statement * iws, unsigned scope_id) {
    fprintf(fp, "\n\t/* WHILE (#%d) */\n", iws->statement_id);
    fprintf(fp, "\tgoto label_while_eval_%d;\n", iws->statement_id);
    fprintf(fp, "\tlabel_while_body_%d:\n", iws->statement_id);
    translate_statement_list(fp, iws->statement_list, scope_id);
    fprintf(fp, "\tlabel_while_eval_%d:\n", iws->statement_id);
    fprintf(fp, "\tif (");
    translate_logical_expression(fp, iws->logical_expression, scope_id);
    fprintf(fp, ") goto label_while_body_%d;\n", iws->statement_id);
    fprintf(fp, "\tlabel_while_end_%d:\n", iws->statement_id);
}




void translate_if_statement(FILE * fp, is_if_statement * iis, unsigned scope_id) {
    fprintf(fp, "\n\t/* IF (#%d) ------------------------------- */\n", iis->statement_id);
    fprintf(fp, "\tgoto label_if_eval_%d;\n", iis->statement_id);
    fprintf(fp, "\tlabel_if_body_%d:\n", iis->statement_id);

    if (iis->then_block_type == d_SINGLE_STATEMENT) {
        translate_statement(fp, iis->then_block.statement, scope_id);
    } else {
        translate_statement_list(fp, iis->then_block.statement_list, scope_id);
    }

    fprintf(fp, "\tgoto label_if_end_%d;\n", iis->statement_id);
    fprintf(fp, "\tlabel_if_eval_%d:\n", iis->statement_id);
    fprintf(fp, "\tif (");
    translate_logical_expression(fp, iis->logical_expression, scope_id);
    fprintf(fp, ") goto label_if_body_%d;\n", iis->statement_id);

    if (iis->have_else_block == d_TRUE) {
        if (iis->else_block_type == d_SINGLE_STATEMENT) {
            translate_statement(fp, iis->else_block.statement, scope_id);
        } else {
            translate_statement_list(fp, iis->else_block.statement_list, scope_id);
        }
    }

    fprintf(fp, "\tlabel_if_end_%d:\n", iis->statement_id);
}




void translate_logical_expression(FILE * fp, is_logical_expression * ile, unsigned scope_id) {
    switch (ile->logical_type) {
        case d_LOG_INTERNAL_LOGICAL: translate_internal_logical_expression(fp, ile->data_d4.internal_logical_expression, scope_id); break;
        case d_LOG_INFIX_LOGICAL: translate_infix_logical_expression(fp, ile->data_d4.infix_logical_expression, scope_id); break;
    }
}



void translate_infix_logical_expression(FILE * fp, is_infix_logical_expression * iile, unsigned scope_id) {
    fprintf(fp, "(");
    translate_logical_expression(fp, iile->logical_expression1, scope_id);
    translate_logical_operator(fp, iile->logical_operator);
    translate_logical_expression(fp, iile->logical_expression2, scope_id);
    fprintf(fp, ")");
}



void translate_internal_logical_expression(FILE * fp, is_internal_logical_expression * iile, unsigned scope_id) {
    fprintf(fp, "(");
    translate_expression(fp, iile->expression1, scope_id);
    if (iile->expression2 != NULL) {
        translate_logical_operator(fp, iile->logical_operator);
        translate_expression(fp, iile->expression2, scope_id);
    }
    fprintf(fp, ")");
}



void translate_logical_operator(FILE * fp, is_logical_operator ilo) {
    switch(ilo) {
        case d_EQUAL: fprintf(fp, " == "); break;
        case d_GT: fprintf(fp, " > "); break;
        case d_LT: fprintf(fp, " < "); break;
        case d_GE: fprintf(fp, " >= "); break;
        case d_LE: fprintf(fp, " <= "); break;
        case d_NOTEQUAL: fprintf(fp, " != "); break;
        case d_AND: fprintf(fp, " && "); break;
        case d_OR: fprintf(fp, " || "); break;
    }
}




void translate_writeln_statement(FILE * fp, is_writeln_statement * iws, unsigned scope_id) {
    fprintf(fp, "\n");
    is_writeln_argument_list *temp;
    for (temp = iws->writeln_argument_list; temp != NULL; temp = temp->next) {
        switch(temp->writeln_argument->argument_type) {
            case d_ARG_STRING:
                fprintf(fp, "\tprintf(\"%s\");\n", temp->writeln_argument->data_d3.string->string);
                break;

            case d_ARG_EXPRESSION:

                switch (temp->writeln_argument->data_d3.expression->data_type) {
                    case d_INTEGER:
                        fprintf(fp, "\tprintf(\"%%d\", ");
                        translate_expression(fp, temp->writeln_argument->data_d3.expression, scope_id);
                        fprintf(fp, ");\n");
                        break;

                    case d_REAL:
                        fprintf(fp, "\tprintf(\"%%f\", ");
                        translate_expression(fp, temp->writeln_argument->data_d3.expression, scope_id);
                        fprintf(fp, ");\n");
                        break;

                    case d_BOOLEAN:
                        fprintf(fp, "\tprintf(\"%%s\", ");
                        translate_expression(fp, temp->writeln_argument->data_d3.expression, scope_id);
                        fprintf(fp, " ? \"TRUE\" : \"FALSE\");\n");
                        break;
                }

                break;
        }
    }

    fprintf(fp, "\tprintf(\"\\n\");\n\n");
}




void translate_assignment_statement(FILE * fp, is_assignment_statement * ias, unsigned scope_id) {
    // Check for calling expressions
    translate_function_call_expression(fp, ias->expression, scope_id);

    translate_assignment_var_name(fp, ias->var_name, scope_id);

    translate_expression(fp, ias->expression, scope_id);
    fprintf(fp, "; /* Assignment */\n");
}




void translate_function_call_expression(FILE * fp, is_expression * ie, unsigned scope_id) {
        switch(ie->expression_type) {

            case d_EXP_INFIX_EXPRESSION:
                translate_function_call_expression(fp, ie->data_d2.infix_expression->expression1, scope_id);
                translate_function_call_expression(fp, ie->data_d2.infix_expression->expression2, scope_id);
                break;

            case d_EXP_FUNCTION_CALL:
                translate_function_call(fp, ie->data_d2.function_call, scope_id);
                break;
    }
}




void translate_function_call(FILE * fp, is_function_call * ifc, unsigned scope_id) {

    function_element *fe = search_function_symbol(ifc->var_name->var_name);
    fprintf(fp, "\n\t/* calling '%s()' to 'v%d' (Call ID: %d) */\n", ifc->var_name->var_name, element_position(ifc->var_name->var_name, fe->id), ifc->call_id);

    is_function_call_argument_list *temp2 = ifc->function_call_argument_list;
    function_argument_id *temp;

    for (temp = fe->function_argument_id; temp != NULL; temp = temp->next, temp2 = temp2->next) {
        fprintf(fp, "\tv%d = ", temp->id);
        translate_expression(fp, temp2->expression, scope_id);
        fprintf(fp, ";\n");
    }

    add_to_redirect(redirect_id);
    fprintf(fp, "\tr = %d;\n", redirect_id);
    fprintf(fp, "\tgoto start_%s;\n", ifc->var_name->var_name);
    fprintf(fp, "\tassignment_%d:;\n", redirect_id);

    // Create a new variable and save function return value there
    table_element *te = search_el(ifc->var_name->var_name, scope_id);

    switch(te->data_type) {
        case d_INTEGER: fprintf(fp, "\tint"); break;
        case d_BOOLEAN: fprintf(fp, "\tboolean"); break;
        case d_REAL:    fprintf(fp, "\tfloat"); break;
    }

    fprintf(fp, " c%d = v%d;\n", ifc->call_id, element_position(ifc->var_name->var_name, fe->id));

    redirect_id += 1;
}




void translate_expression(FILE * fp, is_expression * ie, unsigned scope_id) {
    switch(ie->expression_type) {
        case d_EXP_INFIX_EXPRESSION: translate_infix_expression(fp, ie->data_d2.infix_expression, scope_id); break;
        case d_EXP_VAR_NAME:         translate_var_name(fp, ie->data_d2.var_name, scope_id); break;
        case d_EXP_DIGIT_SEQUENCE:   translate_digit_sequence(fp, ie->data_d2.digit_sequence); break;
        case d_EXP_BOOLEAN:          translate_boolean(fp, ie->data_d2.boolean); break;
        case d_EXP_FUNCTION_CALL:    translate_function_call_variable(fp, ie->data_d2.function_call, scope_id); break;
    }
}



void translate_function_call_variable(FILE * fp, is_function_call * ifc, unsigned scope_id) {
    fprintf(fp, "c%d", ifc->call_id);
}


void translate_infix_expression(FILE * fp, is_infix_expression * iie, unsigned scope_id) {
    fprintf(fp, "(");
    translate_expression(fp, iie->expression1, scope_id);
    translate_operator(fp, iie->oper);
    translate_expression(fp, iie->expression2, scope_id);
    fprintf(fp, ")");
}




void translate_operator(FILE * fp, is_operator operator) {
    char oper;

     switch(operator) {
        case d_PLUS: oper = '+'; break;
        case d_MINUS: oper = '-'; break;
        case d_STAR: oper = '*'; break;
        case d_DIV: oper = '/'; break;
        case d_MOD: oper = '%'; break;
     }

    fprintf(fp, "%c", oper);
}

void translate_assignment_var_name(FILE * fp, is_var_name * ivn, unsigned scope_id) {
    if (scope_id > 1) {
        table_element *te = search_el(ivn->var_name, scope_id);

        switch(te->data_type) {
            case d_INTEGER: fprintf(fp, "\tsp->locals[%d] = (int *) ", element_position(ivn->var_name, scope_id)); break;
            case d_BOOLEAN: fprintf(fp, "\tsp->locals[%d] = (boolean *) ", element_position(ivn->var_name, scope_id)); break;
            case d_REAL: fprintf(fp, "\t*((float *)sp->locals[%d]) = ", element_position(ivn->var_name, scope_id)); break;
        }

    } else {
        fprintf(fp, "\tv%d = ", element_position(ivn->var_name, scope_id));
    }
}


void translate_var_name(FILE * fp, is_var_name * ivn, unsigned scope_id) {
    if (scope_id > 1) {
        table_element *te = search_el(ivn->var_name, scope_id);

        switch(te->data_type) {
            case d_INTEGER: fprintf(fp, "((int) sp->locals[%d])", element_position(ivn->var_name, scope_id)); break;
            case d_BOOLEAN: fprintf(fp, "((boolean) sp->locals[%d])", element_position(ivn->var_name, scope_id)); break;
            case d_REAL: fprintf(fp, "*((float *) sp->locals[%d])", element_position(ivn->var_name, scope_id)); break;
        }

    } else {
        fprintf(fp, "v%d", element_position(ivn->var_name, scope_id));
    }
}


void translate_digit_sequence(FILE * fp, is_digit_sequence * ids) {
    switch (ids->type) {
        case d_DIGSEQ_INTEGER:
            if (ids->data.digit_sequence < 0) {
                fprintf(fp, "(%d)", ids->data.digit_sequence);
            } else {
                fprintf(fp, "%d", ids->data.digit_sequence);
            }
            break;

        case d_DIGSEQ_FLOAT:
            if (ids->data.float_digit_sequence < 0) {
                fprintf(fp, "(%f)", ids->data.float_digit_sequence);
            } else {
                fprintf(fp, "%f", ids->data.float_digit_sequence);
            }
            break;
    }
}


void translate_boolean(FILE * fp, unsigned boolean) {
    if (boolean == 1) {
        fprintf(fp, "TRUE");
    } else {
        fprintf(fp, "FALSE");
    }
}


void translate_single_variable_declaration(FILE * fp, is_var_name * ivn, is_data_type idt, unsigned scope_id) {
    translate_data_type(fp, idt); // Global Scope
    fprintf(fp, " v%d; /* %s */\n", element_position(ivn->var_name, scope_id), ivn->var_name);
}


void translate_data_type(FILE * fp, is_data_type idt) {
    /* Print type */
    switch(idt) {
        case d_INTEGER: fprintf(fp, "\tint"); break;
        case d_BOOLEAN: fprintf(fp, "\tboolean"); break;
        case d_REAL:    fprintf(fp, "\tfloat"); break;
    }
}


void translate_header(FILE* fp) {
	fprintf(fp, "#include <stdlib.h>\n");
	fprintf(fp, "#include <stdio.h>\n\n");
	fprintf(fp, "typedef struct _f1 {\n");
	fprintf(fp, "\tstruct _f1* parent;\n");
	fprintf(fp, "\tvoid* locals[64];\n");
	fprintf(fp, "\tvoid* outgoing[32];\n");
	fprintf(fp, "\tint return_address;\n");
	fprintf(fp, "}frame;\n\n");
	fprintf(fp, "typedef enum {\n\tFALSE, TRUE\n} boolean;\n\n");
	fprintf(fp, "int main() {\n");
	fprintf(fp, "\tframe* fp = NULL;\n");
	fprintf(fp, "\tframe* sp = NULL;\n");
    fprintf(fp, "\tint r = 0; /* registo para redirect no final das funções */\n");
	fprintf(fp, "\tsp = (frame*) malloc(sizeof(frame));\n\n");
}


void translate_footer(FILE* fp) {
	fprintf(fp, "\n\treturn 0;\n}\n\n");
}


void add_to_redirect(unsigned value) {
    redirect *r = (redirect *) malloc(sizeof(redirect));
    r->value = value;

    if (redirect_list == NULL) {
        redirect_list = r;
    } else {
        redirect *temp;
        for(temp = redirect_list; temp->next != NULL; temp = temp->next);
        temp->next = r;
    }
}


void translate_redirect(FILE * fp) {
    redirect *temp;
    fprintf(fp, "\n\t/* Redirect functions on return */\n\tgoto skip_redirect;\n");
    fprintf(fp, "\tredirect:\n");
    for (temp = redirect_list; temp != NULL; temp = temp->next) {
        fprintf(fp, "\tif (r == %d) goto assignment_%d;\n", temp->value, temp->value);
    }
    fprintf(fp, "\tskip_redirect:\n");
}

