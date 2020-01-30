#include<iostream>
#include<string>

using namespace std;

class IColor
{
public:
    virtual string Color() = 0;
};

class RedColor : public IColor
{
public:
    string Color()
    {
        return "of Red Color";
    }
};

class BlueColor : public IColor
{
public:
    string Color()
    {
        return "of Blue Color";
    }
};

class ICarModel
{
public:
    virtual string WhatIsMyType() = 0;
};

class Model_A : public ICarModel
{
    IColor* _myColor;
public:
    Model_A(IColor *obj) :_myColor(obj){}
    string WhatIsMyType()
    {
        return "I am a Model_A " + _myColor->Color();
    }
};

class Model_B : public ICarModel
{
    IColor* _myColor;
public:
    Model_B(IColor *obj) :_myColor(obj){}
    string WhatIsMyType()
    {
        return "I am a Model_B " + _myColor->Color();;
    }
};

class Model_C : public ICarModel
{
    IColor* _myColor;
public:
    Model_C(IColor *obj) :_myColor(obj){}
    string WhatIsMyType()
    {
        return "I am a Model_C " + _myColor->Color();;
    }
};

int main()
{
    IColor* red = new RedColor();
    IColor* blue = new BlueColor();

    ICarModel* modelA = new Model_B(red);
    ICarModel* modelB = new Model_A(blue);
    ICarModel* modelC = new Model_C(blue);


    cout << "\n" << modelA->WhatIsMyType();
    cout << "\n" << modelB->WhatIsMyType();
    cout << "\n" << modelC->WhatIsMyType() << "\n\n";

    delete red;
    delete blue;
    return 1;
}
