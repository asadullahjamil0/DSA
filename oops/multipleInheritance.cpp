#include <iostream>
using namespace std;

class Student
{
private:
    int roll_number;

public:
    Student() {}
    void setRollNumber(int);
    void getRrollNumber();
};

void Student::setRollNumber(int r)
{
    roll_number = r;
}

void Student ::getRrollNumber()
{
    cout << "Roll number of student is:" << roll_number << endl;
}

class Exam : public Student
{
protected:
    float physicsMarks;
    float mathMarks;

public:
    void setMarks(float, float);
    void displayMarks();
};

void Exam::setMarks(float phy, float math)
{
    physicsMarks = phy;
    mathMarks = math;
}

void Exam ::displayMarks()
{
    cout << "Physics Marks: " << physicsMarks << endl;
    cout << "Math Marks: " << mathMarks << endl;
}

class percentageResult : public Exam
{
    float percentage;

public:
    void displayPercentage()
    {
        getRrollNumber();
        displayMarks();
        cout << "Percentage of student's result: " << (mathMarks + physicsMarks) / 2 << "%" << endl;
    }
};

int main()
{
    percentageResult st1;
    st1.setRollNumber(5733);
    st1.getRrollNumber();
    st1.setMarks(77, 84);
    st1.displayMarks();
    st1.displayPercentage();

    return 0;
}