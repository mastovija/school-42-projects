NAME		= so_long
INC			= inc
INC			= -I include
LIBFT		= libft
PRINTF		= printf
MINILIBX	= mlx
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf
LINKS	    = -L$(LIBFT) -L$(PRINTF) -L$(MINILIBX) -lmlx -lX11 -lXext -lm
SRC_DIR		= 	src/
MAND_FILES	=	so_long validate_map check_limits create_window fill_window move_functions validate_path utils image_loader
SRC_FILES	=	$(addprefix $(SRC_DIR), $(MAND_FILES))
SRC 		= 	$(addsuffix .c, $(SRC_FILES))
OBJ 		= 	$(addsuffix .o, $(SRC_FILES))


all:		minilibx $(NAME)

minilibx:
			@make -s -C $(MINILIBX)

$(NAME):	$(OBJ)
			@make -s -C $(LIBFT)
			@make -s -C $(PRINTF)
			$(CC) $(CFLAGS) $(OBJ) $(INC) $(LIBFT)/libft.a $(PRINTF)/libftprintf.a $(LINKS) -o $(NAME)

clean:
			@make clean -C $(LIBFT)
			@make clean -C $(PRINTF)
			$(RM) $(OBJ)
			$(RM) $(OBJB)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(BNAME)
			@$(RM) $(LIBFT)/libft.a
			@$(RM) $(PRINTF)/libftprintf.a

re:			fclean all

.PHONY:		all clean fclean re 
