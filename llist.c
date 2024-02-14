#include "llist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main(int argc, char *argv[]) {

    
    struct node *head = NULL;


    if (argc < 2) {
        printf("invalid number of arguments");
        return EXIT_FAILURE;
    }

    for(int i = 1; i < argc; i++){

        if(strcmp(argv[i],"ih") == 0) {
            int value = atoi(argv[i + 1]);
            struct node *new_node = node_alloc(value);
            llist_insert_head(&head, new_node);
            i++;

        } else if (strcmp(argv[i],"it") == 0) {
            int value = atoi(argv[i + 1]);
            struct node *new_node = node_alloc(value);
            llist_insert_tail(&head, new_node);
            i++;

        } else if (strcmp(argv[i], "dh") == 0) {
           llist_delete_head(&head);

        } else if (strcmp(argv[i],"f") == 0) {
            llist_free(&head);

        } else if (strcmp(argv[i],"p") == 0) {
            llist_print(head);
        } else {
            printf("command not recognized");
            return EXIT_FAILURE;
        }

    }

    return 0;
}


struct node *node_alloc(int value){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}


void llist_insert_head(struct node **head, struct node *n) {
    if (*head == NULL){
        *head = n;
    }
    else{
        n->next = *head;
        *head = n;
    }
}

void llist_insert_tail(struct node **head, struct node *n) {
    if (*head == NULL){
        *head = n;
    }

    else{
    struct node *tail_node = *head;
        while (tail_node->next != NULL){
            tail_node = tail_node->next;
        }

        tail_node->next = n;
    }
}


struct node *llist_delete_head(struct node **head){
    if (*head == NULL){
        return NULL;
    }

    else{
        struct node *delete = *head;
        *head = (*head)->next;
        delete->next = NULL;
        return delete;
    }
}


void node_free(struct node *n){
    free(n);
}

void llist_free(struct node **head) {
    while (*head != NULL) {
        struct node *temp = *head;
        *head = (*head)->next;
        node_free(temp);
    }
}


void llist_print(struct node *head) {
    if (head == NULL) {
        printf("[empty]");
    }

    while (head != NULL) {
        printf("%d", head->value);
        if (head->next!= NULL){
            printf("->");
        }
        head = head->next;
    }

    printf("\n");
}
