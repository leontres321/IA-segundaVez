#ifndef CLASS_H_
#define CLASS_H_
#include <iostream>
#include <vector>
/*
** "Clases"
 */
//*.exm
/*class Examen{
    public:
        int id;
        int cantAlumnos; //Necesario?
};
*/


//*.stu ... esta clase no es necesaria verdad? un vector de vectores y listo
class Alumno{
    public:
        std::string id;
        std::vector<int> examenes;
};

#endif // CLASS_H_
