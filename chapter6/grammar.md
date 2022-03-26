# Grammars
A grammar is an ordered list of rules and patterns that we follow to produce an output. e.g. english.
The grammar receives a token or list of tokens that is defined for the specific problem.

# simple calculator grammar and tokens
token:
```cpp
class Token {
public:
	// public interface of type
	char kind;
	double value;
private:
	// hidden implementation details
}
```
grammar for a simple expression:
Expression:
	Term
	Expression '+' Term
	Expression '-' Term
Term:
	Primary
	Term '*' Primary
	Term '/' Primary
	Term '%' Primary
Primary:
	Number
	'(' Expression ')'
Number:
	floating-point-literal

## writing a grammar
1. Distinguish a rule from a token
2. Put one rule after another (sequencing)
3. Express alternative patterns (alternation)
4. Express a repeating pattern (repetition)
5. Recognise the grammar rule to start with

## turning grammar into code
Simplest form: Write a function for each rule and use our Token to represent tokens. This is called a parser.
## Functions:
Token get_token(); // reads chars and creates tokens
double expression(); // deal with + and -
double term(); // deal with *,/,%
double primary() // deal with numbers and parentheses
