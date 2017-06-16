// This is a program to implement a priority queue using linked list.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct node{
    int data;
    int priority;
    struct node *next;
};

struct node *start = NULL;
struct node *insert(struct node *);
struct node *delete1(struct node *);
void display(struct node *);

int main(void)
{
    int option;
    do {
        printf("\n ***** MAIN MENU *****");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. DISPLAY");
        printf("\n 4. EXIT");
        printf("\n Enter your option: ");
        scanf(" %d", &option);

        switch(option){
        case 1:
            start = insert(start);
            break;
        case 2:
            start = delete1(start);
            break;
        case 3:
            display(start);
            break;
        default:
            printf("Unknown command\n");
            break;

        }
    }while (option != 4);

    return 0;
}

struct node *insert(struct node *p)
{
    int val, pri;
    struct node *ptr, *q;
    ptr = (struct node *) malloc (sizeof (struct node));
    printf("\n Enter the value and its priority: ");
    scanf(" %d %d", &val, &pri);
    ptr -> data = val;
    ptr -> priority = pri;

    if (p == NULL || pri < p -> priority){
        ptr -> next = p;
        p = ptr;
    }else{
        q = start;
        while (q -> next != NULL && q -> next -> priority <= pri)
                q = q -> next;
        ptr -> next = q -> next;
        q -> next = ptr;
    }

    return p;
}

struct node *delete1(struct node *p)
{
    struct node *ptr;
    if (p == NULL){
        printf("\nUnderflow");
        return ;
    }else{
        ptr = p;
        printf("\n Deleted item is : %d", ptr -> data);
        p = p -> next;
        free(ptr);
    }

    return p;
}

void display(struct node *p)
{
    struct node *ptr;
    ptr = p;
    if (p == NULL)
        printf("\nQUEUE IS EMPTY");
    else{
        printf("\n PRIORITY QUEUE IS : ");
        while (ptr != NULL){
            printf("\t%d[priority=%d]", ptr -> data, ptr -> priority);
            ptr = ptr -> next;
        }
    }
}
