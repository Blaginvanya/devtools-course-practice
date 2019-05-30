// Copyright 2019 Perov Dima

#include "include/caesar_cipher_application.h"
#include <string>

std::string CaesarCipherApplication::operator()(int argc, const char** argv) {
  std::string result = "";
  std::string in_filename = "";
  std::string out_filename = "";
  std::string operation = "";

  if (argc > 4) {
    int key = 0;
    in_filename = argv[1];
    out_filename = argv[2];
    key = atoi(argv[3]);
    operation = argv[4];

    if (operation == "EN") {
      result = EncryptFile(in_filename, out_filename, key);
    }

    if (operation == "DE") {
      result = DecryptFile(in_filename, out_filename, key);
    }

    if (operation != "DE" && operation != "EN") {
      result = GetHelpMessage();
    }

  } else {
    result = GetHelpMessage();
  }

  if (result == "") {
    result = GetHelpMessage();
  }

  return result;
}

std::string CaesarCipherApplication::GetHelpMessage() {
  std::string help_message;
  help_message =
      "\nThis application encrypts/decrypts the contents of the file.\n";
  help_message += "Please provide arguments in the following format:\n";
  help_message += "1: File name(string) for operation;\n";
  help_message += "2: File name(string) to save the result;\n";
  help_message += "3: The key(int) to encrypt/decrypt operations;\n";
  help_message += "4: The operation(string): EN to Encrypt or DE to Decrypt;\n";
  return help_message;
}

std::string CaesarCipherApplication::DecryptFile(std::string in_filename,
                                                 std::string out_filename,
                                                 int key) {
  filetext_ = "";
  if (ReadFile(in_filename)) {
    filetext_ = cipher_.Decrypt(filetext_, key);
    WriteFile(out_filename);
  }
  return filetext_;
}

std::string CaesarCipherApplication::EncryptFile(std::string in_filename,
                                                 std::string out_filename,
                                                 int key) {
  filetext_ = "";
  if (ReadFile(in_filename)) {
    filetext_ = cipher_.Encrypt(filetext_, key);
    WriteFile(out_filename);
  }
  return filetext_;
}

bool CaesarCipherApplication::ReadFile(std::string in_filename) {
  std::ifstream in_file(in_filename);
  if (!in_file.is_open()) {
    return false;
  } else {
    filetext_.assign((std::istreambuf_iterator<char>(in_file.rdbuf())),
                    std::istreambuf_iterator<char>());
    in_file.close();
  }
  return true;
}

void CaesarCipherApplication::WriteFile(std::string out_filename) {
  std::ofstream out_file(out_filename);
  out_file << filetext_;
  out_file.close();
}

