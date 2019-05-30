// Copyright 2019 Repin Vladimir
#ifndef MODULES_CAESAR_CIPHER_INCLUDE_CAESAR_CIPHER_APPLICATION_H_
#define MODULES_CAESAR_CIPHER_INCLUDE_CAESAR_CIPHER_APPLICATION_H_

#include <string>
#include <iostream>
#include <fstream>
#include "include/caesar_cipher.h"

class CaesarCipherApplication {
 protected:
  bool ReadFile(std::string in_filename);
  void WriteFile(std::string out_filename);
  std::string filetext_;
  CaesarCipher cipher_;

 public:
  std::string operator()(int argc, const char** argv);
  std::string GetHelpMessage();
  std::string DecryptFile(std::string in_filename, std::string out_filename,
                          int key);
  std::string EncryptFile(std::string in_filename, std::string out_filename,
                          int key);
};

#endif  // MODULES_CAESAR_CIPHER_INCLUDE_CAESAR_CIPHER_APPLICATION_H_
