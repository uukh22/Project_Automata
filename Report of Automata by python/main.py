class DFA_State:
    def __init__(self):
        self.AcceptState = False
        self.transitions = {}


def main():
    Num_Of_States = int(input("Enter the number of states: "))
    alphabet = input("Enter the alphabet symbols: ")

    states = [DFA_State() for _ in range(Num_Of_States)]

    for eterate in range(Num_Of_States):
        for c in alphabet:
            nextState = int(input(f"In state ({eterate}), Enter next state for input [{c}]: "))
            states[eterate].transitions[c] = nextState

    Start_State = int(input("Enter the start state: "))

    Accept_State = input("Enter the accept states: ")
    for c in Accept_State:
        if c.isdigit():
            acceptState = int(c)
            states[acceptState].AcceptState = True
        else:
            print("Invalid character in accept states. Please enter digits only.")
            return 1  # Exit with an error code

    while True:
        test = input("Enter the string to test: ")

        Current_State = Start_State
        for c in test:
            Current_State = states[Current_State].transitions[c]

        result = "The DFA accepts the string." if states[
            Current_State].AcceptState else "The DFA does not accept the string."
        print(result)

        ForExit = input("For Another test press any key, \nFor exit press x: ")
        if ForExit == 'x':
            break


if __name__ == "__main__":
    main()
