#include<stdio.h>
int main(){
    int a[] = { 6,2,1,5,3};
int *q;
q = a;
printf("%p\n",a);

printf("%p\n",q);
printf("%p\n",*q);
q++;
printf("%p\n",q);
printf("%p\n",*q);
q++;
printf("%p",q);
printf("%p",* q);

}