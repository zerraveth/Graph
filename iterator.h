#ifndef ITERATOR_H
#define ITERATOR_H
#include <QString>
#include "graph.h"
class Iterator
{
private:
    size_t iteratorId;
    size_t maxId;
    bool initialize;
public:
    Iterator();
    QString getNextVertex(Graph *);
    void toDefault();
    size_t init(Graph *);
};

#endif // ITERATOR_H
