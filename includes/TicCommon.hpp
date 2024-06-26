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
 * @file TicCommon.hpp
 * @brief Common tic definitions
 *
 * @note Contact maintainer for modifications: info@soft-loop.com
 */
 #pragma once
 
    enum class TicError
    {
        IntentionallyDeenergized = 0,
        MotorDriverError         = 1,
        LowVin                   = 2,
        KillSwitch               = 3,
        RequiredInputInvalid     = 4,
        SerialError              = 5,
        CommandTimeout           = 6,
        SafeStartViolation       = 7,
        ErrLineHigh              = 8,
        SerialFraming            = 16,
        RxOverrun                = 17,
        Format                   = 18,
        Crc                      = 19,
        EncoderSkip              = 20,
    };

/// This enum defines the Tic command codes which are used for its serial, I2C,
/// and USB interface.  These codes are used by the library and you should not
/// need to use them.
    enum class TicCommand
    {
        SetTargetPosition                 = 0xE0,
        SetTargetVelocity                 = 0xE3,
        HaltAndSetPosition                = 0xEC,
        HaltAndHold                       = 0x89,
        GoHome                            = 0x97,
        ResetCommandTimeout               = 0x8C,
        Deenergize                        = 0x86,
        Energize                          = 0x85,
        ExitSafeStart                     = 0x83,
        EnterSafeStart                    = 0x8F,
        Reset                             = 0xB0,
        ClearDriverError                  = 0x8A,
        SetSpeedMax                       = 0xE6,
        SetStartingSpeed                  = 0xE5,
        SetAccelMax                       = 0xEA,
        SetDecelMax                       = 0xE9,
        SetStepMode                       = 0x94,
        SetCurrentLimit                   = 0x91,
        SetDecayMode                      = 0x92,
        SetAgcOption                      = 0x98,
        GetVariable                       = 0xA1,
        GetVariableAndClearErrorsOccurred = 0xA2,
        GetSetting                        = 0xA8,
    };

/// This enum defines the possible operation states for the Tic.
///
/// See TicBase::getOperationState().
    enum class TicOperationState
    {
        Reset             = 0,
        Deenergized       = 2,
        SoftError         = 4,
        WaitingForErrLine = 6,
        StartingUp        = 8,
        Normal            = 10,
    };

/// This enum defines the possible planning modes for the Tic's step generation
/// code.
///
/// See TicBase::getPlanningMode().
    enum class TicPlanningMode
    {
        Off            = 0,
        TargetPosition = 1,
        TargetVelocity = 2,
    };

/// This enum defines the possible causes of a full microcontroller reset for
/// the Tic.
///
/// See TicBase::getDeviceReset().
    enum class TicReset
    {
        PowerUp        = 0,
        Brownout       = 1,
        ResetLine      = 2,
        Watchdog       = 4,
        Software       = 8,
        StackOverflow  = 16,
        StackUnderflow = 32,
    };

/// This enum defines the possible decay modes.
///
/// See TicBase::getDecayMode() and TicBase::setDecayMode().
    enum class TicDecayMode
    {
        /// This specifies "Mixed" decay mode on the Tic T825
        /// and "Mixed 50%" on the Tic T824.
        Mixed    = 0,

        /// This specifies "Slow" decay mode.
        Slow     = 1,

        /// This specifies "Fast" decay mode.
        Fast     = 2,

        /// This is the same as TicDecayMode::Mixed, but better expresses your
        /// intent if you want to use "Mixed 50%' mode on a Tic T834.
        Mixed50 = 0,

        /// This specifies "Mixed 25%" decay mode on the Tic T824
        /// and is the same as TicDecayMode::Mixed on the Tic T825.
        Mixed25 = 3,

        /// This specifies "Mixed 75%" decay mode on the Tic T824
        /// and is the same as TicDecayMode::Mixed on the Tic T825.
        Mixed75 = 4,
    };

/// This enum defines the possible step modes.
///
/// See TicBase::getStepMode() and TicBase::setStepMode().
    enum class TicStepMode
    {
        Full    = 0,
        Half    = 1,

        Microstep1  = 0,
        Microstep2  = 1,
        Microstep4  = 2,
        Microstep8  = 3,
        Microstep16 = 4,
        Microstep32 = 5,
        Microstep2_100p = 6,
        Microstep64 = 7,
        Microstep128 = 8,
        Microstep256 = 9,
    };

/// This enum defines possible AGC modes.
///
/// See TicBase::setAgcMode() and TicBase::getAgcMode().
    enum class TicAgcMode
    {
        Off = 0,
        On = 1,
        ActiveOff = 2,
    };

/// This enum defines possible AGC buttom current limit percentages.
///
/// See TicBase::setAgcBottomCurrentLimit() and
/// TicBase:getAgcBottomCurrentLimit().
    enum class TicAgcBottomCurrentLimit
    {
        P45 = 0,
        P50 = 1,
        P55 = 2,
        P60 = 3,
        P65 = 4,
        P70 = 5,
        P75 = 6,
        P80 = 7,
    };

/// This enum defines possible AGC current boost steps values.
///
/// See TicBase::setAgcCurrentBoostSteps() and
/// TicBase::getAgcCurrentBoostSteps().
    enum class TicAgcCurrentBoostSteps
    {
        S5 = 0,
        S7 = 1,
        S9 = 2,
        S11 = 3,
    };

/// This enuam defines possible AGC frequency limit values.
///
/// See TicBase::setAgcFrequencyLimit() and TicBase::getAgcFrequencyLimit().
    enum class TicAgcFrequencyLimit
    {
        Off = 0,
        F225Hz = 1,
        F450Hz = 2,
        F675Hz = 3,
    };

/// This enum defines the Tic's control pins.
    enum class TicPin
    {
        SCL = 0,
        SDA = 1,
        TX  = 2,
        RX  = 3,
        RC  = 4,
    };

/// This enum defines the Tic's pin states.
///
/// See TicBase::getPinState().
    enum class TicPinState
    {
        HighImpedance = 0,
        InputPullUp   = 1,
        OutputLow     = 2,
        OutputHigh    = 3,
    };

/// This enum defines the possible states of the Tic's main input.
    enum class TicInputState
    {
        /// The input is not ready yet.  More samples are needed, or a command has not
        /// been received yet.
        NotReady = 0,

        /// The input is invalid.
        Invalid = 1,

        /// The input is valid and is telling the Tic to halt the motor.
        Halt = 2,

        /// The input is valid and is telling the Tic to go to a target position,
        /// which you can get with TicBase::getInputAfterScaling().
        Position = 3,

        /// The input is valid and is telling the Tic to go to a target velocity,
        /// which you can get with TicBase::getInputAfterScaling().
        Velocity = 4,
    };

/// This enum defines the bits in the Tic's Misc Flags 1 register.  You should
/// not need to use this directly.  See TicBase::getEnergized() and
/// TicBase::getPositionUncertain().
    enum class TicMiscFlags1
    {
        Energized = 0,
        PositionUncertain = 1,
        ForwardLimitActive = 2,
        ReverseLimitActive = 3,
        HomingActive = 4,
    };

/// This enum defines possible motor driver errors for the Tic T249.
///
/// See TicBase::getLastMotorDriverError().
    enum class TicMotorDriverError
    {
        None = 0,
        OverCurrent = 1,
        OverTemperature = 2,
    };

/// This enum defines the bits in the "Last HP driver errors" variable.
///
/// See TicBase::getLastHpDriverErrors().
    enum class TicHpDriverError
    {
        OverTemperature = 0,
        OverCurrentA = 1,
        OverCurrentB = 2,
        PreDriverFaultA = 3,
        PreDriverFaultB = 4,
        UnderVoltage = 5,
        Verify = 7,
    };
