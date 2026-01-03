#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define minN 10
#define minM 10


void printStarwars(int N, int M, char **starwars);
void printFake(int N, int M, char **starwars, int *lx, int *ly);
void entolh_kinhshs(int *lx,int *ly,int M,int N, char **starwars, char *nikh, char *htta, int *life, char *telos);
void Vader(int *lx, int *ly, int *Vx, int *Vy, int M, int N, char **starwars, char *htta);


int main(void)
{
    srand(time(NULL));
    char **starwars,kinhsh,*nikh,win,*htta,defeat,*telos,end;
    char ch,characters[]={'R', 'D', 'L' ,'#'};
    int i,j,N,M,z,x,y,gwnia,level=1,new_N,new_M,min,*lx,*ly,leiaX,leiaY,*Vx,*Vy,VaderX,VaderY, **trooper_pos,trooper_counter=0;
    int darthVaderAppeared,*life,zwh,flagN=0,flagM=0,flagNM=0, counter=0;
    double stormtroopers, empodia;

    lx=&leiaX;
    ly=&leiaY;
    Vx=&VaderX;
    Vy=&VaderY;
    nikh=&win;
    htta=&defeat;
    life=&zwh;
    telos=&end;
    *nikh='n';
    *htta='n';
    *telos='n';

    do    //Rwtaw ton xrhsth ama thelei na paixei
     {
       printf("\nAuto to paixnidi einai gia tous latreis tou Star Wars!!!");
       printf("\nThes na paixeis,y/n?\n");
       ch=getchar();
       while(getchar()!='\n');   //Otan o xrhsths grafei enter den tha emfanizei tipota
      }while ((ch!='y') && (ch!='n'));

    if(ch=='y')
    {
        do
         {          
           printf("Dwse to ligotero arithmo grammwn:");  //Diabazei oti eisagei o xrhsths
           scanf("\n%d", &N); 
           printf("Dwse ton ligotero arithmo stylwn:");  //Diabazei oti eisagei o xrhsths
           scanf("\n%d", &M);
           while(getchar()!='\n');
         }while(N<=minN && M<=minM);

        do    //O xrhsths epilegei epipedo dyskolias
         {
           printf("\nDialeje epipedo dyskolias: ");
           printf("\nEukolo: e");
           printf("\nMetrio: m");
           printf("\nDyskolo: d");
           printf("\nAkatorthwto: a\n");
           ch=getchar();
         }while(ch!='e' && ch!='m' && ch!='d' && ch!='a');
        
        if(N>=minN && M>=minM) //Paizeis ean o arithmos sthlwn pou deinei o xrhsths einai megalyteros apo ton elaxisto arithmo sthlwn kai antistoixa twn grammwn 
        {
          //Meiwsh diastasewn tou pinaka se kathe epomenh pista
	        level=0;
	        while (*htta!='X' && *telos!='X' && (flagNM!=1))
          {
	          *life=2;
            starwars=(char**)malloc(N*sizeof(char*));  //Dhmiourgia N grammwn
	         for (i=0; i<N; i++)
	         {
		         starwars[i]=(char*)malloc(M*sizeof(char)); //Dhmiourgia M stylwn
	         }

	          for (i=0; i<N; i++)
	          {
		         for (j=0; j<M; j++)
		         {
			         starwars[i][j]='#';
		         }
            }

              //Bazoyme ton Darth Vader ston pinaka se mia apo tis 4 gwnies
              gwnia=rand()%4;
             
              if(gwnia==0) //Epanw aristerh gwnia
              {
                *Vx=0;
                *Vy=0;
              }
              else if(gwnia==1) //Epanw dejia gwnia
              {
                *Vx=0;
                *Vy=M-1;
              }
              else if(gwnia==2) //Katw aristerh gwnia
              {
                *Vx=N-1;
                *Vy=0;
              }
              else if(gwnia==3) //Katw dejia gwnia
              {
                *Vx=N-1;
                *Vy=M-1;
              }

            starwars[*Vx][*Vy]=characters[1]; 
          
            //Bazoyme thn Leia kai ton R2D2 ston pinaka
            char characters[]={'R', 'D', 'L'};
            for (i=0; i<3; i++)  //3 einai o arithmos twn xarakthrwn poy theloume na topothethsoume ston pinaka
	          {
             if(i!=1)   //Ejasfalizw na mhn jana emfanistei o Darth Vader
             {
              do
               {
                 x=rand()%(N-1);
                 y=rand()%(M-1);
               } while(starwars[x][y]!='#'); //Elegxw an h thesh einai kenh
               starwars[x][y]=characters[i];
		           if (characters[i]=='L')
		          {
			          *lx=x;
			          *ly=y;
		          }
             }
            }
          	
            if (starwars==NULL)   //Ginetai elegxos ths malloc
            {
				      printf("Den uparxei ekxwrhsh mnhmhs, kati phge lathos!\n");
				      exit(0);
            }

           if(ch=='e')
           {
             stormtroopers=(int)(N*M)*0.02;
             empodia=(int)(N*M)*0.13;
           }
           else if (ch=='m')
           {
             stormtroopers=(int)(N*M)*0.05;
             empodia=(int)(N*M)*0.10;
           }
           else if(ch=='d')
           {
             stormtroopers=(int)(N*M)*0.10;
             empodia=(int)(N*M)*0.05;
           }
           else if (ch=='a')
           {
             stormtroopers=(int)(N*M)*0.15;
             empodia=(int)(N*M)*0;
           }

           //Stroggulopoihsh
           if(stormtroopers<2)  
           {
             stormtroopers=2;
           }
           if(empodia<0)
           {
             empodia=0;
           }
	        trooper_pos = (int**)malloc(stormtroopers*sizeof(int*)); //Dhmiourgoume dynamiko pinaka analoga ton arithmo twn stormtroopers
	        for (i=0; i<stormtroopers; i++)
	        {
		       trooper_pos[i]=(int*)malloc(3*sizeof(int));
	        }

	         //Topothethsh empodiwn kai stormstroopers sto pinaka
           for (z=0; z<empodia+stormtroopers; z++)
           {
            do
            {
              x=rand()%N;
              y=rand()%M;
            } while (starwars[x][y]!='#' || (x==*lx+1 && y==*ly) || (x==*lx-1 && y==*ly) || (y==*ly-1 && x==*lx) || (y==*ly+1 && x==*lx));  //Elegxoume an h thesh einai kenh kai oti den tha mpei otidhpote, gyrw apo thn Leia
            if (z<empodia)
            {
              starwars[x][y]='X';  //Topothetoume ta empodia
            } 
            else
            {
              starwars[x][y]='@';  //Topothetoume tous stormtroopers
	            trooper_pos[trooper_counter][0]=x; //Diathroume tis syntetagmenes tou kathe stormtrooper entos tou pinaka trooper_pos
	            trooper_pos[trooper_counter][1]=y;
	            trooper_pos[trooper_counter][2]=rand()%2; //Dialegoume kai enan random arithmo 0-1 gia na orisoume kateuthunsh kinhshs me 0:Vertical, 1:Horizontal
	           if (trooper_counter<stormtroopers)
	           {
	      	    trooper_counter++;
	           }
            }
           }
	         trooper_counter=0;

           if(i!=1) //Ejasfalizw na mhn jana emfanistei o Darth Vader
           {  
            if (darthVaderAppeared==0) 
            {
              darthVaderAppeared=1; //Ejasfalizw na mhn emfanistei panw apo dyo fores o Darth Vader kata th meiwsh tou tamplo
            }
           }
            empodia=(int)(N*M*empodia);
            stormtroopers=(int)(N*M*stormtroopers);
         
            //Emfanish pistas
            printf("Level %d:\n", level);
            printf("\n\n                  To paixnidi jekina!!!\n\n");
	          level++;

            //Entoles tou paixnidiou
            counter=0;
            do
            {
              //Entolh kinhshs
		          printFake(N, M, starwars, lx, ly);
              entolh_kinhshs(lx,ly,M,N,starwars,nikh,htta,life,telos);
		          counter++;
		          if (counter==2)
		          {
			          Vader(lx,ly,Vx,Vy,M,N,starwars,htta);
			          counter=0;
		          }
            } while(((*nikh!='X') && (*htta!='X') && (*telos!='X')));

           //Meiwnontai oi diastaseis gia tis epomenes pistes
	         if (N>minN)
	         {
             N--;
	         } 
           else
	         {
		         flagN=1;
	         }

	        if (M>minM)
	        {
            M--;
	        } 
          else
	        {
		        flagM=1;
	        }
	        if (flagN==1 && flagM==1)
	        {
		        flagNM=1; //Oi flag xreiazontai gia na enhmerwsoume thn arxikh while prokeimenou na teleiwsei to paixnidi se periptwsh telikhs nikhs tou paixth
	        }
	        //Ananaiwnoume tis metablhtes nikhs wste o paixths na mporei na paiksei pali gia panw apo mia entolh
	        *nikh='n';
        }
        if (*htta!='X' && *telos!='X')
        {
	        printf("SYGXARHTHRIA NIKHSES, H ANTISTASH PROKEITAI TWRA NA LABEI TA METRA THS! :D\n");
	        printf("Arkei na einai ejoplismenoi kai me enan arketa kalo piloto gia na epitethei sto Darth Vader... :3\n");
        }
      }
    }
  printf("\n\nBye Bye!\n");
 for(i=0; i<stormtroopers; i++)
 {
   free(trooper_pos[i]);
 }
 free(trooper_pos);
 for(i=0; i<N; i++)
 {
   free(starwars[i]);
 } 
 free(starwars);
 return 0;
}
/**************SYNARTHSEIS****************/
//Oloklhrwmenos pinakas
void printStarwars(int N, int M, char **starwars)
{
  int i, j;
  char alphabet[26]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  printf("   ");    //Afhnei keno mprosta apo to A
  for (i=0; i<M; i++)
  {
    if (i < 26)
    {
      printf("%2c ", alphabet[i]); //Prostithontai kena stoixeia gia eythugrammish
    }
    else
    {
      printf("%2c ", 'A' + (i-26));
    }
  }
  printf("\n");

  printf("   ");    //Afhnei keno mprosta apo to A
  for (i=0; i<M; i++)
  {
    printf("---");
  }
  printf("\n");

  for (i=0; i<N; i++)
  {
    printf("%2d|", i+1); //Prostithontai kena stoixeia gia eythugrammish
    for (j=0; j<M; j++)
    {
      printf(" %c ", starwars[i][j]); //Prostithontai kena stoixeia gia eythugrammish
    }
    printf("\n");
  }
}

//Fog of war pinakas
void printFake(int N, int M, char **starwars, int *lx, int *ly)
{
  int i, j;
  char alphabet[26]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  printf("   ");    //Afhnei keno mprosta apo to A
  for (i=0; i<M; i++)
  {
    if (i < 26)
    {
      printf("%2c ", alphabet[i]); //Prostithontai kena stoixeia gia eythugrammish
    }
    else
    {
      printf("%2c ", 'A' + (i-26));
    }
  }
  printf("\n");

  printf("   ");    //Afhnei keno mprosta apo to A
  for (i=0; i<M; i++)
  {
    printf("---");
  }
  printf("\n");

  for (i=0; i<N; i++)
  {
    printf("%2d|", i+1); //Prostithontai kena stoixeia gia eythugrammish
    for (j=0; j<M; j++)
    {
	    if (*lx!=i && *ly!=j && (starwars[i][j]!='R' && starwars[i][j]!='@')) //Elegxoume an to shmeio den einai o R2D2 h Stormtrooper prokeimenou na to ektypwsoume kanonika (empodio, patwma, Vader)
	    {
        printf(" %c ", starwars[i][j]); //Prostithontai kena stoixeia gia eythugrammish
	    } 
      else if ((*lx==i || *ly==j) && starwars[i][j]=='#') //Elegxoume an to shmeio einai katheto h orizontio me thn Leia prokeimenou na to metatrepsoume se "." sthn ektypwsh
	    {
		    printf(" . "); // Prosthetei kena gia eythygrammish
	    } 
      else if ((*lx==i || *ly==j) && (starwars[i][j]!='#'))
	    {
		    printf(" %c ", starwars[i][j]);
	    } 
      else 
	    {
		    printf(" # ");
	    }
    }
    printf("\n");
  }
}

//Entoles kinhshs
void entolh_kinhshs(int *lx,int *ly,int M,int N,char **starwars,char *nikh, char *htta, int *life, char *telos)
{
  char kinhsh;
  printf("Oi entoles einai: U/u(Epanw), D/d(Katw), L/l(Aristera), R/r(Dejia), H/h(Bohtheia), X/x(Telos paixnidiou) \n ");
  printf("\nDwse entolh:\n ");
  scanf(" %c", &kinhsh);
  system("clear"); //Emfanizetai enas pinakas gia kathe leitourgia
  printf("\nH entolh kinhshs einai: %c\n",kinhsh);

  if((kinhsh=='U') || (kinhsh=='u'))
  {
    //PANW: (lx-1,ly)
    //KATW: (lx+1, ly)
    //DEKSIA: (lx, ly+1)
    //ARISTERA: (lx,ly-1)
    //Stis periptwseis opou den prepei na ginei kinhsh, o xrhsths tha prepei na ksanaerwththei apo to programma gia nea kinhsh, sthn dikh mas periptwsh apla skipparei mia fora thn seira tou meta apo katallhlo mhnyma
    //En oligis, ta lathoi exoun sobares synepeies kathws o xrhsths xanei mia seira sta bots..
    if ((*lx-1)<0) //tsekaroume an h mellontikh thesh ths Leia tha einai entos pinaka xrhsimopoiontas thn twrinh ths thesh sto y kathws gia na paei panw, h nea syntetagmenh tha einai (x,y-1)
    {
	   printf("Adunath kinhsh, prospathhse jana: \n");
    } 
    else if (starwars[*lx-1][*ly]=='X') //Tsekaroume an h mellontikh thesh ths Leia einai empodio kai enhmerwnoume ton xrhsth analoga
    {
      printf("Epeses panw se empodio, prospathise jana: \n");
    } 
    else if (starwars[*lx-1][*ly]=='@')
    {
      printf("Epeses panw se exthro, sou menei mono mia zwh: \n");
	    *life=*life-1;
	    if (life>0)
      {
		    printf("Bghkes nikiths an kai plhgwmenos, h zwh pou sou apomenei einai: %d\n",*life);
		    starwars[*lx-1][*ly]=starwars[*lx][*ly];
		    starwars[*lx][*ly]='#';
		    *lx=*lx-1;
	    } 
      else
	    {
		    printf("Piasthkes apo enan stormtrooper,h zwh pou sou apomenei einai : 0\n");
		    *htta='X'; //Teleiwne to paixnidi kai o paixths xanei
	    }
    } 
    else if (starwars[*lx-1][*ly]=='D')
    {
	    printf("Piasthkes apo ton Darth Vader, exases...\n");
	    *htta='X';
    } 
    else if (starwars[*lx-1][*ly]=='#') //Auto prepei na allaksei se # epeidh kanonika den tha eprepe na allazei to value to starwars se . alla na einai apla ena visual print
    {
	    starwars[*lx-1][*ly]=starwars[*lx][*ly];
	    starwars[*lx][*ly]='#';
      *lx=*lx-1;
    } 
    else if (starwars[*lx-1][*ly]=='R')
    {
	    printf("BRHKES TON R2D2! NIKHSES AYTO TO LEVEL!\n");
      *nikh='X';
    }
  }
  else if((kinhsh=='D') || (kinhsh=='d'))
  {
    if((*lx+1)>N)   //Elegxw ean brisketai sto katw orio tou tamplo
    {
      printf("Adunath kinhsh, prospathise jana: \n");
    } 
    else if (starwars[*lx+1][*ly]=='X') //Tsekaroume an h mellontikh thesh ths Leia einai empodio kai enhmerwnoume ton xrhsth analoga
    {
	    printf("Epeses panw se empodio, prospathise jana: \n");
    } 
    else if (starwars[*lx+1][*ly]=='@')
    {
	    printf("Epeses epanw se exthro, enas bathmos zwhs exei meiwthei: \n");
	    *life=*life-1;
	    if (life>0)
	    {
		    printf("Bghkes nikhths an kai plhgwmenos, h zwh pou sou apomenei einai: %d\n",*life);
		    starwars[*lx+1][*ly]=starwars[*lx][*ly];
		    starwars[*lx][*ly]='#';
		    *lx=*lx-1;
	    } 
      else
	    {
		    printf("Piasthkes apo enan stormtrooper, h zwh pou sou apomenei einai: 0\n");
		    *htta='X'; //Teleiwnei to paixnidi kai o paixths xanei
	    }
    } 
    else if (starwars[*lx+1][*ly]=='D')
    {
	    printf("Piasthkes apo ton Darth Vader, exases...\n");
	    *htta='X';
    } 
    else if (starwars[*lx+1][*ly]=='#')
    {
	    starwars[*lx+1][*ly]=starwars[*lx][*ly];
	    starwars[*lx][*ly]='#';
	    *lx=*lx+1;
    } 
    else if (starwars[*lx+1][*ly]=='R')
    {
	    printf("BRHKES TON R2D2! NIKHSES AYTO TO LEVEL!\n");
	    *nikh='X';
    }
  }
  else if((kinhsh=='L') || (kinhsh=='l'))
  {
    if ((*ly-1)<0) //Tsekaroume an h mellontikh thesh ths Leia tha einai entos pinaka xrhsimopoiontas thn twrinh ths thesh sto y kathws gia na paei panw, h nea syntetagmenh tha einai (x,y-1)
    {
	    printf("Adunath kinhsh, prospathise jana: \n");
    } 
    else if (starwars[*lx][*ly-1]=='X') //Tsekaroume an h mellontikh thesh ths Leia einai empodio kai enhmerwnoume ton xrhsth analoga
    {
      printf("Epeses epanw se empodio, prospathise jana: \n");
    } 
    else if (starwars[*lx][*ly-1]=='@')
    {
      printf("Epeses epanw se exthro, enas pontos zwhs enas bathmos zwhs exei meiwthei: \n");
	    *life=*life-1;
	    if (life>0)
      {
		    printf("Bghkes nikhths an kai plhgwmenos, h zwh pou sou apomenei einai: %d\n",*life);
		    starwars[*lx][*ly-1]=starwars[*lx][*ly];
		    starwars[*lx][*ly]='#';
		    *ly=*ly-1;
	    } 
      else
	    {
		    printf("Piasthkes apo enan stormtrooper, h zwh pou sou apomenei einai: 0\n");
		    *htta='X'; //Teleiwne to paixnidi kai o paixths xanei
	    }
    } 
    else if (starwars[*lx][*ly-1]=='D')
    {
	    printf("Piasthkes apo ton Darth Vader, exases...\n");
	    *htta='X';
    } 
    else if (starwars[*lx][*ly-1]=='#') //Auto prepei na allaksei se # epeidh kanonika den tha eprepe na allazei to value to starwars se . alla na einai apla ena visual print
    {
	    starwars[*lx][*ly-1]=starwars[*lx][*ly];
	    starwars[*lx][*ly]='#';
      *ly=*ly-1;
    } 
    else if (starwars[*lx][*ly-1]=='R')
    {
	    printf("BRHKES TON R2D2! NIKHSES AYTO TO LEVEL!\n");
      *nikh='X';
    }
  }
  else if((kinhsh=='R') || (kinhsh=='r'))
  {
    if ((*ly+1)>M) //Tsekaroume an h mellontikh thesh ths Leia tha einai entos pinaka xrhsimopoiontas thn twrinh ths thesh sto y kathws gia na paei panw, h nea syntetagmenh tha einai (x,y-1)
    {
	    printf("ly+1=%d\n",*ly+1);
	    printf("N=%d\n",N);
	    printf("Adunath kinhsh, prospathise jana: \n");
    } 
    else if (starwars[*lx][*ly+1]=='X') //Tsekaroume an h mellontikh thesh ths Leia einai empodio kai enhmerwnoume ton xrhsth analoga
    {
      printf("Epeses epanw se empodio, prospathise jana: \n");
    } 
    else if (starwars[*lx][*ly+1]=='@')
    {
      printf("Epeses epanw se exthro, enas bathmos zwhs meiwthike: \n");
	    *life=*life-1;
	   if (life>0)
     {
		   printf("Bghkes nikhths an kai plhgwmenos, h zwh pou sou apomenei einai: %d\n",*life);
		   starwars[*lx][*ly+1]=starwars[*lx][*ly];
		   starwars[*lx][*ly]='#';
		   *ly=*ly+1;
	   } 
     else
	   {
		   printf("Piasthkes apo enan stormtrooper, h zwh pou sou apomenei einai: 0\n");
		   *htta='X'; //Teleiwne to paixnidi kai o paixths xanei
	   }
    } 
    else if (starwars[*lx][*ly+1]=='D')
    {
	    printf("Piasthkes apo ton Darth Vader, exases...\n");
	    *htta='X';
    } 
    else if (starwars[*lx][*ly+1]=='#') //Auto prepei na allaksei se # epeidh kanonika den tha eprepe na allazei to value to starwars se . alla na einai apla ena visual print
    {
	    starwars[*lx][*ly+1]=starwars[*lx][*ly];
	    starwars[*lx][*ly]='#';
      *ly=*ly+1;
    } 
    else if (starwars[*lx][*ly+1]=='R')
    {
	    printf("BRHKES TON R2D2! NIKHSES AYTO TO LEVEL!\n");
      *nikh='X';
    }
  }
  else if ((kinhsh=='H') || (kinhsh=='h')) //An o xrhsths dialeksei an zhthsei bohtheia
  {
    printf("Oloklhros o pinakas tha emfanistei ejaitias ths dynmhs ths Leia: \n");
    printStarwars(N,M,starwars);
  }
  else if ((kinhsh=='X') || (kinhsh=='x'))
  {
    *telos='X';
  }
  else
  {
    printf("Mh egkyrh kinhsh, prospathise jana: \n");
  }
}

void Vader(int *lx, int *ly, int *Vx, int *Vy, int M, int N, char **starwars, char *htta)
{
	int x_deficit, y_deficit,viable_paths[9][2],i,j,z,overall_deficit[9],posX,posY,max_efficiency,counter;
	char scan[3][3];
	//POSITIVE x_deficit shmainei oti o Darth Vader einai katw apo th Leia
	//NEGATIVE x_deficit shmainei oti o Darth Vader einai panw apo th Leia
	//POSITIVE y_deficit shmainei oti o Darth Vader einai dejia apo th Leia
	//NEGATIVE y_deficit shmainei oti o Darth Vader einai aristera apo th Leia
	//Symfwna me th plhroforia apofasizoume pou tha einai o Darth Vader kai poia yha einai h epomenh kinhsh tou
	for (i=0; i<3; i++) //Ftiaxnw ena pinaka gyrw apo ton Vader pou epishmainei empodia symperilambanomenwn twn ejairesewn pou den symperilambanontai
	{
		for (j=0; j<3; j++)
		{
			if (((*Vx-1)+i)>=0 && ((*Vx-1)+i)<N && ((*Vy-1)+j)>=0 && ((*Vy-1)+j)<M)
			{
				if (starwars[((*Vx-1)+i)][((*Vy-1)+j)]!='@' && starwars[((*Vx-1)+i)][((*Vy-1)+j)]!='R' && starwars[((*Vx-1)+i)][((*Vy-1)+j)]!='X') 
				{
					scan[i][j]=starwars[((*Vx-1)+i)][((*Vy-1)+j)];
				} 
        else
				{
					scan[i][j]='X';
				}
			} 
      else
			{
				scan[i][j]='X';
			}
		}
	}
	z=0;
	for (i=0; i<3; i++) //Brhskw ola ta diathesima monopatia pou tha akolouthisei o Darth Vader kai ta apothikeuw se pinaka 
	{
		for (j=0; j<3; j++)
		{
			if (scan[i][j]=='#' || scan[i][j]=='L')
			{
				viable_paths[z][0]=i;
				viable_paths[z][1]=j;
				z++;
			}
		}
	}
	for (i=0; i<z; i++) //Tropopoiw ton pinaka diathesimwn monopatiwn wste na ginetai o Dart Vader (1,1) to epikentro (0.0)
	{
		viable_paths[i][0]=viable_paths[i][0]-1;
		viable_paths[i][1]=viable_paths[i][1]-1;
	}
	if (z==1)
	{
		if (starwars[((*Vx)+viable_paths[1][0])][((*Vy)+viable_paths[1][1])]!='L')
		{
			starwars[((*Vx-1)+viable_paths[1][0])][((*Vy+1)+viable_paths[1][1])]=starwars[*Vx][*Vy];
			starwars[*Vx][*Vy]='#';
			*Vx=((*Vx-1)+viable_paths[1][0]);
			*Vy=((*Vy+1)+viable_paths[1][1]);
		} 
    else
		{
			printf("Piasthkes apo ton Darth Vader kai exases: \n");
			*htta='X';
		}
	} 
  else
	{
		for (i=0; i<z; i++)
		{
			x_deficit=((*Vx)+viable_paths[i][0]) - *lx;
			y_deficit=((*Vy)+viable_paths[i][1]) - *ly;
			if (x_deficit<0)
			{
				x_deficit=x_deficit * (-1);
			}
			if (y_deficit<0)
			{
				y_deficit=y_deficit * (-1);
			}
			overall_deficit[i]=x_deficit + y_deficit;
			if (i==0)
			{
				max_efficiency=overall_deficit[0];
				posX=viable_paths[0][0];
				posY=viable_paths[0][1];
			} 
      else if (overall_deficit[i]<max_efficiency)
			{
				max_efficiency=overall_deficit[i];
				posX=viable_paths[i][0];
				posY=viable_paths[i][1];
			}
		}
		if (starwars[((*Vx)+posX)][((*Vy)+posY)]!='L')
		{
			starwars[((*Vx)+posX)][((*Vy)+posY)]=starwars[*Vx][*Vy];
      starwars[*Vx][*Vy]='#';
      *Vx=((*Vx)+posX);
      *Vy=((*Vy)+posY);
		} 
    else
		{
			printf("Piasthkes apo ton Darth Vader kai exases: \n");
			*htta='X';
		}
	}
}