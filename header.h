#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
//@2110528

typedef struct Node {
    void *data;
    struct Node *next;
}Node;

typedef struct Stack{
    Node *head;
    int numElem;
    int size;
}Stack;

Stack *createStack(int size, int *error); // creates an empty stack
                                          // if error 0 - could not allocate enough memory, 1 - stack created successfully
                                          // size - a size of elements in bytes

int isEmpty(Stack *stack); //if 1 is returned - stack is empty, if 1 - it is not empty

int push(Stack *stack, void *data); //adds an element to the stack
                                    // if function returned 0 - could not allocate enough memory, 1 - element added successfully

int pop(Stack *stack, void *target); //removes an element from the stack and adds to target
                                     //if function returned 0 - stack is empty, 1 - element popped successfully

int peek(Stack *stack, void *data); //shows the data of the first element
                                    //function returns 0 if stack is empty, else returns 1

int destroyStack(Stack *stack); //destroys the stack
                                //if trying to destroy an empty stack function returns 0, else returns 1

#endif // HEADER_H_INCLUDED
