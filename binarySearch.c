#include <stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int target, int len){
    
    int start=0, end=len-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]>target){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return -1;
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
    int target;
    printf("Enter target element:");
    scanf("%d",&target);
    int index=binarySearch(arr, target, inputSize);
    if(index==-1){
        printf("Element not found\n");
    }else{
        printf("Element found at index: %d\n", index);
    }
    return 0;
 
    free(arr);
}
