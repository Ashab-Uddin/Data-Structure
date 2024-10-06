#include <stdio.h>
struct student
{
    int id;
    char name[50];
    float cgpa;
} std[100];
int t=0;

void insert()
{
    printf("Enter student information:");
    scanf("%d %s %f",&std[t].id,std[t].name,&std[t].cgpa);
    t++;
}
void view()
{
    printf("Id\tName\tCGPA\n");
    for(int i=0;i<t;i++)
        printf("%d\t%s\t%.2f\n",std[i].id,std[i].name,std[i].cgpa);
}
void search()
{
    int Id,f=-1;
    printf("Enter the search Id:");
    scanf("%d",&Id);
    for(int i=0;i<t;i++)
        if(Id==std[i].id)
        {
            printf("Information found:\n");
            printf("Id\tName\tCGPA\n");
            printf("%d\t%s\t%.2f\n",std[i].id,std[i].name,std[i].cgpa);
            f++;
            break;
        }
    if(f==-1)
    printf("Information not found");
}
void edit()
{
    int Id,f=-1;
    printf("Enter the edit Id:");
    scanf("%d",&Id);
    for(int i=0;i<t;i++)
        if(Id==std[i].id)
        {
            printf("Edit the Information:\n");
            scanf("%d %s %f",&std[i].id,std[i].name,&std[i].cgpa);
            f++;
            break;
        }
    if(f==-1)
    printf("Information not found");
}
void delete()
{
    int Id,f=-1;
    printf("Enter the delete Id:");
    scanf("%d",&Id);
    for(int i=0;i<t;i++)
        if(Id==std[i].id)
        {
            for(int j=i;j<t;j++)
                std[j]=std[j+1];
            f++;
            t--;
            break;
        }
    if(f==-1)
    printf("Information not found");
}
int main()
{
    int n;
    do{
        printf("\n1.Insert\n2.View\n3.Search\n4.Edit\n5.Delete\n6.Exit\nEnter your option:");
        scanf("%d",&n);
        if(n==1)
            insert();
        else if(n==2)
            view();
        else if(n==3)
            search();
        else if(n==4)
            edit();
        else if(n==5)
            delete();
    }while(n<6);

    return 0;
}