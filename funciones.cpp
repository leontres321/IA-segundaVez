#include <iostream>
#include <fstream>
#include "funciones.h"
#include "Class.h"

using namespace std;

void leerArchivo(string nombre,
                 vector<int>* examenes,
                 vector<Alumno>* alumnos){

    ifstream archivoEXM (nombre + ".exm");
    ifstream archivoSTU (nombre + ".stu");

    string lectura1;
    string lectura2;

    if (archivoEXM.is_open() && archivoSTU.is_open()){
        //Leera hasta dejar el archivo vacio
        while (archivoEXM >> lectura1 >> lectura2){
            examenes->push_back(stoi(lectura1));
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

vector<vector<int>> generarMatriz(vector<int> examenes){
    vector<vector<int>> conflictos;
}

float ultimoTimeslot(vector<int> x){
    int max = -1;
    for (auto i: x){
       if (i > max) max = i;
    }
    return max;
}

void escribirSalida(int ultimoTimeslot, vector<int> examenes, float penalizacion, vector<int> solucion){
    //Codigo donde sale todo bien, hay que ver la parte donde no se completa una solucion
    //quiza el greedy no encuentra solucion y hay que imprimir algo especial
    //TODO: Quizas tener un flag de si es abierto por segunda vez hacer apend a los archivos que estan aca

    ofstream dotRES ("PROBLEM.RES");
    ofstream dotSOL ("PROBLEMA.SOL");
    ofstream dotPEN ("PROBLEMA.PEN");

    dotRES << ultimoTimeslot;
    dotPEN << penalizacion;


    for (unsigned int i = 0; i < examenes.size(); i++){
        dotSOL << examenes[i] << " " << solucion[i] << endl;
    }

    dotRES.close();
    dotSOL.close();
    dotPEN.close();
}
