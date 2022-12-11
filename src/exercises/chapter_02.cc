#include <exercises/chapter_02.hh>
#include <utils/utils.hh>

#include <cstdlib>
#include <iostream>

using namespace std;

const unsigned int MATRIX_ROWS = 2;
const unsigned int MATRIX_COLUMNS = 3;

void print_matrix(const string name, const int (&matrix)[MATRIX_ROWS][MATRIX_COLUMNS])
{
    cout << name << " =" << endl;
    for (unsigned int row = 0; row < MATRIX_ROWS; row++)
    {
        for (unsigned int col = 0; col < MATRIX_COLUMNS; col++)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void chapter_02::exercise_01()
{
    bool A = true;
    bool B = true;
    bool C = false;
    bool D = false;

    cout << "Assume A is true, B is true, C is false and D is false" << endl;
    cout << "A || B || C || D = true (" << (A || B || C || D) << ")" << endl;
    cout << "A && B && C && D = false (" << (A && B && C && D) << ")" << endl;
    cout << "!C && !D = true (" << (!C && !D) << ")" << endl;
    cout << "!((A && B) || (B && !C)) || !(C && D)  = true (" << (!((A && B) || (B && !C)) || !(C && D)) << ")" << endl;
    cout << "!(!((A && !D) && (B || C))) = true (" << (!(!((A && !D) && (B || C)))) << ")" << endl;
}

void chapter_02::exercise_02()
{
    utils::vec2 current_position = {0, 0};
    char input;

    do
    {
        cout << "Current position = (" << current_position.x << ", " << current_position.y << ")" << endl;
        cout << "Move (N)orth, (E)ast, (S)outh, (W)est or (Q)uit? ";
        cin >> input;

        switch (input)
        {
        case 'n':
        case 'N':
            current_position.y += 1;
            break;

        case 'e':
        case 'E':
            current_position.x += 1;
            break;

        case 's':
        case 'S':
            current_position.y -= 1;
            break;

        case 'w':
        case 'W':
            current_position.x -= 1;
            break;

        // dont need these cases here, but i like being explicit
        case 'q':
        case 'Q':
        default:
            break;
        }
    } while (input != 'q' && input != 'Q');
}

void chapter_02::exercise_03()
{
    int n;
    double input, sum = 0;

    cout << "Enter the number of values to average: ";
    cin >> n;

    for (unsigned int i = 0; i < n; i++)
    {
        cout << "[" << i << "] = ";
        cin >> input;
        sum += input;
    }

    cout << "Average = " << sum / n << endl;
}

void chapter_02::exercise_04()
{
    unsigned int n;

    cout << "Enter a positive integer to compute the factorial of: ";
    cin >> n;
    cout << "!" << n << " = " << utils::factorial(n) << endl;
}

void chapter_02::exercise_05()
{
    int A[2][3] = {
        {-5, 2, 8},
        {1, 0, 0}};
    int B[2][3] = {
        {1, 0, 2},
        {0, 3, -6}};
    int sum[2][3] = {
        {0, 0, 0},
        {0, 0, 0}};

    for (unsigned int m = 0; m < 2; m++)
    {
        for (unsigned int n = 0; n < 3; n++)
        {
            sum[m][n] = A[m][n] + B[m][n];
        }
    }

    print_matrix("A", A);
    print_matrix("B", B);
    print_matrix("A + B", sum);
}

void chapter_02::exercise_06()
{
    const int max_cols = 9;

    for (unsigned int i = 33; i <= 255; i++)
    {
        cout << i << ": " << (unsigned char)i << " ";

        if (!((i - 33) % max_cols))
        {
            cout << endl;
        }
    }
}

void chapter_02::exercise_07()
{
    const int list[] = {7, 3, 32, 2, 55, 34, 6, 13, 29, 22, 11, 9, 1, 5, 42, 39, 8};
    const int elements = sizeof(list) / sizeof(int);
    int key;

    cout << "Enter an integer in the list to search for: ";
    cin >> key;

    for (unsigned int i = 0; i < elements; i++)
    {
        if (list[i] == key)
        {
            cout << "Item found at index [" << i << "]" << endl;
            return;
        }
    }
    cout << "No item in list matches with given criteria!" << endl;
}

void chapter_02::exercise_08()
{
    int x[10];
    const int n = sizeof(x) / sizeof(int);
    int p, temp;

    // input
    cout << "Enter " << n << " unsorted integers..." << endl;
    for (unsigned int i = 0; i < n; i++)
    {
        cout << "[" << i << "] = ";
        cin >> x[i];
    }
    cout << endl;

    // unsorted
    cout << "Unsorted List =";
    for (unsigned int i = 0; i < n; i++)
    {
        cout << " " << x[i];
    }
    cout << endl;

    // sorting...
    cout << "Sorting using selection sort algorithm..." << endl;

    // let x[n] = x[0],...,x[n-1] be an arn integers to sort
    // let p be an integer to store an array indexray of give
    // for i = 0 to n - 2
    for (unsigned int i = 0; i <= n - 2; i++)
    {
        // find the array index of the smallest value in the subarray x[i],...,x[n-1] and store it in p
        for (unsigned int j = i; j <= n - 1; j++)
        {
            if (j == i || x[j] < temp)
            {
                temp = x[j];
                p = j;
            }
        }

        // swap x[i] and x[p]
        temp = x[i];
        x[i] = x[p];
        x[p] = temp;
    }

    // sorted
    cout << "Sorted List =";
    for (unsigned int i = 0; i < n; i++)
    {
        cout << " " << x[i];
    }
    cout << endl;
}
