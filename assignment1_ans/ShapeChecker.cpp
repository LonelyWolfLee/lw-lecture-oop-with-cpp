#include "MyShapes.h"
#include "AnswerShapes.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

Canvas expected(50, 50), actual(50, 50);

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

enum LengthType
{
    UNKNOWN,   // 아직 판단이 안된 경우
    INCLUSIVE, // 길이가 자신의 위치를 포함하는 경우 (3 ~ 6 을 길이 4로 판단)
    EXCLUSIVE  // 길이가 자신의 위치를 포함하지 않는 경우 (3 ~ 6 을 길이 3으로 판단)
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

        if (expected != actual)
        {
            return score;
        }
    }
    score++;

    for (int i = 0; i < 5; i++)
    {
        expected.clear();
        actual.clear();

        Answer::Line line1(LineTestCase[i][0], LineTestCase[i][1], LineTestCase[i][2], LineTestCase[i][3]);
        Line line2(LineTestCase[i][0], LineTestCase[i][1], LineTestCase[i][2], LineTestCase[i][3]);

        for (int n = 0; n < 10; n++)
        {
            expected.clear();
            actual.clear();

            int dx = rand() % 2;
            int dy = rand() % 2;
            line1.move(dx, dy);
            line2.move(dx, dy);
            line1.draw(expected);
            line2.draw(actual);
        }
        
        if (expected != actual)
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
    srand((unsigned int)time(NULL));

    scoring(student);
    return 0;
}