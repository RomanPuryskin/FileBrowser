#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QTableView>
#include <QTreeView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileSystemModel>
#include <QLabel>
#include <QComboBox>
#include "calculation.h"
#include "datamodel.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(){delete m_strategy;}

private:
    DataModel *m_model; // наша табличная модель
    QTableView *tableView; // для работы с таблицами
    QFileSystemModel *systemModel; // для работы с файловой системой
    QTreeView *treeView; // для отображения файловой системы деревом

    // выбор стратегии
    QLabel *strategyLabel;
    QComboBox *strategyBox;

    //лэйауты
    QHBoxLayout *panelLayout;
    QHBoxLayout *viewsLayout;
    QVBoxLayout *mainLayout;

    Browser* m_strategy;

private slots:
    void selectedSlot(const QItemSelection &selected, const QItemSelection &deselected);
    void strategyBoxSlot(int strategy);
};
#endif // MAINWINDOW_H
