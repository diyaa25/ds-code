#include <stdio.h>

struct Student
{
    int rollNo;
    char name[30];
    float marks;
};

void display(struct Student s[], int n)
{
    int i;

    printf("\nRoll No\tName\tMarks\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%s\t%.2f\n",
               s[i].rollNo, s[i].name, s[i].marks);
    }
}

void insertionSort(struct Student s[], int n)
{
    int i, j;
    struct Student temp;

    for(i = 1; i < n; i++)
    {
        temp = s[i];
        j = i - 1;

        while(j >= 0 && s[j].rollNo > temp.rollNo)
        {
            s[j + 1] = s[j];
            j--;
        }

        s[j + 1] = temp;
    }
}

void selectionSort(struct Student s[], int n)
{
    int i, j, min;
    struct Student temp;

    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(s[j].rollNo < s[min].rollNo)
            {
                min = j;
            }
        }

        temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }
}

void shellSort(struct Student s[], int n)
{
    int gap, i, j;
    struct Student temp;

    for(gap = n / 2; gap > 0; gap = gap / 2)
    {
        for(i = gap; i < n; i++)
        {
            temp = s[i];
            j = i;

            while(j >= gap &&
                  s[j - gap].rollNo > temp.rollNo)
            {
                s[j] = s[j - gap];
                j = j - gap;
            }

            s[j] = temp;
        }
    }
}

int main()
{
    struct Student s[50];
    int n, i, choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Enter Roll No: ");
        scanf("%d", &s[i].rollNo);

        printf("Enter Name: ");
        scanf("%29s", s[i].name);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }

    printf("\nOriginal Student Database:");
    display(s, n);

    printf("\n\n----- SORTING MENU -----");
    printf("\n1. Insertion Sort");
    printf("\n2. Selection Sort");
    printf("\n3. Shell Sort");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            insertionSort(s, n);
            printf("\nAfter Insertion Sort:");
            display(s, n);
            break;

        case 2:
            selectionSort(s, n);
            printf("\nAfter Selection Sort:");
            display(s, n);
            break;

        case 3:
            shellSort(s, n);
            printf("\nAfter Shell Sort:");
            display(s, n);
            break;

        default:
            printf("\nInvalid choice!");
    }

    return 0;
}