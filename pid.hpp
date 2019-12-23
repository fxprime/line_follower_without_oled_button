//
// Created by fx on 22/8/2562.
//

#ifndef LINE_FOLLOWER_PID_HPP
#define LINE_FOLLOWER_PID_HPP

namespace pid {
    static inline void  pid_init() {
        Serial.println("pid inited");
    }
    static inline float getOutput(const float& input, const float& ref) {
        float error = ref - input;
        static float prev_error = error;
        error = constrain(error, -_limitError, _limitError);
        float d_error = constrain(error - prev_error, -_limitDError, _limitDError);
        prev_error = error;

//        Serial.print(error);
//        Serial.print("\t");
//        Serial.print(d_error );
//        Serial.print("\t");
//        Serial.println(_Kd*d_error );
        return _Kp*error + _Kd*d_error;
    }
}


#endif //LINE_FOLLOWER_PID_HPP
