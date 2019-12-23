//
// Created by fx on 22/8/2562.
//

#ifndef LINE_FOLLOWER_MOTOR_HPP
#define LINE_FOLLOWER_MOTOR_HPP


namespace motor {


    void motor_init() {
        pinMode(MLftDirAPin, OUTPUT);
        pinMode(MLftDirBPin, OUTPUT);
        pinMode(MLftSpdPin, OUTPUT);
        pinMode(MRgtDirAPin, OUTPUT);
        pinMode(MRgtDirBPin, OUTPUT);
        pinMode(MRgtSpdPin, OUTPUT);
        Serial.println("Motor inited");
    }

    static inline void changeSpeed(const int& pin, const float& normVal) {
        int servoOut;
        servoOut = (normVal*255.0);
        analogWrite(pin, servoOut);
    }

    /**
     * Motor out using norm spd of each motor.
     * @param leftspd [-1.0, 1.0]
     * @param rightspd [-1.0, 1.0]
     */
    static inline void motor_cmd(const float& leftspd, const float& rightspd) {

        //Check direction from spd >0 forward, <0 backward, 0 stop
        digitalWrite( MLftDirAPin, (MLftRev ? sign(leftspd)>0 : sign(leftspd)<0) );
        digitalWrite( MLftDirBPin, (MLftRev ? sign(leftspd)<0 : sign(leftspd)>0));
        digitalWrite( MRgtDirAPin, (MRgtRev ? sign(rightspd)>0 : sign(rightspd)<0) );
        digitalWrite( MRgtDirBPin, (MRgtRev ? sign(rightspd)<0 : sign(rightspd)>0) );

        float Lout = constrain( fabs(leftspd*1000), 0, 1000)/1000.0;
        float Rout = constrain( fabs(rightspd*1000), 0, 1000)/1000.0;
        Lout =  Lout * ((float)_leftMotorLimit)/1000.0;
        Rout =  Rout * ((float)_rightMotorLimit)/1000.0;

//        changeSpeed(MLftSpdPin, Lout);
//        changeSpeed(MRgtSpdPin, Rout);

//        // if difference is too much - decrease using a factor to a decent level
//
//        if(Lout - Rout > _max_mot_diff)
//        {
//            Lout -= (Lout - Rout)/_factor_diff;
//        }
//        else if(Rout - Lout > _max_mot_diff)
//        {
//            Rout -= (Rout - Lout)/_factor_diff;
//        }


        analogWrite(MLftSpdPin, Lout*255.0);
        analogWrite(MRgtSpdPin, Rout*255.0);

//        Serial.print(Lout);
//        Serial.print("\t");
//        Serial.println(Rout);
    }
}


#endif //LINE_FOLLOWER_MOTOR_HPP
