
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void printIdeal(int i, int j, int n, int *bracket, char &name)
{
    if (i == j)
    {
        cout << name++;
        return;
    }
    cout << "(";
    printIdeal(i, *((bracket + i * n) + j), n, bracket, name);
    printIdeal(*((bracket + i * n) + j) + 1, j, n, bracket, name);
    cout << ")";
}

int MatrixChainOrder(vector<int> p, int n)
{
    vector<vector<int>> m(n, vector<int>(n, 0));
    int b[n][n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    b[i][j] = k;
                }
            }
        }
    }
    char name = 'A';
    printIdeal(1, n - 1, n, (int *)b, name);
    cout << "\n";
    return m[1][n - 1];
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
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(v, n) << endl;
    double time = (double)(clock() - start) / CLOCKS_PER_SEC;
    cout << "Time Taken :" << time << endl;

    return 0;
}