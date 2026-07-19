#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Student {
    int rollNo;
    char name[50];
    float marks1, marks2, marks3;
    float total, average;
    char grade;
};

struct Student students[MAX];
int count = 0;

// Calculate total, average and grade
void calculateResult(struct Student *s) {
    s->total = s->marks1 + s->marks2 + s->marks3;
    s->average = s->total / 3;

    if (s->average >= 90)
        s->grade = 'A';
    else if (s->average >= 75)
        s->grade = 'B';
    else if (s->average >= 60)
        s->grade = 'C';
    else if (s->average >= 40)
        s->grade = 'D';
    else
        s->grade = 'F';
}

// Add student
void addStudent() {
    if (count >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[count].rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Marks of Subject 1: ");
    scanf("%f", &students[count].marks1);

    printf("Enter Marks of Subject 2: ");
    scanf("%f", &students[count].marks2);

    printf("Enter Marks of Subject 3: ");
    scanf("%f", &students[count].marks3);

    calculateResult(&students[count]);

    count++;

    printf("\nStudent Added Successfully.\n");
}

// Display students
void displayStudents() {

    if (count == 0) {
        printf("\nNo Records Found.\n");
        return;
    }

    printf("\n------------------------------------------------------------------------------------------\n");
    printf("Roll\tName\t\tSub1\tSub2\tSub3\tTotal\tAverage\tGrade\n");
    printf("------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%-12s\t%.0f\t%.0f\t%.0f\t%.0f\t%.2f\t%c\n",
               students[i].rollNo,
               students[i].name,
               students[i].marks1,
               students[i].marks2,
               students[i].marks3,
               students[i].total,
               students[i].average,
               students[i].grade);
    }
}

// Search student
void searchStudent() {

    int roll;

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("\nStudent Found\n");
            printf("Roll Number : %d\n", students[i].rollNo);
            printf("Name        : %s\n", students[i].name);
            printf("Total       : %.2f\n", students[i].total);
            printf("Average     : %.2f\n", students[i].average);
            printf("Grade       : %c\n", students[i].grade);
            return;
        }
    }

    printf("Student Not Found!\n");
}

// Save records to file
void saveToFile() {

    FILE *fp = fopen("students.txt", "w");

    if (fp == NULL) {
        printf("Unable to create file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp,
                "%d %s %.2f %.2f %.2f %.2f %.2f %c\n",
                students[i].rollNo,
                students[i].name,
                students[i].marks1,
                students[i].marks2,
                students[i].marks3,
                students[i].total,
                students[i].average,
                students[i].grade);
    }

    fclose(fp);

    printf("Data Saved Successfully to students.txt\n");
}

int main() {

    int choice;

    do {

        printf("\n========== Student Result Management System ==========\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Save Records to File\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                saveToFile();
                break;

            case 5:
                printf("Thank You!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 5);

    return 0;
}