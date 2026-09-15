#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,new_size;
    printf("Kac elemanlik array olusturacaksiniz:");
    scanf("%d",&n);
    int* arr=(int*)calloc(n,sizeof(int));

    if(arr==NULL) {
        printf("Bellek ayirma basarisiz\n");
        return 1;
    }
    for(int i=0;i<n;i++){
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
    }
    printf("Mevcut array:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Kac elemanlık array olusturacaksiniz:");
    scanf("%d", &new_size);
    arr=(int*)realloc(arr, new_size*sizeof(int));
    if(arr==NULL){
        printf("Bellek ayırma basarisiz\n");
        return 1;
    }
    for(int i=n; i<new_size;i++){
        printf("arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    printf("realloc sonrasi array:");
    for(int i = 0; i<new_size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
