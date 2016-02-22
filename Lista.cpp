#include "Lista.h"
template <typename Tdata>
TList<Tdata>* create_list()
{
    TList<Tdata>*  l= new TList<Tdata>;
    l->first = l->last=l->window=NULL;
    return l;
}
template <typename Tdata>
bool IsEmpty(TList<Tdata>* l)
{
    if(l!=NULL)
        return (l->first==NULL);
}
template <typename Tdata>
void Push_back (TList<Tdata>* l, Tdata info)
{
    TLNode<Tdata>* box = new TLNode<Tdata>;
    box->info = info;
    if(IsEmpty(l))
    {
        l->first=l->last=l->window=box;
        box->prev=box->next=NULL;
    }
    else
    {
        l->last->next=box;
        box->prev=l->last;
        box->next=NULL;
        l->last=box;
        l->window=box;
    }
}
template <typename Tdata>
void Annex (TList<Tdata>* l, Tdata info)
{
    TLNode<Tdata>* box = new TLNode<Tdata>;
    box->info=info;
    if(IsEmpty(l))
        Push_back(l,info);
    else
    {
        if(!isEnd(l))
        {
            if(l->last == l->window)
            {
                l->last->next=box;
                box->next=NULL;
                box->prev=l->last;
                l->last=box;
            }
            else
            {
                box->prev=l->window;
                box->next=l->window->next;
                l->window->next=box;
                box->next->prev=box;
            }
            l->window=box;
        }
    }
}
template <typename Tdata>
void Insert (TList<Tdata>* l, Tdata info)
{
    TLNode<Tdata>* box = new TLNode<Tdata>;
    box->info=info;
    if(IsEmpty(l))
        Push_back(l,info);
    else
    {
        if(!isEnd(l))
        {
            if(l->first == l->window)
            {
                l->first->prev=box;
                box->next=l->first;
                box->prev=NULL;
                l->first=box;
            }
            else
            {
                box->next=l->window;
                box->prev=l->window->prev;
                l->window->prev=box;
                box->prev->next=box;
            }
            l->window=box;
        }
    }
}
template <typename Tdata>
void Gofirst (TList<Tdata>* l)
{
    if(l->window!=l->first)
        l->window=l->first;
}
template <typename Tdata>
void Golast (TList<Tdata>* l)
{
    if(l->window!=l->last)
        l->window=l->last;
}
template <typename Tdata>
void Gonext(TList<Tdata>* l)
{
    if(!IsEmpty(l)&&!isEnd(l))
        l->window=l->window->next;
}
template <typename Tdata>
void Goprev (TList<Tdata>* l)
{
    if(!IsEmpty(l)&&!isEnd(l))
        l->window=l->window->prev;
}
template <typename Tdata>
bool isEnd (TList<Tdata>* l)
{
    return l->window==NULL;
}
template <typename Tdata>
void Erase (TList<Tdata>* l)
{
    if(!isEnd(l))
    {
        if(l->window==l->last)
        {
            if(l->first==l->last)
                l->first=NULL;
            l->last=l->last->prev;
            delete l->window;
            l->window=NULL;
            if(l->last!=NULL)
                l->last->next=NULL;

        }
        else
        {
            if(l->window==l->first)
            {
                if(l->first==l->last)
                    l->last=NULL;
                l->first=l->first->next;
                delete l->window;
                l->window=l->first;
                if(l->first!=NULL)
                    l->first->prev=NULL;
            }
            else
            {
                l->window->next->prev=l->window->prev;
                l->window->prev->next=l->window->next;
                TLNode<Tdata>* aux = l->window;
                l->window=l->window->next;
                delete aux;
            }
        }
    }
}
template <typename Tdata>
void Push_front (TList<Tdata>* l, Tdata info)
{
    TLNode<Tdata>* box = new TLNode<Tdata>;
    box->info = info;
    if(IsEmpty(l))
    {
        l->first=l->last=l->window=box;
        box->prev=box->next=NULL;
    }
    else
    {
        l->first->prev=box;
        box->next=l->first;
        box->prev=NULL;
        l->first=box;
        l->window=box;
    }
}
template <typename Tdata>
TLNode<Tdata>* Middle (TList<Tdata>*l)
{
    TLNode<Tdata>* ptr=l->first;
    TLNode<Tdata>* ptr2=l->first;
    while(ptr2!=NULL&&ptr2!=l->last)
    {
        ptr=ptr->next;
        ptr2=ptr2->next;
        if(ptr2!=NULL)
            ptr2=ptr2->next;
    }
    return ptr;
}
