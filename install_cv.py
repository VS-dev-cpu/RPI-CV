echo "Installing OpenCV Python Libraries"

sudo apt install git
sudo apt install pip

sudo pip3 install opencv-contrib-python
sudo pip3 install pyserial

cd ..
mv rpi-cv rpi
mv rpi-bt/* rpi

systemctl stop serial-getty@ttyS0.service

echo "Remove the first two chunks from '/boot/cmdline.txt' to make communication work!"
