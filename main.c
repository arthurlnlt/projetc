#include <stdio.h>
#include "fichier.h"
int main() {
    t_d_cell* temp = createCell(10,3);
    t_d_list* list = createList(3);
    t_d_cell* temp1 = createCell(5,3);
    addheadList(list,temp);
    displayList(*list);
    addCelltoList(list,temp1);
    t_d_cell* temp2 = createCell(8,2);
    displayList(*list);
    addCelltoList(list,temp2);
    displayList(*list);
    t_d_cell* temp3 = createCell(9,3);
    addCelltoList(list,temp3);
    displayList(*list);
    printf("la valeur est 1 si trouvee et 0 si pas trouvee :  %d",seekvaluedichotomique(*list,10));
    return 0;
}
