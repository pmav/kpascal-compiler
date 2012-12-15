/**
 * Compiladores 2008/2009
 *
 * Pedro Miguel de Almeida Verruma
 * verruma@student.dei.uc.pt
 * Nº 2006128853
 */

%{

#include <stdio.h>
#include <stdlib.h>
#include "../functions/structures.h"
#include "../functions/functions.c"
#include "../symbol_table/symbol_table.c"
#include "../semantics/semantics.c"
#include "../translate/translate.c"

table_element *symbol_table;
function_element *function_table;

is_program *my_program;

%}
%right EQUAL
%left MINUS PLUS
%left STAR DIV MOD 
%left AND OR
%nonassoc UMINUS

%token PROGRAM VAR FUNCTION ASSIGNMENT IF THEN ELSE WRITELN WHILE DO DOT PBEGIN END
%token COLON SEMICOLON COMMA
%token SLASH STAR MINUS PLUS DIV MOD
%token EQUAL GE GT LE LT NOTEQUAL AND OR LPAREN RPAREN 
%token DTINTEGER DTBOOLEAN DTCHAR DTSTRING DTREAL TRUE FALSE

%union {
 char* string;
 char* identifier;
 unsigned digseq;
 float fdigseq;

 int fr; /* function_return */

 struct _a1  *ip;  /* is_program */
 struct _a2  *ph;  /* is_program_heading */
 struct _a3  *pb;  /* is_program_block */
 struct _a4  *vn;  /* is_var_name */ 
 struct _a5  *vdp; /* is_variable_declaration_part */
 struct _a7  *vd;  /* is_variable_declaration */
 struct _a16 *vnl; /* is_var_name_list */
 struct _a6  *sp;  /* is_statement_list */
 struct _a9  *st;  /* is_statement */
 struct _a10 *as;  /* is_assignment_statement */
 struct _a11 *ws;  /* is_writeln_statement */
 struct _a13 *ds;  /* is_digit_sequence */
 struct _a17 *wa;  /* is_writeln_argument */
 struct _a19 *wal; /* is_writeln_argument_list */
 struct _a18 *s;   /* is_string */
 struct _a12 *ex;  /* is_expression */
 struct _a21 *le;  /* is_logical_expression */
 struct _a25 *ile; /* is_internal_logical_expression */
 struct _a22 *is;  /* is_if_statement */
 struct _a23 *whs; /* if_while_statement */
 struct _a12 *be;  /* is_expression */
 struct _a30 *fa;  /* is_function_argument */
 struct _a29 *fal; /* is_function_argument_list */
 struct _a28 *f;   /* is_function */
 struct _a27 *fl;  /* is_function_list */
 struct _a31 *fc;  /* is_function_call */
 struct _a32 *fcal;/* is_function_call_argument_list */
}

%token <string> STRING
%token <identifier> IDENTIFIER
%token <digseq> DIGSEQ
%token <fdigseq> FDIGSEQ

%type <vn> var_name
%type <ds> digit_sequence
%type <s> string
%type <ip> program
%type <ph> program_heading
%type <pb> program_block
%type <vdp> variable_declaration_part
%type <vd> variable_declaration
%type <vnl> var_name_list
%type <sp> statement_list
%type <st> statement
%type <as> assignment_statement
%type <ws> writeln_statement
%type <wal> writeln_argument_list
%type <wa> writeln_argument
%type <ex> expression
%type <le> logical_expression
%type <ile> internal_logical_expression
%type <is> if_statement
%type <whs> while_statement
%type <be> boolean_expression
%type <fa> function_argument
%type <fal> function_argument_list
%type <f> function
%type <fl> function_list
%type <fc> function_call
%type <fcal> function_call_argument_list
%type <fr> function_return

%%

program :
 program_heading SEMICOLON program_block DOT { $$ = insert_program($1, $3); my_program = $$; }
 ;

program_heading :
 PROGRAM var_name { $$ = insert_program_heading($2); }
 ;

program_block :
   VAR variable_declaration_part function_list PBEGIN statement_list END { $$ = insert_program_block($2, $3, $5); }
 | VAR variable_declaration_part PBEGIN statement_list END { $$ = insert_program_block($2, NULL, $4); }
 | function_list PBEGIN statement_list END { $$ = insert_program_block(NULL, $1, $3); }
 | PBEGIN statement_list END { $$ = insert_program_block(NULL, NULL, $2); }
 ;

// **************************************************************************************************************************

variable_declaration_part :
   variable_declaration { $$ = insert_variable_declaration_part(NULL, $1); }
 | variable_declaration_part variable_declaration { $$ = insert_variable_declaration_part($1, $2); }
 ;

variable_declaration :
   var_name_list COLON DTINTEGER SEMICOLON { $$ = insert_variable_declaration($1, d_INTEGER); }
 | var_name_list COLON DTBOOLEAN SEMICOLON { $$ = insert_variable_declaration($1, d_BOOLEAN); }
 | var_name_list COLON DTREAL SEMICOLON { $$ = insert_variable_declaration($1, d_REAL); }
 ;

var_name_list :
   var_name_list COMMA var_name { $$ = insert_var_name_list($1, $3); }
 | var_name { $$ = insert_var_name_list(NULL, $1); }
 ;

// **************************************************************************************************************************

function_list:
   function_list function { $$ = insert_function_list($1, $2); }
 | function { $$ = insert_function_list(NULL, $1); }
 ;

function:
   FUNCTION var_name LPAREN function_argument_list RPAREN COLON function_return SEMICOLON VAR variable_declaration_part PBEGIN statement_list END SEMICOLON { $$ = insert_function($2, $4, $7, $10, $12, line_number); }
 | FUNCTION var_name LPAREN function_argument_list RPAREN COLON function_return SEMICOLON PBEGIN statement_list END SEMICOLON { $$ = insert_function($2, $4, $7, NULL, $10, line_number); }
 ;

function_argument_list:
   function_argument_list SEMICOLON function_argument { $$ = insert_function_argument_list($1, $3); }
 | function_argument { $$ = insert_function_argument_list(NULL, $1); }
 | { $$ = NULL; }
 ;

function_argument:
 var_name_list COLON function_return { $$ = insert_function_argument($1, $3, line_number); }
 ;

function_return:
   DTINTEGER { $$ = d_INTEGER; }
 | DTREAL { $$ = d_REAL; }
 | DTBOOLEAN { $$ = d_BOOLEAN; }
 ;

// **************************************************************************************************************************

statement_list :
   statement_list statement { $$ = insert_statement_list($1, $2); }
 | statement { $$ = insert_statement_list(NULL, $1); }
 ;

statement :
   while_statement { $$ = insert_statement_while($1); }
 | if_statement { $$ = insert_statement_if($1); }
 | assignment_statement { $$ = insert_statement_assignment($1); }
 | writeln_statement { $$ = insert_statement_writeln($1); }
 ;

// **************************************************************************************************************************

while_statement :
 WHILE logical_expression DO PBEGIN statement_list END SEMICOLON { $$ = insert_while_statement($2, $5); }
 ;

if_statement :
   // Only THEN PART
   IF logical_expression THEN statement { $$ = insert_if_statement_single_then($2, $4); }
 | IF logical_expression THEN PBEGIN statement_list END SEMICOLON { $$ = insert_if_statement_list_then($2, $5); }

   // SIMPLE THEN PART
 | IF logical_expression THEN statement ELSE statement { $$ = insert_if_statement_single_then_single_else($2, $4, $6); }
 | IF logical_expression THEN statement ELSE PBEGIN statement_list END SEMICOLON { $$ = insert_if_statement_single_then_list_else($2, $4, $7); }

   // COMPLEX THEN PART
 | IF logical_expression THEN PBEGIN statement_list END SEMICOLON ELSE statement { $$ = insert_if_statement_list_then_single_else($2, $5, $9); }
 | IF logical_expression THEN PBEGIN statement_list END SEMICOLON ELSE PBEGIN statement_list END SEMICOLON { $$ = insert_if_statement_list_then_list_else($2, $5, $10); }
 ;

assignment_statement :
 var_name ASSIGNMENT expression SEMICOLON { $$ = insert_assignment_statement_expression($1, $3); }
 ;

function_call:
 var_name LPAREN function_call_argument_list RPAREN { $$ = insert_function_call($1, $3, line_number); }
 ;

function_call_argument_list:
   function_call_argument_list COMMA expression { $$ = insert_function_call_argument_list($1, $3); }
 | expression { $$ = insert_function_call_argument_list(NULL, $1); }
 | { $$ = NULL; }
 ;

writeln_statement :
 WRITELN LPAREN writeln_argument_list RPAREN SEMICOLON { $$ = insert_writeln_statement($3); }
 ;

writeln_argument_list :
   writeln_argument_list COMMA writeln_argument { $$ = insert_writeln_argument_list($1, $3); }
 | writeln_argument { $$ = insert_writeln_argument_list(NULL, $1); }
 ;

writeln_argument :
   string { $$ = insert_writeln_argument_string($1); }
 | expression { $$ = insert_writeln_argument_expression($1); }
 ;

// **************************************************************************************************************************

logical_expression :
   logical_expression AND logical_expression { $$ = insert_logical_expression($1, $3, d_AND); }
 | logical_expression OR logical_expression { $$ = insert_logical_expression($1, $3, d_OR); }
 | LPAREN logical_expression RPAREN { $$ = $2; }
 | internal_logical_expression { $$ = insert_logical_expression_internal($1); }
 ;

internal_logical_expression :
   expression EQUAL expression { $$ = insert_internal_logical_expression($1, $3, d_EQUAL); }
 | expression GT expression { $$ = insert_internal_logical_expression($1, $3, d_GT); }
 | expression LT expression { $$ = insert_internal_logical_expression($1, $3, d_LT); }
 | expression GE expression { $$ = insert_internal_logical_expression($1, $3, d_GE); }
 | expression LE expression { $$ = insert_internal_logical_expression($1, $3, d_LE); }
 | expression NOTEQUAL expression { $$ = insert_internal_logical_expression($1, $3, d_NOTEQUAL); }
 | expression { $$ = insert_internal_logical_expression($1, NULL, d_DUMMY); }
 ;

expression :
   expression PLUS expression { $$ = insert_operator($1, $3, d_PLUS, line_number); }
 | expression MINUS expression { $$ = insert_operator($1, $3, d_MINUS, line_number); }
 | expression DIV expression { $$ = insert_operator($1, $3, d_DIV, line_number); }
 | expression STAR expression { $$ = insert_operator($1, $3, d_STAR, line_number); }
 | expression MOD expression { $$ = insert_operator($1, $3, d_MOD, line_number); }
 | LPAREN expression RPAREN { $$ = $2; }
 | digit_sequence { $$ = insert_expression_digit_sequence($1, line_number); }
 | var_name { $$ = insert_expression_var_name($1, line_number); }
 | function_call { $$ = insert_expression_function_call($1, line_number); }
 | boolean_expression { $$ = $1; }
 ;

boolean_expression : 
   TRUE { $$ = insert_expression_bool(1, line_number); }
 | FALSE { $$ = insert_expression_bool(0, line_number); }
 ;

// **************************************************************************************************************************

var_name :
 IDENTIFIER { $$ = insert_var_name($1, line_number); }
 ;

digit_sequence :
   MINUS DIGSEQ { $$ = insert_digit_sequence(-$2); }
 | DIGSEQ { $$ = insert_digit_sequence($1); }
 | MINUS FDIGSEQ { $$ = insert_float_digit_sequence(-$2); }
 | FDIGSEQ { $$ = insert_float_digit_sequence($1); }
 ;

string :
 STRING { $$ = insert_string($1); }
 ;

%%


int yyerror (char *error_message) {
    printf ("ERROR at line %u: %s!\n", line_number, error_message);
    return 0;
}


int main() {

    int errors = 0;
    line_number = 1;
    statement_id = 0;

    if(yyparse() == 0) {
        printf("Syntax...: 0 errors\n");

        errors = check_program(my_program);

        printf("Semantic.: %d %s\n", errors, errors == 1 ? "error" : "errors");

        //show_symbol_table();

        if (errors == 0) {
            translate_program(my_program);
        }

    }

    return 0;
}

