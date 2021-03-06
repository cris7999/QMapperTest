//
// Created by cris on 16/10/21.
//

#include "PreguntaRespuesta.h"

void PreguntaRespuesta::setRespuestas(QStringList respuestas) {
    this->respuestas=respuestas;
}

bool PreguntaRespuesta::isCorrect() {
    return correcta;
}

void PreguntaRespuesta::setCorrect(bool value) {
    correcta=value;
}

QString PreguntaRespuesta::getPregunta() const {
    return pregunta;
}

void PreguntaRespuesta::setPregunta(QString pregunta) {
    this->pregunta = pregunta;
}

QStringList PreguntaRespuesta::getRespuestas() {
    return respuestas;
}

void PreguntaRespuesta::appendRespuesta(QString respuesta) {
    respuestas.append(respuesta);
}
