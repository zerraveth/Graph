#include "bfsiterator.h"

BFSIterator::BFSIterator()
{
    initialize=true;
}
QString BFSIterator::getNextVertex(Graph *s)
{
    QString vertex="";
    if(!initialize){
        s->BFS.clear();
        s->updateG();
        this->maxId=s->ID;
        this->actualID=0;
        initialize=true;
        s->IDBFSIteratorBool=true;
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
                    koniec++;
                    vertices.push_back(nextId);
                }
            }
        }

    }

    //przekazywanie
    vertex=vertex+vertex.number(s->matrix[vertices[actualID]][0]);
    s->BFS.push_back(vertices[actualID]);
    actualID++;


    s->updateG();
    return vertex;
}
void BFSIterator::toDefault(){
     initialize=false;
      vertices.clear();
}
size_t BFSIterator::init(Graph *s)
{
    s->BFS.clear();
    s->updateG();
    this->maxId=s->ID;
    if(maxId==0) return 0;
    this->actualID=0;
    initialize=true;
    s->IDBFSIteratorBool=true;
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
                koniec++;
                vertices.push_back(nextId);
            }
        }
    }
    return koniec;
}
