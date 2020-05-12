#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include "Canvas.h"

class Character
{
private:
    string name, icon; // 캐릭터의 이름과 화면 출력 아이콘
    int x, y, nItem;   // 현재 위치와 획득한 아이템 수
    void clip(int maxx, int maxy)
    {
        if (x < 0)
            x = 0;
        if (x >= maxx)
            x = maxx - 1;
        if (y < 0)
            y = 0;
        if (y >= maxy)
            y = maxy - 1;
    }

public:
    Character(string name, string icon, int px, int py)
        : name(name), icon(icon), x(px), y(py), nItem(0) {}
    ~Character()
    {
        cout << "\t" << name << " " << icon << " is gone." << endl;
    }
};

#endif