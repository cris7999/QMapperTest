//
// Created by cris on 14/10/21.
//

#include "mapperWindow.h"

mapperWindow::mapperWindow() {
    crearVentana();
    enlazarConnects();
    busquedaDeSolucion();
}


void mapperWindow::crearVentana() {
//Busqueda de pregunta
    pregunta= new QLabel();
    pregunta->setText("Pregunta:");
    buscaPregunta = new QTextEdit();
    botonDeBusqueda = new QPushButton();
    botonDeBusqueda->setText("Buscar");
    solucion = new QTextEdit();
    solucion->setReadOnly(true);
    solucionLabel = new QLabel();
    solucionLabel->setText("Solución/es:");

    lineaDePregunta = new QHBoxLayout();
    lineaDePregunta->addWidget(pregunta);
    lineaDePregunta->addWidget(buscaPregunta);
    lineaDePregunta->addWidget(botonDeBusqueda);


    buscador = new QVBoxLayout();
    buscador->addLayout(lineaDePregunta);
    buscador->addWidget(botonDeBusqueda);
    buscador->addWidget(solucionLabel);
    buscador->addWidget(solucion);

    //Añadir pregunta
    annadirPregunta = new QLabel();
    annadirPregunta->setText("Añadir:");
    preguntaAnnadir = new QLabel();
    preguntaAnnadir->setText("Pregunta:");

    lineaPreguntaAnnadir = new QHBoxLayout();
    lineaPreguntaAnnadir->addWidget(preguntaAnnadir);
    textoPregunta = new QTextEdit();
    lineaPreguntaAnnadir->addWidget(textoPregunta);

    correcta = new QLabel();
    correcta->setText("Correcta:");
    lineaCorrectaAnnadir = new QHBoxLayout();
    lineaCorrectaAnnadir->addWidget(correcta);
    check = new QCheckBox();
    lineaCorrectaAnnadir->addWidget(check);

    respuesta = new QLabel();
    respuesta->setText("Respuesta:");
    lineaRespuestaAnnadir = new QHBoxLayout();
    lineaRespuestaAnnadir->addWidget(respuesta);
    textoRespuesta = new QTextEdit();
    lineaRespuestaAnnadir->addWidget(textoRespuesta);

    incorporador = new QVBoxLayout();
    incorporador->addWidget(annadirPregunta);
    incorporador->addLayout(lineaPreguntaAnnadir);
    incorporador->addLayout(lineaCorrectaAnnadir);
    incorporador->addLayout(lineaRespuestaAnnadir);



    mainLayout= new QVBoxLayout(this);


    mainLayout->addWidget(pregunta);
    mainLayout->addLayout(buscador);

    mainLayout->addWidget(annadirPregunta);
    mainLayout->addLayout(incorporador);

    botonAnnadir = new QPushButton();
    botonAnnadir->setText("Añadir pregunta");
    botonSalir = new QPushButton();
    botonSalir->setText("Salir");

    mainLayout->addWidget(botonAnnadir);
    mainLayout->addWidget(botonSalir);
}

void mapperWindow::enlazarConnects() {
    connect(botonSalir, SIGNAL(clicked()),this, SLOT(close()));
}

QString mapperWindow::busquedaDeSolucion() {

    QFile file("/home/cris/CLionProjects/QMapperTest/test.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return "error";
    }

    QStringList wordList;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();

        wordList.append(line.split('###').first());
    }

    qDebug() << wordList;
    textoRespuesta->setText(wordList.join("#"));
    return "wordList";
}
