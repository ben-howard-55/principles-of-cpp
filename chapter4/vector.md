# cpp Program Structure

## constant expressions

`constexpr int i = 1;` <- must be set at runtime, cannot be changed.
`const i = n;` <- once set, cannot be changed.

## logical comparisons

When evaluating `a<b` it evaluates to a `bool` either true or false. Therefore,`a<b<c` would be interpreted as `true<c || false<c` which would produce bugs. Instead result to using logical 'or' or logical 'and' (`|| or &&`) in between expressions that have more than 1 comparison `of logic.

## conversions

Make sure that the conversion you are applying is valid: e.g.

```cpp
// simple temperature conversion tool
double degrees_c;
cin >> degrees_c;

double degrees_f = 9/5 * degrees_c _+ 32; // integer division truncations
double degrees_f = 9.0/5 * degrees_c + 32; // correct double division
```

## if statement

No such thing as an `if-else` statement exists in cpp. It is simply a nested if statement in the else part of the first if statement:

```cpp
if (a == true) {
  std::cout << a;
} else if (b == true) {
  std::cout << b;
} else {
  std::cout << d;
}
```

## switch statement

In cpp switch statement comparison only works on => [integer, char, enumeration type]. You CANNOT switch on a string.

- can only use constant expressions for cases
- cannot use the same value for 2 cases
- cannot use several case labels for a single case
- must end each with break
  You can have multiple case labels for a single action:

````cpp
switch (unit) {
    case 'i' case 'j' case 'l':
        // do something
        break```;
    case 'c':
        // do something
        break;
    default:
        // do x;
        break;
    }
````

## iteration

`while` loops iterate until a certain exit criterion has been met. It evaluates in every iteration. In cpp:

```cpp
i = 10;
while (i >= 1) {
    std::cout << i;
    --i;
}
```

In the above example the `{}` represent a block or _compound statement_. The block can be empty.
`for` statements iterate until a certain criterion has been met.

```cpp
for (int i = 0; i < 100; ++i) {
    std::cout << i;
}
```

## functions

Must be declared before use. So can declare:

```cpp
int square(int);
```

or define the function (Which declares it simultaneously):

```cpp
int square(int x) return x*x;
```

## vectors

A vector is a sequence of elements that you can access by an index (array).
starts at index 0, ends at n-1. `v.size()` is used for accessing size.

The size of a vector does not need to be set and it can grow.

vector definition:

```cpp
vector<int> v = {5, 4, 3, 2, 1}; // vector of ints of size 5.
vector<int> vi(6); // vector of ints of size 6 initialized to 0s.
vector<std::string> vs(3); // vector of 3 empty strings ""

int size = v.size(); // get vectors size
```

## range-for-loop

```cpp
vector<int> v = {1, 2 , 3};
for (int x : v) {
    std::cout << x << `\n`
}
```

Interesting vector example for reading input in a loop.

```cpp
    for (double temp; std::cin>>temp;) {
        std::cout << temp;
    }
```

## Growing a vector

Often start with an empty vector and grow it to its desired size with `v.push_back(1);`. The new element is appended.

> push_back() is a member function call => meaning the function is a member function of vector
> member-function-call: object_name.member-function-name(args)
