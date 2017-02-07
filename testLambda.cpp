#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>

int main(int argc, char *argv[])
{
   std::vector<int> c = {1, 2, 3, 4, 5, 6, 7};
   std::vector<std::string> s = { "one", "two", "three" };

   auto adder = [](auto op1, auto op2){ return op1 + op2; };

   std::cout << "int adder: " << std::accumulate(c.begin(), c.end(), 0, adder) << std::endl;
   std::cout << "str adder: " << std::accumulate(s.begin(), s.end(), std::string(""), adder) << std::endl;

   return 0;
}

