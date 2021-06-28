#include <iostream>
#include <vector>
#include "funciones.h"
#include "Class.h"

using namespace std;

int main(int argc, char** argv){
    int tiempo = 50; //numero de prueba
    float temperatura = 100; //numero de prueba
    float alpha = 0.85; //numero de prueba

    vector<int> x;
    vector<Alumno> alumnos;
    vector<Examen> examenes;

    bool debug = false;

    int iDebug = 1;

    if (argc < 2){
        cout << "**********" << endl;
        cout << "Para poder utilizar correctamente este ejecutable es necesario entregar un valor a CASE." << endl;
        cout << "Ejemplos: make run CASE=Instances/Caso1" << endl;
        cout << "          ./out Instances/Caso1" << endl;
        cout << "No poner el formato para los archivos." << endl;
        cout << "**********" << endl;
        exit(0);
    }

    leerArchivo(argv[1], &examenes, &alumnos);

    if (string(argv[2]) == "--debug" || string(argv[2]) == "-d"){
        debug = true;
        cout << "Examenes id: " << examenes[iDebug].id << "| Cant.Alum.: " << examenes[iDebug].cantAlumnos << endl;
        cout << "Alumno id: " << alumnos[iDebug].id << "| Cant.Exm: " << alumnos[iDebug].examenes.size() << endl;
        for (auto i = alumnos[iDebug].examenes.begin(); i != alumnos[iDebug].examenes.end(); i++){
            cout << "Id examen: " << *i << endl;
        }
    }
/*
    for (int i = 0; i < tiempo; i++){
        for (int j = 0; j < 99; j++){
            //Seleccionar un nuevo punto (Sn)
            //if (nuevoPunto es mejor)
            //    Sc <- Sn
            //else if random([0,1]) < eVal
            //   Sc <- Sn
            //if Sc es mejor que Sbest
            //    Sbest <- Sc

        }
    }
*/
    return 0;
}
