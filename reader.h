#ifndef READER_H
#define READER_H
#include <QtXml/QDomDocument>
#include <QFile>
#include "graph.h"
#include <QXmlStreamReader>
class Reader
{
private:
    QFile *file;
public:
    Reader();
    void load(Graph *);
};

#endif // READER_H
