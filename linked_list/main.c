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
    int err = 0;

    err = linked_list_create(&users_list);

    for (int i = 10; i >= 0; i--) {
        err = linked_list_append(&users_list, i);
    }

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
                linked_list_create(&users_list);
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

    if ( linked_list_size(users_list) != 0 ) {
        linked_list_destroy(&users_list);
    }
    
   
    return 0;
}
