#include "dfsiterator.h"

DFSIterator::DFSIterator()
{

}
size_t DFSIterator::init(Graph *s)
{
    s->updateG();
    this->maxId=s->ID;
    this->actualID=0;
        if(maxId==0) return 0;
    s->IDDFSIteratorBool=true;
    //stratowy element
    size_t firstId;
    for(size_t i=0;i<maxId;i++){
        if(s->matrix.count(i)){
            firstId=i;
            break;
        }
    }
    vertices.push_back(firstId);
    size_t koniec=1;

    bool exit=true;
    do
    {
            bool dodalo=false;
        for(size_t i=0;i<koniec;i++){
            size_t idlocal=vertices[i];
            for(size_t j=1;j<s->matrix[idlocal].size();j++){
                size_t nextId=s->matrix[idlocal][j];
                //sprawdzamy czy jest id
                bool istnieje=false;
                for(size_t k=0;k<vertices.size();k++){
                    if(vertices[k]==nextId)
                    {
                        istnieje=true;
                        break;
                    }
                }
                if(!istnieje){
                    dodalo=true;
                    koniec++;
                    vertices.push_back(nextId);
                    break;
                }

            }
            if(!dodalo) exit=false;
        }
    }while(exit);

    return koniec;
}
void DFSIterator::toDefault(Graph *s)
{
      s->IDDFSIteratorBool=false;
      s->DFS.clear();
      vertices.clear();
      s->updateG();
}
QString DFSIterator::getNextVertex(Graph *s){
    QString vertex="";
    vertex=vertex+vertex.number(s->matrix[vertices[actualID]][0]);
    s->DFS.push_back(vertices[actualID]);
    actualID++;
    s->updateG();
    return vertex;
}
