/**
 * Compiladores 2008/2009
 *
 * Pedro Miguel de Almeida Verruma
 * verruma@student.dei.uc.pt
 * Nº 2006128853
 */

#define ON 0
#define OFF 1

int assignment_state = OFF;
int expression_state = OFF;
int function_call_state = OFF;

char *function_return_var_name;
int function_return_assignment = FALSE;

is_data_type assignment_data_type;
is_data_type expression_data_type = d_NULL;

// **************************************************************************************************************************

char * data_type_to_string(is_data_type);

// **************************************************************************************************************************

int check_program(is_program *);

int check_program_heading(is_program_heading *);

int check_program_block(is_program_block *);

// **************************************************************************************************************************

int check_variable_declaration_part(is_variable_declaration_part *, unsigned);

int check_variable_declaration(is_variable_declaration *, unsigned);

// **************************************************************************************************************************

int check_function_list(is_function_list *);

int check_function(is_function *);

int check_function_argument_list(is_function_argument_list *, is_var_name *, unsigned);

int check_function_argument(is_function_argument *, is_var_name *, unsigned);

// **************************************************************************************************************************

int check_statement_list(is_statement_list *, unsigned);

int check_statement(is_statement *, unsigned);

int check_assignment_statement(is_assignment_statement *, unsigned);

int check_function_call(is_function_call *, unsigned);

int check_function_call_argument_list(is_function_call_argument_list *, is_function_call *, unsigned);

int check_writeln_statement(is_writeln_statement *, unsigned);

int check_if_statement(is_if_statement *, unsigned);

int check_while_statement(is_while_statement *, unsigned);

// **************************************************************************************************************************

int check_expression(is_expression *, unsigned);

int check_infix_expression(is_infix_expression *, unsigned);

int check_logical_expression(is_logical_expression *, unsigned);

int check_infix_logical_expression(is_infix_logical_expression *, unsigned);

int check_internal_logical_expression(is_internal_logical_expression *, unsigned);

// **************************************************************************************************************************

int check_string(is_string *);

int check_var_name_list(is_var_name_list *, unsigned);

int check_var_name(is_var_name *, unsigned);

int check_digit_sequence(is_digit_sequence *, unsigned);

int check_boolean(unsigned, unsigned);

