#ifndef __SHAPES_H__
#define __SHAPES_H__
#include "BaseShape.h"

/**
 * MyShapes.h : 과제 1-1 을 수행하기 위해 구현 해야 하는 파일
 * 
 * [문제]
 * BaseShape.h 의 Shape 클래스를 상속 받은 Line, Rect, VLine, HLine, Square 을 구현하시오
 * 
 * [조건]
 * 모든 도형은 생성 시점에 각자가 필요한 값을 입력 받아서 저장 해야 한다.
 * 모든 도형(Shape)은 각자의 적절한 규칙으로 그리기(draw) 및 이동(move)이 가능해야 한다.
 * 
 * 1. Line (선)
 * 양 끝점을 입력 받고, 두 점을 잇는 선을 그린다.
 * 
 * 2. Rect (사각형)
 * 시작 위치와 가로 세로를 입력 받고, 조건에 맞는 사각형을 그린다.
 * 
 * 3. VLine (수직선)
 * 한 점과 길이를 입력 받고, 수직선을 그린다.
 * 
 * 4. HLine (수평선)
 * 한 점과 길이를 입력 받고, 수평선을 그린다.
 * 
 * 5. Square (정사각형)
 * 시작 위치와 길이를 입력 받고, 정 사각형을 그린다.
 *  
 **/

class Line : public Shape
{
    Point q; //  선분의 다른 쪽 끝점 (한쪽 끝점은 p임)
public:
    Line(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0)
        : Shape(x1, y1), q(x2, y2) {}
    void draw(Canvas &canvas, string color = "L")
    {
        int len = Max(Abs(q.getX() - p.getX()), Abs(q.getY() - p.getY()));
        double x = p.getX(), y = p.getY();
        double dx = (q.getX() - p.getX()) / (double)len, dy = (q.getY() - p.getY()) / (double)len;
        for (int i = 0; i <= len; i++)
        {
            canvas.draw(Round(x), Round(y), color);
            x += dx;
            y += dy;
        }
    }
    void move(int dx, int dy)
    {
        p.move(dx, dy);
        q.move(dx, dy);
    }
};

class Rect : public Shape
{
    int w, h; // 사각형의 가로와 세로 길이 (시작점은 p임)
public:
    Rect(int x = 0, int y = 0, int ww = 0, int hh = 0)
        : Shape(x, y), w(ww), h(hh) {}
    void draw(Canvas &canvas, string color = "R")
    {
        for (int i = p.getX(); i <= p.getX() + w; i++)
        {
            canvas.draw(i, p.getY(), color);     // 사각형의 윗변
            canvas.draw(i, p.getY() + h, color); // 사각형의 아랫변
        }
        for (int i = p.getY(); i <= p.getY() + h; i++)
        {
            canvas.draw(p.getX(), i, color);     // 사각형의 좌변
            canvas.draw(p.getX() + w, i, color); // 사각형의 우변
        }
    }
};

class HLine : public Line
{
public:
    HLine(int x = 0, int y = 0, int len = 0) : Line(x, y, x + len, y) {}
};
class VLine : public Line
{
public:
    VLine(int x = 0, int y = 0, int len = 0) : Line(x, y, x, y + len) {}
};
class Square : public Rect
{
public:
    Square(int x = 0, int y = 0, int w = 0) : Rect(x, y, w, w) {}
};

#endif