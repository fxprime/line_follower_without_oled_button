///*************|
// * Dependency |
// *************/
//
//    #include <SPI.h>
//    #include <Adafruit_GFX.h>
//    #include <Adafruit_SSD1306.h>
//
//
///*************|
// * Global var |
// *************/
//
//    #define SCREEN_WIDTH 128 // OLED display width, in pixels
//    #define SCREEN_HEIGHT 64 // OLED display height, in pixels
//
//    // Declaration for SSD1306 display connected using software SPI (default case):
//    #define OLED_MOSI   3
//    #define OLED_CLK   2
//    #define OLED_DC    4
//    #define OLED_CS    5
//    #define OLED_RESET 6
//    Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
//                             OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
//    typedef enum {
//        CALIB_PAGE = 0,
//        MAIN_PAGE,
//        TUNEP_PAGE,
//        TUNED_PAGE,
//        NUM_PAGES
//    }page_en;
//
//    page_en page = CALIB_PAGE;
//    page_en page_prev = NUM_PAGES;
//
///***************|
// * Function def |
// ***************/
//
//    void display_init() {
//        // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
//        if (!display.begin(SSD1306_SWITCHCAPVCC)) {
//            Serial.println(F("SSD1306 allocation failed"));
//            for (;;); // Don't proceed, loop forever
//        }
//        display.clearDisplay();
//    }
//
//    static inline void display_text(const int& x, const int& y, const int& size, const String& text, bool center = false, const uint16_t color = WHITE, const uint16_t colorBG = BLACK) {
//        int xd = x;
//        if(center) {
//            xd = (SCREEN_WIDTH - 6*size*text.length())/2;
//        }
//        display.fillRect(xd,y,text.length()*size*6,size*8,colorBG);
//        display.setTextSize(size);
//        display.setTextColor(color);
//        display.setCursor(xd,y);
//        display.println(text);
//    }
//    static inline void display_line_track(const float& pos) {
//        int pos_int = ( (1-pos)*128);
//        display.fillRect(0,0,128,16, WHITE);
//        display.fillRect(pos_int -10,0,20,16, BLACK);
//    }
//
//
//    static inline void display_calib_page() {
//        display_text(0,0,1,"Calibration", true);
//        display_text(0,16,1,"Press left to start calib.", false);
//
//        display.display();
//    }
//    
//    static inline void display_main_page() {
//        float pos = -(float)line::getLinePos()+0.5;
//        display_text(0,20,1,"pos = " + String(pos,2));
//        display_text(0,45,1,"Press left key", true);
//        display_text(0,56,1,"to start", true);
//        display_line_track(pos);
//        display.display();
//    }
//
//    static inline void display_tuneP_page() {
//        display_text(0,0,1,"1 = mode, 2 = enter", true);
////        display_text(0,18,2,"P gain",false);
//        display_text(0,18,2,"<"+String(_Kp,2)+">",true);
//        display.display();
//    }
//
//    static inline void display_tuneD_page() {
//        display_text(0,0,1,"1 = mode, 2 = enter", true);
////        display_text(0,18,2,"D gain",false);
//        display_text(0,18,2,"<"+String(_Kd,2)+">",true);
//        display.display();
//    }
//
//    static inline void display_page_number() {
//        display_text(128-6*3,64-8,1,String((int)page+1) + "/"+String((int)NUM_PAGES), false, BLACK, WHITE);
//        display.display();
//    }
//
//    static inline void display_update() {
//
//        if(page != page_prev) {
//            page_prev = page;
//            display.clearDisplay();
//            display_page_number();
//            Serial.println("Change page to "+String((int)page));
//        }
//        switch(page) {
//            case CALIB_PAGE : {
//                display_calib_page();
//                break;
//            }
//            case MAIN_PAGE : {
//                display_main_page();
//                break;
//            }
//            case TUNEP_PAGE : {
//                display_tuneP_page();
//                break;
//            }
//            case TUNED_PAGE : {
//                display_tuneD_page();
//                break;
//            }
//        }
//
//    }
