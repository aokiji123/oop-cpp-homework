#include <iostream>
#include <vector>
using namespace std;

class Square;
class Circle;
class Rectangle;

class Visitor
{
public:
    virtual void visit(Square & square) = 0;
    virtual void visit(Circle & circle) = 0;
    virtual void visit(Rectangle & rectangle) = 0;
};

class Shape
{
public:
    virtual void accept(Visitor & visitor) = 0;
};

class Square: public Shape
{
private: 
    double mSide;

public: 
    Square(double side): mSide(side) {}

	double area() const
	{
		return mSide * mSide;
	}

	void accept(Visitor & visitor) override
	{
		visitor.visit(*this);
	}

	double getMSide()
	{
		return mSide;
	}
};

class Circle: public Shape
{
private:
    double mRadius;

public: 
    Circle(double radius): mRadius(radius) {}

	double area() const
	{
		return 3.14159265359 *mRadius * mRadius;
	}

	void accept(Visitor & visitor) override
	{
		visitor.visit(*this);
	}

	double getMRadius()
	{
		return mRadius;
	}
};

class Rectangle: public Shape
{
private: 
    double mWidth;
	double mHeight;

public:
    Rectangle(double width, double height): mWidth(width), mHeight(height) {}

	double area() const
	{
		return mWidth * mHeight;
	}

	void accept(Visitor & visitor) override
	{
		visitor.visit(*this);
	}

	double getMWidth()
	{
		return mWidth;
	}

	double getMHeight()
	{
		return mHeight;
	}
};

class PerimeterVisitor: public Visitor
{
private: 
    double mPerimeter = 0.0;

public: 
    void visit(Square & square) override
	{
		mPerimeter += 4 *square.getMSide();
	}

	void visit(Circle & circle) override
	{
		mPerimeter += 2 * 3.14159265359 *circle.getMRadius();
	}

	void visit(Rectangle & rectangle) override
	{
		mPerimeter += 2 *(rectangle.getMWidth() + rectangle.getMHeight());
	}

	double perimeter() const
	{
		return mPerimeter;
	}
};

class DrawVisitor: public Visitor
{
private: 
    void drawSquare(double side)
	{
		int integerSide = (int) side;
		for (int i = 0; i < integerSide; i++)
		{
			for (int j = 0; j < integerSide; j++)
            {
				cout << "*";
            }
			cout << "\n";
		}

		cout << "\n";
		figuresDrawed++;
	}

	void drawCircle(double radius)
	{
		cout << "○" << "\n\n"; // типа круг
		figuresDrawed++;
	}

	void drawRectangle(double width, double height)
	{
		int integerWidth = (int) width;
		int integerHeight = (int) height;
		for (int i = 0; i < integerHeight; i++)
		{
			for (int j = 0; j < integerWidth; j++)
            {
				cout << "*";
            }
			cout << "\n";
		}

		cout << "\n";
		figuresDrawed++;
	}

	static int figuresDrawed;

public: 
    void visit(Square & square) override
	{
		drawSquare(square.getMSide());
	}

	void visit(Circle & circle) override
	{
		drawCircle(circle.getMRadius());
	}

	void visit(Rectangle & rectangle) override
	{
		drawRectangle(rectangle.getMWidth(), rectangle.getMHeight());
	}

	int getCountOfDrawedFigures()
	{
		return figuresDrawed;
	}
};

int DrawVisitor::figuresDrawed = 0;

int main()
{
	vector<Shape*> shapes = { 
        new Square(4), new Circle(2), new Rectangle(2, 9)
	};

	PerimeterVisitor perimeterVisitor;
	DrawVisitor drawVisitor;

	for (auto shape: shapes)
	{
		shape->accept(perimeterVisitor);
		shape->accept(drawVisitor);
	}

	cout << "Perimeter: " << perimeterVisitor.perimeter() << "\n";
    cout << "Figures Drawed: " << drawVisitor.getCountOfDrawedFigures() << "\n";

	for (auto shape: shapes)
    {
		delete shape;
    }
}