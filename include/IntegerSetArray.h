#include <stdio.h>

class IntegerSet {
protected:
    int size;
    int hash(int key) { return (key * 997) % size;}
public:
    IntegerSet(int htsize) : size(htsize) {}
    virtual bool insert(int) = 0;
    virtual bool search(int) const = 0;
    virtual void remove(int) = 0;
};

class IntegerSetArray : public IntegerSet {
protected:
    int *IntArray;
    int counter;
    int size;
public:
    IntegerSetArray(int s) : IntegerSet(size=0), size(s) {IntArray = NULL;}
    bool insert(int x);
    bool search(int x) const;
    void remove(int x);
};

bool IntegerSetArray::insert(int x){
    //printf("Inserting, %d\n",x);
    if (IntArray == NULL){
        IntArray = new int[size];
        for(int i = 0; i < size; i++)
            IntArray[i] = -1;
        IntArray[0] = x;
        counter = 1;
        return 1;
    }
    else if(counter < size){
        IntArray[counter] = x;
        counter++;
        return 1;
    }

    else { 
        for(int i = 0; i < size; i++){
            if(IntArray[i] == -1){
                IntArray[i] = x;
                return 1;
            }
        }
    //printf("ARRAY IS FULL\n");
    return 0;
    }
}

bool IntegerSetArray::search(int x) const {

    //printf("\nSearching, %d\n", x);
    for(int i = 0; i < counter; i++){
        if(IntArray[i] == x)
            return 1;
    }
    return 0;
}

void IntegerSetArray::remove(int x){
    //printf("\nRemoving, %d\n", x);
    for(int i = 0; i < size; i++){
        if(IntArray[i] == x){
            IntArray[i] = -1;
        }
    }
}

/*int main(){
    int size = 3;
    IntegerSetArray a(size);
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.remove(2);
    a.insert(9);
    printf("%d\n", a.search(9));
}
*/
