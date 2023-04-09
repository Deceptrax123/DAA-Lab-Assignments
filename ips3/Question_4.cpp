#include <iostream>
#include <vector>
#include <ctime>
#include <unordered_map>

using namespace std;

int main()
{
    vector<int> v;
    int n;

    int num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    int sum = 0;
    unordered_map<int, int> pSum;

    int flag = 0;
    int last, start;
    for (int i = 0; i < n; i++)
    {
        sum = sum + v[i];

        if (pSum.find(sum) != pSum.end())
        {
            flag = 1;
            auto pair = pSum.find(sum);
            start = (pair->second) + 1;
            last = i;
        }
        pSum.insert(pair<int, int>(sum, i));
    }
    if (flag == 1)
    {
        cout << "First Index : " << start << endl;
        cout << "Last Index : " << last << endl;
    }
    else
    {
        cout << -1;
    }
}