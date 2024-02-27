#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFormLayout *layout = new QFormLayout(ui->centralwidget);

    line1 = new QLineEdit ();
    line2 = new QLineEdit ();
    line3 = new QLineEdit ();

    name = new QLabel("Name:");
    surename = new QLabel("Surname:");
    email = new QLabel("Email:");

    layout->addWidget(name);
    layout->addWidget(line1);

    layout->addWidget(surename);
    layout->addWidget(line2);

    layout->addWidget(email);
    layout->addWidget(line3);

    QPushButton *button = new QPushButton();
    layout->addWidget(button);

    button->setText("Continue");

    connect(button, &QPushButton::clicked, this, &MainWindow::onContinue);
    setFixedSize(400, 250);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onContinue()
{
   if (line1->text().isEmpty() || line2->text().isEmpty()) {
        QMessageBox::critical(this,"Error message", "All fields must be filed.");
   } else {
       QMessageBox::about(this, "Success", "Your information successfuly saved.");
       MainWindow::close();
   }
}
