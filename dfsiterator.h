#ifndef DFSITERATOR_H
#define DFSITERATOR_H
#include <QString>
#include "graph.h"

class DFSIterator
{
private:
    size_t maxId;
    size_t actualID;
    std::vector<size_t> vertices;
public:
    DFSIterator();
    size_t init(Graph *);
    QString getNextVertex(Graph *);
    void toDefault(Graph *);
};

#endif // DFSITERATOR_H
