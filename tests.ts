// tests go here; this will not be compiled when this package is used as a library
{
	basic.forever(() => {
    	basic.showNumber(Time.getTimePart(DateTimePart.Seconds))
	})

}