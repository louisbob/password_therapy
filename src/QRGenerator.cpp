#include "include/QRGenerator.h"
#include "include/sha512.h"
#include <string>

QRGenerator::QRGenerator()  {

}

std::string QRGenerator::genHash(std::string MPwd) {
    unsigned char hash[64];

    sha512( (const unsigned char *) MPwd.c_str(), MPwd.length(), hash, 0);

    std::string str((const char*) hash);
    return str;
}

std::string QRGenerator::binToHex(std::string toConvert) {

    unsigned char *buf = (unsigned char*) toConvert.c_str();
    char res[512];

    static const char* hex_lookup = "0123456789ABCDEF";
    char *p = res;

    for (int i = 0 ; i != 64 ; i++) {
        *p++ = hex_lookup[buf[i] >> 4];
        *p++ = hex_lookup[buf[i] & 0x0F];
        if ((i+1)%16) {
            *p++ = ' ';
        } else {
            *p++ = '\r';
            *p++ = '\n';
        }
    }
    *p = '\0';

    std::string str(res);
    return  str;

}
