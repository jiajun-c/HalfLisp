# Parsing

## Polish Notation
To try out the `mpc`, we're going to implement a simple grammer that resembles 
a mathematical subset of our lisp,it is called the polish Notation.

For example
```
1 + 2 + 3 => +1 2 3
6 + (2 * 3) => + 6 (* 2 9)
(10*2) / (4+2) => / (*10 2) (+ 4 2)
```
|The type|The definition|
|-|-|
|Program|The start of input, one or more expression, and the end of the input|
|Expression|either a Number or '(', an Operator, one or more Expression, and an ')'|
|Operator|'+','-'|
|Number| and optinal `-`, and one or more characters between 0 and 9|


## Regular Expression
It gives you a clear and precise control over what is matched and what isn't 
In the linux we always use the regular to match the expression.
|The character|The meaning|
|-|-|
|.|Any character is required|
|a|The character `a` is required|
|[abc]|Ang character in the [abc] is required|
|[a-f]|Ang character in range a to f is requied|
|a?|The character a is optinal|
|a\*|The zero or more character a are required|
|a+|one or more character of a are required|
|^|The start of input is required|
|$|The end of input is required|


## install mpc
mpc is a c library that helps you build the grammer of your language
You can install from the github. 
```shell
cc -std=c99 -Wall parsing.c mpc.c -ledit -lm -o parsing
```

## code example 
```c
/* Create Some Parsers */
mpc_parser_t* Number   = mpc_new("number");
mpc_parser_t* Operator = mpc_new("operator");
mpc_parser_t* Expr     = mpc_new("expr");
mpc_parser_t* Lispy    = mpc_new("lispy");

/* Define them with the following Language */
mpca_lang(MPCA_LANG_DEFAULT,
  "                                                     \
    number   : /-?[0-9]+/ ;                             \
    operator : '+' | '-' | '*' | '/' ;                  \
    expr     : <number> | '(' <operator> <expr>+ ')' ;  \
    lispy    : /^/ <operator> <expr>+ /$/ ;             \
  ",
  Number, Operator, Expr, Lispy);

```

