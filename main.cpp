#include <iostream>
#include <cstring>
#include "Lista.cpp"
#include "Adicional.h"
#include "Cadena.h"
#include "HojaDeCalculo.h"
using namespace std;
/*
 Realizado por Magda Mejia Torres y Alejandro Castro Martinez
 NOTAS:
    -> Se recibe como parametro del Main la ruta del archivo de texto que contine la estructura del Disco a reconstruir
        *Dicho Archivo 'debe' tener en su primera linea el nombre de una carpeta y el nombre del Disco Duro que se trabajara
            durante todo el programa
    -> Al calcular las Hojas de Calculo se generan tantos archivos calculados como Hojas a calcular haya en el Archivo original
        *Se generaran con consecutivos empezando desde el 0 hasta n
    -> A pesar de generarse un disco duro "Artificial" en memoria, LOS ARCHIVOS QUE SE VANA A ABRIR DEBEN DE ESTAR
        EN LA MISMA CARPETA DONDE SE CORRE EL PROGRAMA.
    -> Las Busquedas son binarias y recursivas
    -> Los metodos de impresion de Disco son recursivos
*/
int main(int argc,char* argv[])
{
    Encabezado();
    Nodo* Disco=Crear_Disco(argv[1]);
    TList <Nodo*> *Usuario=create_list<Nodo*>();
    if(Disco!=NULL)
    {
        Push_back(Usuario,Disco);
        int opcion;
        char salida='n';
        cout << "Favor Ingresar la opcion deseada:\n";
        cout << "Ingrese el numero 0 para obtener ayuda.\n----> ";
        cin >> opcion;
        cin.ignore();
        do
        {
            switch(opcion)
            {
            case 0:
            {
                cout <<"-------------------------------------------------------------------------------\n";
                cout << "---------------------------------HELP------------------------------------------\n";
                cout <<"-------------------------------------------------------------------------------\n";
                cout << "\tOpcion 1: Imprimir Disco.\n";
                cout << "\tOpcion 2: Imprimir Archivos/Carpetas de la Carpeta actual.\n";
                cout << "\tOpcion 3: Calcular Hoja de Calculo.\n";
                cout << "\tOpcion 4: Generar reporte.\n";
                cout << "\tOpcion 5: Buscar Archivo/Carpeta en la Carpeta actual.\n";
                cout << "\tOpcion 6: Buscar Archivo/Carpeta en el Disco.\n";
                cout << "\tOpcion 7: Agregar Archivo/Carpeta en la Carpeta actual.\n";
                cout << "\tOpcion 8: Agregar Archivo/Carpeta en el Disco.\n";
                cout << "\tOpcion 9: Salir de Carpeta actual.\n";
                cout <<"-------------------------------------------------------------------------------\n";
                cout <<"-------------------------------------------------------------------------------\n";
                break;
            }
            case 1:
            {
                cout <<"\n-------------------------------------------------------------------------------\n";
                cout << "\tOpcion 1: Imprimir Disco.\n";
                cout <<"-------------------------------------------------------------------------------\n";
                if(Disco!=NULL)
                {
                    char opcion2;
                    cout <<"Digite la opcion en que desea que se muestre el Disco:\n";
                    cout <<"a: Por Tipo de forma Ascendente.\n";
                    cout <<"b: Por Tipo de forma Descendente.\n";
                    cout <<"c: Por Nombre de forma Ascendente.\n";
                    cout <<"d: Por Nombre de forma Descendente.\n";
                    cin >> opcion2;
                    cout <<"-------------------------------------------------------------------------------\n";
                    switch(opcion2)
                    {
                    case 'a':
                        Imprimir_Disco_Tipo_MenoraMayorT(Disco,1);
                        break;
                    case 'b':
                        Imprimir_Disco_Tipo_MayoraMenorT(Disco,1);
                        break;
                    case 'c':
                        Imprimir_Disco_MenoraMayorN(Disco,1);
                        break;
                    case 'd':
                        Imprimir_Disco_MayoraMenorN(Disco,1);
                        break;
                    default:
                        cout << "Opcion de impresion invalida.\n";
                        break;
                    }
                    cout <<"-------------------------------------------------------------------------------\n";
                }
                else
                {
                    cerr << "\n++++++++++++++++++++++++ATENCION+++++++++++++++++++++++++++++++\n";
                    cerr << "El Disco se encuentra actualmente vacio\n";
                    cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
                }
            }
            break;
            case 2:
            {
                cout <<"\n-------------------------------------------------------------------------------\n";
                cout << "\tOpcion 2: Imprimir Archivos/Carpetas de la Carpeta actual.\n";
                cout <<"-------------------------------------------------------------------------------\n";
                if(!IsEmpty(Usuario))
                {
                    char opcion2;
                    cout <<"Digite la opcion en que desea que se muestre los Archivos\\Carpetas de la posicion Actual:\n";
                    cout <<"a: Por Tipo de forma Ascendente.\n";
                    cout <<"b: Por Tipo de forma Descendente.\n";
                    cout <<"c: Por Nombre de forma Ascendente.\n";
                    cout <<"d: Por Nombre de forma Descendente.\n";
                    cin >> opcion2;
                    cout <<"-------------------------------------------------------------------------------\n";
                    switch(opcion2)
                    {
                    case 'a':
                        Imprimir_Lista_MenoraMayorT(Usuario->last->info);
                        break;
                    case 'b':
                        Imprimir_Lista_MayoraMenorT(Usuario->last->info);
                        break;
                    case 'c':
                        Imprimir_Lista_MenoraMayorN(Usuario->last->info);
                        break;
                    case 'd':
                        Imprimir_Lista_MayoraMenorT(Usuario->last->info);
                        break;
                    default:
                        cout << "Opcion de impresion invalida.\n";
                        break;
                    }
                    cout <<"-------------------------------------------------------------------------------\n";
                }
                else
                {
                    cerr << "\n++++++++++++++++++++++++ATENCION+++++++++++++++++++++++++++++++\n";
                    cerr << "El Usuario no se encuentra actualmente en una carpeta valida\n";
                    cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
                    cout << "Favor Ingresar a una Carpeta valida y ejecutar de nuevo esta opcion\n";
                    cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
                }
            }
            break;
            case 3:
            {
                cout <<"\n-------------------------------------------------------------------------------\n";
                cout << "\tOpcion 3: Calcular Hoja de Calculo.\n";
                cout <<"-------------------------------------------------------------------------------\n";
                if(!IsEmpty(Usuario))
                {
                    char* Archivo=new char[100];
                    cout << "Favor ingrese el nombre del archivo a calcular: ";
                    cin.getline(Archivo,100);
                    char* arch=Copiar(Archivo);
                    string Tipo;
                    if(PuntoEnCadena(Archivo))
                        Tipo=Separar_Tipo(Archivo);
                    Nodo* Buscar=Buscar_en_Lista(Usuario->last->info->Nombre,Archivo,Tipo);
                    if(Buscar!=NULL)
                    {
                        cout << "\n-----------------------------------------------------\n";
                        CalcularTodasLasHojas(arch,Usuario->last->info);
                        cout << "La hoja de calculo se ha resuelto con exito\n";
                        cout << "-----------------------------------------------------\n\n";
                    }
                    else
                    {
                        cerr << "\n++++++++++++++++++++++++ATENCION+++++++++++++++++++++++++++++++\n";
                        cerr << "El siguiente Archivo/Carpeta no pudo ser encontrado en la carpeta actual\n";
                        cout << "Nombre: " << Archivo;
                        if(Tipo!="")
                            cout <<"."<<Tipo;
                        cout << endl;
                        cout << "--------------------------------------------\n";
                        cout << "RAZON: Nombre y tipo no coinciden\n";
                        cout << "--------------------------------------------\n";
                        cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
                    }
                    delete [] Archivo;
                    delete [] arch;
                }
                else
                {
                    cerr << "\n++++++++++++++++++++++++ATENCION+++++++++++++++++++++++++++++++\n";
                    cerr << "El Usuario no se encuentra actualmente en una carpeta valida\n";
                    cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
                    cout << "Favor Ingresar a una Carpeta valida y ejecutar de nuevo esta opcion\n";
                    cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
                }
            }
            break;
            case 4:
            {
                cout <<"\n-------------------------------------------------------------------------------\n";
                cout << "\tOpcion 4: Generar reporte.\n";
                cout <<"-------------------------------------------------------------------------------\n";
                if(!IsEmpty(Usuario))
                {
                    char* Archivo=new char[100];
                    cout << "Favor ingrese el nombre del archivo del que quisiera realizar el reporte: ";
                    cin.getline(Archivo,100);
                    char* arch=Copiar(Archivo);
                    string Tipo;
                    if(PuntoEnCadena(Archivo))
                        Tipo=Separar_Tipo(Archivo);
                    cout << Usuario->last->info->nombre<<"\\"<<Archivo << "\\"<<Tipo<<endl;
                    Nodo* Buscar=Buscar_en_Lista(Usuario->last->info->Nombre,Archivo,Tipo);
                    if(Buscar!=NULL)
                    {
                        int reporte,fila,columna;
                        char* report=new char[10];
                        cout << "---------------------------------------------------------------------\n";
                        cout <<"Se ha encontrado el Archivo referenciado\n";
                        cout << "El Archivo contiene: "<< Cantidad_Hojas(arch)<< " hojas de calculo\n";
                        cout << "---------------------------------------------------------------------\n";
                        cout << "De cual quisiera realizar el reporte: ";
                        cin >> reporte;
                        cin.ignore();
                        cout << "----------------------------------------------------------------------\n";
                        cout << "Digite la fila a adicionar en el reporte: ";
                        cin >> fila;
                        cin.ignore();
                        cout << "----------------------------------------------------------------------\n";
                        cout << "Digite la columna que desea adicionar en el reporte: ";
                        cin >> columna;
                        cin.ignore();
                        cout << "----------------------------------------------------------------------\n";
                        if(reporte>Cantidad_Hojas(arch))
                        {
                            cerr << "\n++++++++++++++++++++++++ATENCION+++++++++++++++++++++++++++++++\n";
                            cout << "La hoja de calculo no contiene dicha cantidad de Hojas\n";
                            cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
                        }
                        else
                        {
                            itoa(reporte,report,10);
                            strcat(Archivo,report);
                            char* Abrir_Hoja=Copiar(Archivo);
                            strcat(Abrir_Hoja,".");
                            strcat(Abrir_Hoja,Tipo.c_str());
                            Nodo* Encontrado=Buscar_en_Lista(Usuario->last->info->Nombre,Archivo,Tipo);
                            if(Encontrado==NULL)
                            {
                                cerr << "\n++++++++++++++++++++++++ATENCION+++++++++++++++++++++++++++++++\n";
                                cerr << "El siguiente Archivo no pudo ser encontrado en la carpeta actual\n";
                                cerr << "Nombre: " << Archivo;
                                if(Tipo!="")
                                    cout <<"."<<Tipo;
                                cout << endl;
                                cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
                                cout << "Razon: La Hoja de Calculo referenciada no ha sido calculada\n";
                                cout << "\tEjecutar la opcion 3\n";
                                cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
                            }
                            else
                            {
                                char Archivo_Nombres[100];
                                cout << "======================================================================\n";
                                cout << "Se ha encontrado la Hoja de Calculo deseada.\n";
                                cout << "----------------------------------------------------------------------\n";
                                cout << "Ingrese el nombre del archivo donde se encuentran los nombres para generar el reporte: ";
                                cin.getline(Archivo_Nombres,100);
                                char* Abrir_Nombres=Copiar(Archivo_Nombres);
                                string Tipo_Nombres;
                                if(PuntoEnCadena(Abrir_Nombres))
                                    Tipo_Nombres=Separar_Tipo(Archivo_Nombres);
                                Nodo* Nombres=Buscar_en_Disco(Disco,Archivo_Nombres,Tipo_Nombres);
                                if(Nombres!=NULL)
                                {
                                    cout << "##################################################################\n";
                                    cout << "Generando Reporte......\n";
                                    Reporte(Abrir_Nombres,Abrir_Hoja,Usuario->last->info,fila,columna);
                                    cout << "##################################################################\n";
                                }
                                else
                                {
                                    cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
                                    cerr << "El archivo que contiene los Nombres no ha sido encontrado en el Disco\n";
                                    cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
                                }
                                delete [] Abrir_Nombres;
                            }
                        }
                        delete [] report;
                    }
                    else
                    {
                        cerr << "\n++++++++++++++++++++++++atencion+++++++++++++++++++++++++++++++\n";
                        cerr << "El siguiente Archivo no pudo ser encontrado en la carpeta actual\n";
                        cerr << "Nombre: " << Archivo;
                        if(Tipo!="")
                            cout <<"."<<Tipo;
                        cout << endl;
                        cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
                    }
                    delete [] Archivo;
                    delete [] arch;
                }
                else
                {
                    cerr << "\n++++++++++++++++++++++++ATENCION+++++++++++++++++++++++++++++++\n";
                    cerr << "El Usuario no se encuentra actualmente en una carpeta valida\n";
                    cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
                    cout << "Favor Ingresar a una Carpeta valida y ejecutar de nuevo esta opcion\n";
                    cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
                }
            }
            break;
            case 5:
            {
                cout <<"\n-------------------------------------------------------------------------------\n";
                cout << "\tOpcion 5: Buscar Archivo/Carpeta en la Carpeta actual.\n";
                cout <<"-------------------------------------------------------------------------------\n";
                if(!IsEmpty(Usuario))
                {
                    char * Buscar=new char[300];
                    cout << "Favor ingresar nombre del Archivo/Carpeta a buscar dentro de la ubicacion actual: ";
                    cin.getline(Buscar,300);
                    string Tipo;
                    if(PuntoEnCadena(Buscar))
                        Tipo=Separar_Tipo(Buscar);
                    Nodo* Busqueda=Buscar_en_Lista(Usuario->last->info->Nombre,Buscar,Tipo);
                    if(Busqueda==NULL)
                    {
                        cerr << "\n++++++++++++++++++++++++ATENCION+++++++++++++++++++++++++++++++\n";
                        cerr << "El siguiente Archivo/Carpeta no pudo ser encontrado en la ubicacion actual\n";
                        cerr << "Nombre: " << Buscar;
                        if(Tipo!="")
                            cout << "." << Tipo;
                        cout << endl;
                        cerr << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
                    }
                    else
                    {
                        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                        cout << "El siguiente Archivo/Carpeta ha sido encontrado en la ubicacion actual\n";
                        cout << "Nombre: " << Buscar;
                        if(Tipo!="")
                            cout <<"."<<Tipo;
                        cout << endl;
                        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                        if(Tipo=="")
                        {
                            char resp;
                            cout << "Desea Ingresar a la carpeta antes buscada: (s/n)";
                            cin >> resp;
                            if(resp=='s'||resp=='S')
                                Push_back(Usuario,Busqueda);
                        }
                    }
                    delete [] Buscar;
                }
                else
                {
                    cerr << "\n++++++++++++++++++++++++ATENCION+++++++++++++++++++++++++++++++\n";
                    cerr << "El Usuario no se encuentra actualmente en una carpeta valida\n";
                    cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
                    cout << "Favor Ingresar a una Carpeta valida y ejecutar de nuevo esta opcion\n";
                    cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
                }
            }
            break;
            case 6:
            {
                cout <<"\n-------------------------------------------------------------------------------\n";
                cout << "\tOpcion 6: Buscar Archivo/Carpeta en el Disco.\n";
                cout <<"-------------------------------------------------------------------------------\n";
                if(Disco!=NULL)
                {
                    char * Buscar=new char[300];
                    cout << "Favor ingresar nombre del Archivo/Carpeta a buscar dentro del Disco Local: ";
                    cin.getline(Buscar,300);
                    string Tipo;
                    if(PuntoEnCadena(Buscar))
                        Tipo=Separar_Tipo(Buscar);
                    Nodo * Busqueda=Buscar_en_Disco(Disco,Buscar,Tipo);
                    if(Busqueda== NULL)
                    {
                        cerr << "\n++++++++++++++++++++++++ATENCION+++++++++++++++++++++++++++++++\n";
                        cerr << "El siguiente Archivo/Carpeta no pudo ser encontrado en el Disco Local\n";
                        cerr << "Nombre: " << Buscar;
                        if(Tipo!="")
                            cout <<"."<<Tipo;
                        cout << endl;
                        cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
                    }
                    else
                    {
                        cerr << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                        cerr << "El siguiente Archivo/Carpeta ha sido encontrado en la ubicacion actual\n";
                        cerr << "Nombre: " << Buscar;
                        if(Tipo!="")
                            cout <<"."<<Tipo;
                        cout << endl;
                        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                    }
                    delete [] Buscar;
                }
                else
                {
                    cerr << "\n++++++++++++++++++++++++ATENCION+++++++++++++++++++++++++++++++\n";
                    cerr << "El Disco se encuentra actualmente vacio\n";
                    cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
                }
            }
            break;
            case 7:
            {
                if(!IsEmpty(Usuario))
                {
                    cout <<"\n-------------------------------------------------------------------------------\n";
                    cout << "\tOpcion 7: Agregar Archivo/Carpeta en la Carpeta actual.\n";
                    cout <<"-------------------------------------------------------------------------------\n";
                    char * Nombre=new char[300];
                    cout << "Escriba el nombre que desea darle al nuevo Archivo/Carpeta: ";
                    cin.getline(Nombre,300);
                    Agregar(Usuario->last->info,Nombre);
                    cout << "\n\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
                    cout << "Se ha agregado el Archivo/Carpeta a la Carpeta actual exitosamente\n";
                    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n\n";
                    delete [] Nombre;
                }
                else
                {
                    cerr << "\n++++++++++++++++++++++++ATENCION+++++++++++++++++++++++++++++++\n";
                    cerr << "El Usuario no se encuentra actualmente en una carpeta valida\n";
                    cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
                    cout << "Favor Ingresar a una Carpeta valida y ejecutar de nuevo esta opcion\n";
                    cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
                }
            }
            break;
            case 8:
            {
                if(Disco!=NULL)
                {
                    char * Carpeta=new char[300];
                    cout <<"\n-------------------------------------------------------------------------------\n";
                    cout << "\tOpcion 8: Agregar Archivo/Carpeta en el Disco.\n";
                    cout <<"-------------------------------------------------------------------------------\n";
                    cout << "Ingrese el nombre de la carpeta donde quiere agregar el Archivo\\Carpeta: ";
                    cin.getline(Carpeta,300);
                    string Tipo;
                    if(PuntoEnCadena(Carpeta))
                        Tipo=Cortar(Carpeta);
                    if(Buscar_en_Disco(Disco,Carpeta,Tipo)!=NULL)
                    {
                        char * Agrega=new char[300];
                        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                        cout << "La carpeta "<<Carpeta<< " fue encontrada\n";
                        cout << "Favor ingresar el nombre del Archivo\\Carpeta que desea agregar: ";
                        cin.getline(Agrega,300);
                        Nodo* Donde_Agrega=Buscar_en_Disco(Disco,Carpeta,Tipo);
                        Agregar(Donde_Agrega,Agrega);
                        cout << "El Archivo\\Carpeta ha sido agregado a su Disco Local\n";
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                        delete [] Agrega;
                    }
                    else
                    {
                        cerr << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                        cout << "La carpeta no pudo ser encontrada en el Disco Local.\n";
                        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                    }
                    delete [] Carpeta;
                }
                else
                {
                    cerr << "\n++++++++++++++++++++++++ATENCION+++++++++++++++++++++++++++++++\n";
                    cerr << "El Disco se encuentra actualmente vacio\n";
                    cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
                }
            }
            break;
            case 9:
            {
                char op;
                cout<<"Desea devolverse s/n";
                cin>>op;
                if(op=='s')
                {
                    Golast(Usuario);
                    Erase(Usuario);
                    Golast(Usuario);
                }
            }
            break;
            case 10:
            {
                cout << "Terminar Programa"<<endl;
                cout << "Esta seguro que desea terminar el programa?(s/n)"<<endl;
                cin >> salida;
            }
            break;
            default:
            {
                cout << "Favor ingresar una opcion valida"<<endl;
            }
            break;
            }
            if(salida!='s'&&salida!='S')
            {
                cout << "Favor Ingresar la opcion deseada:\n";
                cout << "Ingrese el numero 0 para obtener ayuda.\n----> ";
                cin >> opcion;
                cin.ignore();
            }
        }
        while(salida!='s'&&salida!='S');
    }
    else
    {
        cerr << "\n++++++++++++++++++++++++ATENCION+++++++++++++++++++++++++++++++\n";
        cerr << "El Disco se encuentra actualmente vacio\n";
        cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
    }
    cout << "\n\n__________________________________________________________\n";
    cout << "==========================================================\n";
    cout << "\tPrograma terminado\n";
    cout << "\tGracias por utilizar nuestro Software\n";
    cout << "__________________________________________________________\n";
    cout << "==========================================================\n\n";
    return 0;
}
