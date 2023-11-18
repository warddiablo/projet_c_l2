#ifndef UNTITLED_STOCKAGE_H
#define UNTITLED_STOCKAGE_H
#include "list.h"

// structure contact
typedef struct{
    char* nom, prenom;
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

// structure rendez-vous
typedef struct{
    DATE date;
    HEURE heure;
    DUREE duree;
    char* objet;
}RDV;

// structure d'entrée de l'agenda
typedef struct{
    CONTACT contact;
    t_d_list rdv;
}ENTRY;

#endif //UNTITLED_STOCKAGE_H
