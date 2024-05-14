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
 #include "../includes/TicDeviceBase.hpp"
#include <cstdint>

void TicDeviceBase::setTargetPosition(int32_t position){
    _channel->commandW32(TicCommand::SetTargetPosition, position);
}

void TicDeviceBase::setTargetVelocity(int32_t velocity){
    _channel->commandW32(TicCommand::SetTargetVelocity, velocity);
}

void TicDeviceBase::haltAndSetPosition(int32_t position){
    _channel->commandW32(TicCommand::HaltAndSetPosition, position);
}

void TicDeviceBase::haltAndHold(){
    _channel->commandQuick(TicCommand::HaltAndHold);
}

void TicDeviceBase::goHomeReverse(){
    _channel->commandW7(TicCommand::GoHome, 0);
}

void TicDeviceBase::goHomeForward(){
    _channel->commandW7(TicCommand::GoHome, 1);
}

void TicDeviceBase::resetCommandTimeout(){
    _channel->commandQuick(TicCommand::ResetCommandTimeout);
}

void TicDeviceBase::deenergize(){
    _channel->commandQuick(TicCommand::Deenergize);
}

void TicDeviceBase::energize(){
    _channel->commandQuick(TicCommand::Energize);
}

void TicDeviceBase::exitSafeStart(){
    _channel->commandQuick(TicCommand::ExitSafeStart);
}

void TicDeviceBase::enterSafeStart(){
    _channel->commandQuick(TicCommand::EnterSafeStart);
}

void TicDeviceBase::reset(){
    _channel->commandQuick(TicCommand::ResetCommandTimeout);
    ThisThread::sleep_for(10ms);
}

void TicDeviceBase::clearDriverError(){
    _channel->commandQuick(TicCommand::ClearDriverError);
}

void TicDeviceBase::setMaxSpeed(uint32_t speed){
    _channel->commandW32(TicCommand::SetSpeedMax, speed);
}

void TicDeviceBase::setStartingSpeed(uint32_t speed){
    _channel->commandW32(TicCommand::SetStartingSpeed, speed);
}

void TicDeviceBase::setMaxAccel(uint32_t accel){
    _channel->commandW32(TicCommand::SetAccelMax, accel);
}

void TicDeviceBase::setMaxDecel(uint32_t decel){
    _channel->commandW32(TicCommand::SetDecelMax, decel);
}

void TicDeviceBase::setStepMode(TicStepMode mode){
    _channel->commandW7(TicCommand::SetStepMode, (uint8_t) mode);
}

void TicDeviceBase::setCurrentLimit(uint16_t limit){

}

void TicDeviceBase::setDecayMode(TicDecayMode mode){
    _channel->commandW7(TicCommand::SetDecayMode, (uint8_t)mode);
}

//void TicDeviceBase::setAgcBottomCurrentLimit(TicAgcBottomCurrentLimit limit){}
//void TicDeviceBase::setAgcCurrentBoostSteps(TicAgcCurrentBoostSteps steps){}
//void TicDeviceBase::setAgcFrequencyLimit(TicAgcFrequencyLimit limit){}
TicOperationState TicDeviceBase::getOperationState(){

    return (TicOperationState)getVar8(VarOffset::OperationState);
}

bool TicDeviceBase::getEnergized(){
    return getVar8(VarOffset::MiscFlags1) >> (uint8_t)TicMiscFlags1::Energized & 1;
}

bool TicDeviceBase::getPositionUncertain(){
    return getVar8(VarOffset::MiscFlags1) >> (uint8_t)TicMiscFlags1::PositionUncertain & 1;
}

bool TicDeviceBase::getForwardLimitActive(){
    return getVar8(VarOffset::MiscFlags1) >> (uint8_t)TicMiscFlags1::ForwardLimitActive & 1;
}

bool TicDeviceBase::getReverseLimitActive(){
    return getVar8(VarOffset::MiscFlags1) >> (uint8_t)TicMiscFlags1::ReverseLimitActive & 1;
}

bool TicDeviceBase::getHomingActive(){
    return getVar8(VarOffset::MiscFlags1) >> (uint8_t)TicMiscFlags1::HomingActive & 1;
}

uint16_t TicDeviceBase::getErrorStatus(){
    return getVar16(VarOffset::ErrorStatus);
}

uint32_t TicDeviceBase::getErrorsOccurred(){
    uint32_t result;
    _channel->getSegment(TicCommand::GetVariableAndClearErrorsOccurred, VarOffset::ErrorsOccurred, 4, &result);
    return result;
}

TicPlanningMode TicDeviceBase::getPlanningMode(){
    return (TicPlanningMode)getVar8(VarOffset::PlanningMode);
}

int32_t TicDeviceBase::getTargetPosition(){
    return getVar32(VarOffset::TargetPosition);
}

int32_t TicDeviceBase::getTargetVelocity(){
    return getVar32(VarOffset::TargetVelocity);
}

uint32_t TicDeviceBase::getMaxSpeed(){
    return getVar32(VarOffset::SpeedMax);
}

uint32_t TicDeviceBase::getStartingSpeed(){
    return getVar32(VarOffset::StartingSpeed);
}

uint32_t TicDeviceBase::getMaxAccel(){
    return getVar32(VarOffset::AccelMax);
}

uint32_t TicDeviceBase::getMaxDecel(){
    return getVar32(VarOffset::DecelMax);
}

int32_t TicDeviceBase::getCurrentPosition(){
    return getVar32(VarOffset::CurrentPosition);
}

int32_t TicDeviceBase::getCurrentVelocity(){
    return getVar32(VarOffset::CurrentVelocity);
}

TicReset TicDeviceBase::getDeviceReset(){
    return (TicReset)getVar8(VarOffset::DeviceReset);
}

uint16_t TicDeviceBase::getVinVoltage(){
    return getVar16(VarOffset::VinVoltage);
}

uint32_t TicDeviceBase::getUpTime(){
    return getVar32(VarOffset::UpTime);
}

int32_t TicDeviceBase::getEncoderPosition(){
    return getVar32(VarOffset::EncoderPosition);
}

uint16_t TicDeviceBase::getRCPulseWidth(){
    return getVar16(VarOffset::RCPulseWidth);
}

uint16_t TicDeviceBase::getAnalogReading(TicPin pin){
    uint8_t offset = VarOffset::AnalogReadingSCL + 2 * (uint8_t)pin;
    return getVar16(offset);
}

bool TicDeviceBase::getDigitalReading(TicPin pin){
    uint8_t readings = getVar8(VarOffset::DigitalReadings);
    return (readings >> (uint8_t)pin) & 1;
}

TicPinState TicDeviceBase::getPinState(TicPin pin){
    uint8_t states = getVar8(VarOffset::PinStates);
    return (TicPinState)(states >> (2 * (uint8_t)pin) & 0b11);
}

TicStepMode TicDeviceBase::getStepMode(){
    return (TicStepMode)getVar8(VarOffset::StepMode);
}

TicDecayMode TicDeviceBase::getDecayMode(){
    return (TicDecayMode)getVar8(VarOffset::DecayMode);
}

TicInputState TicDeviceBase::getInputState(){
    return (TicInputState)getVar8(VarOffset::InputState);
}

uint16_t TicDeviceBase::getInputAfterAveraging(){
    
}

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

uint8_t TicDeviceBase::getVar8(uint8_t offset){
    uint8_t result;
    _channel->getSegment(TicCommand::GetVariable, offset, 1, &result);
    return result;
}

uint16_t TicDeviceBase::getVar16(uint8_t offset){
    uint8_t buffer[2];
    _channel->getSegment(TicCommand::GetVariable, offset, 2, &buffer);
    return ((uint16_t)buffer[0] << 0) | ((uint16_t)buffer[1] << 8);
}

uint32_t TicDeviceBase::getVar32(uint8_t offset){
    uint8_t buffer[4];
    _channel->getSegment(TicCommand::GetVariable, offset, 4, buffer);
    return ((uint32_t)buffer[0] << 0) |
      ((uint32_t)buffer[1] << 8) |
      ((uint32_t)buffer[2] << 16) |
      ((uint32_t)buffer[3] << 24);
}