//
// Created by ryanc on 23/10/2023.
//

#ifndef UNTITLED1_FICHIER_H
#define UNTITLED1_FICHIER_H

typedef struct s_d_cell
{
    int value;
    int level;
    struct s_d_cell **next;
} t_d_cell;

typedef struct s_d_list
{
    int max_level;
    t_d_cell **head;
} t_d_list;

typedef struct s_d_rdv_cell
{
    int* date;
    int* horaire;
    int* dureerdv;
    char* motifrdv;
    int level;
    struct s_d_rdv_cell *next;
} t_d_rdv_cell;

typedef struct s_d_cell_contact
{
    char* nom;
    char* prenom;
    struct s_d_cell_contact ** next;
    t_d_rdv_cell * rendezvous;
} t_d_cell_contact;

typedef struct s_d_agenda_list
{
    t_d_cell_contact **head;
} t_d_agenda_list;
//test
t_d_cell* createCell(int value,int hauteur);
t_d_list* createList(int hauteur);
void displayList(t_d_list list);
void addCelltoList(t_d_list* list,t_d_cell *cell);
void addheadList(t_d_list* list,t_d_cell* cell);
void displaylistwithlevel(t_d_list list, int level);
int seekvalue(t_d_list list,int valeur_recherchee);
int seekvaluedichotomique(t_d_list list,int valeur_recherchee);
t_d_list *createonelistfromlist(t_d_list list);
void displayListWithLevelAlignedDisplay(t_d_list list);

char *scanString();
t_d_agenda_list * createagenda();
t_d_rdv_cell* createRdv();
t_d_cell_contact* createContact();
void addContactToAgenda(t_d_cell_contact* contact,t_d_agenda_list* agenda);
void afficher_agenda(t_d_agenda_list list,int level);
void complete_afficher_agenda(t_d_agenda_list list);
void modifierstrMajToMin(char* mot);
#endif //UNTITLED1_FICHIER_H
