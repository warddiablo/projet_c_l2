#include "cell.h"

t_d_cell createCell(int val, int nbrniveaux){
    t_d_cell cell;
    cell.valeur = val;
    cell.nbrniv = nbrniveaux;
    cell.next = (t_d_cell**) malloc(nbrniveaux*sizeof(t_d_cell*)); // création d'un tableau dynamique en fonction du nombre de niveaux de la cellule
    return cell;
}
void supprCell(t_d_cell* p_cell){
    free(p_cell);
}