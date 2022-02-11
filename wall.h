#ifndef WALL_H
#define WALL_H

#include "creature.h"

class Wall : public Creature
{
public:
    virtual void print(ostream& outs) const {outs << "Z";}
    virtual int get_type() const {return _type;}

    friend ostream& operator <<(ostream& outs, const Wall& z)
    {
        z.print(outs);
        return outs;
    }
private:
    int _type = WALL;
};

#endif // WALL_H
