// Copyright 2019 Perov Dima
#include "include/caesar_cipher_application.h"

int main(int argc, char const **argv) {
  CaesarCipherApplication application;
  std::cout << application(argc, argv);
  return 0;
}

