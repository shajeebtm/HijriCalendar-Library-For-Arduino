# HijriCalendar : Arduino  library  for converting Gregorian date to Hijri date and vice versa

## Library setup

* Mac users :  Create a directory named HijriCalendar inside ~/Documents/Arduino/libraries/ . Then copy the file [HijriCalendar.h](../master/src/HijriCalendar.h) into this newly created directory
* Windows suers : Create a directory named HijriCalendar inside My Documents\Arduino\libraries\ . Then copy the file  [HijriCalendar.h](../master/src/HijriCalendar.h) into this newly created directory

## Basic usage

      #include <HijriCalendar.h>
      // Gregorian to Hijri conversion 
      gregorianToHijri (month , date , year); // NOTE value of these variables get overwritten with the result
      // Hijri to Gregorian  conversion 
      hijriToGregorian (month , date , year); // NOTE value of these variables get overwritten with the result
      PrayerTimes my_prayer_object;
 
The result will be available in the same variable were the input is stored

Refer to [example](example) for detailed usage of the library.

