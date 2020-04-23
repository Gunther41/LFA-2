#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
char history[100];
char v[50][50][50][10]; //[nod1][nod2][cuvintele sau literele dintre nod1 si nod2][fiecare litera din acele cuvinte]
char gol[2]={' ','\0'};
int latura=0,inaltime=0,starifinale[100],nrfinale,accept=0;


/*
int verifica (int nod,int locincuv){
int i,k,j,lung;
char temp[10];
if(locincuv==strlen(word)){for(i=1;i<=nrfinale;i++)if(nod==starifinale[i]){cout<<"Acceptat";accept=1;return 0;}}

for(k=1;k<=inaltime;k++)for(j=0;j<=latura;j++){
        if(accept==1)break;
        if(strcmp(v[nod][j][k],gol)!=0){
            lung=strlen(v[nod][j][k]);
            for(i=0;i<lung;i++)temp[i]=word[locincuv+i];temp[i]='\0';
            if(strcmp(temp,v[nod][j][k])==0){cout<<"\nDin nodul "<<nod<<" iau "<<v[nod][j][k]<<" la "<<j;verifica(j,locincuv+lung);}}}

return 0;}

*/

int drum (int nod,int locincuv, int finish){
int i,k,j,lung;
char temp[10];
if(locincuv==finish){for(i=1;i<=nrfinale;i++)if(nod==starifinale[i]){puts (history);return 0;}}

for(k=1;k<=inaltime;k++)for(j=0;j<=latura;j++)
    {
        if(strcmp(v[nod][j][k],gol)!=0)
        {
            lung=strlen(v[nod][j][k]);
            if(lung+locincuv<=finish){
                strcat(history,v[nod][j][k]);
                history[locincuv+lung] = '\0';
                drum(j,locincuv+lung,finish);}
                history[locincuv] = '\0';
                //AS PUTEA SALVA AICI TOATE NODURILE PRIN CARE TREC SI SA LE PRINTEZ CUM FAC SI CU CUVINTELE
        }
    }
return 0;}








int main (){
ifstream f("input3d.in");
ofstream o("output3d.txt");
int n,i,j,k,l,stareinit,sfarsit;
f>>stareinit;
f>>nrfinale;
for(i=1;i<=nrfinale;i++)f>>starifinale[i];
f>>n;


for(i=0;i<50;i++)for(j=0;j<50;j++)for(k=0;k<50;k++)strcpy(v[i][j][k],gol);
for(l=1;l<=n;l++){
f>>i;
f>>j;
k=1;
while(strcmp(v[i][j][k],gol)!=0)k++;
if(inaltime<k)inaltime=k;
f>>v[i][j][k];
if(latura<i)latura=i;
if(latura<j)latura=j;
}


f>>sfarsit;

for(i=1;i<=sfarsit;i++){
        cout<<"Lungimea "<<i<<" :\n";
        history[0] = '\0';
        drum(stareinit,0,i);}



//verifica(stareinit,0);
//if(accept==0)cout<<"Cuvantul nu a fost acceptat";

for(k=1;k<=inaltime;k++){o<<"\n"<<"Stratul "<<k<<":\n";for(i=0;i<latura;i++){for(j=0;j<latura;j++)o<<"["<<v[i][j][k]<<"]";o<<"\n";}} //pentru vizualizarea matricei

o.close();
f.close();
return 0;}



