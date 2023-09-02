#include "link_list.h"
#include <stdbool.h>
#include <stdlib.h>

int8_t linked_list_create(linked_list_t **head, int value) {
    // check if list already exist
    if ( (*head)->list_head != NULL ){
        return 1;
    }

    // create
    if ((*head)->list_head = 
        (linked_list_t *) malloc(sizeof(linked_list_t))
        == NULL
    ) {
        return -1;
    }

    // init
    (*head)->list_tail = NULL;
    (*head)->list_head->item = value;

    return 0;
}


int8_t linked_list_destory(linked_list_t **head) {
    // check if list already exist
    if ( (*head)->list_head != NULL ){
        return 1;
    }

    // traverse list
    linked_list_t *temp = NULL;

    while ( (*head)->list_head != NULL ) {
        temp = (*head)->list_head->next_node;
        free( (*head)->list_head );
        (*head)->list_head = temp;
    }

    // danglers begone
    (*head)->list_head = NULL;
    (*head)->list_tail = NULL;
    temp = NULL;

    return 0;

}