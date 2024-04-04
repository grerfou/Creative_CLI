

CC = gcc
EXEC = prog
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(EXEC)

%.o : %.c
	$(CC) -o $@ -c $<

$(EXEC) : $(OBJ)
	$(CC) -o $@ $^

run : $(EXEC)
	./prog

clean :
	rm -rf *.o
	rm -rf $(EXEC)
#	rm -r projet
#	rm -r project_processing

.PHONY : run clean
