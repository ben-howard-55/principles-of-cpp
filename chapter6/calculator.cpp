#include "calculator.h"
#include "error.h"
#include "iostream"
#include "stdio.h"
#include <list>

class Token {
public:
  char kind;
  double value;
};

class TokenStream {
public:
    TokenStream();
    Token get();
    void putback(Token t);
private:
//    implementation details
    bool full {false};
    Token buffer;
};

void TokenStream::putback(Token t) {
    if (full) throw std::runtime_error ("putback() into a full buffer");
    buffer = t;
    full = true;
}

Token TokenStream::get() {
    if (full) {
        full = false;
        return buffer;
    }
    char ch;
    std::cin >> ch;

    switch (ch) {
        case '(': case ')': case '+':case '-':case '*':case '/':
            return Token {ch};
        case '0':case '1':case '2':case '3':case '4':case '5':
        case '6':case '7':case '8':case '9':
            std::cin.putback(ch);
            double val;
            std::cin >> val;
            return Token {'8', val};
        default:
            throw std::runtime_error ("Bad Token");
    }


}

double expression();

Token get_token() { return Token{'+'}; }

double primary() {
  Token token = get_token();

  switch (token.kind) {
      case '(': {
          double d = expression();
          token = get_token();
          if (token.kind != ')') throw std::runtime_error(") expected");
          return d;
      }
      case '8':
          return token.value;
      default:
          throw std::runtime_error ("primary expected");
  }
}

double term() {
  double left = primary();
  Token token = get_token();

  while (true) {
    switch (token.kind) {
    case '*':
        left *= primary();
        token = get_token();
        break;
    case '/': {
        double d = primary();
        if (d == 0) throw std::runtime_error("cannot divide by 0");
        left /= d;
        token = get_token();
        break;
    }
    default:
      return left;
    }
  }
}

double expression() {
  double left = term();
  Token token = get_token();

  while (true) {
    switch (token.kind) {
    case '+':
      left += term();
      token = get_token();
      break;
    case '-':
      left -= term();
      token = get_token();
      break;
    default:
      return left;
    }
  }
}

int main() {
    try {
        while(std::cin) {
            std::cout << '=' << expression() << '\n';
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

}
