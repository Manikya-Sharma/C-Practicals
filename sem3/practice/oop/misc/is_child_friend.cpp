#include <iostream>
using namespace std;

class BaseFriend;
class Base
{
    int priv;

public:
    Base(int x) { priv = x; }
    friend BaseFriend;
};

class Child;
class BaseFriend
{
public:
    void myFriendsData(Base b) { cout << "data:" << b.priv << endl; }
    void FriendChildData(Child);
};
class Child : public Base
{
    int child_priv;
};
void BaseFriend::FriendChildData(Child ch)
{
    cout << "I can access " << ch.priv << endl;
    cout << "I can't access provite data solely belonging to child (child_priv)"
         << endl;
}
