#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *next;
}ListNode;

ListNode* findMiddle(ListNode* head){
    if(head==NULL) return head;
    if(head->next==NULL) return head;
        
    ListNode* slow=head;
    ListNode* fast=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

ListNode* mergeList(ListNode* head1, ListNode* head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;

    ListNode* dummy=(ListNode*)calloc(1, sizeof(ListNode));
    dummy->next=NULL;
    ListNode* temp=dummy;
    ListNode* temp1=head1;
    ListNode* temp2=head2;

    while(temp1!=NULL && temp2!=NULL){
        if(temp2->data>temp1->data){
            temp->next=temp1;
            temp1=temp1->next;
        }else{
            temp->next=temp2;
            temp2=temp2->next;
        }
        temp=temp->next;
    }
    if(temp1!=NULL){
        temp->next=temp1;
    }
    if(temp2!=NULL){
        temp->next=temp2;
    }
    
    return dummy->next;
}

ListNode* divide(ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    ListNode* leftHead=head;
    ListNode* rightHead=NULL;
    ListNode* temp=findMiddle(head);
    rightHead=temp->next;
    temp->next=NULL;

    leftHead=divide(leftHead);
    rightHead=divide(rightHead);
        
    return mergeList(leftHead, rightHead);
}

int main(){
    int n;
    printf("enter number of nodes:\n");
    scanf("%d", &n);

    ListNode* head=NULL;
    ListNode* temp=NULL;
    int flag=1;
    
    while(n--){
       int val;
       printf("Enter value of element\n");
       scanf("%d", &val);
       ListNode* curr= (ListNode*)malloc(sizeof(ListNode));
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
     
    temp=divide(head);
    
    printf("Elements after sorting are:\n");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    
    free(head);
    return 0;
}
