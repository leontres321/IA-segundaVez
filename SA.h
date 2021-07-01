#ifndef SA_H
#define SA_H
#include <iostream>
#include <vector>

bool tomarDecision(float cambiar, int tiempo);

void solucionInicial(std::vector<int> soluciones);

float enfriamiento(float tempActual, float alpha);

void moverse();

#endif // SA_H
