#include "list.h"
#include "time.h"

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
    srand(time(NULL)); // initialisation du générateur de nombre aléatoire
    FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    char *time_lvl0;
    char *time_all_levels;
    for (int i=7;i<25;i++){
        t_d_list list = createList(i);
        int nb_cell = ((int)pow(2,i))-1;
        printf("niveau teste : %d :\n",i);
        startTimer();
        for (int j=1;j<10000;j++){
            int nb_alea = (rand()%nb_cell)+1;
            isValInListClassic(list,nb_alea);
        }
        stopTimer();
        time_lvl0 = getTimeAsString(); // fonction du module timer
        displayTime();
        startTimer();
        for (int j=1;j<10000;j++){
            int nb_alea = (rand()%nb_cell)+1;
            isValInListAdvanced(list,nb_alea);
        }
        stopTimer();
        time_all_levels = getTimeAsString();
        displayTime();
        fprintf(log_file,format,i,time_lvl0, time_all_levels);
    }
    fclose(log_file);
    return 0;
}
