#include "iterator.h"

Iterator::Iterator()
{
    initialize=false;
}
size_t Iterator::init(Graph *s){
    return s->matrix.size();
}
QString Iterator::getNextVertex(Graph *s)
{
    QString vertex;
    if(!initialize){
        this->maxId=s->ID;
        this->iteratorId=0;
        initialize=true;
        s->IDIteratorBool=true;
    }
    for(size_t i=iteratorId;iteratorId<maxId;i++){
        if(!s->matrix.count(i)){
            iteratorId++;
            continue;
        }else{
            vertex=vertex.number(s->matrix[i][0]);
            break;
        }
    }
    s->IDIterator=iteratorId;
    iteratorId++;
    s->updateG();
    return vertex;
}
void Iterator::toDefault(){
     initialize=false;

}
