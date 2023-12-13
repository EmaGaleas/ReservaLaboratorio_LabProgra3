#ifndef EDUCACIONCONTINUA_H
#define EDUCACIONCONTINUA_H
#include <iostream>
#include "solicitante.h"


class EducacionContinua : public Solicitante
{
private:
    int repetir;
public:
    EducacionContinua();
    EducacionContinua(string labSolicitado,string clase,string motivo,string perfil,string nombreI,double numeroI,string correoI,int cantidad,string infoGrupo,string equipo,string fecha,string horaInicio,string horaFin,int repetir);
    ~EducacionContinua();
    int getRepetir() const;
    void setRepetir(int newRepetir);

    virtual void Imprimir()const;
};

#endif // EDUCACIONCONTINUA_H
