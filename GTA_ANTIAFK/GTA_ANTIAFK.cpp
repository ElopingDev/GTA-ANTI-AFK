
#define NOMINMAX
#include <iostream>
#include <limits>
#include <windows.h>
#include <chrono>
#include <thread>


bool toggled = false;

void SendKeys(char key) {
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;

    input.ki.wScan = MapVirtualKey(LOBYTE(VkKeyScan(key)), 0);
    SendInput(1, &input, sizeof(INPUT));
    Sleep(1500);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}


int main()
{
    bool toggled = false;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    std::cout << R"(  _____ _______         _____            _   _ _______ _____          ______ _  __
  / ____|__   __|/\     | ____|     /\   | \ | |__   __|_   _|   /\   |  ____| |/ /
 | |  __   | |  /  \    | |__      /  \  |  \| |  | |    | |    /  \  | |__  | ' / 
 | | |_ |  | | / /\ \   |___ \    / /\ \ | . ` |  | |    | |   / /\ \ |  __| |  <  
 | |__| |  | |/ ____ \   ___) |  / ____ \| |\  |  | |   _| |_ / ____ \| |    | . \ 
  \_____|  |_/_/    \_\ |____/  /_/    \_\_| \_|  |_|  |_____/_/    \_\_|    |_|\_\)" << std::endl;

    std::cout << "\n" << std::endl;
    std::cout << "Press MINUS to toggle the AntiAFK." << std::endl;
    std::cout << "" << std::endl;

    // Send the input event
    while (true)
    {
        if (GetAsyncKeyState(VK_SUBTRACT))
        {
            toggled = !toggled;
            Sleep(1000);
        std::cout << toggled << std::endl;
        continue;
    }
        else if (toggled) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            SendKeys('Z');
            SendKeys('Q');
            SendKeys('S');
            SendKeys('D');

            std::cout << "Loop Executed Once" << std::endl;
        }
        
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;

}

