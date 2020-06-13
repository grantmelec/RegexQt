#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExp>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->RegexTxt->setText("[0-9]{4}") ;

    ui->RegexCombo->addItem("[0-9]{4}");
    ui->RegexCombo->addItem("[a-z]{4}");
    ui->RegexCombo->addItem("[A-Z]{4}");
    ui->RegexCombo->addItem("[A-Z]{4,5}");
    ui->RegexCombo->addItem("[A-Z]{4,5}\\d");
    ui->RegexCombo->addItem("\\w\\d[^A-Za-z0-9]") ;
    ui->RegexCombo->addItem("[A-Z]{4,5}[0-9]{2}");
    ui->RegexCombo->addItem("[A-Z]{4,5}[0-9]+");
    ui->RegexCombo->addItem("[A-Z]{4,5}\\s[0-9]+");
    ui->RegexCombo->addItem("([A-Z]{1}||[a-z]{1})[0-9]{1}");\
    ui->RegexCombo->addItem("([A-Z]{1}||[a-z]{1})[0-9]{1}[^A-Za-z0-9]");
    ui->RegexCombo->addItem("([A-Z]{1}||[a-z]{1})\\s[0-9]{1}\\s[^A-Za-z0-9]");



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_InputTxt_textChanged(const QString &arg1)
{
    QRegExp re;
    re.setCaseSensitivity(Qt::CaseSensitivity::CaseSensitive);
    re.setPattern(ui->RegexTxt->text());
    bool result = re.exactMatch(arg1);


    qDebug()<<"Result: "<<result<<"  ..  "<<arg1;



    if(result != true)
    {
        QPalette *palette = new QPalette();
        palette->setColor(QPalette::Base,Qt::red);
        ui->InputTxt->setPalette(*palette);
    }else
    {
        QPalette *palette = new QPalette();
        palette->setColor(QPalette::Base,Qt::green);
        ui->InputTxt->setPalette(*palette);
    }
}



void MainWindow::on_RegexCombo_currentTextChanged(const QString &arg1)
{
    ui->RegexTxt->setText(arg1);
}
