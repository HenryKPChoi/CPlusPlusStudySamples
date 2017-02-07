#include <memory>
#include <iostream>

class Foo
{
public:
   Foo()      { std::cout << "Foo::Foo()" << std::endl; };
   ~Foo()     { std::cout << "Foo::~Foo()" << std::endl; };
   void bar(const std::string &a) { std::cout << "Foo::bar() " << a << std::endl; };
};

int main (int argc, char *argv[])
{
   std::unique_ptr<Foo> p1(new Foo);

   if (p1)
      p1->bar(std::string("p1"));

   {
      std::unique_ptr<Foo> p2 (std::move(p1));
      if (p1)
         p1->bar(std::string("p1 is still here after move!!!!"));
      
      p1 = std::move(p2);
      std::cout << "p2 end..." << std::endl;

      if (p2)
         p2->bar(std::string("p2 still alive???"));
   }

   if (p1)
      p1->bar(std::string("everything end"));

   return 0;
}
