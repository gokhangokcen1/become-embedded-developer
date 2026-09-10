#include <stdio.h>
#include <stdlib.h>

//fonksiyonumuz bir şey döndürmeyeceksek void olarak tanımlarız. return etmez.


void nameList(char name[], int age);
void allNumbers(int myNumbers[6]);
int showMe(int x);
int sumNumbers( int x, int y);


int main(){
    //myMessage();
    nameList("Gokhan", 25);
    nameList("Ali", 26);

    // ARRAY KULLANMA KISMI
   int myNumbers[6] = {10, 20, 30, 40, 50, 60};
   allNumbers(myNumbers);

    printf("Result is %d\n", showMe(2));
    printf("Result is %d\n", sumNumbers(1,16));


    return 0;
}


void nameList(char name[], int age){
    printf("%s. You are %d years old\n", name, age);
}

void allNumbers(int myNumbers[6]){
    for(int i = 0; i<6; i++){
        printf("%d\n",myNumbers[i]);
    }
}

int showMe(int x){
    return 5 + x;
}

int sumNumbers( int x, int y){
    return x + y;
}
