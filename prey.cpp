#include "prey.h"

void Prey::move(Creature* grid[][MAX_COL])
{
    Creature::move(grid);
}

void Prey::breed(Creature* grid[][MAX_COL])
{
    Creature::breed(grid);
}

void Prey::print(ostream &outs) const
{
    outs << "o";
}

ostream& operator <<(ostream &outs, const Prey &p)
{
    p.print(outs);
    return outs;
}

