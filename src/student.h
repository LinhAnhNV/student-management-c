#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct Student {
    char mssv[12];
    char name [50];
    char major[30];
    Date dob;
    float gk;
    float tl;
    float ck;
    float gpa;
} Student;

float tinhGPA(float gk, float tl, float ck);
int student_compare(const char *a, const char *b);
void student_print(Student *s);

#endif