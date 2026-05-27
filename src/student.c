#include <stdio.h>
#include <string.h>
#include "student.h"
#include "utils.h"

int student_compare(const char *a, const char *b) {
    return strcmp(a, b);
}

void student_print(Student *s) {
    printf("MSSV     : %s\n", s->mssv);
    printf("Ten      : %s\n", s->name);
    printf("Nganh    : %s\n", s->major);
    printf("Ngay sinh: %02d/%02d/%04d (%d tuoi)\n", s->dob.day, s->dob.month, s->dob.year, tinh_tuoi(s->dob));
    printf("GPA      : %.2f\n", s->gpa);
}