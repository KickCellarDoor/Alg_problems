#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
using namespace std;


vector < vector <int> > tree;
vector < vector <int> > score;

int getscore(int num,int flag);

int main(){
	string str;
	while(getline(cin,str)){
		istringstream istr(str);
		int current;
		istr >> current;
		vector <int> dot;
		int temp;
		while(istr >> temp){
			dot.push_back(temp);
		}
		tree.push_back(dot);
	}

	int dot_num = tree.size();	 
	score.resize(dot_num);

	for(int i = 0;i < dot_num;i++){
		score[i].resize(2);
		score[i][0] = -1;
		score[i][1] = -1;
	}
	printf("%d",min(getscore(0,0),getscore(0,1)));
	return 0;
}

int getscore(int num,int flag){
	if(score[num][flag] == -1){
		score[num][0] = 0;
		score[num][1] = 1;
		for(int i = 0;i < tree[num].size();i++){
			score[num][1] += min(getscore(tree[num][i],0),getscore(tree[num][i],1));
			score[num][0] += getscore(tree[num][i],1);
		}
	}
	return score[num][flag];
}

