#ifndef COADA_H_INCLUDED
#define COADA_H_INCLUDED
#include "nod.h"

template <class T>
class coada
{
protected:
    nod<T> marc;
    nod<T>* nullpt;
    nod<T>* fata;
    nod<T>* spate;
    void stergere();///facut
    public:
    void reverse(); ///facut
public:
    virtual void push(nod<T> t); ///facut
    virtual void push(T t);  ///facut cu sfantul asd <3
    void pop(); ///facut cu ajutorul asd-ului :))
    coada<T>();       ///facut
    coada<T>(const coada<T>&a);///facut
    coada<T> operator=(const coada<T>& a); ///facut
    virtual ~coada<T>(); ///facut
    T top(); ///facut
    coada<T> operator-(const coada<T>& x); ///facut
    coada<T> operator+(const coada<T>& x); ///facut
    bool operator==(const coada<T>& x); ///facut
    bool operator!=(const coada<T>& x);  ///facut
    bool nu_e_goala();   ///facut
    bool operator<(const coada<T>& x); ///facut
    bool operator>(const coada<T>& x); ///facut
    template<class X> friend istream& operator>>(istream& in,coada<T>& x); ///facut
    /// facuta scrierea



       class iterator
       {
           nod<T>* act;
           public:
               iterator(nod<T>& x)
               {
                   act=&x;

               }

           iterator(const coada<T>& x){
           act=x.fata;
           }
           iterator(const coada<T>& x,int y){
           act=x.fata;
           for(int i=0;i<y&&act.are_urm();i++)act=act.urm;
           }

           iterator(const iterator& a)
           {
               act=a.act;
           }

           iterator operator++(){
           if(act->are_urm())act=act->urm;
           return *this;
           }

           iterator operator--(){
           nod<T>* aux=fata;
           while(aux->urm!=act)aux=aux->urm;
           act=aux;
           return act;
           }

           iterator operator++(int){
           iterator aux(*act);
           if(act->are_urm())act=act->urm;
           return aux;
           }

           iterator operator--(int)
           {
               iterator aux(act);
               --act;
               return aux;
           }

           bool operator !=(const iterator& a){
           return act!=a.act;}
           T operator*(){
           return act->return_val();}

       };

       iterator begin(){
       return iterator(*this);
       }
       iterator end(){
       return iterator(*nullpt);
       }

};

template<class X>
void coada<X>::reverse()
{
    if(!nu_e_goala())return;
    coada<X> aux(*this);
    stergere();
    spate=new nod<X>;
    spate->urm=nullpt;
    spate->set_val(aux.top());
    aux.pop();
    nod<X>* act;
    nod<X>* nodaux;
    act=&(*spate);
    while(aux.nu_e_goala())
    {
        nodaux=new nod<X>;
        nodaux->set_val(aux.top());
        nodaux->urm=act;
        act=&(*nodaux);
        aux.pop();
    }
    fata=act;
}


template <class X>
bool coada<X>::operator<(const coada<X>& x)
{
    if(*this==x)return false;
    coada<X> aux1(*this);
    coada<X> aux2(x);
    while(aux1.nu_e_goala()&&aux2.nu_e_goala()&&aux1.top()==aux2.top())
    {
        aux1.pop();
        aux2.pop();

    }

    if(aux1.nu_e_goala()==false)return true;
    if(aux2.nu_e_goala()==false)return false;
    if(aux1.top()<aux2.top())return true;
    return false;

}

template<class X>
bool coada<X>::operator>(const coada<X>& x)
{
    return !(*this<x)&&*this!=x;



}


template<class X>
bool coada<X>::operator==(const coada<X>& x)
{
    coada<X> aux1(*this);
    coada<X> aux2(x);
    while(aux1.nu_e_goala()&&aux2.nu_e_goala()&&aux1.top()==aux2.top())
    {
        aux1.pop();
        aux2.pop();
    }
    if(aux1.nu_e_goala())return false;
    if(aux2.nu_e_goala())return false;
    return true;

}

template<class X>
bool coada<X>::operator!=(const coada<X>& x)
{
    return !(*this==x);
}

template<class X>
coada<X> coada<X>::operator-(const coada<X>& x)
{coada<X>aux2(*this);
    coada<X> aux(x);
    while(aux.nu_e_goala()&&aux2.nu_e_goala()&&aux.top()==aux2.top())
    {
        aux2.pop();
        aux.pop();

    }

return aux2;
}


template<class X>
coada<X> coada<X>::operator+(const coada<X>& x)
{
    coada<X> aux(x);
    coada<X> final(*this);
    while(aux.nu_e_goala())
    {
        final.push(aux.top());
        aux.pop();

    }
    return final;
}



template<class X>
istream& operator>>(istream& in,coada<X>& x)
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


ostream& operator<<(ostream& out,coada<char>& x)
{
   while(x.nu_e_goala())
   {
       out<<x.top();
       x.pop();

   }
    return out;

}



ostream& operator<<(ostream& out,coada<string>& x)
{
   while(x.nu_e_goala())
   {
       out<<x.top()<<"\n";
       x.pop();

   }

return out;
}


template<class X>
ostream& operator<<(ostream& out,coada<X>& x)
{
    while(x.nu_e_goala()){
    out<<x.top()<<" ";
    x.pop();
    }

    return out;

}



template<class X>
coada<X>::coada()
{
    nullpt=&marc;
   fata=spate=nullpt;

}

template<class X>
bool coada<X>::nu_e_goala()
{
    return fata!=nullpt;
}

template<class X>
void coada<X>::push(X x){

nod<X>* aux=new nod<X>;
aux->set_val(x);
aux->urm=nullpt;

if(spate==nullpt){
fata=aux;
}
else spate->urm=aux;

spate=aux;
}
template<class X>
void coada<X>::push(nod<X> x){
X aux=x.return_val();
push(aux);
}

template <class X>
void coada<X>::pop(){
if(fata==nullpt)return;
nod<X>* aux=fata;
fata=fata->urm;
delete aux;
if(fata==nullpt)spate=nullpt;


}
template <class X>
void coada<X>::stergere(){
while(fata!=nullpt)pop();
}
template <class X>
coada<X>::coada(const coada<X>& x){
    nullpt=&marc;
    fata=spate=nullpt;
nod<X>* aux=x.fata;
while(aux!=x.nullpt){
push(aux->return_val());
aux=aux->urm;
}
}

template <class X>
coada<X> coada<X>::operator=(const coada<X> &x){
stergere();
nod<X>* aux=x.fata;
while(aux!=x.nullpt){
push(aux->return_val());
aux=aux->urm;
}
return *this;
}

template <class X>
coada<X>::~coada(){
stergere();
}

template <class X>
X coada<X>::top(){ //se presupune ca nu se cere capul unei stive goale
return fata->val;
}


#endif // COADA_H_INCLUDED
