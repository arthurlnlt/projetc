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
    cell->level=hauteur;
    cell->next=(t_d_cell**)malloc(hauteur*sizeof(t_d_cell*));
    for (int i=0;i<cell->level;i++)
    {
        cell->next[i]=NULL;
    }
    return cell;
}

t_d_list* createList(int hauteur)
{
    t_d_list * list=(t_d_list*)malloc(1*sizeof(t_d_list));
    list->head=(t_d_cell**)malloc(hauteur*sizeof(t_d_cell*));
    for (int i=0;i<hauteur;i++)
    {
        list->head[i]=NULL;
    }
    list->max_level=hauteur;
    return list;
}

void addheadList(t_d_list* list,t_d_cell* cell)
{
    for (int i=0;i<cell->level;i++)
    {
        list->head[i]=cell;
    }
}

void displaylistwithlevel(t_d_list list, int level)
{
    printf("[list head_%d @-]-->",level);
    t_d_cell* temp = list.head[level];
    while(temp!=NULL)
    {
        printf("[ %d|@-]-->",temp->value);
        temp=temp->next[level];
    }
    printf("NULL\n");
}

void displayList(t_d_list list)
{
    for (int i=0;i<list.max_level;i++)
    {
        displaylistwithlevel(list,i);
    }
}

void addCelltoList(t_d_list* list,t_d_cell *cell)
{
    for (int i=0;i<cell->level;i++)
    {
        t_d_cell* temp=list->head[i];
        if (list->head[i]==NULL)
        {
            list->head[i]=cell;
        }
        else if (temp->value>cell->value) {
            cell->next[i] = temp;
            list->head[i] = cell;
        }
        else
        {
            t_d_cell *prev = temp;
            while((temp->value<cell->value) && (temp->next[i]!=NULL)) // cas apres la head et le cas en fin de liste
            {
                prev = temp;
                temp=temp->next[i];
            }
            if (temp->next[i]==NULL && temp->value<cell->value)
            {
                printf("ok");
                temp->next[i]=cell;
            }
            else if (temp->next[i]==NULL && temp->value<cell->value){
                cell->next[i]=temp->next[i];
                temp->next[i]=cell;
            }
            else
            {
                cell->next[i]=prev->next[i];
                prev->next[i]=cell;
            }
        }
    }
}

int seekvalue(t_d_list list,int val)
{
    for (int i=list.max_level;i!=-1;i++)
    {
        t_d_cell* researchcell = list.head[i];
        while(researchcell!=NULL) {
            if (researchcell->value==val) {
                return 1;
            }
            researchcell = researchcell->next[i];
        }
    }
    return 0;
}

int seekvaluedichotomique(t_d_list list,int valeur_recherchee)
{
    return 0;
}