/*
This progrem is calculating a sin of an angle taken from the user. All the results are in RAD.
*/

#include <stdio.h>
#include <math.h>

#define EPSILON 0.000001

double my_sin(double x);


int main()
{
	double x;
	
	printf("Hello there! please enter your lucky number in the range [-25,25]\n");
	scanf("%lf", &x);

	if (x < -25 || x > 25){

		printf("This number is not valid\n");
		return 0;
	}

	printf("The sin of %f is %f\n", x, my_sin(x));
	printf("In according to the math libery, the sin of %f is %f\n", x, sin(x));

	return 0;
}

double my_sin(double x)
{
	double add = x;/*Initiating the first add at the series*/	
	int i = 1; /*Initiating the odd power of x*/
	int j = 0;/*Checking the sign of add: j false is negative, while j true is positive*/	
	double x2 = x*x;/*Will help to define 'taylor' indicator*/
	double sin = add, taylor = x2/((i+1)*(i+2)); /*Initiating the series*/
	 
	while (add >= EPSILON || add <= -EPSILON){
		add *= taylor;
		if(j){
			sin += add;
			j = 0;
		}
		else{
			sin -= add;
			j = 1;
		}

		i += 2;/*The next odd power of x*/
		taylor = x2/((i+1)*(i+2));/*The new addition to 'add' on the next iteration*/
	}
	
	return sin;	  
}



