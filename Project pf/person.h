# pragma once
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;
    string gender;
    string email;
    string password;

    Person(string name, int age, string gender, string email, string password) {
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->email = email;
        this->password = password;
    }

    void print_persondetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Email: " << email << endl;
    }
};