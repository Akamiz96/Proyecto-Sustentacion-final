#include "Cadena.h"
#include <iostream>
//Ver si una cadena contiene un punto
bool PuntoEnCadena( char* cadena)
{
    while(*cadena!='\0')
    {
        if(*cadena=='.')
            return true;
        ++cadena;
    }
    return false;
}
//Compara dos cadenas si dos iguales SIN IMPORTAR mayus/minus
bool Comparar_sin(char* cadena1,char* cadena2)
{
    if(Contar(cadena1)!=Contar(cadena2))
        return false;
    else
    {
        while(*cadena1!='\0')
        {
            if(*cadena1!=*cadena2&&*cadena1-32!=*cadena2&&*cadena1!=*cadena2-32)
                return false;
            ++cadena1;
            ++cadena2;
        }
        return true;
    }
}
//Compara dos cadenas si dos cadenas IMPORTANDO mayus/minus
bool Comparar_con(char* cadena1,char* cadena2)
{
    if(Contar(cadena1)!=Contar(cadena2))
        return false;
    else
    {
        while(*cadena1!='\0')
        {
            if(*cadena1!=*cadena2)
                return false;
            ++cadena1;
            ++cadena2;
        }
        return true;
    }
}
//Cuenta cuantos caracteres hay en una cadena
int Contar (char* cadena)
{
    int i=0;
    while(*cadena!='\0')
    {
        ++cadena;
        ++i;
    }
    return i;
}
//Copia una cadena en una nueva (retorna esa nueva cadena)
char* Copiar(char* cadena)
{
    int i=0;
    char* nueva=new char[Contar(cadena)+1];
    while(*cadena!='\0')
    {
        *(nueva+i)=*cadena;
        ++cadena;
        ++i;
    }
    *(nueva+i)='\0';
    return nueva;
}
//Cambia las Mayus en Minus
void Cambio_a_minus(char * cadena)
{
    while(*cadena!='\0')
    {
        if(*cadena>='A'&&*cadena<='Z')
            *cadena=*cadena+32;
        ++cadena;
    }
}
//Quita los espacios de una cadena de caracteres
void Quitar_espacios(char* cadena)
{
    while(*cadena!='\0')
    {
        if(*cadena==' ')
        {
            char * aux=cadena;
            while(*aux!='\0')
            {
                *aux=*(aux+1);
                ++aux;
            }
        }
        ++cadena;
    }
}
//Corta la cadena por el espacio
//Deja un apuntador al principio y retorna el de la segunda cadena
//Si hay comillas separa por el espacio luego de las comillas
char * Cortar(char* palabra)
{
    bool comillas=true;
    char * pal;
    pal=palabra;
    while(*pal!=' '||!comillas)
    {
        if(*pal=='"'&&comillas)
            comillas=false;
        else if(*pal=='"')
            comillas=true;
        ++pal;
    }
    *pal='\0';
    ++pal;
    return pal;
}
//Quita las comillas de una cadena de caracteres
void Cortar_Comillas(char*& palabra)
{
    if(*palabra=='"')
    {
        palabra=palabra+1;
        *(palabra+Contar(palabra)-1)='\0';
    }
}
//Separa la cadena por el punto
//devuelve un apuntador a la siguiente letra luego del punto
char * Separar_Tipo(char * palabra)
{
    if(PuntoEnCadena(palabra))
    {
        while(*palabra!='.')
            ++palabra;
        *palabra='\0';
        return ++palabra;
    }
    return NULL;
}
//Busca si hay una letra dada en una cadena dada
bool Letra_en_Cadena (char * palabra,char Letra)
{
    while(*palabra!='\0')
    {
        if(*palabra==Letra)
            return true;
        ++palabra;
    }
    return false;
}
