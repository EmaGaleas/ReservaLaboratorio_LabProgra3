#include "educacioncontinua.h"

int EducacionContinua::getRepetir() const
{
    return repetir;
}

void EducacionContinua::setRepetir(int newRepetir)
{
    repetir = newRepetir;
}

void EducacionContinua::Imprimir() const
{
    Solicitante::Imprimir();
    std::cout<<"EDU CONTINUA";


}

EducacionContinua::EducacionContinua() :Solicitante()
{
    this->repetir=0;
}

EducacionContinua::EducacionContinua(std::string labSolicitado, std::string clase, std::string motivo, std::string perfil, std::string nombreI, double numeroI, std::string correoI, int cantidad, std::string infoGrupo, std::string equipo, std::string fecha, std::string horaInicio, std::string horaFin, int repetir)
    : Solicitante(labSolicitado,clase,motivo,perfil,nombreI,numeroI,correoI,cantidad,infoGrupo,equipo,fecha,horaInicio,horaFin)
{
    this->repetir=repetir;
}

EducacionContinua::~EducacionContinua(){}



