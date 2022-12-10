#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


struct proces
{
    char nom[50];
    int duree;
    int priorite;
};
//processus définie sous forme de structure avec le nom, la durée et la priorité

typedef struct proces *processus;

struct file
{
    processus val;
    struct file* suivant;
}file;
//est une structure représentant une file d'exécution


typedef struct file *liste;

processus creer_proc()
{
    processus proc=(processus)malloc(sizeof(struct proces));
    printf("quel nom?\n");
    scanf("%s",proc->nom);
    printf("quelle duree?\n");
    scanf("%d",&proc->duree);
    printf("quel niveau de priorite?\n");
    scanf("%d",&proc->priorite);
    return proc;
}
//Cette fonction permet de créer un processus en permettant d'entréer un nom, une durée et une priorité


liste creer_noeud()
{
    liste tete=(liste)malloc(sizeof(struct file));
    tete->val=NULL;
    tete->suivant=NULL;
    return tete;
}
//crée un neoud qui contient un processus et les informations pour aller au processus suivant

void suppression(liste L)
{
    if (L == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (L != NULL)
    {
        processus aSupprimer = L->val;
        L = L->suivant;
        free(aSupprimer);
    }
}
//permet de libérer l'espace apès avoir exécuté un processus


void afficher_liste(liste tete)
{
    while(tete->suivant != NULL){
        printf("%s a une durée de %d et une priorité de %d\n",tete->val->nom,tete->val->duree,tete->val->priorite);
        tete=tete->suivant;
    }
    printf("%s a une durée de %d et une priorité de %d\n",tete->val->nom,tete->val->duree,tete->val->priorite);
}
//permet d'afficher tout les processus present dans une file d'exécution


void ajout_activite(liste L,processus p)
{
    while(L->suivant !=  NULL){
        L=L->suivant;
    }
    L->suivant=creer_noeud();
    L->suivant->val=p;
}
//permet d'ajouter un processus à une file L


liste step2(liste L)
{
    if(L!=NULL){
        if(L->val->duree > 0){
            L->val->duree--;
            printf("il reste à %s %d itération.\n",L->val->nom,L->val->duree);
            return L;
        }else{
            return L->suivant;
        }
    }else{
        printf("la liste est vide\n");
        return NULL;
    }
}
//permet d'exécuter la file jusqu'à ce qu'elle soit vide


void s_sleep(int seconds) {
    time_t start_time = 0;
    time_t current_time = 0;

    start_time = time(NULL);
    while(current_time-start_time+1 <= seconds) {
        current_time = time(NULL);
    }
}
// une fonction qui permet d'attendre x seconde


void run2(liste L)
{
    while(L=step2(L)){
        s_sleep(1);
    }
}
//la fonction run2 exécute step2 tant qu'il n'est pas null et attend 1 seconde à chaque itération

void clean(void)
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}
//cette fonction permet de vider le buffer


char demander(){
    char r;
    while(r!= 'y' && r != 'n'){
        clean();
        printf("voulez vous continuer?(y ou n)\n");
        scanf("%c",&r);
        clean();
    }
    return r;
}
//cette fonction permet de demander à l'utilisateur si il veut continuer à rentrer des processus


liste creer_liste()
{
    liste L=creer_noeud();
    L->val=creer_proc();
    char rep='y';
    while(rep == 'y'){
        ajout_activite(L,creer_proc());
        rep=demander();
    }
    return L;
}
//cette fonction crée la file de processus

int main()
{
    liste L=creer_liste();
    afficher_liste(L);
    run2(L);
}