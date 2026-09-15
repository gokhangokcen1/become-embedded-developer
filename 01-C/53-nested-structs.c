#include <stdio.h>
#include <stdlib.h>

struct candidateInfo {
    char* name;
    char* lastname;
    int age;
    int note;
    float average;
};

struct interview {
    char* interviewer;
    char* interviewDate;
    struct candidateInfo candidate;
    int interviewNote;
};

int main() {
    struct interview y;
    y.interviewer = "Muslume Gun";
    y.interviewDate = "25.05.2009";
    y.interviewNote = 89;

    y.candidate.name = "Ceren";
    y.candidate.lastname = "Nereden";
    y.candidate.age = 25;
    y.candidate.note = 80;
    y.candidate.average = 2.69;

    printf("Mulakati Yapan: %s\n", y.interviewer);
    printf("Mulakat Tarihi: %s\n", y.interviewDate);
    printf("Mulakat Notu: %d\n\n", y.interviewNote);

    printf("Adayin Adi: %s\n", y.candidate.name);
    printf("Adayin Soyadi: %s\n", y.candidate.lastname);
    printf("Adayin Yasi: %d\n", y.candidate.age);
    printf("Adayin Sinav Notu: %d\n", y.candidate.note);
    printf("Adayin Lisans Ortalamasi: %.2f\n", y.candidate.average); // Lisans Ortalaması eklendi

    return 0;
}
