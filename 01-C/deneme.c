#include <stdio.h>
#include <stdlib.h>

int main(){

    int i;
    float examGrade, sumGrade;
    i = 1;
    examGrade = 0.0;
    sumGrade = 0.0;

    do{
        printf("%dth exam grade: ", i);
        scanf("%f", &examGrade);

        if(examGrade == 0){
            break;
        }
        if(examGrade < 0) {
            printf("pls enter pos. number.\n");
            continue;
        }else{
            sumGrade += examGrade;
        }
        i++;
    }while(examGrade != 0);

    printf("average: %f\n", sumGrade / (i-1));

    return 0;

}
