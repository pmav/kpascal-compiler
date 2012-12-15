/**
 * Compiladores 2008/2009
 *
 * Pedro Miguel de Almeida Verruma
 * verruma@student.dei.uc.pt
 * Nº 2006128853
 */

// **************************************************************************************************************************

is_program * insert_program(is_program_heading *, is_program_block *);

is_program_heading * insert_program_heading(is_var_name *);

is_program_block * insert_program_block(is_variable_declaration_part *, is_function_list *, is_statement_list *);

// **************************************************************************************************************************

is_variable_declaration_part * insert_variable_declaration_part(is_variable_declaration_part *, is_variable_declaration *);

is_variable_declaration * insert_variable_declaration(is_var_name_list *, is_data_type);

is_var_name_list * insert_var_name_list(is_var_name_list *, is_var_name *);

// **************************************************************************************************************************

is_function_list * insert_function_list(is_function_list *, is_function *);

is_function * insert_function(is_var_name *, is_function_argument_list *, is_data_type, is_variable_declaration_part *, is_statement_list *, unsigned);

is_function_argument_list * insert_function_argument_list(is_function_argument_list *, is_function_argument *);

is_function_argument * insert_function_argument(is_var_name_list *, is_data_type, unsigned);

is_function_call * insert_function_call(is_var_name *, is_function_call_argument_list *, unsigned);

is_function_call_argument_list * insert_function_call_argument_list(is_function_call_argument_list *, is_expression *);

// **************************************************************************************************************************

is_statement_list * insert_statement_list(is_statement_list *, is_statement *);

is_statement * insert_statement_writeln(is_writeln_statement *);

is_statement * insert_statement_assignment(is_assignment_statement *);

is_statement * insert_statement_if(is_if_statement *);

is_statement * insert_statement_while(is_while_statement *);

// **************************************************************************************************************************

is_while_statement * insert_while_statement(is_logical_expression *, is_statement_list *);

is_if_statement * insert_if_statement_single_then(is_logical_expression *, is_statement *);

is_if_statement * insert_if_statement_list_then(is_logical_expression *, is_statement_list *);

is_if_statement * insert_if_statement_single_then_single_else(is_logical_expression *, is_statement *, is_statement *);

is_if_statement * insert_if_statement_single_then_list_else(is_logical_expression *, is_statement *, is_statement_list *);

is_if_statement * insert_if_statement_list_then_single_else(is_logical_expression *, is_statement_list *, is_statement *);

is_if_statement * insert_if_statement_list_then_list_else(is_logical_expression *, is_statement_list *, is_statement_list *);

is_assignment_statement * insert_assignment_statement_expression(is_var_name *, is_expression *);

is_writeln_statement * insert_writeln_statement(is_writeln_argument_list *);

is_writeln_argument_list * insert_writeln_argument_list(is_writeln_argument_list *, is_writeln_argument *);

is_writeln_argument * insert_writeln_argument_string(is_string *);

is_writeln_argument * insert_writeln_argument_expression(is_expression *);

// **************************************************************************************************************************

is_expression * insert_expression_string(is_string *, unsigned);

is_expression * insert_expression_digit_sequence(is_digit_sequence *, unsigned);

is_expression * insert_expression_var_name(is_var_name *, unsigned);

is_expression * insert_expression_bool(unsigned, unsigned);

is_expression * insert_expression_function_call(is_function_call *, unsigned);

is_expression * insert_operator(is_expression *, is_expression *, is_operator, unsigned);

is_logical_expression * insert_logical_expression(is_logical_expression *, is_logical_expression *, is_logical_operator);

is_logical_expression * insert_logical_expression_internal(is_internal_logical_expression *);

is_internal_logical_expression * insert_internal_logical_expression(is_expression *, is_expression *, is_logical_operator);

// **************************************************************************************************************************

is_digit_sequence * insert_digit_sequence(int);

is_digit_sequence * insert_float_digit_sequence(float);

is_var_name * insert_var_name(char *, unsigned);

is_string * insert_string(char *);

