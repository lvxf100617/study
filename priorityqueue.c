// Implements priority queue!!!!!


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int priority;
    struct node *next;
};

struct node *insertNode(struct node *p);
struct node *deleteNode(struct node *p);
void display(struct node *p);

int main(void)
{
    int oper;
    struct node *pqueue = NULL;

    do{

        printf("1. Insert node\n");
        printf("2. Delete node\n");
        printf("3. Display all node in priority queue\n");
        printf("4. exit\n");

        printf("Enter an operation code: ");
        scanf("%d", &oper);

        switch(oper){
        case 1:
            pqueue = insertNode(pqueue);
            break;
        case 2:
            pqueue = deleteNode(pqueue);
            break;
        case 3:
            display(pqueue);
            break;
         }

     } while (oper != 4);
    return 0;
}

struct node *insertNode(struct node *p)
{
        struct node *new_node;
        int val, pri;

        new_node = (struct node *) malloc(sizeof(struct node));
        if (new_node == NULL){
            printf("no space allocate\n");
            exit(-1);
        }

        printf("Enter a value and its priority: ");
        scanf("%d %d", &val, &pri);

        new_node -> data = val;
        new_node -> priority = pri;

        if (p == NULL || pri < p -> priority){
            new_node -> next = p;
            p = new_node;
        }else {
            while (p -> next != NULL &&p -> next -> priority <= pri)
                p = p -> next;
            new_node -> next = p -> next;
            p -> next = new_node;
        }

        return p;
}

struct node *deleteNode(struct node *p)
{
        if (p == NULL){
            printf("Underflow\n");
            return ;
        } else{
            //struct node *temp = p;
            printf("Deleted number is %d\n", p -> data);
            p = p -> next;
        }

        return p;
}

void display(struct node *p)
{
    if (p != NULL){
        printf("val[%d]  pri[%d]\n", p -> data, p -> priority);
        display(p -> next);
    }
}
