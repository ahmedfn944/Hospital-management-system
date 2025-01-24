#pragma once
# ifndef APPOINTMENT_H
# define APPOINTMENT_H
#include <iostream>
#include <string>
#include "person.h"
#include "patient.h"
#include "doctor.h"
using namespace std;
class Doctor;
class Appointment {
public:
    Patient* patient;
    Doctor* doctor;
    string date;

    Appointment(Patient* patient, Doctor* doctor, string date) {
        this->patient = patient;
        this->doctor = doctor;
        this->date = date;
    }

    void print_appointmentdetails() {
        cout << "Appointment Details:\n";
        cout << "Date: " << date << endl;
        cout << "Patient: " << patient->name << " (" << patient->medicalhistory << ")" << endl;
    }
};
#endif