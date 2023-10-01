#include <iostream>
using namespace std;

class Parent {
  private:
    int private_parent_a;

  public:
    class Child {
      private:
        int private_child_a;
        int private_child_b;

      public:
        Child()
            : public_child_a(0), private_child_a(0), private_child_b(0),
              public_child_b(0)
        {
            Parent pt(5);
            cout << "My parent: " << pt.private_parent_a << endl;
        }
        int public_child_a;
        int public_child_b;
    };
    Parent() : private_parent_a(0), public_parent_a(0), public_parent_b(0)
    {
        Child ch;
        cout << "Child's public data: " << ch.public_child_a << endl;
    }
    Parent(int dummy) {}
    int public_parent_a;
    int public_parent_b;
};

int main()
{
    Parent pt;
    cout << pt.public_parent_a << endl;
    return 0;
}