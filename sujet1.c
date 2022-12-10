#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


#define TMAX 500
#define NBR_RAND 1000

 
float SquareRoot(float X)
{
  float A,B,M,XN;
  if(X==0.0) {
     return 0.0;
  } else {
     M=1.0;
     XN=X;
     while(XN>=2.0) {
        XN=0.25*XN;
        M=2.0*M;
     }
     while(XN<0.5) {
        XN=4.0*XN;
        M=0.5*M;
     }
     A=XN;
     B=1.0-XN;
     do {
        A=A*(1.0+0.5*B);
        B=0.25*(3.0+B)*B*B;
     } while(B>=1.0E-15);
     return A*M;
  }
}


struct BNB{
    float dist;
    float accommodates;
    float bedrooms;
    float bathrooms;
    float beds;
    float prix;
    float minimum_nights;
    float maximum_nights;
    float number_of_reviews;

}BNB;

typedef struct BNB *airbnb;

#define accX 5.0
#define bedrX 2.0
#define bathX 1.0
#define bedsX 4.0
#define minX 1.0
#define maxX 1000.0
#define revwX 100.0  

airbnb creer_airbnb()
{
    airbnb lieux=malloc(sizeof(BNB));
    lieux->dist=0;
    lieux->accommodates=0;
    lieux->bedrooms=0;
    lieux->bathrooms=0;
    lieux->beds=0;
    lieux->prix=0;
    lieux->minimum_nights=0;
    lieux->maximum_nights=0;
    lieux->number_of_reviews=0;
    return lieux;
}

void afficher_airbnb(airbnb lieux)
{
    printf("lieux->dist= %f\nlieux->accommodates= %f\nlieux->bedrooms= %f\nlieux->bathrooms= %f\nlieux->beds= %f\nlieux->minimum_nights= %f\nlieux->maximum_nights= %f\nlieux->number_of_reviews= %f\nle prix est de: %f\n",lieux->dist,lieux->accommodates,lieux->bedrooms,lieux->bathrooms,lieux->beds,lieux->minimum_nights,lieux->maximum_nights,lieux->number_of_reviews,lieux->prix);
}

void afficher_tab_airbnb(airbnb* tab, int taille)
{
    for(int i=0;i<taille;i++)
    {
        printf("tab[%d] tab[i]->dist= %f\ntab[i]->accommodates= %f\ntab[i]->bedrooms= %f\ntab[i]->bathrooms= %f\ntab[i]->beds= %f\ntab[i]->minimum_nights= %f\ntab[i]->maximum_nights= %f\ntab[i]->number_of_reviews= %f\nle prix est de: %f\n",i,tab[i]->dist,tab[i]->accommodates,tab[i]->bedrooms,tab[i]->bathrooms,tab[i]->beds,tab[i]->minimum_nights,tab[i]->maximum_nights,tab[i]->number_of_reviews,tab[i]->prix);
    }
}

float carre(float a){
    return a*a;
}

float calculer_distance_X(airbnb lieux)
{
    float res=carre(lieux->accommodates-accX);//+carre(lieux->bedrooms-bedrX)+carre(lieux->bathrooms-bathX)+carre(lieux->beds-bedsX)+carre(lieux->minimum_nights-minX)+carre(lieux->maximum_nights-maxX)+carre(lieux->number_of_reviews-revwX);
    return res;
}

float calculer_distance_comms(airbnb lieux)
{
    float res=carre(lieux->number_of_reviews-revwX);//+carre(lieux->bedrooms-bedrX)+carre(lieux->bathrooms-bathX)+carre(lieux->beds-bedsX)+carre(lieux->minimum_nights-minX)+carre(lieux->maximum_nights-maxX)+carre(lieux->number_of_reviews-revwX);
    return res;
}

float calculer_distance_acc(airbnb lieux)
{
    float res=carre(lieux->accommodates-accX);//+carre(lieux->bedrooms-bedrX)+carre(lieux->bathrooms-bathX)+carre(lieux->beds-bedsX)+carre(lieux->minimum_nights-minX)+carre(lieux->maximum_nights-maxX)+carre(lieux->number_of_reviews-revwX);
    return res;
}

float calculer_distance_bath(airbnb lieux)
{
    float res=carre(lieux->bathrooms-bathX);//+carre(lieux->bedrooms-bedrX)+carre(lieux->bathrooms-bathX)+carre(lieux->beds-bedsX)+carre(lieux->minimum_nights-minX)+carre(lieux->maximum_nights-maxX)+carre(lieux->number_of_reviews-revwX);
    return res;
}

float calculer_distance_bedr(airbnb lieux)
{
    float res=carre(lieux->bedrooms-bedrX);//+carre(lieux->bedrooms-bedrX)+carre(lieux->bathrooms-bathX)+carre(lieux->beds-bedsX)+carre(lieux->minimum_nights-minX)+carre(lieux->maximum_nights-maxX)+carre(lieux->number_of_reviews-revwX);
    return res;
}

float calculer_distance_beds(airbnb lieux)
{
    float res=carre(lieux->beds-bedsX);//+carre(lieux->bedrooms-bedrX)+carre(lieux->bathrooms-bathX)+carre(lieux->beds-bedsX)+carre(lieux->minimum_nights-minX)+carre(lieux->maximum_nights-maxX)+carre(lieux->number_of_reviews-revwX);
    return res;
}

float calculer_distance_min(airbnb lieux)
{
    float res=carre(lieux->minimum_nights-minX);//+carre(lieux->bedrooms-bedrX)+carre(lieux->bathrooms-bathX)+carre(lieux->beds-bedsX)+carre(lieux->minimum_nights-minX)+carre(lieux->maximum_nights-maxX)+carre(lieux->number_of_reviews-revwX);
    return res;
}


float calculer_distance_max(airbnb lieux)
{
    float res=carre(lieux->maximum_nights-maxX);//+carre(lieux->bedrooms-bedrX)+carre(lieux->bathrooms-bathX)+carre(lieux->beds-bedsX)+carre(lieux->minimum_nights-minX)+carre(lieux->maximum_nights-maxX)+carre(lieux->number_of_reviews-revwX);
    return res;
}




void recup_coor(FILE* fichier, airbnb lieux)
{
    int compteur=0,i=-1,j=0;
    char ligne[TMAX],str[15],str2[15];
    char* pointeur;
    fgets(ligne,TMAX,fichier);
    while(compteur < 1 ) 
    {
        i++;
        if(ligne[i]==',' || ligne[i]==';')   compteur++;
    }
    i++;
    while(ligne[i]!=',' && ligne[i]!=';') // récupere accommodates
    {
        str[j]=ligne[i];
        i++;
        j++;
    }
    str[j]='\0';
    lieux->accommodates=atof(str);
    i++;
    j=0;
    while(ligne[i]!=',' && ligne[i]!=';') // récupere bedroom
    {
        str[j]=ligne[i];
        i++;
        j++;
    }
    str[j]='\0';
    lieux->bedrooms=atof(str);
    i++;
    j=0;
    while(ligne[i]!=',' && ligne[i]!=';') // récupere bathrooms
    {
        str[j]=ligne[i];
        i++;
        j++;
    }
    str[j]='\0';
    lieux->bathrooms=atof(str);
    i++;
    j=0;
    while(ligne[i]!=',' && ligne[i]!=';') // récupere beds
    {
        str[j]=ligne[i];
        i++;
        j++;
    }
    str[j]='\0';
    lieux->beds=atof(str);
    i++;
    j=0;
    while(ligne[i]!=',' && ligne[i]!=';') // récupere le prix
    {
        str[j]=ligne[i];
        i++;
        j++;
    }
    str[j]='\0';
    lieux->prix=atof(str);
    i++;
    j=0;
    while(ligne[i]!=',' && ligne[i]!=';') // récupere le minimum de nuit à passer
    {
        str[j]=ligne[i];
        i++;
        j++;
    }
    str[j]='\0';
    lieux->minimum_nights=atof(str);
    i++;
    j=0;
    while(ligne[i]!=',' && ligne[i]!=';') // récupere le maximum de nuit à passer
    {
        str[j]=ligne[i];
        i++;
        j++;
    }
    str[j]='\0';
    lieux->maximum_nights=atof(str);
    i++;
    j=0;
    while(ligne[i]!=',' && ligne[i]!=';') // récupere lenombre de commentaire
    {
        str[j]=ligne[i];
        i++;
        j++;
    }
    str[j]='\0';
    lieux->number_of_reviews=atof(str);
    i++;
    j=0;

    //afficher_airbnb(lieux);
}

void passer_ligne(FILE* flux)
{
    char chaine[TMAX];
    fgets(chaine,TMAX,flux);
}

int wc_l(FILE* flux)
{
    char chaine[TMAX];
    int compteur=-1;
    while(fgets(chaine,TMAX,flux)!=NULL)
    {
        compteur++;
    }
    rewind(flux);
    passer_ligne(flux);
    return compteur;
}


void permuter(airbnb* a, airbnb* b)
{
    airbnb temp;
    temp = *a;
    *a=*b;
    *b=temp;
}

void rand_tab(airbnb* tab, int taille)
{
    int j;
    srand(time(NULL));
    for(int i = 0; i<NBR_RAND;i++)
    {
        j=rand()%taille;
        permuter(&tab[0],&tab[j]);
    }
}

void quicksort(airbnb* number,int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while((number[i]->dist)<=(number[pivot]->dist) && i<last)
         i++;
         while((number[j]->dist)>(number[pivot]->dist))
         j--;
         if(i<j){
            permuter(&number[i],&number[j]);
         }
      }
      permuter(&number[pivot],&number[j]);
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
}

float moyenne_prix(airbnb* tab,int k)
{
    int i;
    float total=0;
    float res=0;
    for(i=0;i<k;i++){  
        res=res+tab[i]->prix;
    }
    return res/k;
}

int menu(airbnb* tab,int taille){
    int choix=0,booleen=1;
    float res=0.0;
    printf("______________________________________________________\n");
    printf("|                                                    |\n");
    printf("|quel parametre voulais vous utiliser?               |\n");
    printf("| 1.nombre de comms                                  |\n");
    printf("| 2.accommodates                                     |\n");
    printf("| 3.bedrooms                                         |\n");
    printf("| 4.bathrooms                                        |\n");
    printf("| 5.beds                                             |\n");
    printf("| 6.minimum nights                                   |\n");
    printf("| 7.maximum nights                                   |\n");
    printf("| autres. ne pas rajouter de critere                 |\n");
    printf("______________________________________________________\n");
    do{
        scanf("%d",&choix);
        switch(choix)
        {
            case 1:
                for(int i=0; i<=taille;i++)
                {
                    tab[i]->dist=tab[i]->dist+calculer_distance_comms(tab[i]);
                }
                break;
            case 2:
                for(int i=0; i<=taille;i++)
                {
                    tab[i]->dist=tab[i]->dist+calculer_distance_acc(tab[i]);
                }
                break;
            case 3:
                for(int i=0; i<=taille;i++)
                {
                    tab[i]->dist=tab[i]->dist+calculer_distance_bedr(tab[i]);
                }
                break;
            case 4:
                for(int i=0; i<=taille;i++)
                {
                    tab[i]->dist=tab[i]->dist+calculer_distance_bath(tab[i]);
                }
                break;
            case 5:
                for(int i=0; i<=taille;i++)
                {
                    tab[i]->dist=tab[i]->dist+calculer_distance_beds(tab[i]);
                }
                break;
            case 6:
                for(int i=0; i<=taille;i++)
                {
                    tab[i]->dist=tab[i]->dist+calculer_distance_min(tab[i]);
                }
                break;
            case 7:
                for(int i=0; i<=taille;i++)
                {
                    tab[i]->dist=tab[i]->dist+calculer_distance_max(tab[i]);
                }
                break;
            default:
                booleen=0;
        }
    }while(booleen);
    for(int i=0; i<=taille;i++)
                {
                    tab[i]->dist=SquareRoot(tab[i]->dist);
                }
    
}

int main ()
{
    //le fichier airbnb doit etre dans le meme dossier que le programme
    FILE* paris=fopen("airbnb_donnees_propre.csv","r");
    if (paris == NULL)  return 1;
    passer_ligne(paris);
    int taille =wc_l(paris),rien,k;
    airbnb* tableau=malloc(taille*sizeof(airbnb));
    for(int i=0; i<=taille;i++)
    {
        tableau[i]=creer_airbnb();
        recup_coor(paris,tableau[i]);
    }
    printf("avec combien de logement voulez vous estimer le prix?\n");
    scanf("%d",&k);
    menu(tableau,k);
    afficher_tab_airbnb(tableau,taille);
    rand_tab(tableau, taille);
    afficher_tab_airbnb(tableau,taille);
    quicksort(tableau,0,taille-1);
    
    afficher_tab_airbnb(tableau,k);
    printf("le prix moyen estimé est de %f\n",moyenne_prix(tableau,k));
}