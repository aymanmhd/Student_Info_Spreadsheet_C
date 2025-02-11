#ifndef MY_ORDERING_C
#define MY_ORDERING_C

#include "spreadsheet.c"

// Function to adjust grade mapping (curve)
void adjust_grade_mapping(struct student *students, int student_count)
{
    // Display the original baselines
    printf("Current grade baselines:\n");
    printf("A: %d and above\n", BASELINE_A);
    printf("B: %d and above\n", BASELINE_B);
    printf("C: %d and above\n", BASELINE_C);
    printf("D: %d and above\n", BASELINE_D);
    printf("F: below %d\n\n", BASELINE_D);

    // Ask the user for new baselines
    printf("Enter new baseline for an A: ");
    scanf("%d", BASELINE_A);
    printf("Enter new baseline for a B: ");
    scanf("%d", BASELINE_B);
    printf("Enter new baseline for a C: ");
    scanf("%d", BASELINE_C);
    printf("Enter new baseline for a D: ");
    scanf("%d", BASELINE_D);

    // Update the grades of all students based on the new baselines
    for (int i = 0; i < student_count; i++) {
        if (students[i].total >= BASELINE_A) {
            students[i].grade = 'A';
        } else if (students[i].total >= BASELINE_B) {
            students[i].grade = 'B';
        } else if (students[i].total >= BASELINE_C) {
            students[i].grade = 'C';
        } else if (students[i].total >= BASELINE_D) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }
    }
}

// Comparison function for sorting by student ID (ascending)
int compare_by_id(const void *a, const void *b) {
    struct student *student_a = (struct student *)a;
    struct student *student_b = (struct student *)b;
    return (student_a->id - student_b->id);
}

// Comparison function for sorting by last name (alphabetical)
int compare_by_last_name(const void *a, const void *b) {
    struct student *student_a = (struct student *)a;
    struct student *student_b = (struct student *)b;
    return strcmp(student_a->last_name, student_b->last_name);
}

// Comparison function for sorting by final exam grade (descending)
int compare_by_exam_grade_desc(const void *a, const void *b) {
    struct student *student_a = (struct student *)a;
    struct student *student_b = (struct student *)b;
    return (student_b->final_exam - student_a->final_exam);
}

// Comparison function for sorting by total grade (descending)
int compare_by_total_grade_desc(const void *a, const void *b) {
    struct student *student_a = (struct student *)a;
    struct student *student_b = (struct student *)b;
    return (student_b->total - student_a->total);
}

// Function to sort students by user-specified option
void sort_students(struct student *students, int student_count)
{
    int sort_option;
    
    // Prompt the user to choose the sorting option
    printf("Column Options:\n");
    printf("1. Sort by ID (ascending)\n");
    printf("2. Sort by Last Name (alphabetical)\n");
    printf("3. Sort by Final Exam Grade\n");
    printf("4. Sort by Total Grade\n");
    printf("Sort Column: ");
    scanf("%d", &sort_option);

    // Perform sorting based on user's choice
    switch (sort_option) {
        case 1:
            qsort(students, student_count, sizeof(struct student), compare_by_id);
            printf("Students sorted by ID (ascending).\n");
            break;
        case 2:
            qsort(students, student_count, sizeof(struct student), compare_by_last_name);
            printf("Students sorted by Last Name.\n");
            break;
        case 3:
            qsort(students, student_count, sizeof(struct student), compare_by_exam_grade_desc);
            printf("Students sorted by Final Exam Grade.\n");
            break;
        case 4:
            qsort(students, student_count, sizeof(struct student), compare_by_total_grade_desc);
            printf("Students sorted by Total Grade.\n");
            break;
        default:
            printf("Invalid option, no sorting applied.\n");
            break;
    }

    char proceed;
    printf("\nPress 'c' or 'C' to continue ");
    do {
        scanf(" %c", &proceed);
    } while ((proceed != 'c') && (proceed != 'C'));
    getchar(); // Pause
}

#endif