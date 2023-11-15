#include <stdlib.h>
#include <stdio.h>
#include "doubly_linked_list.h"

enum fun{
    quit,
    create,
    destroy,
    insert_at,
    push,
    append,
    delete_at,
    pop,
    removee,
    replace_at,
    replace_head,
    replace_tail,
    value_at,
    value_at_head,
    value_at_tail,
    print_list,
    list_status,
    node_status,
    print_err,
    size,
    search_for
};

int main() {
    char *menu = "     \n"
    "0)  quit          \n"
    "1)  create        \n"
    "2)  destory       \n"
    "3)  insert at     \n"
    "4)  push          \n"
    "5)  append        \n"
    "6)  delete at     \n"
    "7)  delete head   \n"
    "8)  delete tail   \n"
    "9)  replace at    \n"
    "10) replace head  \n"
    "11) replace tail  \n"
    "12) value at      \n"
    "13) value at head \n"
    "14) value at tail \n"
    "15) print list    \n"
    "16) print list status\n"
    "17) print node status\n"
    "18) print err code\n"
    "19) size          \n"
    "20) search for    \n"
    ">> ";
    int reply = 0;
    int flag = 1;
    int ret_val = 0;
    int node_value = -1000;
    uint64_t index = 0;
    doubly_linked_list_t *users_list = NULL;

    ret_val = doubly_ll_create(&users_list);

    for (int i = 10; i >= 0; i--) {
        ret_val = doubly_ll_append(&users_list, (void *)&i);
    }

    while (flag) {
        printf("%s", menu);
        scanf("%d", &reply);

        switch (reply) {
            case quit:
                flag = 0;
                break;
            case create:
                ret_val = doubly_ll_create(&users_list);
                doubly_ll_print_err_code(ret_val);
                break;
            case destroy:
                ret_val = doubly_ll_destroy(&users_list);
                doubly_ll_print_err_code(ret_val);
                break;
            case insert_at:
                printf("\nenter index: ");
                scanf("%lu", &index);
                printf("enter value: ");
                scanf("%d", &reply);
                ret_val = doubly_ll_insert_at(&users_list, index, reply);
                doubly_ll_print_err_code(ret_val);
                break;
            case push:
                printf("\nenter value: ");
                scanf("%d", &reply);
                ret_val = doubly_ll_push(&users_list, reply);
                doubly_ll_print_err_code(ret_val);
                break;
            case append:
                printf("\nenter value: ");
                scanf("%d", &reply);
                ret_val = doubly_ll_append(&users_list, reply);
                doubly_ll_print_err_code(ret_val);
                break;
            case delete_at:
                printf("\nenter index: ");
                scanf("%lu", &index);
                ret_val = doubly_ll_delete_at(&users_list, index);
                doubly_ll_print_err_code(ret_val);
                break;
            case pop:
                ret_val = doubly_ll_pop(&users_list);
                doubly_ll_print_err_code(ret_val);
                break;
            case removee:
                ret_val = doubly_ll_remove(&users_list);
                doubly_ll_print_err_code(ret_val);
                break;
            case print_list:
                ret_val = doubly_ll_print_list(users_list);
                doubly_ll_print_err_code(ret_val);
                break;
            case list_status:
                ret_val = doubly_ll_list_status(users_list);
                doubly_ll_print_err_code(ret_val);
                break;
            case node_status:
                printf("\nenter index: ");
                scanf("%lu", &index);
                ret_val = doubly_ll_node_status(users_list, index);
                doubly_ll_print_err_code(ret_val);
                break;
            case print_err:
                doubly_ll_print_err_code(ret_val);
                break;
            case size:
                printf("\nlinked list size: %lu\n", doubly_ll_size(users_list));
                break;
            case replace_at:
                printf("\nenter index: ");
                scanf("%lu", &index);
                ret_val = doubly_ll_replace_at(&users_list, index, -69);
                doubly_ll_print_err_code(ret_val);
                break;
            case replace_head:
                ret_val = doubly_ll_replace_head(&users_list, -69);
                doubly_ll_print_err_code(ret_val);
                break;
            case replace_tail:
                ret_val = doubly_ll_replace_tail(&users_list, -69);
                doubly_ll_print_err_code(ret_val);
                break;
            case value_at:
                printf("\nenter index: ");
                scanf("%lu", &index);
                ret_val = doubly_ll_value_at(users_list, index, &node_value);
                printf("\nnode value: %d", node_value);
                doubly_ll_print_err_code(ret_val);
                break;
            case value_at_head:
                ret_val = doubly_ll_value_at_head(users_list, &node_value);
                printf("\nnode value: %d", node_value);
                doubly_ll_print_err_code(ret_val);
                break;
            case value_at_tail:
                ret_val = doubly_ll_value_at_tail(users_list, &node_value);
                printf("\nnode value: %d", node_value);
                doubly_ll_print_err_code(ret_val);
                break;
            case search_for:
                printf("\nenter value: ");
                scanf("%d", &reply);
                uint64_t ret_index = 0;
                ret_val = doubly_ll_search_for(users_list, reply, &ret_index);
                printf("\nindex value: %lu", ret_index);
                doubly_ll_print_err_code(ret_val);
                break;
            default:
                printf("\ninvalid input\n\n");
                break;
        }
    }

    if ( users_list != NULL ) {
        printf("\ndestroying linked list...\n");
        doubly_ll_destroy(&users_list);
    }
    
   
    return 0;
}

