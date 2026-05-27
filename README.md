# Student Management System

Chương trình quản lý sinh viên viết bằng C — dùng Binary Search Tree (BST) làm cấu trúc lưu trữ chính, tra cứu theo MSSV.

Bắt đầu từ một bài tập nhỏ, mở rộng dần qua từng tính năng. Viết tay từng dòng, debug từng lỗi — không dùng thư viện ngoài, không copy nguyên.

> A student management program in C using a Binary Search Tree keyed on student ID. Built feature by feature, line by line.

---

## Tính năng / Features

- Thêm / xóa (có xác nhận) / sửa sinh viên
- Tìm theo MSSV hoặc tên — hỗ trợ tìm gần đúng
- In danh sách dạng bảng, sort theo MSSV / GPA / tên / ngành
- Tính tuổi tự động từ ngày sinh
- Lưu và tải dữ liệu từ file CSV, backup tự động khi thoát
- Xuất báo cáo ra file
- Thống kê GPA — trung bình, giỏi / khá / TB / yếu
- Validation đầu vào — MSSV trùng, ngày hợp lệ theo tháng, GPA trong khoảng 0–4

---

## Cấu trúc / Structure

```
student-management-c/
├── src/
│   ├── main.c        # Menu chính, xử lý input
│   ├── bst.c         # Insert, search, delete, update, sort, save, load, thống kê, export
│   ├── bst.h
│   ├── student.c     # In thông tin sinh viên
│   ├── student.h     # Struct Student, Date
│   ├── utils.c       # Nhập chuỗi, số nguyên, số thực, tính tuổi — có validation
│   └── utils.h
├── .gitignore
├── Makefile
└── README.md

---

## Yêu cầu / Requirements

- GCC (>= 9)
- Windows: [MinGW](https://winlibs.com/)
- Linux/macOS: `sudo apt install gcc` hoặc có sẵn

---

## Build & Run

**Windows:**
```bash
mingw32-make
.\student_mgmt.exe
```

**Linux / macOS:**
```bash
make
./student_mgmt
```

**Dọn file build:**
```bash
mingw32-make clean   # Windows
make clean           # Linux/macOS
```

---

## Về BST / About the BST

Cây sắp xếp theo MSSV. Duyệt in-order ra danh sách đã sort — không cần bước sort riêng. Sort theo tiêu chí khác (GPA, tên, ngành) dùng `qsort` trên mảng tạm.

| Thao tác | Độ phức tạp |
|----------|-------------|
| Insert   | O(h)        |
| Search   | O(h)        |
| Delete   | O(h)        |
| Inorder  | O(n)        |

`h` = chiều cao cây — `n` = số node  
Worst case khi nhập theo thứ tự tăng dần: `h = n`

---

## Tác giả / Author

**Nguyễn Văn Linh Anh**  
Sinh viên CNTT — ĐH Công Thương TP.HCM (HUIT)  
Củ Chi, TP.HCM · 2025