#ifndef __COORDINATE_H__
#define __COORDINATE_H__

class Coordinate
{
    public:
        Coordinate();
        Coordinate(int x, int y);

        ~Coordinate();

        // X Coordinate
        void setXCoordinate(int x);
        int getXCoordinate() const;

        // Y Coordinate
        void setYCoordinate(int y);
        int getYCoordinate() const;

    private:
        int _x;
        int _y;
};

#endif // __COORDIANTE_H__