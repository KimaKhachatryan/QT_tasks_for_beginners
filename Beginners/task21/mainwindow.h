#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QMessageBox>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onContinue();

private:
    Ui::MainWindow *ui;
    QLineEdit *line1;
    QLineEdit *line2;
    QLineEdit *line3;

    QLabel *name;
    QLabel *surename;
    QLabel *email;
};
#endif // MAINWINDOW_H
