#ifndef PREY_H
#define PREY_H

#include "creature.h"

class Prey : public Creature
{
public:
    Prey() = default;
    Prey(int row, int col) : Creature(row, col) {}

    virtual void move(Creature* grid[][MAX_COL]);
    virtual void breed(Creature* grid[][MAX_COL]);
    virtual void print(ostream& outs) const;
    virtual int get_type() const {return _type;}

    // creating a new derived object
    virtual Creature* new_derived(int row, int col)
    {return new Prey(row, col);}

private:
    int _type = PREY;
};

#endif // PREY_H
