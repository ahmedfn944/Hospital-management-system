#pragma once
# ifndef DOCTOR_H
# define DOCTOR_H
#include <iostream>
#include <string>
#include "person.h"
#include "patient.h"
#include "appointment.h"
class Doctor : public Person {
public:
    static const int max_appointments = 20;
    string specialization;
    Appointment* appointments[max_appointments] = { nullptr };

    Doctor(string name, int age, string gender, string email, string password, string specialization) : Person(name, age, gender, email, password)
    {
        this->specialization = specialization;
    }

    void print_doctordetails() {
        print_persondetails();
        cout << "Specialization: " << specialization << endl;
    }

    void add_appointment(Appointment* appointment) {
        for (int i = 0; i < max_appointments; i++) {
            if (appointments[i] == nullptr) {
                appointments[i] = appointment;
                cout << "Appointment added successfully!" << endl;
                return;
            }
        }
        cout << "No available slots for new appointments." << endl;
    }

    void print_appointments() {
        cout << "Appointments for " << name << ":\n";
        for (int i = 0; i < max_appointments; i++) {
            if (appointments[i] != nullptr) {
                appointments[i]->print_appointmentdetails();
            }
        }
    }

    void delete_appointment(int index) {
        if (index >= 0 && index < max_appointments && appointments[index] != nullptr) {
            delete appointments[index];
            appointments[index] = nullptr;
            cout << "Appointment deleted successfully!" << endl;
        }
        else {
            cout << "Invalid appointment index." << endl;
        }
    }
};
#endif
