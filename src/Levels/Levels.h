#include "../stdafx/stdafx.h"
#include "../Bonus/Bonus.h"

class Levels
{
private:
    std::string label;
    std::vector<Bonus> bones;
public:
    Levels(std::string label);
    ~Levels();
};


