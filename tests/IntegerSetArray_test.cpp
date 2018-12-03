#include "IntegerSetArray.h"
#include <stdio.h>

int main()
{
    using namespace ece309;
    
    int testPassCnt = 0;
    int testFailCnt = 0;
    
    printf("constructing an integer set of size 3 ...\n");
    IntegerSetArray isa(3);

    for (int i=0;i<4;i++)
    {
        bool insertResult = isa.insert(i);
        if(insertResult)
        {
            if (i<3)
                testPassCnt++;
            else
                testFailCnt++;
        }
        else {
            if (i<3)
                testFailCnt++;
            else
                testPassCnt++;
        }
        // for 1,2,3 should return true, for 4 should return false
        printf("Insert result of %d: %d\n",i,insertResult);
    }

    // test the search function
    if (isa.search(2)){
        testPassCnt++;
    }
    else {
        testFailCnt++;
        printf("search 2 test failed ... \n");
    }
    if (isa.search(4)){
        testFailCnt++;
        printf("search 4 test failed ... \n");
    }
    else {
        testPassCnt++;
    }

    // test the remove function
    isa.remove(2);
    // after remove 2, search of 2 should return false
    if(isa.search(2))
    {
        testFailCnt++;
        printf("remove 2 test failed ... \n");
    }
    else
        testPassCnt++;

    // print test result
    printf("Tests passed: %d, tests failed: %d\n",testPassCnt,testFailCnt);
    
    if (testFailCnt)
        return 1;
    else
        return 0;
}
