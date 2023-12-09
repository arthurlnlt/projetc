//Auteur : GASNIER Mathieu LAINAULT Arthur et CROHAS Ryan groupe E

#include "fichier.h"
#include <stdlib.h>
#include "string.h"
#include <stdio.h>
#include "math.h"

#define TAILLE_MAX 10000

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
    return cell; //retourne la cellule crée
}

t_d_list* createList(int hauteur)
{
    t_d_list * list=(t_d_list*)malloc(1*sizeof(t_d_list));
    list->max_level=hauteur;
    list->head=(t_d_cell**)malloc(hauteur*sizeof(t_d_cell*)); //allocation dynamique selon la hauteur de la liste
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
        while (lvl0!=NULL)      // on va comparer la liste de niveau i par rapport a la liste de niveau 0, si elles ne pointent pas vers la meme celulle alors on affiche un simple espace
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
        if (list->head[i]==NULL)        //cas ou la tete est nulle
        {
            list->head[i]=cell;
        }
        else if (temp->value>cell->value) { // cas ou la valeur de la celulle est INFERIEUR a la tete
            cell->next[i] = temp;
            list->head[i] = cell;
        }
        else
        {
            t_d_cell *prev = temp;
            while((temp->value<cell->value) && (temp->next[i]!=NULL))  // on avance dans la liste tant que la valeur de CELL est inférieur a celle de temp
            {
                prev = temp;
                temp=temp->next[i];
            }
            if (temp->next[i]==NULL && temp->value<cell->value)     //cas ou on insere en fin de liste
            {
                temp->next[i]=cell;
            }
            else        //cas ou on insere en millieu de liste
            {
                cell->next[i]=prev->next[i];
                prev->next[i]=cell;
            }
        }
    }
}

int seekvalue(t_d_list list,int val)
{
    t_d_cell* researchcell = list.head[0];  //parcours la liste au niveau 0
    while(researchcell!=NULL) {
        if (researchcell->value==val) {
            return 1;
        }
        researchcell = researchcell->next[0];
    }
    return 0;
}

int seekvaluedichotomique(t_d_list mylist, int val)
{
    t_d_cell* temp;
    t_d_cell * prev;
    int j=mylist.max_level-1;
    temp = mylist.head[j];      //parcours la liste au niveau max
    while (temp!=NULL)
    {
        if (temp->value == val)
        {
            return 1;
        }
        else if (temp->value >val && temp == mylist.head[j])    //cas où la valeur a rechercher est a gauche de la temp
        {
            if(j>0){       //si j>0, on descend d'un niveau
                j--;
            }
            temp = mylist.head[j];
        }
        else if (val > temp->value)     //cas où la valeur a rechercher est à droite de la temp
        {
            prev=temp;
            if(j>0){        //si j>0, on descend d'un niveau
                j--;
            }
            temp = temp->next[j];
        }
        else    //cas où la temp est superieure a la valeur, il faut donc récuperer le prev et aller a son successeur a un niveau inferieur
        {
            if(j>0){        //si j>0, on descend d'un niveau
                j--;
            }
            temp=prev->next[j];
        }
    }
    return 0;
}

t_d_list *createonelistfromlist(t_d_list list)
{

    int k=(pow(2,list.max_level)-1);    //initialisation du nombre de cases a créer
    int *levels=(int*)malloc(k*sizeof(int));
    for (int i=0;i<k;i++)   //initialisation a 0 de toute les cases
    {
        levels[i]=0;
    }
    int compteur=2;
    while(compteur-2<(k/2))         //Il faut à la fois, diviser la liste en 2, mais aussi avancer de compteur fois
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
        addCelltoList(listearetourner, createCell(i+1,levels[i]+1));    //On ajoute la celulle de valeur i+1 ayant comme hauteur levels[i]+1
    }
    return listearetourner;
}

char* scanString()
{
    char* mot=(char*)malloc(80*sizeof(mot));
    fgets(mot,80,stdin);
    mot[strlen(mot)-1]='\0';
    return mot;
}

t_d_cell_contact* createContact()
{
    t_d_cell_contact* contact = (t_d_cell_contact*)malloc(1*sizeof(t_d_cell_contact));
    printf("saisissez votre nom:\n");
    contact->nom = scanString();
    sleep(5);                                           //utilisation de sleep pour éviter que le main plante (le main compile plus vite que la saisie, mais on ne comprends pas pourquoi
    printf("Saisissez votre prenom\n");
    contact->prenom = scanString();
    sleep(5);
    contact->rendezvousHead=NULL;
    return contact;
}

t_d_cell_contact* createContactFromNom(char* mot)   //fonction utilisée pour créer l'agenda à partir d'un fichier
{
    t_d_cell_contact* contact = (t_d_cell_contact*)malloc(1*sizeof(t_d_cell_contact));
    strcpy(contact->nom,mot);
    contact->prenom = scanString();
    contact->rendezvousHead=NULL;
    return contact;
}


t_d_rdv_cell* createRdv()
{
    t_d_rdv_cell* rdv = (t_d_rdv_cell*)malloc(sizeof(t_d_rdv_cell));
    rdv->date=(int*)malloc(3*sizeof(int));
    printf("Ecrivez la date sous la forme JOUR/MOIS/ANNEE ");
    scanf("%d/%d/%d",&rdv->date[0],&rdv->date[1],&rdv->date[2]);
    rdv->horaire=(int*)malloc(2*sizeof(int));
    printf("Ecrivez l'heure sous la forme HEUREhMINUTE ");
    scanf("%dh%d",&rdv->horaire[0],&rdv->horaire[1]);
    rdv->dureerdv=(int*)malloc(2*sizeof(int));
    printf("Ecrivez la duree sous la forme HEUREhMINUTE ");
    scanf("%dh%d",&rdv->dureerdv[0],&rdv->dureerdv[1]);
    rdv->next=(t_d_rdv_cell *)malloc(sizeof(t_d_rdv_cell));
    printf("Saissez le motif du rdv :\n");
    rdv->motifrdv=(char*)malloc(80*sizeof(char));
    rdv->motifrdv = scanString();
    rdv->next=NULL;
    return rdv;
}

t_d_agenda_list* createagenda()
{
    t_d_agenda_list * agenda = (t_d_agenda_list*)malloc(1*sizeof(t_d_agenda_list));
    agenda->head=(t_d_cell_contact**)malloc(4*sizeof(t_d_cell_contact));
    for (int i=0;i<4;i++)   //un agenda à forcement 4 de hauteur
    {
        agenda->head[i]=NULL;
    }
    return agenda;
}

void modifierstrMajToMin(char* mot)
{
    for (int i=0;mot[i]!='\0';i++)
    {
        int nbAscii = mot[i];
        if (65<=nbAscii && nbAscii<=90)     //lettre majuscule
        {
            mot[i]+=32;         //+32 pour passer de majuscule à minuscule
        }
    }
}

void addContactToAgenda(t_d_cell_contact* contact,t_d_agenda_list* agenda) {
    modifierstrMajToMin(contact->nom);
    t_d_cell_contact *templvl3 = agenda->head[3];   //on copie le niveau le plus haut
    int i = 0;                                      //besoin de deux variable, une pour la hauteur de la liste, une autre pour comparer l'indice i du mot
    int j = 3;
    t_d_cell_contact *prev;
    if (agenda->head[0] == NULL) {      //cas ou la head est NULLE la hauteur de la celulle est forcement 4
        contact->next = (t_d_cell_contact **) malloc((j+1) * sizeof(t_d_cell_contact *));
        for (int nb=0;nb<=j;nb++)
        {
            agenda->head[nb] = contact;
            contact->next[nb]=NULL;
        }
        contact->level=j;
    }
    else {
        while (templvl3!= NULL && templvl3->nom[i]<=contact->nom[i])    // Ici, le while permet de récuperer la hauteur du contact a ajouter,
        {
            prev = templvl3;
            while (templvl3->nom[i] == contact->nom[i] && j>0){     //si le nom du contact est égal au nom de la liste que l'on a copié, on descends de niveau, mais augmente l'indice du nom de recherche
                j--;
                i++;
            }
            templvl3 = templvl3->next[j];       //next de la hauteur de j ( donc si on décrémente bien, on descends de niveau)
        }
        if (templvl3==NULL)     //cas en fin de liste
        {
            templvl3=prev;
        }
        contact->next = (t_d_cell_contact **) malloc((j+1) * sizeof(t_d_cell_contact *));   //on connait la hauteur, donc on peut allouer dynamiquement
        for (int k = 0; k <= j; k++) {
            contact->next[k] = NULL;
        }
        contact->level=j;
        for (int k = 0; k <= j; k++)    //reparcours de notre liste pour L'insertion désormais
        {
            t_d_cell_contact *copie=templvl3;
            if (contact->nom[i]<agenda->head[k]->nom[i])    //cas ou il faut déplacer la tete de l'agenda
            {
                contact->next[k]=agenda->head[k];
                agenda->head[k]=contact;
            }
            else                                            //tout les autres cas (où il faut affecter le successeur de copie)
            {
                while(copie->next[k]!=NULL)
                {
                    copie=copie->next[k];
                }
                copie->next[k]=contact;
            }
        }
    }
}

void afficher_agenda(t_d_agenda_list list,int level){
    printf("[list head_%d @-]-->",level);
    t_d_cell_contact * temp = list.head[level];
    while(temp!=NULL)
    {
        printf("[ %s|@-]-->",temp->nom);
        temp=temp->next[level];
    }
    printf("NULL\n");
}

void complete_afficher_agenda(t_d_agenda_list list)
{
    afficher_agenda(list,0);
    for (int i=1;i<=3;i++)
    {
        t_d_cell_contact * lvl0= list.head[0];
        t_d_cell_contact *temp=list.head[i];
        printf("[list head_%d @-]--",i);
        while (lvl0!=NULL)                          //fonctionne de la meme maniere que le aligneddisplay vue en partie 1
        {
            if(temp==lvl0){
                printf(">[ %s|@-]--",temp->nom);
                temp=temp->next[i];
                lvl0=lvl0->next[0];
            }
            else{
                printf("-----");
                for (int k=0;lvl0->nom[k]!='\0';k++)
                {
                    printf("-");
                }
                printf("----");
                lvl0=lvl0->next[0];
            }
        }
        printf(">NULL\n");
    }
}


void ajouternomsfichier(char fichier[],t_d_agenda_list* agenda){        // recupere un fichier passé en parametre et ajoute chaque nom dans l'agenda
    char nom[TAILLE_MAX] = "";
    fichier = fopen(fichier, "r");

    if (fichier != NULL)
    {
        while (fgets(nom, TAILLE_MAX, (FILE *) fichier) != NULL){
            // ajouter la fonction pour ajouter tous les noms aux contacts
            addContactToAgenda(createContactFromNom(nom),agenda);
            complete_afficher_agenda(*agenda);
        }
        fclose((FILE *) fichier);
    }
}

void afficher_rendez_vous_contact(t_d_cell_contact contact)
{
    printf("Rendezvous de %s", contact.nom);
    if (contact.rendezvousHead==NULL)
    {
        printf(" n'a pas de rendez-vous... Pensez a en rajouter un !\n");
    }
    else {

        t_d_rdv_cell *temp = contact.rendezvousHead;
        while (temp != NULL) {
            printf(" Date : %d/%d/%d\n", temp->date[0], temp->date[1], temp->date[2]);
            printf("L'heure du rendez vous : %dh%d\n", temp->horaire[0], temp->horaire[1]);
            printf("Le rendez vous dure : %dh%d\n", temp->dureerdv[0], temp->dureerdv[1]);
            printf("Le motif du rendez vous est %s\n", temp->motifrdv);
            temp = temp->next;
        }
        printf("%s n'a plus de rendez vous \n", contact.nom);
    }
}

void insertion_rendez_vous_contact(t_d_cell_contact * contact, t_d_rdv_cell* rdv)
{
    if (contact->rendezvousHead==NULL)
    {
        contact->rendezvousHead=rdv;
    }
    else
    {
        t_d_rdv_cell * temp=contact->rendezvousHead;        //si la tete n'est pas null on parcours la liste de contact alors
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=rdv;
    }
}

void supprimer_rendez_vous(t_d_cell_contact * contact, int* dateasupprimer)
{
    if (contact->rendezvousHead!=NULL) {
        t_d_rdv_cell *prev = contact->rendezvousHead;
        t_d_rdv_cell *temp = prev;
        if (temp->date[0] == dateasupprimer[0] && temp->date[1] == dateasupprimer[1] && temp->date[2] == dateasupprimer[2]) { // cas ou il faut retirer en tete
            contact->rendezvousHead = prev->next;
            prev->next = NULL;
            free(prev);
        } else {
            while (temp != NULL && temp->date[0] != dateasupprimer[0] && temp->date[1] != dateasupprimer[1] && temp->date[2] != dateasupprimer[2]) { //sinon on avance
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL) { //si on a rien
                printf("date non trouvee\n");
                free(temp);
            } else {        //sinon on supprime le temp
                prev->next = temp->next;
                temp->next = NULL;
                free(temp);
            }
        }
    }
    else
    {
        printf("Ce contact n'a pas de rendez-vous... Pensez a en ajouter un avant d'en supprimer !\n");
    }
}

t_d_cell_contact *seekContact(t_d_agenda_list list, char * mot)
{
    if (list.head!=NULL) {
        t_d_cell_contact *temp;
        temp = list.head[0];
        while (temp != NULL) {
            if (strncmp(temp->nom, mot, strlen(mot)) == 0) {    //permet de comparer les deux mots
                return temp;
            }
            temp = temp->next[0];
        }
        return NULL;
    }
    else {
        return NULL;
    }
}