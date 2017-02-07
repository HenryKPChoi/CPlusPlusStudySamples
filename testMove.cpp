#include <memory>
#include <iostream>

int main(int argc, char *argv[])
{
   std::unique_ptr<int> p(new int);

   *p = 5;

   std::cout << "before move: " << *p << std::endl;

   auto y = [p=std::move(p)]() { std::cout << "inside move :" << *p << std::endl; };

   y();
   std::cout << "after move: " << *p << std::endl;

  return 0;
}
