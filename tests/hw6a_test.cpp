#include <stdlib.h>
#include <time.h>
#include "hw6a.h"

int main()
{
using namespace ece309;
    IntegerSetHT a(1000);
    srand(time(NULL));

    for(int i = 0; i<500; i++)
        a.insert(rand());
    printf("\nCollisons = %d, Failures = %d",a.collisions, a.failures);

}
