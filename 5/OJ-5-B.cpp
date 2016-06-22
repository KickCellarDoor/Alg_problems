#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

#define INF numeric_limits<int>::max()

struct dot{
	int des;
	int weight;
};
vector < vector <dot> > map;
vector <int> ColorList;
vector <int> mydistance; 
int n,s,t;

void SPFA(int n);

int main(){
	scanf("%d%d%d",&n,&s,&t);

	vector <int> temp;
	temp.resize(3);
	map.resize(n);
	ColorList.resize(n,0);
	mydistance.resize(n,0);

	dot d1,d2;
	while(scanf("%d%d%d",&temp[0],&temp[1],&temp[2]) != EOF){
		d1.des = temp[1];
		d1.weight = temp[0];
		map[temp[2]].push_back(d1);
		d2.des = temp[2];
		d2.weight = temp[0];
		map[temp[1]].push_back(d2);
	}

	SPFA(n);

	printf("%d",mydistance[t]);
	return 0;

}

void SPFA(int n)
{
    queue<int> q;
    int i;
    for(i = 0;i < n;i++){
    	if(i == s)
    		continue;
        mydistance[i] = INF;
        ColorList[i] = 0;
    }
    mydistance[s] = 0;
    ColorList[s] = 1;
    q.push(s);
    while(!q.empty()){
        i = q.front();
        q.pop();
        ColorList[i] = 0;
        for(int j = 0;j < map[i].size();j++){
            if(mydistance[map[i][j].des] > max(mydistance[i],map[i][j].weight)){
                mydistance[map[i][j].des] = max(mydistance[i],map[i][j].weight);
                if(ColorList[map[i][j].des] == 0){
                    q.push(map[i][j].des);
                    ColorList[map[i][j].des] = 1;
                }
            }
        }
    }
}
