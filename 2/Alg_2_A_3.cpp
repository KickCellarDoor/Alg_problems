#include <iostream>
#include <vector>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, greater<int> > queue_b;
priority_queue<int, vector<int>, less<int> > queue_s;

void insert(int x);

int main(){
  int a;
  int count = 1;
  while(scanf("%d",&a) != EOF){
    count++;
    insert(a);
    if(count % 2 == 0)
      printf("%d ",queue_b.top());
    else
      printf("%d ",queue_s.top());
  }
  return 0;
}

void insert(int x) {
    if(queue_b.empty()) {
        queue_b.push(x);
    }
    else{
      if(x > queue_b.top())
        queue_b.push(x);
      else
        queue_s.push(x);
    }
    if(queue_b.size() < queue_s.size() ) {
        queue_b.push(queue_s.top());
        queue_s.pop();
    }
    if(queue_b.size() > queue_s.size() + 1) {
        queue_s.push(queue_b.top());
        queue_b.pop();
    }
}
