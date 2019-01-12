#ifndef WRITER_H
#define WRITER_H
#include <QXmlStreamWriter>
#include <QtXml/QDomDocument>
#include <QFile>
#include "graph.h"
#include <QWidget>
class Writer : public QWidget
{
    Q_OBJECT
private:
    QFile *file;
public:
    //Writer(QWidget *parent = nullptr);
    Writer();
            void save(Graph *);
public slots:

};

#endif // WRITER_H
