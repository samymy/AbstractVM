NAME = AbstractVM

SRC_DIR = src

SRC_NAME =	OperandFactory.cpp \
			Operands.cpp \
			Operators.cpp \
			Instruction.cpp \
			Lexer.cpp \
			Parser.cpp \
			VirtualMachine.cpp \
			VMException.cpp \
			main.cpp

SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAME))

OBJ = $(SRC:.cpp=.o)

INC = include

FLAGS = -Wall -Wextra -Werror -std=c++11

all: $(NAME)

.cpp.o:
	@g++ $(FLAGS) -I$(INC) -c $<
	@mv $(addsuffix .o, $(notdir $(basename $<))) $(SRC_DIR)

$(NAME): $(OBJ)
	@g++ $(FLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
