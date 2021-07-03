#ifndef SA_H
#define SA_H
#include <iostream>
#include <vector>
#include "Class.h"

/*
 *  Parte greedy
 */

std::vector<int> solucionInicial(std::vector<std::vector<int>> conflictos,
                                 std::vector<int> examenes);

int movimientoGreedy(std::vector<std::vector<int>> conflictos,
                     std::vector<int> solucion,
                     unsigned int iterador);

/*
 *  Parte Simulated Annealing
 */

bool tomarDecision(int WActual, int WNuevo, int tiempo);

float enfriamiento(float tempActual, float alpha);

void moverse();

#endif // SA_H
