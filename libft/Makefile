# Makefile for building the libft library

# Output library name
NAME = libft.a

# Compiler and flags
CC			:=  cc
CFLAGS 		:= -Wall -Wextra -Werror -fPIE
CPPFLAGS 	+= -MMD -MP -MF $(@:.o=.d)

# Directories
SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj

# Source files
DISPLAY_SRC := \
	close_fd.c \
	dup_error.c \
	ft_close_fd.c \
	ft_fd_is_valid.c \
    ft_putchar_fd.c \
    ft_putendl_fd.c \
    ft_putnbr_fd.c \
    ft_putstr_fd.c \
	reopen.c \
	stdout_to_stderr.c
DISPLAY_DIR := $(addprefix $(SRC_DIR)/,display)
DISPLAY_OBJ := $(addprefix $(OBJ_DIR)/display/, $(DISPLAY_SRC:.c=.o))

GRAPHIC_SRC := \
	ft_hex_to_rgb.c \
	ft_rgb_to_hex.c
GRAPHIC_DIR := $(addprefix $(SRC_DIR)/,graphic)
GRAPHIC_OBJ := $(addprefix $(OBJ_DIR)/graphic/, $(GRAPHIC_SRC:.c=.o))

GET_NEXT_LINE_SRC := \
    get_next_line.c \
    get_next_line_utils.c
GET_NEXT_LINE_DIR := $(addprefix $(SRC_DIR)/,get_next_line)
GET_NEXT_LINE_OBJ := $(addprefix $(OBJ_DIR)/get_next_line/, \
	$(GET_NEXT_LINE_SRC:.c=.o))

LIST_SRC := \
    ft_gcadd_back.c \
    ft_gcadd_front.c \
	ft_gcclear.c \
	ft_gcdelfirst.c \
	ft_gcdellast.c \
	ft_gcdelone.c \
	ft_gcfindone.c \
    ft_gclast.c \
    ft_gcnew.c \
    ft_gcsize.c \
    ft_lstadd_back.c \
    ft_lstadd_front.c \
    ft_lstclear.c \
	ft_lstdelfirst.c \
	ft_lstdellast.c \
    ft_lstdelone.c \
    ft_lstiter.c \
    ft_lstlast.c \
    ft_lstmap.c \
    ft_lstnew.c \
    ft_lstsize.c
LIST_DIR := $(addprefix $(SRC_DIR)/,list)
LIST_OBJ := $(addprefix $(OBJ_DIR)/list/, $(LIST_SRC:.c=.o))

MATH_SRC := \
    ft_abs.c \
	ft_find_next_prime.c \
	ft_is_prime.c \
	ft_max.c \
	ft_min.c \
	ft_mod.c \
	ft_swap.c
MATH_DIR := $(addprefix $(SRC_DIR)/,math)
MATH_OBJ := $(addprefix $(OBJ_DIR)/math/, $(MATH_SRC:.c=.o))

MEMORY_SRC := \
    ft_bzero.c \
    ft_calloc.c \
	ft_failloc.c \
	ft_free.c \
	ft_freenull.c \
	ft_memcheck.c \
    ft_memchr.c \
    ft_memcmp.c \
    ft_memcpy.c \
    ft_memmove.c \
    ft_memset.c
MEMORY_DIR := $(addprefix $(SRC_DIR)/,memory)
MEMORY_OBJ := $(addprefix $(OBJ_DIR)/memory/, $(MEMORY_SRC:.c=.o))

PREDICATE_SRC := \
    ft_isalnum.c \
    ft_isalpha.c \
    ft_isascii.c \
    ft_isdigit.c \
    ft_islower.c \
    ft_isnumber.c \
    ft_isprint.c \
    ft_isspace.c \
    ft_isupper.c
PREDICATE_DIR := $(addprefix $(SRC_DIR)/,predicate)
PREDICATE_OBJ := $(addprefix $(OBJ_DIR)/predicate/, $(PREDICATE_SRC:.c=.o))

PRINTF_SRC := \
    ft_printf_address.c \
    ft_printf.c \
    ft_printf_char.c \
    ft_printf_decimal.c \
    ft_printf_integer_decimal.c \
    ft_printf_lowercase_hexadecimal.c \
    ft_printf_percent.c \
    ft_printf_string.c \
    ft_printf_unsigned_decimal.c \
    ft_printf_uppercase_hexadecimal.c \
    ft_printf_utils.c
PRINTF_DIR := $(addprefix $(SRC_DIR)/,printf)
PRINTF_OBJ := $(addprefix $(OBJ_DIR)/printf/, $(PRINTF_SRC:.c=.o))

STRING_SRC := \
    ft_atoi.c \
    ft_atoll.c \
    ft_c_to_s.c \
	ft_count_tokens.c \
    ft_itoa.c \
    ft_ltoa.c \
    ft_split.c \
    ft_strchr.c \
    ft_strcmp.c \
    ft_strdup.c \
    ft_striteri.c \
    ft_strjoin.c \
    ft_strlcat.c \
    ft_strlcpy.c \
    ft_strlen.c \
    ft_strmapi.c \
    ft_strncmp.c \
    ft_strnstr.c \
	ft_strpbrk.c \
	ft_strstr.c \
	ft_strtoi.c \
	ft_strtok.c \
	ft_strtok_r.c \
    ft_strrchr.c \
    ft_strtrim.c \
    ft_substr.c \
    ft_tolower.c \
    ft_toupper.c \
	ft_trimwhitespace.c
STRING_DIR := $(addprefix $(SRC_DIR)/,string)
STRING_OBJ := $(addprefix $(OBJ_DIR)/string/, $(STRING_SRC:.c=.o))

# Combine all source files and object files
SRC := $(DISPLAY_SRC) $(GRAPHIC_SRC) $(GET_NEXT_LINE_SRC) $(LIST_SRC) \
	$(MATH_SRC) $(MEMORY_SRC) $(PREDICATE_SRC) $(PRINTF_SRC) $(STRING_SRC)
OBJ := $(DISPLAY_OBJ) $(GRAPHIC_OBJ) $(GET_NEXT_LINE_OBJ) $(LIST_OBJ) \
	$(MATH_OBJ) $(MEMORY_OBJ) $(PREDICATE_OBJ) $(PRINTF_OBJ) $(STRING_OBJ)

# Rules to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -I$(INC_DIR) -c $< -o $@

# Default target
all: 
	make $(NAME)

# Rule to create the library
$(NAME): $(OBJ)
	ar rcs $@ $^

# Clean up object files
clean:
	rm -rf $(OBJ_DIR)

# Remove object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean 
	make all

# Release target: Builds an optimized release version of the library
release: CFLAGS += -O2
release: $(NAME)

# Debug Mode Configuration
DEBUG	:= 0

ifeq ($(DEBUG), 1)
    CFLAGS += -g3
endif

# Phony targets
.PHONY: all clean debug fclean re release

# Include .d files (dependency files)
-include $(OBJ:.o=.d)
