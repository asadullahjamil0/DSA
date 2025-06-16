#include <iostream>
using namespace std;

void arrays_test_2D()
{
    int a[2][3];
    int val = 1;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j] = val;
            val += 1;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void struct_class()
{
    struct Students
    {
        int roll_no;
        float marks;
    };

    Students s1;
    Students s2;

    s1.roll_no = 2345;
    s1.marks = 20.5;
    s2.roll_no = 6532;
    s2.marks = 18;

    cout << "Student one has " << s1.marks << " marks!" << endl;
    cout << "Student two has " << s2.marks << " marks!" << endl;
};

int main()
{
    arrays_test_2D();
    struct_class();

    return 0;
}