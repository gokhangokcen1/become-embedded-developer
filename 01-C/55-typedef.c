#include <stdio.h>
#include <stdlib.h>

// değişken tipinin ismini istediğimiz şekilde kısaltabiliyoruz
// typedef unsigned long long integer ulli;
// typedef char name[30] n1;
// typedef int i;

typedef struct{
    char* name;
    int age;
    float weight;
}Student;

int main(){

    //i x,y;
    //x = 7;
    //y = 19;
    //printf("%d %d\n", x,y);


    // her seferinde şunu yazmak yerine kısalttık
    // struct Student s1 = ....
    // struct Student s2 = ....
    Student s1={"Nazli",28,62.3};
    Student s2={"Ceren",25,61.7};

    printf("Your Name:%s\n",s1.name);
    printf("Your Age:%d\n",s1.age);
    printf("Your Weight:%.2f\n\n",s1.weight);

    printf("Your Name:%s\n",s2.name);
    printf("Your Age:%d\n",s2.age);
    printf("Your Weight:%.2f\n",s2.weight);


    return 0;
}
