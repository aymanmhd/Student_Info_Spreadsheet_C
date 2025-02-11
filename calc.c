#ifndef MY_CALC_C
#define MY_CALC_C

#include "spreadsheet.c"

// Function to display the menu
void display_menu()
{
    system("clear");
    printf("Spreadsheet Menu:\n");
    printf("1. Display Spreadsheet\n");
    printf("2. Display Histogram\n");
    printf("3. Sort Students\n");
    printf("4. Update Last Name\n");
    printf("5. Update Exam Grade\n");
    printf("6. Adjust Grade Mapping\n");
    printf("7. Remove Student\n");
    printf("8. Exit\n");
}

// Function to display the spreadsheet
void display_spreadsheet(struct student *students, int student_count)
{
    printf("ID\tLast Name\tFirst Name\tA1\tA2\tA3\tMid\tExam\tTotal\tGrade\n");
    printf("--------------------------------------------------------------------------------------------------------\n"); // Separation line

    for (int i = 0; i < student_count; i++)
    {
        struct student s = students[i];
        printf("%d\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%d\t%d\t%c\n",
               s.id, s.last_name, s.first_name, s.a1, s.a2, s.a3, s.midterm, s.final_exam, s.total, s.grade);
    }
    char proceed;
    printf("\nPress 'c' or 'C' to continue ");
    do
    {
        scanf("%c", &proceed);
    } while ((proceed != 'c') && (proceed != 'C'));
    getchar();
}

// Function to calculate totals and grades
void calculate_totals(struct student *students, int student_count)
{
    for (int i = 0; i < student_count; i++)
    {
        struct student *s = &students[i];
        s->total = (s->a1 + s->a2 + s->a3) * 0.25 + s->midterm * 0.25 + s->final_exam * 0.5;
        s->grade = calculate_grade(s->total);
    }
}

// Function to calculate the letter grade
char calculate_grade(int total)
{
    if (total >= BASELINE_A)
        return 'A';
    if (total >= BASELINE_B)
        return 'B';
    if (total >= BASELINE_C)
        return 'C';
    if (total >= BASELINE_D)
        return 'D';
    return 'F';
}

// Function to display the histogram
void display_histogram(struct student *students, int student_count)
{
    int grades[5] = {0}; // A, B, C, D, F

    for (int i = 0; i < student_count; i++)
    {
        switch (students[i].grade)
        {
        case 'A':
            grades[0]++;
            break;
        case 'B':
            grades[1]++;
            break;
        case 'C':
            grades[2]++;
            break;
        case 'D':
            grades[3]++;
            break;
        case 'F':
            grades[4]++;
            break;
        }
    }

    printf("A: %d\nB: %d\nC: %d\nD: %d\nF: %d\n", grades[0], grades[1], grades[2], grades[3], grades[4]);
    char proceed;
    printf("\nPress 'c' or 'C' to continue ");
    do
    {
        scanf("%c", &proceed);
    } while ((proceed != 'c') && (proceed != 'C'));
    getchar();

}

// Function to update the last name of a student
void update_last_name(struct student *students, int student_count)
{

    display_spreadsheet(students, student_count);
    int id;
    printf("\nEnter student ID: ");
    scanf("%d", &id);

    for (int i = 0; i < student_count; i++)
    {
        if (students[i].id == id)
        {
            printf("\nEnter new last name: ");
            scanf("%s", students[i].last_name);
            printf("Last name updated!\n");
            return;
        }
    }

    printf("Student not found!\n");
}

// Function to update the exam grade of a student
void update_exam_grade(struct student *students, int student_count)
{

    display_spreadsheet(students, student_count);
    int id, new_grade;
    printf("Enter student ID: ");
    scanf("%d", &id);

    for (int i = 0; i < student_count; i++)
    {
        if (students[i].id == id)
        {
            printf("Enter new exam grade: ");
            scanf("%d", &new_grade);
            students[i].final_exam = new_grade;
            calculate_totals(students, student_count); // Recalculate totals and grades
            printf("Exam grade updated!\n");
            return;
        }
    }

    printf("Student not found!\n");
}

// Function to remove a student
void remove_student(struct student *students, int *student_count)
{

    display_spreadsheet(students, student_count);
    int id;
    printf("Enter student ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < *student_count; i++)
    {
        if (students[i].id == id)
        {
            for (int j = i; j < *student_count - 1; j++)
            {
                students[j] = students[j + 1];
            }
            (*student_count)--;
            printf("Student removed!\n");
            return;
        }
    }

    printf("Student not found!\n");
}

#endif
