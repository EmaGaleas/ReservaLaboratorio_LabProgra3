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
    string labSolicitado,clase,motivo,perfil,nombreI,correoI, infoGrupo,equipo,fecha,numeroI;
    int cantidad,repetir;
    int horaInicio,horaFin;
public:
    Solicitante();
    Solicitante(string labSolicitado,string clase,string motivo,string perfil,string nombreI,string numeroI,string correoI,int cantidad,string infoGrupo,string equipo,string fecha,int horaInicio,int horaFin,int repetir);
    ~Solicitante();

    void Imprimir() const;

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

    int getCantidad() const;
    void setCantidad(int newCantidad);
    int getRepetir() const;
    void setRepetir(int newRepetir);
    int getHoraInicio() const;
    void setHoraInicio(int newHoraInicio);
    int getHoraFin() const;
    void setHoraFin(int newHoraFin);
    const string &getNumeroI() const;
    void setNumeroI(const string &newNumeroI);
};

#endif // SOLICITANTE_H
