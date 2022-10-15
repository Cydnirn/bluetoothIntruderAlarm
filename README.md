# bluetoothIntruderAlarm
Silly side project to test Bluetooth HC-06 module with static buzzer

# How
It works by storing a type char command from bluetooth HC-06 into a temporary string variable
Then if there is a new command, the temporary string variable will rewrite the command string variable
The temporary string, as the name suggest, will be deleted on every loop
