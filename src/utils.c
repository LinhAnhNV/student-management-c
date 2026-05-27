#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void xoa_ky_tu_xuong_dong(char *s) {
    size_t len =strlen(s);
    if (len > 0 && s[len - 1] == '\n') s[len - 1] = '\0';
}
void nhap_chuoi(const char *msg, char *out, size_t max_len) {
    char buffer[BUFFER_SIZE];
    while(1) {
        printf("%s", msg);
        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Loi nhap. Vui long nhap lai.\n");
        }
        xoa_ky_tu_xuong_dong(buffer);
        if(strlen(buffer) == 0) {
            printf("Khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }
        if(strlen(buffer) > max_len) {
            printf("Chuoi qua dai, toi da %lld ky tu. Vui long nhap  lai.\n", max_len);
            continue;
        }
        strcpy(out, buffer);
        break;
    }
}
int nhap_so_nguyen(const char *msg, int min, int max) {
    char buffer[BUFFER_SIZE], extra;
    int x;
    while(1) {
        printf("%s", msg);
        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Loi nhap. Vui long nhap lai.\n");
            continue;
        }
        xoa_ky_tu_xuong_dong(buffer);
        if(sscanf(buffer, "%d %c", &x, &extra) != 1) {
            printf("Vui long nhap mot so nguyen.\n");
            continue;
        }
        if(x < min || x > max) {
            printf("Vui long nhap so nguyen tu %d den %d.\n", min, max);
            continue;
        }
        return x;
    }
}
float nhap_so_thuc(const char *msg, float min, float max) {
    char buffer[BUFFER_SIZE], extra;
    float x;
    while(1) {
        printf("%s", msg);
        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Loi nhap. Vui long nhap lai.\n");
            continue;
        }
        xoa_ky_tu_xuong_dong(buffer);
        if(sscanf(buffer, "%f %c", &x, &extra) != 1) {
            printf("Vui long nhap mot so thuc.\n");
            continue;
        }
        if(x < min || x > max) {
            printf("Vui long nhap so thuc tu %.2f den %.2f.\n", min, max);
            continue;
        }
        return x;
    }
}
int namNhuan(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int ngayTrongThang(int month, int year) {
    if(month == 2) return namNhuan(year) ? 29 : 28;
    else if(month == 4 || month == 6 || month == 9 || month == 11) return 30;
    else return 31;
}

