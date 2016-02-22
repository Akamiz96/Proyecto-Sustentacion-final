#ifndef HOJADECALCULO_H_INCLUDED
#define HOJADECALCULO_H_INCLUDED
#include "Adicional.h"
//Cuenta cuantos caracteres hay en la cadena
int tama(char* hola);
//Convierte a un numero la cadena
int numero(char* info);
//Retorna el valor superior derecho de la hoja de calculo
int SupDerecha(char * lect);
//Retorna el valor superior izquierda de la hoja de calculo
int SupIzquierda(char* lect);
//Retorna el valor inferior derecho de la hoja de calculo
int InfDerecha(char* lect);
//Retorna el valor inferior izquierdo de la hoja de calculo
int InfIzquierda(char * lect);
//Retorna el valor de la sumatoria de la fila entre 2
int FilaEntre2(char * lect);
//Retorna el valor de la sumatoria de la columna entre 2
int ColumnaEntre2(char * lect);

int Dato(int fila,int columna,char * lect);
//pone el apuntador del archivo en la hoja a culcular
void posicion(ifstream& lectura, int hoja);
//recibe A B... AA BB.. ZZ AAA AAB.. ZZZ y lo transforma en un numero
int columna (char*formula);
// Calcula y Retorna el entero de la formula (info)
int BuscarValorEc(ifstream&lectura, ofstream &fina,char*info,int hoja);
//Calcula y resuelve la hoja de calculo SOLAMENTE UNA HOJA
void calcular(ifstream& lectura,  ofstream &fina,int hojas,int leid);
//Calcula todas la HOJAS
void CalcularTodasLasHojas(char * ruta,Nodo* Lala); // RECIBIR NODO *
//Retorna la Cantidad de hojas de calculo en un archivo
int Cantidad_Hojas(char* ruta);
//Calcula la suma de la fila dada en el archivo
int Calcular_Fila(char * Archivo, int fila);
//Calcula la suma de una columna dada
int Calcular_Columna(char * Archivo, int Columna);
#endif // HOJADECALCULO_H_INCLUDED
