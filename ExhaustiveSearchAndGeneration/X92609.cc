#include <iostream>
#include <vector>
using namespace std;

/////////////////////
////ta dificil :))///
/////////////////////


int write_sols(const vector<int>& nums, int x, int partial_sum, vector<int>& selected, int left_sum) {
    if (partial_sum > x) return 0;
    if (left_sum + partial_sum < x) return 0;
    if (nums.size() == selected.size()) {

    }
}

void write_sols(const vector<int>& nums, int x) {
    vector<int> selected;
    int partial_sum = 0;
    int left_sum = 0;
    for (int i : nums) left_sum += i;
    cout << write_sols(nums, x, partial_sum, selected, left_sum);
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

        //sort(nums.begin(), nums.end());
        write_sols(nums, x);

        cout << endl;
    }

}
