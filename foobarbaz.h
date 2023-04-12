#ifndef FOOBARBAZ
#define FOOBARBAZ
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <errno.h>
#ifdef CATCH_SEGFAULTS
  #include <signal.h>
  #include <unistd.h>
  #include <setjmp.h>
  #define _if_catching_segfaults(...) __VA_ARGS__
#else
  #define _if_catching_segfaults(...)
#endif

#define _with(...) \
  for (int _w = 1; _w; _w = 0) \
    for (__VA_ARGS__; _w; _w = 0)
#define _then(...) \
  for (int _t = 1; _t; ((__VA_ARGS__), _t = 0))
#define _stringize(x) _stringize1(x)
#define _stringize1(x) #x
#define _printfspecifier(x) _Generic((x), \
  char: "%i", \
  unsigned char: "%u", \
  short: "%hi", \
  unsigned short: "%hu", \
  int: "%i", \
  unsigned int: "%u", \
  long: "%li", \
  unsigned long: "%lu", \
  long long: "%lli", \
  unsigned long long: "%llu", \
  float: "%g", \
  double: "%g", \
  long double: "%Lg", \
  char *: "%s", \
  default: (sizeof(x) == sizeof(void*)) ? "%p" : "" \
)

#define _argcount(...) \
  _argcount5( \
    0, \
    _argcount1(__VA_ARGS__,   \
    63,62,61,60,                   \
    59,58,57,56,55,54,53,52,51,50, \
    49,48,47,46,45,44,43,42,41,40, \
    39,38,37,36,35,34,33,32,31,30, \
    29,28,27,26,25,24,23,22,21,20, \
    19,18,17,16,15,14,13,12,11,10, \
     9, 8, 7, 6, 5, 4, 3, 2, 1), \
    _argcount2(__VA_ARGS__), \
    _argcount2(_argcount3 __VA_ARGS__), \
    _argcount2(__VA_ARGS__ ()), \
    _argcount2(_argcount3 __VA_ARGS__ ()) \
  )
#define _argcount1( \
     _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
    _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
    _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
    _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
    _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
    _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
    _61,_62,_63,N, ...) N
#define _argcount2(...) \
    _argcount1(__VA_ARGS__,   \
     1, 1, 1, 1,                   \
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
     1, 1, 1, 1, 1, 1, 1, 1, 0)
#define _argcount3(...) ,
#define _argcount4(_0, _1, _2, _3, _4) _0 ## _1 ## _2 ## _3 ## _4
#define _argcount5(yes, no, _0, _1, _2, _3) _argcount4(_argcount6_, _0, _1, _2, _3)(yes, no)
#define _argcount6_0000(yes, no) no
#define _argcount6_0001(yes, no) yes
#define _argcount6_0010(yes, no) no
#define _argcount6_0011(yes, no) no
#define _argcount6_0100(yes, no) no
#define _argcount6_0101(yes, no) no
#define _argcount6_0110(yes, no) no
#define _argcount6_0111(yes, no) no
#define _argcount6_1000(yes, no) no
#define _argcount6_1001(yes, no) no
#define _argcount6_1010(yes, no) no
#define _argcount6_1011(yes, no) no
#define _argcount6_1100(yes, no) no
#define _argcount6_1101(yes, no) no
#define _argcount6_1110(yes, no) no
#define _argcount6_1111(yes, no) no
#define _vaopt(args, ...) _vaopt1(_argcount args, (__VA_ARGS__))
#define _vaopt1(count, emitted) _vaopt2(count, emitted)
#define _vaopt2(count, emitted) _vaopt2_##count emitted
#define _vaopt2_0(...)
#define _vaopt2_1(...) __VA_ARGS__
#define _vaopt2_2(...) __VA_ARGS__
#define _vaopt2_3(...) __VA_ARGS__
#define _vaopt2_4(...) __VA_ARGS__
#define _vaopt2_5(...) __VA_ARGS__
#define _vaopt2_6(...) __VA_ARGS__
#define _vaopt2_7(...) __VA_ARGS__
#define _vaopt2_8(...) __VA_ARGS__
#define _vaopt2_9(...) __VA_ARGS__
#define _vaopt2_10(...) __VA_ARGS__
#define _vaopt2_11(...) __VA_ARGS__
#define _vaopt2_12(...) __VA_ARGS__
#define _vaopt2_13(...) __VA_ARGS__
#define _vaopt2_14(...) __VA_ARGS__
#define _vaopt2_15(...) __VA_ARGS__
#define _vaopt2_16(...) __VA_ARGS__
#define _vaopt2_17(...) __VA_ARGS__
#define _vaopt2_18(...) __VA_ARGS__
#define _vaopt2_19(...) __VA_ARGS__
#define _vaopt2_20(...) __VA_ARGS__
#define _vaopt2_21(...) __VA_ARGS__
#define _vaopt2_22(...) __VA_ARGS__
#define _vaopt2_23(...) __VA_ARGS__
#define _vaopt2_24(...) __VA_ARGS__
#define _vaopt2_25(...) __VA_ARGS__
#define _vaopt2_26(...) __VA_ARGS__
#define _vaopt2_27(...) __VA_ARGS__
#define _vaopt2_28(...) __VA_ARGS__
#define _vaopt2_29(...) __VA_ARGS__
#define _vaopt2_30(...) __VA_ARGS__
#define _vaopt2_31(...) __VA_ARGS__
#define _vaopt2_32(...) __VA_ARGS__
#define _vaopt2_33(...) __VA_ARGS__
#define _vaopt2_34(...) __VA_ARGS__
#define _vaopt2_35(...) __VA_ARGS__
#define _vaopt2_36(...) __VA_ARGS__
#define _vaopt2_37(...) __VA_ARGS__
#define _vaopt2_38(...) __VA_ARGS__
#define _vaopt2_39(...) __VA_ARGS__
#define _vaopt2_40(...) __VA_ARGS__
#define _vaopt2_41(...) __VA_ARGS__
#define _vaopt2_42(...) __VA_ARGS__
#define _vaopt2_43(...) __VA_ARGS__
#define _vaopt2_44(...) __VA_ARGS__
#define _vaopt2_45(...) __VA_ARGS__
#define _vaopt2_46(...) __VA_ARGS__
#define _vaopt2_47(...) __VA_ARGS__
#define _vaopt2_48(...) __VA_ARGS__
#define _vaopt2_49(...) __VA_ARGS__
#define _vaopt2_50(...) __VA_ARGS__
#define _vaopt2_51(...) __VA_ARGS__
#define _vaopt2_52(...) __VA_ARGS__
#define _vaopt2_53(...) __VA_ARGS__
#define _vaopt2_54(...) __VA_ARGS__
#define _vaopt2_55(...) __VA_ARGS__
#define _vaopt2_56(...) __VA_ARGS__
#define _vaopt2_57(...) __VA_ARGS__
#define _vaopt2_58(...) __VA_ARGS__
#define _vaopt2_59(...) __VA_ARGS__
#define _vaopt2_60(...) __VA_ARGS__
#define _vaopt2_61(...) __VA_ARGS__
#define _vaopt2_62(...) __VA_ARGS__
#define _vaopt2_63(...) __VA_ARGS__
#define _empty()
#define _defer(x) x _empty()
#define _obstruct(x) x _defer(_empty)()
#define _cat(x, y) _cat1(x, y)
#define _cat1(x, y) x##y
#define _expand(...) __VA_ARGS__
#define _mapreduce(mapper, reducer, ...) _expand(_expand(_obstruct(_cat(_mapreduce1_, _argcount(__VA_ARGS__))) (mapper, reducer _vaopt((__VA_ARGS__), ,) __VA_ARGS__)))
#define _mapreduce1_0(mapper, reducer)
#define _mapreduce1_1(mapper, reducer, a0) mapper(a0)
#define _mapreduce1_2(mapper, reducer, a0, a1) reducer(mapper(a0), mapper(a1))
#define _mapreduce1_3(mapper, reducer, a0, a1, a2) reducer(mapper(a0), reducer(mapper(a1), mapper(a2)))
#define _mapreduce1_4(mapper, reducer, a0, a1, a2, a3) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), mapper(a3))))
#define _mapreduce1_5(mapper, reducer, a0, a1, a2, a3, a4) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), mapper(a4)))))
#define _mapreduce1_6(mapper, reducer, a0, a1, a2, a3, a4, a5) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), mapper(a5))))))
#define _mapreduce1_7(mapper, reducer, a0, a1, a2, a3, a4, a5, a6) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), mapper(a6)))))))
#define _mapreduce1_8(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), mapper(a7))))))))
#define _mapreduce1_9(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), mapper(a8)))))))))
#define _mapreduce1_10(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), mapper(a9))))))))))
#define _mapreduce1_11(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), mapper(a10)))))))))))
#define _mapreduce1_12(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), mapper(a11))))))))))))
#define _mapreduce1_13(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), mapper(a12)))))))))))))
#define _mapreduce1_14(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), mapper(a13))))))))))))))
#define _mapreduce1_15(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), mapper(a14)))))))))))))))
#define _mapreduce1_16(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), mapper(a15))))))))))))))))
#define _mapreduce1_17(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), mapper(a16)))))))))))))))))
#define _mapreduce1_18(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), mapper(a17))))))))))))))))))
#define _mapreduce1_19(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), mapper(a18)))))))))))))))))))
#define _mapreduce1_20(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), mapper(a19))))))))))))))))))))
#define _mapreduce1_21(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), mapper(a20)))))))))))))))))))))
#define _mapreduce1_22(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), mapper(a21))))))))))))))))))))))
#define _mapreduce1_23(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), mapper(a22)))))))))))))))))))))))
#define _mapreduce1_24(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), mapper(a23))))))))))))))))))))))))
#define _mapreduce1_25(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), mapper(a24)))))))))))))))))))))))))
#define _mapreduce1_26(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), mapper(a25))))))))))))))))))))))))))
#define _mapreduce1_27(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), mapper(a26)))))))))))))))))))))))))))
#define _mapreduce1_28(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), mapper(a27))))))))))))))))))))))))))))
#define _mapreduce1_29(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), mapper(a28)))))))))))))))))))))))))))))
#define _mapreduce1_30(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), mapper(a29))))))))))))))))))))))))))))))
#define _mapreduce1_31(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), mapper(a30)))))))))))))))))))))))))))))))
#define _mapreduce1_32(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), mapper(a31))))))))))))))))))))))))))))))))
#define _mapreduce1_33(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), mapper(a32)))))))))))))))))))))))))))))))))
#define _mapreduce1_34(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), mapper(a33))))))))))))))))))))))))))))))))))
#define _mapreduce1_35(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), mapper(a34)))))))))))))))))))))))))))))))))))
#define _mapreduce1_36(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), mapper(a35))))))))))))))))))))))))))))))))))))
#define _mapreduce1_37(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), mapper(a36)))))))))))))))))))))))))))))))))))))
#define _mapreduce1_38(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), mapper(a37))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_39(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), mapper(a38)))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_40(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), mapper(a39))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_41(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), mapper(a40)))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_42(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), mapper(a41))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_43(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), mapper(a42)))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_44(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), mapper(a43))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_45(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), mapper(a44)))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_46(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), mapper(a45))))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_47(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), reducer(mapper(a45), mapper(a46)))))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_48(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), reducer(mapper(a45), reducer(mapper(a46), mapper(a47))))))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_49(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), reducer(mapper(a45), reducer(mapper(a46), reducer(mapper(a47), mapper(a48)))))))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_50(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), reducer(mapper(a45), reducer(mapper(a46), reducer(mapper(a47), reducer(mapper(a48), mapper(a49))))))))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_51(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), reducer(mapper(a45), reducer(mapper(a46), reducer(mapper(a47), reducer(mapper(a48), reducer(mapper(a49), mapper(a50)))))))))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_52(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), reducer(mapper(a45), reducer(mapper(a46), reducer(mapper(a47), reducer(mapper(a48), reducer(mapper(a49), reducer(mapper(a50), mapper(a51))))))))))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_53(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), reducer(mapper(a45), reducer(mapper(a46), reducer(mapper(a47), reducer(mapper(a48), reducer(mapper(a49), reducer(mapper(a50), reducer(mapper(a51), mapper(a52)))))))))))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_54(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), reducer(mapper(a45), reducer(mapper(a46), reducer(mapper(a47), reducer(mapper(a48), reducer(mapper(a49), reducer(mapper(a50), reducer(mapper(a51), reducer(mapper(a52), mapper(a53))))))))))))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_55(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), reducer(mapper(a45), reducer(mapper(a46), reducer(mapper(a47), reducer(mapper(a48), reducer(mapper(a49), reducer(mapper(a50), reducer(mapper(a51), reducer(mapper(a52), reducer(mapper(a53), mapper(a54)))))))))))))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_56(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), reducer(mapper(a45), reducer(mapper(a46), reducer(mapper(a47), reducer(mapper(a48), reducer(mapper(a49), reducer(mapper(a50), reducer(mapper(a51), reducer(mapper(a52), reducer(mapper(a53), reducer(mapper(a54), mapper(a55))))))))))))))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_57(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), reducer(mapper(a45), reducer(mapper(a46), reducer(mapper(a47), reducer(mapper(a48), reducer(mapper(a49), reducer(mapper(a50), reducer(mapper(a51), reducer(mapper(a52), reducer(mapper(a53), reducer(mapper(a54), reducer(mapper(a55), mapper(a56)))))))))))))))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_58(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), reducer(mapper(a45), reducer(mapper(a46), reducer(mapper(a47), reducer(mapper(a48), reducer(mapper(a49), reducer(mapper(a50), reducer(mapper(a51), reducer(mapper(a52), reducer(mapper(a53), reducer(mapper(a54), reducer(mapper(a55), reducer(mapper(a56), mapper(a57))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_59(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), reducer(mapper(a45), reducer(mapper(a46), reducer(mapper(a47), reducer(mapper(a48), reducer(mapper(a49), reducer(mapper(a50), reducer(mapper(a51), reducer(mapper(a52), reducer(mapper(a53), reducer(mapper(a54), reducer(mapper(a55), reducer(mapper(a56), reducer(mapper(a57), mapper(a58)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_60(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), reducer(mapper(a45), reducer(mapper(a46), reducer(mapper(a47), reducer(mapper(a48), reducer(mapper(a49), reducer(mapper(a50), reducer(mapper(a51), reducer(mapper(a52), reducer(mapper(a53), reducer(mapper(a54), reducer(mapper(a55), reducer(mapper(a56), reducer(mapper(a57), reducer(mapper(a58), mapper(a59))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_61(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), reducer(mapper(a45), reducer(mapper(a46), reducer(mapper(a47), reducer(mapper(a48), reducer(mapper(a49), reducer(mapper(a50), reducer(mapper(a51), reducer(mapper(a52), reducer(mapper(a53), reducer(mapper(a54), reducer(mapper(a55), reducer(mapper(a56), reducer(mapper(a57), reducer(mapper(a58), reducer(mapper(a59), mapper(a60)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_62(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), reducer(mapper(a45), reducer(mapper(a46), reducer(mapper(a47), reducer(mapper(a48), reducer(mapper(a49), reducer(mapper(a50), reducer(mapper(a51), reducer(mapper(a52), reducer(mapper(a53), reducer(mapper(a54), reducer(mapper(a55), reducer(mapper(a56), reducer(mapper(a57), reducer(mapper(a58), reducer(mapper(a59), reducer(mapper(a60), mapper(a61))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
#define _mapreduce1_63(mapper, reducer, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61, a62) reducer(mapper(a0), reducer(mapper(a1), reducer(mapper(a2), reducer(mapper(a3), reducer(mapper(a4), reducer(mapper(a5), reducer(mapper(a6), reducer(mapper(a7), reducer(mapper(a8), reducer(mapper(a9), reducer(mapper(a10), reducer(mapper(a11), reducer(mapper(a12), reducer(mapper(a13), reducer(mapper(a14), reducer(mapper(a15), reducer(mapper(a16), reducer(mapper(a17), reducer(mapper(a18), reducer(mapper(a19), reducer(mapper(a20), reducer(mapper(a21), reducer(mapper(a22), reducer(mapper(a23), reducer(mapper(a24), reducer(mapper(a25), reducer(mapper(a26), reducer(mapper(a27), reducer(mapper(a28), reducer(mapper(a29), reducer(mapper(a30), reducer(mapper(a31), reducer(mapper(a32), reducer(mapper(a33), reducer(mapper(a34), reducer(mapper(a35), reducer(mapper(a36), reducer(mapper(a37), reducer(mapper(a38), reducer(mapper(a39), reducer(mapper(a40), reducer(mapper(a41), reducer(mapper(a42), reducer(mapper(a43), reducer(mapper(a44), reducer(mapper(a45), reducer(mapper(a46), reducer(mapper(a47), reducer(mapper(a48), reducer(mapper(a49), reducer(mapper(a50), reducer(mapper(a51), reducer(mapper(a52), reducer(mapper(a53), reducer(mapper(a54), reducer(mapper(a55), reducer(mapper(a56), reducer(mapper(a57), reducer(mapper(a58), reducer(mapper(a59), reducer(mapper(a60), reducer(mapper(a61), mapper(a62)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))

_if_catching_segfaults(
  static sigjmp_buf _test_back;
  
  static inline void _segfault_catcher(int signo, siginfo_t *info, void *context) {
    siglongjmp(_test_back, 1);
  }
  
  static inline int _catch_segfaults(void) {
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = _segfault_catcher;

    if (sigemptyset(&sa.sa_mask))
        exit(EXIT_FAILURE);
    if (sigaddset(&sa.sa_mask, SIGSEGV))
        exit(EXIT_FAILURE);
    if (sigaction(SIGSEGV, &sa, NULL))
        exit(EXIT_FAILURE);
    
    return 0;
  }
)

#ifndef MAX_TRIES
  #define MAX_TRIES 10000
#endif
  
#ifndef MAX_REDUCTIONS
  #define MAX_REDUCTIONS 50000
#endif

struct _pbt {
  int is_reducing, just_failed;
  int number_of_tries, number_of_reductions;
};

static const int _is_in_property = 0;
static struct _pbt _data;

#define given(...) \
  _with(struct _pbt _data) \
  _with(memset(&_data, 0x00, sizeof(_data))) \
  _with(char buf[1024], *bufp = buf) \
  _mapreduce(_given3, _given4, __VA_ARGS__) \
  _then( \
    _data.just_failed \
    ? (_mapreduce(_given6, _given2, __VA_ARGS__)) \
    : 0, \
    bufp += snprintf( \
      bufp, \
      (char *) buf + sizeof(buf) - bufp, \
      __FILE__ ":" _stringize(__LINE__) ": Property was incorrect." \
    ), \
    _mapreduce(_given7, _given2, __VA_ARGS__), \
    _assert( \
      !_data.is_reducing, \
      &_succeeded, \
      buf \
    ) \
  ) \
  _with(int _succeeded) \
  _with(const int _is_in_property = 1) \
  _with(_mapreduce(_given5, _given2, __VA_ARGS__)) \
  while (_advance(&_data)) \
  _with(_data.just_failed = 0) \
  _then(_mapreduce(_given1, _given2, __VA_ARGS__)) \
  _if_catching_segfaults( \
    if (sigsetjmp(_test_back, 1) == 1 ? 1 : _catch_segfaults()) \
      _data.just_failed = 1; \
    else \
  )

static int _advance(struct _pbt *data) {
  if (data->is_reducing)
    return data->number_of_reductions++ < MAX_REDUCTIONS;
  else
    return data->number_of_tries++ < MAX_TRIES;
}

#define _given1(x) \
  _iterate(&_data, (void *) &x, (void *) &last_##x, sizeof(x))
#define _given2(x, y) (x, y)
#define _given3(x) \
  _with(char last_##x[sizeof(x)])
#define _given4(x, y) x y
#define _given5(x) \
  memset(&x, 0x00, sizeof(x)), memset(&last_##x, 0x00, sizeof(x))
#define _given6(x) \
  memcpy(&x, &last_##x, sizeof(x))
#define _given7(x) \
  bufp += snprintf( \
    bufp, \
    (char *) buf + sizeof(buf) - bufp, \
    "\n" #x ": " \
  ), bufp += snprintf( \
    bufp, \
    (char *) buf + sizeof(buf) - bufp, \
    _printfspecifier(x), x \
  )

#ifndef CHECKMARK
  #define CHECKMARK "✓"
#endif

#ifndef SLOW
  #define SLOW 75ms
#endif

#define INDENT(i) ( \
  (i) <= 0 ? "" : \
  (i) == 1 ? "  " : \
  (i) == 2 ? "    " : \
  (i) == 3 ? "      " : \
  (i) == 4 ? "        " : \
  (i) == 5 ? "          " : \
  (i) == 6 ? "            " : \
  (i) == 7 ? "              " : \
  (i) == 8 ? "                " : \
  (i) == 9 ? "                  " : \
             "                    " \
)

#define ANSI_RED(s) "\x1b[31m" s "\x1b[0m"
#define ANSI_GREEN(s) "\x1b[32m" s "\x1b[0m"
#define ANSI_YELLOW(s) "\x1b[33m" s "\x1b[0m"

static const int _indentation_level = 0;
static int _passing = 0, _failing = 0;
static long int _slow = 0;
static const char *error_messages[256];
static int error_i = 0;

#define describe(desc) \
  _with(printf("%s" desc "\n", INDENT(_indentation_level))) \
    _with(const int x = _indentation_level, _indentation_level = x + 1)

#define it(desc) \
  _with(_register_handler()) \
  _with(const char _current_description[sizeof(desc)] = desc) \
  _with(struct timespec start, end) \
  _with(memset(&start, 0x00, sizeof(start)), memset(&end, 0x00, sizeof(end))) \
  _with(int _succeeded = 1) \
  _with(_draw_initial(_indentation_level, _current_description, &start)) \
  _then(_draw_final(_succeeded, _current_description, sizeof(_current_description), &start, &end)) \
  _if_catching_segfaults( \
    if (sigsetjmp(_test_back, 1) == 1 ? 1 : _catch_segfaults()) \
      _assert( \
        0, \
        &_succeeded, \
        __FILE__ ":" _stringize(__LINE__) ": Segmentation fault." \
      ); \
    else \
  )

static inline long _to_ms(const char *duration) {
  long result = 0;
  long current_duration = 0;
  
  for (int i = 0; duration[i]; i++) {
    if ('0' <= duration[i] && duration[i] <= '9') {
      current_duration = current_duration * 10 + duration[i] - '0';
    } else {
      if (duration[i] == 's') {
        result += current_duration * 1000;
      } else if (duration[i] == 'm' && duration[i + 1] != 's') {
        result += current_duration * 60000;
      } else if (duration[i] == 'm' && duration[i + 1] == 's') {
        result += current_duration;
        i++;
      }
      current_duration = 0;
    }
  }
  
  return result;
}

static inline void _draw_initial(
  const int _indentation_level,
  const char *_current_description,
  struct timespec *start
) {
  printf(
    "%s... %s",
    INDENT(_indentation_level),
    _current_description
  );
  fflush(stdout);
  
  clock_gettime(CLOCK_MONOTONIC_RAW, start);
}

static inline void _draw_final(
  const int _succeeded,
  const char *_current_description,
  const size_t len,
  struct timespec *start,
  struct timespec *end
) {
  clock_gettime(CLOCK_MONOTONIC_RAW, end);

  if (_slow == 0)
    _slow = _to_ms(_stringize(SLOW));
  
  if (_succeeded) {
    _passing++;
    printf(
      "\x1b[%luD\x1b[0K" ANSI_GREEN(CHECKMARK) " %s ",
      3 + len,
      _current_description
    );
  } else {
    _failing++;
    printf(
      #ifdef CROSSMARK
      "\x1b[%luD\x1b[0K" ANSI_RED(CROSSMARK " %s "),
      #else
      "\x1b[%luD\x1b[0K" ANSI_RED("%d) %s "),
      #endif
      3 + len,
      #ifndef CROSSMARK
      error_i,
      #endif
      _current_description
    );
  }
  
  long ms = (end->tv_sec - start->tv_sec) * 1000 + (end->tv_nsec - start->tv_nsec) / 1000000;
  if (ms < _slow / 2)
    printf("\n");
  else if (ms > _slow / 2 && ms < _slow)
    printf(ANSI_YELLOW("(%ld ms)") "\n", ms);
  else
    printf(ANSI_RED("(%ld ms)") "\n", ms);
}

static void _handler(void) {
  printf("\n");
  
  if (_passing)
    printf(ANSI_GREEN("%d passing") "\n", _passing);
  
  if (_failing)
    printf(ANSI_RED("%d failing") "\n", _failing);
  
  printf("\n");
  
  for (int i = 0; i < error_i; i++) 
    printf(ANSI_RED("%d) %s") "\n", i + 1, error_messages[i]);
}

static inline void _register_handler(void) {
  static int _registered_handler = 0;
  
  if (_registered_handler)
    return;
  
  _registered_handler = 1;
  atexit(_handler);
}

static inline int _assert(int cond, int *_succeeded, const char *message) {
  if (*_succeeded && !cond) {
    *_succeeded = 0;
    error_messages[error_i++] = message;
  }
  return cond;
}

#define assert(cond) ( \
  _is_in_property \
  ? _assert_no_message(cond, &_data) \
  : _assert( \
    cond, \
    &_succeeded, \
    __FILE__ ":" _stringize(__LINE__) ": Assertion failed: " #cond "." \
    ) \
)

static inline int _assert_no_message(int cond, struct _pbt *data) {
  _data.just_failed = 0;
  data->just_failed = !cond;
  return cond;
}

static inline void _iterate(struct _pbt *data, char *ptr, char *last_ptr, int len) {
  if (data->just_failed && !data->is_reducing)
    data->is_reducing = 1;
  
  if (!data->is_reducing)
    switch (data->number_of_tries) {
      case 0:
        memset(ptr, 0x00, len);
        return;
      
      case 1:
        memset(ptr, 0xff, len);
        return;
      
      default:
        for (int i = 0; i < len; i++)
          ptr[i] = rand() % CHAR_MAX;
        return;
    }

  if (data->just_failed)
    memcpy(last_ptr, ptr, len);
  else
    memcpy(ptr, last_ptr, len);
  
  int operand = rand();
  int i = rand() % len;
  
  switch (rand() % 4) {
    case 0:
      ptr[i] >>= operand % CHAR_BIT;
      return;

    case 1:
      ptr[i] &= operand;
      return;

    case 2:
      if (i < len && len != 0)
        ptr[i + 1] = ptr[i];
      ptr[i] = 0x00;
      return;

    case 3:
      if (ptr[i] <= operand)
        ptr[i] = 1;
      else
        ptr[i] -= operand;
      return;
  }
}
#endif
