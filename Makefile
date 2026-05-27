CC	= gcc
CFLAGS	= -Wall -Wextra -g
SRC = src/main.c src/student.c src/bst.c src/utils.c
OBJ = main.o student.o bst.o utils.o
OUT	= student_mgmt

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	del /f student_mgmt.exe 2>nul || true

utils.o: src/utils.c
	$(CC) $(CFLAGS) -c src/utils.c -o utils.o