CC	= gcc
CFLAGS	= -Wall -Wextra -g
SRCS	= src/main.c src/student.c src/bst.c
OUT	= student_mgmt

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(OUT)

run: all
	./$(OUT)

clean:
	del /f student_mgmt.exe 2>nul || true