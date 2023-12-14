#include <iostream>
#include <vector>

using namespace std;
int cnt = 0;
vector<vector<int>> matrixAddition(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

vector<vector<int>> matrixSubtraction(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}
void print(string s, vector<vector<int>> v)
{
    cout << s << endl;
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}
vector<vector<int>> strassenMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    if (n == 1)
    {
        vector<vector<int>> result(1, vector<int>(1, 0));
        result[0][0] = A[0][0] * B[0][0];
        return result;
    }

    int half = n / 2;
    vector<vector<int>> A11(half, vector<int>(half));
    vector<vector<int>> A12(half, vector<int>(half));
    vector<vector<int>> A21(half, vector<int>(half));
    vector<vector<int>> A22(half, vector<int>(half));

    vector<vector<int>> B11(half, vector<int>(half));
    vector<vector<int>> B12(half, vector<int>(half));
    vector<vector<int>> B21(half, vector<int>(half));
    vector<vector<int>> B22(half, vector<int>(half));

    for (int i = 0; i < half; i++)
    {
        for (int j = 0; j < half; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    vector<vector<int>> P1 = strassenMultiply(A11, matrixSubtraction(B12, B22));
    vector<vector<int>> P2 = strassenMultiply(matrixAddition(A11, A12), B22);
    vector<vector<int>> P3 = strassenMultiply(matrixAddition(A21, A22), B11);
    vector<vector<int>> P4 = strassenMultiply(A22, matrixSubtraction(B21, B11));
    vector<vector<int>> P5 = strassenMultiply(matrixAddition(A11, A22), matrixAddition(B11, B22));
    vector<vector<int>> P6 = strassenMultiply(matrixSubtraction(A12, A22), matrixAddition(B21, B22));
    vector<vector<int>> P7 = strassenMultiply(matrixSubtraction(A11, A21), matrixAddition(B11, B12));

    vector<vector<int>> C11 = matrixSubtraction(matrixAddition(matrixAddition(P5, P4), P6), P2);
    vector<vector<int>> C12 = matrixAddition(P1, P2);
    vector<vector<int>> C21 = matrixAddition(P3, P4);
    vector<vector<int>> C22 = matrixSubtraction(matrixSubtraction(matrixAddition(P5, P1), P3), P7);

    print("M1", P1);
    print("M2", P2);
    print("M3", P3);
    print("M4", P4);
    print("M5", P5);
    print("M6", P6);
    print("M7", P7);
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < half; i++)
    {
        for (int j = 0; j < half; j++)
        {
            cnt++;
            result[i][j] = C11[i][j];
            result[i][j + half] = C12[i][j];
            result[i + half][j] = C21[i][j];
            result[i + half][j + half] = C22[i][j];
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> A = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3},
        {2, 2, 2, 2}};

    vector<vector<int>> B = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3},
        {2, 2, 2, 2}};

    vector<vector<int>> result = strassenMultiply(A, B);

    cout << endl;
    cout << "A :" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "B :" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Multiply : " << endl;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Count :" << cnt;
    cout << endl
         << endl;

    return 0;
}