/**
 * @file linked_list.c
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
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>


int8_t linked_list_create(linked_list_t **list, int value) {
    /**
     * @brief  initialized a linked list object with 'value' stored in the first node
     * 
     * @param  list     the linked list object
     * @param  value    the value to store in the first node
     * @return int8_t   error code; -1 = fatel error, 0 = no error, 1 = user error
    **/
    // check if list already exist
    if ( *list != NULL ){
        return 1;
    }

    // create list
    if (
        ( *list = (linked_list_t *) malloc(sizeof(linked_list_t)) )
        == NULL
    ) {
        return -1;
    }

    // create first node
    if (
        ( (*list)->list_head = (node_t *) malloc(sizeof(node_t)) )
        == NULL
    ) {
        return -1;
    }

    // init
    (*list)->list_tail = NULL;
    (*list)->list_head->item = value;
    (*list)->list_head->next_node = NULL;

    return 0;
}


int8_t linked_list_destroy(linked_list_t **list) {
    /**
     * @brief  frees all the memory allocated to a linked list
     * 
     * @param  list     the linked list to free
     * @return int8_t   error code; -1 = fatel error, 0 = no error, 1 = user error
    **/
    // check if list exist
    if ( *list == NULL ){
        return 1;
    }

    // traverse list
    node_t *temp = NULL;

    while ( (*list)->list_head != NULL ) {
        temp = (*list)->list_head->next_node;
        free( (*list)->list_head );
        (*list)->list_head = temp;
    }

    // danglers begone
    (*list)->list_head = NULL;
    (*list)->list_tail = NULL;
    *list = NULL;
    temp = NULL;

    return 0;
}


uint64_t linked_list_size(linked_list_t *list) {
    /**
     * @brief  returns the total number of nodes in linked list
     * 
     * @param  list         the linked list object
     * @return uint64_t     the total number of nodes
    **/
    if ( list == NULL ) {
        return 0;
    }
    uint_fast64_t counter = 0;
    node_t *temp = list->list_head;

    // traverse linked list
    while ( temp != NULL ) {
        counter++;
        temp = temp->next_node;
    }

    return counter;
}


int8_t linked_list_insert_at(linked_list_t **list, uint64_t index, int value) {
    /**
     * @brief  inserts node at index given by user
     * 
     * @param  list     linked list
     * @param  index    index to insert
     * @return int8_t   error code
    **/
    if ( *list == NULL ) {
        // invalid list
        return 1;
    }

    if ( index > linked_list_size(*list) + 1 ) {
        // invalid index
        return 1;
    }

    // create node
    node_t *new_node = NULL;
    if (
        ( new_node = (node_t *) malloc(sizeof(node_t)) )
        == NULL
    ) {
        return -1;
    }
    new_node->item = value;

    // insert at head
    if ( index == 0 ) {
        new_node->next_node = (*list)->list_head;
        (*list)->list_head = new_node;        
        return 0;
    }

    // insert at tail
    if ( index == linked_list_size(*list) + 1 ) {
        (*list)->list_tail = new_node;
        new_node->next_node = NULL;
        return 0;
    }

    // insert inbetween list
    node_t *current_node = (*list)->list_head;

    while ( index != 1 ) {
        current_node = current_node->next_node;
        index--;
    }

    new_node->next_node = current_node->next_node;
    current_node->next_node = new_node;

    current_node = NULL;

    return 0;
}


int8_t linked_list_print(linked_list_t *list) {
    
    if ( list == NULL ) {
        return 1;
    }

    node_t *temp = list->list_head;
    fprintf(stdout, "linked list: ");
    // traverse linked list
    while ( temp != NULL ) {
        fprintf(stdout, "%d ", temp->item);
        temp = temp->next_node;
    }

    fprintf(stdout, "\n");
    
    return 0;
}