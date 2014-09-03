#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>

class MainWindow : public QWidget
{
    public:
    MainWindow();

    private:
    QGridLayout *layout;

    QLabel *lbl_masterPwd;
    QLineEdit *inp_masterPwd;

    QLabel *lbl_myPwd;
    QLineEdit *inp_myPwd;

    QPushButton *btn_process;

    QLabel *lbl_txtSHA2;
    QLabel *lbl_SHA2;

    QLabel *lbl_txtCipher;
    QLabel *lbl_Cipher;
};

#endif
