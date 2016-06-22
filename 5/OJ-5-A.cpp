#include <iostream>
#include <stack>
#include <vector>
#include <limits>
#define INF numeric_limits<int>::max()

using namespace std;

struct dot{
	int des;
	int weight;
};

vector <vector <dot> > map;
stack <int> mysort;
vector <int> ColorList;
vector <int> score;

void DFS(int current);
void max_weight();

int main(){
	int dot_num;
	scanf("%d",&dot_num);

	map.resize(dot_num);
	ColorList.resize(dot_num,0);
	score.resize(dot_num,-INF);
	score[0] = 0;
	
	int data[3];
	dot d;
	while(scanf("%d%d%d",&data[0],&data[1],&data[2]) != EOF){
		d.des = data[1];
		d.weight = data[2];
		map[data[0]].push_back(d);
	}
	
	DFS(0);

	for(int i = 0;i < dot_num;i++)
		ColorList[i] = 0;

	max_weight();
	for(int i = 1;i < score.size();i++)
		printf("%d ",score[i]);
	return 0;
}

void DFS(int current){
	ColorList[current] = -1;
	for(int i = 0;i < map[current].size();i++){
		if(ColorList[map[current][i].des] == 0)
			DFS(map[current][i].des);
	}
	mysort.push(current);
	ColorList[current] = 1;
}

void max_weight(){
	while(!mysort.empty()){
		int current = mysort.top();
		mysort.pop();

		if(score[current] != -INF){
			for(int i = 0;i < map[current].size();i++){
				if(score[map[current][i].des] < score[current] + map[current][i].weight)
					score[map[current][i].des] = score[current] + map[current][i].weight;
			}
		}
	}
}