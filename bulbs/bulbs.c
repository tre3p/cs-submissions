#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
string get_input();
int get_char_count(string n);
int get_n_bit_of_char(char input, int n);

int main(void)
{
    string input = get_input();
    int counter = 0;

    do
    {
        for (int i = 7; i >= 0; i--)
        {
            int bite = get_n_bit_of_char(input[counter], i);
            print_bulb(bite);
        }
        printf("\n");
        counter++;
    }
    while (input[counter] != '\0');
}

int get_n_bit_of_char(char input, int n)
{
    char tmp_input = input;
    int counter = 0;

    do
    {
        if (n == 0)
        {
            return input % 2;
        }
        else if (tmp_input == 0)
        {
            return 0;
        }

        counter++;
        tmp_input /= 2;
    }
    while (counter != n);

    return tmp_input % 2;
}

int get_char_count(string n)
{
    int counter = 0;

    do
    {
        counter++;
    }
    while (n[counter] != '\0');

    return counter;
}

string get_input()
{
    string n = get_string("Message: ");
    return n;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}