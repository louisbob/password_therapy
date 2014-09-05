#include "include/QRGenerator.h"
#include "include/sha512.h"
#include <iostream>
#include <string>
#include <crypto++/aes.h>
#include <crypto++/modes.h>
#include <crypto++/filters.h>


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

void QRGenerator::encryptAES() {
    //Key and IV setup
    //AES encryption uses a secret key of a variable length (128-bit, 196-bit or 256-
    //bit). This key is secretly exchanged between two parties before communication
    //begins. DEFAULT_KEYLENGTH= 16 bytes
    byte key[ CryptoPP::AES::DEFAULT_KEYLENGTH ], iv[ CryptoPP::AES::BLOCKSIZE ];
    memset( key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH );
    memset( iv, 0x00, CryptoPP::AES::BLOCKSIZE );

    //
       // String and Sink setup
       //
       std::string plaintext = "Now is the time for all good men to come to the aide...";
       std::string ciphertext;
       std::string decryptedtext;

       //
       // Dump Plain Text
       //
       std::cout << "Plain Text (" << plaintext.size() << " bytes)" << std::endl;
       std::cout << plaintext;
       std::cout << std::endl << std::endl;

       //
       // Create Cipher Text
       //
       CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
       CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption( aesEncryption, iv );

       CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink( ciphertext ) );
       stfEncryptor.Put( reinterpret_cast<const unsigned char*>( plaintext.c_str() ), plaintext.length() + 1 );
       stfEncryptor.MessageEnd();

       //
          // Dump Cipher Text
          //
          std::cout << "Cipher Text (" << ciphertext.size() << " bytes)" << std::endl;

          for( int i = 0; i < ciphertext.size(); i++ ) {

              std::cout << "0x" << std::hex << (0xFF & static_cast<byte>(ciphertext[i])) << " ";
          }

          std::cout << std::endl << std::endl;
}
