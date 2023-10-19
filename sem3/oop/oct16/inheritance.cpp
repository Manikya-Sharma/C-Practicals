#include <iostream>
using namespace std;

class Parent
{
private:
    void ParentPrivateFunction() { cout << "Parent private function" << endl; }

protected:
    void ParentProtectedFunction()
    {
        cout << "Parent protected function" << endl;
    }

public:
    void ParentPublicFunction() { cout << "Parent public function" << endl; }
};

class PublicChild : public Parent
{
private:
    void PublicChildPrivateFunction()
    {
        cout << "PublicChildPrivateFunction called" << endl;
    }

protected:
    void PublicChildProtectedFunction()
    {
        cout << "PublicChildProtectedFunction called" << endl;
    }

public:
    void PublicChildPublicFunction()
    {
        cout << "PublicChildPublicFunction called" << endl;
    }
};

class ProtectedChild : protected Parent
{
private:
    void ProtectedChildPrivateFunction()
    {
        cout << "ProtectedChildPrivateFunction called" << endl;
    }

protected:
    void ProtectedChildProtectedFunction()
    {
        cout << "ProtectedChildProtectedFunction called" << endl;
    }

public:
    void ProtectedChildPublicFunction()
    {
        cout << "ProtectedChildPublicFunction called" << endl;
    }
};

class PrivateChild : Parent
{
private:
    void PrivateChildPrivateFunction()
    {
        cout << "PrivateChildPrivateFunction called" << endl;
    }

protected:
    void PrivateChildProtectedFunction()
    {
        cout << "PrivateChildProtectedFunction called" << endl;
    }

public:
    void PrivateChildPublicFunction()
    {
        cout << "PrivateChildPublicFunction called" << endl;
    }
};

class ChildOfPublicChild : public PublicChild
{
public:
    void CallFns()
    {

        // ParentPrivateFunction(); // not allowed
        ParentProtectedFunction();
        ParentPublicFunction();

        // PublicChildPrivateFunction(); // not allowed
        PublicChildProtectedFunction();
        PublicChildPublicFunction();
    }
};

class ChildOfProtectedChild : public ProtectedChild
{
public:
    void CallFns()
    {

        // ParentPrivateFunction(); // not allowed
        ParentProtectedFunction();
        ParentPublicFunction();

        // ProtectedChildPrivateFunction(); // not allowed
        ProtectedChildProtectedFunction();
        ProtectedChildPublicFunction(); // allowed here but not outside
    }
};

class ChildOfPrivateChild : public PrivateChild
{
public:
    void CallFns()
    {

        // ParentPrivateFunction();   // not allowed
        // ParentProtectedFunction(); // not allowed
        // ParentPublicFunction();    // not allowed

        // PrivateChildPrivateFunction(); // not allowed
        PrivateChildProtectedFunction();
        PrivateChildPublicFunction();
    }
};

int main()
{

    ChildOfPublicChild cp1;
    ChildOfProtectedChild cp2;
    ChildOfPrivateChild cp3;

    // cp1.ParentPrivateFunction();   // not allowed
    // cp1.ParentProtectedFunction(); // not allowed
    cp1.ParentPublicFunction();

    // cp2.ParentPrivateFunction();   // not allowed
    // cp2.ParentProtectedFunction(); // not allowed
    // cp2.ParentPublicFunction();    // not allowed

    // cp3.ParentPrivateFunction();   // not allowed
    // cp3.ParentProtectedFunction(); // not allowed
    // cp3.ParentPublicFunction();    // not allowed

    return 0;
}