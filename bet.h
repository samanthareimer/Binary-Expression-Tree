#ifndef BET_H
#define BET_H

#include <string> 
#include <iostream>
#include <sstream> 
#include <cctype> 
#include <stack> 
using namespace std; 

template <typename T> 
class BET {
    private: 
        //nested BinaryNode class 
        struct BinaryNode {
            T element; 
            BinaryNode *left; 
            BinaryNode *right; 

            //Constructor for BinaryNode 
            BinaryNode(const T & e, BinaryNode *l = nullptr, BinaryNode *r = nullptr) 
                : element{e}, left{l}, right{r} {}
        }; 
        
        //root element 
        BinaryNode *root; 

        void printInfixExpression(BinaryNode *n) const;     //print infix output of string expression
        void printPostfixExpression(BinaryNode *n) const ;  //print postfix expression of inputted string
        void makeEmpty(BinaryNode* &t);                     //remove all nodes in the subtree t points to 
        BinaryNode * clone(BinaryNode *t) const;            //copy nodes in subtree that t points to 
        size_t size(BinaryNode *t) const;                   //# of nodes t points to in subtree
        size_t leaf_nodes(BinaryNode *t) const;             //# of leaf nodes t points to in subtree
                                                    
        int getPrecedence(const T& token) const;           //*** PRECEDENCE GETTER FUNCTION *** 

    public: 
        BET();                          //default constructor 
        BET(const string& postfix);     //one-parameter constructor
        BET(const BET&);                //copy constructor 
        ~BET();                         //destructor

        bool buildFromPostfix(const string& postfix);         //function to build tree from postfix string
        const BET & operator= (const BET &);                  //assignment operator -- deep copy 
        void printInfixExpression() const;                    //print infix. use private (recursive) version
        void printPostfixExpression() const;                  //print postfix. use private (recursive) version
        size_t size() const;                                  //# of nodes in the tree (uses private func)
        size_t leaf_nodes() const;                            //# of leaves in the tree (uses private func)
        bool empty() const;                                   //true if empty, false if not

};
    
#include "bet.hpp"

#endif
