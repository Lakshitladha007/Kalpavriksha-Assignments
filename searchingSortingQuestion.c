#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int data;
    struct Node *next;
} Node;
 
 int comp(const void*a , const void* b){
     return *(int*)a-*(int*)b;
 }
 
Node* inputList(int n) {
    Node* head = NULL;
    Node* temp = NULL;
    int flag = 1;
    while (n--) {
        int val;
        printf("Enter value of element: ");
        scanf("%d", &val);
        Node* curr = (Node*)malloc(sizeof(Node));
        if (flag) {
            flag = 0;
            head = curr;
            curr->data = val;
            curr->next = NULL;
            temp = head;
        } else {
            curr->data = val;
            curr->next = NULL;
            temp->next = curr;
            temp = curr;
        }
    }
    return head;
}

Node* mergeSortedLists(Node* head1, Node* head2){
    Node* dummy = (Node*)malloc(sizeof(Node));
    dummy->next = NULL;
    Node* temp = dummy;
 
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            temp->next = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    if (head1 != NULL) {
        temp->next = head1;
    }
    if (head2 != NULL) {
        temp->next = head2;
    }
    temp=dummy->next;
    free(dummy);
    return temp;
}
 
void printMaxFrequency(Node* head){
    int frequency = -1;
    int element= 0;
    Node* temp=head;
    while (temp != NULL) {
        int curr = temp->data;
        int count = 0;
        while (temp != NULL && temp->data == curr) {
            count++;
            temp = temp->next;
        }
        if (count > frequency) {
            frequency = count;
             element= curr;
        }
    }
 
    printf("The element with the highest frequency is %d and the frequency is %d\n", element, frequency);
}

void sortList(Node* head, int n){
    int *arr=(int *)calloc(n, sizeof(int));
    Node* temp=head;
    int index=0;
    while(temp!=NULL){
        arr[index++]=temp->data;
        temp=temp->next;
    }
    
    qsort(arr,n, sizeof(int), comp);
    
    temp=head;
    index=0;
    while(temp!=NULL){
        temp->data=arr[index++];
        temp=temp->next;
    }
}

int main() {
    int n1;
    printf("Enter number of nodes of list 1:\n");
    scanf("%d", &n1);
    Node* head1 = inputList(n1);
    
    int n2;
    printf("Enter number of nodes of list 2:\n");
    scanf("%d", &n2);
    Node* head2 = inputList(n2);
    
    sortList(head1, n1);
    sortList(head2, n2);
    
    Node* newHead=mergeSortedLists(head1, head2);
    
    printf("List after sorting are:\n");
    
    Node* temp=newHead;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    
    printf("\n");
    printMaxFrequency(newHead);
    
    return 0;
}
