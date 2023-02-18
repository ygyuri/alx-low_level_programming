int main(void)
{
    int i, j, first_digit, second_digit;

    for (i = 0; i < 100; i++)
    {
        first_digit = i / 10;
        second_digit = i % 10;

        if (first_digit < second_digit)
        {
            putchar(first_digit + '0');
            putchar(second_digit + '0');

            if (i < 89)
            {
                putchar(',');
                putchar(' ');
            }
        }
    }

    putchar('\n');
    return (0);
}

