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


t_d_cell* createCell(int value,int hauteur);
t_d_list* createList(int value);
void displayList(t_d_list list);
void displayCell(t_d_cell* list,int hauteur);

#endif //UNTITLED1_FICHIER_H
