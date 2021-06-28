#include <iostream>
#include <fstream>
#include "funciones.h"
#include "Class.h"

using namespace std;

void leerArchivo(string nombre,
                 vector<Examen>* examenes,
                 vector<Alumno>* alumnos){
    ifstream archivoEXM (nombre + ".exm");
    ifstream archivoSTU (nombre + ".stu");
    Alumno newAlumno;
    Examen newExamen;
    if (archivoEXM.is_open() && archivoSTU.is_open()){

    }
    else{
        cout << "Alguno de los archivos no fue encontrado." << endl;
        archivoEXM.close();
        archivoSTU.close();
        exit(1);
    }
}

int* generarMatriz(std::vector<Examen> examenes){
   int* matriz = nullptr;
}

bool tomarDecision(float cambiar, int tiempo){
    //exp(delta/tiempo)
    return true;
}

void solucionInicial(){

}

float enfriamiento(float tempActual, float alpha){
    return tempActual * alpha;
}
