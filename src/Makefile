OBJS = *.cpp

CC = g++ -std=c++11

COMPILER_FLAGS = -Wall -Wextra -g

LINKER_FLAGS = -lSDL2

OBJ_NAME = Life

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

.PHONY: clean
clean:
	rm Life .*.*.swp
