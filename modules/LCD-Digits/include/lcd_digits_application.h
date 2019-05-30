// Copyright 2019 Repin Vladimir

#ifndef MODULES_LCD_DIGITS_INCLUDE_LCD_DIGITS_APPLICATION_H_
#define MODULES_LCD_DIGITS_INCLUDE_LCD_DIGITS_APPLICATION_H_

#include <string>

class LCDDigitsApplication {
 public:
    LCDDigitsApplication() = default;
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname);
    std::string message_;
};

#endif  // MODULES_LCD_DIGITS_INCLUDE_LCD_DIGITS_APPLICATION_H_
