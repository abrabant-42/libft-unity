# /!\ WARNING /!\
# You should not edit the Makefile. The only configuration you need to do
# is editing the configuration file shipped with the tester.
# You have no option to choose your compiler because you need to use clang
# to get optimal results (compared to moulinette's ones). If you're on
# Mac, this is the default. On linux, just install clang (btw, I made this
# tester on linux).

#----------[ 1. PROJECT SETTINGS     ]----------#

#----------[ 2. UNITY SETTINGS     ]----------#

UNITY_ROOT			= unity/
UNITY_FLAGS			= UNITY_OUTPUT_COLOR

#----------[ 3. COMPILATION SETTINGS ]----------#

# Please use clang for optimal results. The moulinette uses clang.
CC					= clang
CFLAGS				= -Werror -Wextra -Wall -Wformat=0 -g
INC_DIRS			= -Isrc -I$(UNITY_ROOT)/src -Itest/tests -Itest -Isrc/utils

#----------[ 4. PATH CONFIGURATION   ]----------#

TESTS_PATH          = ./test/tests
OBJ_DIR             = ./.obj/
BIN_DIR				= ./bin/

VPATH               = $(UNITY_ROOT)/src \
					= ./src/utils		\
                    = ./test/test_runners \
                    = ./test/tests \

#----------[ 5. SOURCES              ]----------#

PART1				= ft_memset_test.c ft_bzero_test.c ft_memcpy_test.c		\
					ft_memccpy_test.c ft_memmove_test.c ft_memchr_test.c	\
					ft_memcmp_test.c  ft_strlcpy_test.c	ft_strlen_test.c	\
					ft_strlcat_test.c ft_strchr_test.c ft_strrchr_test.c	\
					ft_strncmp_test.c ft_strnstr_test.c ft_atoi_test.c		\
					ft_isalpha_test.c ft_isdigit_test.c ft_isalnum_test.c	\
					ft_isascii_test.c ft_isprint_test.c ft_toupper_test.c	\
					ft_tolower_test.c ft_calloc_test.c ft_strdup_test.c		\

PART2				= ft_substr_test.c ft_strjoin_test.c ft_strtrim_test.c	\
					ft_split_test.c ft_itoa_test.c ft_strmapi_test.c		\
					ft_putchar_fd_test.c ft_putstr_fd_test.c				\
					ft_putendl_fd_test.c ft_putnbr_fd_test.c				\

BONUS				= ft_lstnew_test.c ft_lstadd_front_test.c				\
					ft_lstsize_test.c ft_lstlast_test.c ft_lstdelone_test.c	\
					ft_lstclear_test.c ft_lstiter_test.c ft_lstmap_test.c	\
					ft_lstadd_back_test.c

UTILS				= report_signals.c

RUNNERS				= ft_substr_Runner.c ft_strlwr_Runner.c					\
					ft_strupr_Runner.c ft_strjoin_Runner.c					\
					ft_strinsrt_Runner.c ft_split_Runner.c					\
					ft_toupper_Runner.c ft_tolower_Runner.c					\
					ft_strtrim_Runner.c ft_strmapi_Runner.c					\
					ft_toutf8_Runner.c ft_strrev_Runner.c					\
					ft_strutf8_Runner.c ft_strchri_Runner.c					\
					ft_lltob_Runner.c ft_ulltob_Runner.c 					\
					ft_itoa_Runner.c ft_intlen_Runner.c						\
					ft_set_bit_count_Runner.c ft_atoi_Runner.c				\
					ft_calloc_Runner.c ft_bzero_Runner.c					\
					ft_isalnum_Runner.c	ft_isalpha_Runner.c					\
					ft_isdigit_Runner.c ft_isascii_Runner.c					\
					ft_isprint_Runner.c ft_isspace_Runner.c					\
					ft_memset_Runner.c ft_memcpy_Runner.c					\
					ft_memmove_Runner.c	ft_memcmp_Runner.c					\
					ft_memccpy_Runner.c	ft_memchr_Runner.c					\
					ft_strncmp_Runner.c	ft_strrchr_Runner.c					\
					ft_strchr_Runner.c ft_strnstr_Runner.c					\
					ft_strcasestr_Runner.c ft_strdup_Runner.c				\
					ft_strlcat_Runner.c	ft_strlcpy_Runner.c					\
					ft_putchar_fd_Runner.c ft_putstr_fd_Runner.c			\
					ft_putendl_fd_Runner.c ft_putnbr_fd_Runner.c			\
					ft_lstnew_Runner.c ft_lstadd_front_Runner.c				\
					ft_lstsize_Runner.c ft_lstlast_Runner.c					\
					ft_lstdelone_Runner.c ft_lstclear_Runner.c				\
					ft_lstiter_Runner.c ft_lstmap_Runner.c					\
					ft_lstadd_back_Runner.c									\
					full_Runner.c libft_Runner.c part1_Runner.c				\
					part2_Runner.c 

SRCS				= unity.c $(RUNNERS) $(TEST_FILES) $(UTILS) 

#----------[ 6. OBJECTS              ]----------#\

PART1_OBJS			= $(PART1:%.c=$(OBJ_DIR)%.o)
PART2_OBJS			= $(PART2:%.c=$(OBJ_DIR)%.o)
BONUS_OBJS			= $(BONUS:%.c=$(OBJ_DIR)%.o)
UTILS_OBJS			= $(UTILS:%.c=$(OBJ_DIR)%.o)
RUNNER_OBJS			= $(RUNNERS:%.c=$(OBJ_DIR)%.o)
TEST_OBJS			= $(TEST_FILES:%.c=$(OBJ_DIR)%.o)

#----------[ 7. RULES                ]----------#

all: libft

#Global runners

libft: $(OBJ_DIR) $(PART1_OBJS) $(PART2_OBJS) $(BONUS_OBJS) $(OBJ_DIR)libft_Runner.o $(OBJ_DIR)unity.o $(UTILS_OBJS)
	@$(CC) $(CFLAGS) $(INC_DIRS) $(OBJ_DIR)unity.o $(PART1_OBJS) $(PART2_OBJS) $(BONUS_OBJS) $(UTILS_OBJS) $(OBJ_DIR)libft_Runner.o -L$(LIBFT_PATH) -lft -o build/libft

part1: $(OBJ_DIR) $(PART1_OBJS) $(OBJ_DIR)part1_Runner.o $(OBJ_DIR)unity.o $(UTILS_OBJS)
	@$(CC) $(CFLAGS) $(INC_DIRS) $(OBJ_DIR)unity.o $(PART1_OBJS) $(OBJ_DIR)part1_Runner.o $(UTILS_OBJS) -L$(LIBFT_PATH) -lft -o build/part1

part2: $(OBJ_DIR) $(PART2_OBJS) $(OBJ_DIR)part2_Runner.o $(OBJ_DIR)unity.o $(UTILS_OBJS)
	@$(CC) $(CFLAGS) $(INC_DIRS) $(OBJ_DIR)unity.o $(PART2_OBJS) $(OBJ_DIR)part2_Runner.o $(UTILS_OBJS) -L$(LIBFT_PATH) -lft -o build/part2

bonus: $(OBJ_DIR) $(BONUS_OBJS) $(OBJ_DIR)bonus_Runner.o $(OBJ_DIR)unity.o $(UTILS_OBJS)
	@$(CC) $(CFLAGS) $(INC_DIRS) $(OBJ_DIR)unity.o $(BONUS_OBJS) $(OBJ_DIR)bonus_Runner.o $(UTILS_OBJS) -L$(LIBFT_PATH) -lft -o build/bonus

# Avoid secondary files deletion
.SECONDARY: $(RUNNER_OBJS) $(PART1_OBJS) $(PART2_OBJS) $(BONUS_OBJS)

ft_%: $(OBJ_DIR)ft_%_test.o $(OBJ_DIR)ft_%_Runner.o $(OBJ_DIR)/unity.o $(UTILS_OBJS) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(INC_DIRS) $(OBJ_DIR)/unity.o $(OBJ_DIR)ft_$*_test.o $(OBJ_DIR)ft_$*_Runner.o $(UTILS_OBJS) -L$(LIBFT_PATH) -lft -o build/$@

#----Compilation rule for unity.c ----#

$(OBJ_DIR)unity.o: unity.c
	@$(CC) -D $(UNITY_FLAGS) -c $(UNITY_ROOT)src/unity.c -o $(OBJ_DIR)unity.o

$(OBJ_DIR)%.o: %.c
	@$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
