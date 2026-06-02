
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
/*
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
*/


// 3️⃣ Function callback pointer has now the design to sort arrays based on different ranking mechanism... Example is based on absolute value of integer sorting in ascending and descending orders.

/*
#include <stdio.h>
#include <math.h>

int absolute_compare(int a, int b){
    if(abs(a) > abs(b)) return -1;
    else return 1;
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
    int A[] = {-31, 21, -25, 3, 13, 7};
    BubbleSort(A,6,absolute_compare);
    for(i = 0; i < 6; i++) printf("%d ", A[i]);
    
    return 0;
}
*/


// 4️⃣ More generic qsort algorithm found stdlib library. Takes two void pointers as arguments and compare using pointer address with typecast.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b){
    int A = *((int*)a);
    int B = *((int*)b);
    return abs(A) - abs(B);
}



int main(void){
    int i;
    int A[] = {-31, 21, -25, 3, 13, 7};
    qsort(A,6,sizeof(int),compare);
    for(i = 0; i < 6; i++) printf("%d ", A[i]);
    
    return 0;
}

