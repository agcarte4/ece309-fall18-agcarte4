#include <stdio.h>


class IntInf {
public:                 //public for convenience
    bool pos_inf;       //set to true to represent positive infinity
    bool neg_inf;       //set to true to represent negative infinity
    int num;            //set to a integer value to represent an int
    bool empty;         //set true if this object is created with no parameter
public:
    IntInf() {          //default constructor creates an empty object
        pos_inf = false; 
        neg_inf = false; 
        num = 0;
        empty = true;
    }
    IntInf(bool val) {  //parameter determines if object is positive or negative infinity
        empty = false;
        if(val == true){
            pos_inf = true; 
            neg_inf = false; 
            num = 0;
            }
        else {
            pos_inf = false;
            neg_inf = true;
            num = 0;
        }
    }
    IntInf(int val) {   //parameter sets the object to represent an integer
        empty = false;
        pos_inf = false; 
        neg_inf = false; 
        num = val;
    }
    void clear(){       //used to clear an object for operations
        empty = true;
        pos_inf = false;
        neg_inf = false;
        num = 0;
    }
    void print(){       //prints what the object represents
        if(pos_inf == true)
            printf("positive infinity.\n");
        else if(neg_inf == true)
            printf("negative infinity.\n");
        else if(empty == false)
            printf("equal to %d.\n", num);
        else
            printf("empty!\n");
        return;
    }

    
    IntInf operator=(const IntInf &rhs){    //sets lhs inf to the value of rhs
        this->clear();
        if(rhs.empty == true)
            return this;
        else if(rhs.pos_inf == true)
            this->pos_inf = true;
        else if (rhs.neg_inf == true)
            this->neg_inf = true;
        else
            this->num = rhs.num;
        this->empty = false;        
        return this;
    }

    IntInf operator=(const int &rhs){       //sets lhs inf to an int value
        this->clear();
        this->num = rhs;  
        this->empty = false;      
        return this;
    }

    IntInf operator+(const IntInf &rhs){    //pos_inf + neg_inf is always pos_inf and vice-versa
        IntInf result;
        if(this->pos_inf)                   //if lhs is pos_inf, then result is pos_inf
            return this;
        else if(this->neg_inf){             //if lhs is neg_inf, then result is neg_inf
            result.neg_inf = true;
            result.empty = false;
            return result;
        }
        else if(rhs.pos_inf)                //lhs is either an int or empty          
            return rhs;                     //thus, if rhs is pos_inf, then result is pos_inf
        else if(rhs.neg_inf)                //lhs is either an int or empty     
            return rhs;                     //thus if rhs is neg_inf, then result is neg_inf
        else if(this->empty){               //if neither rhs or lhs are pos/neg infinity, 
            if(rhs.empty == true)           //then both are empty, ints, or a mix
                return result;              //if both are empty, result is an empty IntInf
            else                            //else, rhs is an int
                return rhs;
        }
        else if(!(this->empty)){            //else, lhs is an int
            if(rhs.empty){                  //if rhs is empty, the result is int
                result.empty = false;
                result.num = this->num;
                return result;
            }
            else{                            //lastly, both are ints, return the result
                result.empty = false;
                result.num = (this->num + rhs.num);
                return result;
            }
        }                   
    }

    IntInf operator-(const IntInf &rhs){    //pos_inf - neg_inf is always pos_inf and vice versa
        IntInf result;
        if(this->pos_inf)                   //if lhs is pos_inf, then result is pos_inf
            return this;
        else if(this->neg_inf)              //if lhs is neg_inf, then result is neg_inf
            return this;
        else if(rhs.pos_inf){               //lhs is either an int or empty          
            result.empty = false;           //thus, if rhs is pos_inf, then result is neg_inf
            result.neg_inf = true;
            return result;
        }
        else if(rhs.neg_inf){               //lhs is either an int or empty     
            result.empty = false;           //thus if rhs is neg_inf, then result is pos_inf
            result.pos_inf = true;
            return result;
        }
        else if(this->empty){               //if neither rhs or lhs are pos/neg infinity, 
            if(rhs.empty)                   //then both are empty, ints, or a mix
                return result;              //if both are empty, result is an empty IntInf
            else{                           //else, rhs is an int and the result is negative int
                result.empty = false;
                result.num = (0 - rhs.num);
                return result;
            }
        }
        else if(!(this->empty)){            //else, lhs is an int
            if(rhs.empty){                  //if rhs is empty, the result is int
                result.empty = false;
                result.num = this->num;
                return result;
            }
            else{                           //lastly, both are ints, return the result
                result.empty = false;
                result.num = (this->num - rhs.num);
                return result;
            }
        }                   
    }

    IntInf operator*(const IntInf &rhs){
        IntInf result;                  
        if((!rhs.pos_inf) && !(rhs.neg_inf) && (rhs.num == 0)){
            result.empty = false;       //check for 0 in rhs
            result.num = 0;
            return result;
        }
        else if(this->pos_inf){              
            if(!(rhs.neg_inf))          //rhs is not neg_inf then result is pos_inf
                return this;            //return this as it is pos_inf
            else
                return rhs;             //else return rhs as its neg_inf   
        }
        else if(this->neg_inf){         //all cases for when lhs is neg_inf
            if(rhs.neg_inf){            //when rhs is also neg_inf, return pos_inf
                result.empty = false;   
                result.pos_inf = true;
                return result;
            }
            else
                return this;            //else, the result is always neg_inf
        }
        else if(this->empty)
            return rhs;                 //if lhs is empty, the result is always rhs
        else{                           //else, lhs is an integer
            if(rhs.pos_inf || rhs.neg_inf)            
                return rhs;             //int multiplied to +/- inf is +/- inf
            else if(rhs.empty){         //if rhs is empty, then result is lhs
                result.empty = false;
                result.num = this->num;
                return result; 
            }       
            else{                       //else rhs is also an int
                result.empty = false;
                result.num = (this->num * rhs.num);
                return result;
            }
        }
    }

    IntInf operator/(const IntInf &rhs){
        IntInf result;
        if((rhs.num == 0) && !(rhs.pos_inf) && !(rhs.neg_inf)){//special case: division by 0 is impossible regardless of lhs
            result.num = 1 / (rhs.num);
            return result;
        }
        else if(this->pos_inf){              
            if(!(rhs.neg_inf))          //rhs is not neg_inf then result is pos_inf
                return this;            //return this as it is pos_inf
            else
                return rhs;             //else return rhs as its neg_inf   
        }
        else if(this->neg_inf){         //all cases for when lhs is neg_inf
            if(rhs.neg_inf){            //when rhs is also neg_inf, return pos_inf
                result.empty = false;   
                result.pos_inf = true;
                return result;
            }
            else 
                return this;            //else, always negative
        }
        else if (this->empty)           //empty always results in empty unless rhs = 0  
            return this;
        else{                           //else lhs is an int
            if(rhs.pos_inf || rhs.neg_inf){ //if rhs is +/- inf, then result is 0
                result.empty = false;
                result.num = 0;
                return result;
            }
            else if (rhs.empty)         //division by nothing is lhs
                return this;    
            else{                       //else, lhs and rhs are non-zero ints
                result.empty = false;
                result.num = this->num / rhs.num;
                return result;
            }
        }
    }

    bool operator==(const IntInf &rhs){
        if(this->pos_inf){              //cases for when lhs is pos_inf
            if(rhs.pos_inf)             //only true if rhs is also pos_inf
                return true;
            else
                return false;
        }
        else if(this->neg_inf){         //cases for when lhs is neg_inf
            if(rhs.neg_inf)             //only true if rhs is also neg_inf
                return true;    
            else    
                return false;
        }
        else if(this->empty){           //cases for empty
            if(rhs.empty)               //only true when both are empty objects
                return true;            
            else
                return false;
        }
        else{                           //else the lhs is an int
            if (!(rhs.empty && rhs.pos_inf && rhs.neg_inf))  //check that rhs is an int
                return (this->num == rhs.num);
            else 
                return false;
        }
    }

    bool operator>(const IntInf &rhs){
        if(this->pos_inf){              //cases for lhs = pos_inf
            if(rhs.pos_inf)             //only false when rhs is pos_inf
                return false;
            else 
                return true;
        }
        else if (this->neg_inf)         //neg_inf is never greater than anything
            return false;   
        else if(this->empty)            //an empty set is never greater than anything            
            return false;
        else{                           //lhs is an int
            if(rhs.pos_inf)             //an integer cant be greater than pos_inf
                return false;           
            else if(rhs.neg_inf)        //integer is always greater than neg_inf
                return true;
            else if(rhs.empty)          //integer is always greater than an empty set
                return true;
            else                        //else, both are ints
                return ((this->num) > (rhs.num));
        }
    }

    bool operator<(const IntInf &rhs){
        if(this->pos_inf)               //pos_inf is never less than anything
            return false;
        else if(this->neg_inf){         //neg_inf is less than everything except neg_inf
            if(rhs.neg_inf)
                return false;
            else    
                return true;
        }
        else if(this->empty)            //an empty set cant be less than anything
            return false;
        else{                           //else, rhs is in an int
            if(rhs.pos_inf)
                return true;
            else if(rhs.neg_inf)        //an ineger cant be less than neg_inf
                return false;
            else if(rhs.empty)          //never less than an empty set
                return false;
            else                        //else, both are ints, so compare
                return ((this->num) < (rhs.num));
        }        
    }
};
