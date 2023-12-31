/**
 * @file linked_list.c
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
 * @version 1.7.3
 * @date 2023-09-10
 * 
 * @copyright Copyright (c) 2023
 * 
**/
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>


/*** 
 * functions to initialize linked list object 
***/
int8_t linked_list_create(
    linked_list_t **list
) {
    /**
     * @brief  initialized a linked list object 
     * 
     * @param  list     the linked list object
     * @param  value    the value to store in the first node
     * @return int8_t   error code; -1 = fatal error, 0 = no error, 1 = user error
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

    // init list
    (*list)->list_head = NULL;
    (*list)->list_tail = NULL;
    (*list)->size = 0;

    return 0;
}


int8_t linked_list_destroy(
    linked_list_t **list
) {
    /**
     * @brief  frees all the memory allocated to a linked list
     * 
     * @param  list     the linked list to free
     * @return int8_t   error code; -1 = fatal error, 0 = no error, 1 = user error
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

        (*list)->size--;
    }

    // something went wrong
    if ( (*list)->size != 0 ) {
        return -1;
    }

    // danglers begone
    (*list)->list_tail = NULL;
    *list = NULL;
    temp = NULL;

    return 0;
}


/*** 
 * functions to add nodes in linked list 
***/
int8_t linked_list_insert_at(
    linked_list_t **list, 
    uint64_t index, 
    int value
) {
    /**
     * @brief  inserts node at index given by user
     * 
     * @param  list     linked list
     * @param  index    index to insert
     * @return int8_t   error code
    **/

    // check if list exist
    if ( *list == NULL ) {
        return 1;
    }

    // check if index is in range of list
    if ( index + 1 > (*list)->size ) {
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

        if ( (*list)->size == 0 ) {
            (*list)->list_tail = (*list)->list_head;
        }

        (*list)->size++;

        return 0;
    }

    // insert at tail
    if ( index == (*list)->size ) {
        (*list)->list_tail->next_node = new_node;
        (*list)->list_tail = new_node;
        new_node->next_node = NULL;

        (*list)->size++;

        return 0;
    }

    // insert inbetween list
    node_t *current_node = (*list)->list_head;

    /*** current node points to node right before insertion point
     *   when index equals 1. This is required to insert node at appropriate location.
    ***/
    while ( index != 1 ) {
        current_node = current_node->next_node;
        index--;
    }

    new_node->next_node = current_node->next_node;
    current_node->next_node = new_node;

    (*list)->size++;

    return 0;
}


int8_t linked_list_push(
    linked_list_t **list, 
    int value
) {
    /**
     * @brief  adds node to head of list
     * 
     * @param  list     the linked list object
     * @param  value    the value of the new node
     * @return int8_t   error code
    **/
   
    // check if list exist
    if ( *list == NULL ) {
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

    // insert to head
    new_node->next_node = (*list)->list_head;
    (*list)->list_head = new_node;

    // have tail point towards end of list
    if ( (*list)->size == 0 ) {
        (*list)->list_tail = (*list)->list_head;
    }

    (*list)->size++;

    return 0;
}


int8_t linked_list_append(
    linked_list_t **list, 
    int value
) {
    /**
     * @brief  adds node to tail of list
     * 
     * @param  list     the linked list object
     * @param  value    the vlaue of the new node
     * @return int8_t   error code
    **/
    
    // check if list exist
    if ( *list == NULL ) {
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
    new_node->next_node = NULL;

    // attach to tail if empty
    if ( (*list)->list_tail == NULL ) {

        (*list)->list_tail = new_node;
        (*list)->list_head = (*list)->list_tail;
        (*list)->size++;

        return 0;
    }

    // attach to tail
    (*list)->list_tail->next_node = new_node;
    (*list)->list_tail = new_node;
    (*list)->size++;

    return 0;
}


/*** 
 * functions to delete nodes in linked list 
***/
int8_t linked_list_delete_at(
    linked_list_t **list, 
    uint64_t index
) {
    /**
     * @brief  deletes node at a given index.
     * 
     * @param  list 
     * @param  index 
     * @return int8_t 
    **/

    // list existane or empty list
    if ( (*list) == NULL || (*list)->size == 0 ) {
        return 1;
    }

    // check if index is in range
    if ( index > (*list)->size - 1 ) {
        return 1;
    }

    // traverse list
    node_t *temp = NULL;
    node_t *current_node = (*list)->list_head;
    
    if ( index == 0 ) {
        (*list)->list_head = current_node->next_node;

        // check if node is the last one in list
        if ( current_node == (*list)->list_tail ) {
            (*list)->list_tail = NULL;
        }

        free(current_node);
        (*list)->size--;

        return 0;
    }

    // current_node stops at node right before node at index
    while ( current_node != NULL && index != 1 ) {
        current_node = current_node->next_node;
        index--;
    }

    // check if deleting node at tail
    if ( current_node->next_node == (*list)->list_tail ) {
        (*list)->list_tail = current_node;
        (*list)->list_tail->next_node = NULL;
    } 

    // save next next node
    temp = current_node->next_node->next_node;

    // delete node
    free(current_node->next_node);

    // re-attach current nodes pointer
    current_node->next_node = temp;
    (*list)->size--;

    return 0;
}


int8_t linked_list_pop(
    linked_list_t **list
) {
    /**
     * @brief  deletes the first node in list
     * 
     * @param  list 
     * @return int8_t 
    **/

    // check if list exist or is empty
    if ( *list == NULL || (*list)->size == 0 ) {
        return 1;
    }
    
    // point to node to delete
    node_t *temp = (*list)->list_head;
    (*list)->list_head = temp->next_node;

    // check if theres only one node
    if ( temp == (*list)->list_tail ) {
        (*list)->list_tail = NULL;
    }

    // delete node
    free(temp);
    (*list)->size--;

    return 0;
}


int8_t linked_list_remove(
    linked_list_t **list
) {
    /**
     * @brief  deletes the last node in list
     * 
     * @param  list 
     * @return int8_t 
    **/
    
    // check if list exist or is empty
    if ( *list == NULL || (*list)->size == 0 ) {
        return 1;
    }

    // (*list)->size - 1 = index of last node in list
    linked_list_delete_at(list, (*list)->size - 1);

    return 0;
}


/***
 * functions to replace values stored in nodes
***/
int8_t linked_list_replace_at(
    linked_list_t **list,
    uint64_t index,
    int new_item
) {
    /**
     * @brief  replaces node at index given by user
     * 
     * @param  list     linked list
     * @param  index    index to insert
     * @param  new_item the new value that will replace the old
     * @return int8_t   error code
    **/

    // check if list exist
    if ( *list == NULL ) {
        return 1;
    }

    // check if index is in range of list
    if ( index + 1 > (*list)->size ) {
        return 1;
    }

    // replace at head
    if ( index == 0 ) {

        (*list)->list_head->item = new_item;
        return 0;
    }

    // insert at tail
    if ( index == (*list)->size ) {

        (*list)->list_tail->item = new_item;
        return 0;
    }

    // insert inbetween list
    node_t *current_node = (*list)->list_head;

    /*** current node points to node whos value will be replace
    ***/
    while ( index != 0 ) {
        current_node = current_node->next_node;
        index--;
    }

    current_node->item = new_item;

    return 0;
}


int8_t linked_list_replace_head(
    linked_list_t **list,
    int new_item
) {
    /**
     * @brief  replaces node at index given by user
     * 
     * @param  list     linked list
     * @param  new_item the new value that will replace the old
     * @return int8_t   error code
    **/

    // check if list exist or is empty
    if ( *list == NULL || (*list)->size == 0 ) {
        return 1;
    }

    (*list)->list_head->item = new_item;
    return 0;
}


int8_t linked_list_replace_tail(
    linked_list_t **list,
    int new_item
) {
    /**
     * @brief  replaces node at index given by user
     * 
     * @param  list     linked list
     * @param  new_item the new value that will replace the old
     * @return int8_t   error code
    **/

    // check if list exist or is empty
    if ( *list == NULL || (*list)->size == 0 ) {
        return 1;
    }

    (*list)->list_tail->item = new_item;

    return 0;
}


/*** 
 * functions to retrieve values stored in nodes 
***/
int8_t linked_list_value_at(
    linked_list_t *list, 
    uint64_t index, 
    int *ret_val
) {
    /**
     * @brief  retrieve the value from a node at the given index 
     * 
     * @param  list     linked list
     * @param  index    the node location
     * @param  ret_val  the variable where the value gets stored in
     * @return int8_t   error code
    **/
    
    // check if list exist or is empty
    if ( list == NULL || list->size == 0 ) {
        return 1;
    }

    // check if index is in range of list
    if ( index + 1 > list->size ) {
        return 1;
    }

    // replace at head
    if ( index == 0 ) {

        *ret_val = list->list_head->item;
        return 0;
    }

    // insert at tail
    if ( index == list->size ) {

        *ret_val = list->list_tail->item;
        return 0;
    }

    // insert inbetween list
    node_t *current_node = list->list_head;

    /*** current node points to node whos value will be replace
    ***/
    while ( index != 0 ) {
        current_node = current_node->next_node;
        index--;
    }

    *ret_val = current_node->item;

    return 0;
}


int8_t linked_list_value_at_head(
    linked_list_t *list, 
    int *ret_val
) {
    /**
     * @brief  retrieve the value from the first node in the list
     * 
     * @param  list     linked list
     * @param  ret_val  the variable where the value gets stored in
     * @return int8_t   error code
    **/
    
    // check if list exist or is empty
    if ( list == NULL || list->size == 0 ) {
        return 1;
    }

    *ret_val = list->list_head->item;
    return 0;
}


int8_t linked_list_value_at_tail(
    linked_list_t *list, 
    int *ret_val
) {
    /**
     * @brief  retrieve the value from the last node in the list 
     * 
     * @param  list     linked list
     * @param  ret_val  the variable where the value gets stored in
     * @return int8_t   error code
    **/
    
    // check if list exist or is empty
    if ( list == NULL || list->size == 0 ) {
        return 1;
    }

    *ret_val = list->list_tail->item;
    return 0;
}


/*** 
 * functions to re-arrange linked list 
***/
int8_t linked_list_reverse(
    linked_list_t **list
) {
    /**
     * @brief  reverses linked list
     * 
     * @param  list 
     * @return int8_t 
    **/
    
    // check if list exist or empty
    if ( *list == NULL || (*list)->size == 0 ) {
        return 1;
    }

    // cant reverse a list with one node
    if ( (*list)->size == 1 ) {
        return 0;
    }

    // cursor nodes to traverse list
    node_t *prev, *current, *next;

    // set cursor
    prev = current = (*list)->list_head;
    next = current->next_node;

    // initial start; make first node as last by having it point to null
    current->next_node = NULL;

    // reversing algorithm
    while ( next != NULL ) {
        // make 'next' node point to 'prev' node using the 'current' variable
        current = next;

        // save next_node location with the next variable
        next = current->next_node;

        // have current node point to prev node
        current->next_node = prev;

        // prev node is no longer needed. current node becomes new prev node
        prev = current;
    }

    // head points at the end of list
    (*list)->list_tail = (*list)->list_head;

    // prev and current both point to front of list now
    (*list)->list_head = current;
    
    return 0;
}


/*** 
 * functions to debug linked list 
***/
int8_t linked_list_print_list(
    linked_list_t *list
) {
    /**
     * @brief  prints all the values stored in the linked list.
     * 
     * @param  list     the linked list object
     * @return int8_t   error code
    **/
    // check if list is empty
    if ( list == NULL ) {
        return 1;
    }

    /*** although "list" is a local variable, "list_head" is not and is being reference.
     *   hence, modifing "list_head" in this function will result in a permanent change.
    ***/
    node_t *temp = list->list_head;

    fprintf(stdout, "\nlinked list: ");
    
    // traverse linked list
    while ( temp != NULL ) {
        fprintf(stdout, "%d ", temp->item);
        temp = temp->next_node;
    }

    fprintf(stdout, "\n");
    
    return 0;
}


int8_t linked_list_print_status(
    linked_list_t *list
) {
    /**
     * @brief  prints all members of list obj.
     * 
     * @param  list 
     * @return int8_t 
    **/
    
    // check if list exist
    if ( list == NULL ) {
        return 1;
    }

    printf(
        "\nlinked_list_t:\n"
        "\tlist @%p\n"
        "\thead @%p\n"
        "\ttail @%p\n"
        "\tsize = %lu\n",
        list,
        list->list_head,
        list->list_tail,
        list->size
    );

    return 0;
}


void linked_list_print_err_code(
    int8_t err_code
) {
    /**
     * @brief  prints a description of the error code returned
     *         from the linked list API
     * 
     * @param  err_code 
     * @return int8_t  
    **/

    switch ( err_code ) {
        case LL_EXIT_SUCCESS:
            printf("\nno error occurred\n");
            break;
        case LL_EXIT_FATAL:
            printf("\nmalloc failed\n");
            break;
        case LL_EXIT_USER:
            printf("\nimproper use of linked list API\n");
            break;
        default:
            printf(
                "\nthe value: %d, does not get return "
                "from any linked list API function\n",
                err_code
            );
            break;
    }

}


uint64_t linked_list_size(
    linked_list_t *list
) {
    /**
     * @brief  returns the total number of nodes in linked list
     * 
     * @param  list         the linked list object
     * @return uint64_t     the total number of nodes
    **/

    // check if list exist
    if ( list == NULL ) {
        return 0;
    }
    
    return list->size;
}


int8_t linked_list_search_for(
    linked_list_t *list,
    int value,
    uint64_t *ret_index
) {
    /**
     * @brief  returns the index of the *first* node whos value matches
     *         the value passed by the user.  
     * 
     * @param  list     linked list
     * @param  value    the value to search for in list
     * @return int8_t   exit status; each value represents
     *                  what happen during the function call
    **/
    
    // check if list exist or is empty
    if ( list == NULL || list->size == 0 ) {
        return 1;
    }

    // index of node with matching item
    uint64_t current_index = 0;

    // cursor node
    node_t *current_node = list->list_head;

    // traverse list
    while ( current_node != NULL ) {

        if ( current_node->item == value ) {

            *ret_index = current_index;
            return 0;
        }

        // search next node
        current_node = current_node->next_node;
        current_index++;
    }

    // no match found
    return -1;
}

