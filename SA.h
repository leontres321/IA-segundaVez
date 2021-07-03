#ifndef SA_H
#define SA_H
#include <iostream>
#include <vector>
#include "Class.h"

bool tomarDecision(float cambiar, int tiempo);

std::vector<int> solucionInicial(std::vector<int> soluciones,
                                              std::vector<Alumno> alumnos,
                                              std::vector<int> examenes);

float enfriamiento(float tempActual, float alpha);

void moverse();

#endif // SA_H
