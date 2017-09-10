#include<stdio.h>

int length;
int *binAdd(const int a[], const int b[])
{
    int c[length + 1];
    bool add = false;
    for(int i = length - 1; i >= 0; --i) {
        if(!add) {
            if(a[i] + b[i] == 2) {
                c[i + 1] = 0;
                add = true;
            } else {
                c[i + 1] = a[i] + b[i];
                add = false;
            }
        } else {
            if(a[i] + b[i] == 2){
                c[i + 1] = 1;
                add = true;
            } else if(a[i] + b[i] == 1) {
                c[i + 1] = 0;
                add = true;
            } else {
                c[i + 1] = 0;
                add = false;
            }
        }
    }
    if(add) c[0] = 1;
    else c[0] = 0;
    return c;
}

int main()
{
    length = 3;
    int a[] = {0, 1, 1};
    int b[] = {1, 1, 1};
    int *c = binAdd(a, b);
    for(int i = 0; i <= length; ++i)
        printf("%d ", c[i]);
        printf("\n");
    return 0;
}
