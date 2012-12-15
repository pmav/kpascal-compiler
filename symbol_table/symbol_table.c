/**
 * Compiladores 2008/2009
 *
 * Pedro Miguel de Almeida Verruma
 * verruma@student.dei.uc.pt
 * Nº 2006128853
 *
 * Nota: parte do código presente neste ficheiro foi retirado de uma ficha prática.
 */

#include "symbol_table.h"
#include <malloc.h>
#include <string.h>
#include <stdio.h>

extern table_element *symbol_table;
extern function_element *function_table;

table_element *insert_el(char *str, is_data_type idt, unsigned scope_id) {
    //printf("Inserting symbol '%s', type %d\n", str, idt);

	table_element *new_symbol = (table_element*) malloc(sizeof(table_element));
	table_element *temp;
	table_element* previous;

	strcpy(new_symbol->name, str);
	new_symbol->data_type = idt;
    new_symbol->scope_id = scope_id;
	new_symbol->next = NULL;

	if(symbol_table) {
		for(temp = symbol_table; temp; previous = temp, temp = temp->next) {
			if(strcmp(temp->name, str) == 0 && temp->scope_id == scope_id) {
				return NULL;
            }
		}

		previous->next = new_symbol;

	} else {
		symbol_table = new_symbol;		
	}

	return new_symbol; 
}




table_element *search_el(char *var_name, unsigned scope_id) { /* TODO: change name */
    //printf("Searching symbol '%s' with scope id: %d\n", var_name, scope_id);
    table_element *temp;

    for(temp = symbol_table; temp; temp = temp->next) {
	    if(strcmp(temp->name, var_name) == 0 && (temp->scope_id == scope_id || temp->scope_id == SUPER_GLOBAL)) {
	    	return temp;
        }
    }

    return NULL;
}



table_element * get_element(unsigned position) {
    unsigned actual_position = 0;

    table_element *temp;
    for(temp = symbol_table; temp; temp = temp->next, actual_position++) {
        if (actual_position == position) {
            return temp;
        }
    }

    return NULL;
}



int element_position(char * var_name, unsigned scope_id) {
    int position = 0;

    table_element *temp;
    for(temp = symbol_table; temp; temp = temp->next) {
	    if(strcmp(temp->name, var_name) == 0 && (temp->scope_id == scope_id || temp->scope_id == SUPER_GLOBAL)) {
	    	return position;
        }
        position++;
    }

    return position;
}




void show_symbol_table() {
    table_element *temp;
    printf("\n");

    for(temp=symbol_table; temp; temp=temp->next) {
    	printf("type: %d, id: %d ('%s')\n", temp->data_type, temp->scope_id, temp->name);
    }
}




function_element * insert_function_symbol(char * function_name) {
	function_element *new_symbol = (function_element*) malloc(sizeof(function_element));
	function_element *temp;
	function_element* previous;

	strcpy(new_symbol->name, function_name);
    new_symbol->id = function_id;
	new_symbol->next = NULL;
    function_id++;

	if(function_table) {
		for(temp = function_table; temp; previous = temp, temp = temp->next) {
			if(strcmp(temp->name, function_name) == 0) {
				return NULL;
            }
		}

		previous->next = new_symbol;

	} else {
		function_table = new_symbol;		
	}

	return new_symbol;
}



function_element * search_function_symbol(char * function_name) {
    function_element *temp;

    for(temp = function_table; temp; temp = temp->next) {
	    if(strcmp(temp->name, function_name) == 0) {
	    	return temp;
        }
    }

    return NULL;
}


int function_position(char * function_name) {
    int position = 0;

    function_element *temp;
    for(temp = function_table; temp; temp = temp->next) {
	    if(strcmp(temp->name, function_name) == 0) {
	    	return position;
        }
        position++;
    }

    return position;
}
