#include <stdio.h>
#include <stdlib.h>
#include <iostream>

template<class T>
class FunClass
{
public:
   FunClass(const T &&mem) :
      _mem(mem)
   {
   };

   virtual ~FunClass() {};

   void run(void)
   {
      std::cout << _mem;
      std::cout << std::endl;
   }

private:
   FunClass(){};
   T _mem;
};

int main (int argc, char *argv[])
{
   FunClass<double> abc(10.5);
   abc.run();

   return 0;
}

