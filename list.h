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
void inserCellTri(t_d_list* list, t_d_cell* cell);

#endif //UNTITLED_LIST_H
