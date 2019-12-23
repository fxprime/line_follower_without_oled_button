//
// Created by fx on 22/8/2562.
//

#ifndef LINE_FOLLOWER_CONFIG_HPP
#define LINE_FOLLOWER_CONFIG_HPP

//Tuner
#define NUM_SEN 4


//Pid gain
float _Kp = 0.03;
float _Kd = 1.0;
float _baseSpeed = 0.55;
float _limitError = 40;
float _limitDError = 40;
float _limitOutput = 0.6;


//Motor limit
uint16_t _leftMotorLimit = 1000; //0-1000
uint16_t _rightMotorLimit = 1000; //0-1000
float _max_mot_diff = 40/255.0;
float _factor_diff = 4;


//Pin setup
uint8_t LedPIN = 13;

//ขาสัญญาณมอเตอร์ซ้าย
uint8_t MLftDirAPin = 7;
uint8_t MLftDirBPin = 8;
uint8_t MLftSpdPin = 9;
bool  MLftRev = false; //กลับทิศทาง

//ขาสัญญาณมอเตอร์ขวา
uint8_t MRgtDirAPin = 12;
uint8_t MRgtDirBPin = 11;
uint8_t MRgtSpdPin = 10;
bool  MRgtRev = true; //กลับทิศทาง

//Line detector Pin setup
QTRSensors qtr;
const uint8_t _SensorCount = 4;
uint16_t sensorValues[_SensorCount];

//Robot start or stop
bool _is_sensor_inited = false;
bool _is_robot_start = false;
uint32_t last_print = 0;


#endif //LINE_FOLLOWER_CONFIG_HPP
