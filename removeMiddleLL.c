#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
    char data;
    struct Node* next;
}Node;

int main() {
    int n;
    printf("Enter value of total nodes:\n");
    scanf("%d", &n);
    getchar();
    
    if(n<=0){
        printf("Invalid input\n");
        return 0;
    }
    
    Node* head=NULL;
    Node* temp=NULL;
    
    int flag=1;
    while(n--){
        char val;
        printf("Enter value of node:\n");
        scanf("%c", &val);
        getchar();
        Node* newNode= (Node*)malloc(sizeof(Node));
        newNode->data=val;
        newNode->next=NULL;
        if(flag){
            flag=0;
            head=newNode;
            temp=newNode;
        }else{
            temp->next=newNode;
            temp=newNode;
        }
    }
    
    Node* slow=head;
    Node* fast=head;
    Node* prev=NULL;
    while(fast->next!=NULL && fast->next->next!=NULL){
         prev=slow;
         slow=slow->next;
         fast=fast->next->next;
    }
    if(prev!=NULL){
     prev->next=slow->next;
    }else{
        if(head->next==NULL){
            printf("After deletion the linked list is empty\n");
            return 0;
        }
        printf("%d", head->next->data);
        return 0;
    }
    
    temp=head;
    while(temp!=NULL){
        printf("%c ", temp->data);
        temp=temp->next;
    }
    printf("\n");
    return 0;
}
