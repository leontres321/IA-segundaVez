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

    string lectura1;
    string lectura2;

    if (archivoEXM.is_open() && archivoSTU.is_open()){
        //Leera hasta dejar el archivo vacio
        while (archivoEXM >> lectura1 >> lectura2){
            Examen newExamen;
            newExamen.id = stoi(lectura1);
            newExamen.cantAlumnos = stoi(lectura2);
            examenes->push_back(newExamen);
        }

        while (archivoSTU >> lectura1 >> lectura2){
            //Falta logica de agregar mas pruebas al mismo alumno
            Alumno newAlumno;
            newAlumno.id = lectura1;
            newAlumno.examenes.push_back(stoi(lectura2));
            if (alumnos->size() > 0 && alumnos->back().id == lectura1){
                //El alumno posee mas de examen a rendir
                alumnos->back().examenes.push_back(stoi(lectura2));
            }
            else{
                alumnos->push_back(newAlumno);
            }
        }
        archivoEXM.close();
        archivoSTU.close();
    }
    else{
        cout << "Alguno de los archivos no fue encontrado." << endl;
        archivoEXM.close();
        archivoSTU.close();
        exit(EXIT_FAILURE);
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
