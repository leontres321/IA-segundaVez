CC =g++
FLAGS =-Wall

FILES =main.o funciones.o
OUTPUTS =OUT
BINARY =out

all: $(BINARY)

out: $(FILES)
	$(CC) $(FLAGS) -o $(BINARY) $(FILES)

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp

funciones.o: funciones.cpp
	$(CC) $(FLAGS) -c funciones.cpp

clean:
	rm $(BINARY) $(FILES)

delete:
	rm -rf $(OUTPUTS)

run:
	@./$(BINARY) $(CASE)

test:
	@timeout -s 2 5m ./$(BINARY) $(CASE)
