// Date and time functions using a DS1307 RTC connected via I2C and Wire lib

#include <TinyWireM.h>
#include <TinyRTClib.h>

RTC_DS1307 rtc;

void setup () {
 
#ifdef AVR
  TinyWireM.begin();
#else
  Wire1.begin(); // Shield I2C pins connect to alt I2C bus on Arduino Due
#endif
  rtc.begin();

  if (! rtc.isrunning()) {
   
    // following line sets the RTC to the date & time this sketch was compiled
   rtc.adjust(DateTime(2015, 2, 3, 22, 16, 0));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

void loop () {
    DateTime now = rtc.now();
    
    // calculate a date which is 7 days and 30 seconds into the future
    DateTime future (now.unixtime() + 7 * 86400L + 30);
   
   
   
   for(i=0;i<now.day();i++){
     delay(1000);
   }
   
    delay(3000);
    
    
}
