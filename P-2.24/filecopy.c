/* Problem 2.24
Achintya K N
191EC201
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

// function which checks if a file of the given filename exists or not using file pointers
bool file_exists(char *file_name) {
    FILE *file_ptr = fopen(file_name, "r");

    if (!file_ptr) {
        return false;
    }

    return true;
}

void copy(char *out, char *in) {
    // int c to store one character at a time during copy operation
    int c;
    
    // declare and open files for the copy operation
    FILE *fptr1 = fopen(in, "r");
    FILE *fptr2 = fopen(out, "w");


    if (!fptr1) {
        perror("Source file can't be opened: ");
        exit(1);
    }

    if (!fptr2) {
        perror("Destination file can't be opened: ");
        exit(1);
    }
    
    // copy file one char at a time 
    while ((c = fgetc(fptr1)) != EOF) {
        fputc(c, fptr2);
    }

    // printing success message to notify the user 
    printf("\nContents copied!\n");

    // close files
    fclose(fptr1);
    fclose(fptr2);
}

int main() { 
    char temp[32], in_str[32], out_str[32];  
    // initializing pointers for each string variable used to store filenames
    char *temp_ptr = temp; // buffer variable to hold the filename scanned when the file existence will be checked
    char *in_ptr = in_str;
    char *out_ptr = out_str;

    // user prompt to get source file name and also check whether it exists
    // loop created so as to keep asking the user for inputs until a valid input file name is given
    while (strcmp(in_str, "")) { // loop terminates as soon as a valid file name gets scanned for the input variable
        printf("Enter file name for reading : ");
        scanf("%s", temp_ptr);
        
        if (file_exists(temp_ptr)) {
            strcpy(in_str, temp);
            break;
        }
        else {
            printf("File %s can't be opened, invalid file name.\n", temp);
            continue;
        }
    }

    // user prompt to get destination file name and also check whether it exists
    // similar working as it was for the source file name input
    while (strcmp(out_str, "")) { 
        printf("Enter name of destination file: ");
        scanf("%s", temp_ptr); 
        
        if (!file_exists(temp_ptr)) {
            strcpy(out_str, temp);
            break;
        }
        else {
            printf("File %s already exists, please give a new filename to copy the source file contents into.\n", temp);
            continue;
        }
    }

    copy(out_str, in_str); // function call to carry out the copy operation
    
    return 0;
}
