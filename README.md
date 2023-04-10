# foobarbaz
foobarbaz is my attempt to create a unit testing library for C that is simple,
type-agnostic[^1], and readable.
its pseudo-syntax is borrowed heavily from [mocha](https://mochajs.org/), and it
achieves it through many macros from [chax](https://github.com/Oderjunkie/chax).

[^1]: it is not *completely* type-agnostic, because if a type has an "invalid" state
(ex. a tagged union) then the input may be invalid.
## usage
```c
// change the text displayed next to a passing test
#define CHECKMARK "[pass]"

// note: by default, CROSSMARK is *not* defined, and
// instead of displaying a fixed piece of text it will
// display the ordinal corresponding to which test failed
#define CROSSMARK "[fail]"

// if the test takes longer than SLOW/2, then it will be
// marked yellow. if it takes longer than SLOW, it will be red.
// note that you can use minutes, seconds, and milliseconds as
// units of measure (ex. #define SLOW 1s500ms) but they must be
// whole numbers
#define SLOW 10ms

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
