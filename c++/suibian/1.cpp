#include <bits/stdc++.h>
#include <ratio>
using namespace std;
int main(){
	std::queue<int> s;
	std::deque<int> s1;
}class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        index=0;
    }
    
    void push(int x) {
		int mins;
		if(index==0){
			mins=x;
		}
        mins=mins>x?x:mins;
        fnt.emplace_back(make_pair(x,mins));
        index++;
    }
    
    void pop() {
		fnt.pop_back();
		index--;
    }
    
    int top() {
        return fnt[index-1].first;
    }
    
    int min() {
		return fnt[index-1].second;
    }
private:
    vector<pair<int,int>> fnt;
    int index;
};
