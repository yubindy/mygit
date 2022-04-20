#include <stack>
#include<map>
using namespace std;
class CQueue
{
private:
    stack<int> fro, end;

public:
    CQueue()=default;

    void appendTail(int value)
    {
        fro.push(value);
    }

    int deleteHead()
    {   int s=0;
    map<int,int> t;
    t.
        if (end.empty())
        {
            while (!fro.empty())
            {
                end.push(fro.top());
                fro.pop();
            }
        }
        if(end.empty())
        {
            return -1;
        }
        else
        {
         s=end.top();
         end.pop();
         return s;
        }
    }
};