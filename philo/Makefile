# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 11:10:23 by lflandri          #+#    #+#              #
#    Updated: 2022/11/28 10:40:59 by lflandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		= philo

MAKEFLAGS	= --no-print-directory

SRC 		=	main.c\
				ft_atoiwo.c\
				free_and_cie.c\
				parser.c\
				ft_calloc.c\
				start_routine.c\
				ft_gettime.c\
				ft_print_activity.c\
				ft_p_gosleep.c\
				ft_p_goeat.c\
				ft_p_gothink.c\
				ft_p_gothink_untils.c\
				ft_i_am_alive.c\
				ft_check_nb_eat.c

#couleur
BLACK		=\\e[0;30m
GREY		=\\e[1;30m
BLACKRED	=\\e[0;31m
PINK		=\\e[1;31m
BLACKGREEN	=\\e[0;32m
WHITEGREEN	=\\e[1;32m
ORANGE		=\\e[0;33m
YELLOW		=\\e[1;33m
BLACKBLUE	=\\e[0;34m
WHITEBLUE	=\\e[1;34m
BLACKPURPLE	=\\e[0;35m
WHITEPURPLE	=\\e[;1;35m
BLACKCYAN	=\\e[0;36m
WHITECYAN	=\\e[1;36m
WHITEGREY	=\\e[0;37m
WHITE		=\\e[1;37m

NEUTRE		= \\e[0;m

all :		
			@echo -n "${BLACKCYAN}"
			@echo " .########..##.....##.####.##........#######...######...#######..########..##.....##.########.########...######. ";
			@echo " .##.....##.##.....##..##..##.......##.....##.##....##.##.....##.##.....##.##.....##.##.......##.....##.##....## ";
			@echo " .##.....##.##.....##..##..##.......##.....##.##.......##.....##.##.....##.##.....##.##.......##.....##.##...... ";
			@echo " .########..#########..##..##.......##.....##..######..##.....##.########..#########.######...########...######. ";
			@echo " .##........##.....##..##..##.......##.....##.......##.##.....##.##........##.....##.##.......##...##.........## ";
			@echo " .##........##.....##..##..##.......##.....##.##....##.##.....##.##........##.....##.##.......##....##..##....## ";
			@echo " .##........##.....##.####.########..#######...######...#######..##........##.....##.########.##.....##..######. ";

			@echo "${NEUTRE}"
			@make ${NAME}
			@echo "${WHITEGREEN}PROGRAMME \"${NAME}\" PRET POUR EXECUTION !${NEUTRE}"

${NAME}: ${NAMEL} ${SRC}
			@echo "${BLACKPURPLE}============== CRÉATION PHILOSOFERS ============${WHITE}" 
			gcc  -Wall -Wextra -Werror -pthread  -o ${NAME} ${SRC} ${NAMEL}
			@echo "${BLACKPURPLE}============ FIN CRÉATION PHILOSOFERS ==========${NEUTRE}" 

clean :
			@echo -n "${BLACKRED}"
			@echo "Nothing to supress"
			@echo -n "${NEUTRE}"

fclean :	#clean
			@echo -n "${BLACKRED}"
			rm -f ${NAME}
			@echo -n "${NEUTRE}"

bonus :
			@make BONUS=42

re :		fclean all

rebonus : fclean bonus

.PHONY : all clean fclean re bonus