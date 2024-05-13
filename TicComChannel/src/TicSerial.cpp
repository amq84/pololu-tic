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
 * @file TicSerial.cpp
 * @brief Tic Serial Communication channel class implementation
 *
 * @note Contact maintainer for modifications: info@soft-loop.com
 */
 #pragma once
 #include "../includes/TicSerial.hpp"
#include <cstdint>

TicSerial::TicSerial(PinName tx, PinName rx)
{
    _serial = new BufferedSerial(tx,rx);
}
TicSerial::~TicSerial()
{

}

void TicSerial::commandQuick(TicCommand cmd){
    char _byte[1];
    _byte[0] = (char)cmd;
    _serial->write(_byte, 1);
}

void TicSerial::commandW32(TicCommand cmd, uint32_t val){
    commandQuick(cmd);
    writeW7(MSBs(val));
    writeW7(val >> 0);
    writeW7(val >> 8);
    writeW7(val >> 16);
    writeW7(val >> 24);
}

void TicSerial::commandW7(TicCommand cmd, uint8_t val){
    commandQuick(cmd);
    writeW7(val);
}

int TicSerial::getSegment(TicCommand cmd, uint8_t offset, uint8_t length, void * buffer){
    length &= 0x3F;
    commandQuick(cmd);
    writeW7(offset& 0x7F);
    writeW7(length | (offset >> 1 & 0x40));
    // Flush before read
    _serial->sync();
    uint8_t byteCount = _serial->read((uint8_t *)buffer, length);
    if (byteCount > length || byteCount < 0)
    {
        memset(buffer,0,length);
        return -2;
    }else if (byteCount == length)
    {
        return 0;
    }else
    {
        return -1;
    }
}

uint8_t TicSerial::MSBs(uint32_t byte)
{
    return ((byte >>  7) & 1) |
           ((byte >> 14) & 2) |
           ((byte >> 21) & 4) |
           ((byte >> 28) & 8);
}

void TicSerial::writeW7(uint8_t byte)
{
    byte = byte & 0x7F;
    _serial->write(&byte, 1);
}