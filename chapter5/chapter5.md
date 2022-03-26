# Errors in c++

## narrow cast
If we assign a variable a value that is 'too' large. e.g. `int x = 2.9;`, it is implicitly truncated. To prevent this we can use a `narrow_cast<template_argument>` to protect against narrowing and throw a runtime error.
```cpp
int x1 = narrow_cast<int>(2.9); // throws error
int x2 = narrow_cast<int>(2.0); // OK

```
The angular brackets are used to represent the template argument `<>`.

## pre-conditions
At the start of a function always check the pre-conditions. e.g. 
- We do not know who would call the functions
- The overhead is usually not enough to justify not having.
```cpp
int mcf(int a, int b) {
	// a must be less than b
	if (!a < b) {
		error("bad arguments for func");
	}
}
```
## post-conditions
At the end of a function we can provide a post-condition check. This is where we check the return value, before returning. This helps prevent errors from propagating through out our code.

## testing
examples.