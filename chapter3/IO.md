# IO

The `>>` operator is the 'get from' type. It is sensitive to type. For instance, in the below example the input will automatically be parsed to of type string and int due to input from `cin`. `cin` by default terminates the reading of strings due to _whitespace_ => [space, newline, tab].

```cpp
    // input: 'Hello 22'

    std::string name;
    int age;

    // below reads two 'strings' at once.
    std::cin >> name >> age;
```

Setting a string to: "" - initializes the string to contain only the 'space' character and due to the fact that the `>>` operator skips white spaces, these means that this value could not be read from the input.
