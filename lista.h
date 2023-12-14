#ifndef LISTA_H
#define LISTA_H
#include <nodo.h>
#include <string>
#include <fstream>
using std::ofstream;
using std::ios;
using std::string;
using std::ios;

template<typename tipo>
class lista{
    friend class cframe;
private:
    nodo<tipo> *raizPtr;
    nodo< tipo > *NuevoNodo( const tipo & );
    int Cant=0;
    //int Cant;
public:
    lista();
    ~lista();

    void InsertarAlInicio(const tipo &);
    void InsertarAlFinal(const tipo &);
    bool Vacia();

    void NewExcel();
    void AppendExcel();

    bool Guardar(string nombre);
    int Cantidad();

};

template<typename tipo>
void lista<tipo>::NewExcel()
{
    std::ofstream File("export.xls");
    if (File.is_open())
    {
        File << "Laboratorio Solicitado\tClase\tMotivo\tPerfil\tNombreI\tNumeroI\tCorreoI\tCantidad\tInfoGrupo\tEquipo\tFecha\tHora de Inicio\tHora de Finalizacion\tRepeticion\n";
        for ( nodo< tipo > *actPtr = raizPtr; actPtr!=0; actPtr = actPtr->SigPtr )
        {
            File <<(actPtr->dato).getLabSolicitado()
                 <<(actPtr->dato).getClase()
                 <<(actPtr->dato).getMotivo()
                 <<(actPtr->dato).getPerfil()
                 <<(actPtr->dato).getNombreI()
                 <<(actPtr->dato).getNumeroI()
                 <<(actPtr->dato).getCorreoI()
                 <<(actPtr->dato).getCantidad()
                 <<(actPtr->dato).getInfoGrupo()
                 <<(actPtr->dato).getEquipo()
                 <<(actPtr->dato).getFecha()
                 <<(actPtr->dato).getHoraInicio()
                 <<(actPtr->dato).getHoraFin()
                 <<""
                 <<"\n";
        }
        File.close();
        cout << "XLS exportado.\n";
    } else {
        std::cerr << "Error en el archivo.\n";
    }
}

template<typename tipo>
void lista<tipo>::AppendExcel()
{
    std::ofstream File("export.xls",ios::out|ios::app);
    if (File.is_open())
    {
        File <<(raizPtr->dato)->getLabSolicitado()
             <<(raizPtr->dato)->getClase()
             <<(raizPtr->dato)->getMotivo()
             <<(raizPtr->dato)->getPerfil()
             <<(raizPtr->dato)->getNombreI()
             <<(raizPtr->dato)->getNumeroI()
             <<(raizPtr->dato)->getCorreoI()
             <<(raizPtr->dato)->getCantidad()
             <<(raizPtr->dato)->getInfoGrupo()
             <<(raizPtr->dato)->getEquipo()
             <<(raizPtr->dato)->getFecha()
             <<(raizPtr->dato)->getHoraInicio()
             <<(raizPtr->dato)->getHoraFin()
             <<""
             <<"\n";
        File.close();
        cout << "XLS exportado.\n";
    } else {
        std::cerr << "Error en el archivo.\n";
    }
}

template<typename tipo>
nodo<tipo> *lista<tipo>::NuevoNodo(const tipo &dato)
{
    return new nodo<tipo>(dato);
}


template<typename tipo>
lista<tipo>::lista() : raizPtr(0), Cant(0){}

template<typename tipo>
lista<tipo>::~lista()
{
    if ( !Vacia() ){
        std::cout << "Destruyendo nodos ...\n";
        nodo< tipo > *actPtr = raizPtr;
        nodo< tipo > *tempPtr;

        for ( ; actPtr != 0; ){
            tempPtr = actPtr;
            actPtr = actPtr->SigPtr;
            delete tempPtr;
        }
    }

    std::cout << "Se destruyeron todos los nodos\n\n";
}

template<typename tipo>
void lista<tipo>::InsertarAlInicio(const tipo &dato)
{
    nodo< tipo > *nuevoPtr = NuevoNodo( dato ); // nuevo nodo

    if ( Vacia() ){ // la Lista está vacía
        raizPtr = nuevoPtr; // la nueva lista sólo tiene un nodo
    }else{
        nuevoPtr->SigPtr = raizPtr; // apunta el nuevo nodo al nodo que antes era el primero
        raizPtr = nuevoPtr; // orienta primeroPtr hacia el nuevo nodo
    }
    Cant++;
}

template<typename tipo>
void lista<tipo>::InsertarAlFinal(const tipo &dato)
{
    nodo< tipo > *nuevoPtr = NuevoNodo( dato ); // nuevo nodo
    nodo< tipo > *actPtr = raizPtr;
    if ( Vacia() ){ // la Lista está vacía
        raizPtr = nuevoPtr; // la nueva lista sólo tiene un nodo
    }else{
        for( ; actPtr->SigPtr != 0; actPtr = actPtr->SigPtr);

        actPtr->SigPtr = nuevoPtr;
    }
    Cant++;
}

template<typename tipo>
bool lista<tipo>::Vacia()
{
    return raizPtr==0;
}

template<typename tipo>
int lista<tipo>::Cantidad()
{
    return Cant;
}

#endif // LISTA_H
