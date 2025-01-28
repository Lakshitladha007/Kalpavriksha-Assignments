#include <stdio.h>
#include<stdlib.h>

int linearSearch(int arr[], int target, int len){
    
    int index=0;
    while(index<len){
        if(arr[index]==target){
            return index;
        }
        index++;
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
    int index=linearSearch(arr, target, inputSize);
    if(index==-1){
        printf("Element not found\n");
    }else{
        printf("Element found at index: %d\n", index);
    }
    return 0;
 
    free(arr);
}
