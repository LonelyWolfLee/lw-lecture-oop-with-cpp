#include "MyShapes.h"
#include "AnswerShapes.h"
#include <cstdio>

Canvas expected(40, 40), actual(40, 40);

int LineTestCase[5][4] = {{3, 3, 3, 20},
                          {12, 16, 27, 16},
                          {3, 37, 37, 3},
                          {11, 14, 15, 33},
                          {4, 32, 29, 26}};

enum TestCase
{
    LINE,
    RECT,
    VLINE,
    HLINE,
    SQUARE
};

int LineTest()
{
    int score = 0;
    for (int i = 0; i < 5; i++)
    {
        expected.clear();
        actual.clear();

        Answer::Line line1(LineTestCase[i][0], LineTestCase[i][1], LineTestCase[i][2], LineTestCase[i][3]);
        Line line2(LineTestCase[i][0], LineTestCase[i][1], LineTestCase[i][2], LineTestCase[i][3]);

        line1.draw(expected);
        line2.draw(actual);

        if(expected != actual) 
        {
            return score;
        }
    }
    score++;



    return score;
}

int RectTest()
{
    int score = 0;

    return score;
}

int VLineTest()
{
    int score = 0;

    return score;
}

int HLineTest()
{
    int score = 0;

    return score;
}

int SquareTest()
{
    int score = 0;

    return score;
}

void scoring(string student)
{
    int score[5];

    for (int i = 0; i < 5; i++)
    {
        switch (i)
        {
        case LINE:
            score[LINE] = LineTest();
            break;
        case RECT:
            score[RECT] = RectTest();
            break;
        case VLINE:
            score[VLINE] = VLineTest();
            break;
        case HLINE:
            score[HLINE] = HLineTest();
            break;
        case SQUARE:
            score[SQUARE] = SquareTest();
            break;

        default:
            break;
        }
    }

    cout << student;
    for (int i = 0; i < 5; i++)
    {
        printf(", %d", score[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        cerr << "You need 1 parameeter for this program" << endl;
    }

    string student(argv[1]);

    cerr << "Student No. : " << student << endl;
    scoring(student);
    return 0;
}