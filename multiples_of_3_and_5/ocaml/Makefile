OBJS = main.ml
OBJ_NAME = main.exe

all: $(OBJS)
	dune build

run: _build/default/$(OBJ_NAME)
	dune exec ./$(OBJ_NAME)
