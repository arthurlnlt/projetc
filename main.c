#include <stdio.h>
#include "fichier.h"
int main() {
    t_d_cell* temp = createCell(5,3);
    t_d_list* list = createList(3);
    list->head=temp;
    displayList(*list);
    return 0;
}
