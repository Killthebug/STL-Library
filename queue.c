// #Authored : Jaipal Singh Goud
// Part of : My STL 
// Date :
// Sem I-II

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

typedef struct xyz{
    int data;
    struct xyz *next;
}node;

node * dequeue(node *head);
void printqueue(node *head);
//#GABTIPS was here
node *fordel,*head,*tail,*cur,*new;
int len,x,i,n;

int main()
{
    new = (node *)malloc(sizeof(node));                     // Initialized the Very first node (Allocates some memory to it)
    head = new;
    printf("Enter Length of linked list ");
    scanf("%d",&len);
    printf("Enter List Elements\n");
    for(i=0;i<len;i++)
    {
        scanf("%d",&x);
        new->data = x;
        cur = (node *)malloc(sizeof(node));                 // After data is allocated to previous node, a new node is then created
        new->next = cur;
        new = cur;
        new->next = NULL;
    }
    printqueue(head);
    printf("How many elements do you want to delete?");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        fordel = dequeue(head);
        head = fordel;
    }
    printqueue(head);
    return 0;
}

void printqueue(node *head)                                  // Prints list
{
    node *temp;
    temp = head;
    while(temp->next != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("END \n");
}

node * dequeue(node *head)
{
    node *temp;
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

