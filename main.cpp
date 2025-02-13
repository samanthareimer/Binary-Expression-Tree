#include <iostream>
#include <string>
#include <sstream>
#include "bet.h"
using namespace std;

int main(void)
{
    BET<string> userInput;                  //users inputted postfix
    BET<string> exPostfix("4 5 + 5 6 + /"); //example
    BET<string> infix3;                     //to copy example using operator=
    BET<string> testCopy(exPostfix);        //COPY constructor 

    //EXAMPLE ONE (4 5 + 5 6 + /) --> ( 4 + 5 ) / ( 5 + 6 )
    cout << "\nPostfix Example: "; 
    exPostfix.printPostfixExpression(); 
    cout << "\nInfix conversion: "; 
    exPostfix.printInfixExpression();
    cout << "\nNumber of Leaf Nodes in expression: " << exPostfix.leaf_nodes() << endl;
    cout << "Size of expression: " << exPostfix.size() << endl;
    
    //SHOWING TEST FOR OPERATOR= OVERLOAD 
    cout << "\nTesting the assignment operator= overload" << endl;
    infix3 = exPostfix;
    cout << "Copied infix: "; 
    infix3.printInfixExpression();
    cout << "\nSize of new infix (copied from first example) is: " << infix3.size() << endl;
    
    //SHOWING TEST FOR COPY CONSTRUCTOR 
    cout << "\nTesting the copy constructor for the testCopy. " << endl;
    cout << "testCopy: "; 
    testCopy.printInfixExpression();
    cout << "\nSize of copy using copy constructor is: " << testCopy.size() << endl;

    //LOOP FOR USER INPUTTED POST FIX. Stops when user inputs exit
    while(1){
        string instr;

        //PROMPT
        cout << "\nDIRECTIONS: Enter a postfix expression WITH SPACES when prompted."  
             << "\nhelp: To see these directions again"
             << "\nexit: To stop program" << endl; 

        cout << "\nEnter a postfix notation (variables allowed): ";
        getline(cin, instr);

        if(instr == "help") {
            cout << "\nDIRECTIONS: Enter a postfix expression WITH SPACES when prompted."  
                 << "\nhelp: To see these directions again"
                 << "\nexit: To stop program" << endl;
        }
        else if(instr == "exit") {
            cout << "Exiting program..." << endl; 
            break; 
        }
        else{
            userInput.buildFromPostfix(instr);
            cout << "Infix conversion: "; 
            userInput.printInfixExpression();   
            cout << "\nNumber of Leaf Nodes in expression: " << userInput.leaf_nodes() << endl;
            cout << "Size of expression: " << userInput.size() << endl;
        }
    }

    return 0;
}
