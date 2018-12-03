//PList.h
#include <stdio.h>
// Hold a string, integer, or a double depending on the type created.

namespace ece309 {

class Item {
public:
    virtual void print(){ printf("Item\n"); }
};

class StringItem : public Item {
    public: 
        const char * str;
        StringItem(const char *as = ""){ str = as; }
        void print(){ printf("%s\n", str); }
  };

class IntItem : public Item {
    public: 
        int x;
        IntItem(int a = 0){ x = a; }
        void print(){ printf("%d\n", x); }
  };

  class DoubleItem : public Item {
    public: 
        double y;
        DoubleItem(double b = 0.00){ y = b; }
        void print(){ printf("%.2f\n", y); }
  };

class PList {
    private:
        class ListNode {
        public:
            Item *item; // data in the list
            ListNode *next;
            ListNode *last;
            
        public:
            ListNode(Item *a, ListNode *n);/*{
                item = a;
                next=n; // automatically serves as a list tail
            }*/
            ListNode* getNext(); //{ return next; }
            void setNext(ListNode *n);//{ next = n; }
            Item* getItem();//{ return item; }
        };

    // add head and tail pointer
    ListNode *head;
    ListNode *tail;
    
    public:
        class iterator {
        private:
            ListNode *node;
        public:
            iterator(ListNode *n= NULL ) { node = n; }
            Item *getItem() { return node->getItem(); }
            void increment() { node = node->next; }
            bool end() {  return node == NULL ; }

        friend class PList;
        };
    
    public:
        class reverse_iterator{
        private:
            ListNode *node;
            ListNode *next;
            ListNode *last;
            
        public:
            reverse_iterator(ListNode *n = NULL) { node = n;}
            void decrement();/* {
                    next = last->next;
                    last->next = node;
                    node = last;
                    
                node = node->next;
                }        */                                                                                   //move to the prior node in the list
            Item *getItem()  { return node->getItem();}                                                 //return a reference to the item 
            bool rend();//{ return node == NULL;}                                                          //return a bool indicating if the end of iteration is reached
        };

    public:
        PList();
        void append(Item *a);
        bool remove(Item *a);
        bool empty();

        iterator begin();//{ return iterator(head); }
        reverse_iterator rbegin();/*{   //add this to the List object to return a reverse_iterator initialized to point to the tail.
            ListNode *last = NULL;
            ListNode *node = head;
            for(ListNode* next; node != NULL; node = next){
                next = node->next;
                node->next = last;
                last = node;
            }   
            return reverse_iterator(tail);
        }*/

        void removeAfter(iterator it); // pseudocode in zyBook 2.4
        void insertAfter(iterator it, Item item);
};
    
}
