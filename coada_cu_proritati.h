#ifndef COADA_CU_PRORITATI_H_INCLUDED
#define COADA_CU_PRORITATI_H_INCLUDED
#include "coada.h"

template<class X>
class Coada_cu_prioritati : public coada<X>
{
    public:

    void push(nod<X> t);

    void push(X t);

    ~Coada_cu_prioritati<X>(){};


    Coada_cu_prioritati<X>():
    coada<X>()
    {}


    Coada_cu_prioritati<X>(const Coada_cu_prioritati<X>&a):
    coada<X>(a)
    {}

    Coada_cu_prioritati<X> operator=(const Coada_cu_prioritati<X>& a);

};

template<class X>
istream& operator>>(istream& in,Coada_cu_prioritati<X>& x)
{
    int nr;
    in>>nr;
    X aux;
    for(int i=0;i<nr;i++)
    {
        in>>aux;
        x.push(aux);

    }

    return in;
}

template<class X>
void Coada_cu_prioritati<X>::push(X x)
{
    coada<X>::push(x);
    coada<X>::reverse();
    nod<X>* aux1;
    nod<X>* aux2;
    aux1=coada<X>::fata;
    if(aux1==coada<X>::nullpt||aux1->urm==coada<X>::nullpt)return;
    aux2=coada<X>::fata->urm;
    while(aux2!=coada<X>::nullpt&&aux1->return_val()<aux2->return_val()) ///aici schimb daca vreau sa fie primele elementele mai mari sau cele mai mici: < pentru cele mari primele, > pentru cele mici primele
    {
        swap(*aux1,*aux2);
        aux1=aux1->urm;
        aux2=aux2->urm;

    }
    coada<X>::reverse();
}

template<class X>
void Coada_cu_prioritati<X>::push(nod<X> x)
{
    push(x.return_val());

}

template<class X>
Coada_cu_prioritati<X> Coada_cu_prioritati<X>::operator=(const Coada_cu_prioritati<X>& a)
{
    coada<X>::stergere();
    nod<X>* aux=coada<X>::fata;
    while(aux!=coada<X>::nullpt)
    {
        push(*aux);
        aux=aux->urm;

    }

}

#endif // COADA_CU_PRORITATI_H_INCLUDED
