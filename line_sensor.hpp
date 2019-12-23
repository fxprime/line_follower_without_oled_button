//
// Created by fx on 22/8/2562.
//

#ifndef LINE_FOLLOWER_LINE_SENSOR_HPP
#define LINE_FOLLOWER_LINE_SENSOR_HPP



namespace line {

    void line_sensor_init() {
        qtr.setTypeAnalog();
        qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3/*, A4*/}, _SensorCount);
//        qtr.setEmitterPin(255);

        // analogRead() takes about 0.1 ms on an AVR.
        // 0.1 ms per sensor * 4 samples per sensor read (default) * 6 sensors
        // * 10 reads per calibrate() call = ~24 ms per calibrate() call.
        // Call calibrate() 400 times to make calibration take about 10 seconds.
        for (uint16_t i = 0; i < 200; i++)
        {
            qtr.calibrate();
        }
        digitalWrite(LED_BUILTIN, LOW); // turn off Arduino's LED to indicate we are through with calibration

        // print the calibration minimum values measured when emitters were on
        for (uint8_t i = 0; i < _SensorCount; i++)
        {
            Serial.print(qtr.calibrationOn.minimum[i]);
            Serial.print(' ');
        }
        Serial.println();

        // print the calibration maximum values measured when emitters were on
        for (uint8_t i = 0; i < _SensorCount; i++)
        {
            Serial.print(qtr.calibrationOn.maximum[i]);
            Serial.print(' ');
        }
        Serial.println();
        Serial.println();
        delay(1000);

        Serial.println("line sensor inited");
    }

    static inline float getLinePos() {
        //Calculate line pos
        int16_t line_pos = qtr.readLineBlack(sensorValues);

        static int16_t max_val = INT16_MIN;
        static int16_t min_val = INT16_MAX;
        if(max_val < line_pos) max_val = line_pos;
        if(min_val > line_pos) min_val = line_pos;

        float out = (line_pos - 0.5*(max_val+min_val))/(max_val - min_val);

        return out;
    }


}


#endif //LINE_FOLLOWER_LINE_SENSOR_HPP
