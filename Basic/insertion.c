#include<stdio.h>
int main()
{	
    int arr[100];
    int lb, ub;
    printf("Enter the Lower Bound & Upper Bound of the array:\n");
    scanf("%d %d", &lb, &ub);

    int i;
    printf("Input the values of array:\n");
    for(i=lb;i<=ub;i++){
        scanf("%d",&arr[i]);
    }

    printf("Array:");
    for(int i=lb;i<=ub;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    int p,v;
    printf("Enter the position where you want to add a new value: ");
    scanf("%d", &p);
    printf("Enter the value:");
    scanf("%d",&v);

    int j;

    for (j=ub; j>=p; j--) {
        arr[j + 1] = arr[j];
    }
    arr[p] = v;
    ub++;

    printf("Array:");
    for(int i=lb;i<=ub;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}
