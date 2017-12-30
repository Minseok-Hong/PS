#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
 
struct meeting{
    int start,end;
};
 
int cmp(const meeting &a, const meeting &b){
    if(a.end == b.end)
        return a.start < b.start;
    return a.end < b.end;
}
 
int main() {
    int n,i,s,e,last=-1,c=0;
    meeting t;
    vector<meeting> v;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&s,&e);
        t.start = s;
        t.end = e;
        v.push_back(t);
    }
    sort(v.begin(),v.end(),cmp);
    for(i=0;i<n;i++){
        if(v[i].start >= last){
            last = v[i].end;
            c++;
        }
    }
    printf("%d",c);
    return 0;
}