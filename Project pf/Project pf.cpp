#include<iostream>
using namespace std;

class Person {
public:
    string name;
    int age;
    string gender;
    Person(string name, int age, string gender) {
        this->name = name;
        this->age = age;
        this->gender = gender;
    }
    void print_persondetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

class Patient : public Person {
public:
    string medicalhistory;
    Patient(string name, int age, string gender, string medicalhistory) : Person(name, age, gender) {
        this->medicalhistory = medicalhistory;
    }
    void print_patientdetails() {
        print_persondetails();
        cout << "Medical History: " << medicalhistory << endl;
    }
};

class Admin : public Person {
public:
    string role;
    Admin(string name, int age, string gender, string role) : Person(name, age, gender) {
        this->role = role;
    }
    void print_admindetails() {
        print_persondetails();
        cout << "Role: " << role << endl;
    }
};


class Appointment {
public:
    Patient* patient;
    /*Doctor* doctor;*/
    string date;

    Appointment(Patient* patient, string date) {
        this->patient = patient;
        this->date = date;
    }

    void print_appointmentdetails() {
        cout << "Appointment Details:" << endl;
        cout << "Date: " << date << endl;
        cout << "Patient: " << patient->name << " (" << patient->medicalhistory << ")" << endl;
    }
};

class Doctor : public Person {
public:
    string specialization;
    int max_appointments = 20;
    Appointment* appointments[20] = { nullptr };

    Doctor(string name, int age, string gender, string specialization) : Person(name, age, gender) {
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
                break;
            }
        }
    }

    void edit_appointment(int index, string new_date) {
        if (index >= 0 && index < max_appointments && appointments[index] != nullptr) {
            appointments[index]->date = new_date;
            cout << "Appointment updated successfully!" << endl;
        }
        else {
            cout << "Invalid appointment index." << endl;
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

    void print_appointment() {
        for (int i = 0; i < max_appointments; i++) {
            if (appointments[i] != nullptr) {
                appointments[i]->print_appointmentdetails();
            }
            
        }
    }
};



class Hospital {
public:
    string name;
    string branch;
    string address;
    string phonenumber;
    int max_doctors = 10;
    Doctor* doctors[10] = { nullptr };

    Hospital(string name, string branch, string address, string phonenumber) {
        this->name = name;
        this->branch = branch;
        this->address = address;
        this->phonenumber = phonenumber;
    }

    void add_doctor(Doctor* doctor) {
        for (int i = 0; i < max_doctors; i++) {
            if (doctors[i] == nullptr) {
                doctors[i] = doctor;
                break;
            }
        }
    }

    void edit_doctor(int index, string new_name, int new_age, string new_gender, string new_specialization) {
        if (index >= 0 && index < max_doctors && doctors[index] != nullptr) {
            doctors[index]->name = new_name;
            doctors[index]->age = new_age;
            doctors[index]->gender = new_gender;
            doctors[index]->specialization = new_specialization;
            cout << "Doctor updated successfully!" << endl;
        }
        else {
            cout << "Invalid doctor index." << endl;
        }
    }

    void delete_doctor(int index) {
        if (index >= 0 && index < max_doctors && doctors[index] != nullptr) {
            delete doctors[index];
            doctors[index] = nullptr;
            cout << "Doctor deleted successfully!" << endl;
        }
        else {
            cout << "Invalid doctor index." << endl;
        }
    }

    void print_hospitaldetails() {
        cout << "Hospital Name: " << name << endl;
        cout << "Branch Name: " << branch << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phonenumber << endl;

        cout << "\nDoctors List:" << endl;
        for (int i = 0; i < max_doctors; i++) {
            if (doctors[i] != nullptr) {
                cout << "Doctor " << i + 1 << ":" << endl;
                doctors[i]->print_doctordetails();
                cout << endl;
            }
        }
    }
};

int main() {
    Hospital h("Evercare", "City Branch", "123 Street", "1234567895");
    Doctor* d1 = new Doctor("Dr. Ayub", 60, "Male", "MBBS ACPS");
    Doctor* d2 = new Doctor("Dr. Farzana", 55, "Female", "Dermatologist");
    h.add_doctor(d1);
    h.add_doctor(d2);

    Patient* p1 = new Patient("Moazam", 20, "Male", "Allergy");
    Patient* p2 = new Patient("Sarah", 25, "Female", "Diabetes");

    Appointment* a1 = new Appointment(p1, "2025-01-20");
    Appointment* a2 = new Appointment(p2, "2025-01-22");

    d1->add_appointment(a1);  
    d1->add_appointment(a2);
    d1->delete_appointment(0);

    d1->print_appointment();


   

    return 0;
}
