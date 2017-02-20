CC=gcc
CFLAGS=-I -lm.
DEPS = img_pro.h my_header.h
OBJ = img_pro.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tilt_shiftB: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
