// Copyright 2019 Perov Dima

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/caesar_cipher_application.h"

class CaesarCipherApplicationTest : public ::testing::Test {
 protected:
  void Act(std::vector<std::string> args_) {
    std::vector<const char*> parameters;
    parameters.push_back("caesar-cipher.exe");
    for (size_t i = 0; i < args_.size(); ++i) {
      parameters.push_back(args_[i].c_str());
    }

    const char** argv = &parameters.front();
    int argc = static_cast<int>(args_.size()) + 1;

    output_ = app_(argc, argv);
  }

  void Assert(std::string expected) { EXPECT_EQ(expected, output_); }

 private:
  CaesarCipherApplication app_;
  std::string output_;
};

TEST_F(CaesarCipherApplicationTest, Can_Print_Help_Without_Arguments) {
  // Arrange
  std::vector<std::string> args = {};

  Act(args);

  Assert(
      "\nThis application encrypts/decrypts the contents of the file.\n"
      "Please provide arguments in the following format:\n"
      "1: File name(string) for operation;\n"
      "2: File name(string) to save the result;\n"
      "3: The key(int) to encrypt/decrypt operations;\n"
      "4: The operation(string): EN to Encrypt or DE to Decrypt;\n");
}

TEST_F(CaesarCipherApplicationTest, Throws_On_Invalid_FileName) {
    // Arrange
    std::vector<std::string> args = {"InvalidName", "SaveFile", "4", "EN"};

    Act(args);

    Assert(
      "\nThis application encrypts/decrypts the contents of the file.\n"
      "Please provide arguments in the following format:\n"
      "1: File name(string) for operation;\n"
      "2: File name(string) to save the result;\n"
      "3: The key(int) to encrypt/decrypt operations;\n"
      "4: The operation(string): EN to Encrypt or DE to Decrypt;\n");
}

TEST_F(CaesarCipherApplicationTest, Throws_On_Invalid_Operation) {
    // Arrange
    std::vector<std::string> args = {"Encrypt.txt", "Decrypt.txt", "4",
     "InvalidOperation"};

    Act(args);

    Assert(
      "\nThis application encrypts/decrypts the contents of the file.\n"
      "Please provide arguments in the following format:\n"
      "1: File name(string) for operation;\n"
      "2: File name(string) to save the result;\n"
      "3: The key(int) to encrypt/decrypt operations;\n"
      "4: The operation(string): EN to Encrypt or DE to Decrypt;\n");
}

TEST_F(CaesarCipherApplicationTest, Can_Encrypt_File) {
    // Arrange
    std::vector<std::string> args = {"Encrypt.txt", "Decrypt.txt", "4", "EN"};

    Act(args);

    Assert(
        "Xlvsykl xli hevoriww sj jyxyvi tewx,\n"
        "xli qekmgmer psrkw xs wii,\n"
        "sri glergi syx fixaiir xas asvphw,\n"
        "jmvi aepo amxl qi.\n");
}

TEST_F(CaesarCipherApplicationTest, Can_Decrypt_File) {
    // Arrange
    std::vector<std::string> args = {"Decrypt.txt", "Encrypt.txt", "4", "DE"};

    Act(args);

    Assert(
        "Through the darkness of future past,\n"
        "the magician longs to see,\n"
        "one chance out between two worlds,\n"
        "fire walk with me.\n");
}

TEST_F(CaesarCipherApplicationTest, Can_Encrypt_File_With_Negative_Key) {
    // Arrange
    std::vector<std::string> args = {"Decrypt.txt", "Encrypt.txt", "-4", "EN"};

    Act(args);

    Assert(
        "Through the darkness of future past,\n"
        "the magician longs to see,\n"
        "one chance out between two worlds,\n"
        "fire walk with me.\n");
}

TEST_F(CaesarCipherApplicationTest, Can_Encrypt_File_With_Zero_Key) {
    // Arrange
    std::vector<std::string> args = {"Encrypt.txt", "Encrypt.txt", "0", "EN"};

    Act(args);

    Assert(
        "Through the darkness of future past,\n"
        "the magician longs to see,\n"
        "one chance out between two worlds,\n"
        "fire walk with me.\n");
}

TEST_F(CaesarCipherApplicationTest, Can_Decrypt_File_With_Zero_Key) {
    // Arrange
    std::vector<std::string> args = {"Decrypt.txt", "Decrypt.txt", "0", "DE"};

    Act(args);

Assert(
        "Xlvsykl xli hevoriww sj jyxyvi tewx,\n"
        "xli qekmgmer psrkw xs wii,\n"
        "sri glergi syx fixaiir xas asvphw,\n"
        "jmvi aepo amxl qi.\n");
}

