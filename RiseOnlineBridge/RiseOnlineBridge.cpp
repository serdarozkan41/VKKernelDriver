// RiseOnlineBridge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Mouse.h"
#include "Keyboard.h"

int main()
{
    Mouse mouse;
    try {
        mouse.initialize();
    }
    catch (const std::runtime_error& e) {
        std::cout << std::string("Mouse initialization: ") + e.what() << std::endl;
        return EXIT_FAILURE;
    }

    Keyboard keyboard;
    try {
        keyboard.initialize();
    }
    catch (const std::runtime_error& e) {
        std::cout << std::string("Keyboard initialization: ") + e.what() << std::endl;
        return EXIT_FAILURE;
    }

    Sleep(5000);

    mouse.moveCursor(136, 271);
    mouse.leftButtonClick();
    Sleep(500);
    mouse.moveCursor(56, 315);
    mouse.leftButtonClick();
    Sleep(500);
    mouse.moveCursor(283, 350);
    mouse.leftButtonClick();
    Sleep(500);
    mouse.moveCursor(275, 271);
    mouse.leftButtonClick();
    Sleep(500);

    return EXIT_SUCCESS;
}