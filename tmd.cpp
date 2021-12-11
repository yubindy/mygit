#include <iostream>
#include <vector>
using namespace std;
class TopVotedCandidate
{
public:
   TopVotedCandidate(vector<int> &persons, vector<int> &times):
       per(persons),
       time(times) {}
   int q(int t)
   {
    t=1;
    return t;   
   }
private:
   vector<int> per;
   vector<int> time;
};
