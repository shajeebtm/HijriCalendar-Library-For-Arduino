/*-------------------------- In the name of God ----------------------------*\


/* Arduino class library  to convert Gregorian date to Hijri date and vice versa */
/* This is ported  by Shajeeb T Muhammad from the code found in the Internet     */
/* Refer https://github.com/shajeebtm for usage details with example.            */

/*

License: GNU LGPL v3.0

TERMS OF USE:
    Permission is granted to use this code, with or
    without modification, in any website or application
    provided that credit is given to the original work
    with a link back to PrayTimes.org.

This program is distributed in the hope that it will
be useful, but WITHOUT ANY WARRANTY.

PLEASE DO NOT REMOVE THIS COPYRIGHT BLOCK.

------------------------------------------------------------------------------
*/

static const long IslamicEpoch = 227014; // Absolute date of start of Islamic calendar

static int lastDayOfGregorianMonth( int month, int year )
 {
     // Compute the last date of the month for the Gregorian calendar.

     switch ( month ) {
     case 2:
         if ( ( ( ( year % 4 ) == 0 ) && ( ( year % 100 ) != 0 ) )
                 || ( ( year % 400 ) == 0 ) ) {
             return 29;
         } else {
             return 28;
         }
     case 4:
     case 6:
     case 9:
     case 11: return 30;
     default: return 31;
     }
 }


class GregorianDate
 {
 private:
     long year;   // 1...
     int month;  // 1 == January, ..., 12 == December
     int day;    // 1..lastDayOfGregorianMonth(month, year)


 public:
     GregorianDate( int m, int d, int y )
     {
         month = m; day = d; year = y;

     }

     // Computes the Gregorian date from the absolute date.
     GregorianDate( long d )
     {
         // Search forward year by year from approximate year
         year = d / 366;
         while ( d >= GregorianDate( 1, 1, year + 1 ) ) {
             year++;
         }
         // Search forward month by month from January
         month = 1;
         while ( d > GregorianDate( month, lastDayOfGregorianMonth( month, year ), year ) ) {
             month++;
         }
         day = d - GregorianDate( month, 1, year ) + 1;
     }

     // Computes the absolute date from the Gregorian date.
     operator long ()
     {
         int N = day;           // days this month
         for ( int m = month - 1;  m > 0; m-- ) // days in prior months this year
             N = N + lastDayOfGregorianMonth( m, year );
         return
             ( N                    // days this year
               + 365 * ( year - 1 )   // days in previous years ignoring leap days
               + ( year - 1 ) / 4       // Julian leap days before this year...
               - ( year - 1 ) / 100     // ...minus prior century years...
               + ( year - 1 ) / 400 );   // ...plus prior years divisible by 400
     }

     int getMonth()
     {
         return month;
     }

     int getDay()
     {
         return day;
     }

     int getYear()
     {
         return year;
     }

 };
 
 
 
static int IslamicLeapYear( int year )
 {
 // True if year is an Islamic leap year

     if ( ( ( ( 11 * year ) + 14 ) % 30 ) < 11 ) {
         return 1;
     } else {
         return 0;
     }
 }


static int lastDayOfIslamicMonth( int month, int year )
 {
 // Last day in month during year on the Islamic calendar.

     if ( ( ( month % 2 ) == 1 ) || ( ( month == 12 ) && IslamicLeapYear( year ) ) ) {
         return 30;
     } else {
         return 29;
     }
 }
 
 
 class IslamicDate
 {
 private:
     long year;   // 1...
     int month;  // 1..13 (12 in a comonthon year)
     int day;    // 1..lastDayOfIslamicMonth(month,year)

 public:
     IslamicDate( int m, int d, int y )
     {
         month = m; day = d; year = y;
     }

     // Computes the Islamic date from the absolute date.
     IslamicDate( long  d )
     {
         if ( d <= IslamicEpoch ) { // Date is pre-Islamic
             month = 0;
             day = 0;
             year = 0;
         } else {
             // Search forward year by year from approximate year
             year = ( d - IslamicEpoch ) / 355;
             while ( d >= IslamicDate( 1, 1, year + 1 ) ) {
                 year++;
             }
             // Search forward month by month from Muharram
             month = 1;
             while ( d > IslamicDate( month, lastDayOfIslamicMonth( month, year ), year ) ) {
                 month++;
             }
             day = d - IslamicDate( month, 1, year ) + 1;
         }
     }


     // Computes the absolute date from the Islamic date.
     operator long()
     {
         return ( day                          // days so far this month
                  + 29 * ( month - 1 )         // days so far...
                  + month / 2                  //            ...this year
                  + 354 * ( year - 1 )         // non-leap days in prior years
                  + ( 3 + ( 11 * year ) ) / 30 // leap days in prior years
                  + IslamicEpoch );            // days before start of calendar
     }

     int getMonth()
     {
         return month;
     }

     int getDay()
     {
         return day;
     }

     int getYear()
     {
         return year;
     }

 };


static void gregorianToHijri(int  & month, int  &day, int  &year )
 {

     GregorianDate gregorian( month, day , year );
     long  absolute = gregorian;
     IslamicDate islamic( absolute );
      year =  islamic.getYear();
      month = islamic.getMonth();
      day = islamic.getDay();
 }

static void hijriToGregorian(int  & month, int &day, int &year )
 {

     IslamicDate myIslamic( month, day , year );
     long  absolute = myIslamic;
     GregorianDate mYGregorian( absolute );
      year =  mYGregorian.getYear();
      month = mYGregorian.getMonth();
      day = mYGregorian.getDay();
 }
