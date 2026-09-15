int phoneAdd(){
    Record newRecord;
    FILE* fptr;
    fptr = fopen("data.txt", "a");
    if(fptr == NULL){
        return -1;
    }
    printf("\n\n");
    printf("İsim gir:");
    scanf("%s", newRecord.name);
    printf("Soyisim gir:");
    scanf("%s", newRecord.lastname);
    printf("Telefon numarası:");
    scanf("%s", newRecord.phone);

    fprintf(fptr, "\n%s %s %s", newRecord.name, newRecord.lastname, newRecord.phone);
    fclose(fptr);
    return 0;
}