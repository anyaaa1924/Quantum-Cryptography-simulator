#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Quantum bit representation
typedef struct {
    int value;  // 0 or 1
} QBit;

// Alice prepares and sends a qubit to Bob
QBit alicePrepareQubit() {
    QBit qubit;
    qubit.value = rand() % 2;  // 0 or 1
    return qubit;
}

// Bob measures the received qubit
int bobMeasureQubit(QBit qubit) {
    // Bob's measurement randomly chosen
    return rand() % 2;  // 0 or 1
}

int main() {
    srand(time(NULL));

    // Simulation parameters
    int numBits = 10;

    // Alice prepares and sends qubits to Bob
    QBit aliceBits[numBits];
    for (int i = 0; i < numBits; ++i) {
        aliceBits[i] = alicePrepareQubit();
    }

    // Bob measures the received qubits
    int bobResults[numBits];
    for (int i = 0; i < numBits; ++i) {
        bobResults[i] = bobMeasureQubit(aliceBits[i]);
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

    // Check for eavesdropping
    int matchingBits = 0;
    for (int i = 0; i < numBits; ++i) {
        if (aliceBits[i].value == bobResults[i]) {
            matchingBits++;
        }
    }

    printf("Number of Matching Bits: %d\n", matchingBits);

    if (matchingBits == numBits) {
        printf("No eavesdropping detected. Secure key established!\n");
    } else {
        printf("Eavesdropping detected. Secure key compromised!\n");
    }

    return 0;
}
