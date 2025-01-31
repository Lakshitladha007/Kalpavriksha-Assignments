#include <stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_LEN 7
typedef struct Queue{
    int front, rear;
    int arr[MAX_LEN];
}Queue;

void intialize(Queue *queue){
    queue->rear=-1;
    queue->front=-1;
}

int isEmpty(Queue *queue){
    return (queue->front==-1 && queue->rear==-1);
}

int isFull(Queue *queue){
     return queue->rear==MAX_LEN-1;
}

void enqueue(Queue *queue, int val){
    if(isFull(queue)){
        printf("Queue oveflow, can't enqueue element.\n");
        return;
    }else{
        if(queue->front==-1 && queue->rear==-1){
            queue->front=0;
            queue->rear=0;
            queue->arr[(queue->rear)]=val;
        }else{
            queue->rear++;
            queue->arr[(queue->rear)]=val;
        }
    }
}

void dequeue(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue underflow, can't dequeue element.\n");
        return;
    }else if(queue->front==queue->rear){
        queue->front=-1;
        queue->rear=-1;
    }else{
        queue->front++;
    }
    printf("Successfully dequed an element.\n");
}

int getFront(Queue *queue){
    if(isEmpty(queue)){
        printf("Can't get front element, the queue is empty.\n");
        return INT_MAX;
    }
    return queue->arr[queue->front];
}

void display(Queue *queue){
    if(isEmpty(queue)){
        printf("Can't display elements, the queue is empty.\n");
        return;
    }
    printf("The elements in stack are:\n");
    for(int i=queue->front; i<=queue->rear; i++){
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter total number of operations:\n");
    scanf("%d", &n);
    Queue queue;
    intialize(&queue);
    
    while(n--){
        int choice;
        printf("Enter the choice of operation:\n1.Add element to Queue.\n2.Remove element from Queue.\n");
        printf("3.Display elements of Queue.\n4.Check Queue is empty or not.\n");
        printf("5.Get the element at front of Queue.\n6.Exit the program.\n");
        scanf("%d", &choice);
        switch(choice){
        case 1:
        printf("Enter the data:");
        int val;
        scanf("%d", &val);
        enqueue(&queue, val);
        break;
        case 2:dequeue(&queue);
        break;
        case 3:display(&queue);
        break;
        case 4:
        if(isEmpty(&queue)){
            printf("Queue is empty.\n");
        }else{
            printf("Queue is not empty.\n");
        }
        break;
        case 5: 
        int frontElement=getFront(&queue);
        if(frontElement!=INT_MAX){
            printf("Element at front is %d", frontElement);
        }
        break;
        case 6: return 0;
        default:
            break;
        }
    }
    return 0;
}
