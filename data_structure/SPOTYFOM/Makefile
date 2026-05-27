APP := exec

CC ?= gcc

CFLAGS ?= -Wall -Wextra -g -O2 -Iinclude

SRCS := mainSpotyfom.c \
	src/fila.c \
	src/LDE.c \
	src/LSE.c \
	src/parser.c \
	src/pilha.c 

OBJS := $(SRCS:.c=.o)

.PHONY: all run clean 

all: $(APP)

$(APP): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(APP)
	./$(APP)

clean:
	rm -f $(OBJS) $(APP)

help:
	@echo "Usage:"
	@echo "  make        - Build"
	@echo "  make run    - Run"
	@echo "  make clean  - Clean up build files"
