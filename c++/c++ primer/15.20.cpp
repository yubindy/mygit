#include <iostream>
#include <memory>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <fstream>
#include <alloca.h>
#include <sstream>
#include <algorithm>
using namespace std;
class Query_base
{
    friend class Query;
protected:
    Query_base() = default;
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const=0;
    virtual string rep() const=0;
};
class Query
{
  friend Query operator~(const Query &);
  friend Query operator|(const Query &,const Query &);
  friend Query operator&(const Query &,const Query &);
public:
    Query(const string &s);
    QueryResult eval(const TextQuery &t) const {return q->eval;}
    string rep() const {return q->rep;}
    ~Query();
private:
   Query(shared_ptr<Query_base> query): q(query) {}
   shared_ptr<Query_base> q;
};
class Wordquery :public Query_base
{ 
   friend class Query;
   Wordquery(const string &s) : query_word(s) {}
   QueryResult eval(const TextQuery &t) const {return t.query(query_word);}
   string rep() const {return query_word;}
   string query_word;
}