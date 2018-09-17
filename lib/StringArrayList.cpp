#include <iostream>
#include <string.h>

class StringArray{
    private:
        char** string;
        int numStrings = 0;
        int size = 0;
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
