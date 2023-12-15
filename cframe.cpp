#include "cframe.h"
#include "./ui_cframe.h"
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <istream>
#include <iostream>
#include <string>
#include <sstream>


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
    QImage tit(":/unitec edificio1.jpg");
    ui->lbl_Titulo->setPixmap(QPixmap::fromImage(tit));

    //CargarSoli("export.xls");

}

cframe::~cframe()
{
    solicitantes.NewExcel();
    delete ui;
}

bool cframe::CargarSoli(std::string Nombre)
{
    std::ifstream Archivo("export.xls",ios::in);
    std::cout<<"f";

    if(!Archivo){
        std::cout<<"f-1";
        return false;
    }else{
        // Solicitante soli(labSolicitado, clase, motivo, perfil, nombreI, numeroI, correoI, cantidad, infoGrupo, equipo, fecha, horaInicio, horaFin, repetir);
        std::cout<<"f0";
        do {

            std::cout<<"f1";

            Archivo >> labSolicitado >> clase >> motivo >> perfil >> nombreI >> numeroI >> correoI >> cant >> infoGrupo >> equipo >> fecha >> horaI >> horaF >> repe;
            std::cout<<"f2";

            cantidad=std::stoi(cant);
            horaInicio=std::stoi(horaI);
            horaFin=std::stoi(horaF);

            if(repe=="NUNCA"){
                repetir=0;
            }else if(repe=="A DIARIO"){
                repetir=1;
            }else{
                repetir=2;
            }
           // std::cout<< labSolicitado << clase << motivo <<perfil << nombreI<<numeroI << correoI << cantidad << infoGrupo << equipo << fecha << horaInicio << horaFin << repe;
            if (!Archivo.eof()) {
                s= new  Solicitante(labSolicitado,clase,motivo,perfil,nombreI, numeroI,correoI,cantidad,infoGrupo,equipo,fecha, horaInicio, horaFin, repetir);
                //Solicitante soli(labSolicitado,clase,motivo,perfil,nombreI, numeroI,correoI,cantidad,infoGrupo,equipo,fecha, horaInicio, horaFin, repetir);
                SS.InsertarAlInicio(s);
            }
        }while(!Archivo.eof());
    }
    Archivo.close();
    return true;

}
//bool cframe::CargarAlumnos(string Gracia)
//{
//    ifstream Archivo(Gracia.data(),ios::in);
//    if(!Archivo){
//        return false;
//    }else{
//        do{
//            Archivo>>Cuenta>>Nombre>>Correo>>Celular;
//            if(!Archivo.eof()){
//                u = new alumno(Cuenta,Nombre,Correo,Celular);
//                U.InsertarAlInicio(u);
//                //QMessageBox::information(this,".:.",QString::fromStdString(Nombre));
//            }
//        }while(!Archivo.eof());
//    }
//    Archivo.close();
//    return true;
//}

void cframe::ocultarInicio()
{
    QImage tit(":/unitec edificio1.jpg");
    ui->lbl_Titulo->setPixmap(QPixmap::fromImage(tit));
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
    QImage tit(":/unitec negro.png");
    ui->lbl_Titulo->setPixmap(QPixmap::fromImage(tit));
    ui->lbl_Titulo->setScaledContents(false);
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
        string nombreI = ui->led_NombreIndi->text().toStdString();
        string numeroI = ui->led_NumCuentaIndi->text().toStdString();
        // Eliminar cualquier punto decimal y dígitos posteriores
        size_t puntoDecimal = numeroI.find('.');
        if (puntoDecimal != std::string::npos) {
            numeroI = numeroI.substr(0, puntoDecimal);
        }
        string correoI = ui->led_Correo->text().toStdString();
        int cantidad = ui->spinB_NumeroIntegrantes->text().toInt();
        string infoGrupo = ui->led_NombresGrupo->text().toStdString();
        string equipo = ui->led_Equipo->text().toStdString();
        string fecha = ui->dateEdit_Fecha->text().toStdString();
        int horaInicio = ui->cbox_HoraInicio->currentIndex();
        int horaFin = ui->cbox_HoraFin->currentIndex()+2;

        cout<<horaInicio-horaFin;
        //string labSolicitado,string clase,string motivo,string perfil,string nombreI,string numeroI,string correoI,int cantidad,string infoGrupo,string equipo,string fecha,string horaInicio,string horaFin,int repetir
        Solicitante soli(labSolicitado, clase, motivo, perfil, nombreI, numeroI, correoI, cantidad, infoGrupo, equipo, fecha, horaInicio, horaFin, repetir);
        if(numeroI.length()==8 && esCorreoUnitec(correoI) && verificarDisponibilidad(labSolicitado,fecha,horaInicio,horaFin) && horaFin>horaInicio){
            //NUNCA SE REPITE
            if(soli.getRepetir() == 0){
                //las horas de reserva son largas
                if((soli.getHoraFin()) - (soli.getHoraInicio()) > 1){
                    int horaini = soli.getHoraInicio();
                    int horafi = soli.getHoraInicio()+1;
                    while(horafi!=soli.getHoraFin()){
                        Solicitante soli2(labSolicitado, clase, motivo,perfil,nombreI, numeroI,correoI,cantidad,infoGrupo,equipo,fecha,horaini,horafi,repetir);
                        horaini++;
                        horafi++;
                        solicitantes.InsertarAlInicio(soli2);
                    }
                    //if de si la hora de reserva nada mas es una y nunca se repite
                }else if(soli.getHoraFin() - soli.getHoraInicio() == 1){
                    solicitantes.InsertarAlInicio(soli);
                }
                //SE REPITE DIARIAMENTE
            } else {
                // Asumiendo que la fecha es "dd/mm/yyyy"
                string fecha = soli.getFecha();
                string anio = "";
                anio += fecha.at(6);
                anio += fecha.at(7);
                anio += fecha.at(8);
                anio += fecha.at(9);
                cout << anio;
                QDate fechaLimite(2024, 1,1); // Fecha limite: 1 de enero de 2024

                if (soli.getRepetir() == 1) {
                    QDate fechaInicio = QDate::fromString(QString::fromStdString(soli.getFecha()), "dd/MM/yyyy");
                    QDate fechaLimite(2024, 1, 1); // Fecha limite: 1 de enero de 2024

                    // Si la reserva dura solo una hora
                    if (soli.getHoraFin() - soli.getHoraInicio() == 1) {
                        while (fechaInicio <= fechaLimite) {
                            Solicitante soliDiaria(labSolicitado, clase, motivo, perfil, nombreI, numeroI, correoI, cantidad, infoGrupo, equipo, fechaInicio.toString("dd/MM/yyyy").toStdString(), horaInicio, horaFin, repetir);
                            solicitantes.InsertarAlInicio(soliDiaria);
                            fechaInicio = fechaInicio.addDays(1); // Incrementa un dia
                        }
                    } else {
                        // Si la reserva es de más de una hora
                        while (fechaInicio <= fechaLimite) {
                            int horaini = horaInicio;
                            int horafi = horaInicio + 1;
                            while (horafi <= horaFin) {
                                Solicitante soliDiaria(labSolicitado, clase, motivo, perfil, nombreI, numeroI, correoI, cantidad, infoGrupo, equipo, fechaInicio.toString("dd/MM/yyyy").toStdString(), horaini, horafi, repetir);
                                solicitantes.InsertarAlInicio(soliDiaria);
                                horaini++;
                                horafi++;
                            }
                            fechaInicio = fechaInicio.addDays(1); // Incrementa un dia
                        }
                    }
                }
                else if (soli.getRepetir() == 2) { // Repetir semanalmente
                    QDate fechaInicio = QDate::fromString(QString::fromStdString(soli.getFecha()), "dd/MM/yyyy");
                    QDate fechaLimite(2024, 1, 1); // Fecha limite: 1 de enero de 2024

                    // Si la reserva dura solo una hora
                    if (soli.getHoraFin() - soli.getHoraInicio() == 1) {
                        while (fechaInicio <= fechaLimite) {
                            Solicitante soliSemanal(labSolicitado, clase, motivo, perfil, nombreI, numeroI, correoI, cantidad, infoGrupo, equipo, fechaInicio.toString("dd/MM/yyyy").toStdString(), horaInicio, horaFin, repetir);
                            solicitantes.InsertarAlInicio(soliSemanal);
                            fechaInicio = fechaInicio.addDays(7); // Incrementa una semana
                        }
                    } else {
                        // Si la reserva es de más de una hora
                        while (fechaInicio <= fechaLimite) {
                            int horaini = horaInicio;
                            int horafi = horaInicio + 1;
                            while (horafi <= horaFin) {
                                Solicitante soliSemanal(labSolicitado, clase, motivo, perfil, nombreI, numeroI, correoI, cantidad, infoGrupo, equipo, fechaInicio.toString("dd/MM/yyyy").toStdString(), horaini, horafi, repetir);
                                solicitantes.InsertarAlInicio(soliSemanal);
                                horaini++;
                                horafi++;
                            }
                            fechaInicio = fechaInicio.addDays(7); // Incrementa una semana
                        }
                    }
                }
            }
            limpiarAreas();
        } else {
            if(!verificarDisponibilidad(labSolicitado,fecha,horaInicio,horaFin)){
                ui->lbl_LlenarTodo->setText("EL LABORATORIO ESCOGIDO ESTA OCUPADO");
            }
            else if(!esCorreoUnitec(correoI)){
                ui->lbl_LlenarTodo->setText("EL CORREO NO ESTA EN EL FORMATO DESEADO");
            } else if (horaInicio >= horaFin){
                ui->lbl_LlenarTodo->setText("LAS HORAS DE INICIO Y FINAL NO ESTAN BIEN ESCOGIDAS");
            } else if (numeroI.length()!=8){
                ui->lbl_LlenarTodo->setText("EL NUMERO DE CUENTA NO ES DE 8 CARACTERES");
            }
            ui->lbl_LlenarTodo->setVisible(true);
        }
    }else{
        ui->lbl_LlenarTodo->setText("DEBE LLENAR TODOS LOS ESPACIOS");
        ui->lbl_LlenarTodo->setVisible(true);
    }
}

bool cframe::esCorreoUnitec(const string &correo)
{
    std::string dominio = "unitec.edu";
    size_t posicionArroba = correo.find('@');
    // Verificar @ y si el dominio coincide
    if (posicionArroba != std::string::npos) {
        std::string dominioCorreo = correo.substr(posicionArroba + 1);
        return dominioCorreo == dominio;
    }

    return false;
}

bool cframe::verificarDisponibilidad(string laboratorio, const string& fecha, int horaInicioIndex, int horaFinIndex) {
    for (nodo<Solicitante>* actual = solicitantes.raizPtr; actual != nullptr; actual = actual->SigPtr) {
        Solicitante& reservaActual = actual->dato;
        if (reservaActual.getLabSolicitado() == laboratorio && reservaActual.getFecha() == fecha) {
            // Verificar si las horas se solapan
            if (!(horaInicioIndex >= reservaActual.getHoraFin() || horaFinIndex <= reservaActual.getHoraInicio())) {
                return false; // no se puede
            }
        }
    }
    return true;
}


