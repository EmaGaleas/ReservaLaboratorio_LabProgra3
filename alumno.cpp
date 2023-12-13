#include "alumno.h"



Alumno::Alumno():Solicitante()
{}

Alumno::Alumno(std::string labSolicitado, std::string clase, std::string motivo, std::string perfil, std::string nombreI, double numeroI, std::string correoI, int cantidad, std::string infoGrupo, std::string equipo, std::string fecha, std::string horaInicio, std::string horaFin)
 : Solicitante(labSolicitado,clase,motivo,perfil,nombreI,numeroI,correoI,cantidad,infoGrupo,equipo,fecha,horaInicio,horaFin)
{

}

Alumno::~Alumno()
{}

void Alumno::Imprimir() const
{
    Solicitante::Imprimir();
    std::cout<<"ALUMNO";

}
