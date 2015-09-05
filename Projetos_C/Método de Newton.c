// Implementation of the Newton algorithm in C

#include <stdio.h>
#include <math.h>

double newton(double x_0, double tol, int max_iters,
          int* iters_p, int* converged_p);
double f(double x);
double f_prime(double x);

int main() {
   double x_0;       /* Initial guess                */
   double x;         /* Approximate solution         */
   double tol;       /* Maximum error                */
   int    max_iters; /* Maximum number of iterations */
   int    iters;     /* Actual number of iterations  */
   int    converged; /* Whether iteration converged  */

   printf("Enter x_0, tol, and max_iters\n");
   scanf("%lf %lf %d", &x_0, &tol, &max_iters);

   x = newton(x_0, tol, max_iters, &iters, &converged);

   if (converged) {
    printf("Newton algorithm converged after %d steps.\n",
         iters);
    printf("The approximate solution is %19.16e\n", x);
    printf("f(%19.16e) = %19.16e\n", x, f(x));
   } else {
    printf("Newton algorithm didn't converge after %d steps.\n",
          iters);
    printf("The final estimate was %19.16e\n", x);
    printf("f(%19.16e) = %19.16e\n", x, f(x));
  }

   return 0;
}  /* main */


double newton(double x_0, double tol, int max_iters,
          int* iters_p, int* converged_p) {
   double x = x_0;
   double x_prev;
   int    iter = 0;

   do {
      iter++;
      x_prev = x;
      x = x_prev - f(x_prev)/f_prime(x_prev);
   } while (fabs(x - x_prev) > tol && iter < max_iters);

   if (fabs(x - x_prev) <= tol)
      *converged_p = 1;
   else
      *converged_p = 0;
   *iters_p = iter;

   return x;
}  /* newton algorithm */


double f(double x) {
   return x*x-2;
}  /* f */

double f_prime(double x) {
   return 2*x; //the derivative
}  /* f_prime */
