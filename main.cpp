#include <iostream>
#include <conio.h> //console input output
#include <windows.h>
using namespace std;
bool gameover;
int grosime=20,inaltime=20;
int x,y,fx,fy,scor;
int xcoada[100],ycoada[100],lcoada;
enum Directie
{STOP=0,STANGA,DREAPTA,SUS,JOS};
Directie dir;
void setup()
{
    gameover=false;
    dir=STOP;
    x=grosime/2;
    y=inaltime/2;
    fx=rand()%inaltime;
    fy=rand()%grosime;
    scor=0;
}
void desen()
{
    system("cls");
    for(int i=0; i<grosime+2; i++)
        cout<<"#";
    cout<<endl;
    for(int i=0; i<=inaltime; i++)
    {

        for(int j=0; j<grosime; j++)
        {
            if(j==0)cout<<"#";
            if(i==y && j==x) cout<<"0";
            else if(i==fy && j==fx)
                cout<<"F";
            else
            {
                bool print=false;
                for(int k=0; k<lcoada; k++)
                {

                    if(xcoada[k]==j&&ycoada[k]==i)
                    {
                        cout<<"o";
                        print=true;
                    }

                }
                if(!print)cout<<" ";
            }
            if(j==grosime-1)cout<<"#";
        }
        cout<<endl;
    }
    for(int i=0; i<grosime+2; i++)
        cout<<"#";
    cout<<endl;
    cout<<"Scor="<<scor<<endl;
}
void comenzi()
{
    if(kbhit())
    {
        switch(getch())//get charachter
        {
        case 'a':
            dir=STANGA;
            break;
        case 'd':
            dir=DREAPTA;
            break;
        case 'w':
            dir=SUS;
            break;
        case 's':
            dir=JOS;
            break;
        case 'x':
            gameover=true;
            break;
        }
    }
}
void reguli()
{
    int pX=xcoada[0],pY=ycoada[0],p2x,p2y;
    xcoada[0]=x;
    ycoada[0]=y;
    for(int i=1; i<lcoada; i++)
    {
        p2x=xcoada[i];
        p2y=ycoada[i];
        xcoada[i]=pX;
        ycoada[i]=pY;
        pX=p2x;
        pY=p2y;

    }
    switch(dir)
    {
    case STOP:
        break;
    case STANGA:
        x--;
        break;
    case DREAPTA:
        x++;
        break;
    case SUS:
        y--;
        break;
    case JOS:
        y++;
        break;
    default:
        break;
    }
    if(x>grosime || x<0 || y>inaltime || y<0)
        gameover=true;
    for(int i=0; i<lcoada; i++)if(xcoada[i]==x && ycoada[i]==y)gameover=true;
    if(x==fx && y==fy)
    {
        scor++;
        fx=rand()%inaltime;
        fy=rand()%grosime;
        lcoada++;
    }
}
int main()
{
    setup();
    while(!gameover)
    {
        desen();
        comenzi();
        reguli();
        Sleep(60);
    }
    return 0;
}
