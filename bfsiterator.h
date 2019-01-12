#ifndef BFSITERATOR_H
#define BFSITERATOR_H
#include <QString>
#include "graph.h"

class BFSIterator
{
private:
    size_t maxId;
    size_t actualID;
    bool initialize;
    std::map<size_t,bool> tmp;
    std::vector<size_t> vertices;
public:
    BFSIterator();
    QString getNextVertex(Graph *);
    void toDefault();
    size_t init(Graph *s);
};

#endif // BFSITERATOR_H
