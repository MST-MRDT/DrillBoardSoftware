/*
 * main.h
 *
 *  Created on: Apr 19, 2018
 *      Author: drue
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "RoveBoard_TivaTM4C1294NCPDT.h"
#include "DrillPins.h"
#include "ScrewPins.h"
#include "GenevaPins.h"
#include "RoveWare/RoveComm.h"
#include "RoveWare/RoveMotionControl/RoveMotionControl.h"
#include "RoveWare/RoveMotionControl/MotionAxises/SingleMotorAxis.h"
#include "RoveWare/RoveMotionControl/OutputDevices/VNH5019.h"
#include "RoveWare/RoveMotionControl/FeedbackDevices/Ma3Encoder12b.h"
#include "RoveWare/RoveMotionControl/IOConverters/PIAlgorithm.h"

void processBaseStationCommands();
void setup();
void moveDrill(int16_t moveVal);
void moveScrew(int16_t moveValue);
void moveGeneva(int16_t Position);
void switchToClosedLoopScrew();
void switchToOpenLoopScrew();
void closedLoopHandler();
bool checkLimSwitchHit(uint8_t pin);
void setScrewDestination(float degreesDestination);

const uint16_t DrillId = 0xB54;
const uint16_t ScrewId = 0xB55;
const uint16_t GenevaId = 0xB56;

const uint8_t ip[4] = {192, 168, 1, 139};
const uint8_t AlgK = 100;
const uint8_t AlgI = 0;
const float AlgDt = .02;

typedef enum {OpenLoop, ClosedLoop} ControlState;

#endif /* MAIN_H_ */
