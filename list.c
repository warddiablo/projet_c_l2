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
    t_d_cell *temp;
    for (int i=0;i<cell->nbrniv;i++){ // on fait une boucle pour insérer la cellule à tous ses niveaux dans la liste
        temp = list->head[i]; // on initialise une cellule à la cellule de tete de liste au n-ième niveau
        if(list->head[i] == NULL || list->head[i]->valeur > cell->valeur){ // si la liste est vide ou que la 1ere cellule de la liste est plus grande que la cellule cell (valeur)
            cell->next[i] = list->head[i]; // on initialise la cellule suivante avec la tete de la liste
            list->head[i] = cell; // on raccroche la cellule à la liste
        }
        else {
            while (temp->next[i] != NULL && temp->next[i]->valeur < cell->valeur){ // sinon on parcours toute la liste jusqu'à tant qu'elle soit vide ou qu'une cellule de la liste soit plus grande que cell (valeur)
                temp = temp->next[i]; // incrémentation
            }
            cell->next[i] = temp->next[i]; // on initialise la cellule suivante avec une cellule de la liste
            temp->next[i] = cell; // on raccroche la cellule à la liste
        }
    }
}


t_d_list createList(int n){
    t_d_list list = createEmptyList(n);
    int nbrcell = ((int)pow(2,n))-1; // initialisation du nombre de cellule, soit 2^n-1 cellules
    int* levels = (int*) calloc(nbrcell, sizeof (int)); // création d'un tableau d'entier stockant les levels de notre liste, avec pour taille nbrcell
    for (int i=1;i<=nbrcell;i++){
        for (int j=1;j<n;j++){
            if(!(i%((int)pow(2,j)))){ // si i est divisible par 2^j (avec j allant de 1 à n)
                levels[i] += 1; // on ajoute un niveau
            }
        }
    }
    for (int i=nbrcell;i>0;i--){
        t_d_cell* cell = createCell(i, levels[i]+1); // création d'une cellule avec comme valeur i et comme nbrniv l'entier+1 stocké dans le tableau levels
        inserCellHead(&list,cell);
    }
    return list;
}

int isValInListClassic(t_d_list list, int val){
    t_d_cell *temp;
    temp = list.head[0]; // on initialise une cellule temporaire à la tete de liste au niveau 0
    while (temp != NULL) {
        if (temp->valeur == val) {
            return 1; // si la valeur de la cellule est égal à la valeur recherché alors on retourne 1
        }
        temp = temp->next[0]; // on se déplace sur la cellule suivante
    }
    return 0; // la valeur n'a pas été trouvé, on retourne 0
}

int isValInListAdvanced(t_d_list list, int val){
    t_d_cell *temp,*prev;
    temp = list.head[list.nbrniv-1];
    prev = NULL;
    for (int i=list.nbrniv-1;i>=0;i--){
        if(prev == NULL){
            temp = list.head[i];
        }
        while(temp != NULL && temp->valeur <= val){
            if (temp->valeur == val){
                return 1; // La valeur a été trouvée
            }
            prev = temp;
            temp = temp->next[i];
        }
        temp = prev;
    }
    return 0; // la valeur n'a pas été trouvé, on retourne 0
}