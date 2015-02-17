// #Authored : Jaipal Singh Goud
// Part of : My STL 
// Date : 17/2/2015 
// Sem I-II
#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
    int capacity;
    int size;
    int *elements;
}Stack;

Stack * createStack(int maxElements)
{
    Stack *S;
    S = (Stack *)malloc(sizeof(Stack));
    S->elements = (int *)malloc(sizeof(int)*maxElements);
    S->size = 0;
    S->capacity = maxElements;
    return S;
}

void pop(Stack *S)
{
    if(S->size==0)
    {
        printf("Stack is Empty\n");
        return;
    }
    else
    {
        S->size--;
    }
    return;
}

int top(Stack *S)
{
    if(S->size==0)
    {
        printf("Stack is Empty\n");
        exit(0);
    }
    return S->elements[S->size-1];
}

void push(Stack *S,int element)
{
    if(S->size == S->capacity)
    {
        printf("Stack is Full\n");
    }
    else
    {
        S->elements[S->size++] = element;
    }
    return;
}
int main()
{
    int len,i,j,k,x,n;
    printf("Enter length of Stack \n");
    scanf("%d",&len);
    
    Stack *S = createStack(len);
    
    printf("Enter elements to add to stack");
    for(i=0;i<len;i++)
    {
        scanf("%d",&x);
        push(S,x);
    }
    
    printf("Top element is %d\n",top(S));
    return 0;
}
