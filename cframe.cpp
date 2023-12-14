#include "cframe.h"
#include "./ui_cframe.h"
#include <QImage>
#include <QPixmap>
#include <QLabel>

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{

    ui->setupUi(this);
    ocultarInicio();

    QImage info(":/3.png");
    QImage menu(":/0.png");
    ui->lbl_info->setPixmap(QPixmap::fromImage(info));
    ui->lbl_menu->setPixmap(QPixmap::fromImage(menu));
}

cframe::~cframe()
{
    delete ui;
}

void cframe::ocultarInicio()
{
    //ocultar labels al inicio
    ui->lb_Nombre1->setVisible(false);
    ui->lbl_Correo->setVisible(false);
    ui->lbl_Equipo->setVisible(false);
    ui->lbl_Fecha->setVisible(false);
    ui->lbl_HoraFin->setVisible(false);
    ui->lbl_HoraInicio->setVisible(false);
    ui->lbl_Integrantes->setVisible(false);
    ui->lbl_NombresGrupo->setVisible(false);
    ui->lbl_NumCuenta->setVisible(false);
    ui->lbl_Repetir->setVisible(false);
    //ocultar area donde se ingresan datos
    ui->led_Equipo->setVisible(false);
    ui->led_NombreIndi->setVisible(false);
    ui->led_NombresGrupo->setVisible(false);
    ui->led_NumCuentaIndi->setVisible(false);
    ui->spinB_NumeroIntegrantes->setVisible(false);
    ui->cbox_HoraFin->setVisible(false);
    ui->cbox_HoraInicio->setVisible(false);
    ui->cbox_Repetir->setVisible(false);
    ui->led_Correo->setVisible(false);
    ui->dateEdit_Fecha->setVisible(false);
    //ocultar boton de enviar y mensaje
    ui->lbl_informativo->setVisible(false);
    ui->btn_Enviar->setVisible(false);
    ui->lbl_LlenarTodo->setVisible(false);
}

void cframe::mostrar()
{
    //mostrar labels al inicio
    ui->lb_Nombre1->setVisible(true);
    ui->lbl_Correo->setVisible(true);
    ui->lbl_Equipo->setVisible(true);
    ui->lbl_Fecha->setVisible(true);
    ui->lbl_HoraFin->setVisible(true);
    ui->lbl_HoraInicio->setVisible(true);
    ui->lbl_Integrantes->setVisible(true);
    ui->lbl_NombresGrupo->setVisible(true);
    ui->lbl_NumCuenta->setVisible(true);
    ui->lbl_Repetir->setVisible(true);
    //mostrar area donde se ingresan datos
    ui->led_Correo->setVisible(true);
    ui->led_Equipo->setVisible(true);
    ui->led_NombreIndi->setVisible(true);
    ui->led_NombresGrupo->setVisible(true);
    ui->led_NumCuentaIndi->setVisible(true);
    ui->spinB_NumeroIntegrantes->setVisible(true);
    ui->cbox_HoraFin->setVisible(true);
    ui->cbox_HoraInicio->setVisible(true);
    ui->cbox_Repetir->setVisible(true);
    ui->dateEdit_Fecha->setVisible(true);
    //mostrar boton de enviar y mensaje
    ui->lbl_informativo->setVisible(true);
    ui->btn_Enviar->setVisible(true);
    if(ui->rb_Alumno->isChecked()){
        ui->lbl_Repetir->setVisible(false);
        ui->cbox_Repetir->setVisible(false);
    }else{
        ui->lbl_Repetir->setVisible(true);
        ui->cbox_Repetir->setVisible(true);
    }
}

void cframe::limpiarAreas()
{
    //limpiar areas donde se ingresan datos
    ui->led_Correo->setText("");
    ui->led_Equipo->setText("");
    ui->led_NombreIndi->setText("");
    ui->led_NombresGrupo->setText("");
    ui->led_NumCuentaIndi->setText("");
    ui->spinB_NumeroIntegrantes->setValue(1);
    ui->cbox_HoraFin->setCurrentIndex(0);
    ui->cbox_HoraInicio->setCurrentIndex(0);
    ui->cbox_Repetir->setCurrentIndex(0);
    ui->led_Clase->setText("");
    ui->led_Motivo->setText("");
    ui->cbox_labSolicitado->setCurrentIndex(0);
    ui->rb_Admin->setChecked(false);
    ui->rb_Alumno->setChecked(false);
    ui->rb_Docente->setChecked(false);
    ui->rb_EducacionC->setChecked(false);
    ocultarInicio();
}

bool cframe::revisarTodoLleno()
{
    if(ui->led_Correo->text().length()<=0){
        return false;
    }else if(ui->led_Equipo->text().length()<=0){
        return false;
    }else if(ui->led_NombreIndi->text().length()<=0){
        return false;
    }else if(ui->led_NombresGrupo->text().length()<=0){
        return false;
    }else if(ui->led_NumCuentaIndi->text().length()<=0){
        return false;
    }else if(ui->led_Clase->text().length()<=0){
        return false;;
    }else if(ui->led_Motivo->text().length()<=0){
        return false;
    }
    return true;

}


void cframe::on_rb_Docente_clicked()    { mostrar(); }

void cframe::on_rb_Admin_clicked()      { mostrar(); }

void cframe::on_rb_EducacionC_clicked() { mostrar(); }

void cframe::on_rb_Alumno_clicked()     { mostrar(); }

void cframe::on_btn_Enviar_clicked()

{
    if(revisarTodoLleno()){
        //string labSolicitado,string clase,string motivo,string perfil,string nombreI,double numeroI,string correoI,int cantidad,string infoGrupo,string equipo,string fecha,string horaInicio,string horaFin,int repetir

        //repetir: si es cero: no se repite.
        //si es uno: repite diario
        //si es dos: repite semanalmente

        string perfil = "";
        int repetir = 0;
        if(ui->rb_Alumno->isChecked()){
            perfil = "Alumno";
        }
        else {
            if(ui->rb_Admin->isChecked()){
                perfil = "Administrativo";
            }else if(ui->rb_Docente->isChecked()){
                perfil = "Docente";
            }else if(ui->rb_EducacionC->isChecked()){
                perfil = "Educacion continua";
            }
            repetir= ui->cbox_Repetir->currentIndex();
        }

        string labSolicitado = ui->cbox_labSolicitado->currentText().toStdString();
        string clase = ui->led_Clase->text().toStdString();
        string motivo = ui->led_Motivo->text().toStdString();
        //perfil ya esta definidio
        string nombreI = ui->led_NombreIndi->text().toStdString();
        double numeroI = ui->led_NumCuentaIndi->text().toDouble();
        string correoI = ui->led_Correo->text().toStdString();
        int cantidad = ui->spinB_NumeroIntegrantes->text().toInt();
        string infoGrupo = ui->led_NombresGrupo->text().toStdString();
        string equipo = ui->led_Equipo->text().toStdString();
        string fecha = ui->dateEdit_Fecha->text().toStdString();
        string horaInicio = ui->cbox_HoraInicio->currentText().toStdString();
        string horaFin = ui->cbox_HoraFin->currentText().toStdString();

        //string labSolicitado,string clase,string motivo,string perfil,string nombreI,double numeroI,string correoI,int cantidad,string infoGrupo,string equipo,string fecha,string horaInicio,string horaFin,int repetir
        std::cout<<labSolicitado<<clase<<motivo<<perfil<<nombreI<<numeroI<<correoI<<cantidad<<infoGrupo<<equipo<<fecha<<horaInicio<<horaFin<<repetir;
        Solicitante soli(labSolicitado, clase, motivo, perfil, nombreI, numeroI, correoI, cantidad, infoGrupo, equipo, fecha, horaInicio, horaFin, repetir);

        // Insert the instance into the list
        solicitantes.InsertarAlInicio(soli);
        limpiarAreas();
    }else{
        ui->lbl_LlenarTodo->setVisible(true);
    }
}


void cframe::on_pushButton_clicked()
{
    solicitantes.NewExcel();
}

