#include "MyShapes.h"
#include "AnswerShapes.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

Canvas expected(50, 50), actual(50, 50);

int ThreeValueTestCase[5][3] = {{3, 3, 20},
                                {12, 16, 16},
                                {3, 37, 3},
                                {11, 14, 33},
                                {4, 32, 26}};
int FourValueTestCase[5][4] = {{3, 3, 3, 20},
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
    EXCLUSIVE, // 길이가 자신의 위치를 포함하지 않는 경우 (3 ~ 6 을 길이 3으로 판단)
    INCLUSIVE, // 길이가 자신의 위치를 포함하는 경우 (3 ~ 6 을 길이 4로 판단)
    UNKNOWN,   // 아직 판단이 안된 경우

};

LengthType type = UNKNOWN;

int LineTest()
{
    int score = 0;
    for (int i = 0; i < 5; i++)
    {
        expected.clear();
        actual.clear();

        Answer::Line line1(FourValueTestCase[i][0], FourValueTestCase[i][1], FourValueTestCase[i][2], FourValueTestCase[i][3]);
        Line line2(FourValueTestCase[i][0], FourValueTestCase[i][1], FourValueTestCase[i][2], FourValueTestCase[i][3]);

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

        Answer::Line line1(FourValueTestCase[i][0], FourValueTestCase[i][1], FourValueTestCase[i][2], FourValueTestCase[i][3]);
        Line line2(FourValueTestCase[i][0], FourValueTestCase[i][1], FourValueTestCase[i][2], FourValueTestCase[i][3]);

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
    {
        expected.clear();
        actual.clear();
        Answer::Rect rect1(1, 2, 3, 4);
        Rect rect2(1, 2, 3, 4);
        rect1.draw(expected);
        rect2.draw(actual);
        if (expected == actual)
        {
            type = EXCLUSIVE;
        }
        else
        {
            actual.clear();
            Rect rect3(1, 2, 2, 3);
            rect3.draw(actual);
            if (expected == actual)
            {
                type = INCLUSIVE;
            }
            else
            {
                return score;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        expected.clear();
        actual.clear();

        Answer::Rect rect1(FourValueTestCase[i][0], FourValueTestCase[i][1], FourValueTestCase[i][2], FourValueTestCase[i][3]);
        Rect rect2(FourValueTestCase[i][0], FourValueTestCase[i][1], FourValueTestCase[i][2] - type, FourValueTestCase[i][3] - type);

        rect1.draw(expected);
        rect2.draw(actual);

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

        Answer::Rect rect1(FourValueTestCase[i][0], FourValueTestCase[i][1], FourValueTestCase[i][2], FourValueTestCase[i][3]);
        Rect rect2(FourValueTestCase[i][0], FourValueTestCase[i][1], FourValueTestCase[i][2] - type, FourValueTestCase[i][3] - type);

        for (int n = 0; n < 10; n++)
        {
            expected.clear();
            actual.clear();

            int dx = rand() % 2;
            int dy = rand() % 2;
            rect1.move(dx, dy);
            rect2.move(dx, dy);
            rect1.draw(expected);
            rect2.draw(actual);
        }

        if (expected != actual)
        {
            return score;
        }
    }
    score++;

    return score;
}

int HLineTest()
{
    int score = 0;

    if (type == UNKNOWN)
    {
        expected.clear();
        actual.clear();
        Answer::HLine hline1(1, 2, 3);
        HLine hline2(1, 2, 3);
        hline1.draw(expected);
        hline2.draw(actual);
        if (expected == actual)
        {
            type = EXCLUSIVE;
        }
        else
        {
            actual.clear();
            HLine hline3(1, 2, 2);
            hline3.draw(actual);
            if (expected == actual)
            {
                type = INCLUSIVE;
            }
            else
            {
                return score;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        expected.clear();
        actual.clear();

        Answer::HLine hline1(ThreeValueTestCase[i][0], ThreeValueTestCase[i][1], ThreeValueTestCase[i][2]);
        HLine hline2(ThreeValueTestCase[i][0], ThreeValueTestCase[i][1], ThreeValueTestCase[i][2]);

        hline1.draw(expected);
        hline1.draw(actual);

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

        Answer::HLine hline1(ThreeValueTestCase[i][0], ThreeValueTestCase[i][1], ThreeValueTestCase[i][2]);
        HLine hline2(ThreeValueTestCase[i][0], ThreeValueTestCase[i][1], ThreeValueTestCase[i][2] - type);

        for (int n = 0; n < 10; n++)
        {
            expected.clear();
            actual.clear();

            int dx = rand() % 2;
            int dy = rand() % 2;
            hline1.move(dx, dy);
            hline2.move(dx, dy);
            hline1.draw(expected);
            hline2.draw(actual);
        }

        if (expected != actual)
        {
            return score;
        }
    }
    score++;

    return score;
}

int VLineTest()
{
    int score = 0;

    if (type == UNKNOWN)
    {
        expected.clear();
        actual.clear();
        Answer::VLine vline1(1, 2, 3);
        VLine vline2(1, 2, 3);
        vline1.draw(expected);
        vline2.draw(actual);
        if (expected == actual)
        {
            type = EXCLUSIVE;
        }
        else
        {
            actual.clear();
            VLine vline3(1, 2, 2);
            vline3.draw(actual);
            if (expected == actual)
            {
                type = INCLUSIVE;
            }
            else
            {
                return score;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        expected.clear();
        actual.clear();

        Answer::VLine vline1(ThreeValueTestCase[i][0], ThreeValueTestCase[i][1], ThreeValueTestCase[i][2]);
        VLine vline2(ThreeValueTestCase[i][0], ThreeValueTestCase[i][1], ThreeValueTestCase[i][2]);

        vline1.draw(expected);
        vline1.draw(actual);

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

        Answer::VLine vline1(ThreeValueTestCase[i][0], ThreeValueTestCase[i][1], ThreeValueTestCase[i][2]);
        VLine vline2(ThreeValueTestCase[i][0], ThreeValueTestCase[i][1], ThreeValueTestCase[i][2] - type);

        for (int n = 0; n < 10; n++)
        {
            expected.clear();
            actual.clear();

            int dx = rand() % 2;
            int dy = rand() % 2;
            vline1.move(dx, dy);
            vline2.move(dx, dy);
            vline1.draw(expected);
            vline2.draw(actual);
        }

        if (expected != actual)
        {
            return score;
        }
    }
    score++;

    return score;
}

int SquareTest()
{
    int score = 0;

    if (type == UNKNOWN)
    {
        expected.clear();
        actual.clear();
        Answer::Square square1(1, 2, 3);
        Square square2(1, 2, 3);
        square1.draw(expected);
        square2.draw(actual);
        if (expected == actual)
        {
            type = EXCLUSIVE;
        }
        else
        {
            actual.clear();
            Square square3(1, 2, 2);
            square3.draw(actual);
            if (expected == actual)
            {
                type = INCLUSIVE;
            }
            else
            {
                return score;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        expected.clear();
        actual.clear();

        Answer::Square square1(ThreeValueTestCase[i][0], ThreeValueTestCase[i][1], ThreeValueTestCase[i][2]);
        Square square2(ThreeValueTestCase[i][0], ThreeValueTestCase[i][1], ThreeValueTestCase[i][2]);

        square1.draw(expected);
        square2.draw(actual);

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

        Answer::Square square1(ThreeValueTestCase[i][0], ThreeValueTestCase[i][1], ThreeValueTestCase[i][2]);
        Square square2(ThreeValueTestCase[i][0], ThreeValueTestCase[i][1], ThreeValueTestCase[i][2] - type);

        for (int n = 0; n < 10; n++)
        {
            expected.clear();
            actual.clear();

            int dx = rand() % 2;
            int dy = rand() % 2;
            square1.move(dx, dy);
            square2.move(dx, dy);
            square1.draw(expected);
            square2.draw(actual);
        }

        if (expected != actual)
        {
            return score;
        }
    }
    score++;

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
        case HLINE:
            score[HLINE] = HLineTest();
            break;
        case VLINE:
            score[VLINE] = VLineTest();
            break;
        case SQUARE:
            score[SQUARE] = SquareTest();
            break;

        default:
            break;
        }
    }

    int total = 0;
    for (int i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            printf("%d", score[i]);
        }
        else
        {
            printf(", %d", score[i]);
        }
        total += score[i];
    }
    printf(" => %d\n", total);
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        cerr << "You need 1 parameeter for this program" << endl;
        return 1;
    }

    string student(argv[1]);

    cerr << "Student No. : " << student << endl;
    srand((unsigned int)time(NULL));

    scoring(student);
    return 0;
}