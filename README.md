# MAX_Boiler_Control
Python and Arduino code for 433Mhz control of wireless boiler from Max Cube

Files include folders for Bootstrap switches which may or may not get used in the project. Web UI uses Bootstrap theme from the internet so a net connection is required. It may be possible to host the files locally on the RPi but I have not looked into this yet, This would probably speed up web page creation.

The config for the system is set up for my system but there is an Admin page that alows changing of most of the main settings. I need to add the weather location to that also. I am contemplating removing the variables from the database to a text file so making changes is less likely to break the DB.

To use just drop all the files and folders into a folder on the Pi. Mine goes in /home/pi/heating There is a launcher file I used this article on Instructibles to set that up. http://www.instructables.com/id/Raspberry-Pi-Launch-Python-script-on-startup/ 

I appologise for the file names as it was an evolving set of code and some of the file names are not optimal for understanding. A tidy up may be in it's future.
