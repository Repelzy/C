#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
    int value;
    struct Node *next;
} Node;

typedef struct{
    Node *head;
    Node *tail;
}queue;

void init_queue(queue *q){
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue *q, int value){
    //create a new node
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL) return false;

    new_node -> value = value;
    new_node ->next = NULL;
    //if there is a tail, connect tail to this new node
    if(q->tail = NULL){
        q->tail->next = new_node;
    }
    q->tail = new_node;
    
    //make sure head makes sense
    if(q->head == NULL){
        q->head = new_node;
    }
    return true;
}

int dequeue(queue *q){
    //check the queue empty
    if (q->head == NULL) return INT_MIN;
    //save the head
    Node *tmp = q->head;
    int res = tmp -> value;
    q->head = q->head ->next;
    if(q->head == NULL){
        q->tail = NULL;
    }
    free(tmp);
    return res;
}


int main(){
    queue q1,q2,q3;
    init_queue(&q1);
    init_queue(&q2);
    init_queue(&q3);

    enqueue(&q1, 56);
    enqueue(&q2, 25);
    enqueue(&q2, 21);
    enqueue(&q3, 11);
    int t = dequeue(&q2);
    printf("%d\n", t);
}