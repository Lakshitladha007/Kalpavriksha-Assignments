#include<stdio.h>
#include<stdlib.h>
 
void bubbleSort(int *arr, int len){
    for(int i=0; i<len; i++){
        int flag=0;
        printf("%d pass\n", i);
        for(int j=0; j<len-i-1; j++){
            if(arr[j]>arr[j+1]){
                flag=1;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(!flag){
            break;
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
    bubbleSort(arr, inputSize);
 
    for(int start=0; start<inputSize; start++){
        printf("%d ", arr[start]);
    }
    printf("\n");
 
    free(arr);
    return 0;
 
}
