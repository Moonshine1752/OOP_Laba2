#include <iostream>
#include <cmath>

using namespace std;

class Sphere
{
private:
    double radius;

public:
    Sphere()
    {
        radius = 0;
    }

    Sphere(double r)
    {
        radius = r;
    }

    double getRadius()
    {
        return radius;
    }

    void setRadius(double r)
    {
        radius = r;
    }

    double getVolume()
    {
        return (4.0/3.0) * 3.14 * pow(radius, 3);
    }

    void print_val()
    {
        cout << "Radius: " << radius << endl;
        cout << "Volume: " << getVolume() << endl<< endl;
    }

    friend Sphere frd(Sphere s1, Sphere s2)
    {
        double newRadius = pow((3.0/(4.0 * 3.14) * (s1.getVolume() + s2.getVolume())), (1.0/3.0));

        Sphere newSphere(newRadius);
        return newSphere;
    }
};

int main()
{
    Sphere s1(4.5);
    Sphere s2(2.7);
    s1.print_val();
    s2.print_val();
    Sphere s3 = frd(s1, s2);
    s3.print_val();
    return 0;
}
