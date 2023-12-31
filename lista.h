#ifndef LISTA_H
#define LISTA_H
#include <nodo.h>
#include <string>
#include <fstream>
#include <QFile>
#include <QTextStream>

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

    string horas[10] = {"6:45","8:10","9:55","11:15","13:20","14:40","16:00","17:20","18:40","20:00"};
};

template<typename tipo>
void lista<tipo>::NewExcel()
{
    std::ifstream file;
    file.open("export.xls");
    if(file)
    {
        file.close();
        std::ofstream File("export.xls",ios::out|ios::app);
        if (File.is_open())
        {
            string repetir = "NUNCA";
            if((raizPtr->dato).getRepetir()==1){
                repetir = "A DIARIO";
            }else if((raizPtr->dato).getRepetir()==2){
                repetir = "SEMANALMENTE";
            }
            int indexInicio = (raizPtr->dato).getHoraInicio();
            int indexFinal  = (raizPtr->dato).getHoraFin();

            File <<(raizPtr->dato).getLabSolicitado()<<"\t"
                <<(raizPtr->dato).getClase()<<"\t"
               <<(raizPtr->dato).getMotivo()<<"\t"
              <<(raizPtr->dato).getPerfil()<<"\t"
             <<(raizPtr->dato).getNombreI()<<"\t"
            <<(raizPtr->dato).getNumeroI()<<"\t"
            <<(raizPtr->dato).getCorreoI()<<"\t"
            <<(raizPtr->dato).getCantidad()<<"\t"
            <<(raizPtr->dato).getInfoGrupo()<<"\t"
            <<(raizPtr->dato).getEquipo()<<"\t"
            <<(raizPtr->dato).getFecha()<<"\t"
            <<horas[indexInicio]<<"\t"
            <<horas[indexFinal]<<"\t"
            <<repetir<<"\t"
            <<"\n";
            File.close();
            cout << "XLS exportado.\n";
        } else {
            std::cerr << "Error en el archivo.\n";
        }
    }
    else
    {
        file.close();
        std::ofstream File("export.xls");
        if (File.is_open())
        {
            File << "Laboratorio Solicitado\tClase\tMotivo\tPerfil\tNombre\tNumero\tCorreo\tCantidad\tInformacion del Grupo\tEquipo a utilizar\tFecha de reservacion\tHora de Inicio\tHora de Finalizacion\tRepeticion\n";
            for ( nodo< tipo > *actPtr = raizPtr; actPtr!=0; actPtr = actPtr->SigPtr )
            {
                string repetir = "NUNCA";
                if((actPtr->dato).getRepetir()==1){
                    repetir = "A DIARIO";
                }else if((actPtr->dato).getRepetir()==2){
                    repetir = "SEMANALMENTE";
                }
                int indexInicio = (actPtr->dato).getHoraInicio();
                int indexFinal  = (actPtr->dato).getHoraFin();

                File <<(actPtr->dato).getLabSolicitado()<<"\t"
                    <<(actPtr->dato).getClase()<<"\t"
                   <<(actPtr->dato).getMotivo()<<"\t"
                  <<(actPtr->dato).getPerfil()<<"\t"
                 <<(actPtr->dato).getNombreI()<<"\t"
                <<(actPtr->dato).getNumeroI()<<"\t"
                <<(actPtr->dato).getCorreoI()<<"\t"
                <<(actPtr->dato).getCantidad()<<"\t"
                <<(actPtr->dato).getInfoGrupo()<<"\t"
                <<(actPtr->dato).getEquipo()<<"\t"
                <<(actPtr->dato).getFecha()<<"\t"
                <<horas[indexInicio]<<"\t"
                <<horas[indexFinal]<<"\t"
                <<repetir<<"\t"
                <<"\n";
            }
            File.close();
            cout << "XLS exportado.\n";
        } else {
            std::cerr << "Error en el archivo.\n";
        }
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
