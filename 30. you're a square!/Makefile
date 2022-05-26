OBJS =  main.cpp
OBJ_NAME = main

CC = g++
COMPILER_FLAGS = -w -g
LINKER_FLAGS = 

$(OBJ_NAME): $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

run: $(OBJ_NAME)
	./$(OBJ_NAME)

