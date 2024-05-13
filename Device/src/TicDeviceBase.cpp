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
 * @file TicDeviceBase.cpp
 * @brief Tic Device base class implementation
 *
 * @note Contact maintainer for modifications: info@soft-loop.com
 */
 #pragma once
 #include "../includes/TicDeviceBase.hpp"

void TicDeviceBase::setTargetPosition(int32_t position){}
void TicDeviceBase::setTargetVelocity(int32_t velocity){}
void TicDeviceBase::haltAndSetPosition(int32_t position){}
void TicDeviceBase::haltAndHold(){}
void TicDeviceBase::goHomeReverse(){}
void TicDeviceBase::goHomeForward(){}
void TicDeviceBase::resetCommandTimeout(){}
void TicDeviceBase::deenergize(){}
void TicDeviceBase::energize(){}
void TicDeviceBase::exitSafeStart(){}
void TicDeviceBase::enterSafeStart(){}
void TicDeviceBase::reset(){};
void TicDeviceBase::clearDriverError(){}
void TicDeviceBase::setMaxSpeed(uint32_t speed){}
void TicDeviceBase::setStartingSpeed(uint32_t speed){}
void TicDeviceBase::setMaxAccel(uint32_t accel){}
void TicDeviceBase::setMaxDecel(uint32_t decel){}
void TicDeviceBase::setStepMode(TicStepMode mode){}
void TicDeviceBase::setCurrentLimit(uint16_t limit){}
void TicDeviceBase::setDecayMode(TicDecayMode mode){}
void TicDeviceBase::setAgcMode(TicAgcMode mode){}
void TicDeviceBase::setAgcBottomCurrentLimit(TicAgcBottomCurrentLimit limit){}
void TicDeviceBase::setAgcCurrentBoostSteps(TicAgcCurrentBoostSteps steps){}
void TicDeviceBase::setAgcFrequencyLimit(TicAgcFrequencyLimit limit){}
TicOperationState TicDeviceBase::getOperationState(){return TicOperationState::Reset;}
bool TicDeviceBase::getEnergized(){}
bool TicDeviceBase::getPositionUncertain(){}
bool TicDeviceBase::getForwardLimitActive(){}
bool TicDeviceBase::getReverseLimitActive(){}
bool TicDeviceBase::getHomingActive(){}
uint16_t TicDeviceBase::getErrorStatus(){}
uint32_t TicDeviceBase::getErrorsOccurred(){}
TicPlanningMode TicDeviceBase::getPlanningMode(){return TicPlanningMode::Off;}
int32_t TicDeviceBase::getTargetPosition(){return 0;}
int32_t TicDeviceBase::getTargetVelocity(){return 0;}
uint32_t TicDeviceBase::getMaxSpeed(){return 0;}
uint32_t TicDeviceBase::getStartingSpeed(){return 0;}
uint32_t TicDeviceBase::getMaxAccel(){return 0;}
uint32_t TicDeviceBase::getMaxDecel(){return 0;}
int32_t TicDeviceBase::getCurrentPosition(){return 0;}
int32_t TicDeviceBase::getCurrentVelocity(){return 0;}
uint32_t TicDeviceBase::getActingTargetPosition(){return 0;}
uint32_t TicDeviceBase::getTimeSinceLastStep(){return 0;}
TicReset TicDeviceBase::getDeviceReset(){return TicReset::ResetLine;}
uint16_t TicDeviceBase::getVinVoltage(){return 0;}
uint32_t TicDeviceBase::getUpTime(){return 0;}
int32_t TicDeviceBase::getEncoderPosition(){return 0;}
uint16_t TicDeviceBase::getRCPulseWidth(){return 0;}
uint16_t TicDeviceBase::getAnalogReading(TicPin pin){return 0;}
bool TicDeviceBase::getDigitalReading(TicPin pin){return true;}
TicPinState TicDeviceBase::getPinState(TicPin pin){return TicPinState::HighImpedance;}
TicStepMode TicDeviceBase::getStepMode(){return TicStepMode::Microstep1;}
uint16_t TicDeviceBase::getCurrentLimit(){return 0;}
TicDecayMode TicDeviceBase::getDecayMode(){return TicDecayMode::Fast;}
TicInputState TicDeviceBase::getInputState(){return TicInputState::Halt;}
uint16_t TicDeviceBase::getInputAfterAveraging(){return 0;}
uint16_t TicDeviceBase::getInputAfterHysteresis(){return 0;}
int32_t TicDeviceBase::getInputAfterScaling(){return 0;}
TicMotorDriverError TicDeviceBase::getLastMotorDriverError(){return TicMotorDriverError::None;}
TicAgcMode TicDeviceBase::getAgcMode(){return TicAgcMode::Off;}
TicAgcBottomCurrentLimit TicDeviceBase::getAgcBottomCurrentLimit(){return TicAgcBottomCurrentLimit::P45;}
TicAgcCurrentBoostSteps TicDeviceBase::getAgcCurrentBoostSteps(){return TicAgcCurrentBoostSteps::S11;}
TicAgcFrequencyLimit TicDeviceBase::getAgcFrequencyLimit(){return TicAgcFrequencyLimit::Off;}
uint8_t TicDeviceBase::getLastHpDriverErrors(){return 0;}
void TicDeviceBase::getSetting(uint8_t offset, uint8_t length, uint8_t * buffer){}
uint8_t TicDeviceBase::getLastError(){return 0;}