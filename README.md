# Ezviz_RC3_IRremote
Publishing the Ezviz RC3 remote control IR codes for the main functions of the robot.

I bought a Ezviz RC3 robot, and since I the robot does not feature any internet connectivity (on purpose...), I decided to clone the remote so that I can make a "piggyback" Arduino-compatible wifi module installed directly inside the unit, that can receive commands from wifi/the internet and translate them to the appropriate IR commands for the robot.

In the meantime, I decided that these IR codes might be useful for anyone else, that might be missing the remote/it's broken, and still want to keep access to the device, so I'm publishing them here. This way, with any Arduino board at your disposal, you too can clone the remote.

### Note:
I tried decoding the data for sending current date/time and cleaning hours, but I couldn't find an appropriate match. I didn't bother insisting since my technique will allow me to use the Arduino itself as the cleaning scheduling manager.
