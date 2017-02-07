#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

template<long long n>
struct Factorial {
   enum { value = n * Factorial<n-1>::value };
};
template<>
struct Factorial<0> {
   enum { value = 1 };
};

template<typename T>
class Factorial2
{
public :
   Factorial2(){};
   ~Factorial2(){};
   
   void setN(int n)
   {
      _n = n;
      _ret = 1;
   }

   void calc(void)
   {
      _ret = _i * _ret;
      _i++;
      if (_i < _n)
         calc();
   }

   T getResult(void)
   {
      return _ret;
   }


private:
   int _i;
   int _n;
   T _ret;
};

template<typename T>
T factorial3(int n)
{
   if (n==0)
      return 1;

   return n*factorial3<T>(n-1);
}

long double factorial4(int n)
{
   long double *mem = (long double *) malloc (sizeof(long double) * n);
   long double result = 0;
   int i;
   mem[0] = 1;
   for (i=1; i<n; i++)
   {
      mem[i] = mem[i-1]*i;
//      printf ("%d: %Lf\n\n", i, mem[i]);
   }
   result = mem[n-1];

   free(mem);
   return result;
}

template<typename T>
T farbon(int n)
{
   if (n == 0)
      return 0;
   else if (n == 1)
      return 1;
   return farbon<T>(n-1) + farbon<T>(n-2);
}

long double farbon2(int n)
{
   long double *mem = (long double *) malloc (sizeof(long double ) * n);
   long double ret = 0;
   int i;
   
   mem[0] = 0;
   mem[1] = 1;
   for (i = 2; i < n; i++)
   {
      mem[i] = mem[i-1] + mem [i-2];
//      printf ("%d: %.0Lf\n", i, mem[i]);
   }
   ret = mem[n-1];
   free(mem);

   return ret;
}

int main (int argc, char *argv[])
{
   printf("%.0Lf\n",factorial4(1500));
   printf("\n");
   printf("%.0Lf\n",farbon2(18181));

   return 0;
}
