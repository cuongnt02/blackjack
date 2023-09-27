OBJS = main.cpp texture.cpp game.cpp cards.cpp player.cpp

CC = g++

INCLUDE_PATHS = -IE:/Go/mingw_dev_lib/include/SDL2

LIBRARY_PATHS = -LE:/Go/mingw_dev_lib/lib

COMPILER_FLAGS = -w -W

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

OBJ_NAME = blackjack

all:
	make build
	make run

build:
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

run:
	./$(OBJ_NAME)

