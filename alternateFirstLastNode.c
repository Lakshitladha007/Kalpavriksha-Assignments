#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* reverse(Node* head){
    Node* temp=head;
    Node* prev=NULL;
    Node* forward=NULL;
    while(temp!=NULL){
        forward=temp->next;
        temp->next=prev;
        prev=temp;
        temp=forward;
    }
    return prev;
}

int main(){
    int n;
    printf("enter number of nodes:\n");
    scanf("%d", &n);

    Node* head=NULL;
    Node* temp=NULL;
    int flag=1;
    while(n--){
       int val;
       printf("Enter value of element\n");
       scanf("%d", &val);
       Node* curr= (Node*)malloc(sizeof(Node));
       if(flag){
        flag=0;
        head=curr;
        curr->data=val;
        curr->next=NULL;
        temp=head;
       } else{
         curr->data=val;
         curr->next=NULL;
         temp->next=curr;
         temp=curr;
       }
    }
    
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    temp=head;
    Node* newHead= reverse(slow->next);
    slow->next=NULL;
    Node* iterator=newHead;
    Node* prev1=NULL;
    Node* prev2=NULL;
    while(iterator!=NULL){
        prev1=temp->next;
        temp->next=iterator;
        prev2=iterator->next;
        iterator->next=prev1;
        temp=prev1;
        iterator=prev2;
    }
    temp=head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    return 0;
}
