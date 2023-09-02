#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"


int main() {
    char *menu = 
    "0) quit\n"
    "1) create\n"
    "2) destory\n"
    "3) print\n"
    "4) insert at\n"
    ">> ";
    int reply = 0;
    _Bool flag = 1;
    linked_list_t *users_list = NULL;
    // users_list->list_head = NULL; users_list->list_tail = NULL;

    while (flag) {
        printf("%s", menu);
        scanf("%d", &reply);

        switch (reply) {
            case 0:
                flag = 0;
                break;
            case 1:
                printf("enter value: ");
                scanf("%d", &reply);
                linked_list_create(&users_list, reply);
                break;
            case 2:
                linked_list_destroy(&users_list);
                break;
            case 3:
                linked_list_print(users_list);
                break;
            case 4:
                printf("enter index: ");
                uint64_t index = 0;
                scanf("%lu", &index);
                printf("enter value: ");
                scanf("%d", &reply);
                linked_list_insert_at(&users_list, index, reply);
                break;
            default:
                printf("invalid input\n\n");
                break;
        }
    }
    
   
    return 0;
}
