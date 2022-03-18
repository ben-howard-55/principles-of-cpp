# Types and Objects in cpp

| A type is a set of possible values and a set of possible operations (for a given object).

- An object is memory in which holds a given type.
- A value is a set of bits in memory interpreted according to a type.
- A variable is a named object.
- A declaration is a statement that gives a name to an object.
- A definition is a declaration that sets aside memory for an object.

## type safety in cpp

In cpp every object is given a type when defined, however an operation can become NOT _type safe_ when a variable is used without being initialized. e.g.

```cpp
double x;

double y = x;
double z = 2.0 + x;
```

It is therefore, best practice in cpp to always initialize your variables with an initial value.

## safe conversions in cpp

- char to int
- char to double
- int to double
- bool to char
- bool to int
- bool to double

When it is believed that 'narrowing' could occur from unsafe type conversions the `{}`-list notation can be used to check conversions for bad values. e.g.

```cpp
char b1 {1000}; // error: narrowing
char b2 {48}; // OK
```
