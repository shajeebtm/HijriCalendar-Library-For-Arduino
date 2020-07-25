
#include <HijriCalendar.h> 
 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Gregorian to Hijri conversion example
  int todaym = 6; int todayd = 13; int todayy = 2020; // 13 Jun 2020
  Serial.print("Griorian date : ");
  Serial.print (todaym) ; Serial.print("-"); Serial.print(todayd); Serial.print("-"); Serial.print(todayy);
  Serial.print(" -- ");
  Serial.print ("Hijri date : ");
  gregorianToHijri (todaym , todayd , todayy);    // NOTE value of these variables get overwritten
  Serial.print (todaym) ; Serial.print("-"); Serial.print(todayd); Serial.print("-"); Serial.print(todayy);
  Serial.println("");


  // Hijri to Gregorian  conversion example
  todaym = 9; todayd = 1;  todayy = 1441 ; // 1 Ramzan 2020
  Serial.print ("Hijri date : ");
  Serial.print (todaym) ; Serial.print("-"); Serial.print(todayd); Serial.print("-"); Serial.print(todayy);
  Serial.print(" -- ");
  Serial.print("Griorian date : ");
  hijriToGregorian (todaym , todayd , todayy);  // NOTE value of these variables get overwritten
  Serial.print (todaym) ; Serial.print("-"); Serial.print(todayd); Serial.print("-"); Serial.print(todayy);
  Serial.println("");
  
}

void loop() {
  ;
}
