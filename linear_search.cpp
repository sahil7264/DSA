#include <bits/stdc++.h>
using namespace std;
vector<int> generate_unique_random_elements(int n, int start, int end)
{
    vector<int> elements;
    for (int i = start; i <= end; ++i)
    {
        elements.push_back(i);
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(elements.begin(), elements.end(), g);

    elements.resize(n);
    return elements;
}
int linearSearch(vector<int> arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter the number of elements in array" << endl;
    cin >> n;

    vector<int> arr = generate_unique_random_elements(n, 1, n);

    cout << "Elements of array are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter the target" << endl;
    int target;
    cin >> target;
    if (linearSearch(arr, target) != -1)
        cout << "Element is at index " << linearSearch(arr, target) << endl;
    else
        cout << "Element not found" << endl;
}