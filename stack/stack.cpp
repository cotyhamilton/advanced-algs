//Coty Hamilton

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class infixConversion
{
    string infix, postfix;
    char top, input;
    int first, second, temp;
    stack<int> postStack;
    stack<char> inStack;

    void convertToPostfix()
    {
        for (int i = 0; i < infix.length(); i++)
        {
            input = (char)infix[i];                             // current character from input infix string

            if (infix[i] > 47 && infix[i] < 58)                 // if character is number or space
            {
                postfix += input;                               // append to postfix string
            }
            else if(infix[i] == 32)                             // if character is space
            {
                if (infix[i - 1] > 47 && infix[i - 1] < 58)     // and last character was number
                {
                    postfix += " ";
                }
            }
            else
            {
                if (!inStack.empty())
                {
                    top = (char)inStack.top();                  // variable to hold operator in top of stack

                    if (input == '(')
                    {
                        inStack.push(input);                    // push left paren always
                    }
                    else if(input == ')')                       // if input is right paren
                    {
                        while(inStack.top() != '(')
                        {
                            postfix += " ";
                            postfix += inStack.top();           // append to postfix string
                            inStack.pop();                      // and pop operators until matching left paren
                        }
                        inStack.pop();                          // pop the left paren
                    }
                    else if (precedence(top) < precedence(input))
                    {
                        inStack.push(input);                    // push operators with higher precedence
                    }
                    else if (precedence(top) == precedence(input))
                    {
                        postfix += " ";
                        postfix += inStack.top();               // for same precedence append postfix string
                        inStack.pop();                          // pop from stack
                        inStack.push(input);                    // push new operator
                    }
                    else
                    {
                        while(precedence(top) >= precedence(input) && !inStack.empty())
                        {
                            postfix += " ";
                            postfix += inStack.top();           // for lower precedence append postfix string
                            inStack.pop();                      // pop from stack 
                            if(!inStack.empty())
                            {
                                top = (char)inStack.top();      // update top variable for while loop
                            }
                        }
                        inStack.push(input);                    // push new operator
                    }
                }
                else
                {
                    inStack.push(input);                        // push operator to stack if empty
                }
            }
        }

        while(!inStack.empty())
        {
            postfix += " ";
            postfix += inStack.top();                           // append postfix string with leftover operators
            inStack.pop();                                      // in the stack and pop them
        }

        cout << postfix << " = ";
    }

    void evalPostfix()
    {
        for(int i = 0; i < postfix.length(); i++)
        {
            if((int)postfix[i] > 47 && (int)postfix[i] < 58)    // if char in postfix is number
            {
                temp = temp * 10 + (postfix[i] - '0');          // multiply temp by 10 and add new int from input
            }                                                   // for reading in multiple digits
            else if ((int)postfix[i] == 32)
            {
                if ((int)postfix[i-1] > 47 && (int)postfix[i-1] < 58)
                {
                    postStack.push(temp);                       // if current input is space and last character was number push temp to stack
                }
                temp = 0;                                       // reset temp
            }
            else                                                // if char is operator
            {
                first = postStack.top();                        // pop top two values in stack
                postStack.pop();
                second = postStack.top();
                postStack.pop();

                switch(postfix[i])                              // perform operation according to current operator in postfix string
                {
                    case '+': postStack.push(second + first);
                            break;
                    case '*': postStack.push(second * first);
                            break;
                    case '/': postStack.push(second / first);
                            break;
                    case '%': postStack.push(second % first);
                            break;
                    case '-': postStack.push(second - first);
                            break;
                }
            }
        }

        cout << postStack.top() << endl;                        // print answer
        postStack.pop();                                        // pop from stack
    }

    int precedence(int x)                                       // returns precedence value of operators
    {
        switch (x)
        {
            case '(': return 1;
            case '*': return 10;
            case '/': return 10;
            case '%': return 10;
            case '+': return 5;
            case '-': return 5;
        }
        return 0;
    }

    public:

        infixConversion(string x)
        {
            infix = x;
            postfix = "";
            temp = 0;
        }
        void getPostfix()
        {
            convertToPostfix();
            evalPostfix();
        }
};

class postfixConversion
{
    stack<string> inStack;
    string infix, postfix, first, second, temp;

    void convertToInfix()
    {
        for(int i = 0; i < postfix.length(); i++)
        {

            if((int)postfix[i] > 47 && (int)postfix[i] < 58)    // if char in postfix is number
            {
                temp += postfix.at(i);                          // append to temp variable for multiple digit numbers
            }
            else if ((int)postfix[i] == 32)                     // if space
            {
                if ((int)postfix[i - 1] > 47 && (int)postfix[i - 1] < 58)
                {
                    inStack.push(temp);                         // if last character was number, push temp to stack
                }
                temp = "";                                      // reset temp to empty string
            }
            else                                                // if char is operator
            {
                first = inStack.top();                          // pop top two values in stack
                inStack.pop();
                second = inStack.top();
                inStack.pop();

                switch(postfix[i])                              // insert operator between operands
                {
                    case '+': inStack.push(second + " + " + first);
                            break;
                    case '*': inStack.push(second + " * " + first);
                            break;
                    case '/': inStack.push(second + " / " + first);
                            break;
                    case '%': inStack.push(second + " % " + first);
                            break;
                    case '-': inStack.push(second + " - " + first);
                            break;
                }
                infix = "(" + inStack.top() + ")";              // parens around expression
                inStack.pop();
                inStack.push(infix);                            // push to stack
            }
        }
        infix = inStack.top();                                  // get final answer from stack and print
        inStack.pop();
        cout << infix << endl;
    }

    public:

        postfixConversion(string x)
        {
            postfix = x;
            temp = "";
        }
        void getInfix()
        {
            convertToInfix();
        }
};



int main()
{
    string infixInput, postfixInput, option;
    
    while (option != "q")
    {
        cout << "Enter 0 to convert infix to to postfix and evaluate\n";
        cout << "Enter 1 to convert postfix to infix\n";
        cout << "Enter q to quit\n";
        cin >> option;

        if (system("cls")) system("clear");

        if (option == "0")
        {
            cout << "Enter an infix expression\n";
            cin.ignore();
            getline(cin, infixInput);

            infixConversion myInfix(infixInput);
            myInfix.getPostfix();

            cout << endl;
        }

        else if (option == "1")
        {
            cout << "Enter a postfix expression\n";
            cin.ignore();
            getline(cin, postfixInput);

            postfixConversion myPostfix(postfixInput);
            myPostfix.getInfix();

            cout << endl;
        }
    }

    return 0;
}