/**
 * Compiladores 2008/2009
 *
 * Pedro Miguel de Almeida Verruma
 * verruma@student.dei.uc.pt
 * Nº 2006128853
 */

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define SUPER_GLOBAL 0
#define GLOBAL_SCOPE 1

unsigned function_id = 2;

/**
 *  0: super global - functions
 *  1: global - main
 * >1: local
 */

typedef struct _t1 {
    char name[32];
    unsigned scope_id; /* function UID, 0 if global */
    is_data_type data_type;
    struct _t1 *next;
} table_element;


typedef struct _t2 {
    char name[32];
    unsigned number_arguments;
    unsigned id; /* UID for each function */
    struct _t3 *function_argument_id;
    struct _t2 *next;
} function_element;


typedef struct _t3 {
    unsigned id; /* final variable position for each argument */
    struct _t3 *next;
} function_argument_id;


table_element * insert_el(char *, is_data_type, unsigned);

table_element * search_el(char *, unsigned);

table_element * get_element(unsigned);

int element_position(char *, unsigned);

void show_symbol_table();

function_element * insert_function_symbol(char *);

function_element * search_function_symbol(char *);

int function_position(char *);

#endif

