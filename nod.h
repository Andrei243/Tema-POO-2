#ifndef NOD_H_INCLUDED
#define NOD_H_INCLUDED
#include <iostream>
using namespace std;
template <class T>
class nod
{
    T val;
    nod<T>* urm;
public:
    template <class X>  friend class coada;

    template <class X> friend class Coada_cu_prioritati;
    bool are_urm();
    T return_val();
    void set_val(T x);
    nod<T>();
    nod<T>(T x);
    bool operator==(nod<T> x);
    bool operator!=(nod<T> x);
    bool operator<(nod<T> x);
    nod<T> operator=(nod<T> x);
  template<class X>  friend void swap(nod<X> &a,nod<X> &b);
};

template <class T>
void swap(nod<T> &a,nod<T> &b)
{
    T aux=a.return_val();
    a.set_val(b.return_val());
    b.set_val(aux);

}


template <class T>
bool nod<T>::are_urm(){
        if(urm!=NULL)return true;
        return false;
    }
template <class T>
T nod<T>::return_val(){
        return val;
    }
template <class T>
void nod<T>::set_val(T x){
        val=x;
    }
template <class T>
nod<T>::nod(){
        urm=NULL;
    }
template <class T>
nod<T>::nod(T x){
        val=x;
        urm=NULL;
    }
template <class T>
bool nod<T>::operator==(nod<T> x) {
        if(val==x.val)return true;
        return false;
    }
template <class T>
bool nod<T>::operator!=(nod<T> x){
        if(val!=x.val)return true;
        return false;
    }
template <class T>
bool nod<T>::operator<(nod<T> x){
        if(val<x.val)return true;
        return false;
    }
template <class T>
ostream& operator<<(ostream& out,nod<T> &x)
{
    out<<x.return_val();
    return out;
}
template <class T>
istream& operator>>(istream& in,nod<T> &x)
{
    T aux;
    in>>aux;
    x.set_val(aux);
    return in;
}
template <class T>
nod<T> nod<T>::operator=(nod<T> x){
val=x.return_val();
return x;
}


#endif // NOD_H_INCLUDED
