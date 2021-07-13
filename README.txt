*******************
Archivos .stu y .exm deben estar en el mismo directorio y poseer el mismo nombre
*******************

** Como ejecutar **
- make run CASE=<path-to-file> DEBUG=-n TIME=<tiempo> TEMP=<temperatura> ALPHA=<alpha> ITER=<iteraciones>
- ./out <path-to-file> -n <tiempo> <temperatura> <alpha> <iteraciones>

** Compilar **
- make

** Borrar archivos **
- make delete: elimina el ejecutable y archivos de salida
- make clean: elimina archivos de compilacion
