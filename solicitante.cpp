#include "solicitante.h"


const string &Solicitante::getLabSolicitado() const
{
    return labSolicitado;
}

void Solicitante::setLabSolicitado(const string &newLabSolicitado)
{
    labSolicitado = newLabSolicitado;
}

const string &Solicitante::getClase() const
{
    return clase;
}

void Solicitante::setClase(const string &newClase)
{
    clase = newClase;
}

const string &Solicitante::getMotivo() const
{
    return motivo;
}

void Solicitante::setMotivo(const string &newMotivo)
{
    motivo = newMotivo;
}

const string &Solicitante::getPerfil() const
{
    return perfil;
}

void Solicitante::setPerfil(const string &newPerfil)
{
    perfil = newPerfil;
}

const string &Solicitante::getNombreI() const
{
    return nombreI;
}

void Solicitante::setNombreI(const string &newNombreI)
{
    nombreI = newNombreI;
}

const string &Solicitante::getCorreoI() const
{
    return correoI;
}

void Solicitante::setCorreoI(const string &newCorreoI)
{
    correoI = newCorreoI;
}

const string &Solicitante::getInfoGrupo() const
{
    return infoGrupo;
}

void Solicitante::setInfoGrupo(const string &newInfoGrupo)
{
    infoGrupo = newInfoGrupo;
}

const string &Solicitante::getEquipo() const
{
    return equipo;
}

void Solicitante::setEquipo(const string &newEquipo)
{
    equipo = newEquipo;
}

const string &Solicitante::getFecha() const
{
    return fecha;
}

void Solicitante::setFecha(const string &newFecha)
{
    fecha = newFecha;
}

const string &Solicitante::getHoraInicio() const
{
    return horaInicio;
}

void Solicitante::setHoraInicio(const string &newHoraInicio)
{
    horaInicio = newHoraInicio;
}

const string &Solicitante::getHoraFin() const
{
    return horaFin;
}

void Solicitante::setHoraFin(const string &newHoraFin)
{
    horaFin = newHoraFin;
}

int Solicitante::getCantidad() const
{
    return cantidad;
}

void Solicitante::setCantidad(int newCantidad)
{
    cantidad = newCantidad;
}

double Solicitante::getNumeroI() const
{
    return numeroI;
}

void Solicitante::setNumeroI(double newNumeroI)
{
    numeroI = newNumeroI;
}

Solicitante::Solicitante()
{
    this->labSolicitado="";
    this->clase="";
    this->motivo="";
    this->perfil="";
    this->nombreI="";
    this->numeroI=0;
    this->correoI="";
    this->cantidad=0;
    this->infoGrupo="";
    this->equipo="";
    this->fecha="";
    this->horaInicio="";
    this->horaFin="";
    this->repetir=0;
}

Solicitante::Solicitante(string labSolicitado,string clase,string motivo,string perfil,string nombreI,double numeroI,string correoI,int cantidad,string infoGrupo,string equipo,string fecha,string horaInicio,string horaFin,int repetir)
{
    this->labSolicitado=labSolicitado;
    this->clase=clase;
    this->motivo=motivo;
    this->perfil=perfil;
    this->nombreI=nombreI;
    this->numeroI=numeroI;
    this->correoI=correoI;
    this->cantidad=cantidad;
    this->infoGrupo=infoGrupo;
    this->equipo=equipo;
    this->fecha=fecha;
    this->horaInicio=horaInicio;
    this->horaFin=horaFin;
    this->repetir=repetir;
}

Solicitante::~Solicitante()
{

}

void Solicitante::Imprimir() const{

}


