#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure for a patient
struct Patient {
    char name[20];
    int priority;
};

// Priority Queue
struct Patient queue[MAX];
int count = 0;

// Function to add a patient
void addPatient(char name[], int priority) {
    if (count == MAX) {
        printf("Queue is full!\n");
        return;
    }

    strcpy(queue[count].name, name);
    queue[count].priority = priority;
    count++;

    printf("Patient %s added successfully.\n", name);
}

// Function to treat the next patient
void treatNextPatient() {
    if (count == 0) {
        printf("No patients waiting.\n");
        return;
    }

    // Find patient with smallest priority number
    int highestPriority = 0;

    for (int i = 1; i < count; i++) {
        if (queue[i].priority < queue[highestPriority].priority) {
            highestPriority = i;
        }
    }

    printf("Treating patient: %s (Priority %d)\n",
           queue[highestPriority].name,
           queue[highestPriority].priority);

    // Remove the treated patient
    for (int i = highestPriority; i < count - 1; i++) {
        queue[i] = queue[i + 1];
    }

    count--;
}

// Main function
int main() {
    // Add the patients given in the challenge
    addPatient("P1", 3);
    addPatient("P2", 1);
    addPatient("P3", 2);
    addPatient("P4", 1);
    addPatient("P5", 3);
    addPatient("P6", 2);

    printf("\n--- Treatment Order ---\n");

    // Treat 3 patients first
    treatNextPatient();
    treatNextPatient();
    treatNextPatient();

    // Add a new Emergency patient
    printf("\n--- New Emergency Patient Arrived ---\n");
    addPatient("P7", 1);

    printf("\n--- Remaining Treatment Order ---\n");

    // Treat everyone remaining
    treatNextPatient();
    treatNextPatient();
    treatNextPatient();
    treatNextPatient();

    return 0;
}
