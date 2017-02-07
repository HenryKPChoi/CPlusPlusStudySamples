#include <stdio.h>
#include <stdlib.h>
#include <iostream>

auto foo(int type)
{
   if (type == 0)
      return 1;
   else
      return 1.0;
}

int main (int argc, char *argv[])
{
   auto abc = foo(0);
   auto def = foo(1);
   std::cout << abc << std::endl;

   return 0;
}
