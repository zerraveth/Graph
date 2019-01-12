#include "graph.h"

Graph::Graph(QWidget *parent)
    : QWidget(parent)
{
    this->sizeVer=100;
    this->ID=0;
    this->IDIterator=0;
    this->IDIteratorBool=false;
    //this->actualIDBfs=0;
    //this->matrix.insert(std::pair<size_t,std::vector<int>>(0,{6,2}));
    //this->matrix.insert(std::pair<size_t,std::vector<int>>(1,{8,3}));
    //this->matrix.insert(std::pair<size_t,std::vector<int>>(2,{22,4}));
    //this->matrix.insert(std::pair<size_t,std::vector<int>>(3,{5,0}));
    //this->matrix.insert(std::pair<size_t,std::vector<int>>(4,{3,1}));

}
void Graph::paintEvent(QPaintEvent *event){
    position.clear();
    if(!matrix.empty()){
        QPainter painter(this);
        QSize size = this->size();
        const int posX=size.width()/2;
        const int posY=size.height()/2;
        int newRadius=200;
        const int circle=360;
        //size_t vertices_ilosc=matrix.size();
        double skok=circle/ID;


        for(size_t i=0;i<this->ID;i++){
            if(!matrix.count(i)) continue;
            int xpos=int((newRadius)*cos((i*skok)/360.*2.*3.14159));
            int ypos=int((newRadius)*sin((i*skok)/360.*2.*3.14159));
            xpos+=posX;
            ypos+=posY;
            QPoint verticesPosition;
            verticesPosition.setX(xpos);
            verticesPosition.setY(ypos);
            position.insert(std::pair<int,QPoint>(i,verticesPosition));
            if(matrix.count(i))
            {
                int ss = matrix[i].at(0);
                painter.drawEllipse(xpos,ypos,sizeVer,sizeVer);
                painter.drawText(xpos+(int(0.45*sizeVer)),ypos+(int(0.2*sizeVer)),QString::number(ss));
                if(IDIteratorBool && i<=IDIterator)
                {
                    QString Ite="I: ";
                    Ite=Ite+Ite.number(i);
                painter.drawText(xpos+(int(0.45*sizeVer)),ypos+(int(0.8*sizeVer)),Ite);
                }

            }

        }

        for(size_t i=0;i<ID;i++)
        {
            if(!matrix.count(i)) continue;
            for(size_t j=1;j<matrix[i].size();j++){
                if(matrix.count(i)){
                    int firstX=position[i].x()+int(0.5*sizeVer);
                    int firstY=position[i].y()+int(0.5*sizeVer);
                    if(position.count(size_t(matrix[i][j]))){
                        int secondX=position[size_t(matrix[i][j])].x()+int(0.5*sizeVer);
                        int secondY=position[size_t(matrix[i][j])].y()+int(0.5*sizeVer);
                        painter.drawLine(firstX,firstY,secondX,secondY);
                    }


                }

            }
        }
        //BFSIterator
        if(IDBFSIteratorBool)
        for(size_t i=0;i<BFS.size();i++){
            size_t ii=BFS[i];
            int xpos=position[ii].x();
            int ypos=position[ii].y();
            QString Ite="BFS: ";
            Ite=Ite+Ite.number(i);
            painter.drawText(xpos+(int(0.15*sizeVer)),ypos+(int(0.6*sizeVer)),Ite);
        }
        if(IDDFSIteratorBool)
        for(size_t i=0;i<DFS.size();i++){
            size_t ii=DFS[i];
            int xpos=position[ii].x();
            int ypos=position[ii].y();
            QString Ite="DFS: ";
            Ite=Ite+Ite.number(i);
            QBrush d;
            QColor s;
            s.setRed(255);
            d.setColor(s);
            painter.setBrush(d);
            painter.setPen(QPen(s));
            painter.drawEllipse(xpos,ypos,sizeVer,sizeVer);
            //painter.drawText(xpos+(int(0.15*sizeVer)),ypos+(int(0.6*sizeVer)),Ite);
        }
    }

}
void Graph::addNewVertex(){
    int i = QInputDialog::getInt(this,tr("Wprowadzanie"), tr("Podaj wartość węzła:"), 0,INT_MIN,INT_MAX,1);
    this->matrix.insert(std::pair<size_t,std::vector<int>>(ID,{i}));
    this->ID++;
    update();
}
void Graph::addVertexTwo(QPoint VertexPosition){
    int i = QInputDialog::getInt(this,tr("Wprowadzanie"), tr("Podaj wartość węzła:"), 0,INT_MIN,INT_MAX,1);
    this->matrix.insert(std::pair<size_t,std::vector<int>>(ID,{i}));
    this->position.insert(std::pair<size_t,QPoint>(ID,VertexPosition));
    this->ID++;
    update();
}
void Graph::modifyVertex(QPoint VertexPosition)
{
    bool exists=false;
    size_t i=0;
    for(;i<matrix.size();i++)
    {
        if(!matrix.count(i)) continue;
        if(VertexPosition.x()>=this->position[i].x() && VertexPosition.x() <=(this->position[i].x()+sizeVer) && VertexPosition.y()>=this->position[i].y() && VertexPosition.y()<=(this->position[i].y()+sizeVer)){
            //jest w srodku
            exists=true;
            break;
        }
    }
    if(exists){
        int nowa = QInputDialog::getInt(this,tr("Wprowadzanie"), tr("Podaj nową wartość węzła:"), 0,INT_MIN,INT_MAX,1);
        matrix[i][0]=nowa;

    }
update();
}
void Graph::deleteVertex(QPoint VertexPosition)
{
    bool exists=false;
    size_t i=0;
    for(;i<matrix.size();i++)
    {
        if(VertexPosition.x()>=this->position[i].x() && VertexPosition.x() <=(this->position[i].x()+sizeVer) && VertexPosition.y()>=this->position[i].y() && VertexPosition.y()<=(this->position[i].y()+sizeVer)){
            //jest w srodku
            exists=true;
            break;
        }
    }
    if(exists){
        for(size_t k=0;k<matrix.size();k++)
        {
            if(matrix.count(k)){

                for(size_t j=1;j<matrix[k].size();j++)
                {
                    if(i==size_t(matrix[k][j])) matrix[k].erase(matrix[k].begin()+int(j));
                }
            }
        }
        matrix.erase(i);
        position.erase(i);
    }
    reworkMatrix();
    update();
}
void Graph::addNewRoad(size_t a, size_t b){
    matrix[a].push_back(int(b));
    matrix[b].push_back(int(a));
    update();
}
int Graph::checkPosition(QPoint VertexPosition){
    bool exists=false;
    size_t i=0;

    for(;i<matrix.size();i++)
    {
        if(VertexPosition.x()>=this->position[i].x() && VertexPosition.x() <=(this->position[i].x()+sizeVer) && VertexPosition.y()>=this->position[i].y() && VertexPosition.y()<=(this->position[i].y()+sizeVer)){
            //jest w srodku
            exists=true;
            break;
        }
    }
    if(exists){
        return int(i);
    }
    return -1;
}
int Graph::getCountVertex(){
    return int(matrix.size());
}
void Graph::updateG(){
    update();
}
void Graph::reworkMatrix()
{
    size_t newMaxID=matrix.size();
    size_t newActualId=0;
    std::map<size_t,std::vector<int>> tmp;
    std::map<size_t,QPoint> tmpPoints;
    for(size_t i=0;i<this->ID;i++){
        if(!matrix.count(i)) continue;
        tmp.insert(std::pair<size_t,std::vector<int>>(newActualId,matrix[i]));
        tmpPoints.insert(std::pair<size_t,QPoint>(newActualId,position[i]));
        newActualId++;
    }
    matrix.clear();
    position.clear();
    newActualId=0;
    for(size_t i=0;i<newMaxID;i++){
        matrix.insert(std::pair<size_t,std::vector<int>>(newActualId,tmp[i]));
        position.insert(std::pair<size_t,QPoint>(newActualId,tmpPoints[i]));
        newActualId++;
    }
    this->ID=newMaxID;
}
void Graph::boolToFalse(){
    this->IDBFSIteratorBool=false;
    this->IDIteratorBool=false;
}
