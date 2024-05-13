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
 * @file TicDeviceBase.hpp
 * @brief Tic Device base class
 *
 * @note Contact maintainer for modifications: info@soft-loop.com
 */
 #pragma once
 #include "mbed.h"
 #include "../interface/ITicDevice.hpp"
 #include "../../TicComChannel/interface/ITicComChannel.hpp"
#include <cstdint>

 class TicDeviceBase: public ITicDevice
 {
     public:
     TicDeviceBase(){}
     ~TicDeviceBase(){}
        void setTargetPosition(int32_t position)override;
        void setTargetVelocity(int32_t velocity)override;
        void haltAndSetPosition(int32_t position)override;
        void haltAndHold()override;
        void goHomeReverse()override;
        void goHomeForward()override;
        void resetCommandTimeout()override;
        void deenergize()override;
        void energize()override;
        void exitSafeStart()override;
        void enterSafeStart()override;
        void reset()override;
        void clearDriverError()override;
        void setMaxSpeed(uint32_t speed)override;
        void setStartingSpeed(uint32_t speed)override;
        void setMaxAccel(uint32_t accel)override;
        void setMaxDecel(uint32_t decel)override;
        void setStepMode(TicStepMode mode)override;
        void setCurrentLimit(uint16_t limit)override;
        void setDecayMode(TicDecayMode mode)override;
        TicOperationState getOperationState()override;
        bool getEnergized()override;
        bool getPositionUncertain()override;
        bool getForwardLimitActive()override;
        bool getReverseLimitActive()override;
        bool getHomingActive()override;
        uint16_t getErrorStatus()override;
        uint32_t getErrorsOccurred()override;
        TicPlanningMode getPlanningMode()override;
        int32_t getTargetPosition()override;
        int32_t getTargetVelocity()override;
        uint32_t getMaxSpeed()override;
        uint32_t getStartingSpeed()override;
        uint32_t getMaxAccel()override;
        uint32_t getMaxDecel()override;
        int32_t getCurrentPosition()override;
        int32_t getCurrentVelocity()override;
        uint32_t getActingTargetPosition()override;
        uint32_t getTimeSinceLastStep()override;
        TicReset getDeviceReset()override;
        uint16_t getVinVoltage()override;
        uint32_t getUpTime()override;
        int32_t getEncoderPosition()override;
        uint16_t getRCPulseWidth()override;
        uint16_t getAnalogReading(TicPin pin)override;
        bool getDigitalReading(TicPin pin)override;
        TicPinState getPinState(TicPin pin)override;
        TicStepMode getStepMode()override;
        uint16_t getCurrentLimit()override;
        TicDecayMode getDecayMode()override;
        TicInputState getInputState()override;
        uint16_t getInputAfterAveraging()override;
        uint16_t getInputAfterHysteresis()override;
        int32_t getInputAfterScaling()override;
        TicMotorDriverError getLastMotorDriverError()override;
        TicAgcMode getAgcMode()override;
        TicAgcBottomCurrentLimit getAgcBottomCurrentLimit()override;
        TicAgcCurrentBoostSteps getAgcCurrentBoostSteps()override;
        TicAgcFrequencyLimit getAgcFrequencyLimit()override;
        uint8_t getLastHpDriverErrors()override;
        void getSetting(uint8_t offset, uint8_t length, uint8_t * buffer)override;
        uint8_t getLastError()override;

        //void setAgcMode(TicAgcMode mode);
        protected:
        ITicComChannel *_channel;

        private:
        enum VarOffset
        {
            OperationState        = 0x00, // uint8_t
            MiscFlags1            = 0x01, // uint8_t
            ErrorStatus           = 0x02, // uint16_t
            ErrorsOccurred        = 0x04, // uint32_t
            PlanningMode          = 0x09, // uint8_t
            TargetPosition        = 0x0A, // int32_t
            TargetVelocity        = 0x0E, // int32_t
            StartingSpeed         = 0x12, // uint32_t
            SpeedMax              = 0x16, // uint32_t
            DecelMax              = 0x1A, // uint32_t
            AccelMax              = 0x1E, // uint32_t
            CurrentPosition       = 0x22, // int32_t
            CurrentVelocity       = 0x26, // int32_t
            ActingTargetPosition  = 0x2A, // int32_t
            TimeSinceLastStep     = 0x2E, // uint32_t
            DeviceReset           = 0x32, // uint8_t
            VinVoltage            = 0x33, // uint16_t
            UpTime                = 0x35, // uint32_t
            EncoderPosition       = 0x39, // int32_t
            RCPulseWidth          = 0x3D, // uint16_t
            AnalogReadingSCL      = 0x3F, // uint16_t
            AnalogReadingSDA      = 0x41, // uint16_t
            AnalogReadingTX       = 0x43, // uint16_t
            AnalogReadingRX       = 0x45, // uint16_t
            DigitalReadings       = 0x47, // uint8_t
            PinStates             = 0x48, // uint8_t
            StepMode              = 0x49, // uint8_t
            CurrentLimit          = 0x4A, // uint8_t
            DecayMode             = 0x4B, // uint8_t
            InputState            = 0x4C, // uint8_t
            InputAfterAveraging   = 0x4D, // uint16_t
            InputAfterHysteresis  = 0x4F, // uint16_t
            InputAfterScaling     = 0x51, // uint16_t
            LastMotorDriverError  = 0x55, // uint8_t
            AgcMode               = 0x56, // uint8_t
            AgcBottomCurrentLimit = 0x57, // uint8_t
            AgcCurrentBoostSteps  = 0x58, // uint8_t
            AgcFrequencyLimit     = 0x59, // uint8_t
            LastHpDriverErrors    = 0xFF, // uint8_t
        };
        
        uint8_t getVar8(uint8_t offset);
        uint16_t getVar16(uint8_t offset);
        uint32_t getVar32(uint8_t offset);

 };