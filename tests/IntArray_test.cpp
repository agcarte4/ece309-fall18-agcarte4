include "IntArray.h"
#include <stdio.h>
#include <string.h>

int main() {
  int testPassCnt = 0;
  int testFailCnt = 0;

  // test ascii constructor
  IntArray ascii("AB");
  if (ascii.get(0) == 65 && ascii.get(1) == 66) {
    testPassCnt++;
  } else {
    testFailCnt++;
    printf("Test Fail: ascii should be {65, 66}, instead of {%d, %d}\n",
           ascii.get(0), ascii.get(1));
  }

  // test int& operator[](int index)
  if (ascii[0] == 65 && ascii[1] == 66) {
    testPassCnt++;
  } else {
    testFailCnt++;
    printf(
        "Test Fail: ascii indexing should be {65, 66}, instead of {%d, %d}\n",
        ascii[0], ascii[1]);
  }

  // test (length,val) constructor
  // generate lhs = {6, 6, 6}
  IntArray lhs(3, 6);
  if (lhs.get(0) == 6 && lhs.get(1) == 6 && lhs.get(2) == 6) {
    testPassCnt++;
  } else {
    testFailCnt++;
    printf("Test Fail: lhs should be {6, 6, 6}, instead of {%d, %d, %d}\n",
           lhs.get(0), lhs.get(1), lhs.get(2));
  }

  // test operator+=(const IntArray &rhs)
  IntArray rhs(4, 1);
  // resulting lhs = {6,6,6} + {1,1,1,1} = {7,7,7}
  lhs += rhs;
  if (lhs.get(0) == 7 && lhs.get(1) == 7 && lhs.get(2) == 7 &&
      lhs.getLength() == 3) {
    testPassCnt++;
  } else {
    testFailCnt++;
    printf("Test Fail: lhs should be {7, 7, 7}, instead of {%d, %d, %d} and "
           "length: %d\n",
           lhs.get(0), lhs.get(1), lhs.get(2), lhs.getLength());
  }

  // test IntArray operator+(const IntArray &rhs) const
  // reuslting sum = {6,6,6} + {1,1,1} = {7,7,7}
  IntArray nlhs(3, 6);
  IntArray nrhs(3, 1);
  IntArray sum = nlhs + nrhs;
  if (sum.get(0) == 7 && sum.get(1) == 7 && sum.get(2) == 7) {
    testPassCnt++;
  } else {
    testFailCnt++;
    printf("Test Fail: sum should be {7, 7, 7}, instead of {%d, %d, %d}\n",
           sum.get(0), sum.get(1), sum.get(2));
  }

  // test IntArray operator-(const IntArray &rhs) const
  // reuslting sub = {6,6,6} - {1,1,1} = {5,5,5}
  IntArray sub = nlhs - nrhs;
  if (sub.get(0) == 5 && sub.get(1) == 5 && sub.get(2) == 5) {
    testPassCnt++;
  } else {
    testFailCnt++;
    printf("Test Fail: sub should be {5, 5, 5}, instead of {%d, %d, %d}\n",
           sub.get(0), sub.get(1), sub.get(2));
  }

  // test IntArray operator*(int x) const;
  // reuslting multi = {4,4,4} * 2 = {8,8,8}
  IntArray base(3, 4);
  IntArray multi = base * 2;
  if (multi.get(0) == 8 && multi.get(1) == 8 && multi.get(2) == 8) {
    testPassCnt++;
  } else {
    testFailCnt++;
    printf("Test Fail: multi should be {8, 8, 8}, instead of {%d, %d, %d}\n",
           multi.get(0), multi.get(1), multi.get(2));
  }

  // test IntArray operator/(int x) const;
  // reuslting div = {4,4,4} / 2 = {2,2,2}
  IntArray div = base / 2;
  if (div.get(0) == 2 && div.get(1) == 2 && div.get(2) == 2) {
    testPassCnt++;
  } else {
    testFailCnt++;
    printf("Test Fail: div should be {2, 2, 2}, instead of {%d, %d, %d}\n",
           multi.get(0), multi.get(1), multi.get(2));
  }

  // test left shift IntArray operator<<(int count) const;
  // resulting rot = {1,2,3} << 1 = {3,1,2}
  base.set(0, 1);
  base.set(1, 2);
  base.set(2, 3);
  IntArray rot = base << 1;
  if (rot.get(0) == 3 && rot.get(1) == 1 && rot.get(2) == 2) {
    testPassCnt++;
  } else {
    testFailCnt++;
    printf("Test Fail: rot should be {3, 1, 2}, instead of {%d, %d, %d}\n",
           rot.get(0), rot.get(1), rot.get(2));
  }

  // test operator char*() const;
  // resulting str = “A C” from {65, 9000, 67}
  base.set(0, 65);
  base.set(1, 9000);
  base.set(2, 67);

  char *str = (char *)base;
  if (strcmp(str, "A C") == 0) {
    testPassCnt++;
  } else {
    testFailCnt++;
    printf("Test Fail: str should be \"A C\", instead of %s\n", str);
  }

  // test operator int() const;
  // resulting avg = int({1,4}) = 2.5
  IntArray nbase(2, 1);
  nbase.set(1, 4);
  int avg = int(nbase);
  if (avg == 2) {
    testPassCnt++;
  } else {
    testFailCnt++;
    printf("Test Fail: avg should be 2, instead of %d\n", avg);
  }

  // print test result
  printf("Tests passed: %d, tests failed: %d\n", testPassCnt, testFailCnt);

  if (testFailCnt)
    return 1;
  else
    return 0;
}
