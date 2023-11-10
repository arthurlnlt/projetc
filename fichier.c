//
// Created by ryanc on 23/10/2023.
//
#include "fichier.h"
#include <stdlib.h>
#include <stdio.h>
#include "math.h"
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
    list->max_level=hauteur;
    list->head=(t_d_cell**)malloc(hauteur*sizeof(t_d_cell*));
    for (int i=0;i<hauteur;i++)
    {
        list->head[i]=NULL;
    }
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

void displayListWithLevelAlignedDisplay(t_d_list list)
{
    displaylistwithlevel(list,0);
    for (int i=1;i<list.max_level;i++)
    {
        t_d_cell* lvl0 = list.head[0];
        t_d_cell *temp=list.head[i];
        printf("[list head_%d @-]--",i);
        while (lvl0!=NULL)
        {
            if(temp==lvl0){
                printf(">[ %d|@-]--",temp->value);
                temp=temp->next[i];
                lvl0=lvl0->next[0];
            }
            else{
                printf("----------");
                lvl0=lvl0->next[0];
            }

        }
        printf(">NULL\n");
    }
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
        if (list->head[i]==NULL)        //utilisation fonction addheadcell ??
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
            while((temp->value<cell->value) && (temp->next[i]!=NULL))
            {
                prev = temp;
                temp=temp->next[i];
            }
            if (temp->next[i]==NULL && temp->value<cell->value)
            {
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
    t_d_cell* researchcell = list.head[0];
    while(researchcell!=NULL) {
        if (researchcell->value==val) {
            return 1;
        }
        researchcell = researchcell->next[0];
    }
    return 0;
}

int seekvaluedichotomique(t_d_list list,int valeur_recherchee)
{
    for (int i=list.max_level-1;i!=-1;i--)
    {
        int n=list.max_level;
        t_d_cell* searchcell = list.head[i];
        while(searchcell!=NULL)
        {
            if (searchcell->value==valeur_recherchee)
            {
                return 1;
            }
            searchcell=searchcell->next[i];
        }
    }
    return 0;
}

t_d_list *createonelistfromlist(t_d_list list)
{

    int k=(pow(2,list.max_level)-1);
    int *levels=(int*)malloc(k*sizeof(int));
    for (int i=0;i<k;i++)
    {
        levels[i]=0;
    }
    int compteur=2;
    while(compteur-2<(k/2))         //compteur-2  OU (k/2)+2 ?????
    {
        for (int i=compteur-1;i<k;i=i+compteur)
        {
            levels[i]+=1;
        }
        compteur=compteur*2;
    }
    t_d_list* listearetourner = createList(list.max_level);
    addheadList(listearetourner,createCell(1,levels[0]+1));
    for (int i=1;i<k;i++)
    {
        addCelltoList(listearetourner, createCell(i+1,levels[i]+1));
    }
    return listearetourner;
}