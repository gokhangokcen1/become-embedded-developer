#include <stdio.h>
#include <stdlib.h>
#define MYNUMBER 7
int main(){
    #ifdef MYNUMBER
            printf("MYNUMBER tanimli ve degeri:%d\n\n",MYNUMBER);
        #else
            printf("MYNUMBER tanimli degil\n\n");
        #endif // MYNUMBER

        #undef MYNUMBER

        #ifdef MYNUMBER
            printf("MYNUMBER tanimli ve degeri:%d\n\n",MYNUMBER);
        #else
            printf("MYNUMBER tanimli degil\n\n");
        #endif // MYNUMBER

        #ifndef MYNUMBER
            #define MYNUMBER 19
        #endif // MYNUMBER
            printf("MYNUMBER tanimli ve degeri:%d\n\n",MYNUMBER);
    return 0;
}
