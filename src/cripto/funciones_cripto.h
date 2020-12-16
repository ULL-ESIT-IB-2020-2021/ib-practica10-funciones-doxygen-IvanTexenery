/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado de Ingeniería Informática
 * Informática Básica
 * @file funciones_cripto.h
 * @author Iván Texenery Díaz García
 * @date 12/12/2020
 * @brief Declaraciones de funciones del programa principal.
 */
#include <string>
void Parametros(int argc, char *argv[]);
std::string EncriptXor(std::string cadena_a_encriptar, std::string palabra_clave);
std::string EncriptCesar(std::string cadena_a_encriptar, int k_encriptar);
bool EsEntero(std::string cadena);