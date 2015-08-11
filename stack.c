/* Implementing a stack using an array */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef enum Boolean {False, True} Boolean;
typedef struct Stack
{
    int Top; /* Variable Top is used to denote the top position of the stack */
    int S[MAX];
} Stack;

void Push(Stack *, int), Display(Stack*);
int Pop(Stack*), Peek(Stack*);
Boolean IsEmpty(Stack*),IsFull(Stack*);

int main()
{
    int x, Item;
    Stack St;
    St.Top = -1; /* Initializing top */
    while(1)
    {
        printf("Enter choice \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d", &x);
        switch(x)
        {
        case 1:
            if(IsFull(&St))
            {
                printf("Overflow\n");
                break;
            }
            printf("Input the element\n");
            scanf("%d", &Item);
            Push(&St, Item);
            break;
            /* Invoke Push function and break the switch statement */
        case 2:
            if(IsEmpty(&St))
            {
                printf("Underflow\n");
                break;
            }
            Item=Pop(&St);
            printf("Popped element: %d\n", Item);
            break;
            /* Invoke Pop function and break the switch statement */
        case 3:
            if(IsEmpty(&St))
            {
                printf("Stack is empty\n");
                break;
            }
            Item=Peek(&St);
            printf("Top element: %d\n", Item);
            break;
            /* Invoke Peep function and break the switch statement */
        case 4:
            if(IsEmpty(&St))
            {
                printf("Stack is empty\n");
                break;
            }
            Display(&St);
            break;
            /* Display the Stack */
        case 5:
            exit(0); /* Exit the program */
        }
    }
    return 0;
}

Boolean IsFull(Stack *St)
{
    if(St->Top==MAX-1)
        return True; /* Stack cannot store more than 'MAX' elements */
    else
        return False;
}/* end IsFull */

Boolean IsEmpty(Stack *St)
{
    if(St->Top == -1)
        return True; /* No element in Stack */
    else
        return False;
} /* end IsEmpty */

void Push(Stack *St, int Item)
{
    St->S[++St->Top]=Item; /* Push the element in array 's' */
} /* end Push */

int Pop(Stack *St)
{
    int Item;
    Item=St->S[St->Top--]; /* Pop the top element of array 's'*/
    return Item;
} /* end Pop */

int Peek(Stack *St)
{
    int Item;
    Item=St->S[St->Top]; /* Assign top element of the stack to Item */
    return Item;
}

void Display(Stack *St)
{
    int I;
    for(I=St->Top; I>=0; I--)
        printf("%d\n", St->S[I]);
} /* end Display */
