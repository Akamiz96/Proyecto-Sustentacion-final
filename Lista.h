#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>
#include <cstdlib>
using namespace std;
template <typename Tdata>
struct TLNode
{
    Tdata info;
    TLNode<Tdata> * next, *prev;
};
template <typename Tdata>
struct TList
{
    TLNode<Tdata> *first,*last,*window;
};
template <typename Tdata>
TList<Tdata>* create_list();
template <typename Tdata>
bool IsEmpty(TList<Tdata>* l);
template <typename Tdata>
void Push_back (TList<Tdata>* l, Tdata info);
template <typename Tdata>
void Push_front (TList<Tdata>* l, Tdata info);
template <typename Tdata>
void Insert (TList<Tdata>* l, Tdata info);
template <typename Tdata>
void Annex (TList<Tdata>* l, Tdata info);
template <typename Tdata>
void Gofirst (TList<Tdata>* l);
template <typename Tdata>
void Golast (TList<Tdata>* l);
template <typename Tdata>
void Gonext(TList<Tdata>* l);
template <typename Tdata>
void Goprev (TList<Tdata>* l);
template <typename Tdata>
bool isEnd (TList<Tdata>* l);
template <typename Tdata>
void Erase (TList<Tdata>* l);
template <typename Tdata>
TLNode<Tdata>* Middle (TList<Tdata>*l);
#endif // LISTA_H_INCLUDED
