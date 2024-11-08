#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define STATES 3
#define SYMBOLS 2

bool transition[STATES][SYMBOLS][STATES] = {
    {
        {false, true, false}, 
        {true, false, false} 
    },
    // State 1 transitions
    {
        {false, true, false}, // 'a' transitions from state 1
        {false, false, true}  // 'b' transitions from state 1
    },
    // State 2 transitions (final state)
    {
        {false, false, false}, // 'a' transitions from state 2
        {false, false, false}  // 'b' transitions from state 2
    }
};

// Recursive function to simulate NFA
bool simulateNFA(int currentState, const char *input, int position) {
    if (position == strlen(input)) {
        // If we are at the end of the input, check if we're in an accepting state
        return currentState == 2;
    }

    int symbol = input[position] == 'a' ? 0 : 1;

    // Traverse through all possible next states
    for (int nextState = 0; nextState < STATES; nextState++) {
        if (transition[currentState][symbol][nextState]) {
            if (simulateNFA(nextState, input, position + 1)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    char input[100];
    printf("Enter a string of 'a' and 'b': ");
    scanf("%s", input);

    if (simulateNFA(0, input, 0)) {
        printf("The string is accepted by the NFA.\n");
    } else {
        printf("The string is rejected by the NFA.\n");
    }

    return 0;
}
