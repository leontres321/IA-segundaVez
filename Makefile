CC =g++
FLAGS =-Wall

FILES =main.o funciones.o SA.o
OUTPUTS =OUT PROBLEM.RES PROBLEM.SOL PROBLEM.PEN
BINARY =out

all: $(BINARY)

out: $(FILES)
	$(CC) $(FLAGS) -o $(BINARY) $(FILES)

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp

funciones.o: funciones.cpp
	$(CC) $(FLAGS) -c funciones.cpp

SA.o: SA.cpp
	$(CC) $(FLAGS) -c SA.cpp

clean:
	rm $(BINARY) $(FILES)

delete:
	rm -rf $(OUTPUTS)

run:
	@./$(BINARY) $(CASE) $(DEBUG)
