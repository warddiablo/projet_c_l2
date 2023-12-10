#ifndef UNTITLED_STOCKAGE_H
#define UNTITLED_STOCKAGE_H
#include "list.h"
#include <string.h>
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// structure contact
typedef struct{
    char *nom, *prenom;
}CONTACT;

typedef struct{
    int jour, mois, annee;
}DATE;

typedef struct{
    int heure, min;
}HEURE;

typedef struct{
    int heure, min;
}DUREE;

// structure de la cellule rendez-vous
typedef struct{
    DATE date;
    HEURE heure;
    DUREE duree;
    char* objet;
    struct cellRDV *succ;
}cellRDV;

//structure de la liste chainee rdv
typedef struct{
    cellRDV *head;
}listRDV;

// structure de la cellule des entrees de l'agenda
typedef struct{
    CONTACT contact;
    listRDV rdv;
    int nbrniv; // nombre de niveaux de la cellule
    struct cellENTRY **next; // "tableau" de pointeur pointant vers la cellule suivante
}cellENTRY;

// structure de la liste a niveaux des entrees de l'agenda
typedef struct{
    int nbrniv; // nombre maximal de niveaux que possede la liste
    cellENTRY **head; // tete de la liste
}listENTRY;

// fonction permettant la saisie d'une chaine de caractere
char *scanString();
int compareString(cellENTRY* cell1, cellENTRY* cell2);

// fonction permettant d'afficher le menu
void menu(listENTRY*);

// fonction permettant de creer un contact avec l'insertion dans la liste
cellENTRY* createContact();
// insérer le contact dans la liste a niveau
void inserCell(listENTRY*, cellENTRY*);

// fonction permettant de créer une liste
listENTRY createEmptyListE(int);
// fonction permettant d'afficher la liste
void printListNivE(listENTRY, int);
void printAllListE(listENTRY);

// fonction permettant de creer un rdv pour un contact
void createRDV(cellENTRY*);

// fonction permettant de rechercher un contact
cellENTRY searchContact(listENTRY);

// fonction permettant d'afficher les rendez-vous d'un contact
void printRDV(cellENTRY);

// fonction permettant de supprimer un rendez-vous
void supprRDV(cellENTRY*);


#endif //UNTITLED_STOCKAGE_H
