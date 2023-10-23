//
// Created by ryanc on 23/10/2023.
//
#include "fichier.h"
#include <stdlib.h>
t_d_cell* createCell(int value)
{
    t_d_cell * cell = (t_d_cell*)malloc(1*sizeof(t_d_cell));
    cell->value=value;
    cell->next_0=NULL;
    cell->next_1=NULL;
    return cell;
}