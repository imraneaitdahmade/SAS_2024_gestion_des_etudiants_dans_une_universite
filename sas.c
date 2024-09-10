#include <stdio.h>
#include <string.h>
// structure des donnees d etudiant //
typedef struct
{
       int id;
       char nom[20];
       char prenom[20];
       char date[20];
       float note[100];
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
              printf("entre votre departement :");
              getchar();
              fgets(c[q].departement, 20, stdin);
              // ajoute la note general d etudiant//
              printf("entre la date de naissance  d etudiant :");
              scanf("%f", c[q].note);
              // pour donner le choix a lutilisateur d entre un autre etudiant//
              printf("Voulez-vous ajouter un etudiant?(y/n) :");
              scanf("%c", &w);
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
       char nevnom[20],nevprenom[20],nevdate[20],nevnote,nevdepartement[20];
       printf("Veuillez entrer l identifiant unique:");
       scanf("%d ", &r);
       printf("________________________________________________________________________________________________________\n");
       for (e = 0; e < q; e++)
       {
              if (r == c[e].id)
              {
                     printf("________________________________________________________________________________________________________\n");
                     printf("_______________________________________ modification  etudiant N :%d ______________________________________\n", c[e].id);
                     printf("1)modifier le nom                                                                 2)modifier le prenom \n");
                     printf("3)modifier le departement                                                         4)modifier la note generale \n");
                     printf("                                        5)modifier la date de naissance \n");
                     printf("entre :");
                     scanf("%d",&t);
              switch(t){
                     case 1:
                     printf("entre le neveau nom:");
                     getchar();
                     fgets(nevnom,20,stdin);
                     strcpy(nevnom,c[e].nom);
              break;
                     case 2:
                     printf("entre le neveau prenom:");
                     getchar();
                     fgets(nevprenom,20,stdin);
                     strcpy(nevprenom,c[e].prenom);
              break;
                     case 5:
                     printf("entre le neveau date de naissance:");
                     getchar();
                     fgets(nevdate,20,stdin);
                     strcpy(nevdate,c[e].date);
              break;
                     case 3:
                     printf("entre le neveau departement:");
                     getchar();
                     fgets(nevdepartement,20,stdin);
                     strcpy(nevdepartement,c[e].departement);
              }
             

              }
       }
}

int main()
{
       ajout();
       return 0;
}