#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dborysen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 16:40:13 by dborysen          #+#    #+#              #
#    Updated: 2018/01/11 16:40:16 by dborysen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

FT_PRINTF = ft_printf

SRCS =  lem_in.c finding_possible_ways.c finding_ribs.c finding_rooms.c  finding_shortest_way1.c finding_shortest_way2.c finding_shortest_way3.c finding_shortest_way4.c free_work1.c list_work.c read_data.c validation1.c output1.c validation2.c output2.c validation3.c

OBJECT = lem_in.o finding_possible_ways.o finding_ribs.o finding_rooms.o  finding_shortest_way1.o finding_shortest_way2.o finding_shortest_way3.o finding_shortest_way4.o free_work1.o list_work.o read_data.o validation1.o output1.o validation2.o output2.o validation3.o

INCLUDES = ft_printf/ft_printf.h 

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECT)
	@make -C $(FT_PRINTF)
	@gcc -Wall -Wextra -Werror -I lem_in.h $(SRCS) ft_printf/libftprintf.a -o ./$(NAME)

%.o: %.c
	gcc $(FLAGS) -I lem_in.h -c $< 

comp:
	@gcc  $(FLAGS) -I lem_in.h $(SRCS) -g ft_printf/libftprintf.a -o ./$(NAME)

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS) lem_in.h

clean:
	@rm -f $(OBJECT)
	@make clean -C $(FT_PRINTF)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(FT_PRINTF)

re: fclean all