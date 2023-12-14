#ifndef CFRAME_H
#define CFRAME_H
#include <iostream>

#include "solicitante.h"
#include "lista.h"

#include <QMainWindow>
using std::cout;
using std::string;
using std::ostream;

QT_BEGIN_NAMESPACE
namespace Ui { class cframe; }
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT
private:

    lista<Solicitante> solicitantes;
    bool verificarDisponibilidad(string laboratorio, const string& fecha, int horaInicioIndex, int horaFinIndex);
    string horas[10] = {"6:45","8:10","9:55","11:15","13:20","14:40","16:00","17:20","18:40","20:00"};
public:
    cframe(QWidget *parent = nullptr);
    ~cframe();


private slots:
    void on_rb_Alumno_clicked();
    void ocultarInicio();
    void mostrar();
    void limpiarAreas();
    bool revisarTodoLleno();

    void on_rb_Docente_clicked();
    void on_rb_Admin_clicked();
    void on_rb_EducacionC_clicked();
    void on_btn_Enviar_clicked();

    void on_pushButton_clicked();

private:
    Ui::cframe *ui;
};
#endif // CFRAME_H
