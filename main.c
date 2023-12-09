//Auteur : GASNIER Mathieu LAINAULT Arthur et CROHAS Ryan groupe E

#include <stdio.h>
#include "fichier.h"
#include <stdlib.h>
#include "math.h"
#include "timer.h"
int main() {
    printf("Bienvenue sur le fichier global \n tapez 1 pour la partie 1\n 2 pour la partie 2\n 3 pour la partie 3\n");
    int nombrechoisi=0;
    scanf("%d",&nombrechoisi);
    if (nombrechoisi==1)
    {
        printf("Bienvenue sur la partie 1 du projet : \n");
        printf("Saisissez la hauteur de la liste:\n");
        int k=0,x=0,y=0;
        char c;
        scanf("%d",&x);
        t_d_list* list = createList(x);
        t_d_cell* temp;
        while(c!='a')
        {
            printf("1 : permet de creer une cellule et de l'ajouter a la liste :\n"
                   "2 : afficher la liste :\n"
                   "3 : afficher la liste de maniere alignee :\n"
                   "4 : Quitter le programme \n");
            scanf("%d",&k);
            switch(k){
                case(1):
                    printf("Entrez une valeur : ");
                    scanf("%d",&x);
                    printf("Entrez la hauteur de la cellule :\n");
                    scanf("%d",&y);
                    temp = createCell(x,y);
                    addCelltoList(list,temp);
                    break;
                case(2):
                    displayList(*list);
                    break;
                case(3):
                    displayListWithLevelAlignedDisplay(*list);
                    break;
                case(4):
                    printf("Sortie du programme\n");
                    c='a';
                    break;
                default :
                    printf("valeur depasse \n");

            }
        }
    }
    else if (nombrechoisi==2){
        printf("Bienvenue sur la partie 2 du projet\n");
        FILE *log_file = fopen("recherche100000valeurs.txt","w");
        char format[] = "%d\t%s\t%s\n" ;
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
        return 0;
    }
    else
    {
        int i = 0;
        char c = 'c';
        t_d_rdv_cell* rdv;
        t_d_cell_contact *contact;
        t_d_cell_contact *contactarechercher;
        t_d_agenda_list *list = createagenda();
        printf("Bienvenue sur l'AGENDA\n");
        while (c == 'c') {
            printf("Veuillez choisir une action :\n"
                   "1- Ajouter un contact\n"
                   "2- Ajouter un rendez-vous a un contact\n"
                   "3- Afficher les rendez-vous d'un contact\n"
                   "4- Supprimer un rendez-vous\n"
                   "5- Rechercher un contact :\n"
                   "6- Quitter l'agenda :\n");
            scanf("%d", &i);
            switch (i) {
                case (1):
                    contact = createContact();
                    sleep(5);
                    addContactToAgenda(contact, list);
                    break;
                case (2):
                    rdv = createRdv();
                    sleep(10);
                    printf("Saisissez le nom du contact à rechercher :\n");
                    char *mot=scanString();
                    sleep(10);
                    t_d_cell_contact *contact2 = seekContact(*list, mot);
                    if (contact2!=NULL)
                    {
                        insertion_rendez_vous_contact(contact2, rdv);
                    }
                    else
                    {
                        t_d_cell_contact *contact_a_ajouter = createContact();
                        strcpy(contact_a_ajouter->nom,mot);
                        addContactToAgenda(contact_a_ajouter,list);
                        insertion_rendez_vous_contact(contact_a_ajouter,rdv);
                    }
                    break;
                case (3):
                    printf("Saisissez le nom du contact a rechercher :\n");
                    char *mot1 = scanString();
                    sleep(5);
                    t_d_cell_contact *contact1 = seekContact(*list, mot1);
                    if (contact1==NULL)
                    {
                        printf("ce contact n'a pas de rendez-vous\n");
                    }
                    else
                    {
                        afficher_rendez_vous_contact(*contact1);
                    }
                    break;
                case (4):
                    printf("Vous voulez supprimer un rendez-vous, mais de quel contact ?\n");
                    char *mot2 = scanString();
                    sleep(5);
                    contact = seekContact(*list, mot2);
                    printf("Saisissez la date du rendez-vous a supprimer sous la forme JOUR/MOIS/ANNEE:\n");
                    int *date = (int *) malloc(3 * sizeof(int));
                    scanf("%d/%d/%d",&date[0],&date[1],&date[2]);
                    sleep(5);
                    supprimer_rendez_vous(contact, date);
                    break;
                case (5):
                    printf("Saisissez le nom du contact à rechercher :\n");
                    char * mot3 = scanString();
                    sleep(5);
                    contactarechercher = seekContact(*list, mot3);
                    if (contactarechercher == NULL)
                        printf("Le contact n'est pas present dans la liste\n");
                    else
                        printf("Le contact est present dans la liste\n");
                    break;
                case (6):
                    printf("Sortie du programme \n");
                    c = 'a';
                    break;
                default:
                    printf("La valeur n'a pas été reconnu\n");
            }
        }
    }

    //char fichier[] = "nom.txt";     //fichier que l'on va récuperer
    //ajouternomsfichier(fichier,liste);
}