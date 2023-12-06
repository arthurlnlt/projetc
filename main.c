#include <stdio.h>
#include "fichier.h"
#include <stdlib.h>
#include "math.h"
#include "timer.h"
int main() {
    // Liste à niveau vide
    /*int i=0;
    t_d_agenda_list* list=createagenda();
    printf("Bienvenue sur l'AGENDA\n");
    printf("Veuillez choisir une action :\n"
           "1- Ajouter un contact\n"
           "2- Ajouter un rendez-vous a un contact\n"
           "3- Afficher la liste des contacts present dans l'agenda\n"
           "4- Afficher les rendez-vous d'un contact\n"
           "5- Supprimer un rendez-vous\n"
           "6- Sauvegarder tout les rendez-vous d'un contact\n"
           "7- Charger tout les rendez-vous d'un contact :\n"
           "8- Rechercher un contact :\n"
           "9- Afficher le menu : \n"
           "10- Quitter l'agenda :\n");
    while(i!=10)
    {
        scanf("%d",&i);
        if (i==1)
        {
            t_d_cell_contact * contact = createContact();
            addContactToAgenda(contact,list);
        }
        else if (i==2)
        {
            t_d_rdv_cell * rdv = createRdv();
            scanf("Saisissez le nom du contact à rechercher :\n");
            char * mot = scanString();
            t_d_cell_contact *c = seekContact(*list,mot);
            insertion_rendez_vous_contact(c,rdv);
        }
        else if (i==3)
        {
            complete_afficher_agenda(*list);
        }
        else if (i==4)
        {
            scanf("Saisissez le nom du contact à rechercher :\n");
            char * mot = scanString();
            //t_d_cell_contact * c = seekContact(*list,mot);
            afficher_rendez_vous_contact(*seekContact(*list,mot));
        }
        else if (i==5)
        {
            printf("Vous voulez supprimer un rendez-vous, mais de quel contact ?\n");
            char * mot = scanString();
            t_d_cell_contact * c = seekContact(*list,mot);
            scanf("Saisissez la date du rendez-vous a supprimer :\n");
            int * date = (int*)malloc(3*sizeof(int));
            printf("Ecrivez la date a supprimer sous la forme JOUR ");
            scanf("%d",&date[0]);
            printf("Ecrivez la date a supprimer sous la forme MOIS ");
            scanf("%d",&date[1]);
            printf("Ecrivez la date a supprimer sous la forme ANNEE ");
            scanf("%d",&date[2]);
            supprimer_rendez_vous(c->rendezvous,date);
        }
        else if (i==6)
        {

        }
        else if (i==7)
        {

        }
        else if (i==8)
        {
            scanf("Saisissez le nom du contact à rechercher :\n");
            char * mot = scanString();
            //t_d_cell_contact * c = seekContact(*list,mot);
            t_d_cell_contact *c = seekContact(*list,mot);
            if (c!=NULL)
            {
                printf("Le contact est present dans la liste\n");
            }
            else
            {
                printf("Le contact n'est pas present dans la liste\n");
            }
        }
        else if (i==9)
        {
            printf("Veuillez choisir une action :\n"
                   "1- Ajouter un contact\n"
                   "2- Ajouter un rendez-vous a un contact\n"
                   "3- Afficher la liste des contacts present dans l'agenda\n"
                   "4- Afficher les rendez-vous d'un contact\n"
                   "5- Supprimer un rendez-vous\n"
                   "6- Sauvegarder tout les rendez-vous d'un contact\n"
                   "7- Charger tout les rendez-vous d'un contact :\n"
                   "8- Rechercher un contact :\n"
                   "9- Afficher le menu : \n"
                   "10- Quitter l'agenda :\n");
        }
    }



    printf("Liste a niveau vide :\n");
    t_d_list* list = createList(3);
    displayList(*list);

    // Après insertion de cellules à niveau, affichage simple
    printf("Apres insertion de cellules a niveau, affichage simple\n");
    t_d_cell* temp = createCell(18,3);
    t_d_cell* temp1 = createCell(25,1);
    t_d_cell* temp2 = createCell(31,2);
    t_d_cell* temp3 = createCell(32,2);
    t_d_cell* temp4 = createCell(56,3);
    t_d_cell* temp5 = createCell(59,2);
    t_d_cell* temp6 = createCell(78,1);
    t_d_cell* temp7 = createCell(94,3);
    addheadList(list,temp);
    addCelltoList(list,temp1);
    addCelltoList(list,temp2);
    addCelltoList(list,temp3);
    addCelltoList(list,temp4);
    addCelltoList(list,temp5);
    addCelltoList(list,temp6);
    addCelltoList(list,temp7);
    t_d_list *list3= createonelistfromlist(*list);
    displayListWithLevelAlignedDisplay(*list3);
    printf("test");
    printf("La valeur %d est-elle presente dans la liste ?  %d \n",3, seekvaluedichotomique(*list3,3));


    printf("%d val trouve ?\n",seekvaluedichotomique(*list3,7));
    FILE *log_file = fopen("recherche100000valeurs.txt","w");
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
        for (int k = 0;k < 100000;k++) {
            seekvalue(*liste, k);
        }
        stopTimer();
        time_lvl0 = getTimeAsString(); // fonction du module timer
        printf("Recherche classique :\n");
        displayTime();
        startTimer();
        for (int k = 1;k < 100000;k++) {
            seekvaluedichotomique(*liste,k);
        }
        stopTimer();
        time_all_levels = getTimeAsString();
        fprintf(log_file, format, i, time_lvl0, time_all_levels);
        printf("Recheche dichotomique :\n");
        displayTime();
        i++;

    }
    fclose(log_file);

    t_d_agenda_list * liste = createagenda();
    t_d_cell_contact *contact = createContact();
    t_d_cell_contact *contact2 = createContact();
    t_d_cell_contact *contact3 = createContact();
    t_d_cell_contact *contact4= createContact();
    t_d_cell_contact *contact5 = createContact();
    t_d_cell_contact *contact6 = createContact();
    t_d_cell_contact *contact7 = createContact();
    t_d_cell_contact *contact8= createContact();
    addContactToAgenda(contact,liste);
    complete_afficher_agenda(*liste);
    addContactToAgenda(contact2,liste);
    complete_afficher_agenda(*liste);
    addContactToAgenda(contact3,liste);
    complete_afficher_agenda(*liste);
    addContactToAgenda(contact4,liste);
    complete_afficher_agenda(*liste);
    addContactToAgenda(contact5,liste);
    complete_afficher_agenda(*liste);
    addContactToAgenda(contact6,liste);
    complete_afficher_agenda(*liste);
    addContactToAgenda(contact7,liste);
    complete_afficher_agenda(*liste);
    addContactToAgenda(contact8,liste);
    complete_afficher_agenda(*liste);
    */


    //char fichier[] = "nom.txt";
    //ajouternomsfichier(fichier);
}
/*    t_d_rdv_cell* rdv =createRdv();
    insertion_rendez_vous_contact(c,rdv);
    t_d_rdv_cell* rdv2 =createRdv();
    insertion_rendez_vous_contact(c,rdv2);
    t_d_rdv_cell* rdv3 =createRdv();
    insertion_rendez_vous_contact(c,rdv3);
    afficher_rendez_vous_contact(*c);*/