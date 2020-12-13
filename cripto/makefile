# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author Iván Texenery Díaz García
# @date 12/12/2020
# @brief Makefile
# 

CC = g++
CFLAGS = -Wall

cripto: cripto.o funciones_cripto.o
		$(CC) -o cripto cripto.o funciones_cripto.o $(CFLAGS) 
.PHONY: all clean

clean:
		rm -rf *.o