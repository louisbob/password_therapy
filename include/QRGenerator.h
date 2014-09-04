#ifndef QRGENERATOR_H
#define QRGENERATOR_H

#include <string>

class QRGenerator
{
public:
    QRGenerator();
    std::string genHash(std::string MPwd);
    std::string binToHex(std::string toConvert);

private:

};

#endif // QRGENERATOR_H
