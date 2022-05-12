echo "Installing OpenCV Python Libraries"

sudo apt install pip

sudo apt install libglew-dev

sudo pip3 install opencv-contrib-python

cd ..
mv rpi-cv rpi
mv rpi-bt/* rpi
sudo rm -R rpi-bt

systemctl stop serial-getty@ttyS0.service

echo "Remove the first two chunks from '/boot/cmdline.txt' to make communication work!"
