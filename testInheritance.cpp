#include <stdio.h>
#include <stdlib.h>
#include <vector>

class BasicMsg
{
public:
   BasicMsg() {};
   virtual ~BasicMsg(){};

   virtual bool Process(){};
private:
};

class MessageA : public BasicMsg
{
public:
   MessageA () {};
   virtual ~MessageA() {};
   virtual bool Process()
   {
      printf ("Message A\n");
   };
private:
};

class MessageB : public BasicMsg
{
public :
   MessageB() {};
   virtual ~MessageB() {};
   virtual bool Process()
   {
      printf ("Message B\n");
   }
private :
};

class MsgDispatcher
{
public :
   MsgDispatcher (){};
   virtual ~MsgDispatcher() {};
   void dispatch (BasicMsg &msg)
   {
      msg.Process();
   }
private :
};

enum class Sex { man, women };

int main (int argc, char *argv[])
{
   MessageA msgA;
   MessageB msgB;
   MsgDispatcher dispatcher;

   dispatcher.dispatch(msgA);
   dispatcher.dispatch(msgB);

   Sex sex = Sex::man;

   return 0;
}

