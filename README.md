# Wator
<center>Software Development Year 4 Project<br />
Concurrent Device Development Module<br />
Continous Assessment 1<br /> 
Daniel Hayden & Frank Rooney<br /></center>

See more information about the project below the image:
![My image](https://github.com/Sledro/Wator/blob/master/images/preview.png)


# Problem

Re-create the famous Wa-Tor program in Serial C++ then Concurrently 

Read the original Wator Project paper here: https://github.com/josephkehoe/CDD101/blob/master/Concurrency/project/wator_dewdney%20(1).pdf


# Setup

We decided to use the SFML graphics library over just OpenGL alone as it gives more options.

To install SFML on UBUNTU:

sudo apt-get install libsfml-dev

Download SFML, Open the downloaded directory in terminal, enter:

$ sudo cp -r include/SFML /usr/include<br /> 
$ sudo cp -r /lib/* /usr/lib <br />
$ sudo cp -r share/SFML /usr/share<br />

This will add the libraries to your HDD and allow you to comiple the Wator program.


# Run Program

To compile the program, open the repo in the command prompt and type "make"

To clean/remove the object files type "make clean"

To run the program once compiled, type "./main"

# To install profiling tools:

sudo apt-get update<br />
sudo apt install valgrind<br />
sudo apt install kcachegrind<br />
<br />
see profile.sh for more info<br />

# To run the profiling tools:

chmod 755 ./profile.sh first to run this file via command line.<br />
Enter "./profile.sh" in the terminal to run<br />
This file will clean, build and run the program and produce a valgrind profiling report<br />
on compleation the valgrind report can be viewed with kcachegrind GUI tool<br />
