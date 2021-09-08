#ifndef _STUDENTS
#define _STUDENTS 1

#include <iostream>
#include <string>

class student
{
private:
    std::string name;
    float grade;
public:
    student(std::string name, float grade);
};

student::student(std::string name, float grade)
{
    this->name = name;
    this->grade = grade;
}

#endif