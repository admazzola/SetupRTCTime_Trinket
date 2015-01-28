/*
 *
 * RTC clock is set based on hardcoded value! (unix tim
 *pin 1 has an LED for blink debugging
 */

#include <Time.h>  
#include <Wire.h>  
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t

const unsigned long DOWNLOAD_TIME = 1422315564; //time when doing the download..unix time since epoch

int ledPin = 1;

void setup()  {
  
  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  
  
 pinMode(ledPin, OUTPUT);      // sets the digital pin as output
 
 /* if (timeStatus() != timeSet) 
     Serial.println("Unable to sync with the RTC");
  else
     Serial.println("RTC has set the system time");      
    */
}

void loop()
{
  
    time_t t = DOWNLOAD_TIME;
   
      RTC.set(t);   // set the RTC and the system time to the received value
      setTime(t);          
    
    
    if(timeStatus() == timeSet){
    debugBlink(1);//RTC got time, sent it back
    }
    
    if(timeStatus() == timeNotSet){
    debugBlink(3);//issue, RTC didnt get time
    }
    
    if(timeStatus() == timeNeedsSync){
    debugBlink(5);//issue, RTC didnt send time back to us
    }
    
    
    
  delay(1000);
}



void debugBlink(int count)
{
  int i=0;
  for(i=0;i<count;i++)
  {
  digitalWrite(ledPin, HIGH);   // sets the LED on
  delay(200);                  // waits for a second
  digitalWrite(ledPin, LOW);    // sets the LED off
  delay(200); 
  }
  
  delay(4000);
}
