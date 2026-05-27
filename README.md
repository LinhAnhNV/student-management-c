# Student Management System

Chương trình quản lý sinh viên viết bằng C, dùng Binary Search Tree (BST) để lưu và tra cứu dữ liệu theo MSSV.

> A student management program written in C. Uses a Binary Search Tree keyed on student ID for storage and lookup.

---

## Tính năng / Features

- Thêm sinh viên / Add student
- Tìm theo MSSV / Search by student ID
- Xóa sinh viên / Delete student
- In danh sách đã sắp xếp / Print sorted list (in-order traversal)

---

## Cấu trúc / Structure

```
student-management-c/
├── src/
│   ├── main.c        # Menu chính / Main menu
│   ├── bst.c         # Insert, search, delete, inorder, free
│   ├── bst.h
│   ├── student.c     # In thông tin sinh viên / Print student info
│   └── student.h     # Định nghĩa struct Student
├── .gitignore
├── Makefile
└── README.md
```

---

## Yêu cầu / Requirements

- GCC
- Windows: [MinGW](https://www.mingw-w64.org/) hoặc [MSYS2](https://www.msys2.org/)
- Linux/macOS: GCC có sẵn hoặc `sudo apt install gcc`

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

**Dọn file build / Clean:**
```bash
mingw32-make clean   # Windows
make clean           # Linux/macOS
```

---

## Về BST / About the BST

Cây được sắp xếp theo MSSV (string). Duyệt in-order cho ra danh sách đã sort.

The tree is ordered by student ID string. An in-order traversal produces a sorted list.

| Thao tác / Operation | Độ phức tạp / Complexity |
|----------------------|--------------------------|
| Insert               | O(h)                     |
| Search               | O(h)                     |
| Delete               | O(h)                     |
| In-order traversal   | O(n)                     |

`h` = chiều cao cây / tree height — `n` = số node / number of nodes

---

## Demo

*(Screenshot sẽ được cập nhật sau / Screenshot coming soon)*

---

## Tác giả / Author

**Nguyễn Văn Linh Anh**  
Sinh viên CNTT — Trường ĐH Công Thương TP.HCM (HUIT)  
IT Student — Ho Chi Minh City University of Industry and Trade 