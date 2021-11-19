CC = gcc
CFLAGS = -I.
DEPS = hysteresis.h test.h
OBJ = main.o hysteresis.o test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hysteresis: $(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS) -ggdb