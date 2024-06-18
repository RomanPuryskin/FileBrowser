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
#include "Calculation.h"
#include "datamodel.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    DataModel *m_model; // наша табличная модель
    QTableView *tableView; // для работы с таблицами
    QFileSystemModel *systemModel; // для работы с файловой системой
    QTreeView *treeView; // для отображения файловой системы деревом

    // выбор стратегии
    QLabel *labelChooseStategy;
    QComboBox *chooseStategyBox;

    Browser* m_strategy;
};
#endif // MAINWINDOW_H
