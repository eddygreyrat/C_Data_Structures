/**
 * @file linked_list.h
 * @author your name (you@domain.com)
 * @brief linked list library. 
 * error codes:
 *   0 = no error
 *   1 = user error
 *  -1 = fatal error 
 * @version 1.7
 * @date 2023-09-09
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
    LL_EXIT_SUCCESS = 0,
    LL_EXIT_FATAL = -1,
    LL_EXIT_USER = 1
};

/*** structs ***/
typedef struct node node_t;

typedef struct node {
    int item;
    node_t *next_node;
}node_t;

typedef struct linked_list {
    node_t  *list_head; // first node
    node_t  *list_tail; // last node
    uint64_t size;      // total nodes
}linked_list_t;


/*** function declaration ***/
int8_t   linked_list_create        (linked_list_t **list);
int8_t   linked_list_destroy       (linked_list_t **list);
int8_t   linked_list_insert_at     (linked_list_t **list, uint64_t index, int value);
int8_t   linked_list_push          (linked_list_t **list, int value);
int8_t   linked_list_append        (linked_list_t **list, int value);
int8_t   linked_list_delete_at     (linked_list_t **list, uint64_t index);
int8_t   linked_list_pop           (linked_list_t **list);
int8_t   linked_list_remove        (linked_list_t **list);
int8_t   linked_list_reverse       (linked_list_t **list);
int8_t   linked_list_value_at      (linked_list_t *list, uint64_t index); // returns err code not value
int8_t   linked_list_value_at_head (linked_list_t *list);
int8_t   linked_list_value_at_tail (linked_list_t *list);
int8_t   linked_list_print_list    (linked_list_t *list);
int8_t   linked_list_print_status  (linked_list_t *list);
void     linked_list_print_err_code(int8_t err_code);
uint64_t linked_list_size          (linked_list_t *list);


#endif //_LINKED_LIST_H_