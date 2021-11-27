/* multithreaded version of the Monte Carlo method to find the value of Pi 
Achintya K N - 191ec201
*/

#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int i = 0;	
int number_of_points = 0;
int circle_count  = 0;

unsigned int seed = 2;

// Random number generation using Linear Congruency when threads are involved
double Randint (long i)
{
  seed = seed * 1103515245 + 123456;

  return seed / (double)UINT_MAX;
}

// counts the number of randomly initialized points that fell inside the unit circle inscribed in the 1*1 square
void *count(void *X)
{ 
    /* initialize random numbers */
    for (i=0; i < number_of_points; i++)
    {	
        double X = (double) Randint(i); // randomly choosing values for X and Y
        double Y = (double) Randint(i);
        
        if (((X * X) + (Y * Y)) <= 1)
        {
            circle_count++;
        }
    }
    pthread_exit(0);
}

void exec()
{
    int count_norm = 0;
    pthread_t thread;

    // do-while loop for user prompts
    do
	{
        printf("Enter a whole number for the number of points you would like to use to calculate the value of Pi using the Monte Carlo method: \n");
        scanf("%d", &number_of_points);  	
	}while (number_of_points < 1);
  
    pthread_create(&thread, NULL, &count, NULL); // creating a pthread which parallelly computes the number of points that fall in the unit circle
    pthread_join(thread, NULL); // this waits for the termination of the above thread
    
    double pi = 4.0 * circle_count/number_of_points;
    
    printf("The approximate value of Pi for the desired amount of points (%d) is: %f (multithreaded version) \n", number_of_points, pi); 
}

int main()
{
    // mainly calculating time spent for execution in the main function	
    clock_t multi;
    multi = clock ();
    exec();
    multi = clock () - multi;
    double time_spent = ((double)multi) / CLOCKS_PER_SEC;
    printf("Time taken for execution: %f \n", time_spent);
    return 0;
}
