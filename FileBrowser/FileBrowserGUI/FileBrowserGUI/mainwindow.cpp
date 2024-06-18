#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QWidget(parent)
{
    // создали нашу модель и привязали к виджету
    m_model = new DataModel(this);

    //создаем модель для работы с файловой системой
    systemModel = new QFileSystemModel(this);
    systemModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    systemModel->setRootPath(QDir::homePath());

    //создаем модель для древовидного отображения
    treeView = new QTreeView(this);
    treeView->setModel(systemModel);

    //модель для работы с таблицами
    tableView = new QTableView();
    tableView->setModel(m_model);
}

MainWindow::~MainWindow()
{
}

