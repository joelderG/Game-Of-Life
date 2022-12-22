// Game of Life
// by Joel Giese

#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable: 4996)

int dau_eingabe(int min, int max);

int main(){
    int choice = 0;
    char size_zeilen = 0;
    char size_spalten = 0;
    int prozent = 0;
    char ** matrix;

    printf("\n");
    printf("\t\t*** Game of Life ***\n\n");
    printf("Zufallsgenerator: 1\n");
    printf("Datei: 2\n");
    printf("\n");
    printf("Startzustand auswählen:\n");
    choice = dau_eingabe(1,2);
    printf("\n");

    if(choice == 2){
        printf("Datei");
    }

    switch(choice){
        case 1:
                printf("\nGeben Sie die Anzahl an Zeilen an (1 - 255):");
                size_zeilen = dau_eingabe(1,255);
                printf("\nGeben Sie die Anzahl an Spalten an (1 - 255:");
                size_spalten = dau_eingabe(1,255);
                printf("\nGeben Sie an, mit wie viel Prozent das Spielfeld mit lebenden Zellen zu füllen ist (0 - 100):");
                prozent = dau_eingabe(0,100);

                // Speicherplatz reservieren für die char-Zeiger
                matrix = malloc(size_zeilen * sizeof(char *));
                if(matrix == NULL){
                    printf("\nFehler bei der Speichervergabe!\n");
                    return EXIT_FAILURE;
                }

                // Speicherplatz reservieren für die einzelnen Spalten der jeweiligen Zeile i
                for(int i = 0; i < size_zeilen;i++){
                    matrix[i] = malloc(size_spalten * sizeof(char *));
                        if(matrix[i] == NULL){
                        printf("\nFehler bei der Speichervergabe!\n");
                        return EXIT_FAILURE;
                        }
                }

                // Matrix initialisieren
                for(int i = 0; i < size_zeilen; i++){
                    for(int j = 0; j < size_spalten; j++){
                        matrix[i][j] = 32;
                    }
                }
                
                // Matrix ausgeben
                for(int i = 0; i < size_zeilen; i++){
                        for(int j = 0; j < size_spalten; j++){
                            printf("%c  ",matrix[i][j]);                       
                        }
                    printf("\n");
                }

                break;            
    }

    //Speicherplatz wieder freigeben nach ablauf des Programms
    for(int i = 0; i < size_zeilen; i++){
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

int dau_eingabe(int min, int max){
    int choice;

    if(scanf(" %d",&choice) == 0){
        printf("Die Eingabe ist falsch. Beachten Sie den Eingabebereich!\n");
        choice = dau_eingabe(min,max);
    }

    if(choice < min || choice > max){
        printf("Die Eingabe ist falsch. Beachten Sie den Eingabebereich!\n");
        choice = dau_eingabe(min,max);
        }

    if(choice >= min && choice <= max){
        return choice;
        } 
}
