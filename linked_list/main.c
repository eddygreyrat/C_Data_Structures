#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"


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
    "9)  reverse       \n"
    "10) print list    \n"
    "11) print status  \n"
    "12) print err code\n"
    "13) size          \n"
    ">> ";
    int reply = 0;
    int flag = 1;
    int ret_val = 0;
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
            case 0:
                flag = 0;
                break;
            case 1:
                ret_val = linked_list_create(&users_list);
                linked_list_print_err_code(ret_val);
                break;
            case 2:
                ret_val = linked_list_destroy(&users_list);
                linked_list_print_err_code(ret_val);
                break;
            case 3:
                printf("\nenter index: ");
                scanf("%lu", &index);
                printf("enter value: ");
                scanf("%d", &reply);
                ret_val = linked_list_insert_at(&users_list, index, reply);
                linked_list_print_err_code(ret_val);
                break;
            case 4:
                printf("\nenter value: ");
                scanf("%d", &reply);
                ret_val = linked_list_push(&users_list, reply);
                linked_list_print_err_code(ret_val);
                break;
            case 5:
                printf("\nenter value: ");
                scanf("%d", &reply);
                ret_val = linked_list_append(&users_list, reply);
                linked_list_print_err_code(ret_val);
                break;
            case 6:
                printf("\nenter index: ");
                scanf("%lu", &index);
                ret_val = linked_list_delete_at(&users_list, index);
                linked_list_print_err_code(ret_val);
                break;
            case 7:
                ret_val = linked_list_pop(&users_list);
                linked_list_print_err_code(ret_val);
                break;
            case 8:
                ret_val = linked_list_remove(&users_list);
                linked_list_print_err_code(ret_val);
                break;
            case 9:
                ret_val = linked_list_reverse(&users_list);
                linked_list_print_err_code(ret_val);
                break;
            case 10:
                ret_val = linked_list_print_list(users_list);
                linked_list_print_err_code(ret_val);
                break;
            case 11:
                ret_val = linked_list_print_status(users_list);
                linked_list_print_err_code(ret_val);
                break;
            case 12:
                linked_list_print_err_code(ret_val);
                break;
            case 13:
                printf("\nlinked list size: %d\n", linked_list_size(users_list));
                break;
            default:
                printf("\ninvalid input\n\n");
                break;
        }
    }

    if ( users_list != NULL ) {
        linked_list_destroy(&users_list);
    }
    
   
    return 0;
}

