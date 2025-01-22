#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

int main(){
    int n1;
    printf("enter number of nodes in list1:\n");
    scanf("%d", &n1);
    Node* head1=NULL;
    Node* temp1=NULL;
    Node* back1=NULL;
    int flag=1;
    while(n1--){
       int val;
       printf("Enter value of element\n");
       scanf("%d", &val);
       Node* curr= (Node*)malloc(sizeof(Node));
       if(flag){
         curr->data=val;
         curr->next=NULL;
         curr->prev=NULL;
         head1=curr;
         temp1=curr;
         flag=0;
       } else{
         curr->data=val;
         curr->next=NULL;
         curr->prev=temp1;
         temp1->next=curr;
         temp1=curr;
       }
    }
    
    int n2;
    printf("enter number of nodes in list2:\n");
    scanf("%d", &n2);

    Node* head2=NULL;
    Node* temp2=NULL;
    while(n2--){
        int val;
        printf("Enter value of element\n");
        scanf("%d", &val);
        Node* curr= (Node*)malloc(sizeof(Node));
        if(flag){
        flag=0;
        head2=curr;
        curr->data=val;
        curr->next=NULL;
        temp2=head2;
        } else{
         curr->data=val;
         curr->next=NULL;
         temp2->next=curr;
         temp2=curr;
        }
    }
    
    temp1=head1;
    temp2=head2;
    int len=n1+n2;
    int* arr= (int*)calloc(len, sizeof(int));
    int index=0;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<=temp2->data){
            arr[index++]=temp1->data;
            temp1=temp1->next;
        }else{
            arr[index++]=temp2->data;
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        arr[index++]=temp->data;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        arr[index++]=temp->data;
        temp1=temp1->next;
    }
    
    for(int i=0; i<len; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
