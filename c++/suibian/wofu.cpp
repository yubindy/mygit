#include<vector>
#include<stdio.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int mins=0;
    vector<int> s(prices.size(),0);
    s[0]=0;
    int n=1;
    for(auto i=prices.begin()+1;i!=prices.end();i++){
        mins=min(mins,*i);
        s[n]=max(s[n-1],*i-mins);
        n++;
    }
    return s[n-1];
    }
};
int main(){
    class Solution t;
    vector<int> tt{7,1,5,3,6,4};
    printf("%d", t.maxProfit(tt));
}

func (p *defaultPoll) Control(operator *FDOperator, event PollEvent) error {
	//var op int
	var evt epollevent
	var prepRequest iouring.PrepRequest
	var err error
	*(**FDOperator)(unsafe.Pointer(&evt.data)) = operator
	atomic.AddInt64(&p.numid,1)
	num:=atomic.LoadInt64(&p.numid)
	switch event {
	case PollReadable:
		operator.inuse()
		var bs=operator.Inputs(p.barriers[num].bs)
		prepRequest = iouring.Readv(operator.FD,bs)
		p.Requestset, err = p.uring.SubmitRequest(prepRequest,operator.mess)
	case PollDetach:
		_, err = p.Requestset.Cancel()
		<-p.Requestset.Done()
	case PollWritable:
		operator.inuse()
		var bs, supportZeroCopy = operator.Outputs(p.barriers[num].bs)
		prepRequest,err = iouring.Sendmsg(operator.FD,bs,nil,p.barriers[num].ivs,supportZeroCopy )
		p.Requestset, err = p.uring.SubmitRequest(prepRequest,operator.mess)
	}
	return err
}