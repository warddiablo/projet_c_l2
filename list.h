#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H
#include "cell.h"

// structure pour les list contenant les cell
typedef struct{
    int nbrniv; // nombre maximal de niveaux que possede la liste
    t_d_cell *head;
}t_d_list;

// créer une liste à niveau vide
t_d_list createEmptyList(int niv);

#endif //UNTITLED_LIST_H
