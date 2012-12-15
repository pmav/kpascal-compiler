/**
 * Compiladores 2008/2009
 *
 * Pedro Miguel de Almeida Verruma
 * verruma@student.dei.uc.pt
 * Nº 2006128853
 */

#include "functions.h"
#include <string.h>


// **************************************************************************************************************************


is_program * insert_program(is_program_heading * iph, is_program_block * ipb) {
    //printf("insert_program()\n");

    is_program *ip = (is_program *) malloc(sizeof(is_program));
    ip->program_heading = iph;
    ip->program_block = ipb;

    return ip;
}




is_program_heading * insert_program_heading(is_var_name * ivn) {
    //printf("insert_program_heading(\"%s\")\n", ivn->name);

    is_program_heading *iph = (is_program_heading *) malloc(sizeof(is_program_heading));
    iph->var_name = ivn;

    return iph;
}




is_program_block * insert_program_block(is_variable_declaration_part * ivdp, is_function_list * ifl, is_statement_list * isl) {
/*
    // Count arguments
    int n = 1, m = 1;
    is_variable_declaration_part *temp1;
    for(temp1 = ivdp; temp1->next ;n++, temp1 = temp1->next);
    is_statement_list *temp2;
    for(temp2 = isl; temp2->next ;m++, temp2 = temp2->next);
    printf("insert_program_block(%d, %d)\n", n, m);
*/

    is_program_block *ipb = (is_program_block *) malloc(sizeof(is_program_block));
    ipb->variable_declaration_part = ivdp;
    ipb->function_list = ifl;
    ipb->statement_list = isl;

    return ipb;
}


// **************************************************************************************************************************


is_variable_declaration_part * insert_variable_declaration_part(is_variable_declaration_part * ivdp, is_variable_declaration * ivd) {
    //printf("insert_variable_declaration_part(..., %s)\n", ivd->var_type->type);

    is_variable_declaration_part *t_ivdp = (is_variable_declaration_part *) malloc(sizeof(is_variable_declaration_part));
    t_ivdp->variable_declaration = ivd;
    t_ivdp->next = NULL;

    if (ivdp != NULL) {
        is_variable_declaration_part *temp;
        for (temp = ivdp; temp->next != NULL; temp = temp->next); // Go to tail
        temp->next = t_ivdp;

        return ivdp; // Old list plus new element
    }

    return t_ivdp; // New list
}




is_variable_declaration * insert_variable_declaration(is_var_name_list * ivnl, is_data_type data_type) {
    //printf("insert_variable_declaration(..., type: %d)\n", data_type);
/*
    is_var_name_list *temp = ivnl;
    printf("%s\n", temp->var_name->name);
    while (temp->next != NULL) {
        printf("%s\n", temp->next->var_name->name);
        temp = temp->next;
    }
*/
    is_variable_declaration *ivd = (is_variable_declaration *) malloc(sizeof(is_variable_declaration));
    ivd->var_name_list = ivnl;
    ivd->data_type = data_type;

    return ivd;
}




is_var_name_list * insert_var_name_list(is_var_name_list * ivnl, is_var_name * ivn) {
    //printf("insert_var_name_list(\"%s\")\n", ivn->name);

    is_var_name_list *t_ivnl = (is_var_name_list *) malloc(sizeof(is_var_name_list));
    t_ivnl->var_name = ivn;
    t_ivnl->next = NULL;

    if (ivnl != NULL) {
        is_var_name_list *temp;
        for (temp = ivnl; temp->next != NULL; temp = temp->next); // Go to tail
        temp->next = t_ivnl;

        return ivnl; // Old list plus new element
    }

    return t_ivnl; // New list
}


// **************************************************************************************************************************


is_function_list * insert_function_list(is_function_list * ifl, is_function * if_) {
    //printf("insert_function_list()\n");

    is_function_list *t_ifl = (is_function_list *) malloc(sizeof(is_function_list));
    t_ifl->function = if_;
    t_ifl->next = NULL;

    if (ifl != NULL) {
        is_function_list *temp;
        for (temp = ifl; temp->next != NULL; temp = temp->next); // Go to tail
        temp->next = t_ifl;

        return ifl; // Old list plus new element
    }

    return t_ifl; // New list
}




is_function * insert_function(is_var_name *ivn, is_function_argument_list * ifal, is_data_type idt, is_variable_declaration_part * ivdp, is_statement_list * isl, unsigned line_number) {
    //printf("insert_function()\n");

    is_function * if_ = (is_function *) malloc(sizeof(is_function));
    if_->function_name = ivn;
    if_->function_argument_list = ifal;
    if_->data_type = idt;
    if_->variable_declaration_part = ivdp;
    if_->statement_list = isl;
    if_->line_number = line_number;

    return if_;
}



is_function_argument_list * insert_function_argument_list(is_function_argument_list * ifal, is_function_argument * ifa) {
    //printf("insert_function_argument_list()\n");

    is_function_argument_list *t_ifal = (is_function_argument_list *) malloc(sizeof(is_function_argument_list));
    t_ifal->function_argument = ifa;
    t_ifal->next = NULL;

    if (ifal != NULL) {
        is_function_argument_list *temp;
        for (temp = ifal; temp->next != NULL; temp = temp->next); // Go to tail
        temp->next = t_ifal;

        return ifal; // Old list plus new element
    }

    return t_ifal; // New list
}




is_function_argument * insert_function_argument(is_var_name_list * ivnl, is_data_type idt, unsigned line_number) {
    //printf("insert_function_argument()\n");

    is_function_argument * ifa = (is_function_argument *) malloc(sizeof(is_function_argument));
    ifa->var_name_list = ivnl;
    ifa->data_type = idt;
    ifa->line_number = line_number;

    return ifa;
}




is_function_call * insert_function_call(is_var_name * ivn, is_function_call_argument_list * ifcal, unsigned line_number) {
    //printf("insert_function_call()\n");

    is_function_call *ifc = (is_function_call *) malloc(sizeof(is_function_call));
    
    ifc->var_name = ivn;
    ifc->function_call_argument_list = ifcal;
    ifc->call_id = call_id;
    call_id += 1;
    ifc->line_number = line_number;

    return ifc;
}




is_function_call_argument_list * insert_function_call_argument_list(is_function_call_argument_list * ifcal, is_expression * ie) {
    //printf("insert_function_call_arguments_list()\n");

    is_function_call_argument_list *t_ifcal = (is_function_call_argument_list *) malloc(sizeof(is_function_call_argument_list));
    t_ifcal->expression = ie;
    t_ifcal->next = NULL;

    if (ifcal != NULL) {
        is_function_call_argument_list *temp;
        for (temp = ifcal; temp->next != NULL; temp = temp->next); // Go to tail
        temp->next = t_ifcal;

        return ifcal; // Old list plus new element
    }

    return t_ifcal; // New list
}


// **************************************************************************************************************************


is_statement_list * insert_statement_list(is_statement_list * isl, is_statement * is) {
    //printf("insert_statement_list()\n");

    is_statement_list *t_isl = (is_statement_list *) malloc(sizeof(is_statement_list));
    t_isl->statement = is;
    t_isl->next = NULL;

    if (isl != NULL) {
        is_statement_list *temp;
        for (temp = isl; temp->next != NULL; temp = temp->next); // Go to tail
        temp->next = t_isl;

        return isl; // Old list plus new element
    }

    return t_isl; // New list
}




is_statement * insert_statement_assignment(is_assignment_statement * ias) {
    //printf("insert_statement_assignment()\n");

    is_statement *is = (is_statement *) malloc(sizeof(is_statement));
    is->data_d1.assignment_statement = ias;
    is->statement_type = d_ASSIGNMENT;


    return is;
}




is_statement * insert_statement_writeln(is_writeln_statement * iws) {
    //printf("insert_statement_writeln()\n");

    is_statement *is = (is_statement *) malloc(sizeof(is_statement));
    is->data_d1.writeln_statement = iws;
    is->statement_type = d_WRITELN;

    return is;
}




is_statement * insert_statement_if(is_if_statement * iis) {
    //printf("insert_statement_if()\n");

    is_statement *is = (is_statement *) malloc(sizeof(is_statement));
    is->data_d1.if_statement = iis;
    is->statement_type = d_IF;

    return is;
}




is_statement * insert_statement_while(is_while_statement * iws) {
    //printf("insert_statement_while()\n");

    is_statement *is = (is_statement *) malloc(sizeof(is_statement));
    is->data_d1.while_statement = iws;
    is->statement_type = d_WHILE;

    return is;
}


// **************************************************************************************************************************


is_while_statement * insert_while_statement(is_logical_expression * ile, is_statement_list * isl) {
    //printf("insert_while_statement()\n");

    is_while_statement *iws = (is_while_statement *) malloc(sizeof(is_while_statement));
    iws->logical_expression = ile;
    iws->statement_list = isl;
    iws->statement_id = statement_id;
    statement_id++;

    return iws;
}




is_if_statement * insert_if_statement_single_then(is_logical_expression * ile, is_statement * is) {
    //printf("insert_if_statement_single_then()\n");

    is_if_statement *iis = (is_if_statement *) malloc(sizeof(is_if_statement));
    iis->logical_expression = ile;

    iis->then_block.statement = is;
    iis->then_block_type = d_SINGLE_STATEMENT;

    iis->have_else_block = d_FALSE;

    iis->statement_id = statement_id;
    statement_id++;

    return iis;
}




is_if_statement * insert_if_statement_list_then(is_logical_expression * ile, is_statement_list * isl) {
    //printf("insert_if_statement_list_then()\n");

    is_if_statement *iis = (is_if_statement *) malloc(sizeof(is_if_statement));
    iis->logical_expression = ile;

    iis->then_block.statement_list = isl;
    iis->then_block_type = d_LIST_STATEMENT;

    iis->have_else_block = d_FALSE;

    iis->statement_id = statement_id;
    statement_id++;

    return iis;
}




is_if_statement * insert_if_statement_single_then_single_else(is_logical_expression * ile, is_statement * is_then, is_statement * is_else) {
    //printf("insert_if_statement_single_then_single_else()\n");

    is_if_statement *iis = (is_if_statement *) malloc(sizeof(is_if_statement));
    iis->logical_expression = ile;

    iis->then_block.statement = is_then;
    iis->then_block_type = d_SINGLE_STATEMENT;

    iis->else_block.statement = is_else;
    iis->else_block_type = d_SINGLE_STATEMENT;

    iis->have_else_block = d_TRUE;

    iis->statement_id = statement_id;
    statement_id++;

    return iis;
}




is_if_statement * insert_if_statement_single_then_list_else(is_logical_expression * ile, is_statement * is_then, is_statement_list * isl_else) {
    //printf("insert_if_statement_single_then_list_else()\n");

    is_if_statement *iis = (is_if_statement *) malloc(sizeof(is_if_statement));
    iis->logical_expression = ile;

    iis->then_block.statement = is_then;
    iis->then_block_type = d_SINGLE_STATEMENT;

    iis->else_block.statement_list = isl_else;
    iis->else_block_type = d_LIST_STATEMENT;

    iis->have_else_block = d_TRUE;

    iis->statement_id = statement_id;
    statement_id++;

    return iis;
}




is_if_statement * insert_if_statement_list_then_single_else(is_logical_expression * ile, is_statement_list * isl_then, is_statement * is_else) {
    //printf("insert_if_statement_list_then_single_else()\n");

    is_if_statement *iis = (is_if_statement *) malloc(sizeof(is_if_statement));
    iis->logical_expression = ile;

    iis->then_block.statement_list = isl_then;
    iis->then_block_type = d_LIST_STATEMENT;

    iis->else_block.statement = is_else;
    iis->else_block_type = d_SINGLE_STATEMENT;

    iis->have_else_block = d_TRUE;

    iis->statement_id = statement_id;
    statement_id++;

    return iis;
}




is_if_statement * insert_if_statement_list_then_list_else(is_logical_expression * ile, is_statement_list * isl_then, is_statement_list * isl_else) {
    //printf("insert_if_statement_list_then_list_else()\n");

    is_if_statement *iis = (is_if_statement *) malloc(sizeof(is_if_statement));
    iis->logical_expression = ile;

    iis->then_block.statement_list = isl_then;
    iis->then_block_type = d_LIST_STATEMENT;

    iis->else_block.statement_list = isl_else;
    iis->else_block_type = d_LIST_STATEMENT;

    iis->have_else_block = d_TRUE;

    iis->statement_id = statement_id;
    statement_id++;

    return iis;
}




is_assignment_statement * insert_assignment_statement_expression(is_var_name * ivn, is_expression * ie) {
    //printf("insert_assignment_statement_expression(\"%s\", ...)\n", ivn->var_name);

    is_assignment_statement *ias = (is_assignment_statement *) malloc(sizeof(is_assignment_statement));
    ias->var_name = ivn;
    ias->expression = ie;
    //ias->assignment_type = d_EXPRESSION;
    ias->statement_id = statement_id;
    statement_id++;

    return ias;
}




is_writeln_statement * insert_writeln_statement(is_writeln_argument_list * iwal) {
/*
    int n = 1;
    is_writeln_argument_list *temp;
    for(temp = iwal; temp->next ;n++, temp = temp->next);
    printf("insert_writeln_statement(%d)\n", n);
*/

    is_writeln_statement *iws = (is_writeln_statement *) malloc(sizeof(is_writeln_statement));
    iws->writeln_argument_list = iwal;

    return iws;
}




is_writeln_argument_list * insert_writeln_argument_list(is_writeln_argument_list * iwal, is_writeln_argument * iwa) {
    //printf("insert_writeln_argument_list()\n");

    is_writeln_argument_list *t_iwal = (is_writeln_argument_list *) malloc(sizeof(is_writeln_argument_list));
    t_iwal->writeln_argument = iwa;
    t_iwal->next = NULL;

    if (iwal != NULL) {
        is_writeln_argument_list *temp;
        for (temp = iwal; temp->next != NULL; temp = temp->next); // Go to tail
        temp->next = t_iwal;

        return iwal;
    }

    return t_iwal;
}




is_writeln_argument * insert_writeln_argument_string(is_string * is) {
    //printf("insert_writeln_argument_string(\"%s\")\n", is->string);

    is_writeln_argument *iwa = (is_writeln_argument *) malloc(sizeof(is_writeln_argument));
    iwa->data_d3.string = is;
    iwa->argument_type = d_ARG_STRING;

    return iwa;
}




is_writeln_argument * insert_writeln_argument_expression(is_expression * ie) {
    //printf("insert_writeln_argument_expression()\n");

    is_writeln_argument *iwa = (is_writeln_argument *) malloc(sizeof(is_writeln_argument));
    iwa->data_d3.expression = ie;
    iwa->argument_type = d_ARG_EXPRESSION;

    return iwa;
}


// **************************************************************************************************************************


is_expression * insert_expression_string(is_string * is, unsigned line_number) {
    //printf("insert_expression_string(\"%s\")\n", is->string);

    is_expression *ie = (is_expression *) malloc(sizeof(is_expression));
    ie->data_d2.string = is;
    ie->expression_type = d_EXP_STRING;
    ie->line_number = line_number;

    return ie;
}




is_expression * insert_expression_digit_sequence(is_digit_sequence * ids, unsigned line_number) {
    //printf("insert_expression_digit_sequence(%d)\n", ids->digit_sequence);

    is_expression *ie = (is_expression *) malloc(sizeof(is_expression));
    ie->data_d2.digit_sequence = ids;
    ie->expression_type = d_EXP_DIGIT_SEQUENCE;
    ie->line_number = line_number;

    return ie;
}




is_expression * insert_expression_var_name(is_var_name * ivn, unsigned line_number) {
    //printf("insert_expression_var_name(\"%s\")\n", ivn->var_name);

    is_expression *ie = (is_expression *) malloc(sizeof(is_expression));
    ie->data_d2.var_name = ivn;
    ie->expression_type = d_EXP_VAR_NAME;
    ie->line_number = line_number;

    return ie;
}




is_expression * insert_expression_bool(unsigned boolean, unsigned line_number) {
    //printf("insert_expression_bool(%d)\n", boolean);

    is_expression *ie = (is_expression *) malloc(sizeof(is_expression));
    ie->data_d2.boolean = boolean;
    ie->expression_type = d_EXP_BOOLEAN;
    ie->line_number = line_number;

    return ie;
}




is_expression * insert_expression_function_call(is_function_call * ifc, unsigned line_number) {
    //printf("insert_expression_function_call()\n");

    is_expression *ie = (is_expression *) malloc(sizeof(is_expression));
    ie->data_d2.function_call = ifc;
    ie->expression_type = d_EXP_FUNCTION_CALL;
    ie->line_number = line_number;

    return ie;
}




is_expression * insert_operator(is_expression * ie1, is_expression * ie2, is_operator oper, unsigned line_number) {
    is_expression *ie = (is_expression *) malloc(sizeof(is_expression));
    is_infix_expression * iie;

    iie = (is_infix_expression *) malloc(sizeof(is_infix_expression));
    iie->oper = oper;
    iie->expression1 = ie1;
    iie->expression2 = ie2;
    ie->data_d2.infix_expression = iie;
    ie->expression_type = d_EXP_INFIX_EXPRESSION;
    ie->line_number = line_number;

    return ie;
}




is_logical_expression * insert_logical_expression(is_logical_expression * ile1, is_logical_expression *ile2, is_logical_operator ilo) {
    //printf("insert_logical_expression()\n");

    is_logical_expression *ile = (is_logical_expression *) malloc(sizeof(is_logical_expression));
    is_infix_logical_expression * iile = (is_infix_logical_expression *) malloc(sizeof(is_infix_logical_expression));

    iile->logical_operator = ilo;
    iile->logical_expression1 = ile1;
    iile->logical_expression2 = ile2;

    ile->data_d4.infix_logical_expression = iile;
    ile->logical_type = d_LOG_INFIX_LOGICAL;

    return ile;
}




is_logical_expression * insert_logical_expression_internal(is_internal_logical_expression * iile) {
    //printf("insert_logical_expression_internal()\n");

    is_logical_expression * ile = (is_logical_expression *) malloc(sizeof(is_logical_expression));
    ile->data_d4.internal_logical_expression = iile;
    ile->logical_type = d_LOG_INTERNAL_LOGICAL;

    return ile;
}




is_internal_logical_expression * insert_internal_logical_expression(is_expression * ie1, is_expression * ie2, is_logical_operator ilo) {
    //printf("insert_internal_logical_expression()\n");

    is_internal_logical_expression *iile = (is_internal_logical_expression *) malloc(sizeof(is_internal_logical_expression));
    iile->expression1 = ie1;
    iile->expression2 = ie2;
    iile->logical_operator = ilo;

    return iile;

}


// **************************************************************************************************************************


is_var_name * insert_var_name(char * var_name, unsigned line_number) {
    //printf("insert_var_name(\"%s\")\n", var_name);

    is_var_name *ivn = (is_var_name *) malloc(sizeof(is_var_name));
    ivn->var_name = (char*)strdup(var_name);
    ivn->line_number = line_number;

    return ivn;
}




is_digit_sequence * insert_digit_sequence(int digit_sequence) {
    //printf("insert_digit_sequence(%d)\n", digit_sequence);

    is_digit_sequence *ids = (is_digit_sequence *) malloc(sizeof(is_digit_sequence));
    ids->data.digit_sequence = digit_sequence;
    ids->type = d_DIGSEQ_INTEGER;

    return ids;   
}




is_digit_sequence * insert_float_digit_sequence(float digit_sequence) {
    //printf("insert_float_digit_sequence(%d)\n", digit_sequence);

    is_digit_sequence *ids = (is_digit_sequence *) malloc(sizeof(is_digit_sequence));
    ids->data.float_digit_sequence = digit_sequence;
    ids->type = d_DIGSEQ_FLOAT;

    return ids;   
}




is_string * insert_string(char * string) {
    //printf("insert_string(\"%s\")\n", string);

    is_string *is = (is_string *) malloc(sizeof(is_string));
    is->string = (char*)strdup(string);

    return is;
}

