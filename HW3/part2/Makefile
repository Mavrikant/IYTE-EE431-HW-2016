CC=gcc
CFLAGS=-g -lm
DEPS = img_pro.h my_header.h
OBJ = edgedetection.o img_pro.o main.o utility.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

color_edge: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
clean:
	rm -rf *.o color_edge
