#include <iostream>
#include <vector>
#include "funciones.h"
#include "Class.h"
#include "SA.h"

#include <chrono>

using namespace std;

int main(int argc, char** argv){
    int tiempo;
    float temperatura;
    float alpha;
    int iteraciones;

    float descontento;
    int W;

    //Para moverse
    int examenAzar;
    float nuevoDescontento;
    int nuevoW;
    vector<int> nuevoX;

    //best
    vector<int> mejorX;
    float mejorDescontento;
    int mejorW;

    vector<int> x;
    vector<Alumno> alumnos;
    vector<int> examenes;
    vector<vector<int>> conflictos;

    bool debug = false;

    int loopMatriz = 6;
    int iDebug = 1;
    int loopX = 10;

    //tiempos

    auto started = chrono::high_resolution_clock::now();

    if (argc < 7){
        cout << "**********" << endl;
        cout << "Para poder utilizar correctamente este ejecutable es necesario entregar un valor a CASE." << endl;
        cout << "Ejemplos: make run CASE=Instances/Caso1 DEBUG=-n TIME=10 TEMP=10 ALPHA=0.6 ITER=55" << endl;
        cout << "          ./out Instances/Caso1 -n 10 10 0.6 55" << endl;
        cout << "No poner el formato para los archivos." << endl;
        cout << "**********" << endl;
        exit(0);
    }

    tiempo = stoi(argv[3]); //numero de prueba
    temperatura = stof(argv[4]); //numero de prueba
    alpha = stof(argv[5]); //numero de prueba
    iteraciones = stoi(argv[6]); //numero de prueba
    //Para tener numeros "random"
    srand ( time(NULL) );

    leerArchivo(argv[1], &examenes, &alumnos);

    if (argc >= 3 && (string(argv[2]) == "--debug" || string(argv[2]) == "-d")){
        debug = true;
        cout << "Examenes id: " << examenes[iDebug] << "| Cant.Total: " << examenes.size() << endl;
        cout << "Alumno id: " << alumnos[iDebug].id << "| Cant.Exm: " << alumnos[iDebug].examenes.size() << endl;
        for (auto i = alumnos[iDebug].examenes.begin(); i != alumnos[iDebug].examenes.end(); i++){
            cout << "Id examen: " << *i << endl;
        }
    }

    conflictos = generarMatriz(examenes, alumnos);

    if (debug){
        cout << "-------------" << endl;
        cout << "Tiempo: " << tiempo << endl;
        cout << "Temperatura: " << temperatura << endl;
        cout << "Alpha: " << alpha << endl;
        cout << "Iteraciones: " << iteraciones << endl;
        cout << "-------------" << endl;
        cout << "Matriz: " << endl;
        for (int i = 0; i < loopMatriz; i++){
            for (int j = 0; j < loopMatriz; j++){
                cout << conflictos[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-------------" << endl;
    }

    //Valores iniciales
     x = solucionInicial(conflictos, examenes);
     W = ultimoTimeslot(x);
     descontento = calcularDescontento(x, examenes, alumnos);

     //Guardarla como mejor solucion
     mejorX = vector<int> (x);
     mejorW = W;
     mejorDescontento = descontento;

     if (debug){
         cout << "W: " << W << endl;
         cout << "Descontento promedio: " << descontento << endl;
         for (int i = 0; i < loopX; i++){
             cout << x[i] << " ";
         }
         cout << endl;
     }

    for (int i = 0; i < tiempo; i++){
        for (int j = 0; j < iteraciones; j++){
            //Seleccionar un nuevo punto (Sn)
            examenAzar = rand() % examenes.size();

            //Movimiento
            nuevoX = moverse(x, examenAzar);

            //Revisar si es factible
            if (!solucionValida(conflictos, nuevoX, examenAzar)){
                //solucion no es valida, se debe continuar
                continue;
            }

            nuevoDescontento = calcularDescontento(nuevoX, examenes, alumnos);
            nuevoW = ultimoTimeslot(nuevoX);

            if (nuevoW < W){
                //la solucion minimiza los bloques
                x = nuevoX;
                W = nuevoW;
                descontento = nuevoDescontento;
            }
            else if (nuevoW == W && nuevoDescontento < descontento){
                //no minimiza bloques pero ayuda a bajar el descontento
                x = nuevoX;
                descontento = nuevoDescontento;
            }
            else if (tomarDecision(W, nuevoW, tiempo)){
                //La solucion empeora W y hay que ver si es aceptada
                x = nuevoX;
                W = nuevoW;
                descontento = nuevoDescontento;
            }

            //Las solucion encontrada es mejor que la mejor
            if (W < mejorW){
                mejorW = W;
                mejorX = x;
                mejorDescontento = descontento;
            }
            else if (W == mejorW && descontento < mejorDescontento){
                mejorX = x;
                mejorDescontento = descontento;
            }

        }
        //bajar temperatura
        temperatura = enfriamiento(temperatura, alpha);
    }

    //escribir archivos
    if (debug){
         cout << "-------------" << endl;
         cout << "Solucion encontrada:" << endl;
         cout << "W: " << mejorW << endl;
         cout << "Descontento promedio: " << mejorDescontento << endl;
         for (int i = 0; i < loopX; i++){
             cout << mejorX[i] << " ";
         }
         cout << endl;
    }

    escribirSalida(mejorW, examenes, mejorDescontento, mejorX);

    auto done = chrono::high_resolution_clock::now();

    cout << "Tiempo ejecucion: " << chrono::duration_cast<chrono::milliseconds>(done-started).count() << "ms" << endl;

    return 0;
}
