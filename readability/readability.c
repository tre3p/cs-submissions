#include <cs50.h>
#include <stdio.h>
#include <math.h>

string get_input();
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int coleman_liau_index(int letters_count, int word_count, int sentence_count);

int main(void)
{
    string text = get_input();
    int letters_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);

    int index = coleman_liau_index(letters_count, word_count, sentence_count);

    if (index <= 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

int coleman_liau_index(int letters_count, int word_count, int sentence_count)
{
    float avg_letters_per_hundred_words = ((float) letters_count / (float) word_count) * 100.00;
    float avg_sentences_per_hundred_words = ((float) sentence_count / (float) word_count) * 100.00;

    int index = round(0.0588 * (float) avg_letters_per_hundred_words - 0.296 * (float) avg_sentences_per_hundred_words - 15.8);
    return index;
}

int count_sentences(string text)
{
    int i = 0;
    int sentence_count = 0;

    do
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence_count++;
        }
        i++;
    }
    while (text[i] != '\0');

    return sentence_count;
}

int count_words(string text)
{
    int i = 0;
    int word_counter = 1;

    do
    {
        if (text[i] == ' ')
        {
            word_counter++;
        }
        i++;
    }
    while (text[i] != '\0');

    return word_counter;
}

int count_letters(string text)
{
    int i = 0;
    int letter_counter = 0;

    do
    {
        if (text[i] >= 'A' && text[i] <= 'z')
        {
            letter_counter++;
        }
        i++;
    }
    while (text[i] != '\0');

    return letter_counter;
}

string get_input()
{
    string in = get_string("Text: ");
    return in;
}