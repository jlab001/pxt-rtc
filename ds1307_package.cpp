// Documentation on defining PXT blocks:
// https://www.pxt.io/defining-blocks

#include "pxt.h"
#include "DS1307.h"
using namespace pxt;

enum class DateTimePart{
  Seconds = 0,
  Minutes = 1,
  Hours = 2,
  Day = 3,
  Month = 4,
  Year = 5
};

//% color=80 weight=80
//% icon="\uf017"
namespace Time {

  DS1307 rtc(&(uBit.i2c));

  /**
  * gets the current time.
  */
  //% blockId=rtc_ds_get_time
  //% block="the current time"
  StringData* getCurrentTime() {
    DateTime now = rtc.now();
    char buf[30];
    sprintf(buf, "%2d/%d/%d %.2d:%.2d:%.2d", now.day(), now.month(), now.year(), now.hour(), now.minute(), now.second());
    return ManagedString(buf).leakData();
  }

  /**
  * gets the current unix timestamp.
  */
  //% blockId=rtc_ds_get_unixtime
  //% block="the current unix timestamp"
  int getUnixTimestamp(){
    return rtc.now().unixtime();
  }

  int getHour(){ return rtc.now().hour(); }
  int getMinutes(){ return rtc.now().minute(); }
  int getSeconds(){ return rtc.now().second(); }
  int getYear(){ return rtc.now().year(); }
  int getMonth(){ return rtc.now().month(); }
  int getDay(){ return rtc.now().day(); }

  /**
  * gets the current datetimepart.
  */
  //% blockId=rtc_ds_get_part
  //% block="the current %part"
  int getTimePart(DateTimePart part){
    switch (part){
      case DateTimePart::Seconds:
        return getSeconds();
        break;
      case DateTimePart::Minutes:
        return getMinutes();
        break;
      case DateTimePart::Hours:
        return getHour();
        break;
      case DateTimePart::Day:
        return getDay();
        break;
      case DateTimePart::Month:
        return getMonth();
        break;
      case DateTimePart::Year:
        return getYear();
        break;
    }
    return -1;
  }

  /**
  * sets the current time.
  */
  //% blockId=rtc_ds_set_unixtime
  //% block="set unix time to |%uxtime"
  void setUnixTime(int uxtime){
    rtc.adjust(DateTime(uxtime));
  }

  void setHour(int hr){ DateTime now = rtc.now(); rtc.adjust(DateTime(now.year(), now.month(), now.day(), hr, now.minute(), now.second())); }
  void setMinutes(int min){ DateTime now = rtc.now(); rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour(), min, now.second())); }
  void setSeconds(int sec){ DateTime now = rtc.now(); rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour(), now.minute(), sec)); }
  void setYear(int year){ DateTime now = rtc.now(); rtc.adjust(DateTime(year, now.month(), now.day(), now.hour(), now.minute(), now.second())); }
  void setMonth(int mth){ DateTime now = rtc.now(); rtc.adjust(DateTime(now.year(), mth, now.day(), now.hour(), now.minute(), now.second())); }
  void setDay(int day){ DateTime now = rtc.now(); rtc.adjust(DateTime(now.year(), now.month(), day, now.hour(), now.minute(), now.second())); }

  /**
  * sets the current datetimepart.
  */
  //% blockId=rtc_ds_set_part
  //% block="set the current %part| to |%val"
  void setTimePart(DateTimePart part, int val){
    switch (part){
      case DateTimePart::Seconds:
        setSeconds(val);
        break;
      case DateTimePart::Minutes:
        setMinutes(val);
        break;
      case DateTimePart::Hours:
        setHour(val);
        break;
      case DateTimePart::Day:
        setDay(val);
        break;
      case DateTimePart::Month:
        setMonth(val);
        break;
      case DateTimePart::Year:
        setYear(val);
        break;
    }
  }
}