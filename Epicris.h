#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;

public ref class Epicris
{
public:
	Epicris();
	~Epicris();
    
// property items
    property String^ HistoryNumber {
        void set(String^ value) {
            historyNumber = value;
        }
        String^ get() {
            return historyNumber;
        }
    }
    property String^ HistoryYear {
        void set(String^ value) {
            historyYear = value;
        }
        String^ get() {
            return historyYear;
        }
    }
    property String^ Name {
        void set(String^ value) {
            name = value;
        }
        String^ get() {
            return name;
        }
    }
    property String^ Surname {
        void set(String^ value) {
            surname = value;
        }
        String^ get() {
            return surname;
        }
    }
    property String^ Patronymic {
        void set(String^ value) {
            patronymic = value;
        }
        String^ get() {
            return patronymic;
        }
    }
    property String^ Rank {
        void set(String^ value) {
            rank = value;
        }
        String^ get() {
            return rank;
        }
    }
    property String^ MilitaryUnit {
        void set(String^ value) {
            militaryUnit = value;
        }
        String^ get() {
            return militaryUnit;
        }
    }
    property String^ Birthday {
        void set(String^ value) {
            birthday = value;
        }
        String^ get() {
            return birthday;
        }
    }
    property String^ IncomeDate {
        void set(String^ value) {
            incomeDate = value;
        }
        String^ get() {
            return incomeDate;
        }
    }
    property String^ OutcomeDate {
        void set(String^ value) {
            outcomeDate = value;
        }
        String^ get() {
            return outcomeDate;
        }
    }
    property String^ Mkb {
        void set(String^ value) {
            mkb = value;
        }
        String^ get() {
            return mkb;
        }
    }
    property String^ Diagnosis {
        void set(String^ value) {
            diagnosis = value;
        }
        String^ get() {
            return diagnosis;
        }
    }
    property String^ RelatedDiagnosis {
        void set(String^ value) {
            relatedDiagnosis = value;
        }
        String^ get() {
            return relatedDiagnosis;
        }
    }
    property String^ Complications {
        void set(String^ value) {
            complications = value;
        }
        String^ get() {
            return complications;
        }
    }
    property String^ AnamnesisJson {
        void set(String^ value) {
            anamnesisJson = value;
        }
        String^ get() {
            return anamnesisJson;
        }
    }
    property String^ AnamnesisText {
        void set(String^ value) {
            anamnesisText = value;
        }
        String^ get() {
            return anamnesisText;
        }
    }
    property String^ Analyzes {
        void set(String^ value) {
            analyzes = value;
        }
        String^ get() {
            return analyzes;
        }
    }
    property String^ AdditionalData {
        void set(String^ value) {
            additionalData = value;
        }
        String^ get() {
            return additionalData;
        }
    }
    property String^ Therapy {
        void set(String^ value) {
            therapy = value;
        }
        String^ get() {
            return therapy;
        }
    }
    property String^ DoctorsLooked {
        void set(String^ value) {
            doctorsLooked = value;
        }
        String^ get() {
            return doctorsLooked;
        }
    }
    property String^ SideData {
        void set(String^ value) {
            sideData = value;
        }
        String^ get() {
            return sideData;
        }
    }
    property String^ Recommendations {
        void set(String^ value) {
            recommendations = value;
        }
        String^ get() {
            return recommendations;
        }
    }
    property String^ UnworkableList {
        void set(String^ value) {
            unworkableList = value;
        }
        String^ get() {
            return unworkableList;
        }
    }

private:
    String^ historyNumber;
    String^ historyYear;
    String^ name;
    String^ surname;
    String^ patronymic;
    String^ rank;
    String^ militaryUnit;
    String^ birthday;
    String^ incomeDate;
    String^ outcomeDate;
    String^ mkb;
    String^ diagnosis;
    String^ relatedDiagnosis;
    String^ complications;
    String^ anamnesisJson;
    String^ anamnesisText;
    String^ analyzes;
    String^ additionalData;
    String^ therapy;
    String^ doctorsLooked;
    String^ sideData;
    String^ recommendations;
    String^ unworkableList;
};

