#define ROUNDS 1000
#define MULTIPLIER 11
#define ADDER 17
#define MODULO 100

#include <stdio.h>

int random1(int seed)
{
    int num = seed;
    for (int i = 0; i < ROUNDS; i++) {
        num = (MULTIPLIER * num + ADDER) % MODULO;
    }
    return num;
}

int middle(int num)
{
    int len = 0;
    int temp = num;
    while (temp != 0) {
        temp /= 10;
        len++;
    }
    while (len < 3) {
        num *= 10;
        len++;
    }
    int mid = len / 2 + 1;
    int modular = 1;
    for (int i = 0; i < mid + 1; i++) {
        modular *= 10;
    }
    num = num % modular;
    for (int i = 0; i < len - mid; i++) {
        num /= 10;
    }
    return num;
}

int random2(int seed)
{
    int num = seed;
    for (int i = 0; i < ROUNDS; i++) {
        num = middle(num * num);
    }
    return num;
}

int main()
{
    int seed;
    printf("Enter seed: ");
    scanf("%d", &seed);
    int ran = random2(seed);
    printf("%d\n", ran);
}