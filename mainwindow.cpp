#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->HW1_SpinBox, SIGNAL(valueChanged(int)),this,SLOT(update_overall(int)));
    QObject::connect(ui->HW2_SpinBox, SIGNAL(valueChanged(int)),this,SLOT(update_overall(int)));
    QObject::connect(ui->HW3_SpinBox, SIGNAL(valueChanged(int)),this,SLOT(update_overall(int)));
    QObject::connect(ui->HW4_SpinBox, SIGNAL(valueChanged(int)),this,SLOT(update_overall(int)));
    QObject::connect(ui->HW5_SpinBox, SIGNAL(valueChanged(int)),this,SLOT(update_overall(int)));
    QObject::connect(ui->HW6_SpinBox, SIGNAL(valueChanged(int)),this,SLOT(update_overall(int)));
    QObject::connect(ui->HW7_SpinBox, SIGNAL(valueChanged(int)),this,SLOT(update_overall(int)));
    QObject::connect(ui->MT1_SpinBox, SIGNAL(valueChanged(int)),this,SLOT(update_overall(int)));
    QObject::connect(ui->MT2_SpinBox, SIGNAL(valueChanged(int)),this,SLOT(update_overall(int)));
    QObject::connect(ui->Final_SpinBox, SIGNAL(valueChanged(int)),this,SLOT(update_overall(int)));
    QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(update_overall(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_overall(int unused){
   double score;

   if (ui->comboBox->currentText() == "PIC 10B"){
       score = (.3*((ui->HW1_SpinBox->value() + ui->HW2_SpinBox->value() + ui->HW3_SpinBox->value() + ui->HW4_SpinBox->value() + ui->HW5_SpinBox->value() + ui->HW6_SpinBox->value() + ui->HW7_SpinBox->value())/7)
                + .2*(ui->MT1_SpinBox->value()) +.2*(ui->MT2_SpinBox->value()) +.3*(ui->Final_SpinBox->value()));

   }
   else //PIC 10C selected
   {
       score = (.15*((ui->HW1_SpinBox->value() + ui->HW2_SpinBox->value() + ui->HW3_SpinBox->value() + ui->HW4_SpinBox->value() + ui->HW5_SpinBox->value() + ui->HW6_SpinBox->value() + ui->HW7_SpinBox->value())/7)
                + .3*(ui->MT1_SpinBox->value()) +.0*(ui->MT2_SpinBox->value()) +.55*(ui->Final_SpinBox->value()));
   }

    ui->Final_score_label->setText(QString::number(score));
    return;
}
