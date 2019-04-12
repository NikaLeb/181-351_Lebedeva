#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStandardItemModel"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DBModel = new QStandardItemModel(5, 2, this);
    ui->DBtable->setModel(DBModel);


    QModelIndex index;
    for(int row=0; row < DBModel->rowCount(); ++row)
    {
        for(int col=0; col < DBModel->columnCount();++col)
        {
            index = DBModel->index(row, col);
            QString value = "hello"+row;
            DBModel-> setData(index, value);
        }


    }
    //DBModel->setHeaderData()
}

MainWindow::~MainWindow()
{
    delete ui;
}
