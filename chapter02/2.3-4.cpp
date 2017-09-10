//插入排序递归版本
#include<stdio.h>
void INSERTION(int *s, int length, int n)
{
    if(n >= length) return ;
    else {
        int key = s[n];
        int j = n - 1;
        while(j >= 0 && s[j] > key){
            s[j + 1]= s[j];
            --j;
        }
        s[j + 1] = key;
        INSERTION(s, length, n + 1);
    }
}
int main()
{
    int length = 8;
    int s[10] = {5, 6, 4, 7, 3, 8, 2, 9};
    INSERTION(s, 8, 1);
    for(int i = 0; i < length; ++i)
        printf("%d ", s[i]);
    printf("\n");
    return 0;
}
