#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

int findLen(Node* head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}

void bubbleSort(Node* head, int len){
    for(int i=0; i<len; i++){
        Node* start=head;
        for(int j=0; j<len-i-1; j++){
            if(start->data>start->next->data){
                int val=start->data;
                start->data=start->next->data;
                start->next->data=val;
            }
            start=start->next;
        }
    }  
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

    temp=head;
    printf("Elements before sorting are:\n");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
    
    if(head==NULL){  // List is empty
        return 0;
    }
    
    if(head->next==NULL){  // single element in list
        printf("Elements after sorting are:\n");
        printf("%d",head->data);
        return 0;
    }
    
    int len=findLen(head);
    
    bubbleSort(head, len);
    
    temp=head;
    printf("Elements after sorting are:\n");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    
    free(head);
    return 0;
}
