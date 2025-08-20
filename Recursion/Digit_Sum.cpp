#include <stdio.h>

int digitSum(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + digitSum(n / 10);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Digit sum of %d is %d\n", num, digitSum(num));
    return 0;
}
 