#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/////////////////////////
///SE COMPLICA MI PANA///
/////////////////////////

void write(int x, const vector<int>& nums, vector<int>& selected) {
    //for (int i = 0; i < int(selected.size()); ++i) cout << selected[i] << " ";
    cout << x << " = ";
    bool any_written = false;
    for (int i = 0; i < int(selected.size()); ++i) {
        if (selected[i]) {
            if (any_written) cout << " + ";
            else any_written = true;
            cout << nums[i];
            if (nums[i] == nums[i-1]) cout << "p";
        }
    }
    cout << endl;

}

void write_sols(const vector<int>& nums, int x, int partial_sum, vector<int>& selected, int left_sum) {
    if (partial_sum > x) return;
    if (left_sum + partial_sum < x) return;
    if (nums.size() == selected.size()) {
        if (partial_sum == x) write(x,nums,selected);
    }
    else {
        selected.push_back(true);
        write_sols(nums, x, partial_sum+nums[selected.size()-1], selected, left_sum-nums[selected.size()-1]);

        selected.back() = false;
        write_sols(nums, x, partial_sum, selected, left_sum);
        selected.pop_back();
    }
}

void write_sols(const vector<int>& nums, int x) {
    vector<int> selected;
    int partial_sum = 0;
    int left_sum = 0;
    for (int i : nums) left_sum += i;
    write_sols(nums, x, partial_sum, selected, left_sum);
}

int main() {
    int x,n;

    while (cin >> x >> n) {
        // nums will have size 2n
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            nums.push_back(num);
            nums.push_back(num);
        }

        sort(nums.begin(), nums.end());
        write_sols(nums, x);

        cout << "----------" << endl;
    }
}
