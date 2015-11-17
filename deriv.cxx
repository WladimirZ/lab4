#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx,
           const double xmin)
{
   for(int i=0; i<N; i++)
       cout << i*dx + xmin << "\t" << p[i] << endl;
}

void fill (double* p, const int N, const double dx,
	   const double xmin)
{
    for (int i = 0; i<N; i++)
      p[i] = exp(-(i*dx-15)*(i*dx-15));
}

void deriv (double* p, const int N, const double dx)
{
    double a = p[0];
    double b;
    p[0] = p[1]/(2*dx);
    for (int i = 1; i<N-1; i++){
      b = p[i];
      p[i] = (p[i+1]-a)/(2*dx);
      a = b;
    }
    p[N-1] = -a/(2*dx);
}


int main(){
  const int N = 1024;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);

  fill (p, N, dx, xmin);
  deriv (p, N, dx);
  print(p,N,dx,xmin);

  return 0;
}
