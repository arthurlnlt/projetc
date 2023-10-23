//
// Created by ryanc on 23/10/2023.
//
#include "fichier.h"
#include <stdlib.h>
#include <stdio.h>
t_d_cell* createCell(int value,int hauteur)
{
    t_d_cell * cell = (t_d_cell*)malloc(1*sizeof(t_d_cell));
    cell->value=value;
    cell->next=(t_d_cell**)malloc(hauteur*sizeof(t_d_cell*));
    return cell;
}

t_d_list* createList(int hauteur)
{
    t_d_list * list=(t_d_list*)malloc(1*sizeof(t_d_list));
    list->head=(t_d_cell**)malloc(hauteur*sizeof(t_d_cell*));
    list->max_level=hauteur;
    return list;
}

void displayList(t_d_list list)
{
    for (int i=0;i<list.max_level;i++)
    {
        printf("[list head_%d @-]-->",i);
        displayCell(list.head[i],i);
        printf("NULL\n");
    }
}

void displayCell(t_d_cell* cell,int hauteur)
{
    printf("avant le drame");
    while(cell->next[hauteur]!=NULL)
    {
        printf("apres le drame");
        printf("[ %d|@-]-->",cell->value);
        cell=cell->next[hauteur];
    }
    printf("[ %d|@-]-->",cell->value);
}