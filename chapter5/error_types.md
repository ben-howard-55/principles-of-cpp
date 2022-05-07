# Errors

When designing a program, unless otherwise specified, the program should:

1. Should produce desired result for all legal inputs.
2. Should give reasonable error messages about all illegal inputs.
3. Need not worry about hardware, or OS errors.
4. Is allowed to terminate after an error.

Errors are reduced by organizing, debugging and testing, and ensuring remaining errors are not critical.

## sources of errors

- Poor specification
- Incomplete programs
- Unexpected arguments
- Unexpected inputs
- Unexpected state
- logical errors

## compile-time errors

These are errors found by the compiler. These are classified into differing

- syntax errors
- type errors

## link time errors

These are errors found by the linker when it is trying to combine objects into an executable program.

A program consists of several separately compiled parts called 'translation units'. Each function must also only be defined exactly once in a program. The TU must be used with exactly the same type in which ever location it is use (why headers exist).

### run-time errors

These are errors found by checks within the running program. Classified into the following categories:

Callee checking is recommended (function error checking) as a called function is a "

- hardware or OS
- library detected
- user code

When working with exceptions want to create own class specially for reporting errors. e.g.

```cpp
class Bad_calc { };

try {
    ...
}
catch (Bad_calc) {
    std::cout << "error: bad calc inputs given!";
}

// or

if (x < 0) throw Bad_calc{};
```

## logical errors
