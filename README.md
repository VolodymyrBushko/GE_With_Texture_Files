Install requirements Ubuntu 16/18/19 
====================================

sudo apt-get update  
sudo apt-get install git  
sudo apt-get install build-essential  
sudo apt-get install cmake  
sudo apt-get install freeglut3-dev  
  
Build project:  
================
git clone https://github.com/VolodymyrBushko/GameEngine.git  
cd GameEngine  
mkdir build  
cd build  
cmake ..  
make  
