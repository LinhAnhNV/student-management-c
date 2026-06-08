#include <stdio.h>
#include <string.h>
#include "student.h"
#include "utils.h"

float tinhGPA(float gk, float tl, float ck) {
    return gk * 0.2f + tl * 0.2f + ck * 0.6f;
}

int student_compare(const char *a, const char *b) {
    return strcmp(a, b);
}

void student_print(Student *s) {
    printf("MSSV     : %s\n", s->mssv);
    printf("Ten      : %s\n", s->name);
    printf("Nganh    : %s\n", s->major);
    printf("Ngay sinh: %02d/%02d/%04d (%d tuoi)\n", s->dob.day, s->dob.month, s->dob.year, tinh_tuoi(s->dob));
    printf("Diem GK  : %.2f (20%%)\n", s->gk);
    printf("Diem TL  : %.2f (20%%)\n", s->tl);
    printf("Diem CK  : %.2f (60%%)\n", s->ck);
    printf("GPA      : %.2f\n", s->gpa);
}