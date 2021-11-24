/* multithreaded version of the Monte Carlo method to find the value of Pi */

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int i = 0;	
int number_of_points = 0;
int circle_count  = 0;

void *count(void *X)
{ 
    /* initialize random numbers */
    for (i=0; i < number_of_points; i++)
    {	
        double X = (double)rand() / RAND_MAX;
        double Y = (double)rand() / RAND_MAX;
        
        if (((X * X) + (Y * Y)) <= 1)
        {
            circle_count++;
        }
    }
    pthread_exit(0);
    return NULL;
}

int main()
{
    srand(time(NULL));
    clock_t begin = clock();
    pthread_t thread;

    do
	{
        printf("Enter a whole number for the number of points you would like to use to calculate the value of Pi using the Monte Carlo method: \n");
        scanf("%d", &number_of_points);  	
	}while (number_of_points <= 0);
  
    pthread_create(&thread, NULL, &count, NULL);
    pthread_join(thread, NULL);
    
    double pi = 4.0 * circle_count/number_of_points;
    clock_t end = clock();
    double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;

    printf("The approximate value of Pi for the desired amount of points (%d) is: %f \n", number_of_points, pi); 
    printf("Time taken for execution: %f \n", time_spent);
    return 0;
}