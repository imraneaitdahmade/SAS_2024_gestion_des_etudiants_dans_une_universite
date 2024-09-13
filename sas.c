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
int q=10;



// Fonction pour initialiser des données d'étudiants
void initialiserDonnees() {
    // Initialisation de quelques étudiants avec des données prédéfinies
    strcpy(c[0].id, "E001");
    strcpy(c[0].nom, "Dupont");
    strcpy(c[0].prenom, "Jean");
    strcpy(c[0].date, "01/01/2000");
    c[0].note = 12.5;
    strcpy(c[0].departement, "MIP");

    strcpy(c[1].id, "E002");
    strcpy(c[1].nom, "Durand");
    strcpy(c[1].prenom, "Marie");
    strcpy(c[1].date, "02/02/2001");
    c[1].note = 15.0;
    strcpy(c[1].departement, "PC");

    strcpy(c[2].id, "E003");
    strcpy(c[2].nom, "Martin");
    strcpy(c[2].prenom, "Pierre");
    strcpy(c[2].date, "03/03/2002");
    c[2].note = 9.0;
    strcpy(c[2].departement, "IN");

    // Mettre à jour le nombre d'étudiants initialisés
    q = 3;
}




// la fonction d ajoute//
void ajout()
{
       int z,v;
       char w;
       // ecrire les donnees de etudiant //
       
       do
       {
              printf("________________________________________________________________________________________________________\n");
              printf("_______________________________________ ajoute de etudiant N :%d ______________________________________\n", q + 1);
              printf("entre le ID d etudiant :");
       
              scanf("%s",c[q].id);
              printf("entre le nom d etudiant :");
              getchar();
              fgets(c[q].nom, 20, stdin);
              
              printf("entre le prenom d etudiant :");
              getchar();
              fgets(c[q].prenom, 20, stdin);
       
              printf("entre la date de naissance  d etudiant :");
              getchar();
              fgets(c[q].date, 20, stdin);
              
              printf("entre votre departement ona 4 dapartement click le numero correspondant click 1(MIP),2(PC),3(IN),4(BIO) :");
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
              printf("entre la note  general :");
              scanf("%f",&c[q].note);
              
              printf("Voulez-vous ajouter un autre etudiant?(y/n) :");
              scanf("%s",&w);
               q++;
       } while (w == 'y');
}
 // fonction modification d un etudiant //
void modification()
{
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
                     case 1:
                     printf("entre le nom:");
                     getchar();
                     fgets(nevnom,20,stdin);
                     strcpy(c[e].nom,nevnom);
                     printf("le modification a execute");
              break;
                     case 2:
                     printf("entre le  prenom:");
                     getchar();
                     fgets(nevprenom,20,stdin);
                     strcpy(c[e].prenom,nevprenom);
                     printf("le modification a execute");
              break;
                     case 5:
                     printf("entre la date de naissance:");
                     getchar();
                     fgets(nevdate,20,stdin);
                     strcpy(c[e].date,nevdate);
                     printf("le modification a execute");
              break;
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
                     break;printf("le modification a execute");

              }
              break;
                     case 4:
                      printf("entre la note :");
                      scanf("%f",&nevnote);
                     c[e].note=nevnote;
                     printf("le modification a execute");
              break;
              }
       }
} 
}
/// fonction de suprimer //
void suprimer() {
    int i, o;
    char y[10];
    char u;

    printf("Veuillez entrer l'identifiant unique : ");
    scanf("%s", y);

    printf("Es-tu sur ? (y/n) : ");
    scanf(" %c", &u); 

    if (u == 'y') {
        for (i = 0; i < q; i++) {
            if (strcmp(y, c[i].id) == 0) {

                for (o = i; o < q - 1; o++) {
                    strcpy(c[o].id, c[o + 1].id);
                    strcpy(c[o].nom, c[o + 1].nom);
                    strcpy(c[o].prenom, c[o + 1].prenom);
                    strcpy(c[o].date, c[o + 1].date);
                    strcpy(c[o].departement, c[o + 1].departement);
                    c[o].note = c[o + 1].note;
                }
                q--;
                break; 
            }
        }

        if (i == q) {
            printf("Cet etudiant n'existe pas.\n");
        } else {
            printf("Les informations de l'etudiant ont ete supprimees.\n");
        }
    } else {
        printf("Aucune suppression effectuee.\n");
    }
}

//fonction de l affichage
void affichage(){
int o;

for(o=0;o<q;o++){
     printf("les informations de eleve  %d",o+1);
     printf("le id est :%s \n",c[o].id);
     printf("le nom est :%s \n",c[o].nom);
     printf("le prenom est :%s \n",c[o].prenom);
     printf("le date de naissance est :%s \n",c[o].date);
     printf("la departement :%s \n",c[o].departement);
     printf("le nombre total:%.2f\n",c[o].note);  
     printf("____________________________________________\n");
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
              printf("%f",c[d].note);
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
       printf("les informationsde eleve id:%s \n",c[l].id);
       printf("le nom est :%s \n",c[k].nom);
       printf("le prenom est :%s \n",c[k].prenom);
       printf("le date de naissance est :%s \n",c[k].date);
       printf("la departement :%s \n",c[k].departement);
       printf("le nombre total:%.2f\n",c[k].note);
       printf("______________________________________________");
              }
}
       break;
       case 2:
       printf("entre le departement :");
       scanf("%s",rechdepartement);
       for(l=0;l<=q;l++){
       if(strcmp(rechdepartement,c[l].departement)==0){
       printf("les eleves de departement %s sont :\n",rechdepartement);
       printf("les informationsde eleve id:%s \n",c[l].id);
       printf("le nom est :%s \n",c[l].nom);
       printf("le prenom est :%s \n",c[l].prenom);
       printf("le date de naissance est :%s \n",c[l].date);
       printf("la departement :%s \n",c[l].departement);
       printf("le nombre total:%.2f\n",c[l].note);
       printf("______________________________________\n");
       }
       }
     }
       printf("________________________________________________________________________________________________________\n");
}
//fonction des statistiques
void statistique(){
      int t,a,y,j;
      float e;
      eleve temp;
int p,m,i,b;p=0;m=0;i=0;b=0;
       printf("________________________________________________________________________________________________________\n");
       printf("_______________________________________ statistiques des informations  ______________________________________\n");
       printf("1)Afficher le nombre total d'etudiants                                                     2)Afficher le nombre d'etudiants dans chaque departement \n");
       printf("3)Afficher les etudiants ayant une moyenne generale superieure à un seuil                  4)Afficher les 3 etudiants ayant les meilleures notes. \n");
       printf("                                 5)Afficher le nombre d'etudiants ayant reussi dans chaque departement \n");
       printf("entre :");
       scanf("%d",&t);
       switch(t){
              case 1:
              printf("le nombre total des etudiants est %d \n",q);
              break;
              case 2:
              for(a=0;a<=q;a++){
                    if(strcmp(c[a].departement,"MIP")==0){
                     m++;
                    }
                     if(strcmp(c[a].departement,"PC")==0){
                     p++;
                    } 
                    if(strcmp(c[a].departement,"IN")==0){
                     i++;
                    }
                     if(strcmp(c[a].departement,"BIO")==0){
                     b++;
                    }
              }
              printf("le nombre des etudiants dans MIP est :%d \n",m);
              printf("le nombre des etudiants dans PC est :%d \n",p);
              printf("le nombre des etudiants dans  IN est :%d \n",i);
              printf("le nombre des etudiants dans BIO est :%d \n",b);
              break;
              case 3:
              printf("entre le seuil");
              scanf("%f",&e);
              for(a=0;a<=q;a++){
              if(c[a].note>=e){
                     printf("%s | %s | %s | %s | %s | %f \n",c[a].id,c[a].nom,c[a].prenom,c[a].date,c[a].departement,c[a].note);
              }
              }
              break;
              case 4:
              for(a=0;a<=q;a++){
                    for(y=0;y<q-a-1;y++){
                     if(c[y].note<c[y+1].note){
                     temp=c[y];
                     c[y]=c[y+1];
                     c[y+1]=temp;
                     }
                    }
              }
               printf("les trois meilleure etudiants sont :\n");
              for(j=0;j<3;j++){
                     printf("%d) %s | %s | %s | %s | %s |%.2f \n",j+1,c[j].id,c[j].nom,c[j].prenom,c[j].date,c[j].departement,c[j].note);                  
              }
              break;
              case 5:
              for(a=0;a<q;a++){
                 if(c[a].note>=10){

                      if(strcmp(c[a].departement,"MIP")==0){
                     m++;
                    }
                     if(strcmp(c[a].departement,"PC")==0){
                     p++;
                    } 
                    if(strcmp(c[a].departement,"IN")==0){
                     i++;
                    }
                     if(strcmp(c[a].departement,"BIO")==0){
                     b++;
                    }
                 }
              }
              printf("le nombre des etudiants dans MIP est :%d \n",m);
              printf("le nombre des etudiants dans PC est :%d \n",p);
              printf("le nombre des etudiants dans  IN est :%d \n",i);
              printf("le nombre des etudiants dans BIO est :%d \n",b);
              break;
       }
}
void tri(){
       int i,j,e,t;
       int a,y;
       eleve temp;
                     printf("________________________________________________________________________________________________________________\n");
                     printf("__________________________________________________________ trier par :  ______________________________________\n");
                     printf("1)Tri alphabetique des etudiants en fonction de leur nom                    2)Tri des etudiants par moyenne generale\n");
                     printf("                                        3)Tri des etudiants selon leur statut de reussite                     \n");
                     printf("entre :");
                     scanf("%d",&t);
                     switch(t){
                            case 1:
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
              printf("%d) %s | %s | %s | %s | %s | \n",e+1,c[e].id,c[e].nom,c[e].prenom,c[e].date,c[e].departement);
       }
       break;
       case 2:
for(a=0;a<=q;a++){
                    for(y=0;y<q-a-1;y++){
                     if(c[y].note<c[y+1].note){
                     temp=c[y];
                     c[y]=c[y+1];
                     c[y+1]=temp;
                     }
                    }
              }
               
              for(j=0;j<q;j++){
                     printf("%d) %s | %s | %s | %s | %s |%.2f \n",j+1,c[j].id,c[j].nom,c[j].prenom,c[j].date,c[j].departement,c[j].note);                  
              }
       break;
       case 3:
       for(a=0;a<=q;a++){
                    for(y=0;y<q-a-1;y++){
                     if(c[y].note<c[y+1].note){
                     temp=c[y];
                     c[y]=c[y+1];
                     c[y+1]=temp;
                     }
                    }
              }
              for(j=0;j<q;j++){
              if(c[j].note>=10){
                     printf("%d) %s | %s | %s | %s | %s |%.2f \n",j+1,c[j].id,c[j].nom,c[j].prenom,c[j].date,c[j].departement,c[j].note); 
              }

              }
       break;
                     }

}
int main()
{
        //declaration des variables local de main1
       int g,h;
  
       initialiserDonnees();

       //menu principal
       menu:
       printf("______________________________________________________________________________________________________________\n");
       printf("--------------------------------------gestion des etudiants dans une universite----------------------------\n");
       printf("   1)ajouter un etudiant                                                        2)modifier les informations \n \n");
       printf("   3)suprimer un etudiant                                                       4)afficher les informations des etudiants \n \n");
       printf("   5)rechercher un etudiant                                                     6)Trier les etudiants \n \n");
       printf("   7)statistiques                                                               8)calculer le moyenne general \n \n");
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
        statistique();
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
