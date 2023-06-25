#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

typedef struct node {
    void *item;
    struct node *next_node;
}node_t;

typedef struct link_list {
    node_t *list_head;
}link_list_t;


/*** object orientated ***/
bool link_list_create(link_list_t *list, void *value);
bool link_list_destory();
bool link_list_add_to_end();
bool link_list_add_to_head();
bool link_list_insert_node();
bool link_list_delete_node();
bool link_list_reverse();

/*** visual ***/
bool link_list_print();


#endif //_LINK_LIST_H_