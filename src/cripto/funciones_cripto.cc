/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado de Ingeniería Informática
 * Informática Básica
 * @file funciones_cripto.cc
 * @author Iván Texenery Díaz García
 * @date 12/12/2020
 * @brief Funciones del programa principal
 * @see https://es.wikipedia.org/wiki/Cifrado_XOR
 * @see https://es.wikipedia.org/wiki/Cifrado_C%C3%A9sar
 */
#include "funciones_cripto.h"    
#include <string>
#include <iostream>

/**
 * Controla que los parámetros que se le pasan a la funcion main sean correctos.
 * @param Cantidad de parámetros introducidos, array de caracteres con los argumentos introducidos. 
 */
void Parametros(int argc, char *argv[]) {
  const std::string kTextoAyuda = "  Modo de uso: ./cripto fichero_entrada fichero_salida método password operación\n\
  fichero_entrada: Fichero a codificar\n\
  fichero_salida:  Fichero codificado\n\
  método:          Indica el método de encriptado\n\
                   1: Cifrado xor(introducir 'xor')\n\
                   2: Cifrado de César(introducir 'cesar') \n\
  password:        Palabra secreta en el caso de método 1, Valor de K en el método 2\n\
  operación:       Operación a realizar en el fichero\n\
                   +: encriptar el fichero\n\
                   -: desencriptar el fichero";
                
  std::string parametro{argv[1]};
  if (parametro == "--help") {
    std::cout << kTextoAyuda << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc != 6) {
    std::cout << argv[0] << " Modo de uso: ./cripto fichero_entrada fichero_salida método password operación" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/**
 * Encripta o desencripta el mensaje que se le pasa por parámetro.
 * @param Mensaje a encriptar mediante xor y palabra clave para cifrar el mensaje.
 * @return Mensaje inicial encriptado.
 */
std::string EncriptXor(std::string cadena_a_encriptar, std::string palabra_clave){
  std::string cadena_encriptada{""};
  std::string clave_encriptada{""};

  for(size_t i = 0; i < palabra_clave.length(); ++i){
    clave_encriptada.push_back(palabra_clave[i] ^ (char)128);
  }
  for(size_t i = 0; i < cadena_a_encriptar.length(); ++i){
    cadena_encriptada.push_back(cadena_a_encriptar[i] ^ clave_encriptada[i % clave_encriptada.length()]);
  } 
  return cadena_encriptada;
}

/**
 * Encripta o desencripta el mensaje que se le pasa por parámetro.
 * @param Mensaje a encriptar mediante encriptado cesar y valor de k para cifrar el mensaje.
 * @return Mensaje inicial encriptado.
 */
std::string EncriptCesar(std::string cadena_a_encriptar, int k_encriptar){
  for(size_t i = 0; i < cadena_a_encriptar.length(); ++i){
    cadena_a_encriptar[i] += k_encriptar;
  }
  return cadena_a_encriptar;
}

/**
 * Comprueba si la string es un número entero.
 * @param Cadena para comprobar si es un entero.
 * @return False o True dependiendo de si es un entero o no.
 */
bool EsEntero(std::string cadena) {
  for(auto elemento: cadena)
  {
    if(elemento < 48 || elemento > 57)
      return false;
  }
  return true;
} 