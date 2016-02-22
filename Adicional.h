#ifndef ADICIONAL_H_INCLUDED
#define ADICIONAL_H_INCLUDED
#include "lista.h"
//NODO del sistema
struct Nodo
{
    string nombre;
    string tipo;
    TList<Nodo>*Nombre;
    TList<Nodo*>*Tipo;
};
Nodo* Crear_Disco (char* Archivo);
void Recursion_Crear_Disco(ifstream & archivo, Nodo* Disco,char* &Archivo);
void Buscar_No_Encontrados(TList<int>*Lista,Nodo* Disco,char* &Archivo);
//Imprime la lista por NOMBRE
void Imprimir_Lista_MenoraMayorN(Nodo* Disco);
void Imprimir_Lista_MayoraMenorN(Nodo* Disco);
//Imprime la Totalidad del disco por NOMBRE de MENOR a MAYOR
void Imprimir_Disco_MenoraMayorN(Nodo* Disco, int i);
//Imprime la Totalidad del disco por NOMBRE de MAYOR a MENOR
void Imprimir_Disco_MayoraMenorN(Nodo* Disco,int i);
//Imprime la Totalidad del disco por TIPO de MENOR a MAYOR
void Imprimir_Disco_Tipo_MenoraMayorT(Nodo* Disco,int i);
//Imprime la Totalidad del disco por TIPO de MAYOR a MENOR
void Imprimir_Disco_Tipo_MayoraMenorT(Nodo* Disco, int i);
//Imprime la lista por TIPO
void Imprimir_Lista_MayoraMenorT(Nodo* Disco);
void Imprimir_Lista_MenoraMayorT(Nodo* Disco);
//Arma el NODO
Nodo* ArmaNodo (char* nombre);
//Agrega a la lista correspondiente el nodo dado
void Agregar (Nodo* Disco, char* linea);
//Busca el Nodo correspondiente al nombre dado
//Retorna el apuntador a ese Nodo
//RECURSIVA y BINARIA
Nodo* Buscar_en_Lista(TList<Nodo>*Lista,string nombre, string tipo);
//Busqueda del Nodo con nombre y tipo dados
//RECURSIVA
Nodo* Buscar_en_Disco(Nodo* Disco,string nombre,string tipo);
//Deja Window de la Lista en la posicion donde se debe insertar el nombre
//INSERTAR: ANTES DE LA VENTANA
//SEGUN NOMBRE
void Buscar_Insertar(TList<Nodo>*Lista,string nombre);
//Deja Window de la Lista en la posicion donde se debe insertar el tipo
//INSERTAR: ANTES DE LA VENTANA
//SEGUN TIPO
void Buscar_Insertar_Tipo(TList<Nodo*>*Lista,string tipo);
//Inserta NODO en la lista
// Se compara el nombre y se retorna la direccion para el procedimiento de la lista por tipo
Nodo* Insertar_Nodo(TList<Nodo>*Lista,Nodo Insertar);
//Inserta NODO en la lista por tipo
void Insertar_Nodo_Tipo(TList<Nodo*>*Lista,Nodo* Insertar);
//BIENVENIDO HAIRY PETER S.A.
void Encabezado();
//Plantilla del reporte a imprimir
void Reporte(char* Archivo_Nombres,char* ArchivoaAbrir,Nodo* Usuario,int Fila, int Columna);
#endif // ADICIONAL_H_INCLUDED
