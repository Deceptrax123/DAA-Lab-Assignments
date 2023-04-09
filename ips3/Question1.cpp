#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    int n;
    vector<int> v;

    cin >> n;

    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    vector<int> sums;
    vector<vector<int>> indices;

    clock_t start = clock();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + v[j];
            sums.push_back(sum);
            indices.push_back({i, j});
        }
    }
    double time = (double)(clock() - start) / 1000;

    int max = sums[0];
    int f = 0;
    for (int i = 0; i < sums.size(); i++)
    {
        if (sums[i] > max)
        {
            max = sums[i];
            f = i;
        }
    }

    cout << "The maximum sum is " << max << endl;
    cout << "The start and end index are respectively " << indices[f][0] << "," << indices[f][1] << endl;
    cout << "The running time of the program : " << time << endl;

    return 0;
}