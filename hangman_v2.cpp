#include<iostream>
#include<vector>
#include<conio.h>
#include<string>

using namespace std;
string getquestion(){
    string word="";
    char letter;

        while (true){
        letter=getch(); //without echoing stores input
            if(letter<32){ //when special character used, returns word
                cout<<endl;
          return word;
    }
    if(letter==' ')
    word.push_back('_');
    else
    word.push_back(letter);
}
}
string pass(int l){//to genertate * to match length of the question
    int i=0;
    string ash="";
    while(i++<l){
        ash.push_back('*');
    }
    return(ash);
}

int main(){
int lives,i;
char guess;
string qword,secret,buffer;
cout<<"Enter number of lives you want: ";
cin>>lives;
cout<<"\nHey Event organizer, Enter the question (can use space, but they are changed to '_') :\n";//typed word won't be visible on screen
qword=getquestion();
secret=pass(qword.length());


do{
    buffer=secret;
    cout<<"\nEnter your guess: ";
    cin>>guess;
    for(i=0;i<qword.length();i++)//replacing correct guess
        if(qword[i]==guess)
        secret[i]=guess;

        if(buffer==secret)//to check words before and after the guess
        lives--;
    
    cout<<"Lives remaining :"<<lives<<" Progress:"<<secret<<endl;
}while(lives>0&&(secret!=qword));

if(lives==0)
cout<<"n\n\n\ngameover: answer is "<<qword<<endl;
else if(secret==qword)
cout<<"\n\n\n****You won!**** \n\nRESPECT+"<<endl;
return 0;
}