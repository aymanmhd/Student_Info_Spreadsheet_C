#ifndef MY_DATA_C
#define MY_DATA_C

#include "spreadsheet.c"


#define FILENAME "students.txt"

// Function to load student data from a file
void load_data(struct student *students, int *student_count)
{
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        struct student s;
        sscanf(buffer, "%d|%[^|]|%[^|]|%d|%d|%d|%d|%d",
               &s.id, s.last_name, s.first_name, &s.a1, &s.a2, &s.a3, &s.midterm, &s.final_exam);
        students[*student_count] = s;
        (*student_count)++;
    }

    fclose(file);

    // Calculate total scores and grades
    calculate_totals(students, *student_count);
}

#endif
