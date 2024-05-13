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
 * @file TTicDevice.hpp
 * @brief Tic Device interface class
 *
 * @note Contact maintainer for modifications: info@soft-loop.com
 */
 #pragma once
 #include "../../includes/TicCommon.hpp"
 #include <stdint.h>

 class ITicDevice
 {
     public:
        virtual void setTargetPosition(int32_t position)=0;
        virtual void setTargetVelocity(int32_t velocity)=0;
        virtual void haltAndSetPosition(int32_t position)=0;
        virtual void haltAndHold()=0;
        virtual void goHomeReverse()=0;
        virtual void goHomeForward()=0;
        virtual void resetCommandTimeout()=0;
        virtual void deenergize()=0;
        virtual void energize()=0;
        virtual void exitSafeStart()=0;
        virtual void enterSafeStart()=0;
        virtual void reset();
        virtual void clearDriverError()=0;
        virtual void setMaxSpeed(uint32_t speed)=0;
        virtual void setStartingSpeed(uint32_t speed)=0;
        virtual void setMaxAccel(uint32_t accel)=0;
        virtual void setMaxDecel(uint32_t decel)=0;
        virtual void setStepMode(TicStepMode mode)=0;
        virtual void setCurrentLimit(uint16_t limit)=0;
        virtual void setDecayMode(TicDecayMode mode)=0;
        virtual void setAgcMode(TicAgcMode mode)=0;
        virtual void setAgcBottomCurrentLimit(TicAgcBottomCurrentLimit limit)=0;
        virtual void setAgcCurrentBoostSteps(TicAgcCurrentBoostSteps steps)=0;
        virtual void setAgcFrequencyLimit(TicAgcFrequencyLimit limit)=0;
        virtual TicOperationState getOperationState()=0;
        virtual bool getEnergized()=0;
        virtual bool getPositionUncertain()=0;
        virtual bool getForwardLimitActive()=0;
        virtual bool getReverseLimitActive()=0;
        virtual bool getHomingActive()=0;
        virtual uint16_t getErrorStatus()=0;
        virtual uint32_t getErrorsOccurred()=0;
        virtual TicPlanningMode getPlanningMode()=0;
        virtual int32_t getTargetPosition()=0;
        virtual int32_t getTargetVelocity()=0;
        virtual uint32_t getMaxSpeed()=0;
        virtual uint32_t getStartingSpeed()=0;
        virtual uint32_t getMaxAccel()=0;
        virtual uint32_t getMaxDecel()=0;
        virtual int32_t getCurrentPosition()=0;
        virtual int32_t getCurrentVelocity()=0;
        virtual uint32_t getActingTargetPosition()=0;
        virtual uint32_t getTimeSinceLastStep()=0;
        virtual TicReset getDeviceReset()=0;
        virtual uint16_t getVinVoltage()=0;
        virtual uint32_t getUpTime()=0;
        virtual int32_t getEncoderPosition()=0;
        virtual uint16_t getRCPulseWidth()=0;
        virtual uint16_t getAnalogReading(TicPin pin)=0;
        virtual bool getDigitalReading(TicPin pin)=0;
        virtual TicPinState getPinState(TicPin pin)=0;
        virtual TicStepMode getStepMode()=0;
        virtual uint16_t getCurrentLimit()=0;
        virtual TicDecayMode getDecayMode()=0;
        virtual TicInputState getInputState()=0;
        virtual uint16_t getInputAfterAveraging()=0;
        virtual uint16_t getInputAfterHysteresis()=0;
        virtual int32_t getInputAfterScaling()=0;
        virtual TicMotorDriverError getLastMotorDriverError()=0;
        virtual TicAgcMode getAgcMode()=0;
        virtual TicAgcBottomCurrentLimit getAgcBottomCurrentLimit()=0;
        virtual TicAgcCurrentBoostSteps getAgcCurrentBoostSteps()=0;
        virtual TicAgcFrequencyLimit getAgcFrequencyLimit()=0;
        virtual uint8_t getLastHpDriverErrors()=0;
        virtual void getSetting(uint8_t offset, uint8_t length, uint8_t * buffer)=0;
        virtual uint8_t getLastError()=0;
 };