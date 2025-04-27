#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int randNum; 
    srand(time(0));

    int userRange;
    printf("Enter your max range (1 to your number): ");
    scanf("%d", &userRange);

    //Generate a random number between 1 and userRange
    randNum = rand() % userRange + 1;

    int guess; 
    int attempts = 0;
    int lowBound = 1;
    int highBound = userRange;

    if (argc > 1 && strcmp(argv[1], "binary") == 0) {
        printf("Binary search mode active.\n");
        do {
            attempts++;
            guess = lowBound + (highBound - lowBound) / 2;
            printf("Attempt %d: Guessing %d (range: %d-%d)\n", attempts, guess, lowBound, highBound);
            if (guess < randNum) {
                printf("Too low!\n");
                lowBound = guess + 1; 
            } else if (guess > randNum) {
                printf("Too high!\n");
                highBound = guess - 1;
            }
        } while (guess != randNum); 
        printf("Found it! The number is %d (solved in %d attempts).\n", randNum, attempts);
    } else {
        do {
            printf("Guess a number between 1 and %d: ", userRange);
            scanf("%d", &guess);

            if (guess < randNum) {
                printf("Too low! Try again.\n");
                attempts++;
            } else if (guess > randNum) {
                printf("Too high! Try again.\n");
                attempts++;
            } else {
                printf("Congratulations! You guessed the number %d in %d attempts.\n", randNum, attempts + 1);
            }
        } while (guess != randNum);
    }
    return 0;
}