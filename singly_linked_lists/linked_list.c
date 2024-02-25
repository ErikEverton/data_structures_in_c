#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node * next;
} node;


struct node * create_node(int val);
struct node * delete_head(node * head);
struct node * delete_in_any_position(node * head, int key);
struct node * delete_tail(node * head);
int find_length(node * head);
struct node * insert_at_the_beggining(node * head, int val);
struct node * insert_at_the_end(node * head, int val);
struct node * insert_in_any_posistion(node * haed, int val, int key);
struct node * print_list(node * head);
struct node * check_if_is_circular(node * head);


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

    for (int i = 0; i <= 5; i++) {
        head = delete_head(head);
    }

    for (int i = 0; i <= 5; i++) {
        delete_tail(head);
    }

    head = delete_in_any_position(head, 5);
    delete_in_any_position(head, 11);
    delete_in_any_position(head, 3);
    delete_in_any_position(head, 14);

    print_list(head);

    int length = find_length(head);

    printf("Total of elements in the list: %d\n", length);

    

    if (check_if_is_circular(head) == NULL) {
        printf("This is not a circular linked list.\n");
    } else {
        printf("This is a circular linked list.\n");
    }


    return 0;
}


struct node * delete_head(node * head) {
    head = head->next;
    return head;
}


struct node * delete_in_any_position(node * current, int key) {
    node * previous;

    if (current->value == key) {
        current = current->next;
        return current;
    }

    while (current != NULL) {
        previous = current;
        current = current->next;
        if (current->value == key) {
            previous->next = current->next;
            current = NULL;
            return previous->next;
        }
    }
    return current;
}


struct node * delete_tail(node * current) {
    node * previous;
    while(current->next != NULL) {
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
    return current;
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


int find_length(node * current) {
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
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


struct node * check_if_is_circular(node * current) {
    node * head = current;
    while (current->next != NULL) {
        if (head->value == current->value) {
            return NULL;
        }
        current = current->next;
    }
    return current;
}
