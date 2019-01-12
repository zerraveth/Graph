#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "graph.h"
#include <QMessageBox>
#include <QMouseEvent>
#include "writer.h"
#include "reader.h"
#include <QLabel>
#include <QTime>
#include "iterator.h"
#include "bfsiterator.h"
#include "dfsiterator.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void helpQt();
    void helpAbout();
    void modifyVertex();
    void deleteVertex();
    void roadVertex();
    void saveFileSlot();
    void loadFromFileSlot();
    void iteratorSlots();
    void bfsIteratorSlots();
    void dfsIteratorSlot();
    void addVertexSlot();
    void renew();
private:
    Ui::MainWindow *ui;
    //bool action
    bool modVer;
    bool deleteVer;
    bool roadVer;
    bool firstVerBool;
    bool secondVerBool;
    bool addVerBool;
    //MOUSE
    void mousePressEvent(QMouseEvent *event);
    QPoint firstVer;
    QPoint secondVer;
    //resize window
    void resizeEvent(QResizeEvent *);
    //przyciski
    void createButtons();
    int widthButton;
    int heightButton;
    QPushButton *addVertexButton;
    QPushButton *modifyVertexButton;
    QPushButton *deleteVertexButton;
    QPushButton *roadButton;
    QPushButton *iteratorButton;
    QPushButton *bfsIteratorButton;
    QPushButton *dfsIteratorButton;
    //graph
    Graph *graph;
    //newRoad
    size_t firstVerId;
    size_t secondVerId;
    //menubar
    void createMenus();
    void createActions();
    QMenu *fileMenu; //jeden wskaznik do jedenego rozwijanego menu
    QAction *fileNewGraph;
    QAction *fileSaveToAction; // File->new
    QAction *fileLoadFromAction;
    QAction *fileCloseAction;

    QMenu *helpMenu;
    QAction *helpAboutAction;
    QAction *helpQtAction;

    //writer
    Writer *writer;
    //Reader
    Reader *reader;
    //iterator
    Iterator *iterator;

    //label
    void createLabel();
    void clearLabel();
    QLabel *iteratorLabel;
    QLabel *bfsIteratorLabel;
    QLabel *dfsIteratorLabel;
    //opoznienie
    void delay(int i);

    //BFS Iterator
    BFSIterator *bfsiterator;
    //DFS Iterator
    DFSIterator *dfsiterator;

};

#endif // MAINWINDOW_H
