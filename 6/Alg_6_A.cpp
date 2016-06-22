#include <iostream>
#include <vector>
using namespace std;
vector <char> str;
vector < vector <short> > map;
void finish_map();
int main(){
	char c;
	while(scanf("%c",&c) != EOF){
		if(c == ' ' || c == '\n')
			continue;
		str.push_back(c);
	}
	int length = str.size();
	map.resize(length);
	for(int i = 0;i < length;i++){
		map[i].resize(length);
	}
	finish_map();

	printf("%d",map[0][length-1]);
	return 0;

}

void finish_map(){
	for (int i = str.size() - 1;i >= 0;i--)
        {
            for (int j = i + 1;j < str.size();j++){
                if (str[i] == str[j])
                    map[i][j] = map[i+1][j-1] + 2;
                else
                    map[i][j] = max(map[i][j-1],map[i+1][j]);
						}
						map[i][i] = 1;
        }
}
