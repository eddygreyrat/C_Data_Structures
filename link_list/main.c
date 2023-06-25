#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} node_t;

void foo(int num, int *p_num, node_t node, node_t *p_node);
void bar(int num, int *p_num, node_t node, node_t *p_node);

int main() {

    int num        = 1;
    int *p_num     = NULL;
    node_t node    = {0};
    node_t *p_node = NULL;

    p_num  = malloc(sizeof(int));
    p_node = malloc(sizeof(node_t));

    p_num = &num;
    node.value = 1;
    p_node = &node;
    p_node->value = 1;

    printf("num     = %d\t&num   = %p\n", num, &num);
    printf("node.v  = %d\t&node  = %p\n\n", node.value, &node);

    printf("*p_num  = %d\tp_num  = %p\t&p_num  = %p\n", *p_num, p_num, &p_num);
    printf("*p_node = %d\tp_node = %p\t&p_node = %p\n\n", *p_node, p_node, &p_node);
    printf("----------------------------------------------------------------------");

    foo(num, p_num, node, p_node);
    fflush(stdout);
}

void foo(int num, int *p_num, node_t node, node_t *p_node) {

    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = 5;
    new_node->next = NULL;

    printf("num     = %d\t&num   = %p\n", num, &num);
    printf("node.v  = %d\t&node  = %p\n\n", node.value, &node);

    printf("*p_num  = %d\tp_num  = %p\t&p_num  = %p\n", *p_num, p_num, &p_num);
    printf("*p_node = %d\tp_node = %p\t&p_node = %p\n\n", *p_node, p_node, &p_node);
    printf("----------------------------------------------------------------------");




}

void bar(int num, int *p_num, node_t node, node_t *p_node);