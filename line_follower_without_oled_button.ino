#include <Arduino.h>
#include <QTRSensors.h>
#include "User_Setup.h"
#include "macro.hpp"
#include "config.hpp"
#include "line_sensor.hpp"
#include "motor.hpp"
#include "pid.hpp"



void setup() {

    /***************|
     * เริ่มต้น Display  |
     ***************/
        Serial.begin(115200);

//    while(1) {
//        delay(100);
//        char buff[44];
//        sprintf(buff, "%d %d %d %d", analogRead(A0), analogRead(A1), analogRead(A2), analogRead(A3));
//        Serial.println(buff);
//    }


    /***************************************|
     * เริ่มต้น sensor motor และ pid สำหรับหุ่นยนต์เดินตามเส้น|
     ***************************************/
        
        motor::motor_init();
        pid::pid_init();
        line::line_sensor_init();

        
    /***************|
     *  End setup   |
     ***************/
        _is_robot_start = true;
        Serial.println("Start robot!!");
}

void loop() {



        pid_control();

    

}
static inline pid_control() {
    _is_robot_start  =true;
    if( millis() - last_print > 10 && _is_robot_start) {
        last_print = millis();

        float pose = -100*(float)line::getLinePos();

        Serial.println(String(pose,2));
//        float pose = 0;
        
        if(_is_robot_start) {
            float rotate = pid::getOutput(pose, 0);
            rotate = constrain(rotate, -_limitOutput, _limitOutput);
//        _baseSpeed= 0;
            float leftOut = constrain(_baseSpeed + rotate, -1, 1.0);
            float rightOut = constrain(_baseSpeed - rotate, -1, 1.0);
            motor::motor_cmd(leftOut, rightOut);
        }else{
            motor::motor_cmd(0,0);
        }

    }
}
