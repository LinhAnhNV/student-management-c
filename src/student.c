#include <stdio.h>
#include <string.h>
#include "student.h"

int student_compare(const char *a, const char *b) {
    return strcmp(a, b);
}

void student_print(Student *s) {
    printf("MSSV     : %s\n", s->mssv);
    printf("Ten      : %s\n", s->name);
    printf("Nganh    : %s\n", s->major);
    printf("Ngay sinh: %02d/%02d/%04d\n", s->dob.day, s->dob.month, s->dob.year);
    printf("GPA      : %.2f\n", s->gpa);
}