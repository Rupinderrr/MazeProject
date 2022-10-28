#include<stdio.h>
int maxRow,maxColumns;
int charx=1,chary=1;
void printMap(int map[maxRow][maxColumns],int charx,int chary);
void updateMap(int map[maxRow][maxColumns],char choice);



void printMap(int map[maxRow][maxColumns],int charx,int chary){
    char start = 'c';
    char endsymbol = 'E';
    int rows,columns;
              for(rows=0;rows<maxRow;rows++){
    for(columns=0;columns<maxColumns;columns++){

            if (map[rows][columns]==1){
                printf("|");
            }
            else if (map[rows][columns]==2){
            printf("%c",endsymbol);
            }
            else if (charx==rows&&chary==columns){
                printf("%c",start);
            }
            else
            printf(" ");
    }
    printf("\n");
}
}
void updateMap(int map[maxRow][maxColumns],char choice){
if (choice=='w'){
    if(charx>=0 && map[charx][chary]!=1){
        charx--;
    }
  }
  if (choice=='a'){
    if(chary>=0 && map[charx][chary-1]!=1){
        chary--;
    }
  }
  if (choice=='s'){
    if(charx+1<=maxRow && map[charx+1][chary]!=1){
        charx++;
    }
  }
  if (choice=='d'){
    if(chary+1>=0 && map[charx][chary+1]!=1){
        chary++;
    }
  }
}

int main (){
{
FILE *input;
input = fopen("mapData.txt","r");
int rows,columns;
int done=0;
char choice;
fscanf(input,"%d %d",&maxRow,&maxColumns);
int map[maxRow][maxColumns];
for(rows=0;rows<maxRow;rows++){
    for(columns=0;columns<maxColumns;columns++){
        fscanf(input,"%d",&map[rows][columns]);
    }

}
//printf ("The Maze has %d rows %d columns \n",rows,columns);
printMap(map,charx,chary);
 while(done==0){
            printf("Press w,a,s,d for up, left down and right: ");
            fflush(stdin);
            choice=getchar();
            updateMap(map,choice);
            system("cls");
            printMap(map,charx,chary);
if (map[charx][chary]==2){
    done=1;
}
}
printf("\nSOLVED!!!!!!!\n");
fclose(input);
system("pause");
return(0);

}
}
