#ifndef MY_SPREADSHEET_H
#define MY_SPREADSHEET_H

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50

#define BASELINE_A 80
#define BASELINE_B 70
#define BASELINE_C 60
#define BASELINE_D 50
#define BASELINE_F 50





// Structure to hold student data
struct student
{
    int id;
    char last_name[MAX_NAME_LEN];
    char first_name[MAX_NAME_LEN];
    int a1, a2, a3;
    int midterm;
    int final_exam;
    int total;
    char grade;
};


// Function prototypes
void display_menu();
void load_data(struct student *students, int *student_count);
void display_spreadsheet(struct student *students, int student_count);
void display_histogram(struct student *students, int student_count);
void sort_students(struct student *students, int student_count);
void update_last_name(struct student *students, int student_count);
void update_exam_grade(struct student *students, int student_count);
void adjust_grade_mapping();
void remove_student(struct student *students, int *student_count);
char calculate_grade(int total);
void calculate_totals(struct student *students, int student_count);



#endif /* MY_SPREADSHEET_H */