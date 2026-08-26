#include <stdio.h>
#include <stdlib.h>

int main(){
    char myLetter = 'C';
    int myNumber = 57;
    float myNumber2 = 2.56;
    double myNumber3 = 213.568;
    
    printf("%c\n", myLetter);
    printf("%d\n", myNumber);
    printf("%f\n", myNumber2);
    printf("%lf\n", myNumber3);
    printf("%s\n", "where have you been?");
   
    int number, number2, extraction, sum, multiplication, division;
    number = 25;
    number2 = 5;
    sum = number + number2;
    extraction = number - number2;
    multiplication = number * number2;
    division = number / number2;

    printf("Toplama: %d\n", sum);
    printf("Çıkarma: %d\n", extraction);
    printf("Çarpma: %d\n", multiplication);
    printf("Bölme: %d\n", division);


    return 0;

}
