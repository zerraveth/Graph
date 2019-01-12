#include "writer.h"
/*
Writer::Writer(QWidget *parent)
    : QWidget(parent)
{
    file=new QFile("grafy.xml");

}
*/
Writer::Writer()

{
    file=new QFile("grafy.xml");

}
void Writer::save(Graph* s){
    QString ver;
    QString sasiad;
     file->open(QIODevice::WriteOnly);


     QXmlStreamWriter xmlWriter(file);
     xmlWriter.setAutoFormatting(true);
     xmlWriter.writeStartDocument();
     xmlWriter.writeStartElement("Graph");
     xmlWriter.writeStartElement("information");
     ver=""+ver.number(s->ID);
     xmlWriter.writeTextElement("ID",ver);
     xmlWriter.writeEndElement();
    for(size_t i=0;i<s->ID;i++){
        if(!s->matrix.count(i)) continue;

        xmlWriter.writeStartElement("vertices");
        ver=""+ver.number(i);
        xmlWriter.writeTextElement("ID",ver);
        ver=""+ver.number(s->matrix[i][0]);
        xmlWriter.writeTextElement("vertex", ver);
        for(size_t j=1;j<s->matrix[i].size();j++)
        {
            sasiad=""+sasiad.number(s->matrix[i][j]);
        xmlWriter.writeTextElement("matrix", sasiad );
        }


        xmlWriter.writeEndElement();


    }
    xmlWriter.writeEndElement();

    xmlWriter.writeEndDocument();

    file->close();
     //ShowXmlOnScreen();
     //statusBar()->showMessage(tr("Xml Saved"));
}

