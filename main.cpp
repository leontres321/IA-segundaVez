#include <iostream>
#include <vector>
#include "funciones.h"
#include "Class.h"
#include "SA.h"

using namespace std;

int main(int argc, char** argv){
    int tiempo = 50; //numero de prueba
    float temperatura = 100; //numero de prueba
    float alpha = 0.85; //numero de prueba
    int iteraciones = 10; //numero de prueba

    int descontento;
    int W;

    vector<int> x;
    vector<Alumno> alumnos;
    vector<int> examenes;
    vector<vector<int>> conflictos;

    bool debug = false;

    int loopMatriz = 6;
    int iDebug = 1;
    unsigned int loopX = 10;

    if (argc < 2){
        cout << "**********" << endl;
        cout << "Para poder utilizar correctamente este ejecutable es necesario entregar un valor a CASE." << endl;
        cout << "Ejemplos: make run CASE=Instances/Caso1" << endl;
        cout << "          ./out Instances/Caso1" << endl;
        cout << "No poner el formato para los archivos." << endl;
        cout << "**********" << endl;
        exit(0);
    }

    //Para tener numeros "random"
    srand ( time(NULL) );

    leerArchivo(argv[1], &examenes, &alumnos);

    if (argc == 3 && (string(argv[2]) == "--debug" || string(argv[2]) == "-d")){
        debug = true;
        cout << "Examenes id: " << examenes[iDebug] << "| Cant.Total: " << examenes.size() << endl;
        cout << "Alumno id: " << alumnos[iDebug].id << "| Cant.Exm: " << alumnos[iDebug].examenes.size() << endl;
        for (auto i = alumnos[iDebug].examenes.begin(); i != alumnos[iDebug].examenes.end(); i++){
            cout << "Id examen: " << *i << endl;
        }
    }

    conflictos = generarMatriz(examenes, alumnos);

    if (debug){
        for (int i = 0; i < loopMatriz; i++){
            for (int j = 0; j < loopMatriz; j++){
                cout << conflictos[i][j] << " ";
            }
            cout << endl;
        }
    }

     x = solucionInicial(conflictos, examenes);

     W = ultimoTimeslot(x);

     //TODO: calcular descontento

     if (debug){
         cout << "W: " << W << endl;
         //cout << "Descontento: " << descontento << endl;
         for (int i = 0; i < loopX; i++){
             cout << x[i] << " ";
         }
         cout << endl;
     }

    for (int i = 0; i < tiempo; i++){
        for (int j = 0; j < iteraciones; j++){
            //Seleccionar un nuevo punto (Sn)
            //if (nuevoPunto es mejor)
            //    Sc <- Sn
            //else if random([0,1]) < eVal
            //   Sc <- Sn
            //if Sc es mejor que Sbest
            //    Sbest <- Sc

        }
        //bajar temperatura
        temperatura = enfriamiento(temperatura, alpha);
    }
    return 0;
}
