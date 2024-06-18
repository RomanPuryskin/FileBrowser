#include "mainwindow.h"
#include <QDebug>
QString getPersent(quint64 directorySize, quint64 currentSize)
{
    double percent = static_cast<double>(currentSize) / static_cast<double>(directorySize) * 100;
    if (percent < 0.01)
    {
        return "<0.01";
    }
    else
        return QString::number(percent,'f', 2);
}

quint64 getSizeOfDirectory(QMap<QString,quint64> map)
{
    quint64 totalSize = 0;
    for (auto i = map.cbegin(); i != map.cend(); ++i)
        totalSize += i.value();
    return totalSize;
}

QList<TableModel> fillTable(QMap<QString , quint64> map)
{
    quint64 totalSize = getSizeOfDirectory(map);

    QList<TableModel> result;

    for(auto i = map.begin(); i!= map.cend(); i++)
    {
        result.append(TableModel(i.key() , QString::number(i.value()) , getPersent(i.value() , totalSize)));
    }

    return result;
}

MainWindow::MainWindow(QWidget *parent): QWidget{parent}
{
    m_strategy = new Browser(new ByFolder_CalculationStrategy);
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
    tableView = new QTableView(this);
    tableView->setModel(m_model);

    //настройка атрибутов со стратегией
    strategyLabel = new QLabel("Strategy",this);
    strategyBox = new QComboBox(this);
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

    connect(treeView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &MainWindow::selectedSlot);
    connect(strategyBox, qOverload<int>(&QComboBox::currentIndexChanged), this, &MainWindow::strategyBoxSlot);

}

void MainWindow::selectedSlot(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(selected);
    Q_UNUSED(deselected);
    QModelIndex index = treeView->selectionModel()->currentIndex();
    if(index.isValid()){
        m_model->setModel(fillTable(m_strategy->CalculationMethod(systemModel->filePath(index))));
    }
}

void MainWindow::strategyBoxSlot(int strategy)
{
    switch(strategy)
    {
        case 0:
            m_strategy->setStrategy(new ByFolder_CalculationStrategy);
            break;
        case 1:
            m_strategy->setStrategy(new ByFileType_CalculationStrategy);
            break;
    }

    QModelIndex index = treeView->selectionModel()->currentIndex();
        m_model->setModel(fillTable(m_strategy->CalculationMethod(systemModel->filePath(index))));
}

