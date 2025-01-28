#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
   return *(int *)a - *(int *)b;
}

int printSubset(int subset[], int size, int target) {
   int currentSum = 0;
   for (int i = 0; i < size; i++) {
       currentSum += subset[i];
   }
   if(currentSum == target){
      for (int i = 0; i < size; i++) {
           printf("%d ", subset[i]);
       }
       printf("\n");
   }
}

void findSubsets(int arr[], int start, int target, int subset[], int subsetSize, int arrSize) {
   printSubset(subset, subsetSize, target);
   for (int i = start; i < arrSize; i++) {
       if (i > start && arr[i] == arr[i - 1]) {
           continue;
       }
       subset[subsetSize] = arr[i];
       findSubsets(arr, i + 1, target, subset, subsetSize + 1, arrSize);
   }
}

int main() {
   int size;
   printf("Enter the number of elements:\n");
   scanf("%d", &size);

   int arr[size], subset[size];
   printf("Enter the elements:\n");
   for (int i = 0; i < size; i++) {
       scanf("%d", &arr[i]);
   }

   int targetSum;
   printf("Enter the target sum:\n");
   scanf("%d", &targetSum);

   qsort(arr, size, sizeof(int), comp);

   printf("Subsets with target sum %d:\n", targetSum);
   findSubsets(arr, 0, targetSum, subset, 0, size);

   return 0;
}
