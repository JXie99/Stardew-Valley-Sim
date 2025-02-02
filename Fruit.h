#ifndef PROJ4_FRUIT_H
#define PROJ4_FRUIT_H
#include <string>
using namespace std;

class Fruit {
public:

    // Name: Fruit
    // Desc: Creates a fruit with a color
    // Preconditions:  None
    // Postconditions: A fruit is created that is red (cannot access the color anyway)
    Fruit();

private:
    string m_color;
};

#endif //PROJ4_FRUIT_H
