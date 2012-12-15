/**
 * Compiladores 2008/2009
 *
 * Pedro Miguel de Almeida Verruma
 * verruma@student.dei.uc.pt
 * Nº 2006128853
 */


typedef struct _t4 {
    unsigned value;
    struct _t4 *next;
} redirect;

unsigned redirect_id = 0;

// **************************************************************************************************************************

void translate_program (is_program *);

void translate_program_heading(FILE *, is_program_heading *);

void translate_program_block(FILE *, is_program_block *);

// **************************************************************************************************************************

void translate_variable_declaration_part(FILE *, is_variable_declaration_part *, unsigned);

void translate_variable_declaration(FILE *, is_variable_declaration *, unsigned);

// **************************************************************************************************************************

void translate_function_list(FILE *, is_function_list *);

void translate_function(FILE *, is_function *);

void translate_function_argument_list(FILE *, is_function_argument_list *, unsigned);

void translate_function_argument(FILE *, is_function_argument *, unsigned);

void translate_function_argument_list_to_local(FILE *, is_function_argument_list *, unsigned);

// **************************************************************************************************************************

void translate_statement_list(FILE *, is_statement_list *, unsigned);

void translate_statement(FILE *, is_statement *, unsigned);

void translate_while_statement(FILE *, is_while_statement *, unsigned);

void translate_if_statement(FILE *, is_if_statement *, unsigned);

void translate_logical_expression(FILE *, is_logical_expression *, unsigned);

void translate_infix_logical_expression(FILE *, is_infix_logical_expression *, unsigned);

void translate_internal_logical_expression(FILE *, is_internal_logical_expression *, unsigned);

void translate_logical_operator(FILE *, is_logical_operator);

void translate_writeln_statement(FILE *, is_writeln_statement *, unsigned);

void translate_assignment_statement(FILE *, is_assignment_statement *, unsigned);

void translate_function_call_expression(FILE * fp, is_expression *, unsigned);

void translate_function_call(FILE *, is_function_call *, unsigned);

void translate_expression(FILE *, is_expression *, unsigned);

void translate_function_call_variable(FILE *, is_function_call *, unsigned);

void translate_infix_expression(FILE *, is_infix_expression *, unsigned);

void translate_assignment_var_name(FILE *, is_var_name *, unsigned);

void translate_var_name(FILE *, is_var_name *, unsigned);

void translate_digit_sequence(FILE *, is_digit_sequence *);

void translate_boolean(FILE *, unsigned);

void translate_operator(FILE *, is_operator);

void translate_single_variable_declaration(FILE *, is_var_name *, is_data_type, unsigned);

void translate_data_type(FILE *, is_data_type);

void translate_header(FILE *);

void translate_footer(FILE *);

// **************************************************************************************************************************

void add_to_redirect(unsigned);

void translate_redirect(FILE *);

