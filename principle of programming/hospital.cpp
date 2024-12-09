#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string illness;
    bool isAdmitted;

    Patient(int patientId, string patientName, int patientAge, string patientIllness, bool admitted = false)
        : id(patientId), name(patientName), age(patientAge), illness(patientIllness), isAdmitted(admitted) {}

    void displayDetails() {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Age: " << age
             << " | Illness: " << illness
             << " | Status: " << (isAdmitted ? "Admitted" : "Discharged") << endl;
    }
};

class Doctor {
public:
    int id;
    string name;
    string specialization;

    Doctor(int doctorId, string doctorName, string doctorSpecialization)
        : id(doctorId), name(doctorName), specialization(doctorSpecialization) {}

    void displayDetails() {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Specialization: " << specialization << endl;
    }
};

class HospitalManagementSystem {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    int nextPatientId;
    int nextDoctorId;

public:
    HospitalManagementSystem() : nextPatientId(1), nextDoctorId(1) {}

    void addPatient(string name, int age, string illness) {
        patients.push_back(Patient(nextPatientId, name, age, illness, true));
        cout << "Patient added with ID: " << nextPatientId << endl;
        nextPatientId++;
    }

    void addDoctor(string name, string specialization) {
        doctors.push_back(Doctor(nextDoctorId, name, specialization));
        cout << "Doctor added with ID: " << nextDoctorId << endl;
        nextDoctorId++;
    }

    void displayPatients() {
        if (patients.empty()) {
            cout << "No patients in the hospital.\n";
            return;
        }
        for (auto& patient : patients) {
            patient.displayDetails();
        }
    }

    void displayDoctors() {
        if (doctors.empty()) {
            cout << "No doctors in the hospital.\n";
            return;
        }
        for (auto& doctor : doctors) {
            doctor.displayDetails();
        }
    }

    void dischargePatient(int patientId) {
        for (auto& patient : patients) {
            if (patient.id == patientId) {
                if (!patient.isAdmitted) {
                    cout << "Patient with ID " << patientId << " is already discharged.\n";
                    return;
                }
                patient.isAdmitted = false;
                cout << "Patient with ID " << patientId << " has been discharged.\n";
                return;
            }
        }
        cout << "Patient with ID " << patientId << " not found.\n";
    }
};

int main() {
    HospitalManagementSystem hms;
    int choice, id, age;
    string name, illness, specialization;

    while (true) {
        cout << "\nHospital Management System Menu\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. Display Patients\n";
        cout << "4. Display Doctors\n";
        cout << "5. Discharge Patient\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Patient Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Patient Age: ";
            cin >> age;
            cout << "Enter Illness: ";
            cin.ignore();
            getline(cin, illness);
            hms.addPatient(name, age, illness);
            break;

        case 2:
            cout << "Enter Doctor Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Specialization: ";
            getline(cin, specialization);
            hms.addDoctor(name, specialization);
            break;

        case 3:
            hms.displayPatients();
            break;

        case 4:
            hms.displayDoctors();
            break;

        case 5:
            cout << "Enter Patient ID to Discharge: ";
            cin >> id;
            hms.dischargePatient(id);
            break;

        case 6:
            cout << "Exiting system.\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
