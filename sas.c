#include <stdio.h>
#include <string.h>
// structure des donnees d etudiant //
typedef struct
{
       char id[10];
       char nom[20];
       char prenom[20];
       char date[20];
       float note;
       char departement[20];
} eleve;
// declaration des variables global //
eleve c[100];
 const char listdpar[6][6]={"MIP","PC","IN","BIO"};
int q=0;
// la fonction d ajoute//
void ajout()
{
       // declaration des variables local  en fonction d ajoute//
       int z,v;
       char w;
       // ecrire les donnees de etudiant //
       q = 0;
       do
       {
              printf("________________________________________________________________________________________________________\n");
              printf("_______________________________________ ajoute de etudiant N :%d ______________________________________\n", q + 1);
              // ajoute le nom d etudiant //
              printf("entre le ID d etudiant :");
              scanf("%s",c[q].id);
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
              printf("entre votre departement ona 4 dapartement click le numero correspondant [1)MIP,2)PC,3)IN,4)BIO] :");
              scanf("%d",&z);
              switch(z){
                     case 1:
                     strcpy(c[q].departement,listdpar[0]);
                     break;
                      case 2:
                     strcpy(c[q].departement,listdpar[1]);
                     break;
                      case 3:
                     strcpy(c[q].departement,listdpar[2]);
                     break;
                      case 4:
                     strcpy(c[q].departement,listdpar[3]);
                     break;
              }
              // ajoute la note general d etudiant//
              printf("entre la note  general :");
              scanf("%f",&c[q].note);
              // pour donner le choix a lutilisateur d entre un autre etudiant//
              printf("Voulez-vous ajouter un autre etudiant?(y/n) :");
              scanf("%s",&w);
               q++;
       } while (w == 'y');
       // finir la fonction d ajoute//
}
 // fonction modification d un etudiant //
void modification()
{
       // declarer les variables global//
       int e,t,x;
       char r[10];
       char nevnom[20],nevprenom[20],nevdate[20];
       float nevnote;
       printf("Veuillez entrer l identifiant unique:");
       scanf("%s",r);
       printf("________________________________________________________________________________________________________\n");
       for (e = 0; e < q; e++)
       {
              if (strcmp(r,c[e].id)==0)
              {
//menu de modification des informations d etudiant
                     printf("________________________________________________________________________________________________________\n");
                     printf("_______________________________________ modification  des informations ______________________________________\n");
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
                     strcpy(c[e].nom,nevnom);
              break;
//modification de prenom//
                     case 2:
                     printf("entre le  prenom:");
                     getchar();
                     fgets(nevprenom,20,stdin);
                     strcpy(c[e].prenom,nevprenom);
              break;
//modification de date de naissance//
                     case 5:
                     printf("entre la date de naissance:");
                     getchar();
                     fgets(nevdate,20,stdin);
                     strcpy(c[e].date,nevdate);
              break;
// modification de la departement
                     case 3:
                     printf("entre votre departement ona 4 dapartement click le numero correspondant [1)MIP,2)PC,3)IN,4)BIO]:");
                     scanf("%d",&x);
                     switch(x){
                     case 1:
                     strcpy(c[e].departement,listdpar[0]);
                     break;
                      case 2:
                     strcpy(c[e].departement,listdpar[1]);
                     break;
                      case 3:
                     strcpy(c[e].departement,listdpar[2]);
                     break;
                      case 4:
                     strcpy(c[e].departement,listdpar[3]);
                     break;
              }
              break;
//modification de note general//
                     case 4:
                      printf("entre la note :");
                      scanf("%f",&nevnote);
                     c[e].note=nevnote;
              break;
              }
       }
} 
}
/// fonction de suprimer //
void suprimer(){
 // declaration des variables local de fonction suprimer//
       int i,o;
       char y[10];
       char u;
//demande a l utilisateur de entre l identifiant unique//
       printf("Veuillez entrer l identifiant unique:");
       scanf("%s",y);
       printf("Es-tu sur?(y/n):");
       scanf("%s",&u);
       if(u=='y'){
       for(i=0;i<=q;i++){
              if(strcmp(c[i].id,y)==0){
                     for(o=i;o<q-1;o++){
                     strcpy(c[o].id,c[o+1].id);
                     strcpy(c[o].nom,c[o+1].nom);
                     strcpy(c[o].prenom,c[o+1].prenom);
                     strcpy(c[o].date,c[o+1].date);
                     strcpy(c[o].departement,c[o+1].departement);
                     c[o].note=c[o+1].note;
                     }  
                     q--;
              }
       }
       printf("Les informations d etudiant  ont ete supprimees . \n");
       } 
       else 
       printf("ce etudiant n existe pas.");     
}
//fonction de l affichage
void affichage(){
int o;

for(o=0;o<q;o++){
     printf("les informationsde eleve id:%s \n",c[o].id);
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
       printf("le moyenne generale des etudiant dans l universite est :%.0f \n",M);
        printf("________________________________________________________________________________________________________\n");
       }    
}
else if(p==1){
       printf("entre le nom de  depatement qui vouler:");
       scanf("%s",moydepartement);
       for(d=0;d<q;d++){
       if(strcmp(c[d].departement,moydepartement)==0){
              s=s+c[d].note;
              f++;
              printf("%d",c[d].note);
       }
       }
       M=s/f;
       printf("le moyenne general dans la departement %s est %.0f \n",moydepartement,M);
         printf("________________________________________________________________________________________________________\n");
     }
}
//fonction de recherche //
void recherche(){
     //declaration des variables local de fonction recherche //
     int j,k,l;
     char rechname[20],rechdepartement[20] ;
     //menu de recherche//
     printf("_____________________________________________________________________________________________________________________________________________\n");
     printf("--------------------------------------------------rechercher---------------------------------------------------------------------------------\n");
     printf("   1)recherche  un etudiant par son nom                         2)Afficher la liste des etudiants  inscrits dans un departement specifique\n \n");
     printf("______________________________________________________________________________________________________________________________________________\n");
     printf("entre :");
     scanf("%d",&j);
     switch(j){
       case 1:
       printf("entre le nom d etudiant :");
       getchar();
       fgets(rechname, 20, stdin);
       for(k=0;k<q;k++){
              if(strcmp(rechname,c[k].nom)==0){
       printf("les informationsde eleve id:%d \n",k+1)  ;
       printf("le nom est :%s \n",c[k].nom);
       printf("le prenom est :%s \n",c[k].prenom);
       printf("le date de naissance est :%s \n",c[k].date);
       printf("la departement :%s \n",c[k].departement);
       printf("le nombre total:%.2f\n",c[k].note);
              }
}
       break;
       case 2:
       printf("entre le departement :");
       scanf("%s",rechdepartement);
       for(l=0;l<=q;l++){
       if(strcmp(rechdepartement,c[l].departement)==0){
       printf("les eleves de departement %s sont :\n",rechdepartement);
       printf("les informationsde eleve id:%d \n",l+1)  ;
       printf("le nom est :%s \n",c[l].nom);
       printf("le prenom est :%s \n",c[l].prenom);
       printf("le date de naissance est :%s \n",c[l].date);
       printf("la departement :%s \n",c[l].departement);
       printf("le nombre total:%.2f\n",c[l].note);
       }
       }
       break;
     }
       printf("________________________________________________________________________________________________________\n");
}
//fonction des statistiques
void statistique(){
      int t;
       printf("________________________________________________________________________________________________________\n");
                     printf("_______________________________________ statistiques des informations  ______________________________________\n");
                     printf("1)modif                                                                 2)modifier le prenom \n");
                     printf("3)modifier le departement                                                         4)modifier la note generale \n");
                     printf("                                        5)modifier la date de naissance \n");
                     printf("entre :");
                     scanf("%d",&t);
}
void tri(){
       int i,j,e;
       eleve temp;
       
       for(i=0;i<q;i++){
              for(j=0;j<q-i-1;j++){
                     if(strcmp(c[j].nom,c[j+1].nom)>0){
                       temp=c[j];
                       c[j]=c[j+1];
                       c[j+1]=temp;
                     }
              }
       }
       for(e=0;e<q;e++){
              printf("%s",c[e].nom);
       }

}
int main()
{
        //declaration des variables local de main1
       int g,h;
       
       //menu principal//
       menu:
       printf("______________________________________________________________________________________________________________\n");
       printf("--------------------------------------gestion des etudiants dans une universite----------------------------\n");
       printf("   1)ajouter un etudiant                                                        2)modifier les informations \n \n");
       printf("   3)suprimer un etudiant                                                       4)afficher les informations des etudiants \n \n");
       printf("   5)rechercher un etudiant                                                     6)Trier les etudiants \n \n");
       printf("   7)statistiques                                                                8)calculer le moyenne general \n \n");
       printf("______________________________________________________________________________________________________________\n");
       printf("entre :");
       scanf("%d",&g);
       switch(g){
        case 1:
        ajout();
          printf("click 1 pour retourne au menu \n click 2 pour finir le programme\n ");
        printf("entre :");
        scanf("%d",&h);
        if(h==1)
        goto menu;
        else
        break;
        case 2:
        modification();
          printf("click 1 pour retourne au menu \n click 2 pour finir le programme\n ");
        printf("entre :");
        scanf("%d",&h);
        if(h==1)
        goto menu;
        else
        break;
        case 3:
        suprimer();
          printf("click 1 pour retourne au menu \n click 2 pour finir le programme\n ");
        printf("entre :");
        scanf("%d",&h);
        if(h==1)
        goto menu;
        else
        break;
        case 4:
        affichage();
          printf("click 1 pour retourne au menu \n click 2 pour finir le programme\n ");
        printf("entre :");
        scanf("%d",&h);
        if(h==1)
        goto menu;
        else
        break;
        case 5:
        recherche();
          printf("click 1 pour retourne au menu \n click 2 pour finir le programme\n ");
        printf("entre :");
        scanf("%d",&h);
        if(h==1)
        goto menu;
        else
        break;
        case 6:
        tri();
          printf("click 1 pour retourne au menu \n click 2 pour finir le programme\n ");
        printf("entre :");
        scanf("%d",&h);
        if(h==1)
        goto menu;
        else
        break;
        case 7:
        printf("click 1 pour retourne au menu \n click 2 pour finir le programme\n ");
        printf("entre :");
        scanf("%d",&h);
        if(h==1)
        goto menu;
        else
        break;
        case 8:
        moyenne();
        printf("click 1 pour retourne au menu \n click 2 pour finir le programme\n ");
        printf("entre :");
        scanf("%d",&h);
        if(h==1)
        goto menu;
        else
        break;
       }
       return 0;
}
