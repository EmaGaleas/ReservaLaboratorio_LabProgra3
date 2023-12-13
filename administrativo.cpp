#include "administrativo.h"

Administrativo::Administrativo():Solicitante()
{
    this->repetir=0;
}

Administrativo::Administrativo(std::string labSolicitado, std::string clase, std::string motivo, std::string perfil, std::string nombreI, double numeroI, std::string correoI, int cantidad, std::string infoGrupo, std::string equipo, std::string fecha, std::string horaInicio, std::string horaFin, int repetir)
    : Solicitante(labSolicitado,clase,motivo,perfil,nombreI,numeroI,correoI,cantidad,infoGrupo,equipo,fecha,horaInicio,horaFin)
   {
       this->repetir=repetir;
   }

Administrativo::~Administrativo(){}

int Administrativo::getRepetir() const
{
    return repetir;
}

void Administrativo::setRepetir(int newRepetir)
{
    repetir = newRepetir;
}

void Administrativo::Imprimir() const
{
    Solicitante::Imprimir();
    std::cout<<"ADMIN";
}

