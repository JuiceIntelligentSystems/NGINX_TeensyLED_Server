# NGINX_TeensyLED_Server
This is a NGINX web server meant to be run on a RPi 4b to control a LED's brightness on a Teensy 4.0.

How it works:
- The web server is run through NGINX in which the data from the slider gets written to a JSON file.
- The server reads the JSON file and prints the output every 5 seconds (for debugging).
- The main.cpp file parses the json file and reads it, catching any reading errors and prints it to the console.
- The RPi communicates with the teensy through I2C (I2C_1 on RPi and pins 18-19 on Teensy).

How to run:
- Compile the main.cpp with c++17 and make sure to include -ljsoncpp and -lwiringPi
- Setup NGINX with php7.4-fpm
- Copy all files in "main" to /var/www/html
- Restart NGINX with "sudo systemctl reload nginx"
- Upload program to Teensy
- Connect the I2C lines of Teensy to RPi
- Make sure to enable I2C through raspi-config
- Connect to the Pi's local IP address (Can be found through ifconfig)

The webpage should look like this:

![Screenshot from 2023-07-25 11-30-29](https://github.com/JuiceIntelligentSystems/NGINX_TeensyLED_Server/assets/129092528/d542d279-a573-457b-9086-364331e2158d)
