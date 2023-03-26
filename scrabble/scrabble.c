#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
const int ALPHABET_SHIFT = 65;
const int TO_LOWER_SHIFT = 32;

int compute_score(string word);
int count_letter_score(char letter);
int to_lowercase(char letter);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score1 < score2) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;
    int counter = 0;
    while (word[counter] != '\0')
    {
        if (word[counter] >= 65 && word[counter] <= 122) {
            char char_to_check = word[counter];

            if (char_to_check >= 97) {
                char_to_check = to_lowercase(char_to_check);
            }

            score += count_letter_score(char_to_check);
        }
        counter++;
    }

    return score;
}

int to_lowercase(char letter)
{
    return letter - TO_LOWER_SHIFT;
}

int count_letter_score(char letter)
{
    int alphabetically_shifted = letter - ALPHABET_SHIFT;
    int score = POINTS[alphabetically_shifted];

    return score;
}