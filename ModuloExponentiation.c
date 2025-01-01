#include <stdio.h>
long long int calculate(long long int number, long long int power, long long int moduloValue) {
    if (power == 0) return 1;
    if (power == 1) return number % moduloValue;

    long long int result = calculate(number, power/2, moduloValue);
    result = (result * result) % moduloValue;
    if (power%2 == 1) {
        return (result * number) % moduloValue;
    }

    return result;
}

int main() {
    long long int number, power ,moduloValue;
    printf("Enter the value of number: ");
    scanf("%lld", &number);
    printf("Enter the value of power: ");
    scanf("%lld", &power);
    printf("Enter the modulo Value: ");
    scanf("%lld", &moduloValue);

    if (moduloValue <= 1) {
        printf("modulo Value should be greater than 1.\n");
        return 0;
    }

    printf("Result: %lld\n", calculate(number, power, moduloValue));
    return 0;
}
