#include <cs50.h>
#include <stdio.h>

const int LOWER_INPUT_BOUND = 0;
const int UPPER_INPUT_BOUND = 8;
const int SPACES_BETWEEN_HASHES = 2;
const string HASH_CHARACTER = "#";
const string SPACE_CHARACTER = " ";

int get_user_input();
void print_character(int amount, string character);

int main(void)
{
    int height = get_user_input();

    for (int i = 1; i <= height; i++) {
        int spaces_amount = height - i;
        print_character(spaces_amount, SPACE_CHARACTER);
        print_character(i, HASH_CHARACTER);
        print_character(SPACES_BETWEEN_HASHES, SPACE_CHARACTER);
        print_character(i, HASH_CHARACTER);
        print_character(1, "\n");
    }
}

void print_character(int amount, string character)
{
    for (int i = 0; i < amount; i++) {
        printf("%s", character);
    }
}

int get_user_input()
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n <= LOWER_INPUT_BOUND || n > UPPER_INPUT_BOUND);

    return n;
}