#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node * next;
} node;


struct node * create_node(int val);
struct node * insert_at_the_beggining(node * head, int val);


int main(void) {
    node * head = (node *) malloc(sizeof(node));
    head->value = 0;
    head->next = NULL;

    for (int i = 1; i <= 10; i++) {
        head = insert_at_the_beggining(head, i);
    }

    printf("The head value: %d\n", head->value);

    return 0;
}


struct node * create_node(int val) {
    node * new_node = (node *) malloc(sizeof(node));

    if (new_node == NULL) {
        return NULL;
    }

    new_node->value = val;
    new_node->next = NULL;
    return new_node;
}


struct node * insert_at_the_beggining(node * head, int val) {
    node * new_head = create_node(val);
    new_head->next = head;
    return new_head;
}
