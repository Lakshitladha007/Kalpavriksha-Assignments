#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* createLL(){
    int n;
    printf("enter number of nodes in list:\n");
    scanf("%d", &n);
    Node* head=NULL;
    Node* temp=NULL;
    Node* back=NULL;
    int flag=1;
    while(n--){
       int val;
       printf("Enter value of element\n");
       scanf("%d", &val);
       Node* curr= (Node*)malloc(sizeof(Node));
       if(flag){
         curr->data=val;
         curr->next=NULL;
         curr->prev=NULL;
         head=curr;
         temp=curr;
         flag=0;
       } else{
         curr->data=val;
         curr->next=NULL;
         curr->prev=temp;
         temp->next=curr;
         temp=curr;
       }
    }
    return head;
}

int findLength(Node* head){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
}

void mergeList(Node* head1, Node* head2, int* arr){
    
    int index=0;
    Node* temp1=head1;
    Node* temp2=head2;
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
        arr[index++]=temp1->data;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        arr[index++]=temp2->data;
            temp2=temp2->next;
    }
   
}

int main(){
   Node* head1=createLL();
   Node* head2=createLL();
   
    int len= findLength(head1)+findLength(head2);
    int* arr= (int*)calloc(len, sizeof(int));
    mergeList(head1, head2,arr);
    
   // joining bot the lists
   Node* temp=head1;
   while(temp->next!=NULL){
       temp=temp->next;
   }
   temp->next=head2;
   head2->prev=temp;
    temp=head1;
    
    int index=0;
    // copying array data into list
    while(temp!=NULL){
        temp->data=arr[index++];
        temp=temp->next;
    }
    
    printList(head1);
    return 0;
}
