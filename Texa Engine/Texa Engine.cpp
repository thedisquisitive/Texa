// Texa Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "texaLog.h"

using namespace std;
int main()
{
    Texa::Logging::TexaLog log;
    log.initDefault();
    log << "Testing TexaLog";
    log >> "Testing TexaError";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
