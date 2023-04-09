#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int maxSubArraySum(vector<int> v, int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    int start = 0, end = 0, s = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + v[i];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << "Starting index : " << start << endl;
    cout << "Ending index : " << end << endl;

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

    clock_t start = clock();
    int max_sum = maxSubArraySum(v, n);
    double time = (double)(clock() - start) / CLOCKS_PER_SEC;

    cout << "Maximum sum of subarray : " << max_sum << endl;
    cout << "Time taken : " << time << endl;
    return 0;
}
