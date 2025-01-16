
#ifndef DICE_H

#define DICE_H

class Dice
{

private:
    int sideUp;

public:
    Dice();

    Dice(int sideUp);

    int getSideUp();

    void setSideUp(int sideUp);

    void toss();


};

#endif
