#include<stdio.h>

void MERGE(int *A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];
    for(int i = 0; i < n1; ++i)
        L[i] = A[p + i];
    for(int j = 0; j < n2; ++j)
        R[j] = A[q + 1 + j];
    int m = 0, n = 0;
    while(m < n1 && n < n2){
        if(L[m] < R[n]){
            A[p++] = L[m]; ++m;
        } else {
            A[p++] = R[n]; ++n;
        }
    }
    while(m < n1){
        A[p++] = L[m]; ++m;
    }
    while(n < n2){
        A[p++] = R[n]; ++n;
    }
}

void MERGE_SORT(int *A, int p, int r)
{
    if(p < r){
        int q = (p + r) / 2;
        MERGE_SORT(A, p, q);
        MERGE_SORT(A, q + 1, r);
        MERGE(A, p, q, r);
    }
}

int main()
{
    int A[10] = {6, 5, 4, 8, 7, 2, 4, 5};
    MERGE_SORT(A, 0, 7);
    for(int i = 0; i < 8; ++i) printf("%d ", A[i]);
}
