SRV		=	server.c

SRV		:=	$(addprefix src/, $(SRV))

SRV_OBJ		=	$(SRV:.c=.o)

CLT		=	client.c

CLT		:=	$(addprefix src/, $(CLT))

CLT_OBJ		=	$(CLT:.c=.o)

INCLUDE	=	-I./include/

LIB		=	-L./lib -lft

FLAG	=	-Wall -Wextra -Werror -g3

SRV_NAME	=	server

CLT_NAME	=	client

DEFAULT	=	\033[0m
GREEN	=	\033[0;32m
RED		=	\033[0;31m
YELLOW	=	\033[0;33m
CYAN	=	\033[0;36m
BOLD	=	\033[1m

%.o: %.c
	@echo "$(CYAN)Compiling:$(DEFAULT) $<"
	@gcc $(FLAG) $(INCLUDE) -c $< -o $@

all:	lib $(SRV_NAME) $(CLT_NAME)

$(SRV_NAME):	$(SRV_OBJ)
	@echo "$(YELLOW)$(BOLD)Creating:$(DEFAULT) ./$(SRV_NAME)"
	@gcc -o $(SRV_NAME) $(SRV_OBJ) $(LIB) $(INCLUDE) $(FLAG)
	@echo "$(GREEN)$(BOLD)Done$(DEFAULT)"

$(CLT_NAME):	$(CLT_OBJ)
	@echo "$(YELLOW)$(BOLD)Creating:$(DEFAULT) ./$(CLT_NAME)"
	@gcc -o $(CLT_NAME) $(CLT_OBJ) $(LIB) $(INCLUDE) $(FLAG)
	@echo "$(GREEN)$(BOLD)Done$(DEFAULT)"

lib:
	@if [ ! -e ./lib/libft.a ]; then \
		echo "$(YELLOW)$(BOLD)Creating:$(DEFAULT) libft";	\
		make -C lib/ --quiet;	\
		echo "$(GREEN)$(BOLD)Done$(DEFAULT)";	\
	fi

clean:
	@echo "$(RED)Cleaning:$(DEFAULT) $(SRV_OBJ)"
	@make clean -C lib/ --quiet
	@rm -f $(SRV_OBJ)
	@rm -f $(CLT_OBJ)
	@echo "$(GREEN)Done:$(DEFAULT) $(SRV_OBJ)"

fclean:	clean
	@make fclean -C lib --quiet
	@rm -f $(SRV_NAME)
	@rm -f $(CLT_NAME)
	@rm -f code

re:	fclean all

.PHONY: all lib clean fclean re
