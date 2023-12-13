#ifndef SOLICITANTE_H
#define SOLICITANTE_H
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Solicitante
{
private:
    //labSolicitado,clase,motivo,perfil(que es),nombreI,numeroI,correoI,cantidad,infoGrupo,equipo,fecha,horaInicio,HoraFin
    string labSolicitado,clase,motivo,perfil,nombreI,correoI, infoGrupo,equipo,fecha,horaInicio,horaFin;
    int cantidad;
    double numeroI;
public:
    Solicitante();
    Solicitante(string labSolicitado,string clase,string motivo,string perfil,string nombreI,double numeroI,string correoI,int cantidad,string infoGrupo,string equipo,string fecha,string horaInicio,string horaFin);
    ~Solicitante();

    virtual void Imprimir() const = 0;

    const string &getLabSolicitado() const;
    void setLabSolicitado(const string &newLabSolicitado);
    const string &getClase() const;
    void setClase(const string &newClase);
    const string &getMotivo() const;
    void setMotivo(const string &newMotivo);
    const string &getPerfil() const;
    void setPerfil(const string &newPerfil);
    const string &getNombreI() const;
    void setNombreI(const string &newNombreI);
    const string &getCorreoI() const;
    void setCorreoI(const string &newCorreoI);
    const string &getInfoGrupo() const;
    void setInfoGrupo(const string &newInfoGrupo);
    const string &getEquipo() const;
    void setEquipo(const string &newEquipo);
    const string &getFecha() const;
    void setFecha(const string &newFecha);
    const string &getHoraInicio() const;
    void setHoraInicio(const string &newHoraInicio);
    const string &getHoraFin() const;
    void setHoraFin(const string &newHoraFin);
    int getCantidad() const;
    void setCantidad(int newCantidad);
    double getNumeroI() const;
    void setNumeroI(double newNumeroI);
};

#endif // SOLICITANTE_H
