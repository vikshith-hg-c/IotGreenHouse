import RPi.GPIO as GPIO
import dht11
import time
import datetime

# initialize GPIO
GPIO.setwarnings(True)
GPIO.setmode(GPIO.BCM)

# read data using pin 14
instance = dht11.DHT11(pin=14)

try:
    now = datetime.datetime.now()
    result = instance.read()
    temp = result.temperature
    hum = result.humidity
    if result.is_valid():
            print"Date","\t\tTime","\t\t","Temperature","\t\t","Humidity"
            print(now.strftime("%d-%m-%Y \t%H:%M:%S")),"\t",temp,"C","\t\t\t",hum,"%"
            
	      
    else:
           print "hii"
	
	
    
except KeyboardInterrupt:
    
    GPIO.cleanup()
