#include <stdio.h>
#include <string.h>
// structure des donnees d etudiant //
typedef struct
{
       int id;
       char nom[20];
       char prenom[20];
       char date[20];
       float note;
       char departement[20];
} eleve;
// declaration des variables global //
eleve c[100];
int q;
// la fonction d ajoute//
void ajout()
{
       // declaration des variables local  en fonction d ajoute//

       char w;
       // ecrire les donnees de etudiant //
       q = 0;
       do
       {
              printf("________________________________________________________________________________________________________\n");
              printf("_______________________________________ ajoute de etudiant N :%d ______________________________________\n", q + 1);
              // ajoute le nom d etudiant //
              printf("entre le nom d etudiant :");
              getchar();
              fgets(c[q].nom, 20, stdin);
              // ajoute le prenom d etudiant //
              printf("entre le prenom d etudiant :");
              getchar();
              fgets(c[q].prenom, 20, stdin);
              // ajout le date de naissance//
              printf("entre la date de naissance  d etudiant :");
              getchar();
              fgets(c[q].date, 20, stdin);
              // ajoute le departement d etudiant //
              printf("entre votre departement one 4 dapartement (MIP,PC,IN,BIO) :");
              getchar();
              fgets(c[q].departement, 20, stdin);
              // ajoute la note general d etudiant//
              printf("entre la note  general :");
              scanf("%f",&c[q].note);
              // pour donner le choix a lutilisateur d entre un autre etudiant//
              printf("Voulez-vous ajouter un autre etudiant?(y/n) :");
              scanf("%s",&w);
              q++;
              c[q].id= q;
       } while (w == 'y');

       // finir la fonction d ajoute//
}
       // fonction modification d un etudiant //
void modification()
{
       // declarer les variables global//
       int e, r, t;
       char nevnom[20],nevprenom[20],nevdate[20],nevdepartement[20];
       float nevnote;
       printf("Veuillez entrer l identifiant unique:");
       scanf("%d",&r);
       printf("________________________________________________________________________________________________________\n");
       for (e = 0; e < q; e++)
       {
              if (r == c[e].id)
              {
//menu de modification des informations d etudiant
                     printf("________________________________________________________________________________________________________\n");
                     printf("_______________________________________ modification  etudiant N :%d ______________________________________\n", c[e].id);
                     printf("1)modifier le nom                                                                 2)modifier le prenom \n");
                     printf("3)modifier le departement                                                         4)modifier la note generale \n");
                     printf("                                        5)modifier la date de naissance \n");
                     printf("entre :");
                     scanf("%d",&t);
              switch(t){
//modification de nom//
                     case 1:
                     printf("entre le nom:");
                     getchar();
                     fgets(nevnom,20,stdin);
                     strcpy(nevnom,c[e].nom);
              break;
//modification de prenom//
                     case 2:
                     printf("entre le  prenom:");
                     getchar();
                     fgets(nevprenom,20,stdin);
                     strcpy(nevprenom,c[e].prenom);
              break;
//modification de date de naissance//
                     case 5:
                     printf("entre la date de naissance:");
                     getchar();
                     fgets(nevdate,20,stdin);
                     strcpy(nevdate,c[e].date);
              break;
// modification de la departement
                     case 3:
                     printf("entre le  departement:");
                     getchar();
                     fgets(nevdepartement,20,stdin);
                     strcpy(nevdepartement,c[e].departement);
              break;
//modification de note general//
                     case 4:
                      printf("entre la note :");
                      scanf("%f",&nevnote);
                     c[e].note==nevnote;
              break;
              }
       }
} 
}
/// fonction de suprimer //
void suprimer(){
 // declaration des variables local de fonction suprimer//
       int y,i;
       char u;
//demande a l utilisateur de entre l identifiant unique//
       printf("Veuillez entrer l identifiant unique:");
       scanf("%d",&y);
       printf("Es-tu sur?(y/n)");
       scanf("%c",&u);
       if(u=='y'){
            


       }      
}
//fonction de l affichage
void affichage(){
int o;
       
for(o=0;o<q;o++){
     printf("les informationsde eleve id:%d",o+1)  ;
     printf("le nom est :%s \n",c[o].nom);
     printf("le prenom est :%s \n",c[o].prenom);
     printf("le date de naissance est :%s \n",c[o].date);
     printf("la departement :%s \n",c[o].departement);
     printf("le nombre total:%.2f\n",c[o].note);
     
}
}
//fonction de calculer la moyene general
void moyenne(){
      int p,a,d,f;
      f=0;
       float s,M;
       char moydepartement[5];
       s=0;
       printf("________________________________________________________________________________________________________\n");
       printf("_____________________________________calculer le moyenne general ________________________________________\n");
       printf("1)la moyenne generale de specifique departement                     2)la moyenne general de l université entiere.\n");
       printf("entre :");
       scanf("%d",&p);
if(p==2){{
            for(a=0;a<q;a++){
              s=s+c[a].note;
            }
            M=s/q;
       printf("le moyenne generale des etudiant dans l universite est :%.0f",M);
       }    
}
else if(p==1){
       printf("entre le nom de  depatement qui vouler:");
       scanf("%s",moydepartement);
       for(d=0;d<q;d++){
       if(strcmp(c[d].departement,moydepartement)==0){
              s=s+c[d].note;
              f++;
       }
       }
       M=s/f;
       printf("le moyenne general dans la departement %s est %.0f",moydepartement,M);

     }
}
int main()
{
       ajout();
       modification();
       affichage();

       return 0;
}
