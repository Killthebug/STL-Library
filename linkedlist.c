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

void scanint(int *p);
void printlist(node *head);
node * delete_element(int n, node *head);
    
node *head,*tail,*cur,*new;
int len,x,i,n;

int main()
{
    new = (node *)malloc(sizeof(node));                     // Initialized the Very first node (Allocates some memory to it)
    head = new;
    printf("Enter Length of linked list ");
    scanint(&len);
    printf("Enter List Elements\n");
    for(i=0;i<len;i++)
    {
        scanint(&x);
        new->data = x;
        cur = (node *)malloc(sizeof(node));                 // After data is allocated to previous node, a new node is then created
        new->next = cur;
        new = cur;
        new->next = NULL;
    }
    printlist(head);
    printf("Enter Number to be deleted\n");
    scanint(&n);
    head = delete_element(n,head);
    printlist(head);
    return 0;
}

void printlist(node *head)                                  // Prints list
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

node * delete_element(int n, node *head)
{
    node *temp,*todel;
    temp = head;
    int check=0;
    if(temp->data == n)                                     // To delete the element if it is present at the head node
    {
        todel = head;
        head = head->next;
        free(todel);
        check = 1;
    }
    else
    {

    while(temp->next != NULL)
    {
        if(temp->next->data == n)
        {
            todel = temp->next;
            temp->next = temp->next->next;
            free(todel);
            check = 1;
        }
        temp = temp->next;
    }
    }
    if(check == 1)
        printf("Deleted\n");
    else
        printf("Un-Successful\n");

    return head;
}

void scanint(int *p)
{
    register int c = getchar_unlocked();
    int x = 0;
    for(;(c<48 || c>57);c = getchar_unlocked())
        ;
    for(;c>47 && c<58;c = getchar_unlocked())
    {
        x = (x<<1) + (x<<3) + c - 48;
    }
    *p = x;
}

