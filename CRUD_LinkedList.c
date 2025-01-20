#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
   int data;
   struct Node* next;
}Node;

Node* insertAtEnd(Node* head){
   int val;
   printf("enter the data to insert at the end:\n");
   scanf("%d", &val);
   Node *newNode=(Node*)malloc(sizeof(Node));
   newNode->data=val;
   newNode->next=NULL;
   if(head==NULL){
       head=newNode;
       return head;
   }
   Node *temp=head;
   while(temp->next!=NULL){
       temp=temp->next;
   }
   temp->next=newNode;
   return head;
}

Node* insertAtBegin(Node* head){
   int val;
   printf("enter the data to insert at the begin:\n");
   scanf("%d", &val);
   Node *newNode=(Node*)malloc(sizeof(Node));
   newNode->data=val;
   newNode->next=head;
   head=newNode;
   return head;
}

Node* insertAtPosition(Node* head){
   int position;
   printf("enter the position where you want to insert data:\n");
   scanf("%d", &position);
   if(position<=0){
       printf("Invalid position\n");
       return head;
   }
   int val;
   printf("enter the data:\n");
   scanf("%d", &val);
   
   Node *dummy=(Node*)malloc(sizeof(Node));
   dummy->data=0;
   dummy->next=head;
   
   Node* previous=dummy;
   Node *temp=head;
   while(temp!=NULL && position>1){
       position--;
       previous=temp;
       temp=temp->next;
   }
   if(temp==NULL && position>1){
      printf("Invalid position\n");
      return head;
   }
   
   Node *newNode=(Node*)malloc(sizeof(Node));
   newNode->data=val;
   previous->next=newNode;
   newNode->next=temp;
   return dummy->next;
}

void display(Node* head){
   if(head==NULL){
       printf("Can't display elements, since the list is empty.\n");
       return;
   }
   printf("The elements of the List are:\n");
   struct Node* temp=head;
   while(temp!=NULL){
       printf("%d ", temp->data);
       temp=temp->next;
   }
   printf("\n");
}

Node* deleteAtBegin(Node * head){
   if(head==NULL){ 
      printf("Can't delete an element, since the list is empty.\n");
      return head;
   }
   if(head->next==NULL){  
       free(head);
       printf("Successfully deleted an element\n");
       return NULL;
   }
   Node* temp=head;
   head=head->next;
   free(temp);
   printf("Successfully deleted an element\n");
   return head;
}

Node* deleteAtEnd(Node * head){
    if(head==NULL){ 
      printf("Can't delete an element, since the list is empty.\n");
      return head;
   }
   if(head->next==NULL){  
       free(head);
       printf("Successfully deleted an element\n");
       return NULL;
   }
   Node* temp=head;
   while(temp->next->next!=NULL){
       temp=temp->next;
   }
   Node* previous=temp;
   temp=temp->next;
   free(temp);
   previous->next=NULL;
   printf("Successfully deleted an element\n");
   return head;
}

Node* deleteAtPosition(Node * head){
    int position;
    printf("enter the position at which element has to be deleted:\n");
    scanf("%d", &position);
    if(position<=0){
        printf("Invalid position.\n");
        return head;
    }
    if(head==NULL){ 
      printf("Can't delete an element, since the list is empty.\n");
      return head;
    }
    Node *dummy= (Node *)malloc(sizeof(Node));
    dummy->data=0;
    dummy->next=head;
    
    Node* temp=head;
    Node* previous=dummy;
    while(temp!=NULL && position>1){
        position--;
        previous=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Invalid position.\n");
        return dummy->next;
    }
    previous->next=temp->next;
    free(temp);
    printf("Successfully deleted an element\n");
    return dummy->next;
}

Node* update(Node * head){
   int position;
   printf("enter the position where you want to update data:\n");
   scanf("%d", &position);
   if(position<=0){
       printf("Invalid position\n");
       return head;
   }
   
   int val;
   printf("Enter the value of data:\n");
   scanf("%d", &val);
   
   if(head==NULL){ 
   printf("Can't update, since the list is empty.\n");
   return head;
   }
   
   Node* temp=head;
   while(temp!=NULL && position>1){
        position--;
        temp=temp->next;
    }
    if(temp==NULL){   
        printf("Invalid position\n");
        return head;
    }
    temp->data=val;
    return head;
}

int main() {
   int n;
   printf("Enter 'n' representing the number of operations to be performed.\n");
   scanf("%d", &n);
   Node *head=NULL;
   while(n--){
       int choice;
       printf("Enter an integer representing the operation to be performed.\n1 x: Add x to the end. (x: is any number and pos: position)\n2 x: Add x at the beginning.\n3 pos x: Add x at position pos (1-indexed).\n4: Display all elements.\n5 pos x: Update the element at position pos to x.\n6: Delete the first element.\n7: Delete the last element.\n8 pos: Delete the element at position pos (1-indexed).\n");
       scanf("%d", &choice);
       switch(choice){
           case 1:
           head=insertAtEnd(head);
           break;
           case 2:
           head=insertAtBegin(head);
           break;
           case 3:
           head=insertAtPosition(head);
           break;
           case 4:
           display(head);
           break;
           case 5:
           head=update(head);
           break;
           case 6:
           head=deleteAtBegin(head);
           break;
           case 7:
           head=deleteAtEnd(head);
           break;
           case 8:
           head=deleteAtPosition(head);
           break;
           default:
           printf("Invalid choice.\n");
           break;
       }
   }
   return 0;
}
