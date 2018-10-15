#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class IntegerSet {
protected:
   int size;
   int hash(int key) const { return (key * 997) % size; }
public:
   IntegerSet(int htsize):size(htsize) {}
   virtual bool insert(int) = 0;
};

// Hash Table with Linear Probing
class IntegerSetHT : public IntegerSet {
protected:
  int *table;
  int probeDistance;
  const int empty_since_start = -2;
  const int empty_after_removal = -1;
public:
   IntegerSetHT(int htsize);
   virtual bool insert(int) override;
   int collisions;
   int failures;
};
IntegerSetHT::IntegerSetHT(int htsize)
:IntegerSet(htsize)
{
  probeDistance = 20;
   table = new int[size];
   for(int i=0; i<size; i++)
      table[i] = empty_since_start;  // -1 means empty
    collisions = 0;
    failures = 0;
}

bool IntegerSetHT::insert(int data)
{
  int before = collisions;
  int index = hash(data);
  int bucketsProbed = 0;
  while( bucketsProbed++ < probeDistance )
  {
   if ( table[index] < 0 )
   {
     // if the entry is not being used, put the
    // data there
     table[ index ] = data;
     return true;
   }
   if(collisions==before)
        collisions++;
   index = (index+1) % size;
  }
  // otherwise give up
   failures ++;
   return false;
}
int main()
{
    IntegerSetHT a(1000);
    srand(time(NULL));

    for(int i = 0; i<500; i++)
        a.insert(rand());
    printf("\nCollisons = %d, Failures = %d",a.collisions, a.failures);

}