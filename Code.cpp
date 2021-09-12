
#include<iostream>
using namespace std;
stack<int> S1,S2;
//S1 keeps track of prev played Songs
//S2 is an auxilary stack
queue<string>Songs;
queue<string> playlist;

void FeedSongs(){
cout<<"Enter Songs:(Press -1 to end)\n";
while(Songs.back()!="-1"){
    string s;
    cin>>s;
    Songs.push_back(s);
}
}


//Searching song in queue
bool Ispresent(string t){
int n=Songs.size();
for(int i=0;i<n;i++){
    if(Songs[i]==t)
      return true;
}
      return false;

}
//Create playlist
void CreatePlaylist(){
cout<<"Enter Songs for Playlist(Press -1 to end)\n";
string s="";
while(s!="-1"){
    cout<<"Enter songs to add";
    string s1;
    cin>>s1;
    if(Ispresent(s1))
    playlist.push_back(s1);
    else
    cout<<"Song not found";
    
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
        
        while(!S2.empty()){
        S1.push(S2.top());
        S2.pop();
    }
     //since prev song is the most recent song
    S1.push(temp);
}


void Play(){
char action='n';

while(action!='e'){
    if(action=='n'){
    S1.push(playlist->val);
    playlist=playlist->next;
    }
    
    if(action=='p'){
        cin>>prev_count;
        PlayPrev(prev_count);
    }
    
    if(action=='n')
     playlist=playlist->next;
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

