//By NAYjY 160314

#include <SoftwareSerial.h>
#include <TinyGPS.h>



TinyGPS gps;

SoftwareSerial uart_gps(4, 5);

void getgps(TinyGPS &gps);

void setup() {
 // This is the serial rate for your terminal program. It must be this 
  // fast because we need to print everything before a new sentence 
  // comes in. If you slow it down, the messages might not be valid and 
  // you will likely get checksum errors.
  Serial.begin(115200);
  //Sets baud rate of your GPS
  uart_gps.begin(57600);
  

}

// This is the main loop of the code. All it does is check for data on 
// the RX pin of the ardiuno, makes sure the data is valid NMEA sentences, 
// then jumps to the getgps() function.
void loop()
{
  getgps(gps);
//  while(uart_gps.available())     // While there is data on the RX pin...
//  {
//      int c = uart_gps.read();    // load the data into a variable...
//      if (uart_gps.overflow())
//    {
//      Serial.println("OVERFLOW ");
//    }
//      getgps(gps);
//      if(gps.encode(c))      // if there is a new valid sentence...
//      { 
//        getgps(gps);         // then grab the data.
//      }
//  }
}

// The getgps function will get and print the values we want.
void getgps(TinyGPS &gps)
{
  // To get all of the data into varialbes that you can use in your code, 
  // all you need to do is define variables and query the object for the 
  // data. To see the complete list of functions see keywords.txt file in 
  // the TinyGPS and NewSoftSerial libs.
  
 
  // Define the variables that will be used
  float latitude, longitude;
  // Then call this function
  gps.f_get_position(&latitude, &longitude);
  // You can now print variables latitude and longitude
  Serial.print("Lat/Long: "); 
  Serial.print(latitude,5); 
  Serial.print(", "); 
  Serial.println(longitude,5);
  Serial.print("Size:"); Serial.print(sizeof(latitude));Serial.print(", ");Serial.println(sizeof(longitude));  
  Serial.print(latitude,BIN);Serial.print(", ");Serial.println(longitude,BIN);
//  // Same goes for date and time
//  int year;
//  byte month, day, hour, minute, second, hundredths;
//  gps.crack_datetime(&year,&month,&day,&hour,&minute,&second,&hundredths);
//  // Print data and time
//  Serial.print("Date: "); Serial.print(month, DEC); Serial.print("/"); 
//  Serial.print(day, DEC); Serial.print("/"); Serial.print(year);
//  Serial.print("  Time: "); Serial.print(hour, DEC); Serial.print(":"); 
//  Serial.print(minute, DEC); Serial.print(":"); Serial.print(second, DEC); 
//  Serial.print("."); Serial.println(hundredths, DEC);
//  //Since month, day, hour, minute, second, and hundr
//  
//  // Here you can print the altitude and course values directly since 
//  // there is only one value for the function
//  Serial.print("Altitude (meters): "); Serial.println(gps.f_altitude());  
//  // Same goes for course
//  Serial.print("Course (degrees): "); Serial.println(gps.f_course()); 
//  // And same goes for speed
//  Serial.print("Speed(kmph): "); Serial.println(gps.f_speed_kmph());
//  Serial.println();
//  
//  // Here you can print statistics on the sentences.
//  unsigned long chars;
//  unsigned short sentences, failed_checksum;
//  gps.stats(&chars, &sentences, &failed_checksum);
//  //Serial.print("Failed Checksums: ");Serial.print(failed_checksum);
//  //Serial.println(); Serial.println();
}
