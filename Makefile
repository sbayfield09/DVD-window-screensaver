# Name of your executable
TARGET = main

# Compiler
CC = gcc

# Source files
SRCS = main.c

# Generate object file names from source files
OBJS = $(SRCS:.c=.o)

# Compiler flags
# -Wall: enable all warnings
# `pkg-config --cflags sdl2 SDL2_image`: gets include paths for SDL2
CFLAGS = -Wall -std=c11 $(shell pkg-config --cflags sdl2 SDL2_image)

# Linker flags
# `pkg-config --libs sdl2 SDL2_image`: gets library paths and link flags
LDFLAGS = $(shell pkg-config --libs sdl2 SDL2_image)

# Default rule
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	./main

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean