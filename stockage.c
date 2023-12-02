#include "stockage.h"

char* scanString(){
    static char input[100];
    printf("\n>>");
    scanf("%s",input);
    return input;
}

void createContact(listENTRY*){
    cellENTRY* cell = (cellENTRY*) malloc(sizeof (cellENTRY)); // allocation dynamique de la cellule
}

void menu(listENTRY* l){
    int nbr=0;
    do {
        printf("1. Rechercher un contact\n2. Afficher les rendez-vous d’un contact\n3. Creer un contact\n4. Creer un rendez-vous pour un contact\n5. Supprimer un rendez-vous\n6. Sauvegarder le fichier de tous les rendez-vous\n7. Charger un fichier de rendez-vous\n8. Fournir les temps de calcul pour une insertion de nouveau contact\n9. Stopper le programme\n");
        do {
            printf("Veuillez saisir un numero : ");
            printf("\n>> ");
            if (scanf("%d", &nbr) != 1) {
                // Gérer le cas où l'entrée n'est pas un entier
                printf("La saisie est incorrecte !\n");
                scanf("%*s"); // Nettoyer le tampon d'entrée
                nbr = 0;
            } else {
                if (nbr < 1 || nbr > 9) {
                    printf("La saisie est incorrecte !\n");
                }
            }
        }while (nbr < 1 || nbr > 9);
        char *input;
        switch(nbr){
            case 1:
                printf("Veuillez saisir un Nom et Prenom : ");
                input = scanString();
                break;
            case 9:
                nbr = 0;
        }
    }while(nbr);
}