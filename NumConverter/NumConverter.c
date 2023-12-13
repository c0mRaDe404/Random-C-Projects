#include <stdio.h>

int main(void)
{

    char digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int NumberToConvert;
    int ConvertedNumber[64];
    int base;
    int index = 0;
    int nextDigit;

    printf("Enter the NumberToConvert >> ");
    scanf("%d", &NumberToConvert);
    printf("\nEnter the base 2/8/10/16 >> ");
    scanf("%d", &base);

    do
    {
        ConvertedNumber[index] = NumberToConvert % base;
        index++;
        NumberToConvert = NumberToConvert / base;

    } while (NumberToConvert != 0);

    
    for (--index; index >= 0; index--)
    {
          nextDigit = ConvertedNumber[index];
          printf("%c", digits[nextDigit]);

    }

      

    return 0;
}
