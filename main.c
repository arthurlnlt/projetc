#include <stdio.h>
#include "fichier.h"
int main() {
    t_d_cell* temp = createCell(10,3);
    t_d_list* list = createList(3);
    addheadList(list,temp);
    displayList(*list);
    return 0;
}
