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


typedef struct contact_d_cell
{
    char* nomETprenom;
    int level;
    struct s_d_cell **next;
} contact_d_cell;

typedef struct rdv_d_cell
{
    int* date;
    int* horaire;
    int* horairerdv;
    char* motif;
    int level;
    struct s_d_cell **next;
} rdv_d_cell;

typedef struct s_d_list
{
    int max_level;
    t_d_cell **head;
} t_d_list;


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
#endif //UNTITLED1_FICHIER_H
