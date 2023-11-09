#ifndef UNTITLED_CELL_H
#define UNTITLED_CELL_H
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// structure de la cellule
typedef struct s_d_cell{
    int valeur; // valeur de la cellule
    int nbrniv; // nombre de niveaux de la cellule
    struct s_d_cell **next; // "tableau" de pointeur pointant vers la cellule suivante
}t_d_cell;

// fonction permettant de créer une cellule
t_d_cell* createCell(int val, int nbrniveaux);
// fonction permettant de supprimer une cellule
void supprCell(t_d_cell*);

#endif //UNTITLED_CELL_H