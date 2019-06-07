CC= gcc
CFLAGS=-Wall -Wextra -pedantic

OBJ= main.o hachage.o dictionnaire.o tests.o

EXEC=exec

$(EXEC) : $(OBJ)
	$(CC) -g $^ -o $@
	echo "executer avec ./exec"

%.o : %.c
	$(CC) -g -c $< $(CFLAGS)

clean :
	rm -rf dep *.o vgcore.*
