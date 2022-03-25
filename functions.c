#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

Stack *createStack(int size, int *error){
    Stack *stack = malloc(sizeof(Stack));
    if (stack){
        stack -> size = size;
        stack -> head = NULL;
        stack -> numElem = 0;
        *error = 1;
    }else{
        *error = 0;
    }
    return stack;
}

int isEmpty(Stack *stack){
    if (stack -> head == NULL){
        return 1;
    }else{
        return 0;
    }
}

int push(Stack *stack, void *data){
    Node *newNode = malloc(sizeof(Node));
    newNode -> data = malloc(stack -> size);
    if (newNode && newNode -> data){
        memcpy(newNode -> data, data, stack -> size);
        newNode -> next = stack -> head;
        stack -> head = newNode;
        stack -> numElem ++;
        return 1;
    }else{
        return 0;
    }
}

int pop(Stack *stack, void *target){
    if (stack -> head == NULL){
        return 0;
    }else{
        Node *node = stack -> head;
        memcpy(target, node -> data, stack -> size);
        stack -> head = node -> next;
        stack -> numElem --;
        free(node -> data);
        free(node);
        return 1;
    }
}

int peek(Stack *stack, void *data){
    if (stack -> head == NULL){
        return 0;
    }else{
        memcpy(data, stack -> head -> data, stack -> size);
        return 1;
    }
}

int destroyStack(Stack *stack){
    if(stack -> head == NULL){
        return 0;
    }else{
        Node *temp = stack -> head;
        while(stack -> head){
            temp = stack -> head;
            stack -> head = stack -> head -> next;
            free(temp);
        }
        return 1;
    }
}


