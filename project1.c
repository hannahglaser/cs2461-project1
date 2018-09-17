#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
Group number:1
Team members:
Hannah Glaser
Melody Lee
Tyller Zhou
*/

/* PROJECT 1 */

/* In this assignment you will examine a program consisting of a number of functions - labelled ques1.c to ques15.c -- each of which tests your knowledge of bitwise C operations. Your goal is to determine what each function does and if there
is a simpler way to implement the function. There are two parts to the requirements.  */

/* Assume 32 bit integers */

/* PART A: You need to determine what each function is doing .
You have to determine what each function is doing WITHOUT running the code. You must provide an explanation for your answer - you will get no credit if you correctly identify the function but provide  an incorrect or insufficient/incomplete explanation.
 Once you determine the function, you should run the code to check your answer.
To run the code to test your function, you will need to insert appropriate C code to call the function and print out the result.
 Once you are done showing what each function does, you should then answer part b. */

/* PART B: For each function, can you write a simpler equivalent function in C (using any C operators) that produces the same result.
 By simpler, we are interested in fewer operations in C but also more readable code. */


/*
 As an example, consider the answers to function ques0 - which you worked out in class.

 HANDIN Instructions: You must write out your answers to Part A in a report to be submitted (as a tarfile or zipfile, along with your code) - in addition to the report, you can include comments in your code that may provide a secondary explanation (in case
 your report has errors). You MUST provide an explanation for what the function does and justify your answer. Simply providing an example is NOT an explanation - so don't expect any credit if
 your answers are simply a collection of examples or code comments. You are welcome to provide formal proofs where appropriate, but use your judgement on whether to pursue a formal proof or not. It is preferable to write your answers as comments in the code - but do not feel pressured to do so.
 For part B, write out your code in this file with the answer (a simpler code if it exists) after each of the assigned functions in a manner similar to the example shown in ques0.c (i.e., the answer to function ques7.c should be named ans7.c).

 IMPORTANT: The code you submit must compile correctly (using gcc). If the code you submit does not compile without errors, you will get a zero for Part B of this project.

 GRADING: Each question has a specific number of points (i.e., not all questions have the same level of difficulty). Your grade will be based
 on the correctness of your answer, expressing the answer as a logical function where possible, and the efficiency and readability of your rewritten code.

 Collaboration: You can discuss the project with your teammate. You CANNOT refer to online sources to get help; you can refer to the C syntax documentations. Your report must include names of both members of the team -- failure to do so would imply you are claiming you worked on your own, and may constitute a violation of academic integrity policies.*/

/* EXAMPLE
 this function is similar to CallMeLast in the inclass exercises */
/*  function ques0 returns 1 if x=y and returns 0 if x is not equal to y */
/* the function ans0 does the same in two C statements */

int ques0(int x, int y){
    int temp;
    temp = ~y;
    temp = temp +1;
    temp = temp + x;
    return !(temp);
}

/* Answer to PART B: */
int ans0(int x, int y){
    int z=0;
    if (x==y)  z= 0;
    else z= 1;

    return z;
}

/* QUESTIONS */

/* question 1 */
int ques1(int x) {
    int z;
    int y  = ~x+1;
    z= (~(y|x));
    z = (z >> 31);

    return (z & 1);

}
/* question 1 answer */
int ans1(int x){
    return (x == 0);
}

/* question 2 */
int ques2(int x) {
    int mask = x>>31;
    int y = (x ^ mask);
    int z = (~mask + 1); //Taking 2s compliment

    return (y+z);
}
/* question 2 answer */
int ans2(int x){
    return abs(x);
}

/* question 3 */
int ques3(int x){
    int y = !x;
    int z = x >> 31;
    z = z | y;

    return !z;
}
/* question 3 answer */
int ans3(int x){
    return (x > 0);
}

/* question 4 */
/* Assume 0 <= n <= 32 */
int ques4(int n) {
    int x = (!!n) << 31;
    x = x >> 31;
    int y = (1 << 31);
    y = y >> (n + (~0));

    return x & y;
}
/* question 4 answer */
int ans4(int n) {
    if (n == 0) {
        return 0;
    } 
    else if (n > 0 && n <= 32) {
        return (int) -(pow(2,(32-n)));
    }
}

/* question 5 */
int ques5(int x) {
    int result = (x<<31);
    result = (result >> 31);

    return result;

}
/* question 5 answer */
int ans5(int x) {
    // If x is odd, x & 1 results in 1 and method returns -1.
    // If x is even, x & 1 results in 0 and method returns 0. 
    return (x & 1) * -1;
}

/* question 6 */
int ques6(void) {
    int byte = 0x55;
    int word = byte | byte<<8;

    return word | word<<16;
}
/* question 6 answer */
int ans6(void) {
    return 1431655765;
}

/* question 7 */
int ques7(int x) {

    return x & (~x+1);
}
/* question 7 answer */
int ans7(int x) {
    // If x is odd
    if (x & 1) {
        return 1;
    }
    // If x is even
    else {
        return abs(x);
    }
}

/* question 8 */
int ques8(int x) {
    int y = x >> 31;
    int z = !!x;

    return y | z;
}
/* question 8 answer */
int ans8(int x) {
    // x is positive
    if (x > 0) {
        return 1;
    }
    // x is negative
    else if (x < 0) {
        return -1;
    }
    // x is zero
    else {
        return 0;
    }
}

/* question 9 */
int ques9(int x, int n, int c) {
    int n8 = n << 3;
    int mask = 0xff << n8;
    int cshift = c << n8;
    int z= (x & ~mask);

    return (z  | cshift);
}
/* question 9 answer */


/* question 10 */
int ques10(int x) {
	int y = !!x;
	int z = (!(x+x));

    return y & z;
}
/* question 10 answer */
int ans10(int x) {
    return 0;
}

/* question 11 */
int ques11(int x, int y) {
	int a = x >> 31;
	int b = y >> 31;

    return !((!a & b) | (!(a ^ b) & (y+~x)>>31));
}
/* question 11 answer */


/* question 12 */
int ques12(int x, int m, int n) {
    int a = ~m+1;
    int b = ~x +1;
    a = x + a;
    b = b + n;

    return !((a|b) >> 31);
}
/* question 12 answer */
int ans12(int x, int m, int n) {
    if (x <= n && x >=m) {
        return 1;
    }
}

/* question 13 */
int ques13(int x) {

    int mask1, mask2, mask4, mask8, mask16;

    mask2 = 0x33 + (0x33 << 8);
    mask2 += mask2 << 16;
    mask1 = mask2 ^ (mask2 << 1);
    mask4 = 0x0F + (0x0F << 8);
    mask4 += mask4 << 16;
    mask8 = 0xFF + (0xFF << 16);
    mask16 = 0xFF + (0xFF << 8);

    x = (x & mask1) + ((x >> 1) & mask1);
    x = (x & mask2) + ((x >> 2) & mask2);
    x = (x & mask4) + ((x >> 4) & mask4);
    x = (x & mask8) + ((x >> 8) & mask8);
    x = (x & mask16) + ((x >> 16) & mask16);

    return x;
}
/* question 13 answer */
int ans13(int x) {
    int bit;
    int count = 0;
    for (int i = 0; i < 32; i++) {
        // Shift bit by bit to the right
        bit = x >> i;
        // If the rightmost bit of the current shift is 1, increment count
        if (bit & 1) {
            count++;
        }
    }
    return count;
}

/* question 14 */
int ques14(int x) {
    int result = 0;
    int i;

    for (i = 0; i < 32; i++)
        result ^=  (x >> i) & 0x1;

    return result;
}
/* question 14 answer */
int ans14(int x) {
    int bit;
    int count = 0;
    for (int i = 0; i < 32; i++) {
        bit = x >> i;
        if (bit & 1) {
            count++;
        }
    }
    if (count & 1) {
        return 1;
    }
    else {
        return 0;
    }
}

/* question 15 */
int ques15(int x, int n) {
    /* for ques15 only, assume n is not a negative number  */

    int temp = (1 << n);
    int z = temp + ~0;

    return (z & x);
}
/* question 15 answer */
int ans15(int x, int n) {
    return (x % ((int) pow(2,n)));
}


int main(){

    int a, b, c;

    int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;

 	printf("Enter first number, an integer stored into variable A preferably between 1 and 20:");
 	scanf ("%d",&a);
	printf("\n");
 	printf("Enter second number, an integer stored into variable B preferably between 1 and 20:");
 	scanf ("%d", &b);
 	printf("\n");
 	printf("Enter third number, an integer stored into variable C preferably between 1 and 20:");
 	scanf ("%d", &c);
	printf("\n");


	printf("you entered a= %d b= %d c= %d  \n", a,b,c);

    // To test/run the functions, you will need to input numbers and then call each of the functions, and print the return value 
    t1 = ques1(a);
    printf("ques1 output: %d \n", t1);
    t1 = ans1(a);
    printf("ans1 output: %d \n", t1);
    
    t2 = ques2(a);
    printf("ques2 output %d \n", t2);
    t2 = ans2(a);
    printf("ans2 output: %d \n", t2);
    
    t3 = ques3(a);
    printf("ques3 output %d \n", t3);
    t3 = ans3(a);
    printf("ans3 output: %d \n", t3);
    
    t4 = ques4(a);
    printf("ques4 output %d \n", t4);
    t4 = ans4(a);
    printf("ans4 output: %d \n", t4);
    
    t5 = ques5(a);
    printf("ques5 output %d \n", t5);
    t5 = ans5(a);
    printf("ans5 output: %d \n", t5);
    
    t6 = ques6();
    printf("ques6 output %d \n", t6);
    t6 = ans6();
    printf("ans6 output: %d \n", t6);
    
    t7 = ques7(a);
    printf("ques7 output %d \n", t7);
    //t7 = ans7(a);
    //printf("ans7 output: %d \n", t7);
    
    t8 = ques8(a);
    printf("ques8 output %d \n", t8);
    t8 = ans8(a);
    printf("ans8 output: %d \n", t8);
    
    t9 = ques9(a,b,c);
    printf("ques9 output %d \n", t9);
    //t9 = ans9(a,b,c);
    //printf("ans9 output: %d \n", t9);
    
    t10 = ques10(a);
    printf("ques10 output %d \n", t10);
    t10 = ans10(a);
    printf("ans10 output: %d \n", t10);
    
    t11 = ques11(a,b);
    printf("ques11 output %d \n", t11);
    //t11 = ans11(a,b);
    //printf("ans11 output: %d \n", t11);
    
    t12 = ques12(a,b,c);
    printf("ques12 output %d \n", t12);
    t12 = ans12(a,b,c);
    printf("ans12 output: %d \n", t12);
    
    t13 = ques13(a);
    printf("ques13 output %d \n", t13);
    t13 = ans13(a);
    printf("ans13 output: %d \n", t13);
    
    t14 = ques14(a);
    printf("ques14 output %d \n", t14);
    t14 = ans14(a);
    printf("ans14 output: %d \n", t14);
    
    t15 = ques15(a,b);
    printf("ques15 output %d \n", t15);
    t15 = ans15(a,b);
    printf("ans15 output: %d \n", t15);
    
    return 0;

}
