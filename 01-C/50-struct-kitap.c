#include <stdio.h>
#include <stdlib.h>

struct books{
    char* bookname;
    char* writer;
    int page;
    int year;
};



int main(){

    int i;
    struct books x[2];

    x[0].bookname="Harry Potter ve Felsefe Taşı";
    x[0].writer="J.K Rowling";
    x[0].page=238;
    x[0].year=1999;

    x[1].bookname="Bu ülke";
    x[1].writer="Cemil meric";
    x[1].page=245;
    x[1].year=1960;

    for(i=0;i<2;i++){
        printf("%d. kitap\n", i+1);
        printf("Book name:%s\n", x[i].bookname);
        printf("Writer:%s\n", x[i].writer);
        printf("Page:%d\n", x[i].page);
        printf("Year:%d\n\n", x[i].year);
    }



    return 0;
}
