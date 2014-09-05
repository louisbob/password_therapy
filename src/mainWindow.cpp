#include "include/mainWindow.h"

MainWindow::MainWindow() : QWidget()
{
    //Window properties

//    ->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    lbl_masterPwd = new QLabel();
    lbl_masterPwd->setText("Master password");
    lbl_myPwd = new QLabel();
    lbl_myPwd->setText("Personnal password");
    inp_masterPwd = new QLineEdit();
    inp_myPwd = new QLineEdit();

    btn_process = new QPushButton("Process1", this);
    btn_process->setCursor(Qt::PointingHandCursor);

    lbl_txtSHA2 = new QLabel();
    lbl_txtSHA2->setText("SHA-2 256 : ");
    lbl_SHA2 = new QLabel();
    lbl_SHA2->setText("(N/A)");

    lbl_txtCipher = new QLabel();
    lbl_txtCipher->setText("Cipher password : ");
    lbl_Cipher = new QLabel();
    lbl_Cipher->setText("(N/A)");

    //Layout properties
    layout = new QGridLayout;
    layout->addWidget(lbl_masterPwd, 0,0);
    layout->addWidget(inp_masterPwd, 0,1);
    layout->addWidget(lbl_myPwd, 1,0);
    layout->addWidget(inp_myPwd, 1,1);
    layout->addWidget(btn_process, 2,1);

    layout->addWidget(lbl_txtSHA2, 3,0);
    layout->addWidget(lbl_SHA2, 3,1);

    layout->addWidget(lbl_txtCipher, 4,0);
    layout->addWidget(lbl_Cipher, 4,1);

    setLayout(layout);

    //Connect button
    QObject::connect(btn_process, SIGNAL(clicked()), this, SLOT(processAlgorithm()));

}

void MainWindow::processAlgorithm() {

    std::string mPwd = inp_masterPwd->text().toStdString();
    std::string mHash = QRGen.genHash(mPwd);
    mHash = QRGen.binToHex(mHash);
    QRGen.encryptAES();

    lbl_SHA2->setText(QString::fromStdString(mHash));
}


