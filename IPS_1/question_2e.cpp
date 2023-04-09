#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool distance(vector<int> v1, vector<int> v2)
{
    vector<double> dist;

    double d1 = sqrt(pow(v1[0], 2) + pow(v1[1], 2));
    double d2 = sqrt(pow(v2[0], 2) + pow(v2[1], 2));

    if (d1 > d2)
    {
        return true;
    }
    return false;
}

void sort(vector<vector<int>> &v, int n)
{
    int j;
    for (int i = 1; i < n; i++)
    {
        vector<int> temp = v[i];
        j = i - 1;

        while (j >= 0 && distance(v[j], temp))
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = temp;
    }
}

int main()
{
    vector<vector<int>> v;
    int n;

    n = 4;
    v = {{0, 1}, {2, 2}, {1, 20}, {-1, 0}};

    sort(v, n);

    cout << "Points after sorting: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i][0] << "," << v[i][1] << " ";
    }

    return 0;
}