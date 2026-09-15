int phoneList(){
    Record currentRecord;
    FILE* fptr;
    fptr = fopen("data.txt", "r");
    if(fptr == NULL){
        return -1;
    }
    printf("\n\nIsim\t\t\tSoyisim\t\t\tTelefon\n");
    printf("----\t\t\t-------\t\t\t-------\n\n");

    while(fscanf(fptr, "%s%s%s", currentRecord.name, currentRecord.lastname, currentRecord.phone) == 3){
        printf("%s\t\t\t", currentRecord.name);
        printf("%s\t\t\t", currentRecord.lastname);
        printf("%s\n", currentRecord.phone);
    }

    fclose(fptr);
    return 0;
}