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
  const int empty_since_start = -1;
  const int empty_after_removal = -2;
public:
   IntegerSetHT(int htsize = 1000);
   virtual bool insert(int) override;

public:
   class iterator {
    private:
        int i;
        IntegerSetHT * owner;
        int * arr;
        int size;
    public:
        iterator(IntegerSetHT * owner) {
            owner = owner; 
            i = 0; 
            arr = owner->table; 
            size = owner->size;
            printf("\n%d\n", size);
            }
        int getInt(){
            return arr[i];
        }
        void increment(){
            i++;
            while(arr[i] < 0)
                i++;
            return;
        }
        bool end(){
            return (i >= (size - 1));
        }
    friend class IntegerSetHT;
   };
    iterator begin(){
       return iterator(this);
   }
};
IntegerSetHT::IntegerSetHT(int htsize)
:IntegerSet(htsize)
{
  probeDistance = 20;
   table = new int[size];
   for(int i=0; i<size; i++)
      table[i] = empty_since_start;  // -1 means empty
}

bool IntegerSetHT::insert(int data)
{ 
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
   index = (index+1) % size;
  }
  // otherwise give up
   return false;
}
