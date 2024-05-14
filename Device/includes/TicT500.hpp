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
 * @file TicT500.hpp
 * @brief Tic T500 device class
 *
 * @note Contact maintainer for modifications: info@soft-loop.com
 */
 #pragma once
 #include "TicDeviceBase.hpp"
 #include "../TicComChannel/includes/TicSerial.hpp"
 
 #include "mbed.h"

 class TicT500: public TicDeviceBase
 {
     public:
     TicT500();
     ~TicT500();
     void setAgcMode(TicAgcMode mode){}
     void setAgcBottomCurrentLimit(TicAgcBottomCurrentLimit limit){}
     void setAgcCurrentBoostSteps(TicAgcCurrentBoostSteps steps){}
     void setAgcFrequencyLimit(TicAgcFrequencyLimit limit){}
     uint16_t getCurrentLimit();
     private:
        uint16_t Tic03aCurrentTable[33] =
        {
            0,
            1,
            174,
            343,
            495,
            634,
            762,
            880,
            990,
            1092,
            1189,
            1281,
            1368,
            1452,
            1532,
            1611,
            1687,
            1762,
            1835,
            1909,
            1982,
            2056,
            2131,
            2207,
            2285,
            2366,
            2451,
            2540,
            2634,
            2734,
            2843,
            2962,
            3093,
        };
 };