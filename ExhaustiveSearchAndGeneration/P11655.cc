#include <iostream>
#include <vector>
using namespace std;

void write(const vector<int>& selected, const vector<int>& nums) {
    bool first = true;
    cout << "{";
    for (int i = 0; i < int(selected.size()); ++i) {
        if (selected[i]) {
            if (not first) cout << ",";
            else first = false;
            cout << nums[i];
        }
    }
    cout << "}" << endl;
}

void bck(int idx, int sum_partial, int sum_left, vector<int>& selected, const vector<int>& nums, int n) {
    if (sum_partial > n) return;
    if (sum_left + sum_partial < n) return;
    if (idx == int(selected.size())) { if (sum_partial == n) write(selected,nums); }
    else {
        selected[idx] = true;
        bck(idx+1,sum_partial+nums[idx],sum_left-nums[idx],selected,nums,n);
        selected[idx] = false;
        bck(idx+1,sum_partial,sum_left-nums[idx],selected,nums,n);
    }
}

void bck(const vector<int>& nums, int n) {
    vector<int> selected(nums.size());
    int sum_partial = 0;
    int sum_left = 0;
    for (const int& i:nums) sum_left += i;
    bck(0,sum_partial,sum_left,selected,nums,n);
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> nums(m);
    for (int& i:nums) cin >> i;
    bck(nums,n);
}
