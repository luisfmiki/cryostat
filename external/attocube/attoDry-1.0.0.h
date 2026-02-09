/**
 * Copyright (C) 2020 attocube systems AG
 * Usage is up to a separate agreement
**/

/**
 * @file generatedAPI.h
 * @brief API for use with attocube devices
**/

#ifndef __GENERATEDAPI_H_attoDry_1_0_0__
#define __GENERATEDAPI_H_attoDry_1_0_0__

#ifndef ATTO_PREFIX
#define ATTO_PREFIX attoDry_1_0_0_
#endif

#define ATTO_PREFIX_CONCAT(x,y) x ## y
#define ATTO_PREFIX_EVALUATOR(x,y) ATTO_PREFIX_CONCAT(x,y)
#define ATTO_FUNCTION(function_name) ATTO_PREFIX_EVALUATOR(ATTO_PREFIX, function_name)

#include <stdbool.h>
#include "attocubeJSONCall.h"
#ifdef __cplusplus
extern "C" {
#endif

/** @brief @attoDry_action_autotunePID
*  Autotune heater PID
*
*  @param deviceHandle     Handle of device
*  @param channel          Channel number
*  @param tuningType       0 tune P, 1 tune PI, 2 tune PID
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_action_autotunePID_attoDry_1_0_0(int deviceHandle, int channel, int tuningType);

static inline int ATTO_FUNCTION(attoDry_action_autotunePID)(int deviceHandle, int channel, int tuningType) {
    return attoDry_action_autotunePID_attoDry_1_0_0(deviceHandle, channel, tuningType);
}


/** @brief @attoDry_action_cancelCurrentCommand
*  Cancels the current command
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_action_cancelCurrentCommand_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_action_cancelCurrentCommand)(int deviceHandle) {
    return attoDry_action_cancelCurrentCommand_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_action_getCurrentCommand
*  Get current command name
*
*  @param deviceHandle     Handle of device
*
*  @param current_command  
*  @param size             Maximum size of buffer current_command
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_action_getCurrentCommand_attoDry_1_0_0(int deviceHandle, char* current_command, int size);

static inline int ATTO_FUNCTION(attoDry_action_getCurrentCommand)(int deviceHandle, char* current_command, int size) {
    return attoDry_action_getCurrentCommand_attoDry_1_0_0(deviceHandle, current_command, size);
}


/** @brief @attoDry_action_getCurrentCommandStatus
*  Get current command status
*
*  @param deviceHandle     Handle of device
*
*  @param current_command  
*  @param size             Maximum size of buffer current_command
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_action_getCurrentCommandStatus_attoDry_1_0_0(int deviceHandle, char* current_command, int size);

static inline int ATTO_FUNCTION(attoDry_action_getCurrentCommandStatus)(int deviceHandle, char* current_command, int size) {
    return attoDry_action_getCurrentCommandStatus_attoDry_1_0_0(deviceHandle, current_command, size);
}


/** @brief @attoDry_action_getGoToBaseRampRateSetting
*  Get sample ramp rate
*
*  @param deviceHandle     Handle of device
*
*  @param errorcode        
*  @param Rate             Ramp rate in Kelvin / minute. 0.1 - 100. 0.0 means ramp limit is off.
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_action_getGoToBaseRampRateSetting_attoDry_1_0_0(int deviceHandle, int* errorcode, double* Rate);

static inline int ATTO_FUNCTION(attoDry_action_getGoToBaseRampRateSetting)(int deviceHandle, int* errorcode, double* Rate) {
    return attoDry_action_getGoToBaseRampRateSetting_attoDry_1_0_0(deviceHandle, errorcode, Rate);
}


/** @brief @attoDry_action_getSampleExchangePumpOnSetting
*  Get sample exchange pump on setting
*
*  @param deviceHandle     Handle of device
*
*  @param errorcode        
*  @param OnOrOff          
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_action_getSampleExchangePumpOnSetting_attoDry_1_0_0(int deviceHandle, int* errorcode, bool* OnOrOff);

static inline int ATTO_FUNCTION(attoDry_action_getSampleExchangePumpOnSetting)(int deviceHandle, int* errorcode, bool* OnOrOff) {
    return attoDry_action_getSampleExchangePumpOnSetting_attoDry_1_0_0(deviceHandle, errorcode, OnOrOff);
}


/** @brief @attoDry_action_getSampleExchangeRampRateSetting
*  Get sample ramp rate
*
*  @param deviceHandle     Handle of device
*
*  @param errorcode        
*  @param Rate             Ramp rate in Kelvin / minute. 0.1 - 100. 0.0 means ramp limit is off.
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_action_getSampleExchangeRampRateSetting_attoDry_1_0_0(int deviceHandle, int* errorcode, double* Rate);

static inline int ATTO_FUNCTION(attoDry_action_getSampleExchangeRampRateSetting)(int deviceHandle, int* errorcode, double* Rate) {
    return attoDry_action_getSampleExchangeRampRateSetting_attoDry_1_0_0(deviceHandle, errorcode, Rate);
}


/** @brief @attoDry_action_getWaitForEvent
*  Gets the event the cryostat waits for currently
*
*  @param deviceHandle     Handle of device
*
*  @param event            event the cryostat waits for
*  @param size             Maximum size of buffer event
*
*  @return event the cryostat waits for
*/
int ATTOCUBE_API attoDry_action_getWaitForEvent_attoDry_1_0_0(int deviceHandle, char* event, int size);

static inline int ATTO_FUNCTION(attoDry_action_getWaitForEvent)(int deviceHandle, char* event, int size) {
    return attoDry_action_getWaitForEvent_attoDry_1_0_0(deviceHandle, event, size);
}


/** @brief @attoDry_action_goToBase
*  Cool down to base temperature
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_action_goToBase_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_action_goToBase)(int deviceHandle) {
    return attoDry_action_goToBase_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_action_goToBaseSoft
*  Cool down to base temperature with fixed ramp rate
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_action_goToBaseSoft_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_action_goToBaseSoft)(int deviceHandle) {
    return attoDry_action_goToBaseSoft_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_action_postEvent
*  Posts the event. See: getWaitForEvent()
*
*  @param deviceHandle     Handle of device
*  @param eventName        
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_action_postEvent_attoDry_1_0_0(int deviceHandle, const char* eventName);

static inline int ATTO_FUNCTION(attoDry_action_postEvent)(int deviceHandle, const char* eventName) {
    return attoDry_action_postEvent_attoDry_1_0_0(deviceHandle, eventName);
}


/** @brief @attoDry_action_sampleExchange
*  Start sample exchange
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_action_sampleExchange_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_action_sampleExchange)(int deviceHandle) {
    return attoDry_action_sampleExchange_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_action_sampleExchangeSoft
*  Start sample exchange with fixed ramp rate
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_action_sampleExchangeSoft_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_action_sampleExchangeSoft)(int deviceHandle) {
    return attoDry_action_sampleExchangeSoft_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_action_setGoToBaseRampRateSetting
*  Set sample ramp rate
*
*  @param deviceHandle     Handle of device
*  @param rampRate         Ramp rate in Kelvin / minute. 0.1 - 100. 0.0 means ramp limit is off.
*
*  @param errorcode        
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_action_setGoToBaseRampRateSetting_attoDry_1_0_0(int deviceHandle, double rampRate, int* errorcode);

static inline int ATTO_FUNCTION(attoDry_action_setGoToBaseRampRateSetting)(int deviceHandle, double rampRate, int* errorcode) {
    return attoDry_action_setGoToBaseRampRateSetting_attoDry_1_0_0(deviceHandle, rampRate, errorcode);
}


/** @brief @attoDry_action_setSampleExchangePumpOnSetting
*  Set sample exchange pump on setting
*
*  @param deviceHandle     Handle of device
*  @param onOrOff          
*
*  @param errorcode        :param onOrOff:
*
*  @return :param onOrOff:
*/
int ATTOCUBE_API attoDry_action_setSampleExchangePumpOnSetting_attoDry_1_0_0(int deviceHandle, bool onOrOff, int* errorcode);

static inline int ATTO_FUNCTION(attoDry_action_setSampleExchangePumpOnSetting)(int deviceHandle, bool onOrOff, int* errorcode) {
    return attoDry_action_setSampleExchangePumpOnSetting_attoDry_1_0_0(deviceHandle, onOrOff, errorcode);
}


/** @brief @attoDry_action_setSampleExchangeRampRateSetting
*  Set sample ramp rate
*
*  @param deviceHandle     Handle of device
*  @param rampRate         Ramp rate in Kelvin / minute. 0.1 - 100. 0.0 means ramp limit is off.
*
*  @param errorcode        
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_action_setSampleExchangeRampRateSetting_attoDry_1_0_0(int deviceHandle, double rampRate, int* errorcode);

static inline int ATTO_FUNCTION(attoDry_action_setSampleExchangeRampRateSetting)(int deviceHandle, double rampRate, int* errorcode) {
    return attoDry_action_setSampleExchangeRampRateSetting_attoDry_1_0_0(deviceHandle, rampRate, errorcode);
}


/** @brief @attoDry_action_shutdown
*  Start shutdown
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_action_shutdown_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_action_shutdown)(int deviceHandle) {
    return attoDry_action_shutdown_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_action_switchMagnetsOff
*  Switches magnets off
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_action_switchMagnetsOff_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_action_switchMagnetsOff)(int deviceHandle) {
    return attoDry_action_switchMagnetsOff_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_exchange_downloadCalibrationCurve
*  Gets the exchange sensor calibration curve
*
*  @param deviceHandle     Handle of device
*
*  @param calibration_data 
*  @param size             Maximum size of buffer calibration_data
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_downloadCalibrationCurve_attoDry_1_0_0(int deviceHandle, char* calibration_data, int size);

static inline int ATTO_FUNCTION(attoDry_exchange_downloadCalibrationCurve)(int deviceHandle, char* calibration_data, int size) {
    return attoDry_exchange_downloadCalibrationCurve_attoDry_1_0_0(deviceHandle, calibration_data, size);
}


/** @brief @attoDry_exchange_downloadCalibrationCurve340
*  Gets the exchange sensor .340 calibration curve
*
*  @param deviceHandle     Handle of device
*
*  @param calibration_data 
*  @param size             Maximum size of buffer calibration_data
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_downloadCalibrationCurve340_attoDry_1_0_0(int deviceHandle, char* calibration_data, int size);

static inline int ATTO_FUNCTION(attoDry_exchange_downloadCalibrationCurve340)(int deviceHandle, char* calibration_data, int size) {
    return attoDry_exchange_downloadCalibrationCurve340_attoDry_1_0_0(deviceHandle, calibration_data, size);
}


/** @brief @attoDry_exchange_getHeaterAllZoneRampRates
*  Get exchange heater all zones ramp rate
*
*  @param deviceHandle     Handle of device
*
*  @param errorcode        Error code
*  @param rampRate         Ramp rate for this zone 0.1 100 K/min
*
*  @return Error code
*/
int ATTOCUBE_API attoDry_exchange_getHeaterAllZoneRampRates_attoDry_1_0_0(int deviceHandle, int* errorcode, double* rampRate);

static inline int ATTO_FUNCTION(attoDry_exchange_getHeaterAllZoneRampRates)(int deviceHandle, int* errorcode, double* rampRate) {
    return attoDry_exchange_getHeaterAllZoneRampRates_attoDry_1_0_0(deviceHandle, errorcode, rampRate);
}


/** @brief @attoDry_exchange_getHeaterDefaultZoneSettings
*  Get exchange heater zone settings
*
*  @param deviceHandle     Handle of device
*  @param zone             Zone number
*
*  @param errorcode        Error code
*  @param upperbound       Upper Setpoint boundary of this zone in kelvin
*  @param P                P
*  @param I                I
*  @param D                D
*  @param manualOutput     Manual output for this zone 0 to 100%
*  @param heatingRange     Heating range see class HeaterRanges and Lake Shore 336 manual for ZONE command
*  @param rampRate         Ramp rate for this zone 0.1 100 K/min
*
*  @return Error code
*/
int ATTOCUBE_API attoDry_exchange_getHeaterDefaultZoneSettings_attoDry_1_0_0(int deviceHandle, int zone, int* errorcode, double* upperbound, double* P, double* I, double* D, double* manualOutput, int* heatingRange, double* rampRate);

static inline int ATTO_FUNCTION(attoDry_exchange_getHeaterDefaultZoneSettings)(int deviceHandle, int zone, int* errorcode, double* upperbound, double* P, double* I, double* D, double* manualOutput, int* heatingRange, double* rampRate) {
    return attoDry_exchange_getHeaterDefaultZoneSettings_attoDry_1_0_0(deviceHandle, zone, errorcode, upperbound, P, I, D, manualOutput, heatingRange, rampRate);
}


/** @brief @attoDry_exchange_getHeaterHeatingMode
*  Gets the exchange heater heating mode
*
*  @param deviceHandle     Handle of device
*
*  @param mode             
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_getHeaterHeatingMode_attoDry_1_0_0(int deviceHandle, int* mode);

static inline int ATTO_FUNCTION(attoDry_exchange_getHeaterHeatingMode)(int deviceHandle, int* mode) {
    return attoDry_exchange_getHeaterHeatingMode_attoDry_1_0_0(deviceHandle, mode);
}


/** @brief @attoDry_exchange_getHeaterNumberOfDefaultZones
*  Get the number of the exchange heater default zones
*
*  @param deviceHandle     Handle of device
*
*  @param errorcode        Error code
*  @param number_of_zones  
*
*  @return Error code
*/
int ATTOCUBE_API attoDry_exchange_getHeaterNumberOfDefaultZones_attoDry_1_0_0(int deviceHandle, int* errorcode, int* number_of_zones);

static inline int ATTO_FUNCTION(attoDry_exchange_getHeaterNumberOfDefaultZones)(int deviceHandle, int* errorcode, int* number_of_zones) {
    return attoDry_exchange_getHeaterNumberOfDefaultZones_attoDry_1_0_0(deviceHandle, errorcode, number_of_zones);
}


/** @brief @attoDry_exchange_getHeaterNumberOfZones
*  Get the number of the exchange heater zones
*
*  @param deviceHandle     Handle of device
*
*  @param errorcode        Error code
*  @param number_of_zones  
*
*  @return Error code
*/
int ATTOCUBE_API attoDry_exchange_getHeaterNumberOfZones_attoDry_1_0_0(int deviceHandle, int* errorcode, int* number_of_zones);

static inline int ATTO_FUNCTION(attoDry_exchange_getHeaterNumberOfZones)(int deviceHandle, int* errorcode, int* number_of_zones) {
    return attoDry_exchange_getHeaterNumberOfZones_attoDry_1_0_0(deviceHandle, errorcode, number_of_zones);
}


/** @brief @attoDry_exchange_getHeaterPower
*  Gets the exchange heater power
*
*  @param deviceHandle     Handle of device
*
*  @param power            
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_getHeaterPower_attoDry_1_0_0(int deviceHandle, double* power);

static inline int ATTO_FUNCTION(attoDry_exchange_getHeaterPower)(int deviceHandle, double* power) {
    return attoDry_exchange_getHeaterPower_attoDry_1_0_0(deviceHandle, power);
}


/** @brief @attoDry_exchange_getHeaterRes
*  Gets the exchange heater resistance
*
*  @param deviceHandle     Handle of device
*
*  @param resistance       
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_getHeaterRes_attoDry_1_0_0(int deviceHandle, double* resistance);

static inline int ATTO_FUNCTION(attoDry_exchange_getHeaterRes)(int deviceHandle, double* resistance) {
    return attoDry_exchange_getHeaterRes_attoDry_1_0_0(deviceHandle, resistance);
}


/** @brief @attoDry_exchange_getHeaterStatus
*  Gets the exchange heater status
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_getHeaterStatus_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_exchange_getHeaterStatus)(int deviceHandle) {
    return attoDry_exchange_getHeaterStatus_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_exchange_getHeaterZoneSettings
*  Get exchange heater zone settings
*
*  @param deviceHandle     Handle of device
*  @param zone             Zone number
*
*  @param errorcode        Error code
*  @param upperbound       Upper Setpoint boundary of this zone in kelvin
*  @param P                P
*  @param I                I
*  @param D                D
*  @param manualOutput     Manual output for this zone 0 to 100%
*  @param heatingRange     Heating range see class HeaterRanges and Lake Shore 336 manual for ZONE command
*  @param rampRate         Ramp rate for this zone 0.1 100 K/min
*
*  @return Error code
*/
int ATTOCUBE_API attoDry_exchange_getHeaterZoneSettings_attoDry_1_0_0(int deviceHandle, int zone, int* errorcode, double* upperbound, double* P, double* I, double* D, double* manualOutput, int* heatingRange, double* rampRate);

static inline int ATTO_FUNCTION(attoDry_exchange_getHeaterZoneSettings)(int deviceHandle, int zone, int* errorcode, double* upperbound, double* P, double* I, double* D, double* manualOutput, int* heatingRange, double* rampRate) {
    return attoDry_exchange_getHeaterZoneSettings_attoDry_1_0_0(deviceHandle, zone, errorcode, upperbound, P, I, D, manualOutput, heatingRange, rampRate);
}


/** @brief @attoDry_exchange_getInputFilterSettings
*  Gets the exchange input filter settings
*
*  @param deviceHandle     Handle of device
*
*  @param off_or_on        
*  @param point            
*  @param window           
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_getInputFilterSettings_attoDry_1_0_0(int deviceHandle, bool* off_or_on, int* point, int* window);

static inline int ATTO_FUNCTION(attoDry_exchange_getInputFilterSettings)(int deviceHandle, bool* off_or_on, int* point, int* window) {
    return attoDry_exchange_getInputFilterSettings_attoDry_1_0_0(deviceHandle, off_or_on, point, window);
}


/** @brief @attoDry_exchange_getMaxPower
*  Gets the exchange heater maximum power
*
*  @param deviceHandle     Handle of device
*
*  @param maxPower         
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_getMaxPower_attoDry_1_0_0(int deviceHandle, double* maxPower);

static inline int ATTO_FUNCTION(attoDry_exchange_getMaxPower)(int deviceHandle, double* maxPower) {
    return attoDry_exchange_getMaxPower_attoDry_1_0_0(deviceHandle, maxPower);
}


/** @brief @attoDry_exchange_getResistance
*  Gets the exchange temperature resistance
*
*  @param deviceHandle     Handle of device
*
*  @param exchange_resistance 
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_getResistance_attoDry_1_0_0(int deviceHandle, double* exchange_resistance);

static inline int ATTO_FUNCTION(attoDry_exchange_getResistance)(int deviceHandle, double* exchange_resistance) {
    return attoDry_exchange_getResistance_attoDry_1_0_0(deviceHandle, exchange_resistance);
}


/** @brief @attoDry_exchange_getSetPoint
*  Gets the exchange set point
*
*  @param deviceHandle     Handle of device
*
*  @param set_point        
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_getSetPoint_attoDry_1_0_0(int deviceHandle, double* set_point);

static inline int ATTO_FUNCTION(attoDry_exchange_getSetPoint)(int deviceHandle, double* set_point) {
    return attoDry_exchange_getSetPoint_attoDry_1_0_0(deviceHandle, set_point);
}


/** @brief @attoDry_exchange_getTempControlStatus
*  Gets the exchange heater status
*
*  @param deviceHandle     Handle of device
*
*  @param Status           
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_getTempControlStatus_attoDry_1_0_0(int deviceHandle, bool* Status);

static inline int ATTO_FUNCTION(attoDry_exchange_getTempControlStatus)(int deviceHandle, bool* Status) {
    return attoDry_exchange_getTempControlStatus_attoDry_1_0_0(deviceHandle, Status);
}


/** @brief @attoDry_exchange_getTemperature
*  Gets the exchange temperature
*
*  @param deviceHandle     Handle of device
*
*  @param exchange_temperature 
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_getTemperature_attoDry_1_0_0(int deviceHandle, double* exchange_temperature);

static inline int ATTO_FUNCTION(attoDry_exchange_getTemperature)(int deviceHandle, double* exchange_temperature) {
    return attoDry_exchange_getTemperature_attoDry_1_0_0(deviceHandle, exchange_temperature);
}


/** @brief @attoDry_exchange_setHeaterAllZoneRampRates
*  Set exchange heater all zones ramp rate
*
*  @param deviceHandle     Handle of device
*  @param rampRate         Ramp rate for this zone 0.1 100 K/min
*
*  @param errorcode        Error code
*
*  @return Error code
*/
int ATTOCUBE_API attoDry_exchange_setHeaterAllZoneRampRates_attoDry_1_0_0(int deviceHandle, double rampRate, int* errorcode);

static inline int ATTO_FUNCTION(attoDry_exchange_setHeaterAllZoneRampRates)(int deviceHandle, double rampRate, int* errorcode) {
    return attoDry_exchange_setHeaterAllZoneRampRates_attoDry_1_0_0(deviceHandle, rampRate, errorcode);
}


/** @brief @attoDry_exchange_setHeaterPower
*  Sets the exchange heater power
*
*  @param deviceHandle     Handle of device
*  @param value            
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_setHeaterPower_attoDry_1_0_0(int deviceHandle, double value);

static inline int ATTO_FUNCTION(attoDry_exchange_setHeaterPower)(int deviceHandle, double value) {
    return attoDry_exchange_setHeaterPower_attoDry_1_0_0(deviceHandle, value);
}


/** @brief @attoDry_exchange_setHeaterZoneSettings
*  Set exchange heater zone settings
*
*  @param deviceHandle     Handle of device
*  @param zone             Zone number
*  @param upperbound       Upper Setpoint boundary of this zone in kelvin
*  @param P                P
*  @param I                I
*  @param D                D
*  @param manualOutput     Manual output for this zone 0 to 100%
*  @param heatingRange     Heating range see class HeaterRanges and Lake Shore 336 manual for ZONE command
*
*  @param errorcode        Error code
*
*  @return Error code
*/
int ATTOCUBE_API attoDry_exchange_setHeaterZoneSettings_attoDry_1_0_0(int deviceHandle, int zone, double upperbound, double P, double I, double D, double manualOutput, int heatingRange, int* errorcode);

static inline int ATTO_FUNCTION(attoDry_exchange_setHeaterZoneSettings)(int deviceHandle, int zone, double upperbound, double P, double I, double D, double manualOutput, int heatingRange, int* errorcode) {
    return attoDry_exchange_setHeaterZoneSettings_attoDry_1_0_0(deviceHandle, zone, upperbound, P, I, D, manualOutput, heatingRange, errorcode);
}


/** @brief @attoDry_exchange_setInputFilterSettings
*  Sets the exchange input filter settings
*
*  @param deviceHandle     Handle of device
*  @param filterOn         
*  @param numberOfPoints   
*  @param windowSize       
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_setInputFilterSettings_attoDry_1_0_0(int deviceHandle, bool filterOn, int numberOfPoints, int windowSize);

static inline int ATTO_FUNCTION(attoDry_exchange_setInputFilterSettings)(int deviceHandle, bool filterOn, int numberOfPoints, int windowSize) {
    return attoDry_exchange_setInputFilterSettings_attoDry_1_0_0(deviceHandle, filterOn, numberOfPoints, windowSize);
}


/** @brief @attoDry_exchange_setSetPoint
*  Sets the exchange set point
*
*  @param deviceHandle     Handle of device
*  @param setPoint         
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_setSetPoint_attoDry_1_0_0(int deviceHandle, double setPoint);

static inline int ATTO_FUNCTION(attoDry_exchange_setSetPoint)(int deviceHandle, double setPoint) {
    return attoDry_exchange_setSetPoint_attoDry_1_0_0(deviceHandle, setPoint);
}


/** @brief @attoDry_exchange_startHeaterOpenLoopPower
*  Starts the exchange heater in open loop mode with the previously set power
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_startHeaterOpenLoopPower_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_exchange_startHeaterOpenLoopPower)(int deviceHandle) {
    return attoDry_exchange_startHeaterOpenLoopPower_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_exchange_startHeaterZoneMode
*  Starts the exchange heater in zone mode
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_startHeaterZoneMode_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_exchange_startHeaterZoneMode)(int deviceHandle) {
    return attoDry_exchange_startHeaterZoneMode_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_exchange_startTempControl
*  Starts the exchange heater
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_startTempControl_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_exchange_startTempControl)(int deviceHandle) {
    return attoDry_exchange_startTempControl_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_exchange_stopTempControl
*  Stops the exchange heater
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_stopTempControl_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_exchange_stopTempControl)(int deviceHandle) {
    return attoDry_exchange_stopTempControl_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_exchange_uploadCalibrationCurve
*  Sets the exchange sensor calibration curve
*   May time out, but the upload will still work
*
*  @param deviceHandle     Handle of device
*  @param calibrationData  
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_uploadCalibrationCurve_attoDry_1_0_0(int deviceHandle, const char* calibrationData);

static inline int ATTO_FUNCTION(attoDry_exchange_uploadCalibrationCurve)(int deviceHandle, const char* calibrationData) {
    return attoDry_exchange_uploadCalibrationCurve_attoDry_1_0_0(deviceHandle, calibrationData);
}


/** @brief @attoDry_exchange_uploadCalibrationCurve340
*  Sets the exchange sensor .340 calibration curve
*   May time out, but the upload will still work
*
*  @param deviceHandle     Handle of device
*  @param calibrationData  
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_exchange_uploadCalibrationCurve340_attoDry_1_0_0(int deviceHandle, const char* calibrationData);

static inline int ATTO_FUNCTION(attoDry_exchange_uploadCalibrationCurve340)(int deviceHandle, const char* calibrationData) {
    return attoDry_exchange_uploadCalibrationCurve340_attoDry_1_0_0(deviceHandle, calibrationData);
}


/** @brief @attoDry_pressures_getSampleSpacePressure
*  Gets the sample space pressure
*
*  @param deviceHandle     Handle of device
*
*  @param sample_space_pressure 
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_pressures_getSampleSpacePressure_attoDry_1_0_0(int deviceHandle, double* sample_space_pressure);

static inline int ATTO_FUNCTION(attoDry_pressures_getSampleSpacePressure)(int deviceHandle, double* sample_space_pressure) {
    return attoDry_pressures_getSampleSpacePressure_attoDry_1_0_0(deviceHandle, sample_space_pressure);
}


/** @brief @attoDry_sample_downloadCalibrationCurve
*  Gets the sample sensor calibration curve
*
*  @param deviceHandle     Handle of device
*
*  @param calibration_data 
*  @param size             Maximum size of buffer calibration_data
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_downloadCalibrationCurve_attoDry_1_0_0(int deviceHandle, char* calibration_data, int size);

static inline int ATTO_FUNCTION(attoDry_sample_downloadCalibrationCurve)(int deviceHandle, char* calibration_data, int size) {
    return attoDry_sample_downloadCalibrationCurve_attoDry_1_0_0(deviceHandle, calibration_data, size);
}


/** @brief @attoDry_sample_downloadCalibrationCurve340
*  Gets the sample sensor .340 calibration curve
*
*  @param deviceHandle     Handle of device
*
*  @param calibration_data 
*  @param size             Maximum size of buffer calibration_data
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_downloadCalibrationCurve340_attoDry_1_0_0(int deviceHandle, char* calibration_data, int size);

static inline int ATTO_FUNCTION(attoDry_sample_downloadCalibrationCurve340)(int deviceHandle, char* calibration_data, int size) {
    return attoDry_sample_downloadCalibrationCurve340_attoDry_1_0_0(deviceHandle, calibration_data, size);
}


/** @brief @attoDry_sample_getHeaterAllZoneRampRates
*  Get sample heater all zones ramp rate
*
*  @param deviceHandle     Handle of device
*
*  @param errorcode        Error code
*  @param rampRate         Ramp rate for this zone 0.1 100 K/min
*
*  @return Error code
*/
int ATTOCUBE_API attoDry_sample_getHeaterAllZoneRampRates_attoDry_1_0_0(int deviceHandle, int* errorcode, double* rampRate);

static inline int ATTO_FUNCTION(attoDry_sample_getHeaterAllZoneRampRates)(int deviceHandle, int* errorcode, double* rampRate) {
    return attoDry_sample_getHeaterAllZoneRampRates_attoDry_1_0_0(deviceHandle, errorcode, rampRate);
}


/** @brief @attoDry_sample_getHeaterDefaultZoneSettings
*  Get sample heater zone settings
*
*  @param deviceHandle     Handle of device
*  @param zone             Zone number
*
*  @param errorcode        Error code
*  @param upperbound       Upper set point boundary of this zone in kelvin
*  @param P                P
*  @param I                I
*  @param D                D
*  @param manualOutput     Manual output for this zone 0 to 100%
*  @param heatingRange     Heating range see class HeaterRanges and Lake Shore 336 manual for ZONE command
*  @param rampRate         Ramp rate for this zone 0.1 100 K/min
*
*  @return Error code
*/
int ATTOCUBE_API attoDry_sample_getHeaterDefaultZoneSettings_attoDry_1_0_0(int deviceHandle, int zone, int* errorcode, double* upperbound, double* P, double* I, double* D, double* manualOutput, int* heatingRange, double* rampRate);

static inline int ATTO_FUNCTION(attoDry_sample_getHeaterDefaultZoneSettings)(int deviceHandle, int zone, int* errorcode, double* upperbound, double* P, double* I, double* D, double* manualOutput, int* heatingRange, double* rampRate) {
    return attoDry_sample_getHeaterDefaultZoneSettings_attoDry_1_0_0(deviceHandle, zone, errorcode, upperbound, P, I, D, manualOutput, heatingRange, rampRate);
}


/** @brief @attoDry_sample_getHeaterHeatingMode
*  Gets the sample heater heating mode
*
*  @param deviceHandle     Handle of device
*
*  @param mode             
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_getHeaterHeatingMode_attoDry_1_0_0(int deviceHandle, int* mode);

static inline int ATTO_FUNCTION(attoDry_sample_getHeaterHeatingMode)(int deviceHandle, int* mode) {
    return attoDry_sample_getHeaterHeatingMode_attoDry_1_0_0(deviceHandle, mode);
}


/** @brief @attoDry_sample_getHeaterNumberOfDefaultZones
*  Get the number of sample heater default zones
*
*  @param deviceHandle     Handle of device
*
*  @param errorcode        Error code
*  @param number_of_zones  
*
*  @return Error code
*/
int ATTOCUBE_API attoDry_sample_getHeaterNumberOfDefaultZones_attoDry_1_0_0(int deviceHandle, int* errorcode, int* number_of_zones);

static inline int ATTO_FUNCTION(attoDry_sample_getHeaterNumberOfDefaultZones)(int deviceHandle, int* errorcode, int* number_of_zones) {
    return attoDry_sample_getHeaterNumberOfDefaultZones_attoDry_1_0_0(deviceHandle, errorcode, number_of_zones);
}


/** @brief @attoDry_sample_getHeaterNumberOfZones
*  Get the number of the sample heater zones
*
*  @param deviceHandle     Handle of device
*
*  @param errorcode        Error code
*  @param number_of_zones  
*
*  @return Error code
*/
int ATTOCUBE_API attoDry_sample_getHeaterNumberOfZones_attoDry_1_0_0(int deviceHandle, int* errorcode, int* number_of_zones);

static inline int ATTO_FUNCTION(attoDry_sample_getHeaterNumberOfZones)(int deviceHandle, int* errorcode, int* number_of_zones) {
    return attoDry_sample_getHeaterNumberOfZones_attoDry_1_0_0(deviceHandle, errorcode, number_of_zones);
}


/** @brief @attoDry_sample_getHeaterPower
*  Gets the sample heater power
*
*  @param deviceHandle     Handle of device
*
*  @param power            
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_getHeaterPower_attoDry_1_0_0(int deviceHandle, double* power);

static inline int ATTO_FUNCTION(attoDry_sample_getHeaterPower)(int deviceHandle, double* power) {
    return attoDry_sample_getHeaterPower_attoDry_1_0_0(deviceHandle, power);
}


/** @brief @attoDry_sample_getHeaterRampData
*  Get sample heater ramp data
*
*  @param deviceHandle     Handle of device
*
*  @param errorcode        
*  @param OnOff            Ramp is on or off
*  @param Rate             Ramp rate in Kelvin / minute. 0.1 - 100. 0.0 means ramp limit is off.
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_getHeaterRampData_attoDry_1_0_0(int deviceHandle, int* errorcode, bool* OnOff, double* Rate);

static inline int ATTO_FUNCTION(attoDry_sample_getHeaterRampData)(int deviceHandle, int* errorcode, bool* OnOff, double* Rate) {
    return attoDry_sample_getHeaterRampData_attoDry_1_0_0(deviceHandle, errorcode, OnOff, Rate);
}


/** @brief @attoDry_sample_getHeaterRes
*  Gets the sample heater resistance
*
*  @param deviceHandle     Handle of device
*
*  @param resistance       
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_getHeaterRes_attoDry_1_0_0(int deviceHandle, double* resistance);

static inline int ATTO_FUNCTION(attoDry_sample_getHeaterRes)(int deviceHandle, double* resistance) {
    return attoDry_sample_getHeaterRes_attoDry_1_0_0(deviceHandle, resistance);
}


/** @brief @attoDry_sample_getHeaterStatus
*  Gets the sample heater status
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_getHeaterStatus_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_sample_getHeaterStatus)(int deviceHandle) {
    return attoDry_sample_getHeaterStatus_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_sample_getHeaterWireRes
*  Gets the sample heater wire resistance
*
*  @param deviceHandle     Handle of device
*
*  @param wire_resistance  
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_getHeaterWireRes_attoDry_1_0_0(int deviceHandle, double* wire_resistance);

static inline int ATTO_FUNCTION(attoDry_sample_getHeaterWireRes)(int deviceHandle, double* wire_resistance) {
    return attoDry_sample_getHeaterWireRes_attoDry_1_0_0(deviceHandle, wire_resistance);
}


/** @brief @attoDry_sample_getHeaterZoneSettings
*  Get sample heater zone settings
*
*  @param deviceHandle     Handle of device
*  @param zone             Zone number
*
*  @param errorcode        Error code
*  @param upperbound       Upper set point boundary of this zone in kelvin
*  @param P                P
*  @param I                I
*  @param D                D
*  @param manualOutput     Manual output for this zone 0 to 100%
*  @param heatingRange     Heating range see class HeaterRanges and Lake Shore 336 manual for ZONE command
*  @param rampRate         Ramp rate for this zone 0.1 100 K/min
*
*  @return Error code
*/
int ATTOCUBE_API attoDry_sample_getHeaterZoneSettings_attoDry_1_0_0(int deviceHandle, int zone, int* errorcode, double* upperbound, double* P, double* I, double* D, double* manualOutput, int* heatingRange, double* rampRate);

static inline int ATTO_FUNCTION(attoDry_sample_getHeaterZoneSettings)(int deviceHandle, int zone, int* errorcode, double* upperbound, double* P, double* I, double* D, double* manualOutput, int* heatingRange, double* rampRate) {
    return attoDry_sample_getHeaterZoneSettings_attoDry_1_0_0(deviceHandle, zone, errorcode, upperbound, P, I, D, manualOutput, heatingRange, rampRate);
}


/** @brief @attoDry_sample_getInputFilterSettings
*  Gets the sample input filter settings
*
*  @param deviceHandle     Handle of device
*
*  @param off_or_on        
*  @param point            
*  @param window           
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_getInputFilterSettings_attoDry_1_0_0(int deviceHandle, bool* off_or_on, int* point, int* window);

static inline int ATTO_FUNCTION(attoDry_sample_getInputFilterSettings)(int deviceHandle, bool* off_or_on, int* point, int* window) {
    return attoDry_sample_getInputFilterSettings_attoDry_1_0_0(deviceHandle, off_or_on, point, window);
}


/** @brief @attoDry_sample_getMaxPower
*  Gets the sample heater maximum power
*
*  @param deviceHandle     Handle of device
*
*  @param maxPower         
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_getMaxPower_attoDry_1_0_0(int deviceHandle, double* maxPower);

static inline int ATTO_FUNCTION(attoDry_sample_getMaxPower)(int deviceHandle, double* maxPower) {
    return attoDry_sample_getMaxPower_attoDry_1_0_0(deviceHandle, maxPower);
}


/** @brief @attoDry_sample_getPID
*  Gets the sample heater PID values
*
*  @param deviceHandle     Handle of device
*
*  @param proportional     
*  @param integral         
*  @param derivative       
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_getPID_attoDry_1_0_0(int deviceHandle, double* proportional, double* integral, double* derivative);

static inline int ATTO_FUNCTION(attoDry_sample_getPID)(int deviceHandle, double* proportional, double* integral, double* derivative) {
    return attoDry_sample_getPID_attoDry_1_0_0(deviceHandle, proportional, integral, derivative);
}


/** @brief @attoDry_sample_getRampControlStatus
*  Get the ramp control status
*
*  @param deviceHandle     Handle of device
*
*  @param errorcode        
*  @param OnOff            Ramp is on or off
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_getRampControlStatus_attoDry_1_0_0(int deviceHandle, int* errorcode, bool* OnOff);

static inline int ATTO_FUNCTION(attoDry_sample_getRampControlStatus)(int deviceHandle, int* errorcode, bool* OnOff) {
    return attoDry_sample_getRampControlStatus_attoDry_1_0_0(deviceHandle, errorcode, OnOff);
}


/** @brief @attoDry_sample_getRampRate
*  Get sample ramp rate
*
*  @param deviceHandle     Handle of device
*
*  @param errorcode        
*  @param Rate             Ramp rate in Kelvin / minute. 0.1 - 100. 0.0 means ramp limit is off.
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_getRampRate_attoDry_1_0_0(int deviceHandle, int* errorcode, double* Rate);

static inline int ATTO_FUNCTION(attoDry_sample_getRampRate)(int deviceHandle, int* errorcode, double* Rate) {
    return attoDry_sample_getRampRate_attoDry_1_0_0(deviceHandle, errorcode, Rate);
}


/** @brief @attoDry_sample_getResistance
*  Gets the sample resistance
*
*  @param deviceHandle     Handle of device
*
*  @param sample_resistance 
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_getResistance_attoDry_1_0_0(int deviceHandle, double* sample_resistance);

static inline int ATTO_FUNCTION(attoDry_sample_getResistance)(int deviceHandle, double* sample_resistance) {
    return attoDry_sample_getResistance_attoDry_1_0_0(deviceHandle, sample_resistance);
}


/** @brief @attoDry_sample_getSetPoint
*  Gets the sample set point
*
*  @param deviceHandle     Handle of device
*
*  @param set_point        
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_getSetPoint_attoDry_1_0_0(int deviceHandle, double* set_point);

static inline int ATTO_FUNCTION(attoDry_sample_getSetPoint)(int deviceHandle, double* set_point) {
    return attoDry_sample_getSetPoint_attoDry_1_0_0(deviceHandle, set_point);
}


/** @brief @attoDry_sample_getTempControlStatus
*  Gets the sample heater status
*
*  @param deviceHandle     Handle of device
*
*  @param status           
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_getTempControlStatus_attoDry_1_0_0(int deviceHandle, bool* status);

static inline int ATTO_FUNCTION(attoDry_sample_getTempControlStatus)(int deviceHandle, bool* status) {
    return attoDry_sample_getTempControlStatus_attoDry_1_0_0(deviceHandle, status);
}


/** @brief @attoDry_sample_getTemperature
*  Gets the sample temperature
*
*  @param deviceHandle     Handle of device
*
*  @param sample_temperature 
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_getTemperature_attoDry_1_0_0(int deviceHandle, double* sample_temperature);

static inline int ATTO_FUNCTION(attoDry_sample_getTemperature)(int deviceHandle, double* sample_temperature) {
    return attoDry_sample_getTemperature_attoDry_1_0_0(deviceHandle, sample_temperature);
}


/** @brief @attoDry_sample_heaterRampOff
*  Set sample heater ramp off
*
*  @param deviceHandle     Handle of device
*
*  @param errorcode        
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_heaterRampOff_attoDry_1_0_0(int deviceHandle, int* errorcode);

static inline int ATTO_FUNCTION(attoDry_sample_heaterRampOff)(int deviceHandle, int* errorcode) {
    return attoDry_sample_heaterRampOff_attoDry_1_0_0(deviceHandle, errorcode);
}


/** @brief @attoDry_sample_heaterRampOn
*  Set sample heater ramp on
*
*  @param deviceHandle     Handle of device
*  @param rate             Ramp rate in Kelvin / minute 0.1 - 100
*
*  @param errorcode        
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_heaterRampOn_attoDry_1_0_0(int deviceHandle, double rate, int* errorcode);

static inline int ATTO_FUNCTION(attoDry_sample_heaterRampOn)(int deviceHandle, double rate, int* errorcode) {
    return attoDry_sample_heaterRampOn_attoDry_1_0_0(deviceHandle, rate, errorcode);
}


/** @brief @attoDry_sample_setD
*  Sets the sample heater D value
*
*  @param deviceHandle     Handle of device
*  @param value            
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_setD_attoDry_1_0_0(int deviceHandle, double value);

static inline int ATTO_FUNCTION(attoDry_sample_setD)(int deviceHandle, double value) {
    return attoDry_sample_setD_attoDry_1_0_0(deviceHandle, value);
}


/** @brief @attoDry_sample_setHeaterAllZoneRampRates
*  Set sample heater all zones ramp rate
*
*  @param deviceHandle     Handle of device
*  @param rampRate         Ramp rate for this zone 0.1 100 K/min
*
*  @param errorcode        Error code
*
*  @return Error code
*/
int ATTOCUBE_API attoDry_sample_setHeaterAllZoneRampRates_attoDry_1_0_0(int deviceHandle, double rampRate, int* errorcode);

static inline int ATTO_FUNCTION(attoDry_sample_setHeaterAllZoneRampRates)(int deviceHandle, double rampRate, int* errorcode) {
    return attoDry_sample_setHeaterAllZoneRampRates_attoDry_1_0_0(deviceHandle, rampRate, errorcode);
}


/** @brief @attoDry_sample_setHeaterPower
*  Sets the sample heater power
*
*  @param deviceHandle     Handle of device
*  @param value            
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_setHeaterPower_attoDry_1_0_0(int deviceHandle, double value);

static inline int ATTO_FUNCTION(attoDry_sample_setHeaterPower)(int deviceHandle, double value) {
    return attoDry_sample_setHeaterPower_attoDry_1_0_0(deviceHandle, value);
}


/** @brief @attoDry_sample_setHeaterRes
*  Sets the sample heater resistance
*
*  @param deviceHandle     Handle of device
*  @param value            
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_setHeaterRes_attoDry_1_0_0(int deviceHandle, double value);

static inline int ATTO_FUNCTION(attoDry_sample_setHeaterRes)(int deviceHandle, double value) {
    return attoDry_sample_setHeaterRes_attoDry_1_0_0(deviceHandle, value);
}


/** @brief @attoDry_sample_setHeaterWireRes
*  Sets the sample heater wire resistance
*
*  @param deviceHandle     Handle of device
*  @param value            
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_setHeaterWireRes_attoDry_1_0_0(int deviceHandle, double value);

static inline int ATTO_FUNCTION(attoDry_sample_setHeaterWireRes)(int deviceHandle, double value) {
    return attoDry_sample_setHeaterWireRes_attoDry_1_0_0(deviceHandle, value);
}


/** @brief @attoDry_sample_setHeaterZoneSettings
*  Set sample heater zone settings
*
*  @param deviceHandle     Handle of device
*  @param zone             Zone number
*  @param upperbound       Upper set point boundary of this zone in kelvin
*  @param p_input          P
*  @param i_input          I
*  @param d_input          D
*  @param manualOutput     Manual output for this zone 0 to 100%
*  @param heatingRange     Heating range see class HeaterRanges and Lake Shore 336 manual for ZONE command
*
*  @param errorcode        Error code
*
*  @return Error code
*/
int ATTOCUBE_API attoDry_sample_setHeaterZoneSettings_attoDry_1_0_0(int deviceHandle, int zone, double upperbound, double p_input, double i_input, double d_input, double manualOutput, int heatingRange, int* errorcode);

static inline int ATTO_FUNCTION(attoDry_sample_setHeaterZoneSettings)(int deviceHandle, int zone, double upperbound, double p_input, double i_input, double d_input, double manualOutput, int heatingRange, int* errorcode) {
    return attoDry_sample_setHeaterZoneSettings_attoDry_1_0_0(deviceHandle, zone, upperbound, p_input, i_input, d_input, manualOutput, heatingRange, errorcode);
}


/** @brief @attoDry_sample_setI
*  Sets the sample heater I value
*
*  @param deviceHandle     Handle of device
*  @param value            
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_setI_attoDry_1_0_0(int deviceHandle, double value);

static inline int ATTO_FUNCTION(attoDry_sample_setI)(int deviceHandle, double value) {
    return attoDry_sample_setI_attoDry_1_0_0(deviceHandle, value);
}


/** @brief @attoDry_sample_setInputFilterSettings
*  Sets the sample input filter settings
*
*  @param deviceHandle     Handle of device
*  @param filterOn         
*  @param numberOfPoints   
*  @param windowSize       
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_setInputFilterSettings_attoDry_1_0_0(int deviceHandle, bool filterOn, int numberOfPoints, int windowSize);

static inline int ATTO_FUNCTION(attoDry_sample_setInputFilterSettings)(int deviceHandle, bool filterOn, int numberOfPoints, int windowSize) {
    return attoDry_sample_setInputFilterSettings_attoDry_1_0_0(deviceHandle, filterOn, numberOfPoints, windowSize);
}


/** @brief @attoDry_sample_setMaxPower
*  Sets the sample heater maximum power
*
*  @param deviceHandle     Handle of device
*  @param value            
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_setMaxPower_attoDry_1_0_0(int deviceHandle, double value);

static inline int ATTO_FUNCTION(attoDry_sample_setMaxPower)(int deviceHandle, double value) {
    return attoDry_sample_setMaxPower_attoDry_1_0_0(deviceHandle, value);
}


/** @brief @attoDry_sample_setP
*  Sets the sample heater P value
*
*  @param deviceHandle     Handle of device
*  @param value            
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_setP_attoDry_1_0_0(int deviceHandle, double value);

static inline int ATTO_FUNCTION(attoDry_sample_setP)(int deviceHandle, double value) {
    return attoDry_sample_setP_attoDry_1_0_0(deviceHandle, value);
}


/** @brief @attoDry_sample_setPID
*  Sets the sample heater PID values
*
*  @param deviceHandle     Handle of device
*  @param proportional     
*  @param integral         
*  @param derivative       
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_setPID_attoDry_1_0_0(int deviceHandle, double proportional, double integral, double derivative);

static inline int ATTO_FUNCTION(attoDry_sample_setPID)(int deviceHandle, double proportional, double integral, double derivative) {
    return attoDry_sample_setPID_attoDry_1_0_0(deviceHandle, proportional, integral, derivative);
}


/** @brief @attoDry_sample_setRampRate
*  Set sample ramp rate
*
*  @param deviceHandle     Handle of device
*  @param rate             Ramp rate in Kelvin / minute. 0.1 - 100. 0.0 means ramp limit is off.
*
*  @param errorcode        
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_setRampRate_attoDry_1_0_0(int deviceHandle, double rate, int* errorcode);

static inline int ATTO_FUNCTION(attoDry_sample_setRampRate)(int deviceHandle, double rate, int* errorcode) {
    return attoDry_sample_setRampRate_attoDry_1_0_0(deviceHandle, rate, errorcode);
}


/** @brief @attoDry_sample_setSetPoint
*  Sets the sample set point
*
*  @param deviceHandle     Handle of device
*  @param setPoint         
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_setSetPoint_attoDry_1_0_0(int deviceHandle, double setPoint);

static inline int ATTO_FUNCTION(attoDry_sample_setSetPoint)(int deviceHandle, double setPoint) {
    return attoDry_sample_setSetPoint_attoDry_1_0_0(deviceHandle, setPoint);
}


/** @brief @attoDry_sample_startHeaterOpenLoopPower
*  Starts the sample heater in open loop mode with the previously set power
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_startHeaterOpenLoopPower_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_sample_startHeaterOpenLoopPower)(int deviceHandle) {
    return attoDry_sample_startHeaterOpenLoopPower_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_sample_startHeaterZoneMode
*  Starts the sample heater in zone mode
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_startHeaterZoneMode_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_sample_startHeaterZoneMode)(int deviceHandle) {
    return attoDry_sample_startHeaterZoneMode_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_sample_startRampControl
*  Start controlling the ramping
*
*  @param deviceHandle     Handle of device
*
*  @param errorcode        
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_startRampControl_attoDry_1_0_0(int deviceHandle, int* errorcode);

static inline int ATTO_FUNCTION(attoDry_sample_startRampControl)(int deviceHandle, int* errorcode) {
    return attoDry_sample_startRampControl_attoDry_1_0_0(deviceHandle, errorcode);
}


/** @brief @attoDry_sample_startTempControl
*  Starts the sample heater
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_startTempControl_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_sample_startTempControl)(int deviceHandle) {
    return attoDry_sample_startTempControl_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_sample_stopRampControl
*  Stop controlling the ramping
*
*  @param deviceHandle     Handle of device
*
*  @param errorcode        
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_stopRampControl_attoDry_1_0_0(int deviceHandle, int* errorcode);

static inline int ATTO_FUNCTION(attoDry_sample_stopRampControl)(int deviceHandle, int* errorcode) {
    return attoDry_sample_stopRampControl_attoDry_1_0_0(deviceHandle, errorcode);
}


/** @brief @attoDry_sample_stopTempControl
*  Stops the sample heater
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_stopTempControl_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_sample_stopTempControl)(int deviceHandle) {
    return attoDry_sample_stopTempControl_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_sample_uploadCalibrationCurve
*  Sets the sample sensor calibration curve
*   may time out, but the upload will still work
*
*  @param deviceHandle     Handle of device
*  @param calibrationData  
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_uploadCalibrationCurve_attoDry_1_0_0(int deviceHandle, const char* calibrationData);

static inline int ATTO_FUNCTION(attoDry_sample_uploadCalibrationCurve)(int deviceHandle, const char* calibrationData) {
    return attoDry_sample_uploadCalibrationCurve_attoDry_1_0_0(deviceHandle, calibrationData);
}


/** @brief @attoDry_sample_uploadCalibrationCurve340
*  Sets the sample sensor .340 calibration curve
*   may time out, but the upload will still work
*
*  @param deviceHandle     Handle of device
*  @param calibrationData  
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_sample_uploadCalibrationCurve340_attoDry_1_0_0(int deviceHandle, const char* calibrationData);

static inline int ATTO_FUNCTION(attoDry_sample_uploadCalibrationCurve340)(int deviceHandle, const char* calibrationData) {
    return attoDry_sample_uploadCalibrationCurve340_attoDry_1_0_0(deviceHandle, calibrationData);
}


/** @brief @attoDry_system_emptyExternalDatabaseToMaximumBytes
*  Empty database! This solved issues when the UI is hanging! Don't use it otherwise
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_system_emptyExternalDatabaseToMaximumBytes_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_system_emptyExternalDatabaseToMaximumBytes)(int deviceHandle) {
    return attoDry_system_emptyExternalDatabaseToMaximumBytes_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_system_errorNumberToString
*  “Translate” the error code into an error text
*   Currently we only support the system language
*
*  @param deviceHandle     Handle of device
*  @param errorNumber      error code to translate
*
*  @param error            error message
*  @param size             Maximum size of buffer error
*
*  @return error message
*/
int ATTOCUBE_API attoDry_system_errorNumberToString_attoDry_1_0_0(int deviceHandle, int errorNumber, char* error, int size);

static inline int ATTO_FUNCTION(attoDry_system_errorNumberToString)(int deviceHandle, int errorNumber, char* error, int size) {
    return attoDry_system_errorNumberToString_attoDry_1_0_0(deviceHandle, errorNumber, error, size);
}


/** @brief @attoDry_system_getAutoprobeInformationJSONd
*  Get the hardware autoprobe information
*
*  @param deviceHandle     Handle of device
*
*  @param infoJson         JSONd autoprobe information
*  @param size             Maximum size of buffer infoJson
*
*  @return JSONd autoprobe information
*/
int ATTOCUBE_API attoDry_system_getAutoprobeInformationJSONd_attoDry_1_0_0(int deviceHandle, char* infoJson, int size);

static inline int ATTO_FUNCTION(attoDry_system_getAutoprobeInformationJSONd)(int deviceHandle, char* infoJson, int size) {
    return attoDry_system_getAutoprobeInformationJSONd_attoDry_1_0_0(deviceHandle, infoJson, size);
}


/** @brief @attoDry_system_getAvailableConfigurationSettings
*  Gets all available configuration settings
*
*  @param deviceHandle     Handle of device
*
*  @param Configuration_settings CSV of configuration settings
*  @param size             Maximum size of buffer Configuration_settings
*
*  @return CSV of configuration settings
*/
int ATTOCUBE_API attoDry_system_getAvailableConfigurationSettings_attoDry_1_0_0(int deviceHandle, char* Configuration_settings, int size);

static inline int ATTO_FUNCTION(attoDry_system_getAvailableConfigurationSettings)(int deviceHandle, char* Configuration_settings, int size) {
    return attoDry_system_getAvailableConfigurationSettings_attoDry_1_0_0(deviceHandle, Configuration_settings, size);
}


/** @brief @attoDry_system_getConfigOverrideFile
*  Get the EEPROM JSON file containing the config overrides.
*   To know what entries exist have a look at getAvailableConfigurationSettings()
*   and getConfigurationSettingInformation()
*
*  @param deviceHandle     Handle of device
*
*  @param overrideFile     String containing the override file
*  @param size             Maximum size of buffer overrideFile
*
*  @return String containing the override file
*/
int ATTOCUBE_API attoDry_system_getConfigOverrideFile_attoDry_1_0_0(int deviceHandle, char* overrideFile, int size);

static inline int ATTO_FUNCTION(attoDry_system_getConfigOverrideFile)(int deviceHandle, char* overrideFile, int size) {
    return attoDry_system_getConfigOverrideFile_attoDry_1_0_0(deviceHandle, overrideFile, size);
}


/** @brief @attoDry_system_getConfigurationConfiguration
*  Gets the configuration
*
*  @param deviceHandle     Handle of device
*  @param settingName      
*
*  @param Configuration_value 
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_system_getConfigurationConfiguration_attoDry_1_0_0(int deviceHandle, const char* settingName, double* Configuration_value);

static inline int ATTO_FUNCTION(attoDry_system_getConfigurationConfiguration)(int deviceHandle, const char* settingName, double* Configuration_value) {
    return attoDry_system_getConfigurationConfiguration_attoDry_1_0_0(deviceHandle, settingName, Configuration_value);
}


/** @brief @attoDry_system_getConfigurationSetting
*  Get the value of the specified configuration setting
*
*  @param deviceHandle     Handle of device
*  @param settingName      
*
*  @param Configuration_setting_value 
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_system_getConfigurationSetting_attoDry_1_0_0(int deviceHandle, const char* settingName, double* Configuration_setting_value);

static inline int ATTO_FUNCTION(attoDry_system_getConfigurationSetting)(int deviceHandle, const char* settingName, double* Configuration_setting_value) {
    return attoDry_system_getConfigurationSetting_attoDry_1_0_0(deviceHandle, settingName, Configuration_setting_value);
}


/** @brief @attoDry_system_getConfigurationSettingInformation
*  Gets the configuration setting info string
*
*  @param deviceHandle     Handle of device
*  @param settingName      
*
*  @param Configuration_settings_information 
*  @param size             Maximum size of buffer Configuration_settings_information
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_system_getConfigurationSettingInformation_attoDry_1_0_0(int deviceHandle, const char* settingName, char* Configuration_settings_information, int size);

static inline int ATTO_FUNCTION(attoDry_system_getConfigurationSettingInformation)(int deviceHandle, const char* settingName, char* Configuration_settings_information, int size) {
    return attoDry_system_getConfigurationSettingInformation_attoDry_1_0_0(deviceHandle, settingName, Configuration_settings_information, size);
}


/** @brief @attoDry_system_getCurrentStatusJSONd
*  Get the current cryostat status
*
*  @param deviceHandle     Handle of device
*
*  @param status           Cryostat status
*  @param size             Maximum size of buffer status
*
*  @return Cryostat status
*/
int ATTOCUBE_API attoDry_system_getCurrentStatusJSONd_attoDry_1_0_0(int deviceHandle, char* status, int size);

static inline int ATTO_FUNCTION(attoDry_system_getCurrentStatusJSONd)(int deviceHandle, char* status, int size) {
    return attoDry_system_getCurrentStatusJSONd_attoDry_1_0_0(deviceHandle, status, size);
}


/** @brief @attoDry_system_getDatabaseAsyncQueryResult
*  Get the query result
*
*  @param deviceHandle     Handle of device
*  @param handle           
*
*  @param result           
*  @param size             Maximum size of buffer result
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_system_getDatabaseAsyncQueryResult_attoDry_1_0_0(int deviceHandle, int handle, char* result, int size);

static inline int ATTO_FUNCTION(attoDry_system_getDatabaseAsyncQueryResult)(int deviceHandle, int handle, char* result, int size) {
    return attoDry_system_getDatabaseAsyncQueryResult_attoDry_1_0_0(deviceHandle, handle, result, size);
}


/** @brief @attoDry_system_getDatabaseColumnsMinMaxIntervalRows
*  Get the cryostat database columns
*
*  @param deviceHandle     Handle of device
*  @param minRow           
*  @param maxRow           
*  @param columnNames      Empty string means all available columns
*
*  @param result_rows      
*  @param size             Maximum size of buffer result_rows
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_system_getDatabaseColumnsMinMaxIntervalRows_attoDry_1_0_0(int deviceHandle, int minRow, int maxRow, const char* columnNames, char* result_rows, int size);

static inline int ATTO_FUNCTION(attoDry_system_getDatabaseColumnsMinMaxIntervalRows)(int deviceHandle, int minRow, int maxRow, const char* columnNames, char* result_rows, int size) {
    return attoDry_system_getDatabaseColumnsMinMaxIntervalRows_attoDry_1_0_0(deviceHandle, minRow, maxRow, columnNames, result_rows, size);
}


/** @brief @attoDry_system_getDatabaseMaximumLogSeconds
*  Get the cryostat long term status of a time interval
*
*  @param deviceHandle     Handle of device
*
*  @param maximumSecondsInLog 
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_system_getDatabaseMaximumLogSeconds_attoDry_1_0_0(int deviceHandle, double* maximumSecondsInLog);

static inline int ATTO_FUNCTION(attoDry_system_getDatabaseMaximumLogSeconds)(int deviceHandle, double* maximumSecondsInLog) {
    return attoDry_system_getDatabaseMaximumLogSeconds_attoDry_1_0_0(deviceHandle, maximumSecondsInLog);
}


/** @brief @attoDry_system_getDatabaseMinMaxResult
*  Get the min and max rows.
*
*  @param deviceHandle     Handle of device
*  @param handle           
*
*  @param min_row          
*  @param max_row          
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_system_getDatabaseMinMaxResult_attoDry_1_0_0(int deviceHandle, int handle, int* min_row, int* max_row);

static inline int ATTO_FUNCTION(attoDry_system_getDatabaseMinMaxResult)(int deviceHandle, int handle, int* min_row, int* max_row) {
    return attoDry_system_getDatabaseMinMaxResult_attoDry_1_0_0(deviceHandle, handle, min_row, max_row);
}


/** @brief @attoDry_system_getDatabaseMinimumLogSeconds
*  Get the cryostat long term status of a time interval
*
*  @param deviceHandle     Handle of device
*
*  @param minimumSecondsInLog 
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_system_getDatabaseMinimumLogSeconds_attoDry_1_0_0(int deviceHandle, double* minimumSecondsInLog);

static inline int ATTO_FUNCTION(attoDry_system_getDatabaseMinimumLogSeconds)(int deviceHandle, double* minimumSecondsInLog) {
    return attoDry_system_getDatabaseMinimumLogSeconds_attoDry_1_0_0(deviceHandle, minimumSecondsInLog);
}


/** @brief @attoDry_system_getDeviceType
*  Gets the device type.
*
*  @param deviceHandle     Handle of device
*
*  @param type             type of the device
*  @param size             Maximum size of buffer type
*
*  @return type of the device
*/
int ATTOCUBE_API attoDry_system_getDeviceType_attoDry_1_0_0(int deviceHandle, char* type, int size);

static inline int ATTO_FUNCTION(attoDry_system_getDeviceType)(int deviceHandle, char* type, int size) {
    return attoDry_system_getDeviceType_attoDry_1_0_0(deviceHandle, type, size);
}


/** @brief @attoDry_system_getFeatures
*  Get the features of the cryostat.
*
*  @param deviceHandle     Handle of device
*
*  @param Feature_names    
*  @param size1            Maximum size of buffer Feature_names
*  @param Feature_descriptrions 
*  @param size2            Maximum size of buffer Feature_descriptrions
*  @param Feature_short_descriptrions 
*  @param size3            Maximum size of buffer Feature_short_descriptrions
*  @param Feature_display_names 
*  @param size4            Maximum size of buffer Feature_display_names
*  @param Feature_picture  
*  @param size5            Maximum size of buffer Feature_picture
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_system_getFeatures_attoDry_1_0_0(int deviceHandle, char* Feature_names, int size1, char* Feature_descriptrions, int size2, char* Feature_short_descriptrions, int size3, char* Feature_display_names, int size4, char* Feature_picture, int size5);

static inline int ATTO_FUNCTION(attoDry_system_getFeatures)(int deviceHandle, char* Feature_names, int size1, char* Feature_descriptrions, int size2, char* Feature_short_descriptrions, int size3, char* Feature_display_names, int size4, char* Feature_picture, int size5) {
    return attoDry_system_getFeatures_attoDry_1_0_0(deviceHandle, Feature_names, size1, Feature_descriptrions, size2, Feature_short_descriptrions, size3, Feature_display_names, size4, Feature_picture, size5);
}


/** @brief @attoDry_system_getFeaturesActivated
*  Get the active features of the cryostat.
*
*  @param deviceHandle     Handle of device
*
*  @param localErrorNumber No error = 0
*  @param Feature_names    
*  @param size             Maximum size of buffer Feature_names
*
*  @return No error = 0
*/
int ATTOCUBE_API attoDry_system_getFeaturesActivated_attoDry_1_0_0(int deviceHandle, int* localErrorNumber, char* Feature_names, int size);

static inline int ATTO_FUNCTION(attoDry_system_getFeaturesActivated)(int deviceHandle, int* localErrorNumber, char* Feature_names, int size) {
    return attoDry_system_getFeaturesActivated_attoDry_1_0_0(deviceHandle, localErrorNumber, Feature_names, size);
}


/** @brief @attoDry_system_getFeaturesJSON
*  Get the features of the cryostat as a JSON string.
*
*  @param deviceHandle     Handle of device
*
*  @param localErrorNumber No error = 0
*  @param JSON             
*  @param size             Maximum size of buffer JSON
*
*  @return No error = 0
*/
int ATTOCUBE_API attoDry_system_getFeaturesJSON_attoDry_1_0_0(int deviceHandle, int* localErrorNumber, char* JSON, int size);

static inline int ATTO_FUNCTION(attoDry_system_getFeaturesJSON)(int deviceHandle, int* localErrorNumber, char* JSON, int size) {
    return attoDry_system_getFeaturesJSON_attoDry_1_0_0(deviceHandle, localErrorNumber, JSON, size);
}


/** @brief @attoDry_system_getIntervalLongTermEntriesJSONd
*  Get the cryostat long term status of a time interval
*
*  @param deviceHandle     Handle of device
*  @param secondsOld       
*  @param secondsNew       
*
*  @param intervalJson     JSONd description of cryo status in time interval
*  @param size             Maximum size of buffer intervalJson
*
*  @return JSONd description of cryo status in time interval
*/
int ATTOCUBE_API attoDry_system_getIntervalLongTermEntriesJSONd_attoDry_1_0_0(int deviceHandle, double secondsOld, double secondsNew, char* intervalJson, int size);

static inline int ATTO_FUNCTION(attoDry_system_getIntervalLongTermEntriesJSONd)(int deviceHandle, double secondsOld, double secondsNew, char* intervalJson, int size) {
    return attoDry_system_getIntervalLongTermEntriesJSONd_attoDry_1_0_0(deviceHandle, secondsOld, secondsNew, intervalJson, size);
}


/** @brief @attoDry_system_getIntervalShortTermEntriesJSONd
*  Get the cryostat status of a time interval
*
*  @param deviceHandle     Handle of device
*  @param secondsOld       
*  @param secondsNew       
*
*  @param Short_term_log_entries 
*  @param size             Maximum size of buffer Short_term_log_entries
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_system_getIntervalShortTermEntriesJSONd_attoDry_1_0_0(int deviceHandle, double secondsOld, double secondsNew, char* Short_term_log_entries, int size);

static inline int ATTO_FUNCTION(attoDry_system_getIntervalShortTermEntriesJSONd)(int deviceHandle, double secondsOld, double secondsNew, char* Short_term_log_entries, int size) {
    return attoDry_system_getIntervalShortTermEntriesJSONd_attoDry_1_0_0(deviceHandle, secondsOld, secondsNew, Short_term_log_entries, size);
}


/** @brief @attoDry_system_getLastError
*  Gets all available information on the last error
*
*  @param deviceHandle     Handle of device
*
*  @param lastErrorNumber  Last error number
*  @param recommendation   Recommendation
*  @param size1            Maximum size of buffer recommendation
*  @param component        Component that raised the error
*  @param size2            Maximum size of buffer component
*  @param command          Command
*  @param size3            Maximum size of buffer command
*  @param age              Age
*
*  @return Last error number
*/
int ATTOCUBE_API attoDry_system_getLastError_attoDry_1_0_0(int deviceHandle, int* lastErrorNumber, char* recommendation, int size1, char* component, int size2, char* command, int size3, int* age);

static inline int ATTO_FUNCTION(attoDry_system_getLastError)(int deviceHandle, int* lastErrorNumber, char* recommendation, int size1, char* component, int size2, char* command, int size3, int* age) {
    return attoDry_system_getLastError_attoDry_1_0_0(deviceHandle, lastErrorNumber, recommendation, size1, component, size2, command, size3, age);
}


/** @brief @attoDry_system_getLastErrorAge
*  Gets the age of the last error that happened
*
*  @param deviceHandle     Handle of device
*
*  @param age              time in seconds since the last error happened
*
*  @return time in seconds since the last error happened
*/
int ATTOCUBE_API attoDry_system_getLastErrorAge_attoDry_1_0_0(int deviceHandle, int* age);

static inline int ATTO_FUNCTION(attoDry_system_getLastErrorAge)(int deviceHandle, int* age) {
    return attoDry_system_getLastErrorAge_attoDry_1_0_0(deviceHandle, age);
}


/** @brief @attoDry_system_getLastErrorCommand
*  Gets the command of the last error that happened
*
*  @param deviceHandle     Handle of device
*
*  @param command          command running when the last error happened
*  @param size             Maximum size of buffer command
*
*  @return command running when the last error happened
*/
int ATTOCUBE_API attoDry_system_getLastErrorCommand_attoDry_1_0_0(int deviceHandle, char* command, int size);

static inline int ATTO_FUNCTION(attoDry_system_getLastErrorCommand)(int deviceHandle, char* command, int size) {
    return attoDry_system_getLastErrorCommand_attoDry_1_0_0(deviceHandle, command, size);
}


/** @brief @attoDry_system_getLastErrorComponent
*  Gets the component of the last error that happened
*
*  @param deviceHandle     Handle of device
*
*  @param component        cryostat component of the error
*  @param size             Maximum size of buffer component
*
*  @return cryostat component of the error
*/
int ATTOCUBE_API attoDry_system_getLastErrorComponent_attoDry_1_0_0(int deviceHandle, char* component, int size);

static inline int ATTO_FUNCTION(attoDry_system_getLastErrorComponent)(int deviceHandle, char* component, int size) {
    return attoDry_system_getLastErrorComponent_attoDry_1_0_0(deviceHandle, component, size);
}


/** @brief @attoDry_system_getLastErrorNumber
*  Gets the error number of the last error that happened
*
*  @param deviceHandle     Handle of device
*
*  @param localErrorNumber No error = 0
*
*  @return No error = 0
*/
int ATTOCUBE_API attoDry_system_getLastErrorNumber_attoDry_1_0_0(int deviceHandle, int* localErrorNumber);

static inline int ATTO_FUNCTION(attoDry_system_getLastErrorNumber)(int deviceHandle, int* localErrorNumber) {
    return attoDry_system_getLastErrorNumber_attoDry_1_0_0(deviceHandle, localErrorNumber);
}


/** @brief @attoDry_system_getLastErrorRecommendation
*  Gets the recommendation of the last error that happened
*
*  @param deviceHandle     Handle of device
*
*  @param recommendation   error recommendation
*  @param size             Maximum size of buffer recommendation
*
*  @return error recommendation
*/
int ATTOCUBE_API attoDry_system_getLastErrorRecommendation_attoDry_1_0_0(int deviceHandle, char* recommendation, int size);

static inline int ATTO_FUNCTION(attoDry_system_getLastErrorRecommendation)(int deviceHandle, char* recommendation, int size) {
    return attoDry_system_getLastErrorRecommendation_attoDry_1_0_0(deviceHandle, recommendation, size);
}


/** @brief @attoDry_system_getLastErrorsJSONd
*  Gets the last cryostat errors as a JSON string.
*
*  @param deviceHandle     Handle of device
*
*  @param localErrorNumber No error = 0
*  @param JSON             
*  @param size             Maximum size of buffer JSON
*
*  @return No error = 0
*/
int ATTOCUBE_API attoDry_system_getLastErrorsJSONd_attoDry_1_0_0(int deviceHandle, int* localErrorNumber, char* JSON, int size);

static inline int ATTO_FUNCTION(attoDry_system_getLastErrorsJSONd)(int deviceHandle, int* localErrorNumber, char* JSON, int size) {
    return attoDry_system_getLastErrorsJSONd_attoDry_1_0_0(deviceHandle, localErrorNumber, JSON, size);
}


/** @brief @attoDry_system_getLastErrorsPickled
*  Gets the last cryostat errors from the snapshot.
*   Use getLastErrorsAsJSON() and unJSON the data if this call doesn't work for you
*   (the cryostat data can't be unpickled)
*
*  @param deviceHandle     Handle of device
*  @param pythonVersion    
*
*  @param localErrorNumber No error = 0
*  @param Pickled_data     
*  @param size             Maximum size of buffer Pickled_data
*
*  @return No error = 0
*/
int ATTOCUBE_API attoDry_system_getLastErrorsPickled_attoDry_1_0_0(int deviceHandle, int pythonVersion, int* localErrorNumber, char* Pickled_data, int size);

static inline int ATTO_FUNCTION(attoDry_system_getLastErrorsPickled)(int deviceHandle, int pythonVersion, int* localErrorNumber, char* Pickled_data, int size) {
    return attoDry_system_getLastErrorsPickled_attoDry_1_0_0(deviceHandle, pythonVersion, localErrorNumber, Pickled_data, size);
}


/** @brief @attoDry_system_getLastLongTermEntriesJSONd
*  Get the cryostat long term status of the last seconds
*
*  @param deviceHandle     Handle of device
*  @param seconds          
*
*  @param version          firmware version number
*  @param size             Maximum size of buffer version
*
*  @return firmware version number
*/
int ATTOCUBE_API attoDry_system_getLastLongTermEntriesJSONd_attoDry_1_0_0(int deviceHandle, double seconds, char* version, int size);

static inline int ATTO_FUNCTION(attoDry_system_getLastLongTermEntriesJSONd)(int deviceHandle, double seconds, char* version, int size) {
    return attoDry_system_getLastLongTermEntriesJSONd_attoDry_1_0_0(deviceHandle, seconds, version, size);
}


/** @brief @attoDry_system_getLastShortTermEntriesJSONd
*  Get the cryostat status of the last seconds
*
*  @param deviceHandle     Handle of device
*  @param seconds          
*
*  @param version          firmware version number
*  @param size             Maximum size of buffer version
*
*  @return firmware version number
*/
int ATTOCUBE_API attoDry_system_getLastShortTermEntriesJSONd_attoDry_1_0_0(int deviceHandle, double seconds, char* version, int size);

static inline int ATTO_FUNCTION(attoDry_system_getLastShortTermEntriesJSONd)(int deviceHandle, double seconds, char* version, int size) {
    return attoDry_system_getLastShortTermEntriesJSONd_attoDry_1_0_0(deviceHandle, seconds, version, size);
}


/** @brief @attoDry_system_getLogLines
*  Get the last lines of the system logfile.
*
*  @param deviceHandle     Handle of device
*  @param maxBytes         maximum bytes to read
*
*  @param logLines         String containing the logfile lines
*  @param size             Maximum size of buffer logLines
*
*  @return String containing the logfile lines
*/
int ATTOCUBE_API attoDry_system_getLogLines_attoDry_1_0_0(int deviceHandle, int maxBytes, char* logLines, int size);

static inline int ATTO_FUNCTION(attoDry_system_getLogLines)(int deviceHandle, int maxBytes, char* logLines, int size) {
    return attoDry_system_getLogLines_attoDry_1_0_0(deviceHandle, maxBytes, logLines, size);
}


/** @brief @attoDry_system_getSecondsFromStartCryostatInstallation
*  Gets the seconds from start of cryostat installation
*
*  @param deviceHandle     Handle of device
*
*  @param seconds          Seconds from start of cryostat installation
*
*  @return Seconds from start of cryostat installation
*/
int ATTOCUBE_API attoDry_system_getSecondsFromStartCryostatInstallation_attoDry_1_0_0(int deviceHandle, double* seconds);

static inline int ATTO_FUNCTION(attoDry_system_getSecondsFromStartCryostatInstallation)(int deviceHandle, double* seconds) {
    return attoDry_system_getSecondsFromStartCryostatInstallation_attoDry_1_0_0(deviceHandle, seconds);
}


/** @brief @attoDry_system_getUserConfigOverrideFile
*  Get the user JSON file containing the config overrides.
*   To know what entries exist have a look at getAvailableConfigurationSettings()
*    and getConfigurationSettingInformation()
*
*  @param deviceHandle     Handle of device
*
*  @param overrideFile     String containing the override file
*  @param size             Maximum size of buffer overrideFile
*
*  @return String containing the override file
*/
int ATTOCUBE_API attoDry_system_getUserConfigOverrideFile_attoDry_1_0_0(int deviceHandle, char* overrideFile, int size);

static inline int ATTO_FUNCTION(attoDry_system_getUserConfigOverrideFile)(int deviceHandle, char* overrideFile, int size) {
    return attoDry_system_getUserConfigOverrideFile_attoDry_1_0_0(deviceHandle, overrideFile, size);
}


/** @brief @attoDry_system_lowerError
*  Resets the last error
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_system_lowerError_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_system_lowerError)(int deviceHandle) {
    return attoDry_system_lowerError_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_system_prepareDatabaseColumnsIntervalAsync
*  Prepare the cryostat long term status of a time interval query
*
*  @param deviceHandle     Handle of device
*  @param minRow           
*  @param maxRow           
*  @param columnNames      Empty string means all available columns
*  @param handle           
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_system_prepareDatabaseColumnsIntervalAsync_attoDry_1_0_0(int deviceHandle, int minRow, int maxRow, const char* columnNames, int handle);

static inline int ATTO_FUNCTION(attoDry_system_prepareDatabaseColumnsIntervalAsync)(int deviceHandle, int minRow, int maxRow, const char* columnNames, int handle) {
    return attoDry_system_prepareDatabaseColumnsIntervalAsync_attoDry_1_0_0(deviceHandle, minRow, maxRow, columnNames, handle);
}


/** @brief @attoDry_system_prepareDatabaseMinMaxInterval
*  Prepare the cryostat long term status of a time interval query
*   Get the row numbers with getDatabaseMinMaxResult()
*   Get the data with getDatabaseColumnsMinMaxIntervalRows()
*   minTime and maxTime can be taken from getDatabaseMinimumLogSeconds()  and getDatabaseMaximumLogSeconds()
*
*  @param deviceHandle     Handle of device
*  @param minTime          
*  @param maxTime          
*
*  @param handle           
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_system_prepareDatabaseMinMaxInterval_attoDry_1_0_0(int deviceHandle, double minTime, double maxTime, int* handle);

static inline int ATTO_FUNCTION(attoDry_system_prepareDatabaseMinMaxInterval)(int deviceHandle, double minTime, double maxTime, int* handle) {
    return attoDry_system_prepareDatabaseMinMaxInterval_attoDry_1_0_0(deviceHandle, minTime, maxTime, handle);
}


/** @brief @attoDry_system_resetUserConfigOverrideFile
*  Copy the EEPROM config factory defaults to the user config
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_system_resetUserConfigOverrideFile_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(attoDry_system_resetUserConfigOverrideFile)(int deviceHandle) {
    return attoDry_system_resetUserConfigOverrideFile_attoDry_1_0_0(deviceHandle);
}


/** @brief @attoDry_system_setConfigurationSetting
*  Sets the configuration setting
*
*  @param deviceHandle     Handle of device
*  @param settingName      
*  @param settingValue     
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_system_setConfigurationSetting_attoDry_1_0_0(int deviceHandle, const char* settingName, double settingValue);

static inline int ATTO_FUNCTION(attoDry_system_setConfigurationSetting)(int deviceHandle, const char* settingName, double settingValue) {
    return attoDry_system_setConfigurationSetting_attoDry_1_0_0(deviceHandle, settingName, settingValue);
}


/** @brief @attoDry_system_setUserConfigOverrideFile
*  Set the user JSON file containing the config overrides.
*   To know what entries exist have a look at getAvailableConfigurationSettings()
*    and getConfigurationSettingInformation()
*
*  @param deviceHandle     Handle of device
*  @param fileContent      Contents of the config override file
*
*  @param hint_string      Free text string to give the caller some hints if things don't work
*  @param size             Maximum size of buffer hint_string
*
*  @return Free text string to give the caller some hints if things don't work
*/
int ATTOCUBE_API attoDry_system_setUserConfigOverrideFile_attoDry_1_0_0(int deviceHandle, const char* fileContent, char* hint_string, int size);

static inline int ATTO_FUNCTION(attoDry_system_setUserConfigOverrideFile)(int deviceHandle, const char* fileContent, char* hint_string, int size) {
    return attoDry_system_setUserConfigOverrideFile_attoDry_1_0_0(deviceHandle, fileContent, hint_string, size);
}


/** @brief @attoDry_tboard_autotunePIDError
*  Gets last autotune error
*
*  @param deviceHandle     Handle of device
*
*  @param Autotune_errorcode 
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_autotunePIDError_attoDry_1_0_0(int deviceHandle, int* Autotune_errorcode);

static inline int ATTO_FUNCTION(attoDry_tboard_autotunePIDError)(int deviceHandle, int* Autotune_errorcode) {
    return attoDry_tboard_autotunePIDError_attoDry_1_0_0(deviceHandle, Autotune_errorcode);
}


/** @brief @attoDry_tboard_autotunePIDRunning
*  Check whether PID autotune is currently running
*
*  @param deviceHandle     Handle of device
*
*  @param running          
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_autotunePIDRunning_attoDry_1_0_0(int deviceHandle, bool* running);

static inline int ATTO_FUNCTION(attoDry_tboard_autotunePIDRunning)(int deviceHandle, bool* running) {
    return attoDry_tboard_autotunePIDRunning_attoDry_1_0_0(deviceHandle, running);
}


/** @brief @attoDry_tboard_autotunePIDStage
*  Gets last autotune stage
*
*  @param deviceHandle     Handle of device
*
*  @param Autotune_errorcode 
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_autotunePIDStage_attoDry_1_0_0(int deviceHandle, int* Autotune_errorcode);

static inline int ATTO_FUNCTION(attoDry_tboard_autotunePIDStage)(int deviceHandle, int* Autotune_errorcode) {
    return attoDry_tboard_autotunePIDStage_attoDry_1_0_0(deviceHandle, Autotune_errorcode);
}


/** @brief @attoDry_tboard_downloadCalibrationCurve
*  Gets the sensor calibration curve
*
*  @param deviceHandle     Handle of device
*  @param channel          
*
*  @param calibration_data 
*  @param size             Maximum size of buffer calibration_data
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_downloadCalibrationCurve_attoDry_1_0_0(int deviceHandle, int channel, char* calibration_data, int size);

static inline int ATTO_FUNCTION(attoDry_tboard_downloadCalibrationCurve)(int deviceHandle, int channel, char* calibration_data, int size) {
    return attoDry_tboard_downloadCalibrationCurve_attoDry_1_0_0(deviceHandle, channel, calibration_data, size);
}


/** @brief @attoDry_tboard_downloadCalibrationCurve340
*  Gets the sensor .340 calibration curve
*
*  @param deviceHandle     Handle of device
*  @param channel          
*
*  @param calibration_data 
*  @param size             Maximum size of buffer calibration_data
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_downloadCalibrationCurve340_attoDry_1_0_0(int deviceHandle, int channel, char* calibration_data, int size);

static inline int ATTO_FUNCTION(attoDry_tboard_downloadCalibrationCurve340)(int deviceHandle, int channel, char* calibration_data, int size) {
    return attoDry_tboard_downloadCalibrationCurve340_attoDry_1_0_0(deviceHandle, channel, calibration_data, size);
}


/** @brief @attoDry_tboard_getHeaterPIDChannel
*  Start heating in zone mode
*
*  @param deviceHandle     Handle of device
*  @param channelNumber    
*
*  @param p_output         
*  @param i_output         
*  @param d_output         
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_getHeaterPIDChannel_attoDry_1_0_0(int deviceHandle, int channelNumber, double* p_output, double* i_output, double* d_output);

static inline int ATTO_FUNCTION(attoDry_tboard_getHeaterPIDChannel)(int deviceHandle, int channelNumber, double* p_output, double* i_output, double* d_output) {
    return attoDry_tboard_getHeaterPIDChannel_attoDry_1_0_0(deviceHandle, channelNumber, p_output, i_output, d_output);
}


/** @brief @attoDry_tboard_getHeaterSetpointChannel
*  Start heating in zone mode
*
*  @param deviceHandle     Handle of device
*  @param channelNumber    
*
*  @param set_point        
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_getHeaterSetpointChannel_attoDry_1_0_0(int deviceHandle, int channelNumber, double* set_point);

static inline int ATTO_FUNCTION(attoDry_tboard_getHeaterSetpointChannel)(int deviceHandle, int channelNumber, double* set_point) {
    return attoDry_tboard_getHeaterSetpointChannel_attoDry_1_0_0(deviceHandle, channelNumber, set_point);
}


/** @brief @attoDry_tboard_getHeaterZoneSettingsChannel
*  Get heater zone settings channel
*
*  @param deviceHandle     Handle of device
*  @param channelNumber    
*
*  @param upperbound       Upper temperature bound of zone
*  @param p_output         
*  @param i_output         
*  @param d_output         
*  @param manualOutput     
*  @param heatingRange     0 -> off, 1 -> attocube OEM on, 1 -> 335, 336 Low, , 2 -> 335, 336 Medium, , 3 -> 335, 336 High
*  @param rampRate         
*
*  @return Upper temperature bound of zone
*/
int ATTOCUBE_API attoDry_tboard_getHeaterZoneSettingsChannel_attoDry_1_0_0(int deviceHandle, int channelNumber, double* upperbound, double* p_output, double* i_output, double* d_output, double* manualOutput, int* heatingRange, double* rampRate);

static inline int ATTO_FUNCTION(attoDry_tboard_getHeaterZoneSettingsChannel)(int deviceHandle, int channelNumber, double* upperbound, double* p_output, double* i_output, double* d_output, double* manualOutput, int* heatingRange, double* rampRate) {
    return attoDry_tboard_getHeaterZoneSettingsChannel_attoDry_1_0_0(deviceHandle, channelNumber, upperbound, p_output, i_output, d_output, manualOutput, heatingRange, rampRate);
}


/** @brief @attoDry_tboard_getRawSensorInput
*  Get raw sensor input.
*
*  @param deviceHandle     Handle of device
*  @param channelNumber    
*
*  @param Raw_sensor_input 
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_getRawSensorInput_attoDry_1_0_0(int deviceHandle, int channelNumber, double* Raw_sensor_input);

static inline int ATTO_FUNCTION(attoDry_tboard_getRawSensorInput)(int deviceHandle, int channelNumber, double* Raw_sensor_input) {
    return attoDry_tboard_getRawSensorInput_attoDry_1_0_0(deviceHandle, channelNumber, Raw_sensor_input);
}


/** @brief @attoDry_tboard_getResistance
*  Get resistance.
*
*  @param deviceHandle     Handle of device
*  @param channelNumber    
*
*  @param Resistance       
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_getResistance_attoDry_1_0_0(int deviceHandle, int channelNumber, double* Resistance);

static inline int ATTO_FUNCTION(attoDry_tboard_getResistance)(int deviceHandle, int channelNumber, double* Resistance) {
    return attoDry_tboard_getResistance_attoDry_1_0_0(deviceHandle, channelNumber, Resistance);
}


/** @brief @attoDry_tboard_getTemperature
*  Get temperature.
*
*  @param deviceHandle     Handle of device
*  @param channelNumber    
*
*  @param Temperature      
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_getTemperature_attoDry_1_0_0(int deviceHandle, int channelNumber, double* Temperature);

static inline int ATTO_FUNCTION(attoDry_tboard_getTemperature)(int deviceHandle, int channelNumber, double* Temperature) {
    return attoDry_tboard_getTemperature_attoDry_1_0_0(deviceHandle, channelNumber, Temperature);
}


/** @brief @attoDry_tboard_isHeatingChannel
*  Start heating in zone mode
*
*  @param deviceHandle     Handle of device
*  @param channelNumber    
*
*  @param isHeating        
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_isHeatingChannel_attoDry_1_0_0(int deviceHandle, int channelNumber, bool* isHeating);

static inline int ATTO_FUNCTION(attoDry_tboard_isHeatingChannel)(int deviceHandle, int channelNumber, bool* isHeating) {
    return attoDry_tboard_isHeatingChannel_attoDry_1_0_0(deviceHandle, channelNumber, isHeating);
}


/** @brief @attoDry_tboard_setHeaterPIDChannel
*  Start heating in zone mode
*
*  @param deviceHandle     Handle of device
*  @param channelNumber    
*  @param p_input          
*  @param i_input          
*  @param d_input          
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_setHeaterPIDChannel_attoDry_1_0_0(int deviceHandle, int channelNumber, double p_input, double i_input, double d_input);

static inline int ATTO_FUNCTION(attoDry_tboard_setHeaterPIDChannel)(int deviceHandle, int channelNumber, double p_input, double i_input, double d_input) {
    return attoDry_tboard_setHeaterPIDChannel_attoDry_1_0_0(deviceHandle, channelNumber, p_input, i_input, d_input);
}


/** @brief @attoDry_tboard_setHeaterSetpointChannel
*  Start heating in zone mode
*
*  @param deviceHandle     Handle of device
*  @param channelNumber    
*  @param setpoint         Temperature set point
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_setHeaterSetpointChannel_attoDry_1_0_0(int deviceHandle, int channelNumber, double setpoint);

static inline int ATTO_FUNCTION(attoDry_tboard_setHeaterSetpointChannel)(int deviceHandle, int channelNumber, double setpoint) {
    return attoDry_tboard_setHeaterSetpointChannel_attoDry_1_0_0(deviceHandle, channelNumber, setpoint);
}


/** @brief @attoDry_tboard_setHeaterZoneSettingsChannel
*  Start heating in zone mode
*
*  @param deviceHandle     Handle of device
*  @param channelNumber    
*  @param zone             
*  @param upperbound       Upper temperature bound of zone
*  @param p_input          
*  @param i_input          
*  @param d_input          
*  @param manualOutput     
*  @param heatingRange     0 -> off, 1 -> attocube OEM on, 1 -> 335, 336 Low, , 2 -> 335, 336 Medium, , 3 -> 335, 336 High
*  @param rampRate         
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_setHeaterZoneSettingsChannel_attoDry_1_0_0(int deviceHandle, int channelNumber, int zone, double upperbound, double p_input, double i_input, double d_input, double manualOutput, int heatingRange, double rampRate);

static inline int ATTO_FUNCTION(attoDry_tboard_setHeaterZoneSettingsChannel)(int deviceHandle, int channelNumber, int zone, double upperbound, double p_input, double i_input, double d_input, double manualOutput, int heatingRange, double rampRate) {
    return attoDry_tboard_setHeaterZoneSettingsChannel_attoDry_1_0_0(deviceHandle, channelNumber, zone, upperbound, p_input, i_input, d_input, manualOutput, heatingRange, rampRate);
}


/** @brief @attoDry_tboard_startHeatingChannel
*  Start heating
*
*  @param deviceHandle     Handle of device
*  @param channelNumber    
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_startHeatingChannel_attoDry_1_0_0(int deviceHandle, int channelNumber);

static inline int ATTO_FUNCTION(attoDry_tboard_startHeatingChannel)(int deviceHandle, int channelNumber) {
    return attoDry_tboard_startHeatingChannel_attoDry_1_0_0(deviceHandle, channelNumber);
}


/** @brief @attoDry_tboard_startHeatingOpenLoopChannel
*  Start heating in zone mode
*
*  @param deviceHandle     Handle of device
*  @param channelNumber    
*  @param power            
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_startHeatingOpenLoopChannel_attoDry_1_0_0(int deviceHandle, int channelNumber, double power);

static inline int ATTO_FUNCTION(attoDry_tboard_startHeatingOpenLoopChannel)(int deviceHandle, int channelNumber, double power) {
    return attoDry_tboard_startHeatingOpenLoopChannel_attoDry_1_0_0(deviceHandle, channelNumber, power);
}


/** @brief @attoDry_tboard_startHeatingZoneModeChannel
*  Start heating in zone mode
*
*  @param deviceHandle     Handle of device
*  @param channelNumber    
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_startHeatingZoneModeChannel_attoDry_1_0_0(int deviceHandle, int channelNumber);

static inline int ATTO_FUNCTION(attoDry_tboard_startHeatingZoneModeChannel)(int deviceHandle, int channelNumber) {
    return attoDry_tboard_startHeatingZoneModeChannel_attoDry_1_0_0(deviceHandle, channelNumber);
}


/** @brief @attoDry_tboard_stopHeatingChannel
*  Stop heating
*
*  @param deviceHandle     Handle of device
*  @param channelNumber    
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_stopHeatingChannel_attoDry_1_0_0(int deviceHandle, int channelNumber);

static inline int ATTO_FUNCTION(attoDry_tboard_stopHeatingChannel)(int deviceHandle, int channelNumber) {
    return attoDry_tboard_stopHeatingChannel_attoDry_1_0_0(deviceHandle, channelNumber);
}


/** @brief @attoDry_tboard_uploadCalibrationCurve
*  Sets the sensor calibration curve
*   may time out, but the upload will still work
*
*  @param deviceHandle     Handle of device
*  @param channel          
*  @param curveData        calibration data
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_uploadCalibrationCurve_attoDry_1_0_0(int deviceHandle, int channel, const char* curveData);

static inline int ATTO_FUNCTION(attoDry_tboard_uploadCalibrationCurve)(int deviceHandle, int channel, const char* curveData) {
    return attoDry_tboard_uploadCalibrationCurve_attoDry_1_0_0(deviceHandle, channel, curveData);
}


/** @brief @attoDry_tboard_uploadCalibrationCurve340
*  Sets the sensor .340 calibration curve
*   may time out, but the upload will still work
*
*  @param deviceHandle     Handle of device
*  @param channel          
*  @param curveData        calibration data
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_tboard_uploadCalibrationCurve340_attoDry_1_0_0(int deviceHandle, int channel, const char* curveData);

static inline int ATTO_FUNCTION(attoDry_tboard_uploadCalibrationCurve340)(int deviceHandle, int channel, const char* curveData) {
    return attoDry_tboard_uploadCalibrationCurve340_attoDry_1_0_0(deviceHandle, channel, curveData);
}


/** @brief @attoDry_grantAccess
*  Grants access to a locked device for the requesting IP by checking against the password
*
*  @param deviceHandle     Handle of device
*  @param password         string the current password
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_grantAccess_attoDry_1_0_0(int deviceHandle, const char* password);

static inline int ATTO_FUNCTION(attoDry_grantAccess)(int deviceHandle, const char* password) {
    return attoDry_grantAccess_attoDry_1_0_0(deviceHandle, password);
}


/** @brief @attoDry_lock
*  This function locks the device with a password, so the calling of functions is only possible with this password. The locking IP is automatically added to the devices which can access functions
*
*  @param deviceHandle     Handle of device
*  @param password         string the password to be set
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_lock_attoDry_1_0_0(int deviceHandle, const char* password);

static inline int ATTO_FUNCTION(attoDry_lock)(int deviceHandle, const char* password) {
    return attoDry_lock_attoDry_1_0_0(deviceHandle, password);
}


/** @brief @attoDry_unlock
*  This function unlocks the device, so it will not be necessary to execute the grantAccess function to run any function
*
*  @param deviceHandle     Handle of device
*  @param password         string the current password
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API attoDry_unlock_attoDry_1_0_0(int deviceHandle, const char* password);

static inline int ATTO_FUNCTION(attoDry_unlock)(int deviceHandle, const char* password) {
    return attoDry_unlock_attoDry_1_0_0(deviceHandle, password);
}


/** @brief @attoDry_getLockStatus
*  This function returns if the device is locked and if the current client is authorized to use the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_locked     locked Is the device locked?
*  @param value_authorized authorized Is the client authorized?
*
*  @return locked Is the device locked?
*/
int ATTOCUBE_API attoDry_getLockStatus_attoDry_1_0_0(int deviceHandle, bool* value_locked, bool* value_authorized);

static inline int ATTO_FUNCTION(attoDry_getLockStatus)(int deviceHandle, bool* value_locked, bool* value_authorized) {
    return attoDry_getLockStatus_attoDry_1_0_0(deviceHandle, value_locked, value_authorized);
}


/** @brief @system_about_getInstalledPackages
*  Get list of packages installed on the device
*
*  @param deviceHandle     Handle of device
*
*  @param value_string     string: Comma separated list of packages
*  @param size             Maximum size of buffer value_string
*
*  @return string: Comma separated list of packages
*/
int ATTOCUBE_API system_about_getInstalledPackages_attoDry_1_0_0(int deviceHandle, char* value_string, int size);

static inline int ATTO_FUNCTION(system_about_getInstalledPackages)(int deviceHandle, char* value_string, int size) {
    return system_about_getInstalledPackages_attoDry_1_0_0(deviceHandle, value_string, size);
}


/** @brief @system_about_getPackageLicense
*  Get the license for a specific package
*
*  @param deviceHandle     Handle of device
*  @param pckg             string: Package name
*
*  @param value_string     string: License for this package
*  @param size             Maximum size of buffer value_string
*
*  @return string: License for this package
*/
int ATTOCUBE_API system_about_getPackageLicense_attoDry_1_0_0(int deviceHandle, const char* pckg, char* value_string, int size);

static inline int ATTO_FUNCTION(system_about_getPackageLicense)(int deviceHandle, const char* pckg, char* value_string, int size) {
    return system_about_getPackageLicense_attoDry_1_0_0(deviceHandle, pckg, value_string, size);
}


/** @brief @system_update_getSwUpdateProgress
*  Get the progress of running update
*
*  @param deviceHandle     Handle of device
*
*  @param value_int        int: progress in percent
*
*  @return int: progress in percent
*/
int ATTOCUBE_API system_update_getSwUpdateProgress_attoDry_1_0_0(int deviceHandle, int* value_int);

static inline int ATTO_FUNCTION(system_update_getSwUpdateProgress)(int deviceHandle, int* value_int) {
    return system_update_getSwUpdateProgress_attoDry_1_0_0(deviceHandle, value_int);
}


/** @brief @system_update_getLicenseUpdateProgress
*  Get the progress of running license update
*
*  @param deviceHandle     Handle of device
*
*  @param value_int        int: progress in percent
*
*  @return int: progress in percent
*/
int ATTOCUBE_API system_update_getLicenseUpdateProgress_attoDry_1_0_0(int deviceHandle, int* value_int);

static inline int ATTO_FUNCTION(system_update_getLicenseUpdateProgress)(int deviceHandle, int* value_int) {
    return system_update_getLicenseUpdateProgress_attoDry_1_0_0(deviceHandle, value_int);
}


/** @brief @system_update_softwareUpdateBase64
*  Execute the update with base64 file uploaded.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_update_softwareUpdateBase64_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_update_softwareUpdateBase64)(int deviceHandle) {
    return system_update_softwareUpdateBase64_attoDry_1_0_0(deviceHandle);
}


/** @brief @system_update_uploadSoftwareImageBase64
*  Upload new firmware image in format base 64
*
*  @param deviceHandle     Handle of device
*  @param offset           int: offset of the data
*  @param b64Data          string: base64 data
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_update_uploadSoftwareImageBase64_attoDry_1_0_0(int deviceHandle, int offset, const char* b64Data);

static inline int ATTO_FUNCTION(system_update_uploadSoftwareImageBase64)(int deviceHandle, int offset, const char* b64Data) {
    return system_update_uploadSoftwareImageBase64_attoDry_1_0_0(deviceHandle, offset, b64Data);
}


/** @brief @system_update_uploadLicenseBase64
*  Upload new license file in format base 64
*
*  @param deviceHandle     Handle of device
*  @param offset           int: offset of the data
*  @param b64Data          string: base64 data
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_update_uploadLicenseBase64_attoDry_1_0_0(int deviceHandle, int offset, const char* b64Data);

static inline int ATTO_FUNCTION(system_update_uploadLicenseBase64)(int deviceHandle, int offset, const char* b64Data) {
    return system_update_uploadLicenseBase64_attoDry_1_0_0(deviceHandle, offset, b64Data);
}


/** @brief @system_update_licenseUpdateBase64
*  Execute the license update with base64 file uploaded.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_update_licenseUpdateBase64_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_update_licenseUpdateBase64)(int deviceHandle) {
    return system_update_licenseUpdateBase64_attoDry_1_0_0(deviceHandle);
}


/** @brief @system_functions_checkAMCinRack
*  If AMC is on Rack position 0, use it as DHCP server, else use it as DHCP client
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_functions_checkAMCinRack_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_functions_checkAMCinRack)(int deviceHandle) {
    return system_functions_checkAMCinRack_attoDry_1_0_0(deviceHandle);
}


/** @brief @system_network_getRealIpAddress
*  Get the real IP address of the device set to the network interface (br0, eth1 or eth0)
*
*  @param deviceHandle     Handle of device
*
*  @param value_IP         IP address as string
*  @param size             Maximum size of buffer value_IP
*
*  @return IP address as string
*/
int ATTOCUBE_API system_network_getRealIpAddress_attoDry_1_0_0(int deviceHandle, char* value_IP, int size);

static inline int ATTO_FUNCTION(system_network_getRealIpAddress)(int deviceHandle, char* value_IP, int size) {
    return system_network_getRealIpAddress_attoDry_1_0_0(deviceHandle, value_IP, size);
}


/** @brief @system_network_getIpAddress
*  Get the IP address of the device
*
*  @param deviceHandle     Handle of device
*
*  @param value_IP         IP address as string
*  @param size             Maximum size of buffer value_IP
*
*  @return IP address as string
*/
int ATTOCUBE_API system_network_getIpAddress_attoDry_1_0_0(int deviceHandle, char* value_IP, int size);

static inline int ATTO_FUNCTION(system_network_getIpAddress)(int deviceHandle, char* value_IP, int size) {
    return system_network_getIpAddress_attoDry_1_0_0(deviceHandle, value_IP, size);
}


/** @brief @system_network_setIpAddress
*  Set the IP address of the device
*
*  @param deviceHandle     Handle of device
*  @param address          IP address as string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setIpAddress_attoDry_1_0_0(int deviceHandle, const char* address);

static inline int ATTO_FUNCTION(system_network_setIpAddress)(int deviceHandle, const char* address) {
    return system_network_setIpAddress_attoDry_1_0_0(deviceHandle, address);
}


/** @brief @system_network_getSubnetMask
*  Get the subnet mask of the device
*
*  @param deviceHandle     Handle of device
*
*  @param value_Subnet     Subnet mask as string
*  @param size             Maximum size of buffer value_Subnet
*
*  @return Subnet mask as string
*/
int ATTOCUBE_API system_network_getSubnetMask_attoDry_1_0_0(int deviceHandle, char* value_Subnet, int size);

static inline int ATTO_FUNCTION(system_network_getSubnetMask)(int deviceHandle, char* value_Subnet, int size) {
    return system_network_getSubnetMask_attoDry_1_0_0(deviceHandle, value_Subnet, size);
}


/** @brief @system_network_setSubnetMask
*  Set the subnet mask of the device
*
*  @param deviceHandle     Handle of device
*  @param netmask          Subnet mask as string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setSubnetMask_attoDry_1_0_0(int deviceHandle, const char* netmask);

static inline int ATTO_FUNCTION(system_network_setSubnetMask)(int deviceHandle, const char* netmask) {
    return system_network_setSubnetMask_attoDry_1_0_0(deviceHandle, netmask);
}


/** @brief @system_network_getDefaultGateway
*  Get the default gateway of the device
*
*  @param deviceHandle     Handle of device
*
*  @param value_Default    Default gateway
*  @param size             Maximum size of buffer value_Default
*
*  @return Default gateway
*/
int ATTOCUBE_API system_network_getDefaultGateway_attoDry_1_0_0(int deviceHandle, char* value_Default, int size);

static inline int ATTO_FUNCTION(system_network_getDefaultGateway)(int deviceHandle, char* value_Default, int size) {
    return system_network_getDefaultGateway_attoDry_1_0_0(deviceHandle, value_Default, size);
}


/** @brief @system_network_setDefaultGateway
*  Set the default gateway of the device
*
*  @param deviceHandle     Handle of device
*  @param gateway          Default gateway as string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setDefaultGateway_attoDry_1_0_0(int deviceHandle, const char* gateway);

static inline int ATTO_FUNCTION(system_network_setDefaultGateway)(int deviceHandle, const char* gateway) {
    return system_network_setDefaultGateway_attoDry_1_0_0(deviceHandle, gateway);
}


/** @brief @system_network_getDnsResolver
*  Get the DNS resolver
*
*  @param deviceHandle     Handle of device
*  @param priority         of DNS resolver (Usually: 0 = Default, 1 = Backup)
*
*  @param value_IP         IP address of DNS resolver
*  @param size             Maximum size of buffer value_IP
*
*  @return IP address of DNS resolver
*/
int ATTOCUBE_API system_network_getDnsResolver_attoDry_1_0_0(int deviceHandle, int priority, char* value_IP, int size);

static inline int ATTO_FUNCTION(system_network_getDnsResolver)(int deviceHandle, int priority, char* value_IP, int size) {
    return system_network_getDnsResolver_attoDry_1_0_0(deviceHandle, priority, value_IP, size);
}


/** @brief @system_network_setDnsResolver
*  Set the DNS resolver
*
*  @param deviceHandle     Handle of device
*  @param priority         of DNS resolver (Usually: 0 = Default, 1 = Backup)
*  @param resolver         The resolver's IP address as string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setDnsResolver_attoDry_1_0_0(int deviceHandle, int priority, const char* resolver);

static inline int ATTO_FUNCTION(system_network_setDnsResolver)(int deviceHandle, int priority, const char* resolver) {
    return system_network_setDnsResolver_attoDry_1_0_0(deviceHandle, priority, resolver);
}


/** @brief @system_network_getProxyServer
*  Get the proxy settings of the devide
*
*  @param deviceHandle     Handle of device
*
*  @param value_Proxy      Proxy Server String, empty for no proxy
*  @param size             Maximum size of buffer value_Proxy
*
*  @return Proxy Server String, empty for no proxy
*/
int ATTOCUBE_API system_network_getProxyServer_attoDry_1_0_0(int deviceHandle, char* value_Proxy, int size);

static inline int ATTO_FUNCTION(system_network_getProxyServer)(int deviceHandle, char* value_Proxy, int size) {
    return system_network_getProxyServer_attoDry_1_0_0(deviceHandle, value_Proxy, size);
}


/** @brief @system_network_setProxyServer
*  Set the proxy server of the device
*
*  @param deviceHandle     Handle of device
*  @param proxyServer      Proxy Server Setting as string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setProxyServer_attoDry_1_0_0(int deviceHandle, const char* proxyServer);

static inline int ATTO_FUNCTION(system_network_setProxyServer)(int deviceHandle, const char* proxyServer) {
    return system_network_setProxyServer_attoDry_1_0_0(deviceHandle, proxyServer);
}


/** @brief @system_network_getEnableDhcpServer
*  Get the state of DHCP server
*
*  @param deviceHandle     Handle of device
*
*  @param value_boolean    boolean: true = DHCP server enable, false = DHCP server disable
*
*  @return boolean: true = DHCP server enable, false = DHCP server disable
*/
int ATTOCUBE_API system_network_getEnableDhcpServer_attoDry_1_0_0(int deviceHandle, bool* value_boolean);

static inline int ATTO_FUNCTION(system_network_getEnableDhcpServer)(int deviceHandle, bool* value_boolean) {
    return system_network_getEnableDhcpServer_attoDry_1_0_0(deviceHandle, value_boolean);
}


/** @brief @system_network_setEnableDhcpServer
*  Enable or disable DHCP server
*
*  @param deviceHandle     Handle of device
*  @param enable           boolean: true = enable DHCP server, false = disable DHCP server
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setEnableDhcpServer_attoDry_1_0_0(int deviceHandle, bool enable);

static inline int ATTO_FUNCTION(system_network_setEnableDhcpServer)(int deviceHandle, bool enable) {
    return system_network_setEnableDhcpServer_attoDry_1_0_0(deviceHandle, enable);
}


/** @brief @system_network_getEnableDhcpClient
*  Get the state of DHCP client
*
*  @param deviceHandle     Handle of device
*
*  @param value_boolean    boolean: true = DHCP client enable, false = DHCP client disable
*
*  @return boolean: true = DHCP client enable, false = DHCP client disable
*/
int ATTOCUBE_API system_network_getEnableDhcpClient_attoDry_1_0_0(int deviceHandle, bool* value_boolean);

static inline int ATTO_FUNCTION(system_network_getEnableDhcpClient)(int deviceHandle, bool* value_boolean) {
    return system_network_getEnableDhcpClient_attoDry_1_0_0(deviceHandle, value_boolean);
}


/** @brief @system_network_setEnableDhcpClient
*  Enable or disable DHCP client
*
*  @param deviceHandle     Handle of device
*  @param enable           boolean: true = enable DHCP client, false = disable DHCP client
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setEnableDhcpClient_attoDry_1_0_0(int deviceHandle, bool enable);

static inline int ATTO_FUNCTION(system_network_setEnableDhcpClient)(int deviceHandle, bool enable) {
    return system_network_setEnableDhcpClient_attoDry_1_0_0(deviceHandle, enable);
}


/** @brief @system_network_apply
*  Apply temporary IP configuration and load it
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_apply_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_network_apply)(int deviceHandle) {
    return system_network_apply_attoDry_1_0_0(deviceHandle);
}


/** @brief @system_network_verify
*  Verify that temporary IP configuration is correct
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_verify_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_network_verify)(int deviceHandle) {
    return system_network_verify_attoDry_1_0_0(deviceHandle);
}


/** @brief @system_network_discard
*  Discard temporary IP configuration
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_discard_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_network_discard)(int deviceHandle) {
    return system_network_discard_attoDry_1_0_0(deviceHandle);
}


/** @brief @system_network_getWifiPresent
*  Returns is a Wifi interface is present
*
*  @param deviceHandle     Handle of device
*
*  @param value_True       True, if interface is present
*
*  @return True, if interface is present
*/
int ATTOCUBE_API system_network_getWifiPresent_attoDry_1_0_0(int deviceHandle, bool* value_True);

static inline int ATTO_FUNCTION(system_network_getWifiPresent)(int deviceHandle, bool* value_True) {
    return system_network_getWifiPresent_attoDry_1_0_0(deviceHandle, value_True);
}


/** @brief @system_network_setWifiMode
*  Change the operation mode of the wifi adapter
*
*  @param deviceHandle     Handle of device
*  @param mode             0: Access point, 1: Wifi client
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setWifiMode_attoDry_1_0_0(int deviceHandle, int mode);

static inline int ATTO_FUNCTION(system_network_setWifiMode)(int deviceHandle, int mode) {
    return system_network_setWifiMode_attoDry_1_0_0(deviceHandle, mode);
}


/** @brief @system_network_getWifiMode
*  Get the operation mode of the wifi adapter
*
*  @param deviceHandle     Handle of device
*
*  @param value_mode       mode 0: Access point, 1: Wifi client
*
*  @return mode 0: Access point, 1: Wifi client
*/
int ATTOCUBE_API system_network_getWifiMode_attoDry_1_0_0(int deviceHandle, int* value_mode);

static inline int ATTO_FUNCTION(system_network_getWifiMode)(int deviceHandle, int* value_mode) {
    return system_network_getWifiMode_attoDry_1_0_0(deviceHandle, value_mode);
}


/** @brief @system_network_setWifiSSID
*  Change the SSID of the network hosted (mode: Access point) or connected to (mode: client)
*
*  @param deviceHandle     Handle of device
*  @param ssid             
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setWifiSSID_attoDry_1_0_0(int deviceHandle, const char* ssid);

static inline int ATTO_FUNCTION(system_network_setWifiSSID)(int deviceHandle, const char* ssid) {
    return system_network_setWifiSSID_attoDry_1_0_0(deviceHandle, ssid);
}


/** @brief @system_network_getWifiSSID
*  Get the the SSID of the network hosted (mode: Access point) or connected to (mode: client)
*
*  @param deviceHandle     Handle of device
*
*  @param SSID             SSID
*  @param size             Maximum size of buffer SSID
*
*  @return SSID
*/
int ATTOCUBE_API system_network_getWifiSSID_attoDry_1_0_0(int deviceHandle, char* SSID, int size);

static inline int ATTO_FUNCTION(system_network_getWifiSSID)(int deviceHandle, char* SSID, int size) {
    return system_network_getWifiSSID_attoDry_1_0_0(deviceHandle, SSID, size);
}


/** @brief @system_network_setWifiPassphrase
*  Change the passphrase of the network hosted (mode: Access point) or connected to (mode: client)
*
*  @param deviceHandle     Handle of device
*  @param psk              Pre-shared key
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setWifiPassphrase_attoDry_1_0_0(int deviceHandle, const char* psk);

static inline int ATTO_FUNCTION(system_network_setWifiPassphrase)(int deviceHandle, const char* psk) {
    return system_network_setWifiPassphrase_attoDry_1_0_0(deviceHandle, psk);
}


/** @brief @system_network_getWifiPassphrase
*  Get the the passphrase of the network hosted (mode: Access point) or connected to (mode: client)
*
*  @param deviceHandle     Handle of device
*
*  @param value_psk        psk Pre-shared key
*  @param size             Maximum size of buffer value_psk
*
*  @return psk Pre-shared key
*/
int ATTOCUBE_API system_network_getWifiPassphrase_attoDry_1_0_0(int deviceHandle, char* value_psk, int size);

static inline int ATTO_FUNCTION(system_network_getWifiPassphrase)(int deviceHandle, char* value_psk, int size) {
    return system_network_getWifiPassphrase_attoDry_1_0_0(deviceHandle, value_psk, size);
}


/** @brief @system_network_configureWifi
*  Change the wifi configuration and applies it
*
*  @param deviceHandle     Handle of device
*  @param mode             0: Access point, 1: Wifi client
*  @param ssid             
*  @param psk              Pre-shared key
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_configureWifi_attoDry_1_0_0(int deviceHandle, int mode, const char* ssid, const char* psk);

static inline int ATTO_FUNCTION(system_network_configureWifi)(int deviceHandle, int mode, const char* ssid, const char* psk) {
    return system_network_configureWifi_attoDry_1_0_0(deviceHandle, mode, ssid, psk);
}


/** @brief @system_apply
*  Apply temporary system configuration
*
*  @param deviceHandle     Handle of device
*  @param key              
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_apply_attoDry_1_0_0(int deviceHandle, int key);

static inline int ATTO_FUNCTION(system_apply)(int deviceHandle, int key) {
    return system_apply_attoDry_1_0_0(deviceHandle, key);
}


/** @brief @system_setDeviceName
*  Set custom name for the device
*
*  @param deviceHandle     Handle of device
*  @param name             string: device name
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_setDeviceName_attoDry_1_0_0(int deviceHandle, const char* name);

static inline int ATTO_FUNCTION(system_setDeviceName)(int deviceHandle, const char* name) {
    return system_setDeviceName_attoDry_1_0_0(deviceHandle, name);
}


/** @brief @system_getDeviceName
*  Get the actual device name
*
*  @param deviceHandle     Handle of device
*
*  @param value_string     string: actual device name
*  @param size             Maximum size of buffer value_string
*
*  @return string: actual device name
*/
int ATTOCUBE_API system_getDeviceName_attoDry_1_0_0(int deviceHandle, char* value_string, int size);

static inline int ATTO_FUNCTION(system_getDeviceName)(int deviceHandle, char* value_string, int size) {
    return system_getDeviceName_attoDry_1_0_0(deviceHandle, value_string, size);
}


/** @brief @system_rebootSystem
*  Reboot the system
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_rebootSystem_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_rebootSystem)(int deviceHandle) {
    return system_rebootSystem_attoDry_1_0_0(deviceHandle);
}


/** @brief @system_factoryReset
*  Turns on the factory reset flag.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_factoryReset_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_factoryReset)(int deviceHandle) {
    return system_factoryReset_attoDry_1_0_0(deviceHandle);
}


/** @brief @system_softReset
*  Performs a soft reset (Reset without deleting the network settings).
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_softReset_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_softReset)(int deviceHandle) {
    return system_softReset_attoDry_1_0_0(deviceHandle);
}


/** @brief @system_errorNumberToString
*  Get a description of an error code
*
*  @param deviceHandle     Handle of device
*  @param language         integer: Language code 0 for the error name, 1 for a more user friendly error message
*  @param errNbr           interger: Error code to translate
*
*  @param value_string     string: Error description
*  @param size             Maximum size of buffer value_string
*
*  @return string: Error description
*/
int ATTOCUBE_API system_errorNumberToString_attoDry_1_0_0(int deviceHandle, int language, int errNbr, char* value_string, int size);

static inline int ATTO_FUNCTION(system_errorNumberToString)(int deviceHandle, int language, int errNbr, char* value_string, int size) {
    return system_errorNumberToString_attoDry_1_0_0(deviceHandle, language, errNbr, value_string, size);
}


/** @brief @system_errorNumberToRecommendation
*  Get a recommendation for the error code
*
*  @param deviceHandle     Handle of device
*  @param language         integer: Language code
*  @param errNbr           interger: Error code to translate
*
*  @param value_string     string: Error recommendation (currently returning an int = 0 until we have recommendations)
*  @param size             Maximum size of buffer value_string
*
*  @return string: Error recommendation (currently returning an int = 0 until we have recommendations)
*/
int ATTOCUBE_API system_errorNumberToRecommendation_attoDry_1_0_0(int deviceHandle, int language, int errNbr, char* value_string, int size);

static inline int ATTO_FUNCTION(system_errorNumberToRecommendation)(int deviceHandle, int language, int errNbr, char* value_string, int size) {
    return system_errorNumberToRecommendation_attoDry_1_0_0(deviceHandle, language, errNbr, value_string, size);
}


/** @brief @system_getFirmwareVersion
*  Get the firmware version of the system
*
*  @param deviceHandle     Handle of device
*
*  @param value_string     string: The firmware version
*  @param size             Maximum size of buffer value_string
*
*  @return string: The firmware version
*/
int ATTOCUBE_API system_getFirmwareVersion_attoDry_1_0_0(int deviceHandle, char* value_string, int size);

static inline int ATTO_FUNCTION(system_getFirmwareVersion)(int deviceHandle, char* value_string, int size) {
    return system_getFirmwareVersion_attoDry_1_0_0(deviceHandle, value_string, size);
}


/** @brief @system_getHostname
*  Return device hostname
*
*  @param deviceHandle     Handle of device
*
*  @param available        available
*  @param size             Maximum size of buffer available
*
*  @return available
*/
int ATTOCUBE_API system_getHostname_attoDry_1_0_0(int deviceHandle, char* available, int size);

static inline int ATTO_FUNCTION(system_getHostname)(int deviceHandle, char* available, int size) {
    return system_getHostname_attoDry_1_0_0(deviceHandle, available, size);
}


/** @brief @system_getMacAddress
*  Get the mac address of the system
*
*  @param deviceHandle     Handle of device
*
*  @param value_string     string: Mac address of the system
*  @param size             Maximum size of buffer value_string
*
*  @return string: Mac address of the system
*/
int ATTOCUBE_API system_getMacAddress_attoDry_1_0_0(int deviceHandle, char* value_string, int size);

static inline int ATTO_FUNCTION(system_getMacAddress)(int deviceHandle, char* value_string, int size) {
    return system_getMacAddress_attoDry_1_0_0(deviceHandle, value_string, size);
}


/** @brief @system_getSerialNumber
*  Get the serial number of the system
*
*  @param deviceHandle     Handle of device
*
*  @param value_string     string: Serial number
*  @param size             Maximum size of buffer value_string
*
*  @return string: Serial number
*/
int ATTOCUBE_API system_getSerialNumber_attoDry_1_0_0(int deviceHandle, char* value_string, int size);

static inline int ATTO_FUNCTION(system_getSerialNumber)(int deviceHandle, char* value_string, int size) {
    return system_getSerialNumber_attoDry_1_0_0(deviceHandle, value_string, size);
}


/** @brief @system_getFluxCode
*  Get the flux code of the system
*
*  @param deviceHandle     Handle of device
*
*  @param value_string     string: flux code
*  @param size             Maximum size of buffer value_string
*
*  @return string: flux code
*/
int ATTOCUBE_API system_getFluxCode_attoDry_1_0_0(int deviceHandle, char* value_string, int size);

static inline int ATTO_FUNCTION(system_getFluxCode)(int deviceHandle, char* value_string, int size) {
    return system_getFluxCode_attoDry_1_0_0(deviceHandle, value_string, size);
}


/** @brief @system_updateTimeFromInternet
*  Update system time by querying attocube.com
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_updateTimeFromInternet_attoDry_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_updateTimeFromInternet)(int deviceHandle) {
    return system_updateTimeFromInternet_attoDry_1_0_0(deviceHandle);
}


/** @brief @system_setTime
*  Set system time manually
*
*  @param deviceHandle     Handle of device
*  @param day              integer: Day (1-31)
*  @param month            integer: Day (1-12)
*  @param year             integer: Day (eg. 2021)
*  @param hour             integer: Day (0-23)
*  @param minute           integer: Day (0-59)
*  @param second           integer: Day (0-59)
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_setTime_attoDry_1_0_0(int deviceHandle, int day, int month, int year, int hour, int minute, int second);

static inline int ATTO_FUNCTION(system_setTime)(int deviceHandle, int day, int month, int year, int hour, int minute, int second) {
    return system_setTime_attoDry_1_0_0(deviceHandle, day, month, year, hour, minute, second);
}


#ifdef __cplusplus
}
#endif
#undef ATTO_PREFIX
#endif // __GENERATEDAPI_H_attoDry_1_0_0__