#include <cs50.h>
#include <stdio.h>
#include <string.h>

long get_input();
int is_card_checksum_valid(long number);
string determine_card_issuer(long number);
int is_card_length_valid_by_issuer(string issuer, long number);
int get_card_length(long number);

int main(void)
{
    long a = get_input();
    int is_valid = is_card_checksum_valid(a);

    if (is_valid == 1)
    {
        string card_issuer = determine_card_issuer(a);
        if (strcmp(card_issuer, "INVALID\n") == 0)
        {
            printf("INVALID\n");
            return 0;
        }

        int is_length_by_issuer_valid = is_card_length_valid_by_issuer(card_issuer, a);
        if (is_length_by_issuer_valid == 1)
        {
            printf("%s", card_issuer);
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}

int is_card_length_valid_by_issuer(string issuer, long number)
{
    int card_length = get_card_length(number);
    if (strcmp(issuer, "AMEX\n") == 0 && card_length == 15)
    {
        return 1;
    }
    else if (strcmp(issuer, "VISA\n") == 0 && (card_length == 13 || card_length == 16))
    {
        return 1;
    }
    else if (strcmp(issuer, "MASTERCARD\n") == 0 && card_length == 16)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int get_card_length(long number)
{
    long tmp_number = number;
    int counter = 0;
    do
    {
        counter++;
    }
    while (tmp_number /= 10);

    return counter;
}

string determine_card_issuer(long number)
{
    long first_two_numbers = number;

    while (first_two_numbers >= 100)
    {
        first_two_numbers /= 10;
    }

    long first_number = first_two_numbers / 10;


    if (first_two_numbers == 34 || first_two_numbers == 37)
    {
        return "AMEX\n";
    }
    else if (first_two_numbers >= 51 && first_two_numbers <= 55)
    {
        return "MASTERCARD\n";
    }
    else if (first_number == 4)
    {
        return "VISA\n";
    }
    else
    {
        return "INVALID\n";
    }


}

int is_card_checksum_valid(long number)
{
    int digit_pos_counter = 1;
    int even_pos_digit_sum = 0;
    int uneven_pos_digit_sum = 0;

    long a = number;
    do
    {
        int backward_digit = a % 10;
        if (digit_pos_counter % 2 == 0)
        {
            int temp_even_pos_digit_sum = backward_digit * 2;

            if (temp_even_pos_digit_sum >= 10)
            {
                int temp_sum_of_each_digit = 0;
                do
                {
                    int single_num = temp_even_pos_digit_sum % 10;
                    temp_sum_of_each_digit += single_num;
                }
                while (temp_even_pos_digit_sum /= 10);

                even_pos_digit_sum += temp_sum_of_each_digit;
            }
            else
            {
                even_pos_digit_sum += temp_even_pos_digit_sum;
            }
        }
        else
        {
            uneven_pos_digit_sum += backward_digit;
        }

        digit_pos_counter++;
    }
    while (a /= 10);

    int card_nums_sum = even_pos_digit_sum + uneven_pos_digit_sum;

    if (card_nums_sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

long get_input()
{
    long n;
    do
    {
        n = get_long("Number: ");
    }
    while (n <= 0);

    return n;
}