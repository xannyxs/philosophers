# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/01 14:31:21 by xvoorvaa      #+#    #+#                  #
#    Updated: 2022/04/12 21:02:22 by xvoorvaa      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	philo
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
OBJ_DIR			=	OBJ
SRC_DIR			=	SRC
INC_DIR			=	INC

SRCS			=	$(SRC_DIR)/philo.c \
					$(SRC_DIR)/get_time.c \
					$(SRC_DIR)/create_mutex.c \
					$(SRC_DIR)/start_thread.c \
					$(SRC_DIR)/utils/ft_atoi.c \
					$(SRC_DIR)/utils/print_wrap.c \
					$(SRC_DIR)/utils/is_philo_dying.c \
					$(SRC_DIR)/utils/print_fork_or_eat.c \
					$(SRC_DIR)/utils/ft_free_array.c \
					$(SRC_DIR)/actions/start_eat.c \
					$(SRC_DIR)/actions/start_think.c \
					$(SRC_DIR)/actions/start_sleep.c \
					$(SRC_DIR)/actions/start_death.c \

OBJS			=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
HEADERS			=	INC/philo.h

ifdef DEBUG
	CFLAGS += -g3 -fsanitize=address
else ifdef THREAD
	CFLAGS += -g3 -fsanitize=thread
else
	CFLAGS += -O2
endif

GREEN			=	\033[1;32m
BLUE			=	\033[1;36m
RED				=	\033[0;31m
NC				=	\033[0m # No Color

START			= "$(BLUE)---\nStarting...!\n---$(NC)"
MESSAGE			= "$(BLUE)---\nCompiling done! Run ./$(NAME)\n---$(NC)"
COMP_MESSAGE	= "$(GREEN)Building C object... $(NC)%-33.33s\r\n"
REM_MESSAGE		= "$(RED)Removing files...$(NC)"

all:	$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

$(OBJ_DIR):
	mkdir $@

$(NAME): $(OBJS)
	@echo $(START)
	@printf $(COMP_MESSAGE) $(SRCS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(MESSAGE)

clean:
	@echo "\n"
	@rm -f $(OBJS)
	@printf $(REM_MESSAGE)
	@echo "\n"


fclean:		clean
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM

re:			fclean all

.PHONY:		all clean fclean re
