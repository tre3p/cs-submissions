

#include <cs50.h>
#include <stdio.h>

int get_start_size_population();
int get_end_size_population(int start_size_population);
int calculate_years(int initial_size, int end_size);

int main(void)
{
    // TODO: Prompt for start size
    int start_size_population = get_start_size_population();
    // TODO: Prompt for end size
    int end_size_population = get_end_size_population(start_size_population);
    // TODO: Calculate number of years until we reach threshold
    int years_to_reach_population = calculate_years(start_size_population, end_size_population);
    // TODO: Print number of years
    printf("Years: %d\n", years_to_reach_population);
}

int calculate_years(int initial_size, int end_size)
{
    int years = 0;

    while (initial_size < end_size)
    {
        int born_lamas_count = initial_size / 3;
        int pass_lamas_count = initial_size / 4;
        initial_size = (initial_size + born_lamas_count) - pass_lamas_count;
        years++;
    }

    return years;
}

int get_start_size_population()
{
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);

    return n;
}

// Get's user end_size input and validates it
int get_end_size_population(int start_size_population)
{
    int n;
    do
    {
        n = get_int("End size: ");
    }
    while (n < start_size_population);

    return n;
}