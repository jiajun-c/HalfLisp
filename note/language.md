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


