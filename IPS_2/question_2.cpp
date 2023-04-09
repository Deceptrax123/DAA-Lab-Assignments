#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

bool average(vector<int> p1, vector<int> p2)
{
    int m1 = (p1[0] + p1[1]) / 2;
    int m2 = (p2[0] + p2[1]) / 2;

    if (m1 >= m2)
    {
        return true;
    }
    return false;
}

void combine(vector<vector<int>> &v, int p, int q, int r, int f)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<vector<int>> v1;
    vector<vector<int>> v2;

    for (int i = 0; i < n1; i++)
    {
        v1.push_back(v[p + i]);
    }
    for (int j = 0; j < n2; j++)
    {
        v2.push_back(v[q + 1 + j]);
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    if (f == 0 || f == 1)
    {
        while (i < n1 && j < n2)
        {
            if (v1[i][f] <= v2[j][f])
            {
                v[k] = v1[i];
                i++;
            }
            else
            {
                v[k] = v2[j];
                j++;
            }
            k++;
        }
    }
    else
    {
        while (i < n1 && j < n2)
        {
            if (average(v1[i], v2[j]))
            {
                v[k] = v1[i];
                i++;
            }
            else
            {
                v[k] = v2[j];
                j++;
            }
            k++;
        }
    }

    while (i < n1)
    {
        v[k] = v1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        v[k] = v2[j];
        j++;
        k++;
    }
}

void sorted(vector<vector<int>> &v, int l, int r, int f)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        sorted(v, l, m, f);
        sorted(v, m + 1, r, f);
        combine(v, l, m, r, f);
    }
}

int main()
{
    vector<vector<int>> v;
    int n = 4;
    v = {{0, 1}, {2, 2}, {1, 20}, {-1, 0}};

    // sort based on  x value
    // sorted(v, 0, n - 1, 0);

    // sort based on y value
    // sorted(v, 0, 3, 1);

    // sort based on x+y/2
    sorted(v, 0, 3, 2);

    for (int i = 0; i < n; i++)
    {
        cout << "(" << v[i][0] << "," << v[i][1] << ")"
             << " " << endl;
    }

    return 0;
}