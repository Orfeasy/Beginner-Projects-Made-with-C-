#include<vector>
#include<conio.h>
#include<string>
#include<iostream>
using namespace std;

string word;
int size,tries=6,pos=0;
char letter;
char letters[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
                            
                            

void CreateHangman (vector<string> gword,int tries, char letters[]);
int CheckLetter(vector<string>gword, string word, int size);
bool CheckWin(vector<string>gword, vector<string>word2);

void CreateHangman (vector<string> gword, int tries, char letters[]){
switch (tries){
case 0:
cout <<"___________"<<endl;
cout <<"|         ["<<endl;
cout <<"|       \\ 0 /" <<endl;
cout <<"|         |"<<endl;
cout <<"|        / \\ "<<endl;
cout<<"_|______________"<<endl;
break;

case 1:
cout << " ___________"<<endl;
 cout << " |         ["<<endl;
 cout << " |       \\ 0 /" <<endl;
 cout << " |         |"<<endl;
 cout << " |        /  "<<endl;
cout << "_|______________"<<endl;
break;

case 2:
cout << " ___________"<<endl;
cout << " |         ["<<endl;
cout << " |       \\ 0 /" <<endl;
cout << " |         |"<<endl;
cout << " |" << endl;
cout << "_|______________"<<endl;
     break;      
     
case 3:
cout << " ___________"<<endl;
cout << " |         ["<<endl;
cout << " |       \\ 0 /" <<endl;
cout << " |         "<<endl;
cout << " | " << endl;
cout << "_|______________"<<endl;
     break;       
 case 4:
 cout << " ___________"<<endl;
cout << " |         ["<<endl;
cout << " |       \\ 0  " <<endl;
cout << " |         "<<endl;
cout << "_|______________"<<endl;
break;
case 5:
cout << " ___________"<<endl;
cout << " |         ["<<endl;
cout << " |         0  " <<endl;
cout << " |         "<<endl;
cout << " |           " << endl;
cout << "_|______________"<<endl;
break;

case 6:
cout <<"  ___________"<<endl;
 cout <<" |         ["<<endl;
 cout <<" |         " <<endl;
 cout << " |          " << endl;
 cout << " |           " << endl;
 cout <<"_|______________"<<endl; 
 break;
 }
 cout << "" << endl;
 for(auto words : gword)
cout <<words<<" ";
cout << "\n" << endl;
cout << "Letters left to guess : " << endl;
for (int i=0; i<26; i++)
cout << letters[i]<<" ";
cout << "" << endl;
}

int CheckLetter(vector<string>gword, string word, int size){
vector<string>word2(size,"*");
bool x=true;
while( tries>0){
    cout << "\n\nEnter Letter: " << endl;
    cin >> letter;
    for(int i=0; i<26; i++){
    if(letters[i]==letter)
        letters[i]=' ';
        }
    clrscr();
    x=true;
    for( pos=0; pos<size; pos++){
        if(word.at(pos)==letter){
        x=false;
        gword[pos]=letter;
        word2[pos]=gword[pos];
        if(CheckWin(gword, word2))
        return 0;
        }
    }
    if(x==true){
    tries--;
    cout << "Wrong letter! You have " <<tries<<" tries left"<<endl;
    if(tries==0)
    cout << "You lost! Better luck next time! The word was " <<word<<endl;
}
CreateHangman(gword,tries,letters);
}
return 0;
}

bool CheckWin(vector<string>gword, vector<string>word2){
if(word2==gword){
cout << "Congratulations! You won! The word is ";
for (auto words : word2)
cout <<words;

return true;
}
return false; 
}


int main(){
cout << "Enter a word:" << endl;
cin>>word;
clrscr();
size=word.length();
vector<string> gword(size, "_");
CreateHangman (gword,tries,letters);
CheckLetter(gword, word, size);
return 0; 

}