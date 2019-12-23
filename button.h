///*************|
// * Dependency |
// *************/
//
//    #include <Bounce2.h>
//
///*************|
// * Global var |
// *************/
//    
//    //กำหนดจำนวนปุ่มที่ต้องการแก้ bounce ในที่นี้ใช้ 2 ปุ่ม ต่อแบบ active low เข้า A0 และ A1
//    #define NUM_BUTTONS 2
//    const uint8_t BUTTON_PINS[NUM_BUTTONS] = {A4, A5};
//    Bounce * buttons = new Bounce[NUM_BUTTONS];
//    typedef enum {
//        SW_NONE=0,
//        SW_PRESS,
//        SW_LONGPRESS,
//        SW_LONGPRESSUSED
//    }sw_en;
//    sw_en sw[NUM_BUTTONS];
//    unsigned long sw_st[NUM_BUTTONS];
//
//
///***************|
// * Function def |
// ***************/
//    
//    void buttons_init() {
//        for (int i = 0; i < NUM_BUTTONS; i++) {
//            //ตั้งค่า button เป็นแบบ active low (แบบนี้ไม่ต้องใส่ตัวต้านทานในสวิตซ์)
//            //กรณีเป็น active high ก็จะเป็น INPUT เฉยๆ ไม่ใช่ INPUT_PULLUP
//            buttons[i].attach( BUTTON_PINS[i] , INPUT_PULLUP  );
//            //ตั้งค่าว่า ต้องกดเกิน 25 ms ถึงจะถือว่าเป็นการกดจริงๆ
//            buttons[i].interval(25);
//        }
//    }
//    
//    static inline void buttons_update() {
//        for(int i=0; i<NUM_BUTTONS; i++) {
//            buttons[i].update();
//            if(buttons[i].fell()) {
//                sw_st[i] = millis();
//            }
//            if(buttons[i].rose() && millis() - sw_st[i] <= 300) {
//                sw[i]=SW_PRESS;
//                Serial.println(String(i) + " press");
//            }
//            if(buttons[i].rose() && millis() - sw_st[i] > 300) {
//                sw[i]=SW_NONE;
//                Serial.println(String(i) + " unpress");
//            }
//            if(buttons[i].read() == LOW && millis() - sw_st[i] > 300 && sw[i]==SW_NONE){
//                sw[i]=SW_LONGPRESS;
//                Serial.println(String(i) + " Long press");
//            }
//    
//    
//        }
//    }
