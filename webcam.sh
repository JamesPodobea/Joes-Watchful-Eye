#!/bin/bash

DATE=$(date +"%Y-%m-%d_%H%M")

fswebcam -r 1280x720 --no-banner /home/pi/Pictures/$DATE.jpg

mpack -s $DATE /home/pi/Pictures/$DATE.jpg brute.softworks@gmail.com

echo "email sent"
