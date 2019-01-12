#ifndef GRAPH_H
#define GRAPH_H
#include <QWidget>
#include <map>
#include <vector>
#include <QPoint>
#include <QPainter>
#include <cmath>
#include <QString>
#include <QInputDialog>

#include <QBrush>
class Graph : public QWidget
{
    Q_OBJECT

private:
    size_t ID;
    std::map<size_t,std::vector<int>> matrix; // 0 <-wartosc,
    std::map<size_t,QPoint> position;
    int sizeVer;
    size_t IDIterator;
    bool IDIteratorBool;
    bool IDBFSIteratorBool;
    bool IDDFSIteratorBool;
    std::vector<size_t> BFS;
    std::vector<size_t> DFS;
    void reworkMatrix();
public:
    friend class Writer;
    friend class Reader;
    friend class Iterator;
    friend class BFSIterator;
    friend class DFSIterator;
    Graph(QWidget *parent = nullptr);
    void modifyVertex(QPoint);
    void deleteVertex(QPoint);
    void addVertexTwo(QPoint);
    void addNewRoad(size_t,size_t);
    int checkPosition(QPoint);
    int getCountVertex();
    void updateG();
    void boolToFalse();
protected:
    void paintEvent(QPaintEvent *event) override;
public slots:
    void addNewVertex();
};

#endif // GRAPH_H
