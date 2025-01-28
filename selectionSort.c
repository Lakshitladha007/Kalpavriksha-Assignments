#include<stdio.h>
#include<stdlib.h>
 
void selectionSort(int *arr, int len){
    for(int i=0; i<len; i++){
        int minIndex=i;
        for(int j=i+1; j<len; j++){
            if(arr[minIndex]>arr[j]){
                minIndex=j;
            }
        }
        int temp=arr[minIndex];
        arr[minIndex]=arr[i];
        arr[i]=temp;
    }
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
    
    selectionSort(arr,inputSize);
    
    for(int start=0; start<inputSize; start++){
        printf("%d ", arr[start]);
    }
    
    return 0;
}

