//백준 23350, K 물류창고

#include <iostream>
#include <queue>
#include <stack>

std::queue<std::pair<int, int>> q;

int freq[101];
int N, M;
int sum = 0;

void rotate() {
  auto num = q.front();
  q.pop();
  q.push(num);
  sum += num.second;
}

void check(std::stack<int>& s, int w) {
  std::stack<int> tmpS;

  while(!s.empty() && w > s.top()){
    sum += s.top();
    tmpS.push(s.top());
    s.pop();
  }

  s.push(w);
  sum += w;
  
  while (!tmpS.empty()) {
    sum += tmpS.top();
    s.push(tmpS.top());
    tmpS.pop();
  }
}

void solve() {
  int prirotiy = M;
  std::stack<int> s;
  while(prirotiy != 0) {
    if(freq[prirotiy] == 0) {
      --prirotiy;
      s = std::stack<int>();
      continue;
    }
    if(q.front().first != prirotiy) rotate();
    else{
      --freq[prirotiy];
      if(s.empty()) {
        sum += q.front().second;
        s.push(q.front().second);
      }
      else check(s, q.front().second);
      q.pop();
    }
  }
}

int main (){
  std::cin >> N >> M;
  for(int i{0}; i<N; ++i) {
    int P, W;
    std::cin >> P >> W;
    q.push({P, W});
    freq[P] += 1;
  }
  solve();
  std::cout << sum;
  return 0;
}