#pragma once
#include <iostream>
#include <string>
#include "person.h"
#include "patient.h"
#include "doctor.h"

using namespace std;
class Hospital {
public:
    static const int max_doctors = 10;
    static const int max_patients = 50;
    string name;
    string branch;
    string address;
    string phonenumber;
    Doctor* doctors[max_doctors] = { nullptr };
    Patient* patients[max_patients] = { nullptr };

    Hospital(string name, string branch, string address, string phonenumber)
    {
        this->name = name;
        this->branch = branch;
        this->address = address;
        this->phonenumber = phonenumber;
    }

    void add_doctor(Doctor* doctor) {
        for (int i = 0; i < max_doctors; i++) {
            if (doctors[i] == nullptr) {
                doctors[i] = doctor;
                cout << "Doctor added successfully!" << endl;
                return;
            }
        }
        cout << "No space for more doctors." << endl;
    }

    void add_patient(Patient* patient) {
        for (int i = 0; i < max_patients; i++) {
            if (patients[i] == nullptr) {
                patients[i] = patient;
                cout << "Patient added successfully!" << endl;
                return;
            }
        }
        cout << "No space for more patients." << endl;
    }

    Patient* get_patient_by_email(string email) {
        for (int i = 0; i < max_patients; i++) {
            if (patients[i] != nullptr && patients[i]->email == email) {
                return patients[i];
            }
        }
        return nullptr;
    }

    void list_doctors() {
        cout << "\nDoctors List:\n";
        for (int i = 0; i < max_doctors; i++) {
            if (doctors[i] != nullptr) {
                cout << "Doctor " << i + 1 << ":\n";
                doctors[i]->print_doctordetails();
                cout << endl;
            }
        }
    }
};