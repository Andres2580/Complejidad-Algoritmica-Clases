#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
typedef unsigned long ul;
string names1[]={"paz","emocion","libertad","amor","patria"};
string names2[]={"gigante","pequeño","distante","cercano","profundo"};
class Song{
ul nro;
string title;
float duration;
ul views;
public:
  Song(ul nro,string title,float duration, ul views): nro(nro),title(title), duration(duration), views(views){
  }
  Song(ul n=0){
    nro=n;
    generate();
  }
    ul getNro(){return nro;}
  string toString(){return to_string(nro)+","+title+","+to_string(duration)+","+to_string(views)+"\n";}
void generate(){
   title=names1[rand()%5]+" "+names2[rand()%5];
  duration=(float)((rand()%100)/(float)10);
  views=rand()%90000;
  }
};
class PlayList{
vector<Song> vSong;
public:
  PlayList(){}
  void generate(){
    for(size_t i=0;i<10;++i)
      vSong.push_back(Song(i+1));
  }
  void saveAll(){
    ofstream file("canciones.txt");
    for(auto a:vSong)
      file<<a.toString();
    file.close();
  }
  void openAll(){
    vSong.clear();
    ifstream file("canciones.txt");
    string song, tmp, title;
    float dur;
    ul n, views;
    while(getline(file,song)){
      stringstream ss(song);//convierto a un archivo temporal
      getline(ss,tmp,',');
      n=stol(tmp);
      getline(ss,tmp,',');
      title=tmp;
      getline(ss,tmp,',');
      dur=stof(tmp);
      getline(ss,tmp);
      views=stoi(tmp);
//      cout<<n<<" "<<title<<" "<<dur<<" "<<views<<endl;
      vSong.push_back(Song(n,title,dur,views));
    }
       file.close();
  }
  void print(){
    for(auto a:vSong)
      cout<<a.toString(); 
  }
  void shuffle(){
    int j;
    for(size_t i=vSong.size()-1;i>0;i--){
      j=rand()%i;
      swap(vSong[i],vSong[j]);
    }
  }
  void exchangeSort(){
    for(size_t i=0;i<vSong.size()-1;++i){
      for(size_t j=i+1;j<vSong.size();++j){
        if(vSong[i].getNro()<vSong[j].getNro())
          swap(vSong[i],vSong[j]);
    }
  }
  }

};
int main() {
  srand(time(0));
  PlayList p;
  p.generate();
  p.print();
  cout<<endl;
  p.shuffle();
  p.print();
  cout<<endl;
  p.exchangeSort();
  p.print();
//  p.saveAll();
 // p.openAll();
  //Asignación: la función shuffle y exchangesort soporte lambdas
}
