
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
stack<string> S1,S2;
//S1 keeps track of prev played Songs
//S2 is an auxilary stack
queue<string>Songs;
queue<string> playlist;

void FeedSongs(){
cout<<"Enter Songs:(Press -1 to end)\n";
  string s;
while(s!="-1"){
    cin>>s;
    if(s!="-1")
    Songs.push(s);
}
    cout<<"Library of songs created\n";
}


//Searching song in queue
bool Ispresent(string t){
int n=Songs.size();
queue<string>song = Songs;
for(int i=0;i<n;i++){
    if(song.front()==t)
      return true;
      else
       song.pop();
}
      return false;

}
//Create playlist
void CreatePlaylist(){
cout<<"Enter Songs for Playlist(Press -1 to end)\n";
string s1="";
while(s1!="-1"){
    cout<<"Enter songs to add\n";
    cin>>s1;
    if(s1!="-1"){
    if(Ispresent(s1))
    playlist.push(s1);
    else
    cout<<"Song not found";
    }
    else
        cout<<"Playlist created\n";  
}
}


//Play previous
void PlayPrev(int n){
    int nn=S1.size();
    if(n>nn)
    cout<<"Not enough prev songs";
    else{
        while(n--){
        S2.push(S1.top());
        S1.pop();
        }
    
        string temp=S2.top();
        S2.pop();
        cout<<"Now playing"<<temp<<"\n";
        
        while(!S2.empty()){
        S1.push(S2.top());
        S2.pop();
    }
     //since prev song is the most recent song
    S1.push(temp);
}
}


void Play(){
char action='n';
int i=0; 
 int size=playlist.size();
while(action!='e' && i<size){
    cout<<"Enter the action\n";
    cin>>action;
    if(action=='n'){
    S1.push(playlist.front());
     cout<<"Now playing"<<playlist.front()<<"\n";
    playlist.pop();

    }
   
    if(action=='p'){
        int prev_count;
        cin>>prev_count;
        if(prev_count>0)
        PlayPrev(prev_count);
        else
        cout<<"Enter valid prev song";
    }
    
}
}



#include <iostream>
using namespace std;

int main()
{   
    FeedSongs();
    CreatePlaylist();
    Play();
    return 0;
}

