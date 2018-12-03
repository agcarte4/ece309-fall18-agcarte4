#include <iostream>
#include <stdio.h>
#include <string.h>

namespace ece309 {

class StringArray{
    private:
        char** string;
        int numStrings;
        int size;
    public:
        StringArray() {numStrings = 0; size = 0;}
        StringArray(int n) { string = new char*[n];numStrings = 0; size = n;}
        ~StringArray() {delete[] string;}
        void push_back(char* s){
            if(numStrings<size){
                string[numStrings] = s;
                numStrings++;
            } else{
                char** tmp = string;
                size++;
                string = new char*[size];
                for(int i=0; i<size; i++)
                    string[i] = tmp[i];
                string[numStrings] = s;
                numStrings++;
            }
        }
        char * get(int n){
            return string[n];
        }
        int length(){
            return numStrings;
        }
        char* remove_front(){
            char** tmp = string;
            char* removed = string[0];
            for(int i=1; i<size; i++)
                string[i-1] = tmp[i];
            size--;
            numStrings--;
            return removed;
        }
        void print(int n ){ printf("%s\n",string[n]);}
        
};


/*

int main()
{
    StringArray newArray(1);
    newArray.push_back("books");
    newArray.push_back("paper");
    newArray.push_back("pens");
    newArray.push_back("pencil");
    newArray.push_back("eraser");
    newArray.push_back("notebook");
    for(int i = 0; i<6; i++)
        newArray.print(i);
    printf("\n%s",newArray.get(0));
    printf("\n%d\n\n",newArray.length());
    printf("\n%s\n\n",newArray.remove_front());
    for(int i = 0; i<5; i++)
        newArray.print(i);
    printf("\n%s",newArray.get(0));
    return 0;
}*/
}
