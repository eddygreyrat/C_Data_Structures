/**
 * @file link_list.h
 * @author your name (you@domain.com)
 * @brief linked list library. 
 * error codes:
 *  0  = no error
 *  1  = user error
 *  -1 = fatel error 
 * @version 1.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
**/

#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

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
}linked_list_t;


/*** function declaration ***/
int8_t linked_list_create(linked_list_t **list, int value);
int8_t linked_list_destory(linked_list_t **list);
uint64_t linked_list_size(linked_list_t *list);
int8_t linked_list_insert_at(linked_list_t **list, uint64_t index, int value);
// int linked_list_push();
// int linked_list_append();
// int linked_list_delete_at();
// int linked_list_remove();
// int linked_list_reverse();
int8_t linked_list_print(linked_list_t *list);


#endif //_LINK_LIST_H_