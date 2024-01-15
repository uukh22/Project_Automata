#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct DFA_State
{
    bool AcceptState;
    map<char, int> transitions;
};

int main()
{
    int Num_Of_States;
    cout << "Enter the number of states: ";
    cin >> Num_Of_States;

    string alphabet;
    cout << "Enter the alphabet symbols: ";
    cin >> alphabet;

    vector<DFA_State> states(Num_Of_States);

    for (int eterate = 0; eterate < Num_Of_States; eterate++)
    {
        for (char c : alphabet)
        {
            int nextState;
            cout << "In state (" << eterate << ") , Enter next state for input [" << c << "]: ";
            if (!(cin >> nextState))
            {
                cerr << "Invalid input. Please enter integers only.\n";
                return 1; // Exit with an error code
            }
            states[eterate].transitions[c] = nextState;
        }
    }

    int Start_State;
    cout << "Enter the start state: ";
    if (!(cin >> Start_State))
    {
        cerr << "Invalid input for start state. Please enter an integer.\n";
        return 1; // Exit with an error code
    }

    string Accept_State;
    cout << "Enter the accept states: ";
    cin >> Accept_State;
    for (char c : Accept_State)
    {
        if (isdigit(c))
        {
            int acceptState = c - '0';
            states[acceptState].AcceptState = true;
        }
        else
        {
            cerr << "Invalid character in accept states. Please enter digits only.\n";
            return 1; // Exit with an error code
        }
    }

    while (true)
    {
        string test;
        cout << "Enter the string to test: ";
        cin >> test;

        int Current_State = Start_State;

        for (char c : test) Current_State = states[Current_State].transitions[c];

        cout << ((states[Current_State].AcceptState)?"The DFA accepts the string.\n":"The DFA does not accept the string.\n");
        cout << "For Another test press any Key, ";
        cout << "For exit press x: ";

        char ForExit; cin >> ForExit;

        if (ForExit == 'x') break;
    }
    return 0;
}
