#ifndef _BET_HPP
#define _BET_HPP 
 
using namespace std; 

/********************************************
 ************* PRIVATE MEMBERS **************
 ********************************************/

/******************************************************
 * Name: getPrecedence
 * Purpose: returns an integer based on the precedence
 *          of the operator or operand used 
******************************************************/
template <typename T> 
int BET<T> :: getPrecedence(const T& token) const {
    if(token == "*" || token == "/")                //printInfix only uses this function if its token is an operator
        return 3; 
    else
        return 2; 
} 

//PRINT INFIX 
template <typename T> 
void BET<T> :: printInfixExpression(BinaryNode *n) const {    //LrR 
    if(n != nullptr) {
        int nodePrec = getPrecedence(n->element);             //get the precedence of the current n node 

        //left subtree
        if(n->left != nullptr) {
            //check for operator or operand 
            if (n->left->element == "+" || n->left->element == "-" ||
                n->left->element == "*" || n->left->element == "/") {

                int leftPrec = getPrecedence(n->left->element);         
                
                //compare precedence of child with parent node
                if(leftPrec < nodePrec) { 
                    cout << "( "; 
                    printInfixExpression(n->left); 
                    cout << ") "; 
                }
                else 
                    printInfixExpression(n->left); 
            }
            else
                cout << n->left->element << " "; 
        }

        //print element of current node 
        cout << n->element << " "; //i adds spaces within each infix expression for visual purposes

        //right subtree
        if(n->right != nullptr) {
            if (n->right->element == "+" || n->right->element == "-" ||
                n->right->element == "*" || n->right->element == "/") {

                //use getPrecedence function
                int rightPrec = getPrecedence(n->right->element);

                //compare 
                if(rightPrec < nodePrec) {
                    cout << "( "; 
                    printInfixExpression(n->right); 
                    cout << ")"; 
                }
                else 
                    printInfixExpression(n->right); 
            }
            else   
                cout << n->right->element << " ";
        }
    }
}

//PRINT POSTFIX
template <typename T> 
void BET<T> :: printPostfixExpression(BinaryNode *n) const {  //LRr (postfix)
    if(n != nullptr) {
        printPostfixExpression(n->left);        //left subtree recursive print
        printPostfixExpression(n->right);       //right subtree recursive print 
        cout << n->element << " ";              //print element of current node 
    }
}

//MAKE EMPTY
template <typename T> 
void BET<T> :: makeEmpty(BinaryNode * &t) {
    if (t != nullptr) {
        makeEmpty(t->left);
        makeEmpty(t->right); 
        delete t;               //must delete node itself
    }
    t = nullptr; 
}

//CLONE 
template <typename T> 
typename BET<T> :: BinaryNode * BET<T> :: clone(BinaryNode *t) const {
    if(t == nullptr)
        return nullptr; 
    else 
        return new BinaryNode {t->element,clone(t->left), clone(t->right)};    //return newly created node 
} 

//SIZE
template <typename T> 
size_t BET<T> :: size(BinaryNode *n) const {
    if(n != nullptr) {
        return (1 + size(n->left) + size(n->right));    //return size of 1 (current node) + size of the left and right subtree nodes
    }
    else 
        return 0; 
}

//NUMBER OF LEAVES 
template <typename T> 
size_t BET<T> :: leaf_nodes(BinaryNode *t) const {
    if(t == nullptr) 
        return 0; 
    else if(t->left == nullptr && t->right == nullptr)      //if the left and right subtrees are nullptrs the current node is the only one
        return 1;
    else 
        return (leaf_nodes(t->left) + leaf_nodes(t->right)); 
}


/********************************************
 ************* PUBLIC MEMBERS ***************
 ********************************************/
//DEFAULT CONSTRUCTOR 
template <typename T> 
BET<T> :: BET() {
    root = nullptr;     //only has a root which points to nothing
}

//ONE-PARAMETER CONSTRUCTOR
template <typename T> 
BET<T> :: BET(const string& postfix) {
    root = nullptr; 
    buildFromPostfix(postfix);  //builds binary tree using postfix expression
}

//COPY CONSTRUCTOR 
template <typename T> 
BET<T> :: BET(const BET& rhs) {
    root = nullptr;            //initialize 
    root = clone(rhs.root);    //copies all the nodes in the tree that the root points to 
}           

//DESTRUCTOR 
template <typename T> 
BET<T> :: ~BET() {
    makeEmpty(root); 
}

//BUILD TREE
template <typename T> 
bool BET<T> :: buildFromPostfix(const string& postfix) {
    stringstream ss(postfix);       //declare string stream 
    string token; 
    stack<BinaryNode*> tokenStack;  //create a stack to push each symbol on to
    BinaryNode* newRoot = nullptr;  

    //while there are tokens left 
    while(getline(ss, token, ' ')) {
        //both functions from cctype library
        if(isdigit(token[0]) || isalpha(token[0])) {                       
            BinaryNode* newNode = new BinaryNode(token); 
            tokenStack.push(newNode); 
        }
        //checks if operator
        else if(token == "+" || token == "-" || token == "*" || token == "/") {
            //return false if there are not two operands already in stack   
            if(tokenStack.size() < 2) {                                         
                cout << "Invalid expression!" << endl;                     
                return false; 
            }
            else {
                //assign right and left nodes 
                BinaryNode* right = tokenStack.top();                                       
                tokenStack.pop(); 
                BinaryNode* left = tokenStack.top(); 
                tokenStack.pop(); 

                //assign right and left nodes to the new final node 
                BinaryNode* finalNode = new BinaryNode(token, left, right); 
                tokenStack.push(finalNode);    
            }     
        }
        else 
            return false;  
    }

    //set root to the top of the stack
    newRoot = tokenStack.top(); 

    //if statements to check the validity of stack top 
    if(tokenStack.size() != 1)  {
        cout << "Invalid expression!" << endl; 
        return false;
    }

    //pass validity checks 
    root = newRoot; 
    tokenStack.pop(); 

    return true; 
}


//ASSIGNMENT OPERATOR 
template <typename T> 
const BET<T>& BET<T> :: operator= (const BET & rhs) {
    if(this != &rhs) {          
        makeEmpty(root);        //clear out current tree

        root = clone(rhs.root); //call clone function to preform copy 
    }

    return *this; 
}

//INFIX PRINT 
template <typename T>
void BET<T> :: printInfixExpression() const {
    printInfixExpression(root);          //use recursive private function 
}

//POSTFIX PRINT
template <typename T> 
void BET<T> :: printPostfixExpression() const {
    printPostfixExpression(root);       //use recursive private function 
}

//SIZE 
template <typename T> 
size_t BET<T> :: size() const {
    return size(root);                  //use recursive private function 
}                              

//NUMBER OF LEAVES 
template <typename T> 
size_t BET<T> :: leaf_nodes() const {
    return leaf_nodes(root);           //use recursive private function 
}                        

//EMPTY 
template <typename T> 
bool BET<T> :: empty() const {
    if(root == nullptr) 
        return true; 
    else 
        return false; 
} 

#endif
