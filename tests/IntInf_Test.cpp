
int main(){     //IntInf has 3 constructors:  IntInf produces empty IntInf object with no values
    
    using namespace ece309;
    
    IntInf a;               //IntInf(bool) produces pos(true) or neg(false) infinity IntInf
        printf("a is ");    //IntInf(int) produces IntInf initialized to an int
        a.print();
    IntInf b(true);         //b is neg_inf
        printf("b is ");
        b.print();
    b = a;                  //b is empty
        printf("b is now ");
        b.print();
    b = 3;                  //b=3
        printf("b is now ");
        b.print();
    IntInf c(3);            //c=3
        printf("c is now ");
        c.print();
    a = (b + c);            //a = 6
        printf("a is now ");
        a.print();
    a = (b - c);            //a = 0
        printf("a is now ");
        a.print();
    IntInf d(10);            //d = 7
        printf("d is now ");
        d.print();
    IntInf e(false);        //e = neg_inf
        printf("e is now ");
        e.print();
    a = (d * e);            //a = neg_inf
        printf("a is now ");
        a.print();
    a = (d / e);            //a = 0
        printf("a is now ");
        a.print();
    if(d == e)              //d != e 
        printf("d and e are equal\n");
    else   
        printf("d and e are not equal\n");
    if(d > e)              //d > e = true
        printf("d is greater than e\n");
    else   
        printf("d is not greater than e\n");
    if(d < e)              //d < e = false
        printf("d is less than e\n");
    else   
        printf("d is not less than e\n");
    return 0;
};
