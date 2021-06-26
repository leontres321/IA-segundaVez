#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <iostream>
#include <vector>
#include "Class.h"

void leerArchivo(std::string nombre,
                 std::vector<Examen> examenes,
                 std::vector<Alumno> alumnos);

int* generarMatriz(std::vector<Examen> examenes);

bool tomarDecision(float cambiar, int tiempo);

void solucionInicial();

float enfriamiento(float tempActual);

#endif // FUNCIONES_H_
