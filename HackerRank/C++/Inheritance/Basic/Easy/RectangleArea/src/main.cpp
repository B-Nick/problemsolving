#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */

class Rectangle
{
public:
    Rectangle() = default;
    Rectangle(const Rectangle &_other) = default;
    Rectangle(Rectangle &&_other) = default;

    virtual ~Rectangle() = default;

    Rectangle &operator= (const Rectangle &_other) = default;
    Rectangle &operator= (Rectangle &&_other) = default;

    virtual void display() const
    {
        std::cout << i_width << " " << i_height << std::endl;
    }

protected:
    int i_width {0};
    int i_height {0};
};

class RectangleArea final : public Rectangle
{
public:
    RectangleArea() = default;
    RectangleArea(const RectangleArea &_other) = default;
    RectangleArea(RectangleArea &&_other) = default;

    virtual ~RectangleArea() override final = default;

    RectangleArea &operator= (const RectangleArea &_other) = default;
    RectangleArea &operator= (RectangleArea &&_other) = default;

    void read_input()
    {
        int w, h;
        std::cin >> w >> h;

        if (w < 1 || w > 100) throw std::invalid_argument("Invalid width");
        if (h < 1 || h > 100) throw std::invalid_argument("Invalid height");

        i_width = w;
        i_height = h;
    }

    virtual void display() const override final
    {
        std::cout << i_width * i_height <<std::endl;
    }
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();

    /*
     * Print the width and height
     */
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();

    return 0;
}
