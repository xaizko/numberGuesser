#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int randNum; 
    srand(time(0));

    int userRange;
    printf("Enter your max range (1 to your number): ");
    scanf("%d", &userRange);

    //Generate a random number between 1 and userRange
    randNum = rand() % userRange + 1;

    int guess; 
    int attempts = 0;

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
    return 0;
}