#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct students{
    char myLetter;
    char* name;
    char* lastname;
    int no;
    float score;
    char parentName[40];
};

int main(){
    struct students x;
    x.myLetter='A';
    x.name="Gokhan";
    x.lastname="Gokcen";
    x.no=870;
    x.score=92.5;
    strcpy(x.parentName, "Hebele");

    printf("Letter: %c\n", x.myLetter);
    printf("Name:%s\n", x.name);
    printf("Lastname:%s\n", x.lastname);
    printf("No:%d\n", x.no);
    printf("Score:%f\n", x.score);
    printf("Parent name:%s\n", x.parentName);


    printf("\n\n");


    struct students x2={'B', "Kaan", "Gürnaz", 26, 10.32, "Hakan"};
    printf("Letter: %c\n", x2.myLetter);
    printf("Name:%s\n", x2.name);
    printf("Lastname:%s\n", x2.lastname);
    printf("No:%d\n", x2.no);
    printf("Score:%f\n", x2.score);
    printf("Parent name:%s\n", x2.parentName);

    //struct kopyalama
    struct students x3;
    x3=x;

    return 0;
}
