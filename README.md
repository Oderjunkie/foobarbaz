# foobarbaz
![Discord](https://img.shields.io/discord/1096149563871613099?style=for-the-badge&label=exploiting%20c)
![Lines of code](https://img.shields.io/tokei/lines/github/Oderjunkie/foobarbaz?style=for-the-badge)
![GitHub all releases](https://img.shields.io/github/downloads/Oderjunkie/foobarbaz/total?style=for-the-badge)
![GitHub release (latest SemVer)](https://img.shields.io/github/v/release/Oderjunkie/foobarbaz?style=for-the-badge)
![Minimum C version: 99](https://img.shields.io/badge/Minimum%20C%20Version-99-blueviolet?style=for-the-badge)
![GitHub](https://img.shields.io/github/license/Oderjunkie/foobarbaz?style=for-the-badge)

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

// requires POSIX. if defined, will catch segmentation faults.
#define CATCH_SEGFAULTS

#include "foobarbaz.h"

// function under test
int add(int lhs, int rhs) {
  return lhs + rhs;
}

#include <stdio.h>

int main(void) {
  printf("you forgot to compile this file with `-DTEST`\n");
  printf("

  // use `describe` to categorize tests.
  describe ("add") {
    // use `it` to describe individual tests
    it ("can calculate 1+1") {
      assert(add(1, 1) == 2);
    }
    
    it ("has an identity element of 0") {
      // use `given` to test some property that holds true
      // no matter what the given value is. if you're familiar
      // with formal logic, think of `given` as `for_all`
      int x;
      given (x) {
        assert(add(x, 0) == x);
      }
    }
    
    it ("is commutative") {
      // note that you can't write `given (int x, int y)`
      // because of the limitations of C macros
      int x, y;
      given (x, y) {
        assert(add(x, y) == add(y, x));
      }
    }
    
    it ("is associative") {
      int x, y, z;
      given (x, y, z) {
        assert(add(x, add(y, z)) == add(add(x, y), z));
      }
    }
  }
  
}
```
