#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QLabel* label = new QLabel("Hello, World!");
    label->setAlignment(Qt::AlignCenter);

    label->setWindowTitle("Hello World");

    label->resize(600,400);
    label->show();

    return app.exec();
}
