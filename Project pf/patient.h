#pragma once
#include <iostream>
#include <string>
#include "person.h"
using namespace std;

class Patient : public Person {
public:
    string medicalhistory;
    Patient(string name, int age, string gender, string email, string password, string medicalhistory) : Person(name, age, gender, email, password)
    {
        this->medicalhistory = medicalhistory;

    }

    void print_patientdetails() {
        print_persondetails();
        cout << "Medical History: " << medicalhistory << endl;
    }
};
