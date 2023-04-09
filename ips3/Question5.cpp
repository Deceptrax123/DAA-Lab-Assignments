#include <iostream>
#include <vector>

using namespace std;

int maxSubArraySum(vector<int> v, int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    int start = 0, end = 0, s = 0;
    vector<int> sums;
    vector<vector<int>> indices;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + v[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;

            sums.push_back(max_so_far);
            indices.push_back({start, end});
        }
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    for (int i = 0; i < sums.size(); i++)
    {
        if (max_so_far == sums[i])
        {
            cout << "Start index : " << indices[i][0] << endl;
            cout << "End index : " << indices[i][1] << endl;
        }
    }
    return max_so_far;
}

int main()
{
    vector<int> v;
    int n;

    cin >> n;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    int max_sum = maxSubArraySum(v, n);

    cout << "Maximum sum of subarray : " << max_sum << endl;
    return 0;
}
