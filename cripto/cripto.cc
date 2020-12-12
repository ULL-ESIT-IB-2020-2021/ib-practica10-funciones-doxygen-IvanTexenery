/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado de Ingeniería Informática
 * Informática Básica
 * @file cripto.cc
 * @author Iván Texenery Díaz García
 * @date 12/12/2020
 * @brief Desarrolle en C++ un programa cripto.cc cuya finalidad será 
 * encriptar y/o desencriptar ficheros de texto.
 */
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "funciones_cripto.h"

int main(int argc, char* argv[]){

Parametros(argc,argv);

std::ifstream archivo_entrada(argv[1], std::ifstream::in);
std::ofstream archivo_salida(argv[2], std::ofstream::out);
std::string cifrado{argv[3]};
std::string clave {argv[4]};
std::string modo{argv[5]};
int k_cesar{0};

std::stringstream buffer;
buffer << archivo_entrada.rdbuf();
std::string mensaje{buffer.str()};


if(cifrado == "xor" && modo == "+" || cifrado == "xor" && modo == "-"){
  archivo_salida << EncriptXor(mensaje, clave);
  archivo_salida.close();
}

if(cifrado == "cesar" && modo == "+"){
  int k_cesar{stoi(clave)};
  archivo_salida << EncriptCesar(mensaje,k_cesar);
}

if(cifrado == "cesar" && modo == "-"){
  int k_cesar{stoi(clave)};
  archivo_salida << EncriptCesar(mensaje,-k_cesar);
}
 
  return 0;
}