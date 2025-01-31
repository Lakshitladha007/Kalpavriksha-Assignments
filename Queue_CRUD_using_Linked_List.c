#include <stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node{
    int data;
    int length;
    struct Node* next;
}Node;

Node* front=NULL;
Node* rear=NULL;

int isEmpty(){
    return (front==NULL && rear==NULL);
}

void enqueue(int val){
    Node* newNode=(Node*)malloc(sizeof(Node*));
    newNode->next=NULL;
    newNode->data=val;
    if(front==NULL && rear==NULL){
        front=rear=newNode;
    }else{
        rear->next=newNode;
        rear=newNode;
    }
}

void dequeue(){
    if(isEmpty()){
        printf("Queue underflow, can't dequeue element.\n");
        return;
    }else{
        Node* temp=front;
        front=front->next;
        temp->next=NULL;
        free(temp);
    }
    printf("Successfully dequed an element.\n");
}

int getFront(){
    if(isEmpty()){
        printf("Can't get front element, the queue is empty.\n");
        return INT_MAX;
    }
    return front->data;
}

void display(){
    if(isEmpty()){
        printf("Can't display elements, the queue is empty.\n");
        return;
    }
    printf("The elements in stack are:\n");
    Node* temp=front;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter total number of operations:\n");
    scanf("%d", &n);
    
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
        enqueue(val);
        break;
        case 2:dequeue();
        break;
        case 3:display();
        break;
        case 4:
        if(isEmpty()){
            printf("Queue is empty.\n");
        }else{
            printf("Queue is not empty.\n");
        }
        break;
        case 5: 
        int frontElement=getFront();
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
