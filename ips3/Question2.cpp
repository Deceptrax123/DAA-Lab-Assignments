#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int max(int a, int b)
{
    int m = (a > b) ? a : b;
    return m;
}

int max(int a, int b, int c)
{
    return max(max(a, b), c);
}

int crossingsum(vector<int> v, int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;

    for (int i = m; i >= l; i--)
    {
        sum = sum + v[i];
        if (sum > left_sum)
        {
            left_sum = sum;
        }
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m; i <= h; i++)
    {
        sum = sum + v[i];
        if (sum > right_sum)
        {
            right_sum = sum;
        }
    }
    return max(left_sum + right_sum - v[m], left_sum, right_sum);
}

int subarray(vector<int> v, int l, int h)
{
    if (l >= h)
    {
        return v[l];
    }
    int m = (l + h) / 2;

    return max(subarray(v, l, m - 1), subarray(v, m + 1, h), crossingsum(v, l, m, h));
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
    int max_sum = subarray(v, 0, n - 1);
    double time = (double)(clock() - start) / CLOCKS_PER_SEC;

    cout << "Time Taken : " << time;
    return 0;
}