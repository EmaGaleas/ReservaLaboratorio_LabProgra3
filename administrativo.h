#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include <iostream>
#include "solicitante.h"

class Administrativo : public Solicitante
{
private:
    int repetir;
public:
    //repetir reservacion
    Administrativo();
    Administrativo (string labSolicitado,string clase,string motivo,string perfil,string nombreI,double numeroI,string correoI,int cantidad,string infoGrupo,string equipo,string fecha,string horaInicio,string horaFin,int repetir);
    ~Administrativo();

    int getRepetir() const;
    void setRepetir(int newRepetir);

    virtual void Imprimir()const;
};

#endif // ADMINISTRATIVO_H
