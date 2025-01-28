#include <stdio.h>
#include<stdlib.h>
 
void merge(int * arr, int low, int mid, int high){
    int len=high-low+1;
    int *temp=(int*)calloc(len, sizeof(int));
    int start1=low, end1=mid;
    int start2=mid+1, end2=high;
    int index=0;
    while(start1<=end1 && start2<=end2){
        if(arr[start1]>arr[start2]){
            temp[index++]=arr[start2++];
        }else{
            temp[index++]=arr[start1++]; 
        }
    }
    while(start1<=end1){
        temp[index++]=arr[start1++];
    }
    while(start2<=end2){
        temp[index++]=arr[start2++];
    }
    for(int i=0; i<len; i++){
        arr[low+i]=temp[i];
    }
}
 
void divide(int *arr, int low, int high){
    if(low==high) return;
    int mid=(low+high)/2;
    divide(arr, low, mid);
    divide(arr, mid+1, high);
    merge(arr, low, mid, high);
}
 
int main() {
    int inputSize;
    printf("Enter size of input array:\n");
    scanf("%d", &inputSize);
    int* arr=(int*)calloc(inputSize, sizeof(int));
    for(int start=0; start<inputSize; start++){
        printf("Enter value of element%d: ",start+1);
        scanf("%d",&arr[start]);
    }
    divide(arr, 0, inputSize);
    for(int start=0; start<inputSize; start++){
        printf("%d ", arr[start]);
    }
    printf("\n");
    return 0;
}
