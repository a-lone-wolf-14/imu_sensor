First of all download the VSPE (Virtual Serial Port Emulator) from the ZIP folder according to the architecture of your computer, then 'continue with limtitations' (becasuse we are gareeb).

Then from the top bar, create a new device

![image](https://github.com/user-attachments/assets/7f8de176-318a-433b-b64e-dc537d7ba290)

In the menu, select the device type as 'Virtual Connector' and then select the Virtual COM Port as 'COM10' (for this case) and then click finish.

![image](https://github.com/user-attachments/assets/8153617e-4e61-46df-8f33-33213a428f98)

![image](https://github.com/user-attachments/assets/4a6dceea-8482-4dc6-8cf5-852cb1dd8513)

When you get the message that the device was created then start its emulation

![image](https://github.com/user-attachments/assets/9cc7deda-cdf8-44f9-82c8-4b38db20a572)

Then you will get the messaage that the emulation for the selected device has started successfully.

Then you have to run the imu_sensor.py file with the function imu_sensor and its calling, commented out, to check if the COM10 port was available. There will be a message 'COM10 - Eterlogic Virtual Serial Port (COM10)'.
Then afterwards, run the whole file (without any commented out) and you will be sending the required values over from the COM10 port. 

Now all you have to do is run the Qt project after opening it formally from the 'Open Project' option in the Qt creator and then selecting the Qt Project File.
