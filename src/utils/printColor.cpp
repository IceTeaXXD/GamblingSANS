#include "printColor.hpp"

void printColor::printBlue(string text) {
    cout << "\033[1;34m" << text << "\033[0m";
}

void printColor::printRed(string text) {
    cout << "\033[1;31m" << text << "\033[0m";
}

void printColor::printGreen(string text) {
    cout << "\033[1;32m" << text << "\033[0m";
}

void printColor::printYellow(string text) {
    cout << "\033[1;33m" << text << "\033[0m";
}
