#include "stockage.h"

char* scanString(){
    static char input[100];
    printf("\n>>");
    scanf("%s",input);
    return input;
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
                // gérer le cas où l'entrée est supérieur à 9 ou inférieur à 1
                if (nbr < 1 || nbr > 9) {
                    printf("La saisie est incorrecte !\n");
                }
            }
        }while (nbr < 1 || nbr > 9);
        char *input;
        switch(nbr){
            case 1:
                printf("Veuillez saisir un Nom et Prenom pour le contact recherche : ");
                input = scanString();
                printf("Fonctionnalite pas encore implemente\n");
                break;
            case 2:
                printf("Fonctionnalite pas encore implemente\n");
                break;
            case 3:
                printf("Fonctionnalite pas encore implemente\n");
                break;
            case 4:
                printf("Fonctionnalite pas encore implemente\n");
                break;
            case 5:
                printf("Fonctionnalite pas encore implemente\n");
                break;
            case 6:
                printf("Fonctionnalite pas encore implemente\n");
                break;
            case 7:
                printf("Fonctionnalite pas encore implemente\n");
                break;
            case 8:
                printf("Fonctionnalite pas encore implemente\n");
                break;
            case 9:
                nbr = 0;
                break;
        }
    }while(nbr); // répéter le menu jusqu'à ce que l'utilisateur le ferme
}

cellENTRY* createContact(){
    cellENTRY* cell = (cellENTRY*) malloc(sizeof (cellENTRY)); // allocation dynamique de la cellule
    // Saisie du nom et prénom
    printf("Entrez le nom : ");
    char *nom = scanString();
    cell->contact.nom = strdup(nom);
    printf("Entrez le prénom : ");
    char *prenom = scanString();
    cell->contact.prenom = strdup(prenom);
    cell->nbrniv = 4;
    cell->next = (cellENTRY **) malloc(cell->nbrniv * sizeof(cellENTRY *));
    return cell;
}

int compareString(cellENTRY* cell1, cellENTRY* cell2){
    if(cell2 == NULL){
        return 1;
    }
    char *s1 = (char *)malloc(strlen(cell1->contact.nom) + strlen(cell1->contact.prenom) + 2);
    sprintf(s1, "%s_%s", cell1->contact.nom, cell1->contact.prenom);
    char *s2 = (char *)malloc(strlen(cell2->contact.nom) + strlen(cell2->contact.prenom) + 2);
    sprintf(s2, "%s_%s", cell2->contact.nom, cell2->contact.prenom);
    return strcasecmp(s1, s2); // compare 2 str et n'est pas sensible à la casse
}

void inserCell(listENTRY* list, cellENTRY* cell){
    cellENTRY *temp;
    temp = list->head[0];
    while(temp != NULL && compareString(cell,temp)<0) {
        temp = temp->next[0];
    }
    if(temp != NULL){
        int i=0;
        while(cell->contact.nom[i]==temp->contact.nom[i] && i<3){
            i++;
        }
        cell->nbrniv -= i;
        cell->next = realloc(cell->next,cell->nbrniv* sizeof(cellENTRY*));
    }
    for (int i=0;i<cell->nbrniv;i++){ // on fait une boucle pour insérer la cellule à tous ses niveaux dans la liste
        temp = list->head[i]; // on initialise une cellule à la cellule de tete de liste au n-ième niveau
        if(temp == NULL && compareString(cell,temp)>0){
            cell->next[i] = list->head[i]; // on initialise la cellule suivante avec la tete de la liste
            list->head[i] = cell; // on raccroche la cellule à la liste
        }
        else{
            while (temp->next[i] != NULL && compareString(cell,temp)<0){
                temp = temp->next[i]; // incrémentation
            }
            cell->next[i] = temp->next[i]; // on initialise la cellule suivante avec une cellule de la liste
            temp->next[i] = cell; // on raccroche la cellule à la liste
        }
    }
}

listENTRY createEmptyListE(int niv){
    listENTRY list;
    list.nbrniv = niv;
    list.head = (cellENTRY **) malloc(niv*sizeof(cellENTRY *)); // création d'un tableau dynamique en fonction du nombre de niveaux de la liste
    for (int i=0;i<niv;i++){
        list.head[i] = NULL; // initialisation de la tete de liste à NULL, pour que la liste soit vide
    }
    return list;
}

void printListNivE(listENTRY list, int niv){
    cellENTRY *temp;
    temp = list.head[niv]; // on initialise une cellule temporaire à la tete de liste
    printf("[list head_%d @-]-->",niv); // on affiche le niveau donné
    while(temp != NULL){
        printf("[ %s|@-]-->",temp->contact.nom); // on affiche les valeurs des cellules
        temp = temp->next[niv]; // et on se déplace sur la suivante
    }
    printf("NULL\n"); // quand on arrive vers la fin de la liste on affiche NULL
}
void printAllListE(listENTRY list){
    for (int i=0;i<list.nbrniv;i++){ // on fait une boucle pour afficher chaque niveau de la liste
        printListNivE(list,i); // on appelle la fonction printListNiv
    }
}
