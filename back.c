#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to simulate quantum communication
int quantumCommunication(char *aliceChoice, char *bobChoice)
{
    // Simulate quantum entanglement and measurement
    int entangledBit = rand() % 2;
    int aliceMeasurement = rand() % 2;
    int bobMeasurement;

    // Bob's choice is entangled with Alice's choice
    if (entangledBit == 0)
    {
        bobMeasurement = aliceMeasurement;
    }
    else
    {
        bobMeasurement = (aliceMeasurement + 1) % 2;
    }

    // Determine if there is an eavesdropper (50% chance)
    int eavesdropper = rand() % 2;

    // If there is an eavesdropper, change Bob's measurement
    if (eavesdropper == 1)
    {
        bobMeasurement = (bobMeasurement + 1) % 2;
    }

    // Determine if Alice and Bob's measurements match
    int keyBit;
    if (aliceMeasurement == bobMeasurement)
    {
        keyBit = 1; // Matching measurements, secure key bit
    }
    else
    {
        keyBit = 0; // Non-matching measurements, potential eavesdropping
    }

    // Update Alice's and Bob's choices based on the key bit
    aliceChoice[0] = (aliceChoice[0] == 'A') ? '0' + keyBit : '1' - keyBit;
    bobChoice[0] = (bobChoice[0] == 'A') ? '0' + keyBit : '1' - keyBit;

    return keyBit;
}

int main()
{
    srand(time(NULL));

    // Initial choices of Alice and Bob
    char aliceChoice[2] = "A";
    char bobChoice[2] = "B";

    // Simulate multiple rounds of quantum communication
    for (int round = 1; round <= 5; ++round)
    {
        int keyBit = quantumCommunication(aliceChoice, bobChoice);

        // Display the choices and key bit for each round
        printf("Round %d:\n", round);
        printf("Alice's Choice: %c\n", aliceChoice[0]);
        printf("Bob's Choice  : %c\n", bobChoice[0]);
        printf("Key Bit       : %d\n", keyBit);
        printf("------------\n");
    }

    return 0;
}
