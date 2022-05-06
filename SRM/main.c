#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototype
void add_record();
void view_record();
void search_record();
void update_record();
void delete_record();

// define student structure
typedef struct student
{
    int roll;
    char name[20];
    char mobile[15];
    char course[20];
} student;

// menu function
void menu()
{
    while (1)
    {
        system("cls");
        int ch;
        printf("\n\t\t--------------- STUDENT MANAGEMENT SYSTEM ---------------\n");
        printf("\n\t\t1. Add Record\n\t\t2. View Record\n\t\t3. Search Record\n\t\t4. Update Record\n\t\t5. Delete Record\n\t\t6. Exit\n");
        printf("\n\t\tEnter Your Choice:- ");
        fflush(stdin);
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            add_record();
            break;
        case 2:
            view_record();
            break;
        case 3:
            search_record();
            break;
        case 4:
            update_record();
            break;
        // case 5:
        //     delete_record();
        //     break;
        case 6:
            exit(1);
        }
    }
}

// add record function
void add_record()
{
    FILE *fp;
    student s;
    char more = 'y';
    fp = fopen("student_data.txt", "ab+");
    fflush(stdin);
    while (more == 'y')
    {
        system("cls");
        printf("\n\t\t--------------- ENTER STUDENT DETAILS ---------------\n");
        // getting new student details
        fflush(stdin);
        printf("\n\t\tEnter Roll:- ");
        scanf("%d", &s.roll);
        fflush(stdin);
        printf("\t\tEnter Name:- ");
        scanf("%[^\n]", s.name);
        fflush(stdin);
        printf("\t\tEnter Mobile:- ");
        scanf("%[^\n]", s.mobile);
        fflush(stdin);
        printf("\t\tEnter Course:- ");
        scanf("%[^\n]", s.course);
        // saving new student details into student data file.
        fwrite(&s, sizeof(s), 1, fp);
        // ask to user for adding more records or not.
        printf("\n\t\tDo you want to add more record ? press 'y' or 'n' :- ");
        fflush(stdin);
        more = getche();
    }
    fclose(fp);
    printf("\n\n\t\tPress any to Continue...");
    getch();
    menu();
}

// view record function
void view_record()
{
    FILE *fp;
    student s;
    system("cls");
    printf("\n\t----------------------------- ALL RECORDS -------------------------------\n");
    printf("\n\t\tS.No |  Name of Student    |   Mobile No   |  Roll No | Course");
    printf("\n\t-------------------------------------------------------------------------");
    // open the file
    fp = fopen("student_data.txt", "rb+");
    // checking the file is exits or not
    if (fp == NULL)
    {
        printf("\n\t\tCan't open this file!!!");
        exit(1);
    }
    int i = 1;
    // reterive the data from the file one by one
    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        printf("\n\t\t%-8d%-23s%-15s%-10d%-12s", i, s.name, s.mobile, s.roll, s.course);
        i++;
    }
    // close the file
    fclose(fp);
    printf("\n\n\t\tPress any key to Continue...");
    getch(); // hold the screen
    menu();
}

// search record function
void search_record()
{
    system("cls");
    FILE *fp;
    student s;
    char sname[20];
    printf("\n\t---------------------------- SEARCH RECORDS -----------------------------\n");
    printf("\n\t\tEnter name of Student:- ");
    fflush(stdin);
    scanf("%[^\n]", sname);
    // open the file
    fp = fopen("student_data.txt", "rb+");
    // checking the file is exits or not
    if (fp == NULL)
    {
        printf("\n\t\tCan't open this file!!!");
        exit(1);
    }
    printf("\n\t\tS.No |  Name of Student    |   Mobile No   |  Roll No | Course");
    printf("\n\t-------------------------------------------------------------------------");
    int i = 1, found = 0;
    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        if (strcmp(sname, s.name) == 0)
        {
            found += 1;
            printf("\n\t\t%-8d%-23s%-15s%-10d%-12s", i, s.name, s.mobile, s.roll, s.course);
            i++;
            break;
        }
        else
        {
            found = 0;
        }
    }
    if (found == 0)
    {
        printf("\n\t\tNo Record Found!!!");
    }
    // close the file
    fclose(fp);
    printf("\n\n\t\tPress any key to Continue...");
    getch(); // hold the screen
    menu();
}

// update record function
void update_record()
{
    FILE *fp;
    student s;
    char sname[20];
    system("cls");
    printf("\n\t---------------------------- UPDATE RECORDS -----------------------------\n");
    printf("\n\t\tEnter name of Student:- ");
    fflush(stdin);
    scanf("%[^\n]", sname);
    // open the file
    fp = fopen("student_data.txt", "rb+");
    // checking the file is exits or not
    if (fp == NULL)
    {
        printf("\n\t\tCan't open this file!!!");
        exit(1);
    }
    rewind(fp);
    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        if (strcmp(sname, s.name) == 0)
        {
            // getting data from user to update the record
            fflush(stdin);
            printf("\n\t\tEnter Roll:- ");
            scanf("%d", &s.roll);
            fflush(stdin);
            printf("\t\tEnter Name:- ");
            scanf("%[^\n]", s.name);
            fflush(stdin);
            printf("\t\tEnter Mobile:- ");
            scanf("%[^\n]", s.mobile);
            fflush(stdin);
            printf("\t\tEnter Course:- ");
            scanf("%[^\n]", s.course);
            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);
            break;
        }
    }
    // close the file
    fclose(fp);
    printf("\n\n\t\tPress any key to Continue...");
    getch(); // hold the screen
    menu();
}
int main()
{
    menu();
    return 0;
}