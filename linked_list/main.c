#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} node_t;

void numpp(int copy);
void p_numpp(int *copy);

int main() {
    int num = 1;

    printf("num = %d\n", num);
    numpp(num);
    printf("num = %d\n", num);
    p_numpp(&num);
    printf("num = %d\n", num);
   
    return 0;
}

void numpp(int copy) {
    copy += 1;

    printf("copy = %d\n", copy);
}

void p_numpp(int *copy) {
    (*copy) += 1;

    printf("*copy = %d\n", *copy);
}