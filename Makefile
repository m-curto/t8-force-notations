NAME		=	a.exe
CC			=	g++

CFLAGS		=	-Wall -Wextra -static
#  -mwindows
DFLAGS		=	-MMD -MP

SRC_PATH	=	src/
OBJ_PATH	=	.build/
INC_PATH	=	$(SRC_PATH)inc/
DEPS		=	$(OBJ:.o=.d)

LOC_LIB		=	-I$(INC_PATH)

SYS_LIB		=	-lgdi32
# -lX11 -lpthread -ldl -lm
# -lglfw

SRC			=	$(SRC_PATH)Actor.cpp \
				$(SRC_PATH)Bitmap.cpp \
				$(SRC_PATH)build.cpp \
				$(SRC_PATH)Button.cpp \
				$(SRC_PATH)ComboBox.cpp \
				$(SRC_PATH)main.cpp \
				$(SRC_PATH)ProgressBar.cpp \
				$(SRC_PATH)struct.cpp \
				$(SRC_PATH)utils.cpp \
				$(SRC_PATH)wm.cpp

OBJ			=	$(SRC:$(SRC_PATH)%.cpp=$(OBJ_PATH)%.o)

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp Makefile
	$(CC) $(CFLAGS) $(DFLAGS) $(LOC_LIB) -c $< -o $@

-include $(DEPS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(GLFW_LIB) $(SYS_LIB) -o $(NAME)

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re