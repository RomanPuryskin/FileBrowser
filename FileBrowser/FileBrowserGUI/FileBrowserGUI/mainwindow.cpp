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

    //настройка атрибутов со стратегией
    strategyLabel = new QLabel("Strategy");
    strategyBox = new QComboBox();
    strategyBox->addItems({"by Folder", "by FileType"});

    //настройка лэйаутов

    panelLayout = new QHBoxLayout();
    if(panelLayout != nullptr)
    {
        panelLayout->addStretch(1);
        panelLayout->addWidget(strategyLabel);
        panelLayout->addWidget(strategyBox);
    }

    viewsLayout = new QHBoxLayout();
    if(viewsLayout != nullptr)
    {
        viewsLayout->addWidget(treeView);
        viewsLayout->addWidget(tableView);
        viewsLayout->setStretchFactor(tableView, 1);
    }

    mainLayout = new QVBoxLayout(this);
    if(mainLayout != nullptr)
    {
        mainLayout->addLayout(panelLayout);
        mainLayout->addLayout(viewsLayout);
    }


}

MainWindow::~MainWindow()
{
}

