#include <iostream>
#include <vector>
#include <sstream>
#include <string.h>
#include <queue>
using namespace std;

void BFS();
int dot_num;
int *ColorList;
vector<vector <int> > v;
queue <int> q;

int main(){
  string str;
  int dot_num;
  while(getline(cin,str)){
    if(str == "*")
        break;
    istringstream istr(str);
    int test;
    vector <int> temp;
    while(istr >> test){
      temp.push_back(test);
    }
    v.push_back(temp);
  }
  dot_num = v.size();

  ColorList = (int*)malloc(sizeof(int)*dot_num);
  for(int i = 0;i < dot_num;i ++)
    ColorList[i] = -1;
  ColorList[0] = 1;

  q.push(0);
  BFS();

  for(int i = 0;i < dot_num;i ++)
      if(ColorList[i] == 1)
        cout << i << endl;
  return 0;
}

void BFS(){
  while(!q.empty()){
    int temp = q.front();
    q.pop();
    for(int i = 1;i < v[temp].size();i ++){
      if(ColorList[v[temp][i]] == -1){
      q.push(v[temp][i]);
      ColorList[v[temp][i]] = 1 - ColorList[temp];
      }
    }
  }
}
