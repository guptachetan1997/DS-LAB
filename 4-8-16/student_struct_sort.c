#include <stdio.h>
#include <string.h>

#define clear() printf("\033[H\033[J")

struct student
{
    char name[50];
    int roll;
};
struct student stu_list[100];
int list_length = 0;

void insert()
{
    printf("Enter the record you want to insert\n");
    printf("Name : ");
    struct student a;
    scanf("%s", &a.name);
    printf("Roll No : ");
    scanf("%d", &a.roll);
    int start_index = 0;
    for(int i=list_length-1 ; i>=0 ; i--)
    {
        if(strcmp(stu_list[i].name, a.name) < 0)
        {
            start_index = i+1;
            break;
        }
    }
    for(int j=list_length-1 ; j!=start_index-1 ; j--)
    {
        stu_list[j+1] = stu_list[j];
    }
    stu_list[start_index] = a;
    list_length++;
}

void display()
{
    printf("\nThe List is : \n");
    for(int j=0 ; j<list_length ; j++)
    {
        printf("%s : %d \n",stu_list[j].name, stu_list[j].roll);
    }
}

int search()
{
    printf("Enter the name you want to search for : ");
    char name[50];
    scanf("%s", name);
    int low=0,high=list_length,mid, flag=0;
    mid = (low+high)/2;
    do
    {
        if(strcmp(stu_list[mid].name, name) < 0)
            low = mid+1;
        else if (strcmp(stu_list[mid].name, name) > 0)
            high = mid-1;
        else
        {
            flag=1;
            break;
        }
        mid = (low+high)/2;
    }
    while(low<=high);
    if(flag)
    {
        printf("Student Found : \n");
        printf("%s : %d \n", stu_list[mid].name, stu_list[mid].roll);
        return mid;
    }
    else
    {
        printf("No entry found!");
        return -1;
    }
}

void deletes()
{
    int index = search();
    printf("\n");
    if(index != -1)
    {
        printf("Deleting Student!\n");
        for(int j=index ; j<= list_length-1 ; j++)
        {
            stu_list[j] = stu_list[j+1];
        }
        list_length--;
    }
}



int main()
{
    while(1)
    {
        printf("\n\n\n");
        printf("Enter your choice\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        int choice;
        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            deletes();
            break;
        case 3:
            search();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        }
    }
}
