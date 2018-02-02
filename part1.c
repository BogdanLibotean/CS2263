#include <stdlib.h>
#include <stdio.h>

void avgSum(double a[], int n, double *avg, double *sum);

void avgSum(double a[], int n, double *avg, double *sum){
	*sum = 0.0;
	for(int i=0; i<n; i++) {
		*sum += a[i];
	}
	*avg = *sum/n;
}

int main(){
	int n = 5;
	double a[] = {1,2,3,4,5};
	double avg = 0;
	double sum = 0;

	avgSum(a, n, &avg, &sum);
	printf("%f\n%f", avg, sum);
	return EXIT_SUCCESS;
}