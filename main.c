#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int decimal) {
    int binary[32];
    int i = 0;

    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

void decimalToHexadecimal(int decimal) {
    char hexadecimal[32];
    int i = 0;

    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[i] = remainder + '0';
        } else {
            hexadecimal[i] = remainder + 55;
        }
        decimal = decimal / 16;
        i++;
    }

    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");
}

void decimalToOctal(int decimal) {
    int octal[32];
    int i = 0;

    while (decimal > 0) {
        octal[i] = decimal % 8;
        decimal = decimal / 8;
        i++;
    }

    printf("Octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}

int binaryToDecimal(long long binary) {
    int decimal = 0;
    int base = 1;

    while (binary > 0) {
        int lastDigit = binary % 10;
        binary = binary / 10;
        decimal += lastDigit * base;
        base = base * 2;
    }

    return decimal;
}

int hexadecimalToDecimal(char *hexadecimal) {
    int decimal = 0;
    int base = 1;
    int length = strlen(hexadecimal);

    for (int i = length - 1; i >= 0; i--) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (hexadecimal[i] - '0') * base;
        } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            decimal += (hexadecimal[i] - 55) * base;
        }
        base = base * 16;
    }

    return decimal;
}

int main() {
    int choice;
    int decimal;
    long long binary;
    char hexadecimal[32];

    printf("1. Decimal to Binary\n");
    printf("2. Decimal to Hexadecimal\n");
    printf("3. Decimal to Octal\n");
    printf("4. Binary to Decimal\n");
    printf("5. Hexadecimal to Decimal\n");
    printf("6. Octal to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            decimalToBinary(decimal);
            break;
        case 2:
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            decimalToHexadecimal(decimal);
            break;
        case 3:
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            decimalToOctal(decimal);
            break;
        case 4:
            printf("Enter a binary number: ");
            scanf("%lld", &binary);
            printf("Decimal: %d\n", binaryToDecimal(binary));
            break;
        case 5:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexadecimal);
            printf("Decimal: %d\n", hexadecimalToDecimal(hexadecimal));
            break;
        case 6:
            printf("Enter an octal number: ");
            scanf("%s", hexadecimal); // Reusing hexadecimal array for octal input
            printf("Decimal: %d\n", hexadecimalToDecimal(hexadecimal));
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}