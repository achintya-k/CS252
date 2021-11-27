// montecarlo method of pi value estimation via Serial computation

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int i = 0;	
int number_of_points = 0;
int circle_count  = 0;

void exec()
{
 
    // do-while loop for user prompts
    do
	{
        printf("Enter a whole number for the number of points you would like to use to calculate the value of Pi using the Monte Carlo method: \n");
        scanf("%d", &number_of_points);  	
	}while (number_of_points < 1);
    
    for (i=0; i < number_of_points; i++)
    {	
        double X = (double)rand() / RAND_MAX; // randomly choosing values for X and Y
        double Y = (double)rand() / RAND_MAX;
        
        if (((X * X) + (Y * Y)) <= 1)
        {
            circle_count++;
        }
    }
    
    double pi = 4.0 * circle_count/number_of_points;
    
    printf("The approximate value of Pi for the desired amount of points (%d) is: %f\n", number_of_points, pi); 
}

int main()
{
    clock_t norm;
    norm = clock ();
    exec();
    norm = clock () - norm;
    double time_spent = ((double)norm) / CLOCKS_PER_SEC;
    printf("Time taken for execution: %f \n", time_spent);
    return 0;
}
