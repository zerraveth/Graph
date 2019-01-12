#include "reader.h"

Reader::Reader()
{
    file=new QFile("grafy.xml");
}
void Reader::load(Graph *s){
    file->open(QIODevice::ReadOnly);
    QXmlStreamReader xmlReader(file);
    QString IDR;
    QString localIDR;
    QString vertexR;
    QString matrixQS;
    std::vector<int> tmp;
    size_t localIDst;
    int vertexST;
    int matrixST;
    if(xmlReader.readNextStartElement()){
        if(xmlReader.name()=="Graph"){
            while(xmlReader.readNextStartElement())
            {
                if(xmlReader.name()=="information")
                {
                    while(xmlReader.readNextStartElement())
                    {
                        if(xmlReader.name()=="ID")
                        {
                            IDR=xmlReader.readElementText();
                            s->ID=IDR.toULong();
                        }else xmlReader.skipCurrentElement();
                    }
                }
                else if(xmlReader.name()=="vertices")
                {
                    while(xmlReader.readNextStartElement())
                    {
                        if(xmlReader.name()=="ID")
                        {
                            localIDR=xmlReader.readElementText();
                            localIDst=localIDR.toULong();
                            //s->matrix.insert(std::pair<size_t,std::vector<int>>(localIDst,{}));
                        }else if(xmlReader.name()=="vertex")
                        {
                            vertexR=xmlReader.readElementText();
                            vertexST=vertexR.toInt();
                            s->matrix[localIDst].push_back(vertexST);
                        }else if(xmlReader.name()=="matrix"){
                            matrixQS=xmlReader.readElementText();
                            matrixST=matrixQS.toInt();
                            s->matrix[localIDst].push_back(matrixST);
                        }else xmlReader.skipCurrentElement();
                    }
                }else
                {
                    xmlReader.skipCurrentElement();
                }
            }

        }
    }
   file->close();
}
