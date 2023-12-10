#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Quantum bit representation
typedef struct {
    int value;  // 0 or 1
} QBit;

// Function to prepare a qubit with a random value (0 or 1)
QBit prepareQubit() {
    QBit qubit;
    qubit.value = rand() % 2;
    return qubit;
}

// Function to measure a qubit and return the result (0 or 1)
int measureQubit(QBit qubit) {
    return rand() % 2;
}

int main() {
    srand(time(NULL));

    // Simulation parameters
    int numBits = 10;

    // Alice prepares and sends qubits to Bob
    QBit aliceBits[numBits];
    for (int i = 0; i < numBits; ++i) {
        aliceBits[i] = prepareQubit();
    }

    // Bob measures the received qubits
    int bobResults[numBits];
    for (int i = 0; i < numBits; ++i) {
        bobResults[i] = measureQubit(aliceBits[i]);
    }

    // Display the simulation results
    printf("Simulation Results:\n");
    printf("  Alice's Bits: ");
    for (int i = 0; i < numBits; ++i) {
        printf("%d ", aliceBits[i].value);
    }
    printf("\n");

    printf("  Bob's Results: ");
    for (int i = 0; i < numBits; ++i) {
        printf("%d ", bobResults[i]);
    }
    printf("\n");

    return 0;
}
