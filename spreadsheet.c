/*
Name: Ayman Mehdi, 40262543
COMP348 A1
October 11th, 2024
*/


#ifndef MY_MAIN_C
#define MY_MAIN_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "spreadsheet.h"
#include "ordering.c"
#include "data.c"
#include "calc.c"


// Main function
int main()
{
    struct student students[MAX_STUDENTS];
    int student_count = 0;
    int option;

    // Load the data from the file
    load_data(students, &student_count);

    // Menu loop
    do
    {
        display_menu();
        printf("Enter an option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            display_spreadsheet(students, student_count);
            break;
        case 2:
            display_histogram(students, student_count);
            break;
        case 3:
            sort_students(students, student_count);
            break;
        case 4:
            update_last_name(students, student_count);
            break;
        case 5:
            update_exam_grade(students, student_count);
            break;
        case 6:
            adjust_grade_mapping(students, student_count);
            break;
        case 7:
            remove_student(students, &student_count);
            break;
        case 8:
            printf("Goodbye and thanks for using our spreadsheet app!\n");
            break;
        default:
            printf("Invalid option, please try again.\n");
            break;
        }
    } while (option != 8);

    return 0;
}

#endif

