#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

bool authorization(QString login, QString password)
{
    return (login == "admin" && password == "1234");
}

bool authorization2(QString login, QString password)
{
    return (login == "manager" && password == "4321");
}

bool authorization3(QString login, QString password)
{
    return (login == "guest" && password == "123");
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_authorization_clicked()
{
        QString login = ui->lineEdit_login->text();
        QString password = ui->lineEdit_password->text();

        if(authorization(login,password))
        {
            QMessageBox msgBox;
            msgBox.setText("Welcome, admin!");
            msgBox.exec();
        }

        else if(authorization2(login,password))
        {
            QMessageBox msgBox;
            msgBox.setText("Welcome, manager!");
            msgBox.exec();
        }

        else if(authorization3(login,password))
        {
            QMessageBox msgBox;
            msgBox.setText("Welcome, guest!");
            msgBox.exec();
        }

        else
        {

        QMessageBox msgBox;
        // Заголовок сообщения
        msgBox.setText("Login is incorrect");
        // Основное сообщение Message Box
        msgBox.setInformativeText("Retry again.");
        // Добавление реагирования на софт клавиши
       msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
        // На какой кнопке фокусироваться по умолчанию
        msgBox.setDefaultButton(QMessageBox::Save);
        /* Запускаем QMessageBox. После выполнения, в ret будет лежать значение кнопки, на которую нажали - это необходимо для дальнейшей обработки событий*/
        int res = msgBox.exec();
      }
if (int res = QMessageBox::Close)
{
    close();
}

    std::string s ="qwerty";
    QString::fromStdString(s);
    QString::number(123,1);
    QString Qstr = "123456";

}
