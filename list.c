#include "list.h"

t_d_list createEmptyList(int niv){
    t_d_list list;
    list.nbrniv = niv;
    list.head = (t_d_cell**) malloc(niv*sizeof(t_d_cell*)); // création d'un tableau dynamique en fonction du nombre de niveaux de la liste
    for (int i=0;i<niv;i++){
        list.head[i] = NULL; // initialisation de la tete de liste à NULL, pour que la liste soit vide
    }
    return list;
}

void inserCellHead(t_d_list* list, t_d_cell* cell){
    for (int i=0;i<cell->nbrniv;i++){
        cell->next[i] = list->head[i]; // on initialise la cellule suivante avec la tete de la liste
        list->head[i] = cell; // on raccroche la cellule à la liste
    }
}

void printListNiv(t_d_list list, int niv){
    t_d_cell *temp;
    temp = list.head[niv]; // on initialise une cellule temporaire à la tete de liste
    printf("[list head_%d @-]-->",niv); // on affiche le niveau donné
    while(temp != NULL){
        printf("[ %d|@-]-->",temp->valeur); // on affiche les valeurs des cellules
        temp = temp->next[niv]; // et on se déplace sur la suivante
    }
    printf("NULL\n"); // quand on arrive vers la fin de la liste on affiche NULL
}

void printListAll(t_d_list list){
    for (int i=0;i<list.nbrniv;i++){ // on fait une boucle pour afficher chaque niveau de la liste
        printListNiv(list,i); // on appelle la fonction printListNiv
    }
}

void printListAligne(t_d_list list){
    printListNiv(list,0);
    t_d_cell *temp, *temp2;
    for (int i=1;i<list.nbrniv;i++){
        temp = list.head[i];
        temp2 = list.head[0];
        printf("[list head_%d @-]--",i);
        while(temp != NULL || temp2 != NULL){
            if(temp == NULL){
                printf("----------");
            }
            else {
                while (temp2->valeur != temp->valeur) {
                    printf("----------");
                    temp2 = temp2->next[0];
                }
                printf(">[ %d|@-]--", temp->valeur);
                temp = temp->next[i];
            }
            temp2 = temp2->next[0];
        }
        printf(">NULL\n");
    }
}

void inserCellTri(t_d_list* list, t_d_cell* cell){

}