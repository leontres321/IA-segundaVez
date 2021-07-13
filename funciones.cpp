#include <iostream>
#include <fstream>
#include <math.h>
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

vector<vector<int>> generarMatriz(vector<int> examenes,
                                  vector<Alumno> alumnos){
    vector<int> listaExamenes (examenes.size());
    vector<vector<int>> conflictos (examenes.size(), listaExamenes);
    int index1, index2;

    //not nice
    for (auto x: alumnos){
        for (auto exm: x.examenes){
            index1 = encontrarIndex(examenes, exm);
            for (auto exm2: x.examenes){
                if (exm != exm2){
                    index2 = encontrarIndex(examenes, exm2);
                    conflictos[index1][index2] = 1;
                    conflictos[index2][index1] = 1;
                }
            }
        }
    }

    return conflictos;
}

int ultimoTimeslot(vector<int> x){
    int W = -1;
    for (unsigned int i = 0; i < x.size(); i++){
       if (x[i] > W) W = x[i];
    }
    return W;
}

void escribirSalida(int ultimoTimeslot, vector<int> examenes, float descontento, vector<int> solucion){
    //Codigo donde sale todo bien, hay que ver la parte donde no se completa una solucion
    //quiza el greedy no encuentra solucion y hay que imprimir algo especial
    //TODO: Quizas tener un flag de si es abierto por segunda vez hacer apend a los archivos que estan aca

    ofstream dotRES ("PROBLEM.RES");
    ofstream dotSOL ("PROBLEM.SOL");
    ofstream dotPEN ("PROBLEM.PEN");

    dotRES << ultimoTimeslot;
    dotPEN << descontento;


    for (unsigned int i = 0; i < examenes.size(); i++){
        dotSOL << examenes[i] << " " << solucion[i] << endl;
    }

    dotRES.close();
    dotSOL.close();
    dotPEN.close();
}

int encontrarIndex(vector<int> examenes, int codigo){
    for (unsigned int i = 0; i < examenes.size(); i++){
        if (codigo == examenes[i]) return i;
    }
    // podria poner un codigo mas decente
    return -1;
}

float calcularDescontento(vector<int> solucion, vector<int> examenes, vector<Alumno> alumnos){
    float descontento = 0;
    int indexExamen1, indexExamen2, slot1, slot2, diferencia;

    for (auto x: alumnos){
        if (x.examenes.size() > 1){
            for (unsigned int i = 0; i < x.examenes.size(); i++){
                indexExamen1 = encontrarIndex(examenes, x.examenes[i]);
                slot1 = solucion[indexExamen1];
                for (unsigned int j = i + 1; j < x.examenes.size(); j++){
                    indexExamen2 = encontrarIndex(examenes, x.examenes[j]);
                    slot2 = solucion[indexExamen2];
                    diferencia = abs(slot1-slot2);

                    if (diferencia >= 1 && diferencia <= 5){
                        descontento += pow(2, 5 - diferencia);
                    }

                }
            }
        }
    }
    return descontento/alumnos.size();
}
