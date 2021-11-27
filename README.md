# CS252 - Assignment
## Achintya K N - 191EC201

Problem statements chosen are,

## 1. Problem 2.24.

To write a program that copies the contents of one file to a destination file. This program works by first prompting the user for the name of the source and destination files. Write this program using either the POSIX or Windows API. Be sure to include all necessary error checking, including ensuring that the source file exists.

Once you have correctly designed and tested the program, if you used a system that supports it, run the program using a utility that traces system calls. Linux systems provide the strace utility, and macOs systems use the dtruss command. (The dtruss command, which actually is a front end to dtrace, requires admin privileges, so it must be run using
sudo.) These tools can be used as follows (assume that the name of the executable file is FileCopy):

Linux:
strace ./FileCopy

macos:
sudo dtruss ./FileCopy

Since Windows systems do not provide such a tool, you will have to trace through the Windows version of this program using a debugger.


## 2. Problem 4.24.

Finding Pi value using the mutlithreaded version of the Montecarlo algorithm. The technique works as follow, suppose you have a circle inscribed in a square, first, generate a series of random points as simple (x,y) coordinates. These points must fall within the Cartesian coordinates that bound the square. Of the total numberof random points that are generated, some will occur within the circle.

Next, estimate x by performing the following calculation:
= 4x (number of points in circle) / (total number of points)

Write a multithreaded version of this algorithm that creates a separate thread to generate a number of random points. The thread will count the number of points that occur within the circle and store that result in a global variable. When this thread has exited, the parent thread will calculate and output the estimated value of x. Its worth experimenting with the number of random points generated. As a general rule, the greater the number of points, the closer the approximation to x.
