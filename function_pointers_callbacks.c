
// 1️⃣ Bubble sort algorithm in C Based on higher rank logic

/*
#include <stdio.h>

void BubbleSort(int* A, int n){
    int i,j,temp;

    for(i =0; i<n; i++){
        for(j =0; j < n-1;j++){
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
             }
        }
    }
}

int main(void){
    int i;
    int A[] = {3,2,1,5,4,6};
    BubbleSort(A,6);
    for(i = 0; i < 6; i++) printf("%d ", A[i]);


    return 0;
}
*/

// 2️⃣ Bubble sort using function pointer and callback 

// Callback function should compare two integers, should return 1 if first element has higher rank, should return 0 if elements are equal, should return -1 if second element has higher rank.

#include <stdio.h>

int compare(int a, int b){
    if(a > b) return 1;
    else return -1;
}

void BubbleSort(int* A, int n, int (*compare)(int,int)){
    int i,j,temp;

    for(i =0; i<n; i++){
        for(j =0; j < n-1;j++){
            if((compare(A[j],A[j+1])) > 0){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
             }
        }
    }
}

int main(void){
    int i;
    int A[] = {3,2,1,5,4,6};
    BubbleSort(A,6,compare);
    for(i = 0; i < 6; i++) printf("%d ", A[i]);
    
    return 0;
}