//백준 14891, 톱니바퀴

#include <iostream>
#include <deque>

std::deque<int> o;
std::deque<int> t;
std::deque<int> th;
std::deque<int> f;

void input(){
    std::string s;
    std::cin >> s;
    for(int i{0}; i<8; ++i){
        o.push_back(s[i]-'0');
    }

    std::cin >> s;
    for(int i{0}; i<8; ++i){
        t.push_back(s[i]-'0');
    }

    std::cin >> s;
    for(int i{0}; i<8; ++i){
        th.push_back(s[i]-'0');
    }

    std::cin >> s;
    for(int i{0}; i<8; ++i){
        f.push_back(s[i]-'0');
    }
}

void solve(int a, int b){
    bool fO{false}, fT{false}, fTh{false}, fF{false};
    int cO{0}, cT{0}, cTh{0}, cF{0};
    if(a == 1){
        fO = true;
        cO = b;
        if(o[2] != t[6]){
            fT = true;
            cT = cO == -1 ? 1 : -1;
            if(t[2] != th[6]){
                fTh = true;
                cTh = cT == -1 ? 1 : -1;
                if(th[2] != f[6]){
                    fF = true;
                    cF = cTh == -1 ? 1 : -1;
                }
            }
        }
    }
    else if(a == 2){
        fT = true;
        cT = b;
        if(o[2] != t[6]){
            fO = true;
            cO = cT == -1 ? 1 : -1;
        }
        if(t[2] != th[6]){
            fTh = true;
            cTh = cT == -1 ? 1 : -1;
            if(th[2] != f[6]){
                fF = true;
                cF = cTh == -1 ? 1 : -1;
            }
        }
    }
    else if(a == 3){
        fTh = true;
        cTh = b;
        if(th[2] != f[6]){
            fF = true;
            cF = cTh == -1 ? 1 : -1;
        }
        if(th[6] != t[2]){
            fT = true;
            cT = cTh == -1 ? 1 : -1;
            if(o[2] != t[6]){
                fO = true;
                cO = cT == -1 ? 1 : -1;
            }
        }
    }
    else{
        fF = true;
        cF = b;
        if(f[6] != th[2]){
            fTh = true;
            cTh = cF == -1 ? 1 : -1;
            if(th[6] != t[2]){
                fT = true;
                cT = cTh == -1 ? 1 : -1;
                if(t[6] != o[2]){
                    fO = true;
                    cO = cT == -1 ? 1 : -1;
                }
            }
        }
    }
    if(fO){
        if(cO == -1){
            auto tmp = o.front(); o.pop_front();
            o.push_back(tmp);
        } //앞에꺼 빼서 뒤로 보내기
        else{
            auto tmp = o.back(); o.pop_back();
            o.push_front(tmp);
        }
    }
    if(fT){
        if(cT == -1){
            auto tmp = t.front(); t.pop_front();
            t.push_back(tmp);
        } //앞에꺼 빼서 뒤로 보내기
        else{
            auto tmp = t.back(); t.pop_back();
            t.push_front(tmp);
        }
    }
    if(fTh){
        if(cTh == -1){
            auto tmp = th.front(); th.pop_front();
            th.push_back(tmp);
        } //앞에꺼 빼서 뒤로 보내기
        else{
            auto tmp = th.back(); th.pop_back();
            th.push_front(tmp);
        }
    }
    if(fF){
        if(cF == -1){
            auto tmp = f.front(); f.pop_front();
            f.push_back(tmp);
        } //앞에꺼 빼서 뒤로 보내기
        else{
            auto tmp = f.back(); f.pop_back();
            f.push_front(tmp);
        }
    }
}

int main (){
    input();

    int K;
    std::cin >> K;

    int a, b;
    for(int i{0}; i<K; ++i){
        std::cin >> a >> b;
        solve(a, b);
    }

    int sum{0};
    if(o.front() == 1) ++sum;
    if(t.front() == 1) sum += 2;
    if(th.front() == 1) sum +=4;
    if(f.front() == 1) sum += 8;

    std::cout << sum;

    return 0;
}