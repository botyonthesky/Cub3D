# Project name
NAME 		:= cub3D
BONUS		:= cub3D_bonus

# Compiler and flags
CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra
CFLAGS		+= -I./include
CPPFLAGS	+= -MMD -MP -MF $(@:.o=.d)
MLXFLAGS	:= -lX11 -lXext -lm -lz -L.

# Directories
SRC_DIR 		:= ./src
OBJ_DIR 		:= ./obj
LIBFT_DIR		:= ./libft
MINILIBX_DIR	:= ./minilibx-linux

# Libraries
LIBFT			:= ./libft/libft.a
MINILIBX		:= ./minilibx-linux/libmlx.a

# Source files
ROOT_SRC :=	\
			cub3d.c \
			destroy.c \
			handle.c \
			player.c \
			render.c \
			utils.c 
ROOT_DIR := $(SRC_DIR)
ROOT_OBJ := $(addprefix $(OBJ_DIR)/, $(ROOT_SRC:.c=.o))

RAYCASTING_SRC :=	\
			math_utils.c \
			scene.c \
			draw_minimap.c \
			draw_shapes.c \
			bresenham.c \
			mlx_utils.c \
			minimap_rays.c \
			minimap_rays_utils.c \
			draw_rays.c \
			collision.c
RAYCASTING_DIR := $(addprefix $(SRC_DIR)/, raycasting)
RAYCASTING_OBJ := $(addprefix $(OBJ_DIR)/raycasting/, $(RAYCASTING_SRC:.c=.o))

PARSING_SRC :=	\
			check_map.c \
			colors.c \
			fill_grid.c \
			textures.c \
			utils.c 
PARSING_DIR := $(addprefix $(SRC_DIR)/, parsing)
PARSING_OBJ := $(addprefix $(OBJ_DIR)/parsing/, $(PARSING_SRC:.c=.o))

ANIM_SRC := \
			assign_weapons.c \
			assign_menu.c \
			canon_shoot.c \
			door_close.c \
			door_loop.c \
			door_open.c \
			door.c \
			expander_shoot.c \
			grenade_shoot.c \
			gun_shoot.c \
			mlx_perso.c \
			monster_fire.c \
			boss.c \
			monster.c \
			shoot_loop.c \
			shotgun_shoot.c \
			start.c \
			switch_sprites.c \
			weapons.c 
ANIM_DIR := $(addprefix $(SRC_DIR)/, animation)
ANIM_OBJ := $(addprefix $(OBJ_DIR)/animation/, $(ANIM_SRC:.c=.o))

UI_SRC	:= \
			init_data.c \
			init_add.c \
			manage_ui.c \
			put_ui.c \
			set_ui.c \
			ui_info.c \
			pause.c \
			menu.c \
			switch.c \
			manage_health.c 
UI_DIR	:= $(addprefix $(SRC_DIR)/, ui)
UI_OBJ	:= $(addprefix $(OBJ_DIR)/ui/, $(UI_SRC:.c=.o))

# Combine all source files and object files
SRC :=	\
		$(ROOT_SRC)\
		$(PARSING_SRC)\
		$(ANIM_SRC)\
		$(UI_SRC)\
		$(RAYCASTING_SRC)
OBJ :=	\
		$(ROOT_OBJ)\
		$(PARSING_OBJ)\
		$(ANIM_OBJ)\
		$(UI_OBJ)\
		$(RAYCASTING_OBJ)

# Directories
SRCB_DIR 		:= ./src_bonus
OBJB_DIR 		:= ./obj_bonus

# Source files
ROOTB_SRC :=	\
			cub3d_bonus.c \
			destroy_bonus.c \
			handle_bonus.c \
			player_bonus.c \
			render_bonus.c \
			utils_bonus.c
ROOTB_DIR := $(SRCB_DIR)
ROOTB_OBJ := $(addprefix $(OBJB_DIR)/,$(ROOTB_SRC:.c=.o))

RAYCASTINGB_SRC :=	\
			math_utils_bonus.c \
			scene_bonus.c \
			draw_minimap_bonus.c \
			draw_shapes_bonus.c \
			bresenham_bonus.c \
			mlx_utils_bonus.c \
			minimap_rays_bonus.c \
			minimap_rays_utils_bonus.c \
			draw_rays_bonus.c \
			collision_bonus.c
RAYCASTINGB_DIR := $(addprefix $(SRCB_DIR)/,raycasting)
RAYCASTINGB_OBJ := $(addprefix $(OBJB_DIR)/raycasting/, $(RAYCASTINGB_SRC:.c=.o))

PARSINGB_SRC :=	\
			check_map_bonus.c \
			colors_bonus.c \
			fill_grid_bonus.c \
			textures_bonus.c \
			utils_bonus.c
PARSINGB_DIR := $(addprefix $(SRCB_DIR)/,parsing)
PARSINGB_OBJ := $(addprefix $(OBJB_DIR)/parsing/,$(PARSINGB_SRC:.c=.o))

ANIMB_SRC := \
			assign_weapons_bonus.c \
			assign_menu_bonus.c \
			canon_shoot_bonus.c \
			door_close_bonus.c \
			door_loop_bonus.c \
			door_open_bonus.c \
			door_bonus.c \
			expander_shoot_bonus.c \
			grenade_shoot_bonus.c \
			gun_shoot_bonus.c \
			mlx_perso_bonus.c \
			monster_fire_bonus.c \
			boss_bonus.c \
			monster_bonus.c \
			shoot_loop_bonus.c \
			shotgun_shoot_bonus.c \
			start_bonus.c \
			switch_sprites_bonus.c \
			weapons_bonus.c
ANIMB_DIR := $(addprefix $(SRCB_DIR)/,animation)
ANIMB_OBJ := $(addprefix $(OBJB_DIR)/animation/,$(ANIMB_SRC:.c=.o))

UIB_SRC	:= \
			init_data_bonus.c \
			init_add_bonus.c \
			manage_ui_bonus.c \
			put_ui_bonus.c \
			set_ui_bonus.c \
			ui_info_bonus.c \
			pause_bonus.c \
			menu_bonus.c \
			switch_bonus.c \
			manage_health_bonus.c
UIB_DIR	:= $(addprefix $(SRCB_DIR)/,ui)
UIB_OBJ	:= $(addprefix $(OBJB_DIR)/ui/,$(UIB_SRC:.c=.o))

# Combine all source files and object files
SRCB :=	\
		$(ROOTB_SRC)\
		$(PARSINGB_SRC)\
		$(ANIMB_SRC)\
		$(UIB_SRC)\
		$(RAYCASTINGB_SRC)
OBJB :=	\
		$(ROOTB_OBJ)\
		$(PARSINGB_OBJ)\
		$(ANIMB_OBJ)\
		$(UIB_OBJ)\
		$(RAYCASTINGB_OBJ)

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJB_DIR)/%.o: $(SRCB_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Default target: build the executable
# all: libft
# 	@$(MAKE) --no-print-directory $(NAME)

# Rule to build the executable
# $(NAME): $(OBJ)
# 	@echo "$(YELLOW) Building cub3D ... $(END)"
# 	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLXFLAGS) ./libft/libft.a 
# 	@echo "$(GREEN) cub3D built successfully. $(END)"

all: 		$(NAME)
bonus: 		$(BONUS)

$(NAME):	$(LIBFT) $(MINILIBX) $(OBJ)
	@echo "$(YELLOW) Compiling cub3D $(CFLAGS) $(MLXFLAGS)...$(END)"
	@echo "$(GREEN) cub3D compiled successfully.$(END)"
	@echo "$(YELLOW) Building cub3D ... $(END)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN) cub3D built successfully. $(END)"

$(BONUS):	$(LIBFT) $(MINILIBX) $(OBJB)
	@echo "$(YELLOW) Compiling cub3D_bonus $(CFLAGS) $(MLXFLAGS)...$(END)"
	@echo "$(GREEN) cub3D_bonus compiled successfully.$(END)"
	@echo "$(YELLOW) Building cub3D_bonus ... $(END)"
	@$(CC) $(CFLAGS) $(OBJB) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(BONUS)
	@echo "$(GREEN) cub3D_bonus built successfully. $(END)"

$(LIBFT):	
	@echo "$(YELLOW) Building libft $(CFLAGS) ...$(END)"	
	@$(MAKE) DEBUG=$(DEBUG) -C $(LIBFT_DIR) >/dev/null 2>&1
	@echo "$(GREEN) libft built successfully.$(END)"

$(MINILIBX):
	@echo "$(YELLOW) Building minilibx $(MLXFLAGS) ...$(END)"
	@$(MAKE) -C $(MINILIBX_DIR) >/dev/null 2>&1
	@echo "$(GREEN) minilibx built successfully.$(END)"

# Rule to build the libft
# libft:
# 	@echo "$(YELLOW) Building libft $(CFLAGS) ...$(END)"
# 	@$(MAKE) DEBUG=$(DEBUG) -C ./libft >/dev/null 2>&1
# 	@echo "$(GREEN) libft built successfully.$(END)"

# Rule to build the libft for release
libft_release:
	@echo "$(YELLOW) Building libft (release) ...$(END)"
	@$(MAKE) release -C ./libft >/dev/null 2>&1
	@echo "$(GREEN) libft (release) built successfully.$(END)"

# Clean object files and dependencies
clean:
	@echo "$(YELLOW) Cleaning object files and dependencies libft minilibx ...$(END)"
	@rm -rf $(OBJ_DIR) $(OBJB_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean >/dev/null 2>&1
	@$(MAKE) -C $(MINILIBX_DIR) clean >/dev/null 2>&1
	@echo "$(GREEN) Clean complete.$(END)"

# Remove object files, dependencies, and the executable
fclean: clean
	@echo "$(YELLOW) Cleaning object files, dependencies and removing $(NAME)...$(END)"
	@rm -f $(NAME) $(BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean >/dev/null 2>&1
	@echo "$(GREEN) Full clean complete $(END)"

# Rebuild everything
re: fclean
	@$(MAKE) --no-print-directory all

re_bonus: fclean
	@$(MAKE) --no-print-directory bonus

# Release target with optimization and stripping
release: CFLAGS += -O2
release: libft_release $(NAME)
	strip libft/libft.a
	strip $(NAME)

# Debug and Optimization Mode Configuration
DEBUG	:= 0

ifeq ($(DEBUG), 1)
    CFLAGS += -g3
endif

# Visual Optimisation

BLUE=\033[0;34m
YELLOW=\033[0;33m
GREEN=\033[0;32m
RED=\033[0;31m
END=\033[0m

# Phony targets
.PHONY: all clean debug fclean re release libft minilibx

# Include dependency files
-include $(OBJ:.o=.d)