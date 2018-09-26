//PList.cpp
//Functions are defined here
//
#include "Plist.h"

PList::ListNode::ListNode(Item *a, PList::ListNode *n = NULL ){
        item = a;
        next = n; // automatically serves as a list tail
}

PList::ListNode* PList::ListNode::getNext(){ return next; }

void PList::ListNode::setNext(ListNode *n){ next = n; }

Item* PList::ListNode::getItem(){ return item; }

//PList::reverse_iterator::reverse_iterator(ListNode *n = NULL) { node = n;}

void PList::reverse_iterator::decrement() {
                    /*next = last->next;
                    last->next = node;
                    node = last;
                    */
    node = node->next;
}

bool PList::reverse_iterator::rend(){ return node == NULL;} 

PList::iterator PList::begin(){ return iterator(head); }

PList::reverse_iterator PList::rbegin(){
        ListNode *last = NULL;
        ListNode *node = head;
        for(ListNode* next; node != NULL; node = next){
            next = node->next;
            node->next = last;
            last = node;
    }
    return reverse_iterator(tail);
}

PList::PList(){
  // start with an empty list
  head = NULL ;
  tail = NULL ;
  
}

void PList::append(Item *a){
  ListNode *node = new ListNode(a);
  if (head == NULL)
    {
      // list is empty
      head = node;
      tail = node;
    }
  else
    {
      tail->setNext(node);
      tail = node;
    }
}

bool PList::remove(Item *copy){
  if (!empty()) // if list is not empty
    {
      copy = head->getItem(); // return copy
      ListNode *tmp = head->getNext();
      delete head; // delete the node
      head = tmp;  // update the head
      if (tmp== NULL ) // removed last element
	tail = NULL;
      return true;
    }
  return false; // nothing in list
}

bool PList::empty(){
  return head== NULL ;
}

void PList::insertAfter(PList::iterator it, Item item) /* pseudocode in zyBook 2.3*/{
    if (it.node== NULL ){ // special case to insert at the head
	   // point new node at current head of list
	       ListNode *node = new ListNode(&item,head);
	       if (head== NULL ) { // if head was NULL, tail was also NULL
	            tail = node;   // new node is now the tail
	            head = node;   // new node is now the head
	        } else {
	            head = node;   // update head to new node
	        }
    }
    else /* insert after it*/{
	    ListNode *node = new ListNode(&item,it.node->getNext());
	    it.node->setNext(node);
	    if (tail==it.node) 
	        tail = node;
    }
}

void PList::removeAfter(PList::iterator it) // pseudocode in zyBook 2.4
{
   if (it.node== NULL ){ // special case to remove head, it’s not after any node
        ListNode *remove = head;               // will remove the head
        head = head->getNext();      // advance head
        if (head== NULL ) tail = NULL; // if head is NULL now, list is empty
            delete remove;               // delete removed node
     }
   else{// normal case, if not the head, then simply disconnect the node
        ListNode *tmp = it.node;
        ListNode *remove = tmp->getNext(); // next node to be removed
        tmp->setNext(remove->getNext());   // point around node to be removed
        if (tail==remove) tail = tmp;      // if removing tail, update tail
            delete remove; // delete node      // delete the removed node
     }
}
