#ifndef UNTITLED_CELL_H
#define UNTITLED_CELL_H

// structure de la cellule
typedef struct s_d_cell{
    int valeur;
    int nbrniveaux;
    struct s_d_cell *next;
}t_d_cell;

//fonction permettant de créer une cellule
t_d_cell createCell(int val, int nbrniveaux);
void supprCell(t_d_cell*);
#endif //UNTITLED_CELL_H