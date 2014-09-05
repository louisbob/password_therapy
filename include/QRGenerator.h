#ifndef QRGENERATOR_H
#define QRGENERATOR_H

#include <string>

class QRGenerator
{
public:
    QRGenerator();
    std::string genHash(std::string MPwd);
    std::string binToHex(std::string toConvert);

    void encryptAES();

private:

};

#endif // QRGENERATOR_H
