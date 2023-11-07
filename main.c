#include <stdio.h>
#include "fichier.h"
int main() {
    t_d_cell* temp = createCell(10,3);
    t_d_list* list = createList(3);
    t_d_cell* temp1 = createCell(5,3);
    addheadList(list,temp);
    displayList(*list);
    addCelltoList(list,temp1);
    t_d_cell* temp2 = createCell(15,3);
    displayList(*list);
    addCelltoList(list,temp2);
    displayList(*list);
    return 0;
}
