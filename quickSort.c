#include<stdio.h>
#include<stdlib.h>

int partition(int *arr, int start, int end)
{
    int indexStart = start - 1;
    int pivot = arr[end];
    for (int indexTillPivot = start; indexTillPivot < end; indexTillPivot++)
    {
        if (arr[indexTillPivot] <= pivot)
        {
            indexStart++;
            int temp=arr[indexTillPivot];
            arr[indexTillPivot]=arr[indexStart];
            arr[indexStart]=temp;
        }
    }
    indexStart++;
    int temp=arr[indexStart];
    arr[indexStart]=arr[end];
    arr[end]=temp;
    return indexStart;
}
 
void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}
 
int main()
{
    int inputSize;
    printf("Enter size of input array:\n");
    scanf("%d", &inputSize);
    
    int* arr=(int*)calloc(inputSize, sizeof(int));
    for(int start=0; start<inputSize; start++){
        printf("Enter value of element%d: ",start+1);
        scanf("%d",&arr[start]);
    }
 
    printf("Elements before sorting are:\n");
    for(int start=0; start<inputSize; start++){
        printf("%d ", arr[start]);
    }
    
    printf("\n");
    quickSort(arr, 0, inputSize-1);
 
    printf("Elements after sorting are:\n");
    for(int start=0; start<inputSize; start++){
        printf("%d ", arr[start]);
    }
    
    printf("\n");
    
    return 0;
}
 
