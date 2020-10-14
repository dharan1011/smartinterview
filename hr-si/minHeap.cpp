#include <vector>
#include <iostream>
#include <climits>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

class min_heap {
    vector<int> minHeap;

    int left(int idx){
        return 2 * idx + 1;
    }

    int right(int idx){
        return 2 * idx + 2;
    }

    int parent(int idx){
        return (idx - 1) / 2;
    }

    int getSize(){
        return minHeap.size();
    }

    bool empty(){
        return minHeap.empty();
    }

    void heapify(int idx){
        int li = left(idx);
        int ri = right(idx);
        int si = idx;
        if(li < getSize() && minHeap[si] > minHeap[li]){
            si = li;
        }
        if(ri < getSize() && minHeap[si] > minHeap[ri]){
            si = ri;
        }
        if(idx != si){
            swap(minHeap[si], minHeap[idx]);
            heapify(si);
        }
    }

public:
    void insert(int val){
        minHeap.push_back(val);
        int idx = getSize() - 1;
        while(minHeap[idx] < minHeap[parent(idx)]){
            swap(minHeap[idx], minHeap[parent(idx)]);
            idx = parent(idx);
        }
    }
    int getMin(){
        if(empty()){
            return INT_MAX;
        }
        return minHeap[0];
    }
    void deleteMin(){
        if(empty()){
            return;
        }
        int n = getSize() - 1;
        swap(minHeap[0],minHeap[n]);
        minHeap.pop_back();
        if(!empty())
            heapify(0);
    }
};

int main(){
    fast
    min_heap mh;
    int t; cin >> t;
    while(t--){
        string opr; cin >> opr;
        if(opr == "insert"){
            int x; cin >> x;
            mh.insert(x);
        }else if(opr == "getMin"){
            int val = mh.getMin();
            if(val == INT_MAX){
                cout << "Empty";
            }else{
                cout << val;
            }
            cout << "\n";
        }else{
            mh.deleteMin();
        }
    }
    return 0;
}