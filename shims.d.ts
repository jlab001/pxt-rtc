// Auto-generated. Do not edit.



    //% color=80 weight=80
    //% icon="\uf017"
declare namespace Time {

    /**
     * gets the current time.
     */
    //% blockId=rtc_ds_get_time
    //% block="the current time" shim=Time::getCurrentTime
    function getCurrentTime(): string;

    /**
     * gets the current unix timestamp.
     */
    //% blockId=rtc_ds_get_unixtime
    //% block="the current unix timestamp" shim=Time::getUnixTimestamp
    function getUnixTimestamp(): number;

    /**
     * gets the current datetimepart.
     */
    //% blockId=rtc_ds_get_part
    //% block="the current %part" shim=Time::getTimePart
    function getTimePart(part: DateTimePart): number;

    /**
     * sets the current time.
     */
    //% blockId=rtc_ds_set_unixtime
    //% block="set unix time to |%uxtime" shim=Time::setUnixTime
    function setUnixTime(uxtime: number): void;

    /**
     * sets the current datetimepart.
     */
    //% blockId=rtc_ds_set_part
    //% block="set the current %part| to |%val" shim=Time::setTimePart
    function setTimePart(part: DateTimePart, val: number): void;
}

// Auto-generated. Do not edit. Really.
