#ifndef COUPLE_H
#define COUPLE_H
#include <string>
using namespace std;

class Girls;

class Boys{
private:
    string name;

public:
    Boys(string nm);
    void IntroduceOneself();
    void IntroduceFriend(Girls &x);
};

class Girls{
private:
    string name;

public:
    Girls(string nm);
    void IntroduceOneself();
    //friend class Boys;
    friend void Boys::IntroduceFriend(Girls &x);
};

#endif // COUPLE_H
