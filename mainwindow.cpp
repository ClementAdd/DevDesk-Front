#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>


bool MainWindow::isBusy() const
{
    return m_isBusy;
}

void MainWindow::setIsBusy(bool newIsBusy)
{
    m_isBusy = newIsBusy;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnSearch_clicked()
{
    m_isBusy =! m_isBusy;
    ui->listResult->setDisabled(m_isBusy);
    ui->txtSearch->setDisabled(m_isBusy);

    QStringList items;
    items << "Item 1" << "Item 2" << "Item 3";

    QStandardItemModel *model = new QStandardItemModel();
    foreach (const QString &item, items) {
        QStandardItem *listItem = new QStandardItem(item);
        model->appendRow(listItem);
    }

    ui->listResult->setModel(model);




}

