#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
    char mssv[12];
    char name [50];
    char major[30];
    float gpa;
} Student;

int student_compare(const char *a, const char *b);
void student_print(Student *s);

#endif