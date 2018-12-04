#include <stdlib.h>
#include "IntegerSetHT_iterator.h"

int main()
{
    using namespace ece309;
 IntegerSetHT set;
set.insert(5);
set.insert(99);
set.insert(0);
IntegerSetHT::iterator sit = set.begin();
while( !sit.end())
{
   printf("%d ", sit.getInt()); 
   sit.increment();
}
}
