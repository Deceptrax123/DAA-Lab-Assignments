#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int search(vector<int> &v, int l, int r, int k)
{
    if (r >= l)
    {
        int mid = l + (r - 1) / 2;

        if (v[mid] == k)
        {
            return mid + 1;
        }
        if (v[mid] > k)
        {
            return search(v, l, mid - 1, k);
        }
        return search(v, mid + 1, r, k);
    }

    return -1;
}

double sort(vector<int> &v, int n)
{
    int j;

    clock_t start = clock();
    for (int i = 1; i < n; i++)
    {
        int temp = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > temp)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = temp;
    }
    double time = (double)(clock() - start) / CLOCKS_PER_SEC;
    return time;
}

int main()
{
    vector<int> v;
    int n;
    int k;

    cin >> n;
    cin >> k;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    double sort_time = sort(v, n);
    clock_t search_start = clock();
    int pos = search(v, 0, n - 1, k);
    double search_time = (double)(clock() - search_start) / CLOCKS_PER_SEC;

    cout << "Position of element : " << pos << endl;
    cout << "Time taken to run the program : " << search_time + sort_time << " seconds" << endl;
    return 0;
}