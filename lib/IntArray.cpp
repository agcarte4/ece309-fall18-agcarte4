#include <stdio.h>
#include <stdlib.h>

namespace ece309 {

class IntArray {
    private:
        int length;
        int i;
        int * array;

    public:
        IntArray(const char * str) {
            for(length = 1; length > -1; length ++){
                if(str[length-1] == '\0'){
                    length--;
                    break;
                }
            }
            array = new int[length];
            for(i = 0; i < length; i++){
                array[i] = (int) str[i];
            }
        }

        IntArray(int size, int val = 0){
            length = size;
            array = new int[length];
            for(i = 0; i < length; i++){
                array[i] = val;
            }
        }

        ~IntArray(){
            delete [] array;
        }
        void set(int index, int val){
            array[index] = val;
        }

        int get(int index){
            return array[index];
        }

        int getLength(){ return length;}

        int& operator[] (int index){
            return array[index];
        }

        IntArray& operator+=(const IntArray &rhs){
            if(rhs.length < length){
                for(i = 0; i < rhs.length; i++){
                    array[i]+=rhs.array[i];
                }
            }
            else if (rhs.length >= length){
                for(i = 0; i < length; i++){
                    array[i]+=rhs.array[i];
                }
            }
            return *this;
        }

        IntArray operator+(const IntArray &rhs) const {
            IntArray result(length);
            int i;
            for(i = 0;(( i < length) && (i < rhs.length)); i++)
                result.array[i] = array[i] + rhs.array[i];
            for(; i < length; i++)
                result.array[i] = array[i];
            return result;
            
        }

        IntArray operator-(const IntArray &rhs) const{
            IntArray result(length);
            int i;
            for(i = 0;(( i < length) && (i < rhs.length)); i++)
                result.array[i] = array[i] - rhs.array[i];
            for(; i < length; i++)
                result.array[i] = array[i];
            return result;

        }

        IntArray operator*(int x) const{
            IntArray result(length);
            int i;
            for(i = 0; i < length; i++)
                result.array[i] = array[i] * x;
            return result;
        }

        IntArray operator/(int x) const{
            IntArray result(length);
            int i;
            for(i = 0; i < length; i++)
                result.array[i] = array[i] / x;
            return result;

        }

        IntArray operator<<(int count) const{
            int i;
            IntArray result(length);
            for(i = 0; i < length; i++)
                result[i + count] = array[i];
            for(i = 0; i < count; i++)
                result[i] = array[length - count + i];      
            return result;
        }

        operator char*() const{
            int i;
            char * str = new char[length + 1]; //make char array the size of int array with an extra space for '\0'
            for(i = 0; i < length; i++){
                if((array[i] > 0) && (array[i] < 256))
                    str[i] = (char) array[i];
                else if((array[i] < 0) || (array[i] > 255))
                    str[i] = ' ';
                else{
                    str[i] = '\0';
                    return str;
                }
            }
            str[length + 1] = '\0';
            return str;
        }
        operator int() const{
            int i;
            int sum = 0;
            for(i = 0; i < length; i++)
                sum += array[i];
            return sum / length;
        }
};
/*int main(){
    IntArray a("ABCD");
    IntArray b(5,0);
    IntArray c("zzzDEAS");
    b = b + b;
    c = c -a;
    char * s = (char*) c;
    printf("\n%s\n",s);
    a = a << 2;
 
    return 0;
    
};*/

}
