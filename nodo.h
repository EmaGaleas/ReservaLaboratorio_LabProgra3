#ifndef NODO_H
#define NODO_H
#include <iostream>
using std::cout;

template<typename tipo> class lista;
template<typename tipo>
class nodo{
    friend lista<tipo>;
    friend class cframe;
    private:
        tipo dato;
        nodo<tipo*>*SigPtr;
    public:
        nodo(const tipo&);
        tipo getDato()const;
};

template<typename tipo>
nodo<tipo>::nodo(const tipo &dato) : dato(dato),SigPtr(0){}

template<typename tipo>
tipo nodo<tipo>::getDato()const
{
    return dato;
}

#endif // NODO_H


