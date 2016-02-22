#include <iostream>
#include <fstream>
#include <math.h>
#include <cstring>
#include<stdlib.h>
#include "Adicional.h"
using namespace std;
//Cuenta cuantos caracteres hay en la cadena
int tama(char* hola)
{
    int i=0;
    while(*(hola+i)!='\0')
        i++;
    return i;
}
//Convierte a un numero la cadena
int numero(char* info)
{
    int a, i=0;
    int tam = tama(info);
    for(int j=0; j<tam; j++)
    {
        a=((int)*(info+j))-48;
        i*=10;
        i =(i +a);
    }
    return i;
}
//Retorna el valor superior derecho de la hoja de calculo
int SupDerecha(char * lect)
{
    ifstream lectura(lect,ios :: in);
    char * ptr;
    char *supDerecha = new char [300];
    char * linea = new char [300];
    int supDerechaint;
    lectura.seekg(0,ios::beg);
    lectura.getline(linea,300);
    ptr = strtok(linea," ");
    while(ptr != NULL)
    {
        supDerecha=ptr;
        ptr = strtok(NULL, " ");
    }
    supDerechaint=numero(supDerecha);
    delete []supDerecha;
    delete []linea;
    return supDerechaint;
}
//Retorna el valor superior izquierda de la hoja de calculo
int SupIzquierda(char* lect)
{
    ifstream lectura(lect,ios :: in);
    char* supIzquierda=new char[5];
    int supIzquierdaint;
    lectura>>supIzquierda;
    supIzquierdaint=numero(supIzquierda);
    delete []supIzquierda;
    return supIzquierdaint;

}
//Retorna el valor inferior derecho de la hoja de calculo
int InfDerecha(char* lect)
{

    ifstream lectura(lect,ios :: in);
    char * linea1=new char [500];
    char * linea2=new char [500];
    int infDerechaint;
    while(lectura>>linea1)
    {
    }
    infDerechaint=numero(linea1);
    delete []linea1;
    delete []linea2;
    return infDerechaint;

}
//Retorna el valor inferior izquierdo de la hoja de calculo
int InfIzquierda(char * lect)
{
    ifstream lectura(lect,ios :: in);
    lectura.seekg(0,ios::beg);
    char * linea1=new char [500];
    char * linea2=new char [500];
    char* leer= new char [500];
    int infIzquierdaint;
    while(lectura>>leer)
    {
        lectura.getline(linea1,500);

    }
    infIzquierdaint=numero(leer);
    delete []leer;
    delete []linea1;
    delete []linea2;
    lectura.seekg(0,ios::beg);
    return infIzquierdaint;
}
//Retorna el valor de la sumatoria de la fila entre 2
int FilaEntre2(char * lect)
{
    ifstream lectura(lect,ios :: in);
    int fil=0;
    char* leer =new char [10];
    char* linea =new char [200];
    while(lectura>>leer)
    {
        lectura.getline(linea,200);
        fil++;
    }
    if(fil%2!=0)
        fil++;
    fil=fil/2;
    delete [] leer;
    delete [] linea;
    return fil;
}
//Retorna el valor de la sumatoria de la columna entre 2
int ColumnaEntre2(char * lect)
{
    ifstream lectura(lect,ios :: in);
    int col=0;
    char* ptr;
    char* linea =new char [500];
    lectura.getline(linea,500);
    ptr = strtok(linea," ");
    while(ptr != NULL)
    {
        col++;
        ptr = strtok(NULL, " ");
    }
    if(col%2!=0)
        col++;
    col=col/2;
    delete [] linea;
    return col;
}

int Dato(int fila,int columna,char * lect)
{
    ifstream lectura(lect,ios :: in);
    char* linea =new char [500];
    int num;
    for(int i =1; i < fila; i++)
    {
        lectura.getline(linea,500);
    }
    for(int j=1; j<columna; j++)
    {
        lectura>>linea;
    }
    lectura>>linea;
    num = numero(linea);
    delete []linea;
    lectura.close();
    return num;
}
//pone el apuntador del archivo en la hoja a culcular
void posicion(ifstream& lectura, int hoja)
{
    char* linea=new char [600];
    int columnas,filas;
    lectura.seekg(0,ios::beg);
    lectura.getline(linea,600);
    if(hoja>1)
    {
        for(int p=0; p<hoja-1; p++)
        {
            lectura>>linea;
            columnas = numero(linea) ;
            lectura>>linea;
            filas = numero(linea);

            for(int j=0; j<=filas; j++)
            {
                lectura.getline(linea,600);
            }

        }
    }
    delete []linea;
}
//recibe A B... AA BB.. ZZ AAA AAB.. ZZZ y lo transforma en un numero
int columna (char*formula)
{
    int tam,num;
    tam=tama(formula);

    if(tam==1)
    {
        num=(*formula-64);
    }
    if(tam==2)
    {
        num=(((*formula)-64)*26)+(*(formula+1)-64);
    }
    if(tam==3)
    {
        num=(*formula-64)*26*26+26*(*(formula+1)-64)+*(formula+2)-64;
    }
    return num;

}
// Calcula y Retorna el entero de la formula (info)
int BuscarValorEc(ifstream&lectura, ofstream &fina,char*info,int hoja)
{
    info++;
    char *suma [70];
    char * ptr ;
    char * formula= new char [500];
    char * col = new char [200];
    char * fil;
    int fila,j,columnaa,val=0,sum[70];
    ptr = strtok(info,"+");
    int i=0;
    while(ptr != NULL)
    {
        suma[i] = ptr;
        ptr = strtok(NULL, "+");
        i++;
    }
    for(int m=0; m<i; m++)
    {
        posicion(lectura,hoja);
        lectura.getline(formula,200);
        j=0;
        fil=col= suma[m];
        while(58< *(fil) ||*(fil)< 47)
        {
            fil++;
        }
        while( *(fil+j)!= '\0')
        {
            *(formula+j)= *(fil+j);
            j++;
        }
        *(formula+j)='\0';
        *fil='\0';
        fil=formula;
        fila=numero(fil);
        columnaa=columna(col);
        for(int k=1; k<fila; k++)
        {
            lectura.getline(formula,200);
        }
        for(int p=1; p<columnaa; p++)
        {
            lectura>>formula;
        }
        lectura>>formula;
        if(*formula!='=')
        {
            sum[m]=numero(formula);
        }
        else
        {
            sum[m]=BuscarValorEc(lectura,fina,formula,hoja);
        }
    }
    for(int o=0; o<i; o++)
    {
        val =val +sum[o];
    }
    delete []suma;
    delete []formula;
    delete []col;
    delete []ptr ;
    return val;

}
//Calcula y resuelve la hoja de calculo SOLAMENTE UNA HOJA
void calcular(ifstream& lectura,  ofstream &fina,int hojas,int leid)
{
    char* info=new char [300];
    posicion(lectura,hojas);
    lectura.getline(info,300);
    for(int u=0; u<leid; u++)
        lectura>>info;
    lectura>>info;
    if(*info!='=')   // pregunta si es un numero o una formula la que se añade
        fina<<numero(info);  //Si es un numero se convierte a entero y se impime en el archivo
    else
        fina<<BuscarValorEc(lectura,fina,info,hojas); //si es una formula, se llama a la funcion quereturna el entero del calculo de la formula
    delete [] info;
}
//Calcula todas la HOJAS
void CalcularTodasLasHojas(char * ruta, Nodo* Lala) // RECIBIR NODO *
{
    int hojas,columnas,filas,leido;
    ifstream lectura(ruta);
    ofstream fina;
    char* linea=new char [300];
    char* numeroo= new char[10];
    char* nombre = new char [30];
    lectura>>hojas;
    int l= 0;
    while(*(ruta+l)!='.')
    {
        l++;
    }
    *(ruta+l)='\0';
    for(int u =1; u<=hojas; u++)
    {
        leido=0;
        strcpy(nombre,ruta);
        itoa(u,numeroo,10);
        strcat(numeroo,".txt");
        strcat(nombre,numeroo);
        fina.open(nombre,ios::out);
        posicion(lectura,u);
        lectura>>columnas;
        lectura>>filas;
        for(int i=0; i<filas; i++)
        {
            for(int j=0; j<columnas; j++)
            {
                calcular(lectura,fina,u,leido);
                fina<<" ";
                leido++;
            }
            fina<<endl;
        }
        Agregar(Lala,nombre); // Mi funcion.
        fina.close();
    }
    delete [] linea;
    delete [] numeroo;
    delete [] nombre;
    lectura.close();
}
//Retorna la Cantidad de hojas de calculo en un archivo
int Cantidad_Hojas(char* ruta)
{
    ifstream archivo(ruta);
    int i;
    archivo >> i;
    archivo.close();
    return i;
}
//Calcula la suma de la fila dada en el archivo
int Calcular_Fila(char * Archivo, int fila)
{
    ifstream lectura(Archivo,ios :: in);
    char * linea =new char[100];
    int SumaFila=0,i=0;
    while(lectura.getline(linea,100)&&i<fila-1)
        i++;
    if(i<=fila)
    {
        char* aux=linea;
        while(*linea!='\0')
        {
            while(*aux!=' ')
                aux++;
            *aux='\0';
            aux++;
            SumaFila+=numero(linea);
            linea=aux;
        }
        return SumaFila;
    }
    else
        return 0;
    delete []linea;
    lectura.close();
}
//Calcula la suma de una columna dada
int Calcular_Columna(char * Archivo, int Columna)
{
    ifstream lectura(Archivo,ios :: in);
    char * linea =new char[100];
    char*aux;
    int i,Suma_Columna=0;
    while(lectura.getline(linea,100))
    {
        i=0;
        aux=linea;
        while(i<Columna)
        {
            while(*aux!=' '||*aux=='\0')
                ++aux;
            i++;
            linea=aux-1;
        }
        *aux='\0';
        Suma_Columna+=numero(linea);
    }
    return Suma_Columna;
    lectura.close();
    delete [] linea;
}
