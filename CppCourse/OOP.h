#ifndef OOP_H
#define OOP_H

#include <iostream>
#include <string>

namespace OOP {

    // Base abstract class for shapes.
    class Shape {
    private:
        std::string color;
    public:
        Shape();
        Shape(const std::string& col);
        std::string getColor() const;
        void setColor(const std::string& col);
        virtual double area() const = 0;
        void display() const;
        void display(const std::string& msg) const;
        virtual ~Shape();
    };

    // Derived class: Rectangle.
    class Rectangle : public Shape {
    private:
        double width;
        double height;
    public:
        Rectangle(double w, double h, const std::string& col = "Red");
        double area() const override;
        void display() const;
    };

    // Derived class: Circle.
    class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(double r, const std::string& col = "Blue");
        double area() const override;
        void display() const;
    };

    // Person class.
    class Person {
    private:
        std::string name;
        int age;
    public:
        Person();
        Person(const std::string& n, int a);
        Person(const Person& other);
        Person(Person&& other) noexcept;
        Person& operator=(const Person& other);
        Person& operator=(Person&& other) noexcept;
        ~Person();

        bool operator==(const Person& other) const;
        bool operator!=(const Person& other) const;
        bool operator<(const Person& other) const;
        bool operator<=(const Person& other) const;
        bool operator>(const Person& other) const;
        bool operator>=(const Person& other) const;

        void operator()() const;
        Person operator+(const Person& other) const;
        char operator[](size_t index) const;

        friend std::ostream& operator<<(std::ostream& os, const Person& p);
        friend std::istream& operator>>(std::istream& is, Person& p);
    };

    void run();
}

#endif // OOP_H
#pragma once
