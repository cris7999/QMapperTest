//
// Created by cris on 14/10/21.
//

#ifndef QMAPPERTEST_MAPPERWINDOW_H
#define QMAPPERTEST_MAPPERWINDOW_H
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QFile>
#include <QStringList>
#include <QDebug>

class mapperWindow : public QWidget{
public:
    mapperWindow();

private:

    void crearVentana();
    void enlazarConnects();
    QString busquedaDeSolucion();
    ///Atributos:

    //Pregunta
    QLabel* pregunta;
    QVBoxLayout* mainLayout;
    QVBoxLayout* buscador;
    QHBoxLayout* lineaDePregunta;
    QTextEdit* buscaPregunta;
    QLabel* solucionLabel;
    QTextEdit* solucion;
    QPushButton* botonDeBusqueda;

    QLabel* annadirPregunta;
    //Añadir

    QVBoxLayout* incorporador;
    QHBoxLayout* lineaPreguntaAnnadir;
    QHBoxLayout* lineaRespuestaAnnadir;
    QHBoxLayout* lineaCorrectaAnnadir;
    QHBoxLayout* lineaBotonesFin;
    QLabel* preguntaAnnadir;
    QTextEdit* textoPregunta;
    QLabel* correcta;
    QCheckBox* check;
    QLabel* respuesta;
    QTextEdit* textoRespuesta;
    QPushButton* botonAnnadir;

    QPushButton* botonSalir;

};


#endif //QMAPPERTEST_MAPPERWINDOW_H
