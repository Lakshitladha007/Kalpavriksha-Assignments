#include<stdio.h>
#include<stdlib.h>
 
void insertionSort(int *arr, int len){
    for(int i=1; i<len; i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
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
    insertionSort(arr, inputSize);
 
    for(int start=0; start<inputSize; start++){
        printf("%d ", arr[start]);
    }
    printf("\n");
 
    free(arr);
    return 0;
 
}
