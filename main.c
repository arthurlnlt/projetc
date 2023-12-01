#include <stdio.h>
#include "fichier.h"
#include "math.h"
#include "timer.h"
int main() {
    // Liste à niveau vide
   /* printf("Liste à niveau vide :\n");
    t_d_list* list = createList(5);
    displayList(*list);

    // Après insertion de cellules à niveau, affichage simple
    printf("Après insertion de cellules à niveau, affichage simple\n");
    t_d_cell* temp = createCell(18,4);
    t_d_cell* temp1 = createCell(25,1);
    t_d_cell* temp2 = createCell(31,2);
    t_d_cell* temp3 = createCell(32,5);
    t_d_cell* temp4 = createCell(56,3);
    t_d_cell* temp5 = createCell(59,5);
    t_d_cell* temp6 = createCell(59,1);
    t_d_cell* temp7 = createCell(91,3);
    addheadList(list,temp);
    addCelltoList(list,temp1);
    addCelltoList(list,temp2);
    addCelltoList(list,temp3);
    addCelltoList(list,temp4);
    addCelltoList(list,temp5);
    addCelltoList(list,temp6);
    addCelltoList(list,temp7);
    t_d_cell* temp8 = createCell(59,3);
    t_d_cell* temp9= createCell(59,1);
    t_d_cell* temp10 = createCell(91,2);
    addCelltoList(list,temp8);
    addCelltoList(list,temp9);
    addCelltoList(list,temp10);
    t_d_list *list3= createonelistfromlist(*list);
    displayList(*list);
    displayList(*list3);

    printf("%d val trouve ?\n",seekvaluedichotomique(*list3,7));
    FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    int level;
    char *time_lvl0;
    char *time_all_levels;
    int i = 7;
    while (i != 18) {
        printf("Niveau testé : %d\n", i);
        t_d_list* liste = createList(i);
        liste = createonelistfromlist(*liste);
        startTimer();
        for (int k = 0;k < 10000;k++) {
            seekvalue(*liste, k);
        }
        stopTimer();
        time_lvl0 = getTimeAsString(); // fonction du module timer
        printf("Recherche classique :\n");
        displayTime();
        startTimer();
        for (int k = 0;k < 10000;k++) {
            seekvaluedichotomique(*liste,k);
        }
        stopTimer();
        time_all_levels = getTimeAsString();
        fprintf(log_file, format, i, time_lvl0, time_all_levels);
        printf("Recheche dichotomique :\n");
        displayTime();
        i++;

    }
    fclose(log_file);*/
    t_d_agenda_list * list = createagenda();
    t_d_cell_contact *contact = createContact();
    t_d_cell_contact *contact2 = createContact();
    t_d_cell_contact *contact3 = createContact();
    t_d_cell_contact *contact4= createContact();
    addContactToAgenda(contact,list);
    complete_afficher_agenda(*list);
    addContactToAgenda(contact2,list);
    complete_afficher_agenda(*list);
    printf("contact3\n");
    addContactToAgenda(contact3,list);
    complete_afficher_agenda(*list);
    addContactToAgenda(contact4,list);
    complete_afficher_agenda(*list);
}
// zer -> sdf -> wxc-> aze