#include <stdio.h>
#include <stdlib.h>

int main(){

    int* x=(int*)malloc(sizeof(int));
    *x = 7;
    printf("%d\n", *x);
    free(x);

    int n;
    printf("kaç elemanlık bir array olusturacaksizin: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n*(sizeof(int)));
    if(arr==NULL){
        printf("bellek ayirimi basarisiz\n");
        return 1;
    }
    for(int i=0;i<n;i++){
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("girilen array elemanları:");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);

    return 0;
}
