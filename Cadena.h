#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED
//Compara dos cadenas si dos iguales SIN IMPORTAR mayus/minus
bool Comparar_sin(char* cadena1,char* cadena2);
//Compara dos cadenas si dos cadenas IMPORTANDO mayus/minus
bool Comparar_con(char* cadena1,char* cadena2);
//Cuenta cuantos caracteres hay en una cadena
int Contar (char* cadena);
//Copia una cadena en una nueva (retorna esa nueva cadena)
char* Copiar(char* cadena);
//Cambia las Mayus en Minus
void Cambio_a_minus(char * cadena);
//QUita los espacios de una cadena de caracteres
void Quitar_espacios(char* cadena);
//Ver si una cadena contiene un punto
bool PuntoEnCadena( char* cadena);
//Corta la cadena por el espacio
//Deja un apuntador al principio y retorna el de la segunda cadena
char* Cortar(char* palabra);
//Quita las comillas de una cadena de caracteres
void Cortar_Comillas(char*& palabra);
//Separa la cadena por el punto
//devuelve un apuntador a la siguiente letra luego del punto
char * Separar_Tipo(char * palabra);
//Busca si hay una letra dada en una cadena dada
bool Letra_en_Cadena (char * palabra,char Letra);
#endif // CADENA_H_INCLUDED
