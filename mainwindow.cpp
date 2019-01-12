#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*ustawienie wielkosci przyciskow*/
    this->widthButton=140;
    this->heightButton=60;

    /*ustawienie poczatkowych wartosci*/
    this->modVer=false;
    this->deleteVer=false;
    this->roadVer=false;
    this->firstVerBool=false;
    this->secondVerBool=false;
    //this->firstVerId=0;
    //this->secondVerId=0;
    this->graph = new Graph;
    this->setCentralWidget(graph);
    //ui->setupUi(this);
    this->setWindowTitle("Graphs");
    this->setGeometry(100,100,1080,720);
    createActions();
    createMenus();
    createButtons();
    createLabel();
    //writer
    this->writer=new Writer;
    this->reader=new Reader;
    this->iterator =new Iterator;
    this->bfsiterator=new BFSIterator;
    this->dfsiterator=new DFSIterator;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::createButtons()
{

    //    QPushButton *addVertexButton;
    addVertexButton = new QPushButton("Dodaj wierzcholek",this);
    connect(addVertexButton, SIGNAL(clicked()), graph, SLOT(addNewVertex()));
    addVertexButton->setGeometry(0,30,this->widthButton,this->heightButton);

    modifyVertexButton = new QPushButton("Modifikuj wierzcholek",this);
    connect(modifyVertexButton, SIGNAL(clicked()), this, SLOT(modifyVertex()));
    modifyVertexButton->setGeometry(0,100,this->widthButton,this->heightButton);

    deleteVertexButton = new QPushButton("Usuń wierzcholek",this);
    connect(deleteVertexButton, SIGNAL(clicked()), this, SLOT(deleteVertex()));
    deleteVertexButton->setGeometry(0,170,this->widthButton,this->heightButton);

    roadButton = new QPushButton("Rysuj drogę",this);
    connect(roadButton, SIGNAL(clicked()), this, SLOT(roadVertex()));
    roadButton->setGeometry(0,240,this->widthButton,this->heightButton);

    iteratorButton = new QPushButton("Iterator",this);
    connect(iteratorButton, SIGNAL(clicked()), this, SLOT(iteratorSlots()));
    iteratorButton->setGeometry(0,310,this->widthButton,this->heightButton);

    bfsIteratorButton = new QPushButton("BFS Iterator", this);
    connect(bfsIteratorButton,SIGNAL(clicked()),this,SLOT(bfsIteratorSlots()));
    bfsIteratorButton->setGeometry(0,380,this->widthButton,this->heightButton);

    dfsIteratorButton = new QPushButton("DFS Iterator",this);
    connect(dfsIteratorButton,SIGNAL(clicked()),this,SLOT(dfsIteratorSlot()));
    dfsIteratorButton->setGeometry(0,450,this->widthButton,this->heightButton);
}
void MainWindow::modifyVertex(){
    QMessageBox::about(this, tr("Wierzchołek"),
            tr("Wybierz wierzchołek do zmodyfikowania"));
    modVer=true;
}
void MainWindow::deleteVertex(){
    QMessageBox::about(this, tr("Wierzchołek"),
            tr("Wybierz wierzchołek do usunieca"));
    clearLabel();
    deleteVer=true;
}
void MainWindow::roadVertex(){
    QMessageBox::about(this, tr("Wierzchołek"),
            tr("Wybierz 2 wierzchołki, pierwszy LPM, drugi PPM"));
    roadVer=true;
}
void MainWindow::createActions()
{

    //FILE
    fileNewGraph = new QAction("Nowy graf",this);
    fileNewGraph->setShortcut(QKeySequence::New);
    fileNewGraph->setStatusTip("Nowy graf");
    connect(fileNewGraph,&QAction::triggered,this,&MainWindow::renew);

    fileSaveToAction = new QAction("Dodaj do pliku", this);
    fileSaveToAction->setShortcuts(QKeySequence::Save);
    fileSaveToAction->setStatusTip(tr("Create a new file"));
    //connect(fileSaveToAction, SIGNAL(triggered()), this->writer, SLOT(save(graph)));
    connect(fileSaveToAction, SIGNAL(triggered()), this, SLOT( saveFileSlot() ));

    fileLoadFromAction = new QAction("Wczytaj z pliku", this);
    fileLoadFromAction->setShortcuts(QKeySequence::Open);
    fileLoadFromAction->setStatusTip(tr("load from file"));
    connect(fileLoadFromAction, &QAction::triggered, this, &MainWindow::loadFromFileSlot);

    fileCloseAction = new QAction("Zamknij Program",this);
    fileCloseAction->setStatusTip("Zamknij Program Tip");
    fileCloseAction->setShortcuts(QKeySequence::Close);
    connect(fileCloseAction,&QAction::triggered,this,&QWidget::close);

    //HELP
    helpAboutAction = new QAction("O programie",this);
    helpAboutAction->setStatusTip("Pokaz informacje o programie");
    connect(helpAboutAction, &QAction::triggered,this, &MainWindow::helpAbout);

    helpQtAction = new QAction("Informacje o QT",this);
    helpQtAction->setStatusTip("Pokaz info o QT");
    connect(helpQtAction, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(helpQtAction, &QAction::triggered, this, &MainWindow::helpQt);

}
void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu("File"); //menuBar <-domyslnyb menuBar (?) QMenuBar
                                           //tworzymy na ekranie pole o nazwie file
    fileMenu->addAction(fileNewGraph);
    fileMenu->addAction(fileSaveToAction);
    fileMenu->addAction(fileLoadFromAction);
    fileMenu->addAction(fileCloseAction);

    helpMenu = menuBar()->addMenu("Help");
    helpMenu->addAction(helpAboutAction);
    helpMenu->addAction(helpQtAction);
}
void MainWindow::helpAbout(){
    QMessageBox::about(this, tr("About Menu"),
            tr("Program do grafów "));
}
void MainWindow::helpQt(){

}
void MainWindow::mousePressEvent(QMouseEvent *event){
    // trzeba zapamiętać punkt kliknięcia myszką
/*
    if(event->buttons() & Qt::LeftButton){
        firstClick.setX(event->x());
        firstClick.setY(event->y());

        QString QSX = QString::number(event->x());
        QString QSY = QString::number(event->y());
        posXlabel->setText(QSX);
        posYlabel->setText(QSY);
        clickedone=true;

    }

    if(event->buttons() & Qt::RightButton){
        mouseE.setX(event->x());
        mouseE.setY(event->y());
        QString QSX = QString::number(event->x());
        QString QSY = QString::number(event->y());
        posXlabelPPM->setText(QSX);
        posYlabelPPM->setText(QSY);
        if(clickedone){
            clickedone=false;
            graph->addNewRoad(mouseB,mouseE);
        }
    }
    */
    if((event->buttons() & Qt::LeftButton) && modVer){
        this->firstVer.setX(event->x());
        this->firstVer.setY(event->y());
        graph->modifyVertex(firstVer);
        this->modVer=false;
    }

    if((event->buttons() & Qt::LeftButton) && deleteVer){
        this->firstVer.setX(event->x());
        this->firstVer.setY(event->y());
        graph->deleteVertex(firstVer);
        this->deleteVer=false;
    }
    if((event->buttons() & Qt::LeftButton) && roadVer){
        this->firstVer.setX(event->x());
        this->firstVer.setY(event->y());
        int check=graph->checkPosition(firstVer);
        if(check!=(-1)){
             this->firstVerId=size_t(check);
             this->firstVerBool=true;
        }
        else{
            QMessageBox::about(this, tr("Informacja"),
                    tr("Nie znaleziono wierzchołka"));
        }
        if(firstVerBool && secondVerBool){

            this->firstVerBool=false;
            this->secondVerBool=false;
            this->roadVer=false;
            graph->addNewRoad(firstVerId,secondVerId);
        }
    }
    if((event->buttons() & Qt::RightButton) && roadVer){
        this->firstVer.setX(event->x());
        this->firstVer.setY(event->y());
        int check=graph->checkPosition(firstVer);
        if(check!=(-1)){
             this->secondVerId=size_t(check);
             this->secondVerBool=true;
        }
        else{
            QMessageBox::about(this, tr("Informacja"),
                    tr("Nie znaleziono wierzchołka"));
        }
        if(firstVerBool && secondVerBool){
            this->firstVerBool=false;
            this->secondVerBool=false;
            this->roadVer=false;
            graph->addNewRoad(firstVerId,secondVerId);
        }
    }
}
void MainWindow::resizeEvent(QResizeEvent * event){

    QMainWindow::resizeEvent(event);

    QSize size = this->size();
    int maksi=size.height()-20;
    iteratorLabel->setGeometry(0,maksi,1200,20);
    bfsIteratorLabel->setGeometry(0,maksi-20,1200,20);

}
void MainWindow::saveFileSlot(){
    writer->save(graph);
}
void MainWindow::loadFromFileSlot(){
    reader->load(graph);
    update();
}
void MainWindow::iteratorSlots()
{
    QString qs="Iterator: ";
    iteratorLabel->setText(qs);
    size_t count= iterator->init(graph);
    for(size_t i=0;i<count;i++)
    {
        delay(1);
        qs=qs+iterator->getNextVertex(graph);
        qs=qs+" ";
        iteratorLabel->setText(qs);
    }
    iterator->toDefault();

}
void MainWindow::createLabel()
{
    QSize size = this->size();
    int maksi=size.height()-20;

    iteratorLabel = new QLabel(this);
    iteratorLabel->setGeometry(0,maksi,1200,20);

    bfsIteratorLabel = new QLabel(this);
    bfsIteratorLabel->setGeometry(0,maksi-20,1200,20);

    dfsIteratorLabel = new QLabel(this);
    dfsIteratorLabel->setGeometry(0,maksi-40,1200,20);
}
void MainWindow::delay(int i){
    QTime dieTime= QTime::currentTime().addSecs(i);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void MainWindow::bfsIteratorSlots(){

    size_t count= bfsiterator->init(graph);
    if(count){

        QString qs="BFS: ";
        bfsIteratorLabel->setText(qs);
        for(size_t i=0;i<count;i++)
        {
            delay(1);
            qs=qs+bfsiterator->getNextVertex(graph);
            qs=qs+" ";
            bfsIteratorLabel->setText(qs);
        }
        bfsiterator->toDefault();
    }

}
void MainWindow::addVertexSlot(){
    addVerBool=true;
}
void MainWindow::dfsIteratorSlot(){
    QString qs="DFS: ";
    dfsIteratorLabel->setText(qs);
    size_t count= dfsiterator->init(graph);
    for(size_t i=0;i<count;i++)
    {
        delay(1);
        qs=qs+dfsiterator->getNextVertex(graph);
        qs=qs+" ";
        dfsIteratorLabel->setText(qs);
    }
    delay(3);
    dfsiterator->toDefault(graph);
}
void MainWindow::clearLabel(){
    QString qs="";
    bfsIteratorLabel->setText(qs);
    dfsIteratorLabel->setText(qs);
    iteratorLabel->setText(qs);
    graph->boolToFalse();
}
void MainWindow::renew(){
    delete graph;
    graph= new Graph;
}
