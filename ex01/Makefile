# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/05 18:34:00 by macoulib          #+#    #+#              #
#    Updated: 2026/02/06 17:19:08 by macoulib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = RPN
CX = c++
FX = -Wall -Wextra -Werror -std=c++98

SRC_DIR = src
SRCS =  main.cpp RPN.cpp
OBJ_DIR = obj
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)
	@echo "Compilation terminée !"

$(NAME): $(OBJS)
	@$(CX) $(FX) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CX) $(FX) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "Nettoyage complet terminé."

re: fclean all

.PHONY: all clean fclean re