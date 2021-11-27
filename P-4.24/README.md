# Problem 4.24
The code file and the output file have been included in this repository.

The Program uses the Monte carlo method which essentially randomly generates so and so numbers and then counts the number of points that fall in the circle inscribed inside the unit square and uses this ratio to calculate the value of Pi (4 x this ratio).
The program also uses multithreading to separately run the counting part on a different thread.

### Steps to follow during execution
1. Type the command `gcc montecarlo-multithreading.c -o mc-mt.o -lpthread` on the Linux command line.
2. Execute the program: `./mc-mt.o`

### Results and inferences
1. Shown below is the screen dump of a test case.
![image](https://user-images.githubusercontent.com/67586625/143718808-ffe77118-c7f2-4759-9391-0c50f78fdc40.png)

2. Error with the actual Pi value to 6 digits is found to be *0.000032*.
3. Time of execution is *1.737739s* using multithreading and the time required for the same input without multithreading was found to be *3.084187s*.

### References
1. https://github.com/SeanStaz/monteCarloMethod.c

