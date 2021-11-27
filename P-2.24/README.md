# Problem 2.24 
The code file filecopy.c, the text file used for reading, corresponding output files and the strace log file have been included in this repository.

The program first prompts the user to enter read and write files' names and does the necessary error checking for the same followed by the copying of the contents of the source into the destination. The system calls involved during the execution of the program is recorded using `Strace` and saved in `log`.

### Steps to follow during execution of the code
1. Compiled the code on the command line: `gcc filecopy.c -o filecopy.o`
2. Executed program: `./filecopy.o`
3. Enter source and destination file names. (ensure that the source is in the same directory as the code file)
4. Now, to view the system calls, type `strace -olog ./filecopy.o` on the command line.

### Results
1. Below is the screen dump of the Linux command line briefly showing the commands executed,
![image](https://user-images.githubusercontent.com/67586625/143709696-a1fb8d01-e7da-4aff-95ed-d7fbb03a993c.png)

2. And shown below is the output and the contents of the write.txt file created as part of the code execution.
![image](https://user-images.githubusercontent.com/67586625/143712908-336cf13c-5816-4993-8799-0af6036dfa58.png)

3. The code is written such that a new file name needs to be given as the write file destination so as to avoid overwriting of data. 
4. This error case is taken care of in the code and below is the screen dump of the same. (executed after write.txt was already created)
![image](https://user-images.githubusercontent.com/67586625/143715874-ef45c906-cd2d-4dd0-b53c-ded4aa8cc380.png)

Finally the strace log file was created using the command mentioned above which is saved in `log` which is included in this repository.
### References
https://github.com/mattlevan/copy.c (code has been taken from here)
