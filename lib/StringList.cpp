#include <stdio.h>
#include <iostream>


class Item {
private:
    char * x;
public:
    Item() { x = NULL; }
    Item(char * a) { x = a; }
    void print() {
        printf("%s\n",x);
    }
};

class ListNode {
private:
    Item item;
    ListNode *next;
public:
    ListNode(Item a)
        { item = a; next=NULL;}
    ListNode* getNext() { return next; }
    void setNext(ListNode *n) { next = n;}
    Item getItem() { return item;}
};

class List {
private:
    ListNode *head;
    ListNode *tail;
public:
    int numItem;
    List() {head = NULL; tail = NULL; numItem = 0;}
    void push_back(Item a) {
        ListNode *node = new ListNode(a);
        if (head==NULL){
            head = node;
            tail = node;
        } else {
            tail -> setNext(node);
            tail = node;
        }
        numItem += 1;
    }
    Item get(int n) {
        Item copy;
        if (head == NULL){
            printf("List is empty!\n");
            return copy = NULL;
        }
        else {
            if (n <= numItem && n > 0) {
                ListNode * tmp = head;
                int i = 0;
                for(; i<n-1;i++)
                    tmp = tmp->getNext();
                copy = tmp->getItem();
                return copy;
            }
            else {
                printf("Outside of list range!\n");
                return copy = NULL;
            }
        }
    }
    
    int length() { return numItem; }
    
    Item remove_front(){
        Item copy;
        if (head == NULL){
            printf("List is empty!\n");
            return copy = NULL;
        }
        else {
            copy = head->getItem();
            ListNode * tmp = head->getNext();
            delete head;
            head = tmp;
            if (tmp == NULL)
                tail = NULL;
            numItem -= 1;
            return copy;
        }
    }
    ~List(){
        Item t;
        while(head != NULL)
            remove_front();
    }
};
/*
int main()
{
    Item a("books");
    List z;
    z.push_back(a);
    Item b("paper");
    z.push_back(b);
    Item cop = z.get(2);
    cop.print();
    printf("%d\n",z.length());
    z.remove_front();
    Item cop1 = z.get(1);
    cop1.print();
    z.~List();
    z.remove_front();

}*/
