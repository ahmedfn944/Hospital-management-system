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

string admin_email = "admin@hospital.com";
string admin_password = "admin123";

void book_appointment(Hospital* hospital) {
    int choice;
    cout << "\nBook Appointment Menu:\n";
    cout << "1. New Patient\n";
    cout << "2. Old Patient\n";
    cout << "3. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        string name, gender, email, password, medicalhistory;
        int age;
        string doctor_email, date;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin >> gender;
        cout << "Enter Email: ";
        cin >> email;
        cout << "Enter Password: ";
        cin >> password;
        cout << "Enter Medical History: ";
        cin >> medicalhistory;

        Patient* new_patient = new Patient(name, age, gender, email, password, medicalhistory);
        hospital->add_patient(new_patient);

        cout << "Available Doctors:\n";
        hospital->list_doctors();
        cout << "Enter Doctor's Email for Appointment: ";
        cin >> doctor_email;
        cout << "Enter Appointment Date: ";
        cin >> date;

        for (int i = 0; i < hospital->max_doctors; i++) {
            if (hospital->doctors[i] != nullptr && hospital->doctors[i]->email == doctor_email) {
                Appointment* new_appointment = new Appointment(new_patient, hospital->doctors[i], date);
                hospital->doctors[i]->add_appointment(new_appointment);
                return;
            }
        }
        cout << "Doctor not found!" << endl;
        break;
    }
    case 2: {
        string email, doctor_email, date;
        cout << "Enter Patient's Email: ";
        cin >> email;

        Patient* old_patient = hospital->get_patient_by_email(email);
        if (old_patient == nullptr) {
            cout << "Patient not found!" << endl;
            break;
        }

        cout << "Available Doctors:\n";
        hospital->list_doctors();
        cout << "Enter Doctor's Email for Appointment: ";
        cin >> doctor_email;
        cout << "Enter Appointment Date: ";
        cin >> date;

        for (int i = 0; i < hospital->max_doctors; i++) {
            if (hospital->doctors[i] != nullptr && hospital->doctors[i]->email == doctor_email) {
                Appointment* new_appointment = new Appointment(old_patient, hospital->doctors[i], date);
                hospital->doctors[i]->add_appointment(new_appointment);
                return;
            }
        }
        cout << "Doctor not found!" << endl;
        break;
    }
    case 3:
        return;
    }
}

void admin_menu(Hospital* hospital) {
    int choice;
    do {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add Doctor\n";
        cout << "2. Delete Doctor\n";
        cout << "3. List Doctors\n";
        cout << "4. Logout\n";
        cout << "Enter choice: ";
        
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, gender, email, password, specialization;
            int age;
            cout << "Enter Doctor Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Gender: ";
            cin >> gender;
            cout << "Enter Email: ";
            cin >> email;
            cout << "Enter Password: ";
            cin >> password;
            cout << "Enter Specialization: ";
            cin >> specialization;
            hospital->add_doctor(new Doctor(name, age, gender, email, password, specialization));
            break;
        }
        case 2: {
            int index;
            hospital->list_doctors();
            cout << "Enter Doctor Index to Delete: ";
            cin >> index;
            hospital->doctors[index - 1] = nullptr;
            break;
        }
        case 3:
            hospital->list_doctors();
            break;
        }
    } while (choice != 4);
}

void doctor_menu(Doctor* doctor) {
    int choice;
    do {
        cout << "\nDoctor Menu:\n";
        cout << "1. View Appointments\n";
        cout << "2. Delete Appointment\n";
        cout << "3. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            doctor->print_appointments();
            break;
        case 2: {
            int index;
            doctor->print_appointments();
            cout << "Enter Appointment Index to Delete: ";
            cin >> index;
            doctor->delete_appointment(index - 1);
            break;
        }
        }
    } while (choice != 3);
}

void login(Hospital* hospital) {
    string email, password;
    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter Password: ";
    cin >> password;

    if (email == admin_email && password == admin_password) {
        admin_menu(hospital);
        return;
    }

    for (int i = 0; i < hospital->max_doctors; i++) {
        if (hospital->doctors[i] != nullptr && hospital->doctors[i]->email == email && hospital->doctors[i]->password == password)
        {
            doctor_menu(hospital->doctors[i]);
            return;
        }
    }
    cout << "Invalid credentials!" << endl;
}

int main() {
    Hospital* hospital= new Hospital(" Fucking Harmony Hospital ", " City Branch ", " 123 Street ", " 1234567895 ");
    int choice;

    do {
        cout << "\033[96m ";

        cout << "\n" << hospital->name;
        cout << "\n" << hospital->branch;
        cout << "\n" << hospital->address;
        cout << "\n" << hospital->phonenumber << endl;
        cout << "\033[0m ";

        cout << "\033[95m ";
        cout << "\n" << " - MAIN MENU:\n";
        cout << "\033[0m ";

        cout << "\033[96m ";
        cout << "\n" << "1. Login (Admin/Doctor)\n";
        cout << "2. Book Appointment (Patient)\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cout << "\033[0m ";
        cin >> choice;

        if (choice == 1) {
            login(hospital);
        }
        else if (choice == 2) {
            book_appointment(hospital);
        }
    } while (choice != 3);

    return 0;
}
