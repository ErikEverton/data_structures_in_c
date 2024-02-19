#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node * next;
} node;


struct node * create_node(int val);
struct node * insert_at_the_beggining(node * head, int val);
struct node * insert_at_the_end(node * head, int val);
struct node * insert_in_any_posistion(node * haed, int val, int key);
struct node * print_list(node * head);


int main(void) {
    node * head = (node *) malloc(sizeof(node));

    if (head == NULL) {
        return 1;
    }

    head->value = 0;
    head->next = NULL;

    for (int i = 1; i <= 10; i++) {
        head = insert_at_the_beggining(head, i);
        if (head == NULL) {
            return 1;
        }
    }


    for (int i = 11; i <= 20; i++) {
        insert_at_the_end(head, i);
    }


    insert_in_any_posistion(head, 21, 7);


    print_list(head);
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

    if (new_head == NULL) {
        return NULL;
    }

    new_head->next = head;
    return new_head;
}


struct node * insert_at_the_end(node * current, int val) {
    while (current->next != NULL) {
        current = current->next;
    }

    node * new_node = create_node(val);

    if (new_node == NULL) {
        return NULL;
    }

    new_node->next = NULL;
    current->next = new_node;
    return new_node;
}


struct node * insert_in_any_posistion(node * current, int val, int key) {
    node * new_node = create_node(val);

    if (new_node == NULL) {
        return NULL;
    }

    node * previous = NULL;
    while(current != NULL) {
        if (current->value == key) {
            node * temp = current;
            previous->next = new_node;
            new_node->next = temp;
        }
        previous = current;
        current = current->next;
    }
    return new_node;
}


struct node * print_list(node * current) {
    printf("{");
    while(current->next != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("%d}\n", current->value);
}
