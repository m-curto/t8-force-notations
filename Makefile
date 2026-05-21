NAME	= a.exe
SRC		= src\main.cpp src\utils.cpp src\wm.cpp
CC		= g++

FLAG_DEBUG	= -Wall -Wextra -static -lgdi32 -g3
FLAG		= -Wall -Wextra -static -lgdi32 -mwindows

FREEIMAGE	= -I"D:\libs\FreeImage\" -L"D:\libs\FreeImage\" -lFreeImage
INC			= -I".\src\inc"

all: $(NAME)

NAME: $(SRC)
	$(CC) $(SRC) -o $(NAME) $(FLAG) $(INC)

debug: $(SRC)
	$(CC) $(SRC) -o $(NAME) $(FLAG_DEBUG)