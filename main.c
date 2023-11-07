#include <stdio.h>
#include "fichier.h"
int main() {
    // Liste à niveau vide
    printf("Liste à niveau vide :\n");
    t_d_list* list = createList(5);
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
    displayList(*list);


    printf("la valeur est 1 si trouvee et 0 si pas trouvee :  %d",seekvalue(*list,11));
    return 0;
}
