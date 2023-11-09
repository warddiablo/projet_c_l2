#include "list.h"

int main() {
    // Partie 1 :
    /*t_d_list list = createEmptyList(5);
    printf("Affichage de la liste vide :\n");
    printListAll(list);
    for(int i=1;i<6;i++){
        t_d_cell* cell = createCell(i,i);
        inserCellTri(&list,cell);
    }
    printf("\nAffichage de la liste au niveau 2 :\n");
    printListNiv(list,2);
    printf("\nAffichage de la liste complete\n");
    printListAll(list);
    printf("\nAffichage de la liste complete et aligne\n");
    printListAligne(list);*/

    // Partie 2 :
    t_d_list list = createList(3);
    printf("%d", isValInListClassic(list,4));
    printf("%d\n", isValInListAdvanced(list,4));
    printListAligne(list);
}
