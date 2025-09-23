# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Iinclude -Ivendor -Llib -lraylib -lm -lpthread -ldl -lrt -lX11

# Source files
SRCS = src/main.c src/input.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
EXEC = build/game

# Default target
all: $(EXEC)

# Link the object files to create the executable
$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(CFLAGS)
	cp config.json build/

# Compile the source files into object files
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

# Clean up the build files
clean:
	rm -f $(OBJS) $(EXEC)
