
ip addr show wlan0 | grep inet &
ip addr show enxb827ebbe96d9| grep inet &



while((1 <2 ))
do	
raspistill -q 10 -o display.jpg 
python th.py > th.txt
sleep 5
done

