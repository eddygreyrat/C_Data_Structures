/**
 * @file linked_list.h
 * @author your name (you@domain.com)
 * @brief linked list library. 
 * error codes:
 *   0 = no error
 *   1 = user error
 *  -1 = fatel error 
 * @version 1.2
 * @date 2023-09-02
 * 
 * @copyright Copyright (c) 2023
 * 
**/

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

/*** includes ***/
#include <stdint.h>

/*** structs ***/
typedef struct node node_t;

typedef struct node {
    int item;
    node_t *next_node;
}node_t;

typedef struct linked_list {
    node_t *list_head;
    node_t *list_tail;
    uint8_t is_empty;
}linked_list_t;


/*** function declaration ***/
int8_t   linked_list_create   (linked_list_t **list);
int8_t   linked_list_destroy  (linked_list_t **list);
int8_t   linked_list_insert_at(linked_list_t **list, uint64_t index, int value);
int8_t   linked_list_push     (linked_list_t **list, int value);
int8_t   linked_list_append   (linked_list_t **list, int value);
// int linked_list_delete_at();
// int linked_list_pop();
// int linked_list_remove();
// int linked_list_reverse();
int8_t   linked_list_print    (linked_list_t *list);
uint64_t linked_list_size     (linked_list_t *list);


#endif //_LINKED_LIST_H_