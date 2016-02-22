#include <iostream>
#include <cstring>
#include <fstream>
#include "HojaDeCalculo.h"
#include "Lista.cpp"
#include "Adicional.h"
#include "Cadena.h"
using namespace std;
Nodo* Crear_Disco (char* Archivo)
{
    ifstream archivo(Archivo);
    if(archivo.fail())
        cout << "No Se Abrio el archivo del Disco" << endl;
    else
    {
        char* linea=new char[100];
        archivo.getline(linea,100);
        char* carpeta = Cortar(linea);
        Nodo* Disco = ArmaNodo(carpeta);
        Nodo* Agrega = ArmaNodo(linea);
        Nodo* Guardado=Insertar_Nodo(Disco->Nombre,*Agrega);
        Insertar_Nodo_Tipo(Disco->Tipo,Guardado);
        Recursion_Crear_Disco(archivo,Disco,Archivo);
        archivo.close();
        return Disco;
    }
    return NULL;
}
void Recursion_Crear_Disco(ifstream & archivo, Nodo* Disco,char* &Archivo)
{
    char* linea =new char [100];
    int i=2;
    TList<int>*Lista_No_Encontrados=create_list<int>();
    while(archivo.getline(linea,100))
    {
        char* carpeta=Cortar(linea);
        Cortar_Comillas(carpeta);
        Nodo* Agrega=ArmaNodo(linea);
        Nodo* Donde_Agregar=Buscar_en_Disco(Disco,carpeta,"");
        if(Donde_Agregar!=NULL)
        {
            Nodo* Guardado=Insertar_Nodo(Donde_Agregar->Nombre,*Agrega);
            Insertar_Nodo_Tipo(Donde_Agregar->Tipo,Guardado);
        }
        else
            Push_back(Lista_No_Encontrados,i);
        ++i;
    }
    while(!IsEmpty(Lista_No_Encontrados))
        Buscar_No_Encontrados(Lista_No_Encontrados,Disco,Archivo);
    archivo.close();
}
void Buscar_No_Encontrados(TList<int>*Lista,Nodo* Disco,char* &Archivo)
{
    char* linea;
    for(Gofirst(Lista); !isEnd(Lista); Gonext(Lista))
    {
        ifstream archivo(Archivo);
        linea=new char[100];
        for(int i=0; i<Lista->window->info; i++)
            archivo.getline(linea,100);
        char* carpeta=Cortar(linea);
        Cortar_Comillas(carpeta);
        Nodo* Agrega=ArmaNodo(linea);
        Nodo* Donde_Agregar=Buscar_en_Disco(Disco,carpeta,"");
        if(Donde_Agregar!=NULL)
        {
            Nodo* Guardado=Insertar_Nodo(Donde_Agregar->Nombre,*Agrega);
            Insertar_Nodo_Tipo(Donde_Agregar->Tipo,Guardado);
            Erase(Lista);
            Lista->window=NULL;
        }
        delete [] linea;
        archivo.close();
    }
}
//Imprime la lista por NOMBRE
void Imprimir_Lista_MenoraMayorN(Nodo* Disco)
{
    if(Disco!=NULL)
    {
        cout <<"Ubicacion actual: "<< Disco->nombre;
        if(Disco->tipo!="")
            cout << "."<<Disco->tipo;
        cout << endl;
        for(Gofirst(Disco->Nombre); !isEnd(Disco->Nombre); Gonext(Disco->Nombre))
        {
            for(int j=0; j<21; j++)
                cout << " ";
            cout << Disco->Nombre->window->info.nombre;
            if(Disco->Nombre->window->info.tipo!="")
                cout << "."<<Disco->Nombre->window->info.tipo;
            cout << endl;
        }
    }
    else
    {
        cout << "\n======================================================\n";
        cout << "La ubicacion actual no es valida.\n";
        cout << "\n======================================================\n";
    }
}
//Imprime la lista por NOMBRE
void Imprimir_Lista_MayoraMenorN(Nodo* Disco)
{
    if(Disco!=NULL)
    {
        cout <<"Ubicacion actual: "<< Disco->nombre;
        if(Disco->tipo!="")
            cout << "."<<Disco->tipo;
        cout << endl;
        for(Golast(Disco->Nombre); !isEnd(Disco->Nombre); Goprev(Disco->Nombre))
        {
            for(int j=0; j<21; j++)
                cout << " ";
            cout << Disco->Nombre->window->info.nombre;
            if(Disco->Nombre->window->info.tipo!="")
                cout << "."<<Disco->Nombre->window->info.tipo;
            cout << endl;
        }
    }
    else
    {
        cout << "\n======================================================\n";
        cout << "La ubicacion actual no es valida.\n";
        cout << "\n======================================================\n";
    }
}
//Imprime la Totalidad del disco por NOMBRE de MENOR a MAYOR
void Imprimir_Disco_MenoraMayorN(Nodo* Disco,int i)
{
    for(int j=0; j<i; j++)
        cout << " ";
    cout << Disco->nombre;
    if(Disco->tipo!="")
        cout << "."<<Disco->tipo;
    cout << endl;
    for(Gofirst(Disco->Nombre); !isEnd(Disco->Nombre); Gonext(Disco->Nombre))
    {
        if(!IsEmpty(Disco->Nombre->window->info.Nombre))
            Imprimir_Disco_MenoraMayorN(&Disco->Nombre->window->info,i+3);
        else
        {
            for(int j=0; j<i+3; j++)
                cout << " ";
            cout << Disco->Nombre->window->info.nombre;
            if(Disco->Nombre->window->info.tipo!="")
                cout << "."<<Disco->Nombre->window->info.tipo;
            cout << endl;
        }
    }
}
//Imprime la Totalidad del disco por NOMBRE de MAYOR a MENOR
void Imprimir_Disco_MayoraMenorN(Nodo* Disco,int i)
{
    for(int j=0; j<i; j++)
        cout << " ";
    cout << Disco->nombre;
    if(Disco->tipo!="")
        cout << "."<<Disco->tipo;
    cout << endl;
    for(Golast(Disco->Nombre); !isEnd(Disco->Nombre); Goprev(Disco->Nombre))
    {
        if(!IsEmpty(Disco->Nombre->window->info.Nombre))
            Imprimir_Disco_MayoraMenorN(&Disco->Nombre->window->info,i+3);
        else
        {
            for(int j=0; j<i+3; j++)
                cout << " ";
            cout << Disco->Nombre->window->info.nombre;
            if(Disco->Nombre->window->info.tipo!="")
                cout << "."<<Disco->Nombre->window->info.tipo;
            cout << endl;
        }
    }
}
//Imprime la Totalidad del disco por TIPO de MENOR a MAYOR
void Imprimir_Disco_Tipo_MenoraMayorT(Nodo* Disco,int i)
{
    for(int j=0; j<i; j++)
        cout << " ";
    cout << Disco->nombre;
    if(Disco->tipo!="")
        cout << "."<<Disco->tipo;
    cout << endl;
    for(Gofirst(Disco->Tipo); !isEnd(Disco->Tipo); Gonext(Disco->Tipo))
    {
        if(!IsEmpty(Disco->Tipo->window->info->Tipo))
            Imprimir_Disco_Tipo_MenoraMayorT(Disco->Tipo->window->info,i+3);
        else
        {
            for(int j=0; j<i+3; j++)
                cout << " ";
            cout << Disco->Tipo->window->info->nombre;
            if(Disco->Tipo->window->info->tipo!="")
                cout << "."<<Disco->Tipo->window->info->tipo;
            cout << endl;
        }
    }
}
//Imprime la Totalidad del disco por TIPO de MAYOR a MENOR
void Imprimir_Disco_Tipo_MayoraMenorT(Nodo* Disco,int i)
{
    for(int j=0; j<i; j++)
        cout << " ";
    cout << Disco->nombre;
    if(Disco->tipo!="")
        cout << "."<<Disco->tipo;
    cout << endl;
    for(Golast(Disco->Tipo); !isEnd(Disco->Tipo); Goprev(Disco->Tipo))
    {
        if(!IsEmpty(Disco->Tipo->window->info->Tipo))
            Imprimir_Disco_Tipo_MayoraMenorT(Disco->Tipo->window->info,i+3);
        else
        {
            for(int j=0; j<i+3; j++)
                cout << " ";
            cout << Disco->Tipo->window->info->nombre;
            if(Disco->Tipo->window->info->tipo!="")
                cout << "."<<Disco->Tipo->window->info->tipo;
            cout << endl;
        }
    }
}
//Imprime la lista por TIPO
void Imprimir_Lista_MayoraMenorT(Nodo* Disco)
{
    if(Disco!=NULL)
    {
        cout <<"Ubicacion actual: "<< Disco->nombre;
        if(Disco->tipo!="")
            cout << "."<<Disco->tipo;
        cout << endl;
        for(Golast(Disco->Tipo); !isEnd(Disco->Tipo); Goprev(Disco->Tipo))
        {
            for(int j=0; j<10; j++)
                cout << " ";
            cout << Disco->Tipo->window->info->nombre;
            if(Disco->Tipo->window->info->tipo!="")
                cout << "."<<Disco->Tipo->window->info->tipo;
            cout << endl;
        }
    }
    else
    {
        cout << "\n======================================================\n";
        cout << "La ubicacion actual no es valida.\n";
        cout << "\n======================================================\n";
    }
}
//Imprime la lista por TIPO
void Imprimir_Lista_MenoraMayorT(Nodo* Disco)
{
    if(Disco!=NULL)
    {
        cout <<"Ubicacion actual: "<< Disco->nombre;
        if(Disco->tipo!="")
            cout << "."<<Disco->tipo;
        cout << endl;
        for(Gofirst(Disco->Tipo); !isEnd(Disco->Tipo); Gonext(Disco->Tipo))
        {
            for(int j=0; j<10; j++)
                cout << " ";
            cout << Disco->Tipo->window->info->nombre;
            if(Disco->Tipo->window->info->tipo!="")
                cout << "."<<Disco->Tipo->window->info->tipo;
            cout << endl;
        }
    }
    else
    {
        cout << "\n======================================================\n";
        cout << "La ubicacion actual no es valida.\n";
        cout << "\n======================================================\n";
    }
}
//Arma el NODO
Nodo* ArmaNodo (char* nombre)
{
    Cortar_Comillas(nombre);
    Nodo * nuevo = new Nodo;
    if(PuntoEnCadena(nombre))
    {
        string tipo = Separar_Tipo(nombre);
        nuevo->tipo=tipo;
    }
    nuevo->nombre=nombre;
    nuevo->Nombre=create_list<Nodo>();
    nuevo->Tipo=create_list<Nodo*>();
    return nuevo;
}
//Agrega a la lista correspondiente el nodo dado
void Agregar (Nodo* Disco, char* linea)
{
    Nodo* Agrega = ArmaNodo(linea);
    Nodo* Guardado=Insertar_Nodo(Disco->Nombre,*Agrega);
    Insertar_Nodo_Tipo(Disco->Tipo,Guardado);
    delete Agrega;
}
//Busca el Nodo correspondiente al nombre y al tipo dado
//Retorna el apuntador a ese Nodo
//RECURSIVA y BINARIA
Nodo* Buscar_en_Lista(TList<Nodo>*Lista,string nombre,string tipo)
{
    TLNode<Nodo>* middle = Middle(Lista);
    if(Lista->first==NULL||Lista->last==NULL||middle==NULL)
        return NULL;
    if(middle->info.nombre==nombre&&middle->info.tipo==tipo)
        return &(middle->info);
    if(Lista->first->info.nombre==nombre&&Lista->first->info.tipo==tipo)
        return &(Lista->first->info);
    if(middle==Lista->first)
        return NULL;
    if(Lista->first==Lista->last)
        return NULL;
    TList<Nodo>*Lista2 =create_list<Nodo>();
    if(nombre<middle->info.nombre)
    {
        Lista2->first=Lista->first->next;
        Lista2->last=middle->prev;
    }
    else
    {
        Lista2->first=middle->next;
        Lista2->last=Lista->last;
    }
    return Buscar_en_Lista(Lista2,nombre,tipo);
}
//Busqueda del Nodo con nombre y tipo dados
//RECURSIVA
Nodo* Buscar_en_Disco(Nodo* Disco,string nombre,string tipo)
{
    Nodo* Busqueda=Buscar_en_Lista(Disco->Nombre,nombre,tipo);
    if(Busqueda!=NULL)
        return Busqueda;
    if(Disco->nombre==nombre&&Disco->tipo==tipo)
        return Disco;
    else
    {
        for(Gofirst(Disco->Nombre); !isEnd(Disco->Nombre); Gonext(Disco->Nombre))
        {
            if(!IsEmpty(Disco->Nombre->window->info.Nombre))
            {
                Busqueda= Buscar_en_Disco(&(Disco->Nombre->window->info),nombre,tipo);
                if(Busqueda!=NULL)
                    return Busqueda;
            }
        }
    }
    return NULL;
}
//Deja Window de la Lista en la posicion donde se debe insertar el nombre
//INSERTAR: ANTES DE LA VENTANA
//SEGUN NOMBRE
void Buscar_Insertar(TList<Nodo>*Lista,string nombre)
{
    for(Gofirst(Lista); !isEnd(Lista); Gonext(Lista))
    {
        if(Lista->window->info.nombre>nombre)
            break;
    }
}
//Deja Window de la Lista en la posicion donde se debe insertar el tipo
//INSERTAR: ANTES DE LA VENTANA
//SEGUN TIPO
void Buscar_Insertar_Tipo(TList<Nodo*>*Lista,string tipo)
{
    for(Gofirst(Lista); !isEnd(Lista); Gonext(Lista))
    {
        if(Lista->window->info->tipo>tipo)
            break;
    }
}
//Inserta NODO en la lista
// Se compara el nombre y se retorna la direccion para el procedimiento de la lista por tipo
Nodo* Insertar_Nodo(TList<Nodo>*Lista,Nodo Insertar)
{
    Buscar_Insertar(Lista,Insertar.nombre);
    if(Lista->window==NULL)
        Push_back(Lista,Insertar);
    else
        Insert(Lista,Insertar);
    return &(Lista->window->info);
}
//Inserta NODO en la lista por tipo
void Insertar_Nodo_Tipo(TList<Nodo*>*Lista,Nodo * Insertar)
{
    Buscar_Insertar_Tipo(Lista,Insertar->tipo);
    if(Lista->window==NULL)
        Push_back(Lista,Insertar);
    else
        Insert(Lista,Insertar);
}
//BIENVENIDO HAIRY PETER S.A.
void Encabezado()
{
    cout << "*******************************************************************************\n";
    cout << "-------------------------------------------------------------------------------\n";
    cout << "+++++++++++++++++++++++++++++++++++BIENVENIDO++++++++++++++++++++++++++++++++++\n";
    cout << "-------------------------------------------------------------------------------\n";
    cout << "*******************************************************************************\n";
    cout << "-------------------------------------------------------------------------------\n";
    cout << "================================HAIRY PETER S.A.===============================\n";
    cout << "-------------------------------------------------------------------------------\n";
    cout << "*******************************************************************************\n";
}
//Plantilla del reporte a imprimir
void Reporte(char* Archivo_Nombres,char* ArchivoaAbrir,Nodo* Usuario,int Fila, int Columna)
{
    ifstream Nombres(Archivo_Nombres);
    char* Nombre=new char[300];
    char Letra;
    cout <<"Digite la letra de la cual no quiere que se generen reportes: ";
    cin>> Letra;
    cin.ignore();
    while(Nombres.getline(Nombre,300))
    {
        if(!Letra_en_Cadena(Nombre,Letra))
        {
            char* Nom=Copiar(Nombre);
            Quitar_espacios(Nombre);
            Cambio_a_minus(Nombre);
            strcat(Nombre,".txt");
            ofstream Report(Nombre);
            Report << "HAIRY PETER S.A."<<endl;
            Report << Nom << endl;
            Report << "Ciudad" << endl<<endl;
            Report << "  Despues de un analisis detallado de cada movimiento efectivo realizado en la"<<endl;
            Report << SupDerecha(ArchivoaAbrir) << " semana se obtuvieron los siguientes datos: "<<endl<<endl<<endl;
            Report << "\tUnidades producidas: "<<InfDerecha(ArchivoaAbrir)<<endl;
            Report << "\tUnidades vendidas: "<<SupIzquierda(ArchivoaAbrir)<<endl;
            Report << "\tUtilidad Operacional: "<<InfIzquierda(ArchivoaAbrir)<<endl;
            Report << "\tUtilidad neta: "<< Dato(FilaEntre2(ArchivoaAbrir),ColumnaEntre2(ArchivoaAbrir),ArchivoaAbrir)<<endl;
            Report <<"\tSuma Ventas Netas(Suma Fila): "<<Calcular_Fila(ArchivoaAbrir,Fila)<< endl;
            Report <<"\tGastos Netos (Suma Columna): "<<Calcular_Columna(ArchivoaAbrir,Fila)<< endl<<endl;
            Report << "Cordial Saludo,"<<endl<<endl;
            Report <<"Departamento de Finanzas"<<endl;
            Report.close();
            Agregar(Usuario,Nombre);
        }
        else
        {
            cout << "\n\n*******************************************************************************\n";
            cout << "No se genero el reporte de: " << Nombre << endl;
            cout << "*******************************************************************************\n\n\n";
        }
    }
}
