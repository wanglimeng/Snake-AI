#pragma once

#include <string>

enum ColorType {
    RED,
    GREEN,
    BLUE,
    BLACK,
    WHITE,
    YELLOW,
    CYAN,
    PURPLE
};

struct ConsoleColor {
    ConsoleColor(const ColorType foreColor_, const ColorType backColor_, 
                 const bool &foreIntensified_ = false, const bool &backIntensified_ = false);
    ColorType foreColor;
    ColorType backColor;
    bool foreIntensified;
    bool backIntensified;
};

class Console {
public:
    /*
    Set console cursor position.

    @param console x coordinate
    @param console y coordinate
    */
    static void setCursor(const int &x = 0, const int &y = 0);

    /*
    Clear the console.
    */
    static void clear();

    /*
    Write string to console with a given color.

    @param str the string to write
    @param color the output color
    */
    static void writeWithColor(const std::string &str, const ConsoleColor &consoleColor);

    /*
    A cross-platform getch() method.
    Reference: http://stackoverflow.com/questions/3276546/how-to-implement-getch-function-of-c-in-linux
    */
    static char getch();

    /*
    A cross-platform kbhit() method.
    Reference: http://cboard.cprogramming.com/c-programming/63166-kbhit-linux.html
    */
    static int kbhit();

private:
#ifdef WIN32
    /*
    Set console output color.
    Only available in windows platform.

    @param color the output color
    */
    static void setColor(const ConsoleColor &consoleColor);
#endif
};