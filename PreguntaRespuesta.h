//
// Created by cris on 16/10/21.
//

#ifndef QMAPPERTEST_PREGUNTARESPUESTA_H
#define QMAPPERTEST_PREGUNTARESPUESTA_H


#include <QString>
#include <QStringList>

class PreguntaRespuesta {
public:

    bool isCorrect();
    void setCorrect(bool value);

    QString getPregunta();
    void setPregunta(QString pregunta);

    QStringList getRespuestas();
    void setRespuestas(QStringList respuestas);

private:
    QString pregunta;
    bool correcta;
    QStringList respuestas;
};


#endif //QMAPPERTEST_PREGUNTARESPUESTA_H
