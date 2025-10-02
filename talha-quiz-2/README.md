# Quiz 2

## Task 2.1 ‘do/while’ Statement
Write a C++ program which takes an integer input from the user, calculates the factorial of this number using ‘do/while’ statement and displays the result on
screen. Your program should have the following interface.
```
Enter any value to calculate its Factorial: 5
Factorial of 5 is: 120
```

## Task 2.2 ‘for’ Statement 
Write a C++ program which takes an integer input from user in the variable named ‘num’, calculates the sum of all integers from `1` to `‘num’` and displays this sum on screen. Your program should have the following interface.
```
Enter any value: 10
Sum of integers from 1 to 10 is: 55
```

## Task 2.3
Write a C++ program which reads in a number from user, stores it in a variable named `N` and calculates the sum of powers using the following formula.

```
Sum = 1^1 + 2^2 + 3^3 +……+N^N
```

Your program should have the following interface.
```
Enter a number: 4
Sum = 1^1 + 2^2 + 3^3 + 4^4 = 288
```

## Task 2.4: Functions with a Return Value
An integer is said to be a Perfect Number if the sum of its divisors, including `1` (but not itself), is equal to that number. 

For example, `6` is a perfect number, because `6 = 1+2+3`. 

Write a C++ function called `IsPerfect` that takes an integer as parameter and `returns 1` if the passed integer is a perfect number and `0` if it not a perfect number. 

Use this function in a C++ program that reads in an integer value from user into a variable named `N` and prints all perfect numbers between `1` and `N`. Print the divisors of each perfect number to confirm that the number is indeed a perfect number. Your program
should have the following interface.

## Task 2.5 Functions with Arguments and a Return Value
Write a function in C++ language that takes an integer `‘num’` as argument and returns the sum of all numbers between `1` to `num`. Use this function in a C++ program which takes an integer from user, stores it in a variable named `N` and displays the result of the following function.
```
F(N) = 1 + (1+2) + (1+2+3) + ......+ (1+2+...N)
```
Your program should have the following interface.
```
Enter any value of N: 5
F(5) = 1 + 3 + 6 + 10 + 15 = 35
```
