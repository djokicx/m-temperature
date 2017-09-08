/* Author:  Dejan Djokic
 * Date:    5 Semptember 2014
 * File:    temperature.c
 * Purpose: Predicting the temperatures on a metal at each vertex of the grid for each time of interest
 *
 * Input:   m, n, i, j, d, h, t_j, new_u[MAX], old_u[MAX];
 * Output:  Temperature estimates printed for each time of interest
 *
 * Compile: gcc -g -Wall -o temp temperature.c
 * Run:     ./temp
 */
#include <stdio.h>

void print(double t_j, int m, double array[]);
void copy(int m, double new_u[], double old_u[]);
/* Functions we are integrating */

int main(void) {
    const int MAX = 101;
    int m, n, i, j;
    double d, h, t_j;
    double new_u[MAX], old_u[MAX];

    printf("Please enter the number of segments: ");
    scanf("%d", &m);
    printf("Please enter the number of intervals: ");
    scanf("%d", &n);
    d = 1.0 / n;
    h = 1.0 / m;

   /* Scans in the temperatures */
    printf("Please enter your temperatures:\n");
    for(i = 0; i < m; i++) {
        scanf("%lf", &old_u[i]);
    }
	old_u[0] = old_u[m] = 0;
    print(0.0, m, old_u);
    for(j = 1; j <= n; j++) {
        t_j = j * d;
        new_u[0] = new_u[m] = 0.0;
        for(i = 1; i < m; i++) {
            new_u[i] = old_u[i] + d / (h * h) * (old_u[i-1] - 2 * old_u[i] + old_u[i + 1]);
        }
        print(t_j, m, new_u);
        copy(m, new_u, old_u);
    }
    return 0;
}/* main */
/*------------------------------------------------------------------
* Function: print
* Purpose:  Prints an array
* Inp args: t_j       current time
*		    m         number of segments
*			array[]   array that needs to be printed
*/
void print(double t_j, int m, double array[]) {
   int i = 0;
   printf("%.3f.\t", t_j);
   for(i = 0; i < m + 1; i++) {
        printf("%.3f.", array[i]);
    }
    printf("\n");
}
/*------------------------------------------------------------------
* Function: copy
* Purpose:  Copies one array to another
* Inp args: m         number of segments
*    		new_u[]   source array
*			old_u[]   array elements are getting copied into
*/
void copy(int m, double new_u[], double old_u[]) {
	int i = 0;
	for(i = 0; i < m + 1; i++) {
		old_u[i] = new_u[i];
	}
}
