#include "Plist.h"
int main()
{
PList l;
Item* item = new IntItem(3);
Item* item2 = new StringItem("malk");
Item* item3 = new DoubleItem(1.05);
  l.append(item);
  l.append(item2);
  l.append(item3);
  
/*
    PList::iterator it0 = l.begin();
        while(!it0.end()){
            Item *copy = it0.getItem();
            printf("Next thing in list: ");
            copy->print();
            it0.increment();
        }
    
    PList::reverse_iterator rit = l.rbegin();
        while(!rit.rend()) {

            Item *item = rit.getItem();
            printf("Next thing in list: ");
            item->print();
            rit.decrement();
        }*/
    Item* item4 = new StringItem("test");
    l.append(item4);
    if(l.remove(item4)==1)
        printf("removed\n");

    PList::iterator it = l.begin();
        Item *copy = it.getItem();
        printf("Next thing in list is: ");
        copy->print();
        it.increment();
        copy = it.getItem();
        printf("Next thing in list is: ");
        copy->print();
        it.increment();
        copy = it.getItem();
        printf("Next thing in list is: ");
        copy->print();
        it.increment();
        copy = it.getItem();
        printf("Next thing in list is: ");
        copy->print();



  return 0;
}