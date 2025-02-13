# Binary Expression Tree
This project implements a Binary Expression Tree in C++ to convert inputted postfix expressions into infix expressions using recursive algorithms. The program supports error handling, printing, counting nodes and leaves, and memory management.

### Functions
- **Build from Postfix**: Builds a binary tree from postfix expression
- **Infix and Postfix Expressions**: Supports the printing of expressions in postfix and infix
- **Conversion**: Converts given postfix expressions into infix
- **Leaf Nodes**: The number of leaf nodes from the expression tree is counted and printed
- **Size**: Gives the total number of nodes in the tree
- **Copy Constructor and Assignment Operator**: Deep copy functionality for BET objects
- **Destructor**: Cleans up memory when a BET object is destroyed

### Example 
This is an example of user input for a postfix expression. Please note variables CAN be used in this implementation. However, everything should be spaced out. 
### Postfix Expression
```ex
x y z * + 
```
### Infix Conversion
```ex
x + y * z  
```

## File Listing
```
BinaryExpressionTree/
├── main.cpp
├── bet.h
├── bet.hpp
├── analysis.txt
├── README.md
└── Makefile
```
## How to Compile & Execute
### Compilation
To compile this project, run the following in your terminal:
```bash
make
```
This will build the executable BET.x

### Execution
After compiling, run the program with: 
```bash
make run
```
This will execute the Binary Expression Tree program and allow you to input a postfix expression you want to be converted to infix.

## Makefile Description
- **Make**: Builds the executable "BET.x" by compiling source files.
- **Clean**: Removes the unwanted executable and object files.
- **run**: Runs the executable BET.x

Use make clean to remove generated object and executable files. 


### Dependencies
The following libraries support this C++ program:
- **iostream**
- **string**
- **sstream**
- **cctype**
- **stack**



