TARGET = brt

CC = clang

CFLAGS = -Wall -Wextra -pedantic -std=c99

SRCS = brt.c args.c helper.c operations.c

LIBS = -ldirutils -lfileutils -lstrutils

OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa os arquivos objeto e o programa
clean:
	rm -f $(OBJS)

# Define as regras que não são nomes de arquivos
.PHONY: all clean

# Regra padrão, que compila o programa
all: $(TARGET)
