#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

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
    reverse,
    print_list,
    print_status,
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
    "7)  pop           \n"
    "8)  remove        \n"
    "9)  replace at    \n"
    "10) replace head  \n"
    "11) replace tail  \n"
    "12) value at      \n"
    "13) value at head \n"
    "14) value at tail \n"
    "15) reverse       \n"
    "16) print list    \n"
    "17) print status  \n"
    "18) print err code\n"
    "19) size          \n"
    "20) search for    \n"
    ">> ";
    int reply = 0;
    int flag = 1;
    int ret_val = 0;
    int node_value = -1000;
    uint64_t index = 0;
    linked_list_t *users_list = NULL;

    ret_val = linked_list_create(&users_list);

    for (int i = 10; i >= 0; i--) {
        ret_val = linked_list_append(&users_list, i);
    }

    while (flag) {
        printf("%s", menu);
        scanf("%d", &reply);

        switch (reply) {
            case quit:
                flag = 0;
                break;
            case create:
                ret_val = linked_list_create(&users_list);
                linked_list_print_err_code(ret_val);
                break;
            case destroy:
                ret_val = linked_list_destroy(&users_list);
                linked_list_print_err_code(ret_val);
                break;
            case insert_at:
                printf("\nenter index: ");
                scanf("%lu", &index);
                printf("enter value: ");
                scanf("%d", &reply);
                ret_val = linked_list_insert_at(&users_list, index, reply);
                linked_list_print_err_code(ret_val);
                break;
            case push:
                printf("\nenter value: ");
                scanf("%d", &reply);
                ret_val = linked_list_push(&users_list, reply);
                linked_list_print_err_code(ret_val);
                break;
            case append:
                printf("\nenter value: ");
                scanf("%d", &reply);
                ret_val = linked_list_append(&users_list, reply);
                linked_list_print_err_code(ret_val);
                break;
            case delete_at:
                printf("\nenter index: ");
                scanf("%lu", &index);
                ret_val = linked_list_delete_at(&users_list, index);
                linked_list_print_err_code(ret_val);
                break;
            case pop:
                ret_val = linked_list_pop(&users_list);
                linked_list_print_err_code(ret_val);
                break;
            case removee:
                ret_val = linked_list_remove(&users_list);
                linked_list_print_err_code(ret_val);
                break;
            case reverse:
                ret_val = linked_list_reverse(&users_list);
                linked_list_print_err_code(ret_val);
                break;
            case print_list:
                ret_val = linked_list_print_list(users_list);
                linked_list_print_err_code(ret_val);
                break;
            case print_status:
                ret_val = linked_list_print_status(users_list);
                linked_list_print_err_code(ret_val);
                break;
            case print_err:
                linked_list_print_err_code(ret_val);
                break;
            case size:
                printf("\nlinked list size: %d\n", linked_list_size(users_list));
                break;
            case replace_at:
                printf("\nenter index: ");
                scanf("%lu", &index);
                ret_val = linked_list_replace_at(&users_list, index, -69);
                linked_list_print_err_code(ret_val);
                break;
            case replace_head:
                ret_val = linked_list_replace_head(&users_list, -69);
                linked_list_print_err_code(ret_val);
                break;
            case replace_tail:
                ret_val = linked_list_replace_tail(&users_list, -69);
                linked_list_print_err_code(ret_val);
                break;
            case value_at:
                printf("\nenter index: ");
                scanf("%lu", &index);
                ret_val = linked_list_value_at(users_list, index, &node_value);
                printf("\nnode value: %d", node_value);
                linked_list_print_err_code(ret_val);
                break;
            case value_at_head:
                ret_val = linked_list_value_at_head(users_list, &node_value);
                printf("\nnode value: %d", node_value);
                linked_list_print_err_code(ret_val);
                break;
            case value_at_tail:
                ret_val = linked_list_value_at_tail(users_list, &node_value);
                printf("\nnode value: %d", node_value);
                linked_list_print_err_code(ret_val);
                break;
            case search_for:
                printf("\nenter value: ");
                scanf("%d", &reply);
                uint64_t ret_index = 0;
                ret_val = linked_list_search_for(users_list, reply, &ret_index);
                printf("\nindex value: %d", ret_index);
                linked_list_print_err_code(ret_val);
                break;
            default:
                printf("\ninvalid input\n\n");
                break;
        }
    }

    if ( users_list != NULL ) {
        printf("\ndestroying linked list...");
        linked_list_destroy(&users_list);
    }
    
   
    return 0;
}

