#include "list.h"

int main() {
    t_d_list list = createEmptyList(5);
    printf("Affichage de la liste vide :\n");
    printListAll(list);
    t_d_cell cell1 = createCell(1,3);
    t_d_cell cell2 = createCell(4,4);
    t_d_cell cell3 = createCell(6,1);
    t_d_cell cell4 = createCell(8,5);
    t_d_cell cell5 = createCell(9,3);

    inserCellHead(&list, &cell4);
    inserCellHead(&list, &cell3);
    inserCellHead(&list, &cell2);
    inserCellHead(&list, &cell1);
    inserCellTri(&list, &cell5);

    printf("\nAffichage de la liste au niveau 2 :\n");
    printListNiv(list,2);
    printf("\nAffichage de la liste complete\n");
    printListAll(list);
    printf("\nAffichage de la liste complete et aligne\n");
    printListAligne(list);


}
