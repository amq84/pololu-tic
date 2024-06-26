/*
 * pololu-tic 
 * Copyright (C) 2024 soft-loop.com.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * @file TicT500.cpp
 * @brief Tic T500 device class
 *
 * @note Contact maintainer for modifications: info@soft-loop.com
 */

 #include "../includes/TicT500.hpp"
#include <cstdint>

TicT500::TicT500()
{
    _channel = new TicSerial(PC_10, PC_11);
}

TicT500::~TicT500()
{
    
}

uint16_t TicT500::getCurrentLimit()
{
    uint8_t code = getVar8(VarOffset::CurrentLimit);
    if (code > 32) { code = 32; }
    return Tic03aCurrentTable[code];
}