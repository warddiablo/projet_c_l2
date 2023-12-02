#include "list.h"
#include "time.h"
#include "stockage.h"
#include <string.h>

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
    /*srand(time(NULL)); // initialisation du générateur de nombre aléatoire
    FILE *log_file = fopen("log.txt","w"); // ouverture et écriture dans le fichier log.txt
    char format[] = "%d\t%s\t%s\n" ; // format d'écriture dans le fichier
    char *time_lvl0; // temps mis pour la recherche au niveau 0
    char *time_all_levels; // temps mis pour la recherche à partir du plus haut niveau
    for (int i=7;i<25;i++){
        t_d_list list = createList(i);
        int nb_cell = ((int)pow(2,i))-1;
        printf("niveau teste : %d :\n",i);
        startTimer(); // on lance le temps
        for (int j=1;j<10000;j++){
            int nb_alea = (rand()%nb_cell)+1; // choix aleatoire d'un nombre entre 1 et nb_cell
            isValInListClassic(list,nb_alea); // on effectue la recherche au niveau 0
        }
        stopTimer(); // on arrete le temps
        time_lvl0 = getTimeAsString(); // fonction du module timer pour recuperer le temps
        displayTime(); // affiche le temps (optionnelle)
        startTimer(); // on relance le temps
        for (int j=1;j<10000;j++){
            int nb_alea = (rand()%nb_cell)+1; // choix aleatoire d'un nombre entre 1 et nb_cell
            isValInListAdvanced(list,nb_alea); // on effectue la recherche à partir du plus haut niveau
        }
        stopTimer(); // on arrete le temps
        time_all_levels = getTimeAsString(); // fonction du module timer pour recuperer le temps
        displayTime(); // affiche le temps (optionnelle)
        fprintf(log_file,format,i,time_lvl0, time_all_levels); // on ecrit dans le fichier les temps mis par les differentes fonctions
    }
    fclose(log_file); // on ferme la lecture/ecriture du fichier*/

    // Partie 3 :
    listENTRY l;
    menu(&l);
}
