#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include "solicitante.h"

using std::string;

class Alumno : public Solicitante
{
private:
public:
    Alumno();
    Alumno(string labSolicitado,string clase,string motivo,string perfil,string nombreI,double numeroI,string correoI,int cantidad,string infoGrupo,string equipo,string fecha,string horaInicio,string horaFin);
    ~Alumno();

    virtual void Imprimir()const;
};

#endif // ALUMNO_H
