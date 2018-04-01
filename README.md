#Calf
##Brief
Calf is a library which allows "dynamic class creation" in C++, simply, one could create an instance with a given type in string, generally, this can be used with factory pattern and make it more convenient and elegant.
##Examples

Let's use the classic Shape example, say, I've a Shape base class defining the supported interfaces of each concrete shape class
the source file layout is
```
.
`-- shape
    |-- ShapeFactory.hpp
    |-- Shape.hpp
    `-- shapes
        `-- Circle.hpp
```
content of Shape defines the needed interfaces each inhreited class shall realize.
```
class Shape
{
public:
    virtual void name() = 0;
};
```
A concrete class, Circle is created from Shape.
```
class Circle : public Shape
{
public:
    void name()
    {
        cout << "this is Circle" << endl;
    }
};
```
now, I'd add the class Circle with dynamic class characteristic, the only needed thing is just add 2 lines of code, then the Circle.hpp becomes
```
#include "Calf.hpp"

CALF_CLASS(Circle);
class Circle : public Shape
{
public:
    void name()
    {
        cout << "this is Circle" << endl;
    }
};
```
ok, if I'd create an instance from Circle, what I need to do is just
```
#include "Calf.hpp"
#include "Shape.hpp"
int main()
{
    Shape* s = Calf::create<Shape>("Circle");
    s->name();
    delete s;
    return 0;
}

```
A nicer way is to create a ShapeFactory for instanciation. so the ShapeFactory.hpp would be
```
#include "Calr.hpp"
#include "Shape.hpp"
class ShapeFactory
{
public:
    static Shape* create(string& name)
    {
        return Calf::create<Shape>(name);
    }
    static void release(Shape* s)
    {
        delete s;
    }
};
```
so the Circle creation snippet becomes
```
#include "ShapeFactory.hpp"
int main()
{
    Shape* s = ShapeFactory::create("Circle");
    s->name();
    ShapeFactory::release(s);
    return 0;
}
```
See, nice, right? :D
