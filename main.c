#include <stdio.h>
#include "fichier.h"
#include "math.h"
#include "timer.h"
int main() {
    // Liste à niveau vide
    printf("Liste à niveau vide :\n");
    t_d_list* list = createList(5);
    t_d_list* list2 = createList(3);
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
    addheadList(list2,temp8);
    addCelltoList(list2,temp9);
    addCelltoList(list2,temp10);
    t_d_list *list3= createonelistfromlist(*list2);
    displayListWithLevelAlignedDisplay(*list3);
    printf("%d val trouve ?\n",seekvaluedichotomique(*list3,7));

}
