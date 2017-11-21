# Wator
<center>Software Development Year 4 Project<br />
Concurrent Device Development Module<br />
Continous Assessment 1<br /> 
Daniel Hayden & Frank Rooney<br /></center>

# Problem

Re-create the famous Wa-Tor program in Serial C++

Source: https://github.com/josephkehoe/CDD101/blob/master/Concurrency/project/wator_dewdney%20(1).pdf


# Setup

We decided to use the SFML graphics library over just OpenGL alone as it gives more options.

To install SFML on UBUNTU:

sudo apt-get install libsfml-dev

Download SFML, Open the downloaded directory in terminal, enter:

$ sudo cp -r include/SFML /usr/include $ sudo cp -r /lib/* /usr/lib $ sudo cp -r share/SFML /usr/share

This will add the libraries to your HDD and allow you to comiple the Wator program.


# Run

To compile the program, open the repo in the command prompt and type "make"

To clean/remove the object files type "make clean"
