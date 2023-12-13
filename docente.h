#ifndef DOCENTE_H
#define DOCENTE_H
#include "solicitante.h"

class Docente : public Solicitante
{
private:
    int repetir;
public:
    Docente();
    Docente(string labSolicitado,string clase,string motivo,string perfil,string nombreI,double numeroI,string correoI,int cantidad,string infoGrupo,string equipo,string fecha,string horaInicio,string horaFin,int repetir);
    ~Docente();

    int getRepetir() const;
    void setRepetir(int newRepetir);

    virtual void Imprimir()const;
};

#endif // DOCENTE_H
