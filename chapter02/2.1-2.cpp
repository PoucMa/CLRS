#include<stdio.h>
void INSERTION(int *s, int length)
{
    for(int i = 1; i < length; ++i){
        int key = s[i];
        int j = i - 1;
        while(j >= 0 && s[j] < key){
            s[j + 1]= s[j];
            --j;
        }
        s[j + 1] = key;
    }
}
int main()
{
    int length = 8;
    int s[10] = {5, 6, 4, 7, 3, 8, 2, 9};
    INSERTION(s, 8);
    for(int i = 0; i < length; ++i)
        printf("%d ", s[i]);
    printf("\n");
    return 0;
}
