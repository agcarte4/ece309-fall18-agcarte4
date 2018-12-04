#include <stdio.h>

namespace ece309 {

class IntInf {
public:                 //public for convenience
    bool pos_inf;       //set to true to represent positive infinity
    bool neg_inf;       //set to true to represent negative infinity
    int num;            //set to a integer value to represent an int
    bool empty;         //set true if this object is created with no parameter
public:
    IntInf();
    IntInf(bool val);
    IntInf(int val);
    void clear();
    void print();
    IntInf thisResult();
    IntInf operator=(const IntInf &rhs);
    IntInf operator=(const int &rhs);
    IntInf operator+(const IntInf &rhs);
    IntInf operator-(const IntInf &rhs);
    IntInf operator*(const IntInf &rhs);
    IntInf operator/(const IntInf &rhs);
    bool operator==(const IntInf &rhs);
    bool operator>(const IntInf &rhs);
    bool operator<(const IntInf &rhs);
};
}
