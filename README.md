# Student Management System

Chương trình quản lý sinh viên viết bằng C — dùng Binary Search Tree (BST) làm cấu trúc lưu trữ chính, tra cứu theo MSSV.

Dự án này bắt đầu từ một bài tập nhỏ, dần mở rộng thành một hệ thống có đầy đủ validation, lưu file, và thống kê. Viết tay từng dòng, debug từng lỗi.

> A student management program in C using a Binary Search Tree keyed on student ID. Built incrementally — from scratch, by hand.

---

## Tính năng / Features

- Thêm / xóa / sửa sinh viên
- Tìm theo MSSV hoặc tên (hỗ trợ tìm gần đúng)
- In danh sách đã sắp xếp dạng bảng
- Lưu và tải dữ liệu từ file CSV
- Thống kê GPA — trung bình, giỏi / khá / TB / yếu
- Validation đầu vào — kiểm tra MSSV trùng, ngày hợp lệ, GPA trong khoảng 0–4

---

## Cấu trúc / Structure

```
student-management-c/
├── src/
│   ├── main.c        # Menu chính, xử lý input
│   ├── bst.c         # Insert, search, delete, update, inorder, save, load, thống kê
│   ├── bst.h
│   ├── student.c     # In thông tin sinh viên
│   ├── student.h     # Struct Student, Date
│   ├── utils.c       # Nhập chuỗi, số nguyên, số thực có validation
│   └── utils.h
├── .gitignore
├── Makefile
└── README.md
---

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

Cây được sắp xếp theo MSSV (string). Duyệt in-order cho ra danh sách đã sort tự động — không cần thêm bước sort riêng.

| Thao tác | Độ phức tạp |
|----------|-------------|
| Insert   | O(h)        |
| Search   | O(h)        |
| Delete   | O(h)        |
| Inorder  | O(n)        |

`h` = chiều cao cây — `n` = số node  
Worst case khi dữ liệu nhập theo thứ tự: `h = n`

---

## Tác giả / Author

**Nguyễn Văn Linh Anh**  
Sinh viên CNTT — ĐH Công Thương TP.HCM (HUIT)  
Củ Chi, TP.HCM · 2025