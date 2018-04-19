#ifndef COADA_DUBLA_H_INCLUDED
#define COADA_DUBLA_H_INCLUDED
#include "coada.h"

template <class X>
class Coada_dubla:public coada<X>
{
    private:
    void push(nod<X> t){coada<X>::push(t);}
    void push(X t){coada<X>::push(t);}
    void pop(){coada<X>::pop();}


    public:
void push_front(nod<X> t);

    void push_front(X t);
    void push_back(X t);
    void push_back(nod<X> t);

    void pop_front();
    void pop_back();

    ~Coada_dubla<X>(){}
    Coada_dubla<X>():
    coada<X>()
    {};
    Coada_dubla<X>(const Coada_dubla & x):
    coada<X>(x)
    {};

    Coada_dubla<X> operator=(const Coada_dubla& x);


};


template <class X>
void Coada_dubla<X>::push_back(X t){
 ((coada<X>*)this)->push(t);

}

template <class X>
void Coada_dubla<X>::push_back(nod<X> t){
push_back(t.return_val);
}

template <class X>
void Coada_dubla<X>::push_front(X t){
coada<X>::reverse();
push_back(t);
coada<X>::reverse();

}

template <class X>
void Coada_dubla<X>::push_front(nod<X> t){
push_front(t.return_val);

}


template <class X>
void Coada_dubla<X>::pop_front(){
coada<X>::pop();
}

template <class X>
void Coada_dubla<X>::pop_back(){
coada<X>::reverse();
coada<X>::pop();
coada<X>::reverse();

}


template <class X>
Coada_dubla<X> Coada_dubla<X>::operator=(const Coada_dubla<X>& x){
return ((coada<X>*)this)=x;


}

#endif // COADA_DUBLA_H_INCLUDED
