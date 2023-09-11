/**
 * @file linked_list.h
 * @author your name (you@domain.com)
 * @brief linked list library. 
 * TODO: 
 *  - implement the following;
 *      - sort_bubble()
 *      - sort_quick()
 *      - sort_...etc
 *  - rename functions
 *      - push() -> prepend? might keep current naming convention
 *  - MACRO WRAPPER
 *      - generalize linked list to accept any data types
 *  - improve 
 *      - error codes
 *          - currently only have 3 different error codes
 *          - add more to be more specific for user to read
 *      - documentation
 *          - document .h file 
 *          - improve function documentation in .c file
 *      - add a overflow check. if uint64_t size == UINT64_MAX
 *          - stop function from adding to linked list.
 * @version 1.7.3
 * @date 2023-09-10
 * 
 * @copyright Copyright (c) 2023
 * 
**/

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

/*** includes ***/
#include <stdint.h>

/*** enums ***/
enum err_code {
    LL_EXIT_SUCCESS =  0,
    LL_EXIT_FATAL   = -1,
    LL_EXIT_USER    =  1
};

/*** structs ***/
typedef struct node node_t;

typedef struct node {
    int item;
    node_t *next_node;
} node_t;

typedef struct linked_list {
    node_t  *list_head; // first node
    node_t  *list_tail; // last node
    uint64_t size;      // total nodes
} linked_list_t;


/*** function declaration ***/
// functions to initialize linked list object
int8_t linked_list_create(
    linked_list_t **list
);
int8_t linked_list_destroy(
    linked_list_t **list
);

// functions to add nodes in linked list
int8_t linked_list_insert_at(
    linked_list_t **list, 
    uint64_t index, 
    int value
);
int8_t linked_list_push(
    linked_list_t **list, 
    int value
);
int8_t linked_list_append(
    linked_list_t **list, 
    int value
);

// functions to delete nodes in linked list
int8_t linked_list_delete_at(
    linked_list_t **list, 
    uint64_t index
);
int8_t linked_list_pop(
    linked_list_t **list
);
int8_t linked_list_remove(
    linked_list_t **list
);


// functions to replace valuse stored in nodes
int8_t linked_list_replace_at(
    linked_list_t **list,
    uint64_t index,
    int new_item
);
int8_t linked_list_replace_head(
    linked_list_t **list,
    int new_item
);
int8_t linked_list_replace_tail(
    linked_list_t **list,
    int new_item
);


// functions to retrieve values stored in nodes
int8_t linked_list_value_at(
    linked_list_t *list, 
    uint64_t index, 
    int *ret_val
); 
int8_t linked_list_value_at_head(
    linked_list_t *list, 
    int *ret_val
);
int8_t linked_list_value_at_tail(
    linked_list_t *list, 
    int *ret_val
);


// functions to re-arrange linked list
int8_t linked_list_reverse(
    linked_list_t **list
);


// functions to debug linked list 
int8_t linked_list_print_list(
    linked_list_t *list
);
int8_t linked_list_print_status(
    linked_list_t *list
);
void linked_list_print_err_code(
    int8_t err_code
);
uint64_t linked_list_size(
    linked_list_t *list
);
int8_t linked_list_search_for(
    linked_list_t *list,
    int value,
    uint64_t *ret_index
);


#endif //_LINKED_LIST_H_