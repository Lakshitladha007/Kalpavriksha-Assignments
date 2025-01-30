#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    int length;
    struct Node* next;
}Node;

Node* top=NULL;

void push(int val){
    Node* newNode=(Node*)calloc(1, sizeof(Node));
    if(top==NULL){ 
       newNode->length=1;
    }else{
        newNode->length=(top->length)+1;
    }
    newNode->data=val;
    newNode->next=top;
    top=newNode;
}

void pop(){
    if(top==NULL){  
        printf("Can't pop an element, the stack is empty.\n");
        return;
    }
    Node* temp=top;
    top=top->next;
    temp->next=NULL;
    free(temp);
}

int peak(){
    if(top==NULL){
        printf("Stack is empty\n");
        return 0;
    }
    return top->data;
}

int isEmpty(){
    if(top==NULL){
        return 1;
    }else{
        return 0;
    }
}

int getSize(){
    if(top==NULL){
        return 0;
    }else{
        return top->length;
    }

}

void display(){
    if(top==NULL){
        printf("Can't display elements, the stack is empty.\n");
        return;
    }
    Node* temp=top;
    printf("The elements in stack are:\n");
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
        printf("Enter the choice of operation:\n1.Add element to stack.\n2.Remove element from stack.\n");
        printf("3.Display elements of stack.\n4.Get size of stack.\n5.Check stack is empty or not.\n");
        printf("6.Exit the program.\n");
        scanf("%d", &choice);
        switch(choice){
        case 1:
        printf("Enter the data:");
        int val;
        scanf("%d", &val);
        push(val);
        break;
        case 2:pop();
        break;
        case 3:display();
        break;
        case 4:
        printf("The size of stack is: %d\n",getSize());
        break;
        case 5:
        if(isEmpty()){
            printf("Stack is empty.\n");
        }else{
            printf("Stack is not empty.\n");
        }
        break;
        case 6: return 0;
        break;
        default:
            break;
        }
    }
    return 0;
}
