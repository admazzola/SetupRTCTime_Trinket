/*
 *
 * RTC clock is set based on hardcoded value! (unix tim
 *
 */

#include <Time.h>  
#include <Wire.h>  
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t

const unsigned long DOWNLOAD_TIME = 1422315564; //time when doing the download..unix time since epoch


void setup()  {
  
  setSyncProvider(RTC.get);   // the function to get the time from the RTC
   setSyncInterval(10);//every 10 secs, sync with the RTC
 
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
    
  
  digitalClockDisplay();  
  delay(1000);
}

void digitalClockDisplay(){
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year()); 
  Serial.println(); 
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}



