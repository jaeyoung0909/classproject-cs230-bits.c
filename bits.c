/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * fp_func4 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Operations allowed to use: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max # of operations: 30
 *   Points: 4
 */
unsigned fp_func4(unsigned uf) {
    int s = uf & (1<<31);
    int e = uf & ( ~(1<<31)>>23<<23);
    int f = uf & (~(1<<31)>>8);
    if((e == ((~(1<<31))>>23<<23))) return uf;
    else if(e==0) return (((uf<<1) & (~(1<<31)))|s);
    else return (s|(e+(1<<23))|f); 
}
/*
make three cases. one is nan. this case, just return uf. second e is 0. this case, shift whole uf one. last is just add one to e.
*/
/* 
 * is_addition_no_problem - Will it be okay(no overflow) when we add x and y?
 *   If there is an overflow, return 0. Otherwise, return 1.
 *   Example: is_addition_no_problem(0x80000000,0x80000000) = 0,
 *            is_addition_no_problem(0x80000000,0x70000000) = 1, 
 *   Operations allowed to use: ! ~ & ^ | + << >>
 *   Max # of operations: 20
 *   Points: 3
 */
int is_addition_no_problem(int x, int y) {
  return !(((~(x^y)&((x&y)^(x+y))))>>31);
}
/*
control the condition of overflow. that is x positive y positive and x+y negative or its opposite case. treat this overflow cases.
*/
/* 
 * is_x_fits_in_16_bit - Returns 1 if x fits in 16-bit, 2's complement.
 *   Examples: is_x_fits_in_16_bit(34000) = 0, is_x_fits_in_16_bit(-32768) = 1
 *   Operations allowed to use: ! ~ & ^ | + << >>
 *   Max # of operations: 8
 *   Points: 1
 */
int is_x_fits_in_16_bit(int x) {
  return !(x>>15)|!((x>>15)+1);
}
/*
divide two case. one is when x is positive another is negative. and express that by given operation.
*/
/* 
 * fp_func1 - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Operations allowed to use: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max # of operations: 30
 *   Points: 4
 */
unsigned fp_func1(unsigned uf) {
   int s = uf & 0x80000000;
   int e = uf & 0x7f800000;
   int f = uf & 0x007fffff;
   int gr = uf&3;
   if(e == 0x7f800000) return uf;
   else if(e==0||e==(1<<23)) {
	if (gr == 3) return (((uf & (~(1<<31)))>>1)|s)+1;
	else return (((uf & (~(1<<31)))>>1)|s);
   }
   else{
	return (s|(e+(1+~(1<<23)))|f);

    }
}
/*
similar method with *2. just consider round to even when e is zero or one.
*/

/* 
 * fp_func3 - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Operations allowed to use: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max # of operations: 10
 *   Points: 2
 */
unsigned fp_func3(unsigned uf) {
    
    if(((uf<<1>>24)==255)&(!!(uf<<9))) return uf;
    else return uf&(~(1<<31));
}
/*
divide two case. first is nan. just return uf. second case, just change 32's bit to 0.
*/

/* 
 * fp_func2 - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Operations allowed to use: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max # of operations: 30
 *   Points: 4
 */
int fp_func2(unsigned uf) {

    int s = !(uf>>31);
    int E = ((uf & 0x7f800000)>>23)-127;
    int f = uf & 0x007fffff;
    int notG = 0;
    int notR = 0;
    int notS = 0;
    int Esub23 = 23-E;
    int result1 =  ((f+0x800000)>>Esub23);
    int neg_result1 = ~result1+1;
    int result2 = result1 + 1;
    if (E>30) return 0x80000000u;
    else if (E<0) return 0;
    else{
	notG = !((1<<Esub23)&uf);
        notR = !((1<<(22-E))&uf);
        notS = !(uf<<(10+E));
	if ((E>=23)|(notR|(notG&notS))){
	    if (s) return result1;
	    else return neg_result1;
	}
	else{
	    if (s) return result2;
            else return ~result2+1; 
	}
    }
}
/*
just make 3 big case. over int, 0, others. when over int, return 0x8000..0u, and less than 0, return 0. divide two case in others. first is when E is bigger than 23 or not R or(not G and not S) is true and other cases.
first case, we just change float to int. other cases, we must change float to int after add one.
*/
/* 
 * extract_nth_byte - Extract the nth byte from a word x and return it.
 *   The index of the byte at LSB is 0.
 *   The index of the byte at MSB is 3.
 *   Examples: extract_nth_byte(0xFF34AB78,1) = 0xAB
 *   Operations allowed to use: ! ~ & ^ | + << >>
 *   Max # of operations: 6
 *   Points: 2
 */
int extract_nth_byte(int x, int n) {
  return (x>>(n<<3))&255;
}
/*
 we have to shift x 0, 8, 16,24. If we shift left n 2 times, we can mave that number as n changed. By and operation with 255, we can leave only last one byte.  
*/
/* 
 * substitute_byte(x,n,c) - In a word x, replace the nth byte with a new byte c.
 *   The index of the byte at LSB is 0.
 *   The index of the byte at MSB is 3.
 *   Examples: substitute_byte(0xffffffff,1,0xab) = 0xffffabff
 *   Assume that 0 <= n <= 3 and 0 <= c <= 255.
 *   Operations allowed to use: ! ~ & ^ | + << >>
 *   Max # of operations: 10
 *   Points: 3
 */
int substitute_byte(int x, int n, int c) {
  return (x&(~(255<<(n<<3))))+(c<<(n<<3));
}
/*
make a zero byte in n part and other part is one. use and operation to reduce x's n part and add operation with c. 
*/
/*
 * floor_log_2 - return floor(log base 2 of x), where x > 0
 *   Example: floor_log_2(16) = 4
 *   Operations allowed to use: ! ~ & ^ | + << >>
 *   Max # of operations: 90
 *   Points: 4
 */
int floor_log_2(int x) {
	int a = !(x>>16);
	int b,c,d,e;
	x = x<<(a<<4);
	b = !(x>>24);
	x = x<<(b<<3);
	c = !(x>>28);
	x = x<<(c<<2);
	d = !(x>>30);
	x = x<<(d<<1);
	e = !(x>>31);
  return (!a<<4)+(!b<<3)+(!c<<2)+(!d<<1)+!e;
}
/* 
 * is_fits_in_bits - Can x be represented in 2's complement integer with n-bit?
 *   1 <= n <= 32
 *   Examples: is_fits_in_bits(5,3) = 0, is_fits_in_bits(-4,3) = 1
 *   Operations allowed to use: ! ~ & ^ | + << >>
 *   Max # of operations: 15
 *   Points: 2
 */
int is_fits_in_bits(int x, int n) {
  return !(x>>(n+~0))|!((x>>(n+~0))+1);
}
/*
 * lbc - The number of consecutive one's in left-side (MSB-side) end of a word.
 *   Examples: lbc(-1) = 32, lbc(0xFFFF000F0) = 16
 *   Operations allowed to use: ! ~ & ^ | + << >>
 *   Max # of operations: 50
 *   Points: 4
 */
int lbc(int x) {

 	int a,b, c, d, e,subb, subc, subd, sube, helper1,helper2, helper3;
	a = x + (1<<16);
	a = (!(a>>16))<<4;

	subb = 32+(~(a+8)+1);
	b = (x + (1<<subb));
	b = (!(b>>subb))<<3; 

	helper1 = a+b;
  	subc = 32+(~(helper1+4)+1);
	c = (x + (1<<subc));
	c = (!(c>>subc))<<2;

	helper2 = helper1 + c;
	subd = 32+(~(helper2+2)+1);
	d = (x + (1<<subd));
	d = (!(d>>subd))<<1;

	helper3 = helper2 + d;
	sube = 32+(~(helper3+1)+1);
	e = (x + (1<<sube));
	e = !(e>>sube);

	return a+b+c+d+e+!(x+1);
}
/*
use the fact : +1 in first consecutive 1 place than after that 1, others become 0. divid and conquer to find that place. 
*/
/* 
 * bang - return !x, but you should not use ! in the function.
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Operations allowed to use: ~ & ^ | + << >>
 *   Max # of operations: 12
 *   Points: 4 
 */
int bang(int x) {
	int first = x | (x>>16);
	int second = first | (first>>8);
	int third = second | (second>>4);
	int fourth = third | (third>>2);
	int fifth = fourth | (fourth>>1);
  return (~fifth) & 1;
}
/*
divide x by half. the purpose of process is to find one in x. so compare with x and divided x. we can use these method similarily in other position. 
*/
/* 
 * is_subtraction_no_problem - Can x-y be done without any problem(overflow)?
 *   If there is an overflow, return 0. Otherwise, return 1.
 *   Example: is_subtraction_no_problem(0x80000000,0x80000000) = 1,
 *            is_subtraction_no_problem(0x80000000,0x70000000) = 0, 
 *   Operations allowed to use: ! ~ & ^ | + << >>
 *   Max # of operations: 20
 *   Points: 3
 */
int is_subtraction_no_problem(int x, int y) {
  return !(((x^y)&(~y^(x+~y+1)))>>31);
}
/*
similar way with is_addition _no_problem. just find two cases which make overflow. when x is posivie, y is negative, x-y is negative and its opposite case is overflow case.
*/
/* 
 * aeb - If even-numbered bit in a word is set at least one, return 1.
 *   Examples aeb(0xA) = 0, aeb(0xE) = 1
 *   Operations allowed to use: ! ~ & ^ | + << >>
 *   Max # of operations: 12
 *   Points: 2
 */
int aeb(int x) {
	int a,b,c,d;
	a = (x>>16)|x;
	b = (a>>8)|a;
	c = (b>>4)|b;
	d = (c>>2)|c;
  return (d&1);
}
/*
shift half to right. and use or operation until only two bits remain. If there is only one 1, then it remain in even ordered bit. Finally we can know at first bit wheather 1 is in even numbered bit.
*/
/* 
 * is_ge - Return 1 when x >= y, else return 0 
 *   Example: is_ge(4,5) = 1.
 *   Operations allowed to use: ! ~ & ^ | + << >>
 *   Max # of operations: 24
 *   Points: 3
 */
int is_ge(int x, int y) {
	int a = x+(~y+1);
  return !!((((x^y)&y)|(~(x^y)&~a))>>31);
}
/*
divde two case. one is overflow case when x,y have different direction.
overflow case is trivial. another case is sloved by calculate x-y.
*/
