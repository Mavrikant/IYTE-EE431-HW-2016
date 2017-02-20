CC=gcc
CFLAGS=-I -lm.
DEPS = img_pro.h my_header.h
OBJ = gauss.o img_pro.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

rgbgauss: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
