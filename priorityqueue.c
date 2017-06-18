/*
    우선순위 큐 (Priority Queue)

    우선순위 큐를 연결리스트를 통해서 구현하였다.

    이 큐는 우선순위 숫자를 기준으로 위치가 배정된다. (숫자가 낮으면 우선순위가 높다고 가정한다. 반대로 숫자가 높으면 우선순위가 낮다. 우선순위 숫자가 같다면, FCFS 법칙을 따른다. (먼저 들어온 노드가 먼저 처리되는 방식))

    활용될 수 있는 예)
        현재 윈도우에 A, B, C 라는 프로세스(process) 가 있다고 가정하자. 또, 우선순위는 한 process가 실행완료 되는 속도를 기준으로 매겨진다고 가정하자.
        A의 처리속도 = 4ns, B의 처리속도 = 3ns, C의 처리속도 = 5ns 라고 할때, 운영체제는 B -> A -> C 순으로 process를 진행할 것이다.
    
    시간복잡도.
        정렬된 리스트의 리스트 내로의 삽입은 O(n), 삭제는 O(1) 이다.
        반대로, 정렬되지 않은 리스트의 리스트 내로의 삽입은 O(1), 삭제는 O(n)이다.

        하지만, 실제로는 위 두가지 기법이 효율적이지 않아, 두가지 기법을 섞은 방법을 사용하며, 시간복잡도는 O(logn) 이하를 가진다.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;       // 노드에 삽입 될 데이터.
    int priority;     // 노드에 삽입 될 우선순위숫자.
    struct node *next; // 다음 노드를 가르킬 포인터.
};

struct node *insertNode(struct node *p);    // 우선순위 큐에 노드 삽입.    (작업 추가)
struct node *deleteNode(struct node *p);  // 우선순위 큐에 있는 노드를 삭제. (완료된 작업 삭제 아니면 실행단계로 노드를 넘긴다고 생각해도 될 듯.)
void display(struct node *p);                       // 큐에 있는 노드들을 출력.

int main(void)
{
    int oper;
    struct node *pqueue = NULL;   // 큐 초기화.

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
        if (new_node == NULL){               // 메모리를 할당할 수 없을때.
            printf("no space allocate\n");
            exit(-1);
        }

        printf("Enter a value and its priority: ");
        scanf("%d %d", &val, &pri);                   //노드의 데이터값과 우선순위 값을 입력받음.

        new_node -> data = val;                     // 노드의 데이터에 입력받은 데이터 값을 할당.
        new_node -> priority = pri;                    // 노드의 우선순위 값에 입력받은 우선순위값을 할당.

        if (p == NULL || pri < p -> priority){      // 현재 리스트가 비어있거나, 새로 입력받은 우선순위 값이 맨 왼쪽에 있는 우선순위 값보다 낮을때. 즉, 새로 입력받은 노드의 우선순위가 기존에 있던 우선순위 보다 높을때.
            new_node -> next = p;                     // 큐의 왼쪽지점에 새로 입력 받은 노드를 삽입한다.
            p = new_node;
        }else {                                                    // 새로 입력받은 노드의 우선순위가 기존에 있는 우선순위보다 낮을때 아래 작업을 수행한다.
            while (p -> next != NULL && p -> next -> priority <= pri)         // p -> next 가 NULL 이 아니고 p -> next -> priority 가 새로 입력받은 우선순위 값보다 낮을때까지(큐 내에 새로입력받은 우선순위보다 낮은 노드를 발견할때까지) 루프를 반복한다.
                p = p -> next;
            new_node -> next = p -> next;  // 연결과정.
            p -> next = new_node;
        }

        return p;
}

struct node *deleteNode(struct node *p)
{
        if (p == NULL){
            printf("Underflow\n");
            return ;
        } else{                                    // 삭제는 간단하게 맨 왼쪽에서만 이루워진다. 왜냐하면 왼쪽에 있는 노드가 우선순위가 가장 높기 때문이다.
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
