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
 * @file TicSerial.hpp
 * @brief Tic Serial Communication channel class
 *
 * @note Contact maintainer for modifications: info@soft-loop.com
 */
 #pragma once
 #include "mbed.h"
 #include "../interface/ITicComChannel.hpp"
#include <cstdint>

 class TicSerial: public ITicComChannel
 {

    public:
    TicSerial(){}
    TicSerial(PinName tx, PinName rx);
    ~TicSerial();
    void commandQuick(TicCommand cmd);
    void commandW32(TicCommand cmd, uint32_t val);
    void commandW7(TicCommand cmd, uint8_t val);
    int getSegment(TicCommand cmd, uint8_t offset, uint8_t length, void * buffer);

    private:
    BufferedSerial *_serial;

    uint8_t MSBs(uint32_t byte);
    void writeW7(uint8_t byte);
 };