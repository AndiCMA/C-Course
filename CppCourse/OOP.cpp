#include <iostream>
#include <string>
using namespace std;

namespace OOP {

    // Base abstract class demonstrating encapsulation,
    // inheritance, polymorphism, and function overloading.
    class Shape {
    private:
        string color; // Encapsulated member variable.
    public:
        // Constructors.
        Shape() : color("undefined") {}
        Shape(const string& col) : color(col) {}

        // Getter and setter for color (encapsulation).
        string getColor() const { return color; }
        void setColor(const string& col) { color = col; }

        // Pure virtual function: every derived shape must implement its own area.
        virtual double area() const = 0;

        // Overloaded display methods (function overloading).
        void display() const {
            cout << "A " << color << " shape." << endl;
        }
        void display(const string& msg) const {
            cout << msg << " A " << color << " shape." << endl;
        }

        // Virtual destructor to ensure proper cleanup of derived classes.
        virtual ~Shape() {}
    };

    // Derived class: Rectangle.
    class Rectangle : public Shape {
    private:
        double width;
        double height;
    public:
        // Constructor using initializer list (inheritance & encapsulation).
        Rectangle(double w, double h, const string& col = "Red")
            : Shape(col), width(w), height(h) {
        }

        // Overridden area method demonstrating dynamic polymorphism.
        double area() const override {
            return width * height;
        }

        // Overloaded display specific to Rectangle.
        void display() const {
            cout << "Rectangle: Color = " << getColor()
                << ", Width = " << width
                << ", Height = " << height
                << ", Area = " << area() << endl;
        }
    };

    // Derived class: Circle.
    class Circle : public Shape {
    private:
        double radius;
    public:
        // Constructor using initializer list.
        Circle(double r, const string& col = "Blue")
            : Shape(col), radius(r) {
        }

        // Overridden area method.
        double area() const override {
            return 3.14159 * radius * radius;
        }

        // Overloaded display specific to Circle.
        void display() const {
            cout << "Circle: Color = " << getColor()
                << ", Radius = " << radius
                << ", Area = " << area() << endl;
        }
    };

    class Person {
    private:
        std::string name;
        int age;
    public:
        // Default constructor
        Person() : name("Unknown"), age(0) {}

        // Parameterized constructor
        Person(const std::string& n, int a) : name(n), age(a) {}

        // Copy constructor
        Person(const Person& other) : name(other.name), age(other.age) {}

        // Move constructor
        Person(Person&& other) noexcept : name(std::move(other.name)), age(other.age) {
            other.age = 0;
        }

        // Copy assignment operator
        Person& operator=(const Person& other) {
            if (this != &other) { name = other.name; age = other.age; }
            return *this;
        }

        // Move assignment operator
        Person& operator=(Person&& other) noexcept {
            if (this != &other) { name = std::move(other.name); age = other.age; other.age = 0; }
            return *this;
        }

        // Destructor
        ~Person() {}

        // Comparison operators
        bool operator==(const Person& other) const { return name == other.name && age == other.age; }
        bool operator!=(const Person& other) const { return !(*this == other); }
        bool operator<(const Person& other) const {
            return (age != other.age) ? age < other.age : name < other.name;
        }
        bool operator<=(const Person& other) const { return (*this < other) || (*this == other); }
        bool operator>(const Person& other) const { return !(*this <= other); }
        bool operator>=(const Person& other) const { return !(*this < other); }

        // Overload operator() to print details
        void operator()() const { cout << "Person: " << name << ", Age: " << age << endl; }

        // Overload operator+ to combine two Persons (concatenate names and average age)
        Person operator+(const Person& other) const {
            return Person(name + "-" + other.name, (age + other.age) / 2);
        }

        // Overload operator[] to access characters in the name
        char operator[](size_t index) const {
            if (index < name.size()) return name[index];
            throw std::out_of_range("Index out of range");
        }

        // Friend stream insertion operator
        friend std::ostream& operator<<(std::ostream& os, const Person& p) {
            os << "Person(Name: " << p.name << ", Age: " << p.age << ")";
            return os;
        }

        // Friend stream extraction operator
        friend std::istream& operator>>(std::istream& is, Person& p) {
            is >> p.name >> p.age;
            return is;
        }
    };

    // Function Overloading: Multiple 'add' functions demonstrating static polymorphism.
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Function demonstrating all OOP concepts:
    // encapsulation, inheritance, polymorphism, overloading, virtual functions.
    void run() {
        cout << "\n=== OOP Concepts Demo ===" << endl;

        // Create objects of derived classes.
        Rectangle rect(4, 5, "Green");
        Circle circ(3, "Yellow");

        // Encapsulation: Access private data via getters.
        cout << "Rectangle color: " << rect.getColor() << endl;
        cout << "Circle color: " << circ.getColor() << endl;

        // Polymorphism: Calling the derived class's display methods.
        rect.display();
        circ.display();

        // Dynamic polymorphism using base class pointers.
        Shape* shapes[2];
        shapes[0] = new Rectangle(2, 3, "Purple");
        shapes[1] = new Circle(4, "Orange");

        for (int i = 0; i < 2; ++i) {
            // Using the overloaded display function from the base class.
            shapes[i]->display("Base class call:");
            cout << "Area computed polymorphically: " << shapes[i]->area() << endl;
        }

        // Clean up dynamically allocated memory.
        for (int i = 0; i < 2; ++i) {
            delete shapes[i];
        }

        // Demonstrate overloading

        Person p1("Alice", 30), p2("Bob", 25);
        cout << p1 << endl;  // operator<<
        p1();                // operator()
        if (p1 != p2) cout << "Different persons." << endl;
        Person p3 = p1 + p2; // operator+
        cout << "Combined: " << p3 << endl;
        try {
            cout << "First char of p1's name: " << p1[0] << endl;
        }
        catch (const std::exception& e) {
            cout << e.what() << endl;

            // Demonstrate function overloading.
            cout << "Overloaded add (int, int): " << add(3, 4) << endl;
            cout << "Overloaded add (double, double): " << add(3.5, 2.5) << endl;
            cout << "Overloaded add (int, int, int): " << add(1, 2, 3) << endl;
        }

    }
}
