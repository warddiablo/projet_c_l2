#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H
#include "cell.h"

// structure pour les listes contenant les cellules
typedef struct{
    int nbrniv; // nombre maximal de niveaux que possede la liste
    t_d_cell **head; // tete de la liste
}t_d_list;

// créer une liste vide en fonction du nombre maximal de niveaux
t_d_list createEmptyList(int niv);
// insere une cellule en tete de liste
void inserCellHead(t_d_list*, t_d_cell*);
// affiche les differentes cellules pour un niveau donné
void printListNiv(t_d_list, int);
// affiche toute la liste avec les differents niveaux
void printListAll(t_d_list);
// affiche toute la liste avec les differents niveaux en alignant les cellules
void printListAligne(t_d_list);
// insere une cellule en fonction de l'ordre croissant
void inserCellTri(t_d_list*, t_d_cell*);

// Partie 2 :

// créer une liste avec 2^n-1 cellule, avec des valeurs allant de 1 à 2^n-1 et avec n niveaux
t_d_list createList(int n);
// recherche une valeur dans la liste, uniquement dans le niveau 0
int isValInListClassic(t_d_list, int);
// recherche une valeur dans la liste, à partir du niveau le plus haut
int isValInListAdvanced(t_d_list, int);
#endif //UNTITLED_LIST_H
