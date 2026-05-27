#ifndef UTILS_H
#define UTILS_H
#include "student.h"

#define BUFFER_SIZE 256

void xoa_ky_tu_xuong_dong(char *s);
void nhap_chuoi(const char *msg, char *out, size_t max_len);
int nhap_so_nguyen(const char *msg, int min, int max);
float nhap_so_thuc(const char *msg, float min, float max);
int namNhuan(int year);
int ngayTrongThang(int month, int year);
int tinh_tuoi(Date dob);

#endif