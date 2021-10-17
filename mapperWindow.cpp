//
// Created by cris on 14/10/21.
//


#include <search.h>
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
    connect(botonSalir,&QPushButton::clicked,this, &mapperWindow::salvarTodo);
    connect(botonDeBusqueda,
            &QPushButton::clicked,this,&mapperWindow::busqueda);
    connect(botonAnnadir,&QPushButton::clicked,this,&mapperWindow::annadirPreguntaADocumento);
}

void mapperWindow::cargaDePreguntasYSoluciones() {

    QFile file("test.csv");
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
    file.close();
}

void mapperWindow::busqueda() {
    QString textoPregunta = buscaPregunta->toPlainText();
    QStringList respuestas;

    for(PreguntaRespuesta iteracion: listadoPreguntasRespuesta){
        if(iteracion.getPregunta() == textoPregunta){
            respuestas = iteracion.getRespuestas();
            break;
        }
    }

    solucion->setText(respuestas.join('\n'));
}

void mapperWindow::annadirPreguntaADocumento() {

    PreguntaRespuesta nueva;
    nueva.setCorrect(check->isChecked());
    nueva.setPregunta(textoPregunta->toPlainText());
    nueva.setRespuestas(textoRespuesta->toPlainText().split('\n'));
    bool correcta = check->isChecked();

    bool encontrado = false;

    for ( int i =0 ; i<listadoPreguntasRespuesta.size();++i){
        PreguntaRespuesta aux= listadoPreguntasRespuesta.at(i);
        if(aux.getPregunta() == nueva.getPregunta()){
            PreguntaRespuesta modificada = aux;
            modificada.appendRespuesta(nueva.getRespuestas().join("#"));
            listadoPreguntasRespuesta.removeAt(i);
            listadoPreguntasRespuesta.append(modificada);
            return;
        }
    }
    if(!encontrado){
        listadoPreguntasRespuesta.append(nueva);

        QFile archivo("test.csv");
        if(archivo.open(QIODevice::Append | QIODevice::Text)){
            QTextStream datosArchivo(&archivo);
            datosArchivo << nueva.getPregunta()<<"#";
            datosArchivo << nueva.getRespuestas().join('#');

        }
        archivo.close();
    }



}

void mapperWindow::salvarTodo() {
    QFile archivo("test.csv");
    if(archivo.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream datosArchivo(&archivo);

        for(PreguntaRespuesta aux: listadoPreguntasRespuesta){
            datosArchivo << aux.getPregunta()<<"#";
            for(QString respuesta: aux.getRespuestas()){
                datosArchivo << respuesta <<"#";
            }
            datosArchivo<<"\n";
        }


    }
    archivo.close();
    close();
}


