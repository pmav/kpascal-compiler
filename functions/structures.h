/**
 * Compiladores 2008/2009
 *
 * Pedro Miguel de Almeida Verruma
 * verruma@student.dei.uc.pt
 * Nº 2006128853
 */

#ifndef _STRUCTURES_
#define _STRUCTURES_

unsigned line_number; /* Add line number information on error (syntax and semantic) */

unsigned statement_id; /* Each statement (if, while, ...) have a unique ID */

unsigned call_id;

typedef enum {
    d_FALSE, d_TRUE 
} boolean;

// **************************************************************************************************************************

typedef enum {
    d_INTEGER, d_BOOLEAN, d_CHAR, d_STRING, d_REAL, d_NULL
} is_data_type; /* TODO: change name */


typedef enum {
    d_PLUS, d_MINUS, d_STAR, d_DIV, d_MOD
} is_operator; /* TODO: change name */


typedef enum {
    d_EQUAL, d_GT, d_LT, d_GE, d_LE, d_NOTEQUAL, d_AND, d_OR, d_DUMMY /* dummy is used for logical expressions without ilo */
} is_logical_operator; /* TODO: change name */


typedef enum {
    d_ASSIGNMENT, d_WRITELN, d_IF, d_WHILE
} is_statement_type; /* TODO: change name */


typedef enum {
    d_EXP_VAR_NAME, d_EXP_STRING, d_EXP_DIGIT_SEQUENCE, d_EXP_INFIX_EXPRESSION, d_EXP_BOOLEAN, d_EXP_FUNCTION_CALL
} expression_type;


typedef enum {
    d_LOG_INTERNAL_LOGICAL, d_LOG_INFIX_LOGICAL
} logical_type;


typedef enum {
    d_ARG_STRING, d_ARG_EXPRESSION
} argument_type;


typedef enum {
    d_DIGSEQ_INTEGER, d_DIGSEQ_FLOAT
} digit_sequence_type;


typedef enum {
    d_SINGLE_STATEMENT, d_LIST_STATEMENT
} block_type;

// **************************************************************************************************************************

/* is_program -> (<program_heading: is_program_heading> <program_block: is_program_block>) */
typedef struct _a1 {
    struct _a2 *program_heading;
    struct _a3 *program_block;
} is_program;


/* is_program_heading -> (<var_name : is_var_name>) */
typedef struct _a2 {
    struct _a4 *var_name;
} is_program_heading;


/* is_program_block -> (<variable_declaration_part : is_variable_declaration_part><function_list : is_function_list><statement_list : is_statement_list>) */
typedef struct _a3 {
    struct _a5 *variable_declaration_part;
    struct _a27 *function_list;
    struct _a6 *statement_list;
} is_program_block;

// **************************************************************************************************************************

/* is_variable_declaration_part */
typedef struct _a5 {
    struct _a7 *variable_declaration;
    struct _a5 *next;
} is_variable_declaration_part; /* TODO: rename struct */


/* is_variable_declaration -> (<var_name_list : is_var_name_list> <data_type : is_data_type>) */
typedef struct _a7 {
    struct _a16 *var_name_list;
    is_data_type data_type;
} is_variable_declaration;


/* is_var_name_list */
typedef struct _a16 {
    struct _a4 *var_name;
    struct _a16 *next;
} is_var_name_list;


/* is_var_name -> (<var_name : is_var_name> <line_number : unsigned>) */
typedef struct _a4 {
    char *var_name;
    unsigned line_number;
} is_var_name;

// **************************************************************************************************************************

/* is_function_list */
typedef struct _a27 {
    struct _a28 *function;
    struct _a27 *next;
} is_function_list;


/* is_function -> (<function_name : is_function_name> <function_argument_list : is_function_argument_list> <data_type : is_data_type> <variable_declaration_part : is_variable_declaration_part> <statement_list : is_statement_list> <line_number : unsigned>) */
typedef struct _a28 {
    struct _a4 *function_name;
    struct _a29 *function_argument_list;
    is_data_type data_type; /* Return datatype */
    struct _a5 *variable_declaration_part;
    struct _a6 *statement_list;
    unsigned line_number;
} is_function;


/* is_function_argument_list */
typedef struct _a29 {
    struct _a30 *function_argument;
    struct _a29 *next;
} is_function_argument_list;


/* is_function_argument -> (<var_name_list : is_var_name_list> <data_type : is_data_type> <line_number : unsigned>) */
typedef struct _a30 {
    struct _a16 *var_name_list;
    is_data_type data_type;
    unsigned line_number;
} is_function_argument;

// **************************************************************************************************************************

/* is_statement_list */
typedef struct _a6 {
    struct _a9 *statement;
    struct _a6 *next;
} is_statement_list;


/* is_statement -> is_assignment_statement v is_writeln_statement v is_if_statement v is_while_statement */
typedef struct _a9 {
    union {
        struct _a10 *assignment_statement;
        struct _a11 *writeln_statement;
        struct _a22 *if_statement;
        struct _a23 *while_statement;
    } data_d1; /* TODO: change name */
    is_statement_type statement_type;
} is_statement;


/* is_assignment_statement -> (<var_name : is_var_name> <expression : is_expression> <statement_id : unsigned>) */
typedef struct _a10 {
    struct _a4 *var_name;
    struct _a12 *expression;
    unsigned statement_id;
} is_assignment_statement;


/* is_function_call -> (<var_name : is_var_name> <function_call_argument_list : is_function_call_argument_list> <call_id : unsigned> <line_number : unsigned>) */
typedef struct _a31 {
    struct _a4 *var_name;
    struct _a32 *function_call_argument_list;
    unsigned call_id; /* UID for each call of one function */
    unsigned line_number;
} is_function_call;


/* is_function_call_argument_list */
typedef struct _a32 {
    struct _a12 *expression;
    struct _a32 *next;
} is_function_call_argument_list;


/* is_writeln_statement -> (<writeln_argument_list : is_writeln_argument_list>) */
typedef struct _a11 {
    struct _a19 *writeln_argument_list;
} is_writeln_statement;


/* is_expression -> (<data_d2: is_var_name v is_digit_sequence v is_string v is_infix_expression v is_function_call>  <data_type : is_data_type> <line_number : unsigned>) */
typedef struct _a12 {
    union {
        struct _a4 *var_name;
        struct _a13 *digit_sequence;
        struct _a18 *string;
        struct _a14 *infix_expression;
        struct _a31 *function_call;
        unsigned boolean;
    } data_d2; /* TODO: change name */
    expression_type expression_type; // Expression type: var_name, string, digseq, infix
    is_data_type data_type; // Expression data type: integer, real, boolean
    unsigned line_number;
} is_expression;


/* is_digit_sequence -> is_digit_sequence v is_float_digit_sequence */
typedef struct _a13 {
    union {
        int digit_sequence;
        float float_digit_sequence;
    } data;
    digit_sequence_type type;
} is_digit_sequence;


/* is_infix_expression -> (<expression1 : is_expression> <expression2 : is_expression> <oper : is_operator>) */
typedef struct _a14 {
    struct _a12 *expression1;
    struct _a12 *expression2;
    is_operator oper;
} is_infix_expression;


/* is_writeln_argument_list */
typedef struct _a19 {
    struct _a17 *writeln_argument;
    struct _a19 *next;
} is_writeln_argument_list;


/* is_writeln_argument -> is_expression v is_string */
typedef struct _a17 {
    union {
        struct _a12 *expression;
        struct _a18 *string;
    } data_d3;
    argument_type argument_type;
} is_writeln_argument;


/* is_string -> (<string : char*>) */
typedef struct _a18 {
    char *string;
} is_string;


/* is_logical_expression -> is_internal_logical_expression v is_infix_logical_expression */
typedef struct _a21 {
    union {
        struct _a25 *internal_logical_expression;
        struct _a26 *infix_logical_expression;
    } data_d4;
    logical_type logical_type;
} is_logical_expression;


/* is_internal_logical_expression -> (<expression1 : is_expression> <expression2 : is_expression> <logical_operator : is_logical_operator>) */
typedef struct _a25 {
    struct _a12 *expression1;
    struct _a12 *expression2;
    is_logical_operator logical_operator; /* <, >, <=, >=, <>, ==, ... */
} is_internal_logical_expression;


/* is_infix_logical_expression -> (<logical_expression1 : is_logical_expression> <logical_expression2 : is_logical_expression> <logical_operator : is_logical_operator>) */
typedef struct _a26 {
    struct _a21 *logical_expression1;
    struct _a21 *logical_expression2;
    is_logical_operator logical_operator; /* AND, OR, ... */
} is_infix_logical_expression;


/* is_if_statement -> (<then_block : statement_list v statement> <else_block : statement_list v statement> <have_block_else : boolean> <statement_id : unsigned>) */
typedef struct _a22 { /* TODO: add else block */
    struct _a21 *logical_expression;

    union {
        struct _a6 *statement_list;
        struct _a9 *statement;
    } then_block;
    block_type then_block_type;

    union {
        struct _a6 *statement_list;
        struct _a9 *statement;
    } else_block;
    block_type else_block_type;

    boolean have_else_block;

    unsigned statement_id;
} is_if_statement;


/* is_while_statement -> (<logical_expression : is_logical_expression> <statement_list : is_statement_list> <statement_id : unsigned>) */
typedef struct _a23 {
    struct _a21 *logical_expression;
    struct _a6 *statement_list;
    unsigned statement_id;
} is_while_statement;


/* is_boolean -> (<boolean : unsigned>) */
typedef struct _a24 {
    unsigned boolean;
} is_boolean;

#endif
