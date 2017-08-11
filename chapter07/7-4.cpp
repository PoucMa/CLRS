#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int PARTITION(int *A, int p, int r)
{
    int i = p, j = r + 1;
    int x = A[p];
    // 将< x的元素交换到左边区域
    // 将> x的元素交换到右边区域
    while(true) {
       while (A[++i] < x && i < r);
       while (A[--j] > x);
       if (i >= j) break;
       swap(A[i], A[j]);
    }
   A[p] = A[j];
   A[j] = x;
   return j;
}

//
//int PARTITION(int *A, int p, int r)
//{
//    int x = A[r];
//    int i = p - 1;
//    for(int j = p; j <= r - 1; ++j){
//        if(A[j] < x){
//            i = i + 1;
//            swap(A[j], A[i]);
//        }
//    }
//    swap(A[i + 1], A[r]);
//    return i + 1;
//}

//void QUICKSORT(int *A, int p, int r)
//{
//    if(p < r){
//        int q = PARTITION(A, p, r);
//        QUICKSORT(A, p, q - 1);
//        QUICKSORT(A, q + 1, r);
//    }
//}

//尾递归算法
void QUICKSORT(int *A, int p, int r)
{
    while(p < r){
        int q = PARTITION(A, p, r);
        QUICKSORT(A, p, q - 1);
        p = q + 1;
    }
}


int main(){
    int A[10] = {9, 3, 2, 4, 6, 1};
    QUICKSORT(A, 0, 5);
    for(int i = 0; i < 6; ++i){
        cout << A[i] << ' ';
    }cout << endl;
}


