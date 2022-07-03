#ifndef __TABLE_H__
#define __TABLE_H__

#include "Coordinate.h"

class Table
{
    public:
        Table(int length, int width);
        ~Table();

        int getLength();
        int getWidth();
        bool isOutOfBounds(Coordinate & coordinate);

    private:
        int _length;
        int _width;
        
};

#endif // __TABLE_H__