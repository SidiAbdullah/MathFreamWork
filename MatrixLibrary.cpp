#include <iostream>
#include <iomanip>
#include <cstdlib> // for rand(), srand()
#include <ctime>   // for time()
#include <vector>
using namespace std;

void FillRandomMatrix(short array[3][3])
{
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            array[i][j] = rand() % 100 + 1;
        }
    }
}
void printMatrix(short array[3][3])
{
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            cout << setw(5);
            printf("  %0*d  ", 2, array[i][j]);
        }
        cout << endl;
    }
}
void fillMatrixInOrder(short array[3][3])
{
    short counter = 0;
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            ++counter;
            array[i][j] = counter;
            cout << endl;
        }
    }
}
void MatrixMidlleRow(short array[3][3])
{
    cout << "midlle row is: ";
    for (short j = 0; j < 3; j++)
    {
        printf("  %0*d  ", 2, array[1][j]);
    }
    cout << endl;
}
void MatrixMidllecolumn(short array[3][3])
{
    cout << "midlle column is: ";
    for (short j = 0; j < 3; j++)
    {
        printf("  %0*d  ", 2, array[j][1]);
    }
    cout << endl;
}
void transposeMatrix(short array[3][3])
{
    short counter = 0;
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            ++counter;
            array[j][i] = counter;
        }
    }
}
void sumMatrixRows(short array[3][3])
{
    short r = 0;
    short arr[3];
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            r += array[i][j];
        }
        arr[i] = r;
        r = 0;
    }
    for (short i = 0; i < 3; i++)
    {
        cout << "row " << i + 1 << " sum: " << arr[i] << endl;
    }
}
void sumMatrixcolumns(short array[3][3])
{
    short r = 0;
    short arr[3];
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            r += array[j][i];
        }
        arr[i] = r;
        r = 0;
    }
    for (short i = 0; i < 3; i++)
    {
        cout << "column " << i + 1 << " sum: " << arr[i] << endl;
    }
}
void sumMatrixNumbers(short array[3][3])
{
    int result = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result += array[i][j];
        }
    }
    cout << "the sum of the matrix numbers is : " << result << endl;
}
void Multiply2Matrix(short array1[3][3], short array2[3][3])
{
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            cout << setw(5) << array1[i][j] * array2[i][j];
        }
        cout << endl;
    }
}
void areMatrixsTypical(short array1[3][3], short array2[3][3])
{
    int result = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result += (array1[i][j] != array2[i][j]);
        }
    }
    (result == 0) ? cout << "they are equal" : cout << "they are not equal";
    cout << endl;
    // cout << (result == 0) ? "they are not equal" : "they are equal" << endl;
}
void isMatrixIdentity(short array[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((i == j && array[i][j] != 1) || (i != j && array[i][j] != 0))
            {
                cout << "NO. this matrix is not identical" << endl;
                return;
            }
        }
    }
    cout << "YES. this matrix is identical" << endl;
}
int countNumberInMatrix(short array[3][3], short number)
{
    short counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (number == array[i][j])
                ++counter;
        }
    }
    return counter;
}
void isMatrixScalar(short array[3][3])
{
    short firstNumber = array[0][0];
    for (int i = 0; i < 3; i++)
    {
        if (array[i][i] != firstNumber)
        {
            cout << "this matrix is not scalar" << endl;
            return;
        }
        for (int j = 0; j < 3; j++)
        {
            if (i != j && array[i][j] != 0)
            {
                cout << "this matrix is not scalar" << endl;
                return;
            }
        }
    }
    cout << "this is a scalar matrix" << endl;
}
void isSparceMatrix(short array[3][3])
{
    short zeroCount = countNumberInMatrix(array, 0);
    if (zeroCount >= 5)
    {
        cout << "YES. it is parce" << endl;
        return;
    }
    cout << "NO. it is not parce" << endl;
}
bool isNumberInMatrix(short array[3][3], short number)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (number == array[i][j])
            {
                return true;
            }
        }
    }
    return false;
}
void IntercectedNumsOfMatrixs(short array1[3][3], short array2[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (isNumberInMatrix(array2, array1[i][j]))
            {
                cout << setw(3) << array1[i][j];
            }
        }
    }
}
void MaxNumberInMatrix(short array[3][3])
{
    int maxNumber = array[0][0];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (array[i][j] > maxNumber)
            {
                maxNumber = array[i][j];
            }
        }
    }
    cout << "The max number of this matrix is...  " << maxNumber << endl;
}
void MinNumberInMatrix(short array[3][3])
{
    int minNumber = array[0][0];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (array[i][j] < minNumber)
            {
                minNumber = array[i][j];
            }
        }
    }
    cout << "The max number of this matrix is...  " << minNumber << endl;
}
bool isPalindrome(short array[3][3])
{
    short num = 0;
    for (int i = 0; i < 3; i++)
    {
        if (array[i][0] == array[i][2])
        {
            num += 1;
        }
    }
    if (num == 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    short arr1[3][3] = {{2, 3, 2}, {4, 7, 4}, {1, 6, 8}};
    printMatrix(arr1);
    cout << "#####################" << endl;
}

// Sidi Abdullah Lemrabott
