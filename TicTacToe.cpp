#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;

char row[9]={'1','2','3','4','5','6','7','8','9'};
int play=0,pos;
bool IsWin=false;



void CreateBoard(char row[]);
char PlayerInput(int play, char row[]);
bool CheckWin(bool IsWin, char row[]);

void CreateBoard(char row[9]){
cout<<setw(17)<<"   |  "<<row[0]<<"  |  "<<row[1]<<"  |  "<<row[2]<<"  |"<<endl;
cout<<setw(34)<<"  _____________________"<<endl;
cout<<setw(17)<<"   |  "<<row[3]<<"  |  "<<row[4]<<"  |  "<<row[5]<<"  |"<<endl;
cout<<setw(34)<<"  _____________________"<<endl;
cout<<setw(17)<<"   |  "<<row[6]<<"  |  "<<row[7]<<"  |  "<<row[8]<<"  |"<<endl<<endl<<endl<<endl;
}

char PlayerInput(int play, char row[]){

if(play%2!=0)
cout << "Player 1 : " << endl;

else 
cout << "Player 2" << endl;

cin>>pos;

while( pos<1 || pos>9 || row[pos-1]=='X' || row[pos-1]=='O'){
cout << "Wrong input. Enter a position between 1-9 or a position that isn't occupied" << endl;
cin>>pos;
}

if(play%2!=0)
row[pos-1]='X';
else 
row[pos-1]='O';

return row[pos-1];
}


bool CheckWin(bool IsWin, char row[]){
for(int j=0;  j<7; j+=3){
if(row[j]==row[j+1] && row[j]==row[j+2]){

    if (row[j]=='X')
        cout << "Player 1 wins!\n" << endl;
        else 
        cout << "Player 2 wins!\n" << endl;
        IsWin=true;
        }
    }
        
for(int i=0; i<3; i++){

    if (row[i]==row[i+3] && row[i+6]==row[i]){
    
        if (row[i]=='X')
        cout << "Player 1 wins!\n" << endl;
        else 
        cout << "Player 2 wins!\n" << endl;
        IsWin=true;
        }
    }
    
if ( row[0]==row[4] && row[8]==row[0] ){
    if (row[0]=='X')
        cout << "Player 1 wins!\n" << endl;
        else 
        cout << "Player 2 wins!\n" << endl;
        IsWin=true;
}
if (row[2]==row[4] && row[6]==row[2] ){
    if (row[2]=='X')
        cout << "Player 1 wins!\n" << endl;
        else 
        cout << "Player 2 wins!\n" << endl;
        IsWin=true;
}
return IsWin;
}

int main(){

    cout<<"                |"<<"             |"<<endl;
    cout<<"                | TIC TAC TOE |"<< endl;
    cout<<"                |"<<"             |"<<endl<<endl;
    cout << "\n\n\n\n\n" << endl;
    
    cout << "To start press 'ENTER' " << endl<<endl;
    char enter=getchar();
    
    
    while (IsWin==false &&  play<10){
    play++;
    clrscr();
    CreateBoard(row);
    PlayerInput(play,row);
   IsWin= CheckWin(IsWin, row);
    
    }
    CreateBoard(row);
    return 0;
    }
    
    



