//
// Created by cris on 14/10/21.
//

#include "mapperWindow.h"

mapperWindow::mapperWindow() {
    crearVentana();
    enlazarConnects();
    cargaDePreguntasYSoluciones();
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

void mapperWindow::cargaDePreguntasYSoluciones() {

    QFile file("/home/cris/CLionProjects/QMapperTest/test.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }

    QStringList wordList;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        QList<QByteArray> lineaArray = line.split('#');
        QStringList listaPalabrasPorLinea;

        for(int i=0; i<lineaArray.size(); ++i){
            listaPalabrasPorLinea.append(lineaArray[i].constData());
        }

        QString pregunta =listaPalabrasPorLinea.takeFirst();

        for (int i = 0; i < listaPalabrasPorLinea.size(); ++i) {
            wordList.append(listaPalabrasPorLinea.at(i));
        }

        PreguntaRespuesta parPreguntaRespuesta;
        parPreguntaRespuesta.setPregunta(pregunta);
        parPreguntaRespuesta.setRespuestas(listaPalabrasPorLinea);
        parPreguntaRespuesta.setCorrect(listaPalabrasPorLinea.size() == 1);

        listadoPreguntasRespuesta.append(parPreguntaRespuesta);
    }
}
