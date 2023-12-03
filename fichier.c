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
    return cell;
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
                printf("-----------");
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
    for (int i=list.max_level-1;i!=-1;i--)  //On part du niveau le plus grand, au niveau le plus petit
    {
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

    int k=(pow(2,list.max_level)-1);    //initialisation du nombre de cases a créer
    int *levels=(int*)malloc(k*sizeof(int));
    for (int i=0;i<k;i++)   //initialisation a 0 de toute les cases
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
        addCelltoList(listearetourner, createCell(i+1,levels[i]+1));    //On ajoute la celulle de valeur i+1 ayant comme hauteur levels[i]+1
    }
    return listearetourner;
}

char* scanString()
{
    char* mot=(char*)malloc(sizeof(mot));
    fgets(mot,80,stdin);
    mot[strlen(mot)-1]='\0';
    return mot;
}

t_d_cell_contact* createContact()
{
    t_d_cell_contact* contact = (t_d_cell_contact*)malloc(1*sizeof(t_d_cell_contact));
    printf("saisissez votre nom:\n");
    contact->nom=scanString();
    //printf("Saisissez votre prenom\n");
    //contact->prenom = scanString();
    return contact;
}

t_d_rdv_cell* createRdv()   //ajout saisie securisee
{
    t_d_rdv_cell * rdv = (t_d_rdv_cell*) malloc(sizeof(t_d_rdv_cell));
    rdv->date=(int*)malloc(3*sizeof(int));
    printf("Ecrivez la date sous la forme JOUR ");
    scanf("%d",&rdv->date[0]);
    printf("Ecrivez la date sous la forme MOIS ");
    scanf("%d",&rdv->date[1]);
    printf("Ecrivez la date sous la forme ANNEE ");
    scanf("%d",&rdv->date[2]);
    rdv->horaire=(int*)malloc(2*sizeof(int));
    printf("Ecrivez l'heure sous la forme HEURE ");
    scanf("%d",&rdv->horaire[0]);
    printf("Ecrivez l'heure sous la forme MINUTE ");
    scanf("%d",&rdv->horaire[1]);
    rdv->dureerdv=(int*)malloc(2*sizeof(int));
    printf("Ecrivez la duree sous la forme HEURE ");
    scanf("%d",&rdv->dureerdv[0]);
    printf("Ecrivez la duree sous la forme MINUTE ");
    scanf("%d",&rdv->dureerdv[1]);
    rdv->next=(t_d_rdv_cell *)malloc(rdv->level*sizeof(t_d_rdv_cell ));
    printf("Saissez le motif du rdv :");
    rdv->motifrdv=scanString();
    rdv->next=NULL;
    return rdv;
}

t_d_agenda_list* createagenda()
{
    t_d_agenda_list * agenda = (t_d_agenda_list*)malloc(1*sizeof(t_d_agenda_list));
    agenda->head=(t_d_cell_contact**)malloc(4*sizeof(t_d_cell_contact));
    for (int i=0;i<4;i++)
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
        if (65<=nbAscii && nbAscii<=90)
        {
            mot[i]+=32;
        }
    }
}

void addRdvtoContact(t_d_cell_contact* contact, t_d_rdv_cell* rdv)
{
    if (contact->rendezvous==NULL)
    {
        contact->rendezvous=rdv;
    }
    else
    {
        t_d_rdv_cell * temp= contact->rendezvous;
        while(temp!=NULL)
        {
            temp=temp->next;
        }
        temp->next=rdv;
    }
}

void addContactToAgenda(t_d_cell_contact* contact,t_d_agenda_list* agenda) {
    modifierstrMajToMin(contact->nom);
    t_d_cell_contact *templvl3 = agenda->head[3];
    int i = 0;
    int j = 3;
    t_d_cell_contact *prev;
    if (agenda->head[0] == NULL) {
        contact->next = (t_d_cell_contact **) malloc((j+1) * sizeof(t_d_cell_contact *));
        for (int nb=0;nb<=j;nb++)
        {
            agenda->head[nb] = contact;
            contact->next[nb]=NULL;
        }
    }
    else {
        while (templvl3!= NULL && templvl3->nom[i]<=contact->nom[i])    //rajouter i<=3 ??
        {
            prev = templvl3;
            while (templvl3->nom[i] == contact->nom[i] && j>0){
                j--;
                i++;
            }
            templvl3 = templvl3->next[j];
        }
        if (templvl3==NULL)
        {
            templvl3=prev;
        }
        printf("valeur de j soit la hauteur %d du mot %s\n",j,contact->nom);
        contact->next = (t_d_cell_contact **) malloc((j+1) * sizeof(t_d_cell_contact *));
        for (int k = 0; k <= j; k++) {
            contact->next[k] = NULL;
        }
        for (int k = 0; k <= j; k++)
        {
            t_d_cell_contact *copie=templvl3;
            if (contact->nom[i]<agenda->head[k]->nom[i])
            {
                contact->next[k]=agenda->head[k];
                agenda->head[k]=contact;
            }
            else
            {
                while(copie->next[k]!=NULL)
                {
                    copie=copie->next[k];
                }
                printf("val de templvl3 %s, %d\n",templvl3->nom,k);
                printf("val de copie %s\n",copie->nom);
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
        while (lvl0!=NULL)     //fonctionne de la meme maniere que le aligneddisplay vue en partie 1
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


void ajouternomsfichier(char fichier[]){
    char nom[TAILLE_MAX] = "";
    fichier = fopen(fichier, "r");

    if (fichier != NULL)
    {
        while (fgets(nom, TAILLE_MAX, (FILE *) fichier) != NULL){
            // ajouter la fonction pour ajouter tous les noms aux contacts
            printf("%s", nom);
        }
        fclose((FILE *) fichier);
    }
}

void afficher_rendez_vous_contact(t_d_cell_contact contact)
{
    printf("Rendezvous de %s",contact.nom);
    t_d_rdv_cell* temp = contact.rendezvous;
    while(temp!=NULL)
    {
        printf(" Date : %d/%d/%d\n",temp->date[0],temp->date[1],temp->date[2]);
        printf("L'heure du rendez vous : %d:%d\n",temp->horaire[0],temp->horaire[1]);
        printf("Le rendez vous dure : %d %d\n",temp->dureerdv[0],temp->dureerdv[1]);
        printf("Le motif du rendez vous est %s\n",temp->motifrdv);
        temp=temp->next;
    }
    printf("%s n'a plus de rendez vous ",contact.nom);
}

void insertion_rendez_vous_contact(t_d_cell_contact * contact, t_d_rdv_cell* rdv)
{
    t_d_rdv_cell * temp=contact->rendezvous;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=rdv;
}

void supprimer_rendez_vous(t_d_rdv_cell* rdv, int* dateasupprimer)
{
    t_d_rdv_cell * prev =rdv;
    t_d_rdv_cell * temp = rdv;
    while(temp!=NULL && temp->date[0]!=dateasupprimer[0] && temp->date[1]!=dateasupprimer[1] && temp->date[2]!=dateasupprimer[2])
    {
        prev=temp;
        temp=temp->next;
    }
    if (temp==NULL)
    {
        printf("date non trouvee\n");
        free(temp);
    }
    else
    {
        prev->next=temp->next;
        temp->next=NULL;
        free(temp);
    }
}