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
 #include "../interface/ITicDevice.hpp"
 #include "../../TicComChannel/interface/ITicComChannel.hpp"

 class TicDeviceBase: public ITicDevice
 {
     public:
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
        void setAgcMode(TicAgcMode mode)override;
        void setAgcBottomCurrentLimit(TicAgcBottomCurrentLimit limit)override;
        void setAgcCurrentBoostSteps(TicAgcCurrentBoostSteps steps)override;
        void setAgcFrequencyLimit(TicAgcFrequencyLimit limit)override;
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

        private:
        ITicComChannel *_channel;
 };