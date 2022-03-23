# The languages

The programming language is very similar to the real language.There are the rules and the 
structure.

## Parser combinators 
mps is Parser combinator library, which allows you to build program that understand
and process partcular language. 

## Coding grammars
So what does the code that looks like a grammer?
The language we are going to define is as follows.
> An Adj is like "wow", "many", "so" 
> A Noun is like "lisp", "language"
> A phrase is an Adj followed by a Noun
> A Dog is zero or more phrases 

Then you can build it in the mpc
```c
mpc_parser_t* Adj = mpc_or(4,
    mpc_sym("wow"), mpc_sym("many"),
    mpc_sym("dalao"), mpc_sym("such")
);
```

因为大佬都过于抽象，所以是adj

If we wants to define a phrase(a phrase is usually a combination of the n and the adj)

So we can use the `mpc_and` to solve it. 
```c
mpc_parser_t\* phrase = mpc_and(2, mpcf_strfold,Adj,n,free);
```
The Adj and the n is the things define by myself, while the free and teh 
mpcf_strfold will be explained in the following chapters.


## Natural grammars

mps makes it more natural for us to write grammer.

Using the mpcf_strfold or the free can make it easier for us to join or discard 
inputs.

```c
mpc_parser_t* Adjective = mpc_new("adjective");
mpc_parser_t* Noun      = mpc_new("noun");
mpc_parser_t* Phrase    = mpc_new("phrase");
mpc_parser_t* Doge      = mpc_new("doge");

mpca_lang(MPCA_LANG_DEFAULT,
  "                                           \
    adjective : \"wow\" | \"many\"            \
              |  \"so\" | \"such\";           \
    noun      : \"lisp\" | \"language\"       \
              | \"book\" | \"build\" | \"c\"; \
    phrase    : <adjective> <noun>;           \
    doge      : <phrase>*;                    \
  ",
  Adjective, Noun, Phrase, Doge);

/* Do some parsing here... */

mpc_cleanup(4, Adjective, Noun, Phrase, Doge);
```

The special symbols used to define the rukes on the right hand side works as follows.
|character|the meaning|
|-|-|
|"ab"|The string ab is required|
|'a'|The character a is required|
|'a' 'b'|First the a is required and the b is required|
|'a'\|'b'|The 'a' or the 'b' is required|
|'a'\*|zero or more 'a' are required|
|'a'+|One or more 'a' are required|
|<abbc>|The rule called abbc is required|







