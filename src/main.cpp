
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton bouton("Welcome in PasswordTherapy");
    bouton.show();

    return app.exec();
}
