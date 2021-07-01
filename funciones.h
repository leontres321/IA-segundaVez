#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <iostream>
#include <vector>
#include "Class.h"

void leerArchivo(std::string nombre,
                 std::vector<int>* examenes,
                 std::vector<Alumno>* alumnos);

std::vector<std::vector<int>> generarMatriz(std::vector<int> examenes);

float ultimoTimeslot(std::vector<int> x);

void escribirSalida(int ultimoTimeslot,
                    std::vector<int> examenes,
                    float penalizacion,
                    std::vector<int> solucion);

#endif // FUNCIONES_H_
