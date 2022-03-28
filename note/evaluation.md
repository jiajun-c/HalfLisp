# Evaluation

## Tree 
After read the input, we still unable to evaluate it. 
The internal structure is what we saw printed out by the program in the previous chapters. It is called the abstract tree. 

Inside the mpc.h, can we see the structure of mpc_ast_t 
```c
typedef struct mpc_ast_t {
  char* tag;
  char* contents;
  mpc_state_t state;
  int children_num;
  struct mpc_ast_t** children;
} mpc_ast_t;
``` 

- The first field is the `tag`. When we point out the tree this was the information that preceded the content of the node,like the number|reg|expr 
- The next field is the `content`, it will content the actual content of the node, like the '5', '+', '-'
- The state contains the information about what state the parser was in 
- the children_num means how many children are in the tree, and the children is an array of these childern. 



