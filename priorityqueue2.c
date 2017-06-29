// Priory queue using heap!


#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct node{
    int info;
    int prior;
    struct node *left;
    struct node *right;
};

struct tree{
    int size;
    struct node queue[MAX];
};

struct tree priorqueue;

void initializeTree(struct node queue[])
{
    priorqueue.size = 0;
}

void HeapInsert(int prior, int info, struct node queue[])
{
    // H <- Table(h) is what?
    int n, m;
    n = priorqueue.size;

    if (n == MAX){
        printf("Heap is full\n");
        exit(-1);
    }

    m = n;

    while ((m > 0) && prior < (priorqueue.queue[(m - 1) / 2].prior)){
        priorqueue.queue[m] = priorqueue.queue[(m-1)/2];
        m = (m-1)/2;
    }

    priorqueue.queue[m].prior = prior;
    priorqueue.queue[m].info = info;

    priorqueue.size++;

}

int HeapDeleteMin(struct node queue[])
{
    int i, k, m, p, n;

    n = priorqueue.size;

    if (n == 0){
        printf("Heap is empty\n");
        exit(-1);
    }

    i = priorqueue.queue[0].info;
    k = priorqueue.queue[n-1].prior;
    m = 0;

    while (((2 * m + 1 < n) && (k > priorqueue.queue[2 * m + 1].prior)) || ((2 * m + 2 < n) && (k > priorqueue.queue[2 * m + 2].prior))){
        if (2 * m + 2 < n){
            if (priorqueue.queue[2 * m + 1].prior < priorqueue.queue[2 * m + 2].prior)
                p = 2 * m + 1;
            else
                p = 2 * m + 2;
        }else{
            p = n - 1;
        }
        priorqueue.queue[m] = priorqueue.queue[p];
        m = p;
    }

    priorqueue.queue[m] = priorqueue.queue[n-1];
    priorqueue.size--;

    return i;
}

int main(void)
{

    int i;
    struct node p = priorqueue.queue;

    initializeTree(priorqueue.queue);
    printf("%d\n", priorqueue.size);

    HeapInsert(5, 1, priorqueue.queue);
    HeapInsert(4, 2, priorqueue.queue);
    HeapInsert(3, 3, priorqueue.queue);
    HeapInsert(2, 4, priorqueue.queue);
    HeapInsert(1, 5, priorqueue.queue);

    for (i = 0; i < MAX; i++){
        printf("Prior[%d]\tInfo[%d]\n", priorqueue.queue[i].prior, priorqueue.queue[i].info);
    }

    for (i = 0; i < MAX; i++){
        printf("%d is deleted\n", HeapDeleteMin(priorqueue.queue));
    }

    return 0;
}
