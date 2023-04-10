# foobarbaz
foobarbaz - a property-based testing library in C
## usage
```c
#include "foobarbaz.h"

// function under test
int add(int lhs, int rhs) {
  return lhs + rhs;
}

int main(void) {

  // use `describe` to categorize tests.
  // don't put quotes around the description
  describe (add) {
    // use `it` to describe individual tests
    it (can calculate 1+1) {
      assert(add(1, 1) == 2);
    }
    
    it (has an identity element of 0) {
      // use `given` to test some property that holds true
      // no matter what the given value is. if you're familiar
      // with formal logic, think of `given` as `for_all`
      int x;
      given (x) {
        assert(add(x, 0) == x);
      }
    }
    
    it (is commutative) {
      // note that you can't write `given (int x, int y)`
      // because of the limitations of C macros
      int x, y;
      given (x, y) {
        assert(add(x, y) == add(y, x));
      }
    }
    
    it (is associative) {
      int x, y, z;
      given (x, y, z) {
        assert(add(x, add(y, z)) == add(add(x, y), z));
      }
    }
  }
  
}
```
