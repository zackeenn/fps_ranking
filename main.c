#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to display scores
void displayScores(int scores[], int size, char* title, int userScore) 
{
    printf("\n%s\n", title);
    for (int i = 0; i < size; i++) {
        if (scores[i] == userScore) {
            printf("Player %d (YOU): %d points\n", i+1, scores[i]);
        } else {
            printf("Player %d: %d points\n", i+1, scores[i]);
        }
    }
    printf("\n");
}

// Bubble Sort - Ascending Order
void bubbleSortAscending(int scores[], int size) {
    int temp;
    // Outer loop: controls the number of passes
    for (int i = 0; i < size - 1; i++) {
        // Inner loop: compares adjacent elements
        for (int j = 0; j < size - i - 1; j++) {
            // If current element > next element, swap
            
            if (scores[j] > scores[j + 1]) {
                temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
}

// Bubble Sort - Descending Order
void bubbleSortDescending(int scores[], int size) 
{
    int temp;
    // Outer loop: controls the number of passes
    for (int i = 0; i < size - 1; i++) {
        // Inner loop: compares adjacent elements
        for (int j = 0; j < size - i - 1; j++) {
            // If current element < next element, swap
            if (scores[j] < scores[j + 1]) {
                temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
}

int main() 
{

    //seed to generate different random numbers each run
    srand(time(NULL));

    //introduction to the program
    printf("Welcome to the FPS Ranking!\n");
    printf("This program ranks players based on their scores.\n");
    printf("Enter your player name and score: ");
    
    //struct to hold player information
    struct player
    {
        char name[50];
        int score;
    };
    struct player player;

    scanf("%s %d", player.name, &player.score);

    //array to hold 10 scores
    int scores[10];

    // Generate 9 random scores (50 to 350 points)
    printf("\nGenerating scores for other 9 players...\n");
    for(int i = 0; i < 9; i++) {
        scores[i] = rand() % 301 + 50;  // 50 to 350 points
    }
    
    // Add user's score as the 10th element
    scores[9] = player.score;
    
    // Display original scores
    displayScores(scores, 10, "=== ORIGINAL SCORES ===", player.score);
    
    // Create copies for sorting
    int scoresAscending[10], scoresDescending[10];
    for(int i = 0; i < 10; i++) {
        scoresAscending[i] = scores[i];
        scoresDescending[i] = scores[i];
    }
    
    // Apply Bubble Sort - Ascending
    bubbleSortAscending(scoresAscending, 10);
    displayScores(scoresAscending, 10, "=== ASCENDING RANKING (Worst to Best) ===", player.score);
    
    // Apply Bubble Sort - Descending  
    bubbleSortDescending(scoresDescending, 10);
    displayScores(scoresDescending, 10, "=== DESCENDING RANKING (Best to Worst) ===", player.score);
    
    printf("CHAMPION: Player with %d points!\n", scoresDescending[0]);
    printf("Thanks for playing, %s!\n", player.name);

    return 0;
}

