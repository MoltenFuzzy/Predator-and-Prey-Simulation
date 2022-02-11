#ifndef PREDATOR_H
#define PREDATOR_H

#include "creature.h"

class Predator : public Creature
{
public:
    Predator() = default;
    Predator(int row, int col) : Creature(row, col) {}

    virtual void move(Creature* grid[][MAX_COL]);
    virtual void breed(Creature* grid[][MAX_COL]);
    virtual void print(ostream& outs) const;
    virtual int get_type() const {return _type;}

    // creating a new derived object
    virtual Creature* new_derived(int row, int col)
    {return new Predator(row, col);}

private:
    int starve_steps = 0;
    int _type = PREDATOR;
};

#endif // PREDATOR_H
