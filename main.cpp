//INTEGRANTES: 
//ALFREDO GARCES ULLOA
//DANIEL HERNANDEZ CALFUQUEO
//FRANCISCO PINOCHET MORALES 


#include <omp.h>
#include <algorithm>
#include <iostream>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <string.h>


/**
 * @param inferior valor mínimo posible a buscar aleatoreamente
 * @param superior valor máximo a buscar aleatoreamente
 * @return regresa un valor aleatoreo entre los límites (inclusive)
 */
int aleatoreo(int inferior, int superior);

/**
 * @param largo tamaño del token
 * @return Regresa una cadena de caracteres aleatorea especificada por el largo
 */
std::string getToken(int largo);

int main(int argc, char** argv) {
  std::cout << std::endl;
  srand(time(NULL));
  int a=13;
  int b=333;
  int largo = aleatoreo(a,b);
  std::cout<<largo<<std::endl;
  std::cout << std::endl << getToken(largo) << std::endl;

  

  return 0;
}

int aleatoreo(int inferior, int superior) {
  std::random_device dispositivo;
  std::uniform_int_distribution<int> distribucion(inferior, superior);
  return distribucion(dispositivo);
}

std::string getToken(int largo) {
  static const char letras[] =
      "0123456789"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "abcdefghijklmnopqrstuvwxyz";

  char* texto = new char[largo];
  
#pragma omp parallel
{
#pragma omp for
  
  for (int i = 0; i < largo ; i++) 
    { 
      char letrax=letras[aleatoreo(0,strlen(letras)-1)];
      texto[i] = letrax;

    }
}


  std::string token = std::string(texto);
  

  delete texto;

  return token;
}
 
