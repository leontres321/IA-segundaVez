#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_set>
#include "SA.h"
#include "Class.h"

using namespace std;

vector<int> solucionInicial(vector<vector<int>> conflictos, vector<int> examenes){
    //Algoritmo greedy
    vector<int> solucion (conflictos.size());

    for (unsigned int i = 0; i < examenes.size(); i++){
        solucion[i] = movimientoGreedy(conflictos, solucion, i);
    }

    return solucion;
}

int movimientoGreedy(vector<vector<int>> conflictos, vector<int> solucion, unsigned int iterador){
    unordered_set<int> topes;

    for(unsigned int i = 0; i < conflictos.size(); i++){
        if (i != iterador && conflictos[iterador][i]){
            topes.insert(solucion[i]);
        }
    }

    //Suponiendo que todos tienen tope, el rango es de bloque 1 hasta bloque examenes.size()
    //o tambien conflictos.size() + 1, podria poner <=
    for (unsigned int i = 1; i < conflictos.size() + 1; i++){
        if (topes.find(i) == topes.end()) return i;
    }

    // de nuevo, podria ser un error mas explicativo
    return -1;
}

bool tomarDecision(int WActual, int WNuevo, int tiempo){
    //Actual es mejor que nuevo, osea es menor, hay que minimizar vithe
    float random = rand() / float(RAND_MAX);
    if (exp((WActual - WNuevo) / tiempo) < random) return true;
    return false;
}


float enfriamiento(float tempActual, float alpha){
    return tempActual * alpha;
}

void moverse();
