#include<stdio.h>

int length;
int heap_size;

void swap_(int &a, int &b)
{
    int t = a; a = b; b = t;
}
void MAX_HEAPIFY(int *A, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest;
    if(left < heap_size && A[left] > A[i]) {
        largest = left;
    } else {
        largest = i;
    }
    if(right < heap_size && A[right] > A[largest]) {
        largest = right;
    }
    if(largest != i){
        swap_(A[i], A[largest]);
        MAX_HEAPIFY(A, largest);
    }
}

void BUILD_MAX_HEAP(int *A)
{
    heap_size = length;
    for(int i = length / 2 - 1; i >= 0; --i) {
        MAX_HEAPIFY(A, i);
    }
}

void HEAPSORT(int *A)
{
    BUILD_MAX_HEAP(A);
    for(int i = length - 1; i >= 1; --i) {
        swap_(A[i], A[0]);
        heap_size -= 1;
        MAX_HEAPIFY(A, 0);
    }
}
int main()
{
    int A[100] = {9, 8, 7, 6, 5, 4, 3, 1, 2};
    length = 9;
    HEAPSORT(A);
    for(int i = 0; i < length; ++i)
        printf("%d ", A[i]);
}
