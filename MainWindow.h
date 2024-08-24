#pragma once
#include "DB_HelperWrapper.h"

namespace unsaintedWinApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
            dbPath = "prod.db";
            dbHelperWrapper = gcnew DB_HelperWrapper(dbPath);
            FillComboBox(Names_comboBox,"firstNames", "value");

			//
			//TODO: добавьте код конструктора
			//           

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
    private:
        String^ dbPath;
        DB_HelperWrapper^ dbHelperWrapper;
        
    public:       
        String^ IllBeginingDate;
        String^ ResponseDate;
        String^ GospitalSentDate;
        String^ Desease;
        String^ MedOrganizationToResponse;
        String^ MedOrganizationToSend;
        String^ MedicalResearchDate;
        String^ ResearchType = "ФОГК";
        String^ RepeatCheckDate;
        bool Gospitalization = true;
        String^ SanaciyaPolostyRta;
        String^ HealingString;
        String^ OsmotrenString;
        String^ RecomendationString;
        int counter = 0;
        int researchCounter = 1;

	private: System::Windows::Forms::ToolStripContainer^ toolStripContainer1;
	private: System::Windows::Forms::Button^ history_button;
	private: System::Windows::Forms::Panel^ Home_panel;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
    private: System::Windows::Forms::Button^ Hitory_button;
    private: System::Windows::Forms::Button^ epicrisis_button;
    private: System::Windows::Forms::Button^ doctors_notes_button;
    private: System::Windows::Forms::Button^ f1_button;
    private: System::Windows::Forms::Panel^ Epicrisis_panel;
    private: System::Windows::Forms::Button^ BackToHome_button;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel9;
    private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
    private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
    private: System::Windows::Forms::Label^ ID_label;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Button^ Clear_button;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel10;
    private: System::Windows::Forms::GroupBox^ groupBox11;
    private: System::Windows::Forms::GroupBox^ groupBox10;
    private: System::Windows::Forms::GroupBox^ groupBox9;
    private: System::Windows::Forms::GroupBox^ groupBox8;
    private: System::Windows::Forms::GroupBox^ groupBox7;
    private: System::Windows::Forms::GroupBox^ groupBox6;
    private: System::Windows::Forms::TableLayoutPanel^ EpiricisisTabMenu_tableLayoutPanel;
    private: System::Windows::Forms::Button^ AnalysisResults_button;
    private: System::Windows::Forms::Button^ UnworkableList_button;
    private: System::Windows::Forms::Label^ lastLabel;
    private: System::Windows::Forms::Button^ Anamnesis_button;
    private: System::Windows::Forms::Button^ IllHistory_button;
    private: System::Windows::Forms::Button^ Stamp_button;
    private: System::Windows::Forms::Button^ AddingInfo_button;
    private: System::Windows::Forms::Button^ SideInfo_button;
    private: System::Windows::Forms::Button^ Recomendations_button;
    private: System::Windows::Forms::Panel^ Ill_History_panel;
    private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
    private: System::Windows::Forms::GroupBox^ groupBox13;
    private: System::Windows::Forms::GroupBox^ groupBox12;
    private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
    private: System::Windows::Forms::GroupBox^ MKB_groupBox;
    private: System::Windows::Forms::GroupBox^ groupBox14;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::GroupBox^ groupBox16;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::GroupBox^ groupBox15;
    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::Button^ F3_button;
    private: System::Windows::Forms::DateTimePicker^ dateTimePicker3;
    private: System::Windows::Forms::ComboBox^ comboBox3;
    private: System::Windows::Forms::ComboBox^ comboBox2;
    private: System::Windows::Forms::ComboBox^ Diagnoses_comboBox;


    private: System::Windows::Forms::ComboBox^ comboBox4;
    private: System::Windows::Forms::ComboBox^ comboBox8;
    private: System::Windows::Forms::ComboBox^ comboBox6;
    private: System::Windows::Forms::ComboBox^ comboBox9;
private: System::Windows::Forms::ComboBox^ Names_comboBox;

    private: System::Windows::Forms::ComboBox^ comboBox5;
    private: System::Windows::Forms::Label^ BackToHome_label;
    private: System::Windows::Forms::Label^ Ill_History_label;
    private: System::Windows::Forms::Label^ Anamnesis_label;
    private: System::Windows::Forms::Label^ AnalysisResults_label;
    private: System::Windows::Forms::Label^ AddingInfo_label;
    private: System::Windows::Forms::Label^ SideInfo_label;
    private: System::Windows::Forms::Label^ Recomendations_label;
    private: System::Windows::Forms::Label^ UnworkableList_label;
    private: System::Windows::Forms::Label^ Stamp_label;
    private: System::Windows::Forms::Panel^ Anamnesis_panel;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel11;
    private: System::Windows::Forms::Label^ label11;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
    private: System::Windows::Forms::RadioButton^ Pnevmonia_radioButton;
    private: System::Windows::Forms::RadioButton^ Astenia_radioButton;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel3;
    private: System::Windows::Forms::RadioButton^ ResponseMedstation_radioButton;
    private: System::Windows::Forms::RadioButton^ ResponseGospital_radioButton;
    private: System::Windows::Forms::GroupBox^ groupBox17;
    private: System::Windows::Forms::DateTimePicker^ IllBegining_dateTimePicker;
    private: System::Windows::Forms::Label^ label12;
    private: System::Windows::Forms::Label^ label14;
    private: System::Windows::Forms::Label^ label13;
    private: System::Windows::Forms::GroupBox^ groupBox18;
    private: System::Windows::Forms::DateTimePicker^ ResponseDate_dateTimePicker;
    private: System::Windows::Forms::RadioButton^ ResponsePolyclinic_radioButton;
    private: System::Windows::Forms::Label^ label15;
    private: System::Windows::Forms::GroupBox^ groupBox19;
    private: System::Windows::Forms::DateTimePicker^ ResearchDate_dateTimePicker;
    private: System::Windows::Forms::CheckBox^ FOGK_checkBox;
    private: System::Windows::Forms::CheckBox^ RgOGK_checkBox;
    private: System::Windows::Forms::CheckBox^ KT_OGK_checkBox;
    private: System::Windows::Forms::CheckBox^ OAK_checkBox;
    private: System::Windows::Forms::CheckBox^ OAM_checkBox;
    private: System::Windows::Forms::CheckBox^ BioChemicalBloodResearch_checkBox;
    private: System::Windows::Forms::GroupBox^ groupBox20;
    private: System::Windows::Forms::TextBox^ Anamnesis_textBox;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel12;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel7;
    private: System::Windows::Forms::GroupBox^ groupBox5;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Label^ Epicrisis_label;
    private: System::Windows::Forms::GroupBox^ groupBox4;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel6;
    private: System::Windows::Forms::GroupBox^ groupBox3;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Label^ Settings_label;
    private: System::Windows::Forms::Label^ SettingsApplication_label;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
    private: System::Windows::Forms::Button^ TemplatesChange_button;
    private: System::Windows::Forms::GroupBox^ groupBox1;
    private: System::Windows::Forms::Label^ Template_label;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
    private: System::Windows::Forms::Button^ DB_create_button;
    private: System::Windows::Forms::Button^ DB_change_button;
    private: System::Windows::Forms::GroupBox^ DB_groupBox;
    private: System::Windows::Forms::TableLayoutPanel^ DoctorsNotes_tableLayoutPanel;
    private: System::Windows::Forms::GroupBox^ ReportDir_groupBox;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Button^ ReportSave_button;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel5;
    private: System::Windows::Forms::GroupBox^ groupBox2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ DoctorsNotes_label;
    private: System::Windows::Forms::Label^ FirstList_label;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel8;
    private: System::Windows::Forms::Button^ Recovery_button;
    private: System::Windows::Forms::Button^ SaveSettings_button;
    private: System::Windows::Forms::TableLayoutPanel^ NapravlenV_tableLayoutPanel;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel5;
    private: System::Windows::Forms::RadioButton^ SentToLazaret_radioButton;
    private: System::Windows::Forms::RadioButton^ SentToGospital_radioButton;
    private: System::Windows::Forms::RadioButton^ SentToPolyclinic_radioButton;
    private: System::Windows::Forms::Panel^ NapravlenVLazaret_panel;
    private: System::Windows::Forms::GroupBox^ GospitalSentDate_groupBox;
    private: System::Windows::Forms::DateTimePicker^ GospitalSentDate_dateTimePicker;
    private: System::Windows::Forms::Label^ TrackTo_label;
    private: System::Windows::Forms::Panel^ NapravlenVpolyclonic_panel;
    private: System::Windows::Forms::RadioButton^ AmbulanceHealing_radioButton;
    private: System::Windows::Forms::RadioButton^ Gospitalization_radioButton;
    private: System::Windows::Forms::Label^ label10;
    private: System::Windows::Forms::Panel^ panel2;
    private: System::Windows::Forms::GroupBox^ RepeatCheck_groupBox;
    private: System::Windows::Forms::DateTimePicker^ RepeatCheck_dateTimePicker;
    private: System::Windows::Forms::Label^ label16;
    private: System::Windows::Forms::TableLayoutPanel^ NapravlenieVGospital_tableLayoutPanel;
    private: System::Windows::Forms::Panel^ panel3;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel14;
    private: System::Windows::Forms::Button^ F4_button;
    private: System::Windows::Forms::Panel^ AnalysisResults_panel;
    private: System::Windows::Forms::GroupBox^ AnalysisResults_groupBox;
    private: System::Windows::Forms::ComboBox^ comboBox10;
    private: System::Windows::Forms::Panel^ AddingInfo_panel;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel13;
    private: System::Windows::Forms::CheckBox^ Mouth_checkBox;
    private: System::Windows::Forms::GroupBox^ Mouth_groupBox;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::GroupBox^ groupBox22;
    private: System::Windows::Forms::GroupBox^ DoctorLook_groupBox;
    private: System::Windows::Forms::ComboBox^ DoctorLook_comboBox;
    private: System::Windows::Forms::ComboBox^ comboBox11;
    private: System::Windows::Forms::GroupBox^ groupBox23;
    private: System::Windows::Forms::TextBox^ textBox3;
    private: System::Windows::Forms::GroupBox^ groupBox;
    private: System::Windows::Forms::TextBox^ textBox2;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel15;
    private: System::Windows::Forms::Panel^ SideInfo_panel;
    private: System::Windows::Forms::Panel^ UnworkableList_panel;
    private: System::Windows::Forms::Panel^ Stamp_panel;
    private: System::Windows::Forms::Panel^ Recomendations_panel;
    private: System::Windows::Forms::Button^ F6_button;
    private: System::Windows::Forms::Button^ F5_button;
    private: System::Windows::Forms::GroupBox^ SideInfo_groupBox;
    private: System::Windows::Forms::ComboBox^ SideInfo_comboBox;
    private: System::Windows::Forms::Button^ F7_button;
    private: System::Windows::Forms::Button^ button6;
    private: System::Windows::Forms::Button^ button5;
    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel16;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel17;
    private: System::Windows::Forms::Label^ label17;
    private: System::Windows::Forms::GroupBox^ groupBox21;
    private: System::Windows::Forms::ComboBox^ comboBox12;
    private: System::Windows::Forms::Button^ button7;
    private: System::Windows::Forms::Button^ button8;
    private: System::Windows::Forms::RadioButton^ radioButton3;
    private: System::Windows::Forms::RadioButton^ radioButton2;
    private: System::Windows::Forms::RadioButton^ radioButton1;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel18;
    private: System::Windows::Forms::Button^ F9_button;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel19;
    private: System::Windows::Forms::Button^ F8_button;
	private: System::ComponentModel::IContainer^ components;

		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
            this->history_button = (gcnew System::Windows::Forms::Button());
            this->Home_panel = (gcnew System::Windows::Forms::Panel());
            this->tableLayoutPanel12 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->Hitory_button = (gcnew System::Windows::Forms::Button());
            this->epicrisis_button = (gcnew System::Windows::Forms::Button());
            this->doctors_notes_button = (gcnew System::Windows::Forms::Button());
            this->f1_button = (gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->Epicrisis_label = (gcnew System::Windows::Forms::Label());
            this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->Settings_label = (gcnew System::Windows::Forms::Label());
            this->SettingsApplication_label = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->TemplatesChange_button = (gcnew System::Windows::Forms::Button());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->Template_label = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->DB_create_button = (gcnew System::Windows::Forms::Button());
            this->DB_change_button = (gcnew System::Windows::Forms::Button());
            this->DB_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->DoctorsNotes_tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->ReportDir_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->ReportSave_button = (gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->DoctorsNotes_label = (gcnew System::Windows::Forms::Label());
            this->FirstList_label = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->Recovery_button = (gcnew System::Windows::Forms::Button());
            this->SaveSettings_button = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->Epicrisis_panel = (gcnew System::Windows::Forms::Panel());
            this->EpiricisisTabMenu_tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->Anamnesis_button = (gcnew System::Windows::Forms::Button());
            this->IllHistory_button = (gcnew System::Windows::Forms::Button());
            this->Stamp_button = (gcnew System::Windows::Forms::Button());
            this->AddingInfo_button = (gcnew System::Windows::Forms::Button());
            this->SideInfo_button = (gcnew System::Windows::Forms::Button());
            this->Recomendations_button = (gcnew System::Windows::Forms::Button());
            this->UnworkableList_button = (gcnew System::Windows::Forms::Button());
            this->BackToHome_button = (gcnew System::Windows::Forms::Button());
            this->AnalysisResults_button = (gcnew System::Windows::Forms::Button());
            this->BackToHome_label = (gcnew System::Windows::Forms::Label());
            this->Ill_History_label = (gcnew System::Windows::Forms::Label());
            this->Anamnesis_label = (gcnew System::Windows::Forms::Label());
            this->AnalysisResults_label = (gcnew System::Windows::Forms::Label());
            this->AddingInfo_label = (gcnew System::Windows::Forms::Label());
            this->SideInfo_label = (gcnew System::Windows::Forms::Label());
            this->Recomendations_label = (gcnew System::Windows::Forms::Label());
            this->UnworkableList_label = (gcnew System::Windows::Forms::Label());
            this->Stamp_label = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel10 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
            this->dateTimePicker3 = (gcnew System::Windows::Forms::DateTimePicker());
            this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
            this->comboBox8 = (gcnew System::Windows::Forms::ComboBox());
            this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
            this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
            this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
            this->comboBox9 = (gcnew System::Windows::Forms::ComboBox());
            this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
            this->Names_comboBox = (gcnew System::Windows::Forms::ComboBox());
            this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
            this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
            this->SideInfo_panel = (gcnew System::Windows::Forms::Panel());
            this->F7_button = (gcnew System::Windows::Forms::Button());
            this->SideInfo_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->SideInfo_comboBox = (gcnew System::Windows::Forms::ComboBox());
            this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
            this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
            this->ID_label = (gcnew System::Windows::Forms::Label());
            this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->Clear_button = (gcnew System::Windows::Forms::Button());
            this->Ill_History_panel = (gcnew System::Windows::Forms::Panel());
            this->F3_button = (gcnew System::Windows::Forms::Button());
            this->groupBox15 = (gcnew System::Windows::Forms::GroupBox());
            this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->groupBox16 = (gcnew System::Windows::Forms::GroupBox());
            this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->MKB_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
            this->groupBox14 = (gcnew System::Windows::Forms::GroupBox());
            this->Diagnoses_comboBox = (gcnew System::Windows::Forms::ComboBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->groupBox13 = (gcnew System::Windows::Forms::GroupBox());
            this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
            this->groupBox12 = (gcnew System::Windows::Forms::GroupBox());
            this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
            this->Anamnesis_panel = (gcnew System::Windows::Forms::Panel());
            this->tableLayoutPanel14 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->tableLayoutPanel11 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->NapravlenV_tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->flowLayoutPanel5 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->SentToGospital_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->SentToLazaret_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->SentToPolyclinic_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->NapravlenieVGospital_tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->NapravlenVpolyclonic_panel = (gcnew System::Windows::Forms::Panel());
            this->RepeatCheck_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->RepeatCheck_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
            this->label16 = (gcnew System::Windows::Forms::Label());
            this->AmbulanceHealing_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->Gospitalization_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->NapravlenVLazaret_panel = (gcnew System::Windows::Forms::Panel());
            this->GospitalSentDate_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->GospitalSentDate_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
            this->TrackTo_label = (gcnew System::Windows::Forms::Label());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->groupBox19 = (gcnew System::Windows::Forms::GroupBox());
            this->ResearchDate_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->groupBox18 = (gcnew System::Windows::Forms::GroupBox());
            this->ResponseDate_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
            this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->ResponseMedstation_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->ResponseGospital_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->ResponsePolyclinic_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->groupBox17 = (gcnew System::Windows::Forms::GroupBox());
            this->IllBegining_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
            this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->Pnevmonia_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->Astenia_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->FOGK_checkBox = (gcnew System::Windows::Forms::CheckBox());
            this->RgOGK_checkBox = (gcnew System::Windows::Forms::CheckBox());
            this->KT_OGK_checkBox = (gcnew System::Windows::Forms::CheckBox());
            this->OAK_checkBox = (gcnew System::Windows::Forms::CheckBox());
            this->OAM_checkBox = (gcnew System::Windows::Forms::CheckBox());
            this->BioChemicalBloodResearch_checkBox = (gcnew System::Windows::Forms::CheckBox());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->F4_button = (gcnew System::Windows::Forms::Button());
            this->groupBox20 = (gcnew System::Windows::Forms::GroupBox());
            this->Anamnesis_textBox = (gcnew System::Windows::Forms::TextBox());
            this->AnalysisResults_panel = (gcnew System::Windows::Forms::Panel());
            this->F5_button = (gcnew System::Windows::Forms::Button());
            this->AnalysisResults_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->comboBox10 = (gcnew System::Windows::Forms::ComboBox());
            this->AddingInfo_panel = (gcnew System::Windows::Forms::Panel());
            this->tableLayoutPanel15 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->groupBox23 = (gcnew System::Windows::Forms::GroupBox());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->tableLayoutPanel13 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->F6_button = (gcnew System::Windows::Forms::Button());
            this->DoctorLook_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->DoctorLook_comboBox = (gcnew System::Windows::Forms::ComboBox());
            this->Mouth_checkBox = (gcnew System::Windows::Forms::CheckBox());
            this->Mouth_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->groupBox22 = (gcnew System::Windows::Forms::GroupBox());
            this->comboBox11 = (gcnew System::Windows::Forms::ComboBox());
            this->Recomendations_panel = (gcnew System::Windows::Forms::Panel());
            this->tableLayoutPanel19 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->F8_button = (gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel17 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->groupBox21 = (gcnew System::Windows::Forms::GroupBox());
            this->comboBox12 = (gcnew System::Windows::Forms::ComboBox());
            this->label17 = (gcnew System::Windows::Forms::Label());
            this->button7 = (gcnew System::Windows::Forms::Button());
            this->button8 = (gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel16 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->button6 = (gcnew System::Windows::Forms::Button());
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->UnworkableList_panel = (gcnew System::Windows::Forms::Panel());
            this->tableLayoutPanel18 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->F9_button = (gcnew System::Windows::Forms::Button());
            this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
            this->Stamp_panel = (gcnew System::Windows::Forms::Panel());
            this->Home_panel->SuspendLayout();
            this->tableLayoutPanel12->SuspendLayout();
            this->tableLayoutPanel1->SuspendLayout();
            this->tableLayoutPanel2->SuspendLayout();
            this->tableLayoutPanel7->SuspendLayout();
            this->groupBox5->SuspendLayout();
            this->groupBox4->SuspendLayout();
            this->tableLayoutPanel6->SuspendLayout();
            this->groupBox3->SuspendLayout();
            this->tableLayoutPanel3->SuspendLayout();
            this->groupBox1->SuspendLayout();
            this->tableLayoutPanel4->SuspendLayout();
            this->DoctorsNotes_tableLayoutPanel->SuspendLayout();
            this->ReportDir_groupBox->SuspendLayout();
            this->tableLayoutPanel5->SuspendLayout();
            this->groupBox2->SuspendLayout();
            this->tableLayoutPanel8->SuspendLayout();
            this->Epicrisis_panel->SuspendLayout();
            this->EpiricisisTabMenu_tableLayoutPanel->SuspendLayout();
            this->tableLayoutPanel10->SuspendLayout();
            this->groupBox11->SuspendLayout();
            this->groupBox10->SuspendLayout();
            this->groupBox9->SuspendLayout();
            this->groupBox8->SuspendLayout();
            this->groupBox7->SuspendLayout();
            this->groupBox6->SuspendLayout();
            this->SideInfo_panel->SuspendLayout();
            this->SideInfo_groupBox->SuspendLayout();
            this->tableLayoutPanel9->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
            this->flowLayoutPanel1->SuspendLayout();
            this->Ill_History_panel->SuspendLayout();
            this->groupBox15->SuspendLayout();
            this->groupBox16->SuspendLayout();
            this->MKB_groupBox->SuspendLayout();
            this->groupBox14->SuspendLayout();
            this->groupBox13->SuspendLayout();
            this->groupBox12->SuspendLayout();
            this->Anamnesis_panel->SuspendLayout();
            this->tableLayoutPanel14->SuspendLayout();
            this->panel3->SuspendLayout();
            this->tableLayoutPanel11->SuspendLayout();
            this->NapravlenV_tableLayoutPanel->SuspendLayout();
            this->flowLayoutPanel5->SuspendLayout();
            this->NapravlenieVGospital_tableLayoutPanel->SuspendLayout();
            this->NapravlenVpolyclonic_panel->SuspendLayout();
            this->RepeatCheck_groupBox->SuspendLayout();
            this->NapravlenVLazaret_panel->SuspendLayout();
            this->GospitalSentDate_groupBox->SuspendLayout();
            this->groupBox19->SuspendLayout();
            this->groupBox18->SuspendLayout();
            this->flowLayoutPanel3->SuspendLayout();
            this->groupBox17->SuspendLayout();
            this->flowLayoutPanel2->SuspendLayout();
            this->panel2->SuspendLayout();
            this->groupBox20->SuspendLayout();
            this->AnalysisResults_panel->SuspendLayout();
            this->AnalysisResults_groupBox->SuspendLayout();
            this->AddingInfo_panel->SuspendLayout();
            this->tableLayoutPanel15->SuspendLayout();
            this->groupBox->SuspendLayout();
            this->groupBox23->SuspendLayout();
            this->tableLayoutPanel13->SuspendLayout();
            this->DoctorLook_groupBox->SuspendLayout();
            this->Mouth_groupBox->SuspendLayout();
            this->groupBox22->SuspendLayout();
            this->Recomendations_panel->SuspendLayout();
            this->tableLayoutPanel19->SuspendLayout();
            this->tableLayoutPanel17->SuspendLayout();
            this->groupBox21->SuspendLayout();
            this->tableLayoutPanel16->SuspendLayout();
            this->UnworkableList_panel->SuspendLayout();
            this->tableLayoutPanel18->SuspendLayout();
            this->SuspendLayout();
            // 
            // history_button
            // 
            this->history_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->history_button->AutoSize = true;
            this->history_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->history_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->history_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->history_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->history_button->ForeColor = System::Drawing::Color::White;
            this->history_button->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
            this->history_button->Location = System::Drawing::Point(0, 534);
            this->history_button->Margin = System::Windows::Forms::Padding(0, 6, 0, 6);
            this->history_button->Name = L"history_button";
            this->history_button->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->history_button->Size = System::Drawing::Size(767, 516);
            this->history_button->TabIndex = 3;
            this->history_button->TabStop = false;
            this->history_button->Text = L"История";
            this->history_button->UseVisualStyleBackColor = false;
            // 
            // Home_panel
            // 
            this->Home_panel->AutoScroll = true;
            this->Home_panel->AutoSize = true;
            this->Home_panel->Controls->Add(this->tableLayoutPanel12);
            this->Home_panel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Home_panel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->Home_panel->Location = System::Drawing::Point(0, 0);
            this->Home_panel->Name = L"Home_panel";
            this->Home_panel->Size = System::Drawing::Size(1313, 742);
            this->Home_panel->TabIndex = 5;
            // 
            // tableLayoutPanel12
            // 
            this->tableLayoutPanel12->ColumnCount = 1;
            this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel12->Controls->Add(this->tableLayoutPanel1, 0, 1);
            this->tableLayoutPanel12->Controls->Add(this->tableLayoutPanel2, 0, 3);
            this->tableLayoutPanel12->Controls->Add(this->label1, 0, 0);
            this->tableLayoutPanel12->Dock = System::Windows::Forms::DockStyle::Top;
            this->tableLayoutPanel12->Location = System::Drawing::Point(0, 0);
            this->tableLayoutPanel12->Name = L"tableLayoutPanel12";
            this->tableLayoutPanel12->RowCount = 4;
            this->tableLayoutPanel12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                211)));
            this->tableLayoutPanel12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                224)));
            this->tableLayoutPanel12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                214)));
            this->tableLayoutPanel12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                183)));
            this->tableLayoutPanel12->Size = System::Drawing::Size(1296, 1383);
            this->tableLayoutPanel12->TabIndex = 11;
            // 
            // tableLayoutPanel1
            // 
            this->tableLayoutPanel1->ColumnCount = 1;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel1->Controls->Add(this->Hitory_button, 0, 2);
            this->tableLayoutPanel1->Controls->Add(this->epicrisis_button, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->doctors_notes_button, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->f1_button, 0, 3);
            this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel1->Location = System::Drawing::Point(3, 214);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 4;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel1->Size = System::Drawing::Size(1290, 218);
            this->tableLayoutPanel1->TabIndex = 5;
            // 
            // Hitory_button
            // 
            this->Hitory_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->Hitory_button->AutoSize = true;
            this->Hitory_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->Hitory_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->Hitory_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Hitory_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Hitory_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Hitory_button->ForeColor = System::Drawing::Color::White;
            this->Hitory_button->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
            this->Hitory_button->Location = System::Drawing::Point(0, 111);
            this->Hitory_button->Margin = System::Windows::Forms::Padding(0, 3, 0, 3);
            this->Hitory_button->Name = L"Hitory_button";
            this->Hitory_button->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->Hitory_button->Size = System::Drawing::Size(1290, 48);
            this->Hitory_button->TabIndex = 9;
            this->Hitory_button->TabStop = false;
            this->Hitory_button->Text = L"История";
            this->Hitory_button->UseVisualStyleBackColor = false;
            // 
            // epicrisis_button
            // 
            this->epicrisis_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->epicrisis_button->AutoSize = true;
            this->epicrisis_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->epicrisis_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->epicrisis_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->epicrisis_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->epicrisis_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->epicrisis_button->ForeColor = System::Drawing::Color::White;
            this->epicrisis_button->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
            this->epicrisis_button->Location = System::Drawing::Point(0, 57);
            this->epicrisis_button->Margin = System::Windows::Forms::Padding(0, 3, 0, 3);
            this->epicrisis_button->Name = L"epicrisis_button";
            this->epicrisis_button->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->epicrisis_button->Size = System::Drawing::Size(1290, 48);
            this->epicrisis_button->TabIndex = 2;
            this->epicrisis_button->TabStop = false;
            this->epicrisis_button->Text = L"Эпикриз";
            this->epicrisis_button->UseVisualStyleBackColor = false;
            this->epicrisis_button->Click += gcnew System::EventHandler(this, &MainWindow::epicrisis_button_Click);
            // 
            // doctors_notes_button
            // 
            this->doctors_notes_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->doctors_notes_button->AutoSize = true;
            this->doctors_notes_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)),
                static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->doctors_notes_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->doctors_notes_button->FlatAppearance->BorderSize = 0;
            this->doctors_notes_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->doctors_notes_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->doctors_notes_button->ForeColor = System::Drawing::Color::White;
            this->doctors_notes_button->Location = System::Drawing::Point(0, 3);
            this->doctors_notes_button->Margin = System::Windows::Forms::Padding(0, 3, 0, 3);
            this->doctors_notes_button->Name = L"doctors_notes_button";
            this->doctors_notes_button->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->doctors_notes_button->Size = System::Drawing::Size(1290, 48);
            this->doctors_notes_button->TabIndex = 1;
            this->doctors_notes_button->TabStop = false;
            this->doctors_notes_button->Text = L"Записи лечащего врача";
            this->doctors_notes_button->UseVisualStyleBackColor = false;
            // 
            // f1_button
            // 
            this->f1_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->f1_button->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->f1_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
            this->f1_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->f1_button->FlatAppearance->BorderSize = 0;
            this->f1_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->f1_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->f1_button->Location = System::Drawing::Point(0, 165);
            this->f1_button->Margin = System::Windows::Forms::Padding(0, 3, 0, 3);
            this->f1_button->Name = L"f1_button";
            this->f1_button->Size = System::Drawing::Size(1290, 50);
            this->f1_button->TabIndex = 4;
            this->f1_button->TabStop = false;
            this->f1_button->Text = L"Справка(F1)";
            this->f1_button->UseVisualStyleBackColor = false;
            // 
            // tableLayoutPanel2
            // 
            this->tableLayoutPanel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutPanel2->ColumnCount = 1;
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel7, 0, 11);
            this->tableLayoutPanel2->Controls->Add(this->Epicrisis_label, 0, 10);
            this->tableLayoutPanel2->Controls->Add(this->groupBox4, 0, 9);
            this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel6, 0, 8);
            this->tableLayoutPanel2->Controls->Add(this->Settings_label, 0, 0);
            this->tableLayoutPanel2->Controls->Add(this->SettingsApplication_label, 0, 1);
            this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 3);
            this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel4, 0, 2);
            this->tableLayoutPanel2->Controls->Add(this->DoctorsNotes_tableLayoutPanel, 0, 5);
            this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel5, 0, 6);
            this->tableLayoutPanel2->Controls->Add(this->DoctorsNotes_label, 0, 4);
            this->tableLayoutPanel2->Controls->Add(this->FirstList_label, 0, 7);
            this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel8, 0, 12);
            this->tableLayoutPanel2->Location = System::Drawing::Point(3, 652);
            this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
            this->tableLayoutPanel2->RowCount = 13;
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 58)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 37)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 68)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 68)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 37)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 68)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 68)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 37)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 68)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 68)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 37)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 68)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tableLayoutPanel2->Size = System::Drawing::Size(1290, 728);
            this->tableLayoutPanel2->TabIndex = 9;
            // 
            // tableLayoutPanel7
            // 
            this->tableLayoutPanel7->ColumnCount = 2;
            this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                126)));
            this->tableLayoutPanel7->Controls->Add(this->groupBox5, 0, 0);
            this->tableLayoutPanel7->Controls->Add(this->button2, 1, 0);
            this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel7->Location = System::Drawing::Point(3, 617);
            this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
            this->tableLayoutPanel7->RowCount = 1;
            this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->tableLayoutPanel7->Size = System::Drawing::Size(1284, 62);
            this->tableLayoutPanel7->TabIndex = 12;
            // 
            // groupBox5
            // 
            this->groupBox5->Controls->Add(this->label8);
            this->groupBox5->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox5->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox5->ForeColor = System::Drawing::SystemColors::WindowText;
            this->groupBox5->Location = System::Drawing::Point(3, 3);
            this->groupBox5->Name = L"groupBox5";
            this->groupBox5->Size = System::Drawing::Size(1152, 56);
            this->groupBox5->TabIndex = 8;
            this->groupBox5->TabStop = false;
            this->groupBox5->Text = L"Путь сохранения отчета";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label8->Location = System::Drawing::Point(3, 18);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(0, 16);
            this->label8->TabIndex = 0;
            // 
            // button2
            // 
            this->button2->BackColor = System::Drawing::Color::White;
            this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button2->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button2->Location = System::Drawing::Point(1161, 10);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(120, 49);
            this->button2->TabIndex = 7;
            this->button2->TabStop = false;
            this->button2->Text = L"Изменить";
            this->button2->UseVisualStyleBackColor = false;
            // 
            // Epicrisis_label
            // 
            this->Epicrisis_label->AutoSize = true;
            this->Epicrisis_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->Epicrisis_label->ForeColor = System::Drawing::SystemColors::ControlText;
            this->Epicrisis_label->Location = System::Drawing::Point(10, 580);
            this->Epicrisis_label->Margin = System::Windows::Forms::Padding(10, 3, 3, 0);
            this->Epicrisis_label->Name = L"Epicrisis_label";
            this->Epicrisis_label->Size = System::Drawing::Size(121, 31);
            this->Epicrisis_label->TabIndex = 11;
            this->Epicrisis_label->Text = L"Эпикриз";
            // 
            // groupBox4
            // 
            this->groupBox4->Controls->Add(this->label6);
            this->groupBox4->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox4->ForeColor = System::Drawing::SystemColors::WindowText;
            this->groupBox4->Location = System::Drawing::Point(3, 512);
            this->groupBox4->Name = L"groupBox4";
            this->groupBox4->Size = System::Drawing::Size(1284, 62);
            this->groupBox4->TabIndex = 10;
            this->groupBox4->TabStop = false;
            this->groupBox4->Text = L"Префикс имени файла отчета";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label6->Location = System::Drawing::Point(3, 18);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(0, 16);
            this->label6->TabIndex = 0;
            // 
            // tableLayoutPanel6
            // 
            this->tableLayoutPanel6->ColumnCount = 2;
            this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                126)));
            this->tableLayoutPanel6->Controls->Add(this->groupBox3, 0, 0);
            this->tableLayoutPanel6->Controls->Add(this->button1, 1, 0);
            this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel6->Location = System::Drawing::Point(3, 444);
            this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
            this->tableLayoutPanel6->RowCount = 1;
            this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->tableLayoutPanel6->Size = System::Drawing::Size(1284, 62);
            this->tableLayoutPanel6->TabIndex = 9;
            // 
            // groupBox3
            // 
            this->groupBox3->Controls->Add(this->label5);
            this->groupBox3->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox3->ForeColor = System::Drawing::SystemColors::WindowText;
            this->groupBox3->Location = System::Drawing::Point(3, 3);
            this->groupBox3->Name = L"groupBox3";
            this->groupBox3->Size = System::Drawing::Size(1152, 56);
            this->groupBox3->TabIndex = 8;
            this->groupBox3->TabStop = false;
            this->groupBox3->Text = L"Путь сохранения отчета";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label5->Location = System::Drawing::Point(3, 18);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(0, 16);
            this->label5->TabIndex = 0;
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::White;
            this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button1->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button1->Location = System::Drawing::Point(1161, 10);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(120, 49);
            this->button1->TabIndex = 7;
            this->button1->TabStop = false;
            this->button1->Text = L"Изменить";
            this->button1->UseVisualStyleBackColor = false;
            // 
            // Settings_label
            // 
            this->Settings_label->AutoSize = true;
            this->Settings_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Settings_label->ForeColor = System::Drawing::SystemColors::ControlText;
            this->Settings_label->Location = System::Drawing::Point(3, 3);
            this->Settings_label->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
            this->Settings_label->Name = L"Settings_label";
            this->Settings_label->Size = System::Drawing::Size(264, 55);
            this->Settings_label->TabIndex = 0;
            this->Settings_label->Text = L"Настройки";
            // 
            // SettingsApplication_label
            // 
            this->SettingsApplication_label->AutoSize = true;
            this->SettingsApplication_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->SettingsApplication_label->ForeColor = System::Drawing::SystemColors::ControlText;
            this->SettingsApplication_label->Location = System::Drawing::Point(10, 61);
            this->SettingsApplication_label->Margin = System::Windows::Forms::Padding(10, 3, 3, 0);
            this->SettingsApplication_label->Name = L"SettingsApplication_label";
            this->SettingsApplication_label->Size = System::Drawing::Size(173, 31);
            this->SettingsApplication_label->TabIndex = 1;
            this->SettingsApplication_label->Text = L"Приложение";
            this->SettingsApplication_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // tableLayoutPanel3
            // 
            this->tableLayoutPanel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutPanel3->ColumnCount = 2;
            this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                126)));
            this->tableLayoutPanel3->Controls->Add(this->TemplatesChange_button, 1, 0);
            this->tableLayoutPanel3->Controls->Add(this->groupBox1, 0, 0);
            this->tableLayoutPanel3->Location = System::Drawing::Point(3, 166);
            this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
            this->tableLayoutPanel3->RowCount = 1;
            this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->tableLayoutPanel3->Size = System::Drawing::Size(1284, 62);
            this->tableLayoutPanel3->TabIndex = 3;
            // 
            // TemplatesChange_button
            // 
            this->TemplatesChange_button->BackColor = System::Drawing::Color::White;
            this->TemplatesChange_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->TemplatesChange_button->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->TemplatesChange_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->TemplatesChange_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)),
                static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->TemplatesChange_button->Location = System::Drawing::Point(1161, 10);
            this->TemplatesChange_button->Name = L"TemplatesChange_button";
            this->TemplatesChange_button->Size = System::Drawing::Size(120, 49);
            this->TemplatesChange_button->TabIndex = 0;
            this->TemplatesChange_button->TabStop = false;
            this->TemplatesChange_button->Text = L"Изменить";
            this->TemplatesChange_button->UseVisualStyleBackColor = false;
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->Template_label);
            this->groupBox1->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox1->ForeColor = System::Drawing::SystemColors::WindowText;
            this->groupBox1->Location = System::Drawing::Point(3, 3);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(1152, 56);
            this->groupBox1->TabIndex = 1;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Папка с шаблонами";
            // 
            // Template_label
            // 
            this->Template_label->AutoSize = true;
            this->Template_label->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Template_label->Location = System::Drawing::Point(3, 18);
            this->Template_label->Name = L"Template_label";
            this->Template_label->Size = System::Drawing::Size(0, 16);
            this->Template_label->TabIndex = 0;
            // 
            // tableLayoutPanel4
            // 
            this->tableLayoutPanel4->ColumnCount = 3;
            this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                126)));
            this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                126)));
            this->tableLayoutPanel4->Controls->Add(this->DB_create_button, 2, 0);
            this->tableLayoutPanel4->Controls->Add(this->DB_change_button, 1, 0);
            this->tableLayoutPanel4->Controls->Add(this->DB_groupBox, 0, 0);
            this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel4->Location = System::Drawing::Point(3, 98);
            this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
            this->tableLayoutPanel4->RowCount = 1;
            this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->tableLayoutPanel4->Size = System::Drawing::Size(1284, 62);
            this->tableLayoutPanel4->TabIndex = 4;
            // 
            // DB_create_button
            // 
            this->DB_create_button->BackColor = System::Drawing::Color::White;
            this->DB_create_button->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->DB_create_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->DB_create_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->DB_create_button->Location = System::Drawing::Point(1161, 10);
            this->DB_create_button->Name = L"DB_create_button";
            this->DB_create_button->Size = System::Drawing::Size(120, 49);
            this->DB_create_button->TabIndex = 2;
            this->DB_create_button->TabStop = false;
            this->DB_create_button->Text = L"Создать";
            this->DB_create_button->UseVisualStyleBackColor = false;
            // 
            // DB_change_button
            // 
            this->DB_change_button->BackColor = System::Drawing::Color::White;
            this->DB_change_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->DB_change_button->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->DB_change_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->DB_change_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->DB_change_button->Location = System::Drawing::Point(1035, 10);
            this->DB_change_button->Name = L"DB_change_button";
            this->DB_change_button->Size = System::Drawing::Size(120, 49);
            this->DB_change_button->TabIndex = 1;
            this->DB_change_button->TabStop = false;
            this->DB_change_button->Text = L"Изменить";
            this->DB_change_button->UseVisualStyleBackColor = false;
            // 
            // DB_groupBox
            // 
            this->DB_groupBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->DB_groupBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->DB_groupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->DB_groupBox->Location = System::Drawing::Point(3, 3);
            this->DB_groupBox->Name = L"DB_groupBox";
            this->DB_groupBox->Size = System::Drawing::Size(1026, 56);
            this->DB_groupBox->TabIndex = 0;
            this->DB_groupBox->TabStop = false;
            this->DB_groupBox->Text = L"Файл базы данных";
            // 
            // DoctorsNotes_tableLayoutPanel
            // 
            this->DoctorsNotes_tableLayoutPanel->ColumnCount = 2;
            this->DoctorsNotes_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->DoctorsNotes_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                126)));
            this->DoctorsNotes_tableLayoutPanel->Controls->Add(this->ReportDir_groupBox, 0, 0);
            this->DoctorsNotes_tableLayoutPanel->Controls->Add(this->ReportSave_button, 1, 0);
            this->DoctorsNotes_tableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->DoctorsNotes_tableLayoutPanel->Location = System::Drawing::Point(3, 271);
            this->DoctorsNotes_tableLayoutPanel->Name = L"DoctorsNotes_tableLayoutPanel";
            this->DoctorsNotes_tableLayoutPanel->RowCount = 1;
            this->DoctorsNotes_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->DoctorsNotes_tableLayoutPanel->Size = System::Drawing::Size(1284, 62);
            this->DoctorsNotes_tableLayoutPanel->TabIndex = 6;
            // 
            // ReportDir_groupBox
            // 
            this->ReportDir_groupBox->Controls->Add(this->label2);
            this->ReportDir_groupBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->ReportDir_groupBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ReportDir_groupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->ReportDir_groupBox->ForeColor = System::Drawing::SystemColors::WindowText;
            this->ReportDir_groupBox->Location = System::Drawing::Point(3, 3);
            this->ReportDir_groupBox->Name = L"ReportDir_groupBox";
            this->ReportDir_groupBox->Size = System::Drawing::Size(1152, 56);
            this->ReportDir_groupBox->TabIndex = 8;
            this->ReportDir_groupBox->TabStop = false;
            this->ReportDir_groupBox->Text = L"Путь сохранения отчета";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label2->Location = System::Drawing::Point(3, 18);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(0, 16);
            this->label2->TabIndex = 0;
            // 
            // ReportSave_button
            // 
            this->ReportSave_button->BackColor = System::Drawing::Color::White;
            this->ReportSave_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->ReportSave_button->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->ReportSave_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->ReportSave_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)),
                static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->ReportSave_button->Location = System::Drawing::Point(1161, 10);
            this->ReportSave_button->Name = L"ReportSave_button";
            this->ReportSave_button->Size = System::Drawing::Size(120, 49);
            this->ReportSave_button->TabIndex = 7;
            this->ReportSave_button->TabStop = false;
            this->ReportSave_button->Text = L"Изменить";
            this->ReportSave_button->UseVisualStyleBackColor = false;
            // 
            // tableLayoutPanel5
            // 
            this->tableLayoutPanel5->ColumnCount = 1;
            this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutPanel5->Controls->Add(this->groupBox2, 0, 0);
            this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel5->Location = System::Drawing::Point(3, 339);
            this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
            this->tableLayoutPanel5->RowCount = 1;
            this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->tableLayoutPanel5->Size = System::Drawing::Size(1284, 62);
            this->tableLayoutPanel5->TabIndex = 7;
            // 
            // groupBox2
            // 
            this->groupBox2->Controls->Add(this->label3);
            this->groupBox2->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox2->ForeColor = System::Drawing::SystemColors::WindowText;
            this->groupBox2->Location = System::Drawing::Point(3, 3);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = System::Drawing::Size(1278, 56);
            this->groupBox2->TabIndex = 9;
            this->groupBox2->TabStop = false;
            this->groupBox2->Text = L"Префикс имени файла отчета";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label3->Location = System::Drawing::Point(3, 18);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(0, 16);
            this->label3->TabIndex = 0;
            // 
            // DoctorsNotes_label
            // 
            this->DoctorsNotes_label->AutoSize = true;
            this->DoctorsNotes_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->DoctorsNotes_label->ForeColor = System::Drawing::SystemColors::ControlText;
            this->DoctorsNotes_label->Location = System::Drawing::Point(10, 234);
            this->DoctorsNotes_label->Margin = System::Windows::Forms::Padding(10, 3, 3, 0);
            this->DoctorsNotes_label->Name = L"DoctorsNotes_label";
            this->DoctorsNotes_label->Size = System::Drawing::Size(185, 31);
            this->DoctorsNotes_label->TabIndex = 5;
            this->DoctorsNotes_label->Text = L"Записи врача";
            // 
            // FirstList_label
            // 
            this->FirstList_label->AutoSize = true;
            this->FirstList_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->FirstList_label->ForeColor = System::Drawing::SystemColors::ControlText;
            this->FirstList_label->Location = System::Drawing::Point(10, 407);
            this->FirstList_label->Margin = System::Windows::Forms::Padding(10, 3, 3, 0);
            this->FirstList_label->Name = L"FirstList_label";
            this->FirstList_label->Size = System::Drawing::Size(175, 31);
            this->FirstList_label->TabIndex = 8;
            this->FirstList_label->Text = L"Первый лист";
            // 
            // tableLayoutPanel8
            // 
            this->tableLayoutPanel8->ColumnCount = 2;
            this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutPanel8->Controls->Add(this->Recovery_button, 0, 0);
            this->tableLayoutPanel8->Controls->Add(this->SaveSettings_button, 1, 0);
            this->tableLayoutPanel8->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel8->Location = System::Drawing::Point(3, 685);
            this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
            this->tableLayoutPanel8->RowCount = 1;
            this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->tableLayoutPanel8->Size = System::Drawing::Size(1284, 40);
            this->tableLayoutPanel8->TabIndex = 13;
            // 
            // Recovery_button
            // 
            this->Recovery_button->BackColor = System::Drawing::Color::White;
            this->Recovery_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Recovery_button->Dock = System::Windows::Forms::DockStyle::Right;
            this->Recovery_button->FlatAppearance->BorderSize = 0;
            this->Recovery_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Recovery_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->Recovery_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->Recovery_button->Location = System::Drawing::Point(485, 3);
            this->Recovery_button->Name = L"Recovery_button";
            this->Recovery_button->Size = System::Drawing::Size(154, 34);
            this->Recovery_button->TabIndex = 0;
            this->Recovery_button->TabStop = false;
            this->Recovery_button->Text = L"Восстановить";
            this->Recovery_button->UseVisualStyleBackColor = false;
            // 
            // SaveSettings_button
            // 
            this->SaveSettings_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)),
                static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->SaveSettings_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->SaveSettings_button->Dock = System::Windows::Forms::DockStyle::Left;
            this->SaveSettings_button->FlatAppearance->BorderSize = 0;
            this->SaveSettings_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->SaveSettings_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->SaveSettings_button->ForeColor = System::Drawing::Color::White;
            this->SaveSettings_button->Location = System::Drawing::Point(645, 3);
            this->SaveSettings_button->Name = L"SaveSettings_button";
            this->SaveSettings_button->Size = System::Drawing::Size(117, 34);
            this->SaveSettings_button->TabIndex = 1;
            this->SaveSettings_button->TabStop = false;
            this->SaveSettings_button->Text = L"Сохранить";
            this->SaveSettings_button->UseVisualStyleBackColor = false;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label1->ForeColor = System::Drawing::SystemColors::ControlText;
            this->label1->Location = System::Drawing::Point(3, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(157, 55);
            this->label1->TabIndex = 10;
            this->label1->Text = L"Home";
            // 
            // Epicrisis_panel
            // 
            this->Epicrisis_panel->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->Epicrisis_panel->Controls->Add(this->EpiricisisTabMenu_tableLayoutPanel);
            this->Epicrisis_panel->Controls->Add(this->tableLayoutPanel10);
            this->Epicrisis_panel->Controls->Add(this->SideInfo_panel);
            this->Epicrisis_panel->Controls->Add(this->tableLayoutPanel9);
            this->Epicrisis_panel->Controls->Add(this->Ill_History_panel);
            this->Epicrisis_panel->Controls->Add(this->Anamnesis_panel);
            this->Epicrisis_panel->Controls->Add(this->AnalysisResults_panel);
            this->Epicrisis_panel->Controls->Add(this->AddingInfo_panel);
            this->Epicrisis_panel->Controls->Add(this->Recomendations_panel);
            this->Epicrisis_panel->Controls->Add(this->UnworkableList_panel);
            this->Epicrisis_panel->Controls->Add(this->Stamp_panel);
            this->Epicrisis_panel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Epicrisis_panel->Location = System::Drawing::Point(0, 0);
            this->Epicrisis_panel->Name = L"Epicrisis_panel";
            this->Epicrisis_panel->Size = System::Drawing::Size(1313, 742);
            this->Epicrisis_panel->TabIndex = 11;
            // 
            // EpiricisisTabMenu_tableLayoutPanel
            // 
            this->EpiricisisTabMenu_tableLayoutPanel->ColumnCount = 9;
            this->EpiricisisTabMenu_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                58)));
            this->EpiricisisTabMenu_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                160)));
            this->EpiricisisTabMenu_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                102)));
            this->EpiricisisTabMenu_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                191)));
            this->EpiricisisTabMenu_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                206)));
            this->EpiricisisTabMenu_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                146)));
            this->EpiricisisTabMenu_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                139)));
            this->EpiricisisTabMenu_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                217)));
            this->EpiricisisTabMenu_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                13)));
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->Anamnesis_button, 0, 0);
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->IllHistory_button, 0, 0);
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->Stamp_button, 6, 0);
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->AddingInfo_button, 2, 0);
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->SideInfo_button, 3, 0);
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->Recomendations_button, 4, 0);
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->UnworkableList_button, 5, 0);
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->BackToHome_button, 0, 0);
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->AnalysisResults_button, 1, 0);
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->BackToHome_label, 0, 1);
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->Ill_History_label, 1, 1);
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->Anamnesis_label, 2, 1);
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->AnalysisResults_label, 3, 1);
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->AddingInfo_label, 4, 1);
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->SideInfo_label, 5, 1);
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->Recomendations_label, 6, 1);
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->UnworkableList_label, 7, 1);
            this->EpiricisisTabMenu_tableLayoutPanel->Controls->Add(this->Stamp_label, 8, 1);
            this->EpiricisisTabMenu_tableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->EpiricisisTabMenu_tableLayoutPanel->Location = System::Drawing::Point(0, 678);
            this->EpiricisisTabMenu_tableLayoutPanel->Name = L"EpiricisisTabMenu_tableLayoutPanel";
            this->EpiricisisTabMenu_tableLayoutPanel->RowCount = 2;
            this->EpiricisisTabMenu_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                58)));
            this->EpiricisisTabMenu_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                30)));
            this->EpiricisisTabMenu_tableLayoutPanel->Size = System::Drawing::Size(1313, 64);
            this->EpiricisisTabMenu_tableLayoutPanel->TabIndex = 6;
            // 
            // Anamnesis_button
            // 
            this->Anamnesis_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Anamnesis_button->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Anamnesis_button->FlatAppearance->BorderSize = 0;
            this->Anamnesis_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Anamnesis_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->Anamnesis_button->Location = System::Drawing::Point(220, 2);
            this->Anamnesis_button->Margin = System::Windows::Forms::Padding(2);
            this->Anamnesis_button->Name = L"Anamnesis_button";
            this->Anamnesis_button->Size = System::Drawing::Size(98, 54);
            this->Anamnesis_button->TabIndex = 12;
            this->Anamnesis_button->TabStop = false;
            this->Anamnesis_button->Text = L"Анамнез(F3)";
            this->Anamnesis_button->UseVisualStyleBackColor = true;
            this->Anamnesis_button->Click += gcnew System::EventHandler(this, &MainWindow::Anamnesis_button_Click);
            // 
            // IllHistory_button
            // 
            this->IllHistory_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->IllHistory_button->Dock = System::Windows::Forms::DockStyle::Fill;
            this->IllHistory_button->FlatAppearance->BorderSize = 0;
            this->IllHistory_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->IllHistory_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->IllHistory_button->Location = System::Drawing::Point(60, 2);
            this->IllHistory_button->Margin = System::Windows::Forms::Padding(2);
            this->IllHistory_button->Name = L"IllHistory_button";
            this->IllHistory_button->Size = System::Drawing::Size(156, 54);
            this->IllHistory_button->TabIndex = 11;
            this->IllHistory_button->TabStop = false;
            this->IllHistory_button->Text = L"История болезни(F2)";
            this->IllHistory_button->UseVisualStyleBackColor = true;
            this->IllHistory_button->Click += gcnew System::EventHandler(this, &MainWindow::IllHistory_button_Click);
            // 
            // Stamp_button
            // 
            this->Stamp_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Stamp_button->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Stamp_button->FlatAppearance->BorderSize = 0;
            this->Stamp_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Stamp_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Stamp_button->Location = System::Drawing::Point(1221, 2);
            this->Stamp_button->Margin = System::Windows::Forms::Padding(2);
            this->Stamp_button->Name = L"Stamp_button";
            this->Stamp_button->Size = System::Drawing::Size(90, 54);
            this->Stamp_button->TabIndex = 10;
            this->Stamp_button->TabStop = false;
            this->Stamp_button->Text = L"Штамп(F9)";
            this->Stamp_button->UseVisualStyleBackColor = true;
            this->Stamp_button->Click += gcnew System::EventHandler(this, &MainWindow::Stamp_button_Click);
            // 
            // AddingInfo_button
            // 
            this->AddingInfo_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->AddingInfo_button->Dock = System::Windows::Forms::DockStyle::Fill;
            this->AddingInfo_button->FlatAppearance->BorderSize = 0;
            this->AddingInfo_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->AddingInfo_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->AddingInfo_button->Location = System::Drawing::Point(513, 2);
            this->AddingInfo_button->Margin = System::Windows::Forms::Padding(2);
            this->AddingInfo_button->Name = L"AddingInfo_button";
            this->AddingInfo_button->Size = System::Drawing::Size(202, 54);
            this->AddingInfo_button->TabIndex = 8;
            this->AddingInfo_button->TabStop = false;
            this->AddingInfo_button->Text = L"Дополнительные данные(F5)";
            this->AddingInfo_button->UseVisualStyleBackColor = true;
            this->AddingInfo_button->Click += gcnew System::EventHandler(this, &MainWindow::AddingInfo_button_Click);
            // 
            // SideInfo_button
            // 
            this->SideInfo_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->SideInfo_button->Dock = System::Windows::Forms::DockStyle::Fill;
            this->SideInfo_button->FlatAppearance->BorderSize = 0;
            this->SideInfo_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->SideInfo_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->SideInfo_button->Location = System::Drawing::Point(719, 2);
            this->SideInfo_button->Margin = System::Windows::Forms::Padding(2);
            this->SideInfo_button->Name = L"SideInfo_button";
            this->SideInfo_button->Size = System::Drawing::Size(142, 54);
            this->SideInfo_button->TabIndex = 9;
            this->SideInfo_button->TabStop = false;
            this->SideInfo_button->Text = L"Дополнительно(F6)";
            this->SideInfo_button->UseVisualStyleBackColor = true;
            this->SideInfo_button->Click += gcnew System::EventHandler(this, &MainWindow::SideInfo_button_Click);
            // 
            // Recomendations_button
            // 
            this->Recomendations_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Recomendations_button->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Recomendations_button->FlatAppearance->BorderSize = 0;
            this->Recomendations_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Recomendations_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->Recomendations_button->Location = System::Drawing::Point(865, 2);
            this->Recomendations_button->Margin = System::Windows::Forms::Padding(2);
            this->Recomendations_button->Name = L"Recomendations_button";
            this->Recomendations_button->Size = System::Drawing::Size(135, 54);
            this->Recomendations_button->TabIndex = 8;
            this->Recomendations_button->TabStop = false;
            this->Recomendations_button->Text = L"Рекомендации(F7)";
            this->Recomendations_button->UseVisualStyleBackColor = true;
            this->Recomendations_button->Click += gcnew System::EventHandler(this, &MainWindow::Recomendations_button_Click);
            // 
            // UnworkableList_button
            // 
            this->UnworkableList_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->UnworkableList_button->Dock = System::Windows::Forms::DockStyle::Fill;
            this->UnworkableList_button->FlatAppearance->BorderSize = 0;
            this->UnworkableList_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->UnworkableList_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->UnworkableList_button->Location = System::Drawing::Point(1004, 2);
            this->UnworkableList_button->Margin = System::Windows::Forms::Padding(2);
            this->UnworkableList_button->Name = L"UnworkableList_button";
            this->UnworkableList_button->Size = System::Drawing::Size(213, 54);
            this->UnworkableList_button->TabIndex = 7;
            this->UnworkableList_button->TabStop = false;
            this->UnworkableList_button->Text = L"Лист нетрудоспособности(F8)";
            this->UnworkableList_button->UseVisualStyleBackColor = true;
            this->UnworkableList_button->Click += gcnew System::EventHandler(this, &MainWindow::UnworkableList_button_Click);
            // 
            // BackToHome_button
            // 
            this->BackToHome_button->AutoSize = true;
            this->BackToHome_button->BackColor = System::Drawing::SystemColors::ActiveBorder;
            this->BackToHome_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->BackToHome_button->Dock = System::Windows::Forms::DockStyle::Fill;
            this->BackToHome_button->FlatAppearance->BorderSize = 0;
            this->BackToHome_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BackToHome_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->BackToHome_button->Location = System::Drawing::Point(2, 2);
            this->BackToHome_button->Margin = System::Windows::Forms::Padding(2, 2, 1, 2);
            this->BackToHome_button->Name = L"BackToHome_button";
            this->BackToHome_button->Size = System::Drawing::Size(55, 54);
            this->BackToHome_button->TabIndex = 3;
            this->BackToHome_button->TabStop = false;
            this->BackToHome_button->Text = L"Home";
            this->BackToHome_button->UseVisualStyleBackColor = false;
            this->BackToHome_button->Click += gcnew System::EventHandler(this, &MainWindow::BackToHome_button_Click);
            // 
            // AnalysisResults_button
            // 
            this->AnalysisResults_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->AnalysisResults_button->Dock = System::Windows::Forms::DockStyle::Fill;
            this->AnalysisResults_button->FlatAppearance->BorderSize = 0;
            this->AnalysisResults_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->AnalysisResults_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->AnalysisResults_button->Location = System::Drawing::Point(322, 2);
            this->AnalysisResults_button->Margin = System::Windows::Forms::Padding(2);
            this->AnalysisResults_button->Name = L"AnalysisResults_button";
            this->AnalysisResults_button->Size = System::Drawing::Size(187, 54);
            this->AnalysisResults_button->TabIndex = 4;
            this->AnalysisResults_button->TabStop = false;
            this->AnalysisResults_button->Text = L"Результаты анализов (F4)";
            this->AnalysisResults_button->UseVisualStyleBackColor = true;
            this->AnalysisResults_button->Click += gcnew System::EventHandler(this, &MainWindow::AnalysisResults_button_Click);
            // 
            // BackToHome_label
            // 
            this->BackToHome_label->AutoSize = true;
            this->BackToHome_label->Dock = System::Windows::Forms::DockStyle::Top;
            this->BackToHome_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BackToHome_label->Location = System::Drawing::Point(3, 58);
            this->BackToHome_label->Name = L"BackToHome_label";
            this->BackToHome_label->Size = System::Drawing::Size(52, 13);
            this->BackToHome_label->TabIndex = 13;
            // 
            // Ill_History_label
            // 
            this->Ill_History_label->AutoSize = true;
            this->Ill_History_label->Dock = System::Windows::Forms::DockStyle::Top;
            this->Ill_History_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Ill_History_label->Location = System::Drawing::Point(61, 58);
            this->Ill_History_label->Name = L"Ill_History_label";
            this->Ill_History_label->Size = System::Drawing::Size(154, 13);
            this->Ill_History_label->TabIndex = 14;
            // 
            // Anamnesis_label
            // 
            this->Anamnesis_label->AutoSize = true;
            this->Anamnesis_label->Dock = System::Windows::Forms::DockStyle::Top;
            this->Anamnesis_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Anamnesis_label->Location = System::Drawing::Point(221, 58);
            this->Anamnesis_label->Name = L"Anamnesis_label";
            this->Anamnesis_label->Size = System::Drawing::Size(96, 13);
            this->Anamnesis_label->TabIndex = 15;
            // 
            // AnalysisResults_label
            // 
            this->AnalysisResults_label->AutoSize = true;
            this->AnalysisResults_label->Dock = System::Windows::Forms::DockStyle::Top;
            this->AnalysisResults_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->AnalysisResults_label->Location = System::Drawing::Point(323, 58);
            this->AnalysisResults_label->Name = L"AnalysisResults_label";
            this->AnalysisResults_label->Size = System::Drawing::Size(185, 13);
            this->AnalysisResults_label->TabIndex = 16;
            // 
            // AddingInfo_label
            // 
            this->AddingInfo_label->AutoSize = true;
            this->AddingInfo_label->Dock = System::Windows::Forms::DockStyle::Top;
            this->AddingInfo_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->AddingInfo_label->Location = System::Drawing::Point(514, 58);
            this->AddingInfo_label->Name = L"AddingInfo_label";
            this->AddingInfo_label->Size = System::Drawing::Size(200, 13);
            this->AddingInfo_label->TabIndex = 17;
            // 
            // SideInfo_label
            // 
            this->SideInfo_label->AutoSize = true;
            this->SideInfo_label->Dock = System::Windows::Forms::DockStyle::Top;
            this->SideInfo_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->SideInfo_label->Location = System::Drawing::Point(720, 58);
            this->SideInfo_label->Name = L"SideInfo_label";
            this->SideInfo_label->Size = System::Drawing::Size(140, 13);
            this->SideInfo_label->TabIndex = 18;
            // 
            // Recomendations_label
            // 
            this->Recomendations_label->AutoSize = true;
            this->Recomendations_label->Dock = System::Windows::Forms::DockStyle::Top;
            this->Recomendations_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Recomendations_label->Location = System::Drawing::Point(866, 58);
            this->Recomendations_label->Name = L"Recomendations_label";
            this->Recomendations_label->Size = System::Drawing::Size(133, 13);
            this->Recomendations_label->TabIndex = 19;
            // 
            // UnworkableList_label
            // 
            this->UnworkableList_label->AutoSize = true;
            this->UnworkableList_label->Dock = System::Windows::Forms::DockStyle::Top;
            this->UnworkableList_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->UnworkableList_label->Location = System::Drawing::Point(1005, 58);
            this->UnworkableList_label->Name = L"UnworkableList_label";
            this->UnworkableList_label->Size = System::Drawing::Size(211, 13);
            this->UnworkableList_label->TabIndex = 20;
            // 
            // Stamp_label
            // 
            this->Stamp_label->AutoSize = true;
            this->Stamp_label->Dock = System::Windows::Forms::DockStyle::Top;
            this->Stamp_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Stamp_label->Location = System::Drawing::Point(1222, 58);
            this->Stamp_label->Name = L"Stamp_label";
            this->Stamp_label->Size = System::Drawing::Size(88, 13);
            this->Stamp_label->TabIndex = 21;
            // 
            // tableLayoutPanel10
            // 
            this->tableLayoutPanel10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutPanel10->AutoSize = true;
            this->tableLayoutPanel10->ColumnCount = 3;
            this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                33.33333F)));
            this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                33.33334F)));
            this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                33.33334F)));
            this->tableLayoutPanel10->Controls->Add(this->groupBox11, 2, 1);
            this->tableLayoutPanel10->Controls->Add(this->groupBox10, 1, 1);
            this->tableLayoutPanel10->Controls->Add(this->groupBox9, 0, 1);
            this->tableLayoutPanel10->Controls->Add(this->groupBox8, 2, 0);
            this->tableLayoutPanel10->Controls->Add(this->groupBox7, 1, 0);
            this->tableLayoutPanel10->Controls->Add(this->groupBox6, 0, 0);
            this->tableLayoutPanel10->Location = System::Drawing::Point(0, 53);
            this->tableLayoutPanel10->Name = L"tableLayoutPanel10";
            this->tableLayoutPanel10->RowCount = 2;
            this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->tableLayoutPanel10->Size = System::Drawing::Size(1313, 100);
            this->tableLayoutPanel10->TabIndex = 5;
            // 
            // groupBox11
            // 
            this->groupBox11->Controls->Add(this->dateTimePicker3);
            this->groupBox11->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox11->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox11->Location = System::Drawing::Point(877, 53);
            this->groupBox11->Name = L"groupBox11";
            this->groupBox11->Size = System::Drawing::Size(433, 44);
            this->groupBox11->TabIndex = 5;
            this->groupBox11->TabStop = false;
            this->groupBox11->Text = L"Дата рождения*";
            // 
            // dateTimePicker3
            // 
            this->dateTimePicker3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->dateTimePicker3->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->dateTimePicker3->Location = System::Drawing::Point(3, 16);
            this->dateTimePicker3->Name = L"dateTimePicker3";
            this->dateTimePicker3->Size = System::Drawing::Size(427, 20);
            this->dateTimePicker3->TabIndex = 8;
            // 
            // groupBox10
            // 
            this->groupBox10->Controls->Add(this->comboBox8);
            this->groupBox10->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox10->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox10->Location = System::Drawing::Point(440, 53);
            this->groupBox10->Name = L"groupBox10";
            this->groupBox10->Size = System::Drawing::Size(431, 44);
            this->groupBox10->TabIndex = 4;
            this->groupBox10->TabStop = false;
            this->groupBox10->Text = L"Воинская часть*";
            // 
            // comboBox8
            // 
            this->comboBox8->Cursor = System::Windows::Forms::Cursors::Hand;
            this->comboBox8->Dock = System::Windows::Forms::DockStyle::Fill;
            this->comboBox8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->comboBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->comboBox8->FormattingEnabled = true;
            this->comboBox8->Location = System::Drawing::Point(3, 16);
            this->comboBox8->Name = L"comboBox8";
            this->comboBox8->Size = System::Drawing::Size(425, 24);
            this->comboBox8->TabIndex = 7;
            // 
            // groupBox9
            // 
            this->groupBox9->Controls->Add(this->comboBox6);
            this->groupBox9->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox9->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox9->Location = System::Drawing::Point(3, 53);
            this->groupBox9->Name = L"groupBox9";
            this->groupBox9->Size = System::Drawing::Size(431, 44);
            this->groupBox9->TabIndex = 3;
            this->groupBox9->TabStop = false;
            this->groupBox9->Text = L"Звание*";
            // 
            // comboBox6
            // 
            this->comboBox6->Cursor = System::Windows::Forms::Cursors::Hand;
            this->comboBox6->Dock = System::Windows::Forms::DockStyle::Fill;
            this->comboBox6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->comboBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->comboBox6->FormattingEnabled = true;
            this->comboBox6->Location = System::Drawing::Point(3, 16);
            this->comboBox6->Name = L"comboBox6";
            this->comboBox6->Size = System::Drawing::Size(425, 24);
            this->comboBox6->TabIndex = 6;
            // 
            // groupBox8
            // 
            this->groupBox8->Controls->Add(this->comboBox9);
            this->groupBox8->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox8->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox8->Location = System::Drawing::Point(877, 3);
            this->groupBox8->Name = L"groupBox8";
            this->groupBox8->Size = System::Drawing::Size(433, 44);
            this->groupBox8->TabIndex = 2;
            this->groupBox8->TabStop = false;
            this->groupBox8->Text = L"Отчество";
            // 
            // comboBox9
            // 
            this->comboBox9->Cursor = System::Windows::Forms::Cursors::Hand;
            this->comboBox9->Dock = System::Windows::Forms::DockStyle::Fill;
            this->comboBox9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->comboBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->comboBox9->FormattingEnabled = true;
            this->comboBox9->Location = System::Drawing::Point(3, 16);
            this->comboBox9->Name = L"comboBox9";
            this->comboBox9->Size = System::Drawing::Size(427, 24);
            this->comboBox9->TabIndex = 5;
            // 
            // groupBox7
            // 
            this->groupBox7->Controls->Add(this->Names_comboBox);
            this->groupBox7->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox7->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox7->Location = System::Drawing::Point(440, 3);
            this->groupBox7->Name = L"groupBox7";
            this->groupBox7->Size = System::Drawing::Size(431, 44);
            this->groupBox7->TabIndex = 1;
            this->groupBox7->TabStop = false;
            this->groupBox7->Text = L"Имя";
            // 
            // Names_comboBox
            // 
            this->Names_comboBox->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Names_comboBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Names_comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Names_comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Names_comboBox->FormattingEnabled = true;
            this->Names_comboBox->Location = System::Drawing::Point(3, 16);
            this->Names_comboBox->Name = L"Names_comboBox";
            this->Names_comboBox->Size = System::Drawing::Size(425, 24);
            this->Names_comboBox->TabIndex = 4;
            // 
            // groupBox6
            // 
            this->groupBox6->Controls->Add(this->comboBox5);
            this->groupBox6->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox6->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox6->Location = System::Drawing::Point(3, 3);
            this->groupBox6->Name = L"groupBox6";
            this->groupBox6->Size = System::Drawing::Size(431, 44);
            this->groupBox6->TabIndex = 0;
            this->groupBox6->TabStop = false;
            this->groupBox6->Text = L"Фамилия";
            // 
            // comboBox5
            // 
            this->comboBox5->Cursor = System::Windows::Forms::Cursors::Hand;
            this->comboBox5->Dock = System::Windows::Forms::DockStyle::Fill;
            this->comboBox5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->comboBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->comboBox5->FormattingEnabled = true;
            this->comboBox5->Location = System::Drawing::Point(3, 16);
            this->comboBox5->Name = L"comboBox5";
            this->comboBox5->Size = System::Drawing::Size(425, 24);
            this->comboBox5->TabIndex = 3;
            // 
            // SideInfo_panel
            // 
            this->SideInfo_panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->SideInfo_panel->Controls->Add(this->F7_button);
            this->SideInfo_panel->Controls->Add(this->SideInfo_groupBox);
            this->SideInfo_panel->Location = System::Drawing::Point(0, 159);
            this->SideInfo_panel->Name = L"SideInfo_panel";
            this->SideInfo_panel->Size = System::Drawing::Size(1313, 488);
            this->SideInfo_panel->TabIndex = 4;
            // 
            // F7_button
            // 
            this->F7_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->F7_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->F7_button->FlatAppearance->BorderSize = 0;
            this->F7_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->F7_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->F7_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->F7_button->Location = System::Drawing::Point(569, 226);
            this->F7_button->Name = L"F7_button";
            this->F7_button->Size = System::Drawing::Size(173, 37);
            this->F7_button->TabIndex = 16;
            this->F7_button->Text = L"Продолжить";
            this->F7_button->UseVisualStyleBackColor = true;
            this->F7_button->Click += gcnew System::EventHandler(this, &MainWindow::F7_button_Click);
            // 
            // SideInfo_groupBox
            // 
            this->SideInfo_groupBox->Controls->Add(this->SideInfo_comboBox);
            this->SideInfo_groupBox->Dock = System::Windows::Forms::DockStyle::Top;
            this->SideInfo_groupBox->Location = System::Drawing::Point(0, 0);
            this->SideInfo_groupBox->Name = L"SideInfo_groupBox";
            this->SideInfo_groupBox->Size = System::Drawing::Size(1313, 47);
            this->SideInfo_groupBox->TabIndex = 0;
            this->SideInfo_groupBox->TabStop = false;
            // 
            // SideInfo_comboBox
            // 
            this->SideInfo_comboBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->SideInfo_comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->SideInfo_comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->SideInfo_comboBox->FormattingEnabled = true;
            this->SideInfo_comboBox->Location = System::Drawing::Point(3, 16);
            this->SideInfo_comboBox->Name = L"SideInfo_comboBox";
            this->SideInfo_comboBox->Size = System::Drawing::Size(1307, 24);
            this->SideInfo_comboBox->TabIndex = 0;
            // 
            // tableLayoutPanel9
            // 
            this->tableLayoutPanel9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutPanel9->AutoSize = true;
            this->tableLayoutPanel9->ColumnCount = 4;
            this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                237)));
            this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                145)));
            this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                136)));
            this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                163)));
            this->tableLayoutPanel9->Controls->Add(this->numericUpDown2, 0, 0);
            this->tableLayoutPanel9->Controls->Add(this->numericUpDown1, 1, 0);
            this->tableLayoutPanel9->Controls->Add(this->ID_label, 0, 0);
            this->tableLayoutPanel9->Controls->Add(this->flowLayoutPanel1, 3, 0);
            this->tableLayoutPanel9->Location = System::Drawing::Point(0, 0);
            this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
            this->tableLayoutPanel9->RowCount = 1;
            this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
            this->tableLayoutPanel9->Size = System::Drawing::Size(1313, 50);
            this->tableLayoutPanel9->TabIndex = 4;
            // 
            // numericUpDown2
            // 
            this->numericUpDown2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->numericUpDown2->AutoSize = true;
            this->numericUpDown2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->numericUpDown2->Location = System::Drawing::Point(240, 10);
            this->numericUpDown2->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
            this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
            this->numericUpDown2->Name = L"numericUpDown2";
            this->numericUpDown2->Size = System::Drawing::Size(139, 29);
            this->numericUpDown2->TabIndex = 1;
            // 
            // numericUpDown1
            // 
            this->numericUpDown1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->numericUpDown1->AutoSize = true;
            this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->numericUpDown1->Location = System::Drawing::Point(385, 10);
            this->numericUpDown1->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
            this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2100, 0, 0, 0 });
            this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2024, 0, 0, 0 });
            this->numericUpDown1->Name = L"numericUpDown1";
            this->numericUpDown1->Size = System::Drawing::Size(130, 29);
            this->numericUpDown1->TabIndex = 2;
            this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2024, 0, 0, 0 });
            // 
            // ID_label
            // 
            this->ID_label->AutoSize = true;
            this->ID_label->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ID_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->ID_label->Location = System::Drawing::Point(3, 10);
            this->ID_label->Margin = System::Windows::Forms::Padding(3, 10, 3, 0);
            this->ID_label->Name = L"ID_label";
            this->ID_label->Size = System::Drawing::Size(231, 40);
            this->ID_label->TabIndex = 1;
            this->ID_label->Text = L"Номер истории болезни";
            // 
            // flowLayoutPanel1
            // 
            this->flowLayoutPanel1->Controls->Add(this->button3);
            this->flowLayoutPanel1->Controls->Add(this->Clear_button);
            this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::RightToLeft;
            this->flowLayoutPanel1->Location = System::Drawing::Point(521, 1);
            this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 1, 3, 3);
            this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
            this->flowLayoutPanel1->Size = System::Drawing::Size(789, 46);
            this->flowLayoutPanel1->TabIndex = 7;
            // 
            // button3
            // 
            this->button3->AutoSize = true;
            this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button3->Dock = System::Windows::Forms::DockStyle::Right;
            this->button3->FlatAppearance->BorderSize = 0;
            this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button3->ForeColor = System::Drawing::Color::White;
            this->button3->Location = System::Drawing::Point(662, 1);
            this->button3->Margin = System::Windows::Forms::Padding(3, 1, 3, 3);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(124, 37);
            this->button3->TabIndex = 0;
            this->button3->TabStop = false;
            this->button3->Text = L"Готово(F10)";
            this->button3->UseVisualStyleBackColor = false;
            // 
            // Clear_button
            // 
            this->Clear_button->AutoSize = true;
            this->Clear_button->BackColor = System::Drawing::SystemColors::Window;
            this->Clear_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Clear_button->Dock = System::Windows::Forms::DockStyle::Right;
            this->Clear_button->FlatAppearance->BorderSize = 0;
            this->Clear_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Clear_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Clear_button->ForeColor = System::Drawing::Color::Red;
            this->Clear_button->Location = System::Drawing::Point(532, 1);
            this->Clear_button->Margin = System::Windows::Forms::Padding(0, 1, 3, 3);
            this->Clear_button->Name = L"Clear_button";
            this->Clear_button->Size = System::Drawing::Size(124, 37);
            this->Clear_button->TabIndex = 1;
            this->Clear_button->TabStop = false;
            this->Clear_button->Text = L"Очистить";
            this->Clear_button->UseVisualStyleBackColor = false;
            // 
            // Ill_History_panel
            // 
            this->Ill_History_panel->AutoScroll = true;
            this->Ill_History_panel->AutoSize = true;
            this->Ill_History_panel->Controls->Add(this->F3_button);
            this->Ill_History_panel->Controls->Add(this->groupBox15);
            this->Ill_History_panel->Controls->Add(this->label9);
            this->Ill_History_panel->Controls->Add(this->groupBox16);
            this->Ill_History_panel->Controls->Add(this->label7);
            this->Ill_History_panel->Controls->Add(this->MKB_groupBox);
            this->Ill_History_panel->Controls->Add(this->groupBox14);
            this->Ill_History_panel->Controls->Add(this->label4);
            this->Ill_History_panel->Controls->Add(this->groupBox13);
            this->Ill_History_panel->Controls->Add(this->groupBox12);
            this->Ill_History_panel->Location = System::Drawing::Point(0, 159);
            this->Ill_History_panel->Name = L"Ill_History_panel";
            this->Ill_History_panel->Size = System::Drawing::Size(1371, 500);
            this->Ill_History_panel->TabIndex = 7;
            // 
            // F3_button
            // 
            this->F3_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->F3_button->FlatAppearance->BorderSize = 0;
            this->F3_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->F3_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->F3_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->F3_button->Location = System::Drawing::Point(570, 381);
            this->F3_button->Name = L"F3_button";
            this->F3_button->Size = System::Drawing::Size(173, 37);
            this->F3_button->TabIndex = 14;
            this->F3_button->Text = L"Продолжить";
            this->F3_button->UseVisualStyleBackColor = true;
            this->F3_button->Click += gcnew System::EventHandler(this, &MainWindow::F2_button_Click);
            // 
            // groupBox15
            // 
            this->groupBox15->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox15->Controls->Add(this->comboBox4);
            this->groupBox15->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox15->Location = System::Drawing::Point(14, 307);
            this->groupBox15->Name = L"groupBox15";
            this->groupBox15->Size = System::Drawing::Size(1291, 44);
            this->groupBox15->TabIndex = 10;
            this->groupBox15->TabStop = false;
            this->groupBox15->Text = L"Сопутствующий 1*";
            // 
            // comboBox4
            // 
            this->comboBox4->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->comboBox4->Dock = System::Windows::Forms::DockStyle::Fill;
            this->comboBox4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->comboBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->comboBox4->FormattingEnabled = true;
            this->comboBox4->Location = System::Drawing::Point(3, 18);
            this->comboBox4->Name = L"comboBox4";
            this->comboBox4->Size = System::Drawing::Size(1285, 24);
            this->comboBox4->TabIndex = 13;
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label9->Location = System::Drawing::Point(9, 270);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(153, 24);
            this->label9->TabIndex = 9;
            this->label9->Text = L"Сопутствующие";
            // 
            // groupBox16
            // 
            this->groupBox16->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox16->Controls->Add(this->comboBox3);
            this->groupBox16->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox16->Location = System::Drawing::Point(13, 201);
            this->groupBox16->Name = L"groupBox16";
            this->groupBox16->Size = System::Drawing::Size(1291, 44);
            this->groupBox16->TabIndex = 8;
            this->groupBox16->TabStop = false;
            this->groupBox16->Text = L"Сопутствующий 1*";
            // 
            // comboBox3
            // 
            this->comboBox3->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->comboBox3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->comboBox3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->comboBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->comboBox3->FormattingEnabled = true;
            this->comboBox3->Location = System::Drawing::Point(3, 18);
            this->comboBox3->Name = L"comboBox3";
            this->comboBox3->Size = System::Drawing::Size(1285, 24);
            this->comboBox3->TabIndex = 12;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label7->Location = System::Drawing::Point(9, 164);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(153, 24);
            this->label7->TabIndex = 7;
            this->label7->Text = L"Сопутствующие";
            // 
            // MKB_groupBox
            // 
            this->MKB_groupBox->Controls->Add(this->comboBox2);
            this->MKB_groupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->MKB_groupBox->Location = System::Drawing::Point(1183, 101);
            this->MKB_groupBox->Name = L"MKB_groupBox";
            this->MKB_groupBox->Size = System::Drawing::Size(115, 44);
            this->MKB_groupBox->TabIndex = 6;
            this->MKB_groupBox->TabStop = false;
            this->MKB_groupBox->Text = L"МКБ*";
            // 
            // comboBox2
            // 
            this->comboBox2->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->comboBox2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->comboBox2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->comboBox2->FormattingEnabled = true;
            this->comboBox2->Location = System::Drawing::Point(3, 18);
            this->comboBox2->Name = L"comboBox2";
            this->comboBox2->Size = System::Drawing::Size(109, 24);
            this->comboBox2->TabIndex = 13;
            // 
            // groupBox14
            // 
            this->groupBox14->Controls->Add(this->Diagnoses_comboBox);
            this->groupBox14->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox14->Location = System::Drawing::Point(13, 101);
            this->groupBox14->Name = L"groupBox14";
            this->groupBox14->Size = System::Drawing::Size(1161, 44);
            this->groupBox14->TabIndex = 5;
            this->groupBox14->TabStop = false;
            this->groupBox14->Text = L"Диагноз 1*";
            // 
            // Diagnoses_comboBox
            // 
            this->Diagnoses_comboBox->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Diagnoses_comboBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Diagnoses_comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Diagnoses_comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->Diagnoses_comboBox->FormattingEnabled = true;
            this->Diagnoses_comboBox->Location = System::Drawing::Point(3, 18);
            this->Diagnoses_comboBox->Name = L"Diagnoses_comboBox";
            this->Diagnoses_comboBox->Size = System::Drawing::Size(1155, 24);
            this->Diagnoses_comboBox->TabIndex = 11;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label4->Location = System::Drawing::Point(9, 64);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(86, 24);
            this->label4->TabIndex = 4;
            this->label4->Text = L"Диагноз";
            // 
            // groupBox13
            // 
            this->groupBox13->Controls->Add(this->dateTimePicker2);
            this->groupBox13->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox13->Location = System::Drawing::Point(224, 3);
            this->groupBox13->Name = L"groupBox13";
            this->groupBox13->Size = System::Drawing::Size(215, 44);
            this->groupBox13->TabIndex = 3;
            this->groupBox13->TabStop = false;
            this->groupBox13->Text = L"Дата выписки*";
            // 
            // dateTimePicker2
            // 
            this->dateTimePicker2->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->dateTimePicker2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->dateTimePicker2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->dateTimePicker2->Location = System::Drawing::Point(3, 18);
            this->dateTimePicker2->Name = L"dateTimePicker2";
            this->dateTimePicker2->Size = System::Drawing::Size(209, 22);
            this->dateTimePicker2->TabIndex = 10;
            this->dateTimePicker2->Value = System::DateTime(2024, 8, 14, 18, 5, 34, 0);
            // 
            // groupBox12
            // 
            this->groupBox12->Controls->Add(this->dateTimePicker1);
            this->groupBox12->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox12->Location = System::Drawing::Point(3, 3);
            this->groupBox12->Name = L"groupBox12";
            this->groupBox12->Size = System::Drawing::Size(215, 44);
            this->groupBox12->TabIndex = 2;
            this->groupBox12->TabStop = false;
            this->groupBox12->Text = L"Дата поступления*";
            // 
            // dateTimePicker1
            // 
            this->dateTimePicker1->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->dateTimePicker1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->dateTimePicker1->Location = System::Drawing::Point(3, 18);
            this->dateTimePicker1->Name = L"dateTimePicker1";
            this->dateTimePicker1->Size = System::Drawing::Size(209, 22);
            this->dateTimePicker1->TabIndex = 9;
            this->dateTimePicker1->Value = System::DateTime(2024, 8, 14, 18, 5, 14, 0);
            // 
            // Anamnesis_panel
            // 
            this->Anamnesis_panel->AutoSize = true;
            this->Anamnesis_panel->Controls->Add(this->tableLayoutPanel14);
            this->Anamnesis_panel->Location = System::Drawing::Point(2, 159);
            this->Anamnesis_panel->Name = L"Anamnesis_panel";
            this->Anamnesis_panel->Size = System::Drawing::Size(1308, 488);
            this->Anamnesis_panel->TabIndex = 0;
            // 
            // tableLayoutPanel14
            // 
            this->tableLayoutPanel14->ColumnCount = 2;
            this->tableLayoutPanel14->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
            this->tableLayoutPanel14->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
            this->tableLayoutPanel14->Controls->Add(this->panel3, 0, 0);
            this->tableLayoutPanel14->Controls->Add(this->panel2, 1, 0);
            this->tableLayoutPanel14->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel14->Location = System::Drawing::Point(0, 0);
            this->tableLayoutPanel14->Name = L"tableLayoutPanel14";
            this->tableLayoutPanel14->RowCount = 1;
            this->tableLayoutPanel14->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel14->Size = System::Drawing::Size(1308, 488);
            this->tableLayoutPanel14->TabIndex = 2;
            // 
            // panel3
            // 
            this->panel3->AutoScroll = true;
            this->panel3->Controls->Add(this->tableLayoutPanel11);
            this->panel3->Location = System::Drawing::Point(3, 3);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(615, 488);
            this->panel3->TabIndex = 1;
            // 
            // tableLayoutPanel11
            // 
            this->tableLayoutPanel11->AutoSize = true;
            this->tableLayoutPanel11->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->tableLayoutPanel11->ColumnCount = 1;
            this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
            this->tableLayoutPanel11->Controls->Add(this->NapravlenV_tableLayoutPanel, 0, 7);
            this->tableLayoutPanel11->Controls->Add(this->label15, 0, 10);
            this->tableLayoutPanel11->Controls->Add(this->groupBox19, 0, 9);
            this->tableLayoutPanel11->Controls->Add(this->label14, 0, 8);
            this->tableLayoutPanel11->Controls->Add(this->label13, 0, 6);
            this->tableLayoutPanel11->Controls->Add(this->groupBox18, 0, 5);
            this->tableLayoutPanel11->Controls->Add(this->flowLayoutPanel3, 0, 4);
            this->tableLayoutPanel11->Controls->Add(this->groupBox17, 0, 2);
            this->tableLayoutPanel11->Controls->Add(this->flowLayoutPanel2, 0, 1);
            this->tableLayoutPanel11->Controls->Add(this->label12, 0, 3);
            this->tableLayoutPanel11->Controls->Add(this->FOGK_checkBox, 0, 11);
            this->tableLayoutPanel11->Controls->Add(this->RgOGK_checkBox, 0, 12);
            this->tableLayoutPanel11->Controls->Add(this->KT_OGK_checkBox, 0, 13);
            this->tableLayoutPanel11->Controls->Add(this->OAK_checkBox, 0, 14);
            this->tableLayoutPanel11->Controls->Add(this->OAM_checkBox, 0, 15);
            this->tableLayoutPanel11->Controls->Add(this->BioChemicalBloodResearch_checkBox, 0, 16);
            this->tableLayoutPanel11->Controls->Add(this->label11, 0, 0);
            this->tableLayoutPanel11->Dock = System::Windows::Forms::DockStyle::Top;
            this->tableLayoutPanel11->Location = System::Drawing::Point(0, 0);
            this->tableLayoutPanel11->Name = L"tableLayoutPanel11";
            this->tableLayoutPanel11->RowCount = 21;
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel11->Size = System::Drawing::Size(598, 705);
            this->tableLayoutPanel11->TabIndex = 0;
            // 
            // NapravlenV_tableLayoutPanel
            // 
            this->NapravlenV_tableLayoutPanel->AutoSize = true;
            this->NapravlenV_tableLayoutPanel->ColumnCount = 1;
            this->NapravlenV_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->NapravlenV_tableLayoutPanel->Controls->Add(this->flowLayoutPanel5, 0, 0);
            this->NapravlenV_tableLayoutPanel->Controls->Add(this->NapravlenieVGospital_tableLayoutPanel, 0, 1);
            this->NapravlenV_tableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->NapravlenV_tableLayoutPanel->Location = System::Drawing::Point(3, 244);
            this->NapravlenV_tableLayoutPanel->Name = L"NapravlenV_tableLayoutPanel";
            this->NapravlenV_tableLayoutPanel->RowCount = 2;
            this->NapravlenV_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->NapravlenV_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->NapravlenV_tableLayoutPanel->Size = System::Drawing::Size(610, 211);
            this->NapravlenV_tableLayoutPanel->TabIndex = 15;
            // 
            // flowLayoutPanel5
            // 
            this->flowLayoutPanel5->Controls->Add(this->SentToGospital_radioButton);
            this->flowLayoutPanel5->Controls->Add(this->SentToLazaret_radioButton);
            this->flowLayoutPanel5->Controls->Add(this->SentToPolyclinic_radioButton);
            this->flowLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel5->Location = System::Drawing::Point(3, 3);
            this->flowLayoutPanel5->Name = L"flowLayoutPanel5";
            this->flowLayoutPanel5->Size = System::Drawing::Size(604, 25);
            this->flowLayoutPanel5->TabIndex = 0;
            // 
            // SentToGospital_radioButton
            // 
            this->SentToGospital_radioButton->AutoSize = true;
            this->SentToGospital_radioButton->Checked = true;
            this->SentToGospital_radioButton->Cursor = System::Windows::Forms::Cursors::Hand;
            this->SentToGospital_radioButton->FlatAppearance->BorderSize = 0;
            this->SentToGospital_radioButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->SentToGospital_radioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->SentToGospital_radioButton->Location = System::Drawing::Point(3, 3);
            this->SentToGospital_radioButton->Name = L"SentToGospital_radioButton";
            this->SentToGospital_radioButton->Size = System::Drawing::Size(92, 20);
            this->SentToGospital_radioButton->TabIndex = 0;
            this->SentToGospital_radioButton->TabStop = true;
            this->SentToGospital_radioButton->Text = L"Госпиталь";
            this->SentToGospital_radioButton->UseVisualStyleBackColor = true;
            this->SentToGospital_radioButton->Click += gcnew System::EventHandler(this, &MainWindow::SentToGospital_radioButton_Click);
            // 
            // SentToLazaret_radioButton
            // 
            this->SentToLazaret_radioButton->AutoSize = true;
            this->SentToLazaret_radioButton->Cursor = System::Windows::Forms::Cursors::Hand;
            this->SentToLazaret_radioButton->FlatAppearance->BorderSize = 0;
            this->SentToLazaret_radioButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->SentToLazaret_radioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->SentToLazaret_radioButton->Location = System::Drawing::Point(101, 3);
            this->SentToLazaret_radioButton->Name = L"SentToLazaret_radioButton";
            this->SentToLazaret_radioButton->Size = System::Drawing::Size(80, 20);
            this->SentToLazaret_radioButton->TabIndex = 1;
            this->SentToLazaret_radioButton->Text = L"Лазарет";
            this->SentToLazaret_radioButton->UseVisualStyleBackColor = true;
            this->SentToLazaret_radioButton->Click += gcnew System::EventHandler(this, &MainWindow::SentToLazaret_radioButton_Click);
            // 
            // SentToPolyclinic_radioButton
            // 
            this->SentToPolyclinic_radioButton->AutoSize = true;
            this->SentToPolyclinic_radioButton->Cursor = System::Windows::Forms::Cursors::Hand;
            this->SentToPolyclinic_radioButton->FlatAppearance->BorderSize = 0;
            this->SentToPolyclinic_radioButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->SentToPolyclinic_radioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->SentToPolyclinic_radioButton->Location = System::Drawing::Point(187, 3);
            this->SentToPolyclinic_radioButton->Name = L"SentToPolyclinic_radioButton";
            this->SentToPolyclinic_radioButton->Size = System::Drawing::Size(112, 20);
            this->SentToPolyclinic_radioButton->TabIndex = 2;
            this->SentToPolyclinic_radioButton->Text = L"Поликлинику";
            this->SentToPolyclinic_radioButton->UseVisualStyleBackColor = true;
            this->SentToPolyclinic_radioButton->Click += gcnew System::EventHandler(this, &MainWindow::SentToPolyclinic_radioButton_Click);
            // 
            // NapravlenieVGospital_tableLayoutPanel
            // 
            this->NapravlenieVGospital_tableLayoutPanel->AutoSize = true;
            this->NapravlenieVGospital_tableLayoutPanel->ColumnCount = 1;
            this->NapravlenieVGospital_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->NapravlenieVGospital_tableLayoutPanel->Controls->Add(this->NapravlenVpolyclonic_panel, 0, 0);
            this->NapravlenieVGospital_tableLayoutPanel->Controls->Add(this->NapravlenVLazaret_panel, 0, 1);
            this->NapravlenieVGospital_tableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->NapravlenieVGospital_tableLayoutPanel->Location = System::Drawing::Point(3, 34);
            this->NapravlenieVGospital_tableLayoutPanel->Name = L"NapravlenieVGospital_tableLayoutPanel";
            this->NapravlenieVGospital_tableLayoutPanel->RowCount = 2;
            this->NapravlenieVGospital_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->NapravlenieVGospital_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->NapravlenieVGospital_tableLayoutPanel->Size = System::Drawing::Size(604, 174);
            this->NapravlenieVGospital_tableLayoutPanel->TabIndex = 14;
            this->NapravlenieVGospital_tableLayoutPanel->Visible = false;
            // 
            // NapravlenVpolyclonic_panel
            // 
            this->NapravlenVpolyclonic_panel->AutoSize = true;
            this->NapravlenVpolyclonic_panel->Controls->Add(this->RepeatCheck_groupBox);
            this->NapravlenVpolyclonic_panel->Controls->Add(this->AmbulanceHealing_radioButton);
            this->NapravlenVpolyclonic_panel->Controls->Add(this->Gospitalization_radioButton);
            this->NapravlenVpolyclonic_panel->Controls->Add(this->label10);
            this->NapravlenVpolyclonic_panel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->NapravlenVpolyclonic_panel->Location = System::Drawing::Point(3, 3);
            this->NapravlenVpolyclonic_panel->Name = L"NapravlenVpolyclonic_panel";
            this->NapravlenVpolyclonic_panel->Size = System::Drawing::Size(598, 104);
            this->NapravlenVpolyclonic_panel->TabIndex = 3;
            // 
            // RepeatCheck_groupBox
            // 
            this->RepeatCheck_groupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->RepeatCheck_groupBox->Controls->Add(this->RepeatCheck_dateTimePicker);
            this->RepeatCheck_groupBox->Controls->Add(this->label16);
            this->RepeatCheck_groupBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->RepeatCheck_groupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->RepeatCheck_groupBox->Location = System::Drawing::Point(9, 55);
            this->RepeatCheck_groupBox->Name = L"RepeatCheck_groupBox";
            this->RepeatCheck_groupBox->Size = System::Drawing::Size(574, 46);
            this->RepeatCheck_groupBox->TabIndex = 12;
            this->RepeatCheck_groupBox->TabStop = false;
            this->RepeatCheck_groupBox->Text = L"Дата повторного осмотра";
            this->RepeatCheck_groupBox->Visible = false;
            // 
            // RepeatCheck_dateTimePicker
            // 
            this->RepeatCheck_dateTimePicker->Dock = System::Windows::Forms::DockStyle::Fill;
            this->RepeatCheck_dateTimePicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->RepeatCheck_dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->RepeatCheck_dateTimePicker->Location = System::Drawing::Point(3, 18);
            this->RepeatCheck_dateTimePicker->Name = L"RepeatCheck_dateTimePicker";
            this->RepeatCheck_dateTimePicker->Size = System::Drawing::Size(568, 22);
            this->RepeatCheck_dateTimePicker->TabIndex = 8;
            this->RepeatCheck_dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &MainWindow::RepeatCheck_dateTimePicker_ValueChanged);
            // 
            // label16
            // 
            this->label16->AutoSize = true;
            this->label16->Location = System::Drawing::Point(106, 18);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(86, 16);
            this->label16->TabIndex = 12;
            this->label16->Text = L"Назначено*";
            this->label16->Visible = false;
            // 
            // AmbulanceHealing_radioButton
            // 
            this->AmbulanceHealing_radioButton->AutoSize = true;
            this->AmbulanceHealing_radioButton->Cursor = System::Windows::Forms::Cursors::Hand;
            this->AmbulanceHealing_radioButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->AmbulanceHealing_radioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->AmbulanceHealing_radioButton->Location = System::Drawing::Point(145, 29);
            this->AmbulanceHealing_radioButton->Name = L"AmbulanceHealing_radioButton";
            this->AmbulanceHealing_radioButton->Size = System::Drawing::Size(180, 20);
            this->AmbulanceHealing_radioButton->TabIndex = 2;
            this->AmbulanceHealing_radioButton->Text = L"Амбулаторное лечение";
            this->AmbulanceHealing_radioButton->UseVisualStyleBackColor = true;
            this->AmbulanceHealing_radioButton->Click += gcnew System::EventHandler(this, &MainWindow::AmbulanceHealing_radioButton_Click);
            // 
            // Gospitalization_radioButton
            // 
            this->Gospitalization_radioButton->AutoSize = true;
            this->Gospitalization_radioButton->Checked = true;
            this->Gospitalization_radioButton->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Gospitalization_radioButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Gospitalization_radioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->Gospitalization_radioButton->Location = System::Drawing::Point(9, 29);
            this->Gospitalization_radioButton->Name = L"Gospitalization_radioButton";
            this->Gospitalization_radioButton->Size = System::Drawing::Size(132, 20);
            this->Gospitalization_radioButton->TabIndex = 1;
            this->Gospitalization_radioButton->TabStop = true;
            this->Gospitalization_radioButton->Text = L"Госпитализация";
            this->Gospitalization_radioButton->UseVisualStyleBackColor = true;
            this->Gospitalization_radioButton->Click += gcnew System::EventHandler(this, &MainWindow::Gospitalization_radioButton_Click);
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label10->Location = System::Drawing::Point(6, 6);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(86, 16);
            this->label10->TabIndex = 0;
            this->label10->Text = L"Назначено*";
            // 
            // NapravlenVLazaret_panel
            // 
            this->NapravlenVLazaret_panel->AutoSize = true;
            this->NapravlenVLazaret_panel->Controls->Add(this->GospitalSentDate_groupBox);
            this->NapravlenVLazaret_panel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->NapravlenVLazaret_panel->Location = System::Drawing::Point(3, 113);
            this->NapravlenVLazaret_panel->Name = L"NapravlenVLazaret_panel";
            this->NapravlenVLazaret_panel->Size = System::Drawing::Size(598, 58);
            this->NapravlenVLazaret_panel->TabIndex = 13;
            // 
            // GospitalSentDate_groupBox
            // 
            this->GospitalSentDate_groupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->GospitalSentDate_groupBox->Controls->Add(this->GospitalSentDate_dateTimePicker);
            this->GospitalSentDate_groupBox->Controls->Add(this->TrackTo_label);
            this->GospitalSentDate_groupBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->GospitalSentDate_groupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->GospitalSentDate_groupBox->Location = System::Drawing::Point(9, 3);
            this->GospitalSentDate_groupBox->Name = L"GospitalSentDate_groupBox";
            this->GospitalSentDate_groupBox->Size = System::Drawing::Size(574, 52);
            this->GospitalSentDate_groupBox->TabIndex = 11;
            this->GospitalSentDate_groupBox->TabStop = false;
            this->GospitalSentDate_groupBox->Text = L"Дата направления в госпиталь*";
            // 
            // GospitalSentDate_dateTimePicker
            // 
            this->GospitalSentDate_dateTimePicker->Dock = System::Windows::Forms::DockStyle::Fill;
            this->GospitalSentDate_dateTimePicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->GospitalSentDate_dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->GospitalSentDate_dateTimePicker->Location = System::Drawing::Point(3, 18);
            this->GospitalSentDate_dateTimePicker->Name = L"GospitalSentDate_dateTimePicker";
            this->GospitalSentDate_dateTimePicker->Size = System::Drawing::Size(568, 22);
            this->GospitalSentDate_dateTimePicker->TabIndex = 8;
            this->GospitalSentDate_dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &MainWindow::GospitalSentDate_dateTimePicker_ValueChanged);
            // 
            // TrackTo_label
            // 
            this->TrackTo_label->AutoSize = true;
            this->TrackTo_label->Location = System::Drawing::Point(106, 18);
            this->TrackTo_label->Name = L"TrackTo_label";
            this->TrackTo_label->Size = System::Drawing::Size(86, 16);
            this->TrackTo_label->TabIndex = 12;
            this->TrackTo_label->Text = L"Назначено*";
            this->TrackTo_label->Visible = false;
            // 
            // label15
            // 
            this->label15->AutoSize = true;
            this->label15->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label15->Location = System::Drawing::Point(3, 533);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(610, 16);
            this->label15->TabIndex = 14;
            this->label15->Text = L"Обследования*";
            // 
            // groupBox19
            // 
            this->groupBox19->Controls->Add(this->ResearchDate_dateTimePicker);
            this->groupBox19->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox19->Location = System::Drawing::Point(3, 485);
            this->groupBox19->Name = L"groupBox19";
            this->groupBox19->Size = System::Drawing::Size(589, 45);
            this->groupBox19->TabIndex = 13;
            this->groupBox19->TabStop = false;
            this->groupBox19->Text = L"Дата*";
            // 
            // ResearchDate_dateTimePicker
            // 
            this->ResearchDate_dateTimePicker->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ResearchDate_dateTimePicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->ResearchDate_dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->ResearchDate_dateTimePicker->Location = System::Drawing::Point(3, 18);
            this->ResearchDate_dateTimePicker->Name = L"ResearchDate_dateTimePicker";
            this->ResearchDate_dateTimePicker->Size = System::Drawing::Size(583, 22);
            this->ResearchDate_dateTimePicker->TabIndex = 8;
            this->ResearchDate_dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &MainWindow::ResearchDate_dateTimePicker_ValueChanged);
            // 
            // label14
            // 
            this->label14->AutoSize = true;
            this->label14->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->label14->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label14->Location = System::Drawing::Point(3, 458);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(610, 24);
            this->label14->TabIndex = 12;
            this->label14->Text = L"Обследования";
            // 
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->label13->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label13->Location = System::Drawing::Point(3, 221);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(610, 20);
            this->label13->TabIndex = 10;
            this->label13->Text = L"Направлен в*";
            // 
            // groupBox18
            // 
            this->groupBox18->Controls->Add(this->ResponseDate_dateTimePicker);
            this->groupBox18->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox18->Location = System::Drawing::Point(3, 171);
            this->groupBox18->Name = L"groupBox18";
            this->groupBox18->Size = System::Drawing::Size(589, 47);
            this->groupBox18->TabIndex = 9;
            this->groupBox18->TabStop = false;
            this->groupBox18->Text = L"Дата обращения*";
            // 
            // ResponseDate_dateTimePicker
            // 
            this->ResponseDate_dateTimePicker->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ResponseDate_dateTimePicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->ResponseDate_dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->ResponseDate_dateTimePicker->Location = System::Drawing::Point(3, 18);
            this->ResponseDate_dateTimePicker->Name = L"ResponseDate_dateTimePicker";
            this->ResponseDate_dateTimePicker->Size = System::Drawing::Size(583, 22);
            this->ResponseDate_dateTimePicker->TabIndex = 8;
            this->ResponseDate_dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &MainWindow::ResponseDate_dateTimePicker_ValueChanged);
            // 
            // flowLayoutPanel3
            // 
            this->flowLayoutPanel3->Controls->Add(this->ResponseMedstation_radioButton);
            this->flowLayoutPanel3->Controls->Add(this->ResponseGospital_radioButton);
            this->flowLayoutPanel3->Controls->Add(this->ResponsePolyclinic_radioButton);
            this->flowLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel3->Location = System::Drawing::Point(3, 137);
            this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
            this->flowLayoutPanel3->Size = System::Drawing::Size(610, 28);
            this->flowLayoutPanel3->TabIndex = 8;
            // 
            // ResponseMedstation_radioButton
            // 
            this->ResponseMedstation_radioButton->AutoSize = true;
            this->ResponseMedstation_radioButton->Checked = true;
            this->ResponseMedstation_radioButton->Cursor = System::Windows::Forms::Cursors::Hand;
            this->ResponseMedstation_radioButton->Dock = System::Windows::Forms::DockStyle::Left;
            this->ResponseMedstation_radioButton->FlatAppearance->BorderSize = 0;
            this->ResponseMedstation_radioButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->ResponseMedstation_radioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->ResponseMedstation_radioButton->Location = System::Drawing::Point(3, 3);
            this->ResponseMedstation_radioButton->Name = L"ResponseMedstation_radioButton";
            this->ResponseMedstation_radioButton->Size = System::Drawing::Size(89, 20);
            this->ResponseMedstation_radioButton->TabIndex = 0;
            this->ResponseMedstation_radioButton->TabStop = true;
            this->ResponseMedstation_radioButton->Text = L"Медпункт";
            this->ResponseMedstation_radioButton->UseVisualStyleBackColor = true;
            this->ResponseMedstation_radioButton->Click += gcnew System::EventHandler(this, &MainWindow::ResponseMedstation_radioButton_Click);
            // 
            // ResponseGospital_radioButton
            // 
            this->ResponseGospital_radioButton->AutoSize = true;
            this->ResponseGospital_radioButton->Cursor = System::Windows::Forms::Cursors::Hand;
            this->ResponseGospital_radioButton->Dock = System::Windows::Forms::DockStyle::Left;
            this->ResponseGospital_radioButton->FlatAppearance->BorderSize = 0;
            this->ResponseGospital_radioButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->ResponseGospital_radioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->ResponseGospital_radioButton->Location = System::Drawing::Point(98, 3);
            this->ResponseGospital_radioButton->Name = L"ResponseGospital_radioButton";
            this->ResponseGospital_radioButton->Size = System::Drawing::Size(92, 20);
            this->ResponseGospital_radioButton->TabIndex = 1;
            this->ResponseGospital_radioButton->Text = L"Госпиталь";
            this->ResponseGospital_radioButton->UseVisualStyleBackColor = true;
            this->ResponseGospital_radioButton->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::ResponseGospital_radioButton_CheckedChanged);
            // 
            // ResponsePolyclinic_radioButton
            // 
            this->ResponsePolyclinic_radioButton->AutoSize = true;
            this->ResponsePolyclinic_radioButton->Cursor = System::Windows::Forms::Cursors::Hand;
            this->ResponsePolyclinic_radioButton->Dock = System::Windows::Forms::DockStyle::Left;
            this->ResponsePolyclinic_radioButton->FlatAppearance->BorderSize = 0;
            this->ResponsePolyclinic_radioButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->ResponsePolyclinic_radioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->ResponsePolyclinic_radioButton->Location = System::Drawing::Point(196, 3);
            this->ResponsePolyclinic_radioButton->Name = L"ResponsePolyclinic_radioButton";
            this->ResponsePolyclinic_radioButton->Size = System::Drawing::Size(112, 20);
            this->ResponsePolyclinic_radioButton->TabIndex = 2;
            this->ResponsePolyclinic_radioButton->Text = L"Поликлинику";
            this->ResponsePolyclinic_radioButton->UseVisualStyleBackColor = true;
            this->ResponsePolyclinic_radioButton->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::ResponsePolyclinic_radioButton_CheckedChanged);
            // 
            // groupBox17
            // 
            this->groupBox17->Controls->Add(this->IllBegining_dateTimePicker);
            this->groupBox17->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox17->Location = System::Drawing::Point(3, 62);
            this->groupBox17->Name = L"groupBox17";
            this->groupBox17->Size = System::Drawing::Size(589, 49);
            this->groupBox17->TabIndex = 6;
            this->groupBox17->TabStop = false;
            this->groupBox17->Text = L"Заболел*";
            // 
            // IllBegining_dateTimePicker
            // 
            this->IllBegining_dateTimePicker->Dock = System::Windows::Forms::DockStyle::Fill;
            this->IllBegining_dateTimePicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->IllBegining_dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->IllBegining_dateTimePicker->Location = System::Drawing::Point(3, 18);
            this->IllBegining_dateTimePicker->Name = L"IllBegining_dateTimePicker";
            this->IllBegining_dateTimePicker->Size = System::Drawing::Size(583, 22);
            this->IllBegining_dateTimePicker->TabIndex = 8;
            this->IllBegining_dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &MainWindow::IllBegining_dateTimePicker_ValueChanged);
            // 
            // flowLayoutPanel2
            // 
            this->flowLayoutPanel2->Controls->Add(this->Pnevmonia_radioButton);
            this->flowLayoutPanel2->Controls->Add(this->Astenia_radioButton);
            this->flowLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel2->Location = System::Drawing::Point(3, 23);
            this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
            this->flowLayoutPanel2->Size = System::Drawing::Size(610, 33);
            this->flowLayoutPanel2->TabIndex = 1;
            // 
            // Pnevmonia_radioButton
            // 
            this->Pnevmonia_radioButton->AutoSize = true;
            this->Pnevmonia_radioButton->Checked = true;
            this->Pnevmonia_radioButton->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Pnevmonia_radioButton->Dock = System::Windows::Forms::DockStyle::Left;
            this->Pnevmonia_radioButton->FlatAppearance->BorderSize = 0;
            this->Pnevmonia_radioButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Pnevmonia_radioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->Pnevmonia_radioButton->Location = System::Drawing::Point(3, 3);
            this->Pnevmonia_radioButton->Name = L"Pnevmonia_radioButton";
            this->Pnevmonia_radioButton->Size = System::Drawing::Size(157, 20);
            this->Pnevmonia_radioButton->TabIndex = 0;
            this->Pnevmonia_radioButton->TabStop = true;
            this->Pnevmonia_radioButton->Text = L"Пневмония, бронхит";
            this->Pnevmonia_radioButton->UseVisualStyleBackColor = true;
            this->Pnevmonia_radioButton->Click += gcnew System::EventHandler(this, &MainWindow::Pnevmonia_radioButton_Click);
            // 
            // Astenia_radioButton
            // 
            this->Astenia_radioButton->AutoSize = true;
            this->Astenia_radioButton->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Astenia_radioButton->Dock = System::Windows::Forms::DockStyle::Left;
            this->Astenia_radioButton->FlatAppearance->BorderSize = 0;
            this->Astenia_radioButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Astenia_radioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->Astenia_radioButton->Location = System::Drawing::Point(166, 3);
            this->Astenia_radioButton->Name = L"Astenia_radioButton";
            this->Astenia_radioButton->Size = System::Drawing::Size(78, 20);
            this->Astenia_radioButton->TabIndex = 1;
            this->Astenia_radioButton->Text = L"Астения";
            this->Astenia_radioButton->UseVisualStyleBackColor = true;
            this->Astenia_radioButton->Click += gcnew System::EventHandler(this, &MainWindow::Astenia_radioButton_Click);
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label12->Location = System::Drawing::Point(3, 114);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(610, 20);
            this->label12->TabIndex = 7;
            this->label12->Text = L"Обратился в*";
            // 
            // FOGK_checkBox
            // 
            this->FOGK_checkBox->AutoSize = true;
            this->FOGK_checkBox->Checked = true;
            this->FOGK_checkBox->CheckState = System::Windows::Forms::CheckState::Checked;
            this->FOGK_checkBox->Cursor = System::Windows::Forms::Cursors::Hand;
            this->FOGK_checkBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->FOGK_checkBox->FlatAppearance->BorderSize = 0;
            this->FOGK_checkBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->FOGK_checkBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->FOGK_checkBox->ForeColor = System::Drawing::SystemColors::ControlText;
            this->FOGK_checkBox->Location = System::Drawing::Point(3, 552);
            this->FOGK_checkBox->Name = L"FOGK_checkBox";
            this->FOGK_checkBox->Size = System::Drawing::Size(610, 20);
            this->FOGK_checkBox->TabIndex = 15;
            this->FOGK_checkBox->Text = L"ФОГК";
            this->FOGK_checkBox->UseVisualStyleBackColor = true;
            this->FOGK_checkBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::FOGK_checkBox_CheckedChanged);
            // 
            // RgOGK_checkBox
            // 
            this->RgOGK_checkBox->AutoSize = true;
            this->RgOGK_checkBox->Cursor = System::Windows::Forms::Cursors::Hand;
            this->RgOGK_checkBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->RgOGK_checkBox->FlatAppearance->BorderSize = 0;
            this->RgOGK_checkBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->RgOGK_checkBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->RgOGK_checkBox->ForeColor = System::Drawing::SystemColors::ControlText;
            this->RgOGK_checkBox->Location = System::Drawing::Point(3, 578);
            this->RgOGK_checkBox->Name = L"RgOGK_checkBox";
            this->RgOGK_checkBox->Size = System::Drawing::Size(610, 20);
            this->RgOGK_checkBox->TabIndex = 16;
            this->RgOGK_checkBox->Text = L"Rg ОГК";
            this->RgOGK_checkBox->UseVisualStyleBackColor = true;
            this->RgOGK_checkBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::RgOGK_checkBox_CheckedChanged);
            // 
            // KT_OGK_checkBox
            // 
            this->KT_OGK_checkBox->AutoSize = true;
            this->KT_OGK_checkBox->Cursor = System::Windows::Forms::Cursors::Hand;
            this->KT_OGK_checkBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->KT_OGK_checkBox->FlatAppearance->BorderSize = 0;
            this->KT_OGK_checkBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->KT_OGK_checkBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->KT_OGK_checkBox->ForeColor = System::Drawing::SystemColors::ControlText;
            this->KT_OGK_checkBox->Location = System::Drawing::Point(3, 604);
            this->KT_OGK_checkBox->Name = L"KT_OGK_checkBox";
            this->KT_OGK_checkBox->Size = System::Drawing::Size(610, 20);
            this->KT_OGK_checkBox->TabIndex = 17;
            this->KT_OGK_checkBox->Text = L"КТ ОГК";
            this->KT_OGK_checkBox->UseVisualStyleBackColor = true;
            this->KT_OGK_checkBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::KT_OGK_checkBox_CheckedChanged);
            // 
            // OAK_checkBox
            // 
            this->OAK_checkBox->AutoSize = true;
            this->OAK_checkBox->Cursor = System::Windows::Forms::Cursors::Hand;
            this->OAK_checkBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->OAK_checkBox->FlatAppearance->BorderSize = 0;
            this->OAK_checkBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->OAK_checkBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->OAK_checkBox->ForeColor = System::Drawing::SystemColors::ControlText;
            this->OAK_checkBox->Location = System::Drawing::Point(3, 630);
            this->OAK_checkBox->Name = L"OAK_checkBox";
            this->OAK_checkBox->Size = System::Drawing::Size(610, 20);
            this->OAK_checkBox->TabIndex = 18;
            this->OAK_checkBox->Text = L"ОАК";
            this->OAK_checkBox->UseVisualStyleBackColor = true;
            this->OAK_checkBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::OAK_checkBox_CheckedChanged);
            // 
            // OAM_checkBox
            // 
            this->OAM_checkBox->AutoSize = true;
            this->OAM_checkBox->Cursor = System::Windows::Forms::Cursors::Hand;
            this->OAM_checkBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->OAM_checkBox->FlatAppearance->BorderSize = 0;
            this->OAM_checkBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->OAM_checkBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->OAM_checkBox->ForeColor = System::Drawing::SystemColors::ControlText;
            this->OAM_checkBox->Location = System::Drawing::Point(3, 656);
            this->OAM_checkBox->Name = L"OAM_checkBox";
            this->OAM_checkBox->Size = System::Drawing::Size(610, 20);
            this->OAM_checkBox->TabIndex = 19;
            this->OAM_checkBox->Text = L"ОАМ";
            this->OAM_checkBox->UseVisualStyleBackColor = true;
            this->OAM_checkBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::OAM_checkBox_CheckedChanged);
            // 
            // BioChemicalBloodResearch_checkBox
            // 
            this->BioChemicalBloodResearch_checkBox->AutoSize = true;
            this->BioChemicalBloodResearch_checkBox->Cursor = System::Windows::Forms::Cursors::Hand;
            this->BioChemicalBloodResearch_checkBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->BioChemicalBloodResearch_checkBox->FlatAppearance->BorderSize = 0;
            this->BioChemicalBloodResearch_checkBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BioChemicalBloodResearch_checkBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->BioChemicalBloodResearch_checkBox->ForeColor = System::Drawing::SystemColors::ControlText;
            this->BioChemicalBloodResearch_checkBox->Location = System::Drawing::Point(3, 682);
            this->BioChemicalBloodResearch_checkBox->Name = L"BioChemicalBloodResearch_checkBox";
            this->BioChemicalBloodResearch_checkBox->Size = System::Drawing::Size(610, 20);
            this->BioChemicalBloodResearch_checkBox->TabIndex = 20;
            this->BioChemicalBloodResearch_checkBox->Text = L"Биохимическое исследование крови";
            this->BioChemicalBloodResearch_checkBox->UseVisualStyleBackColor = true;
            this->BioChemicalBloodResearch_checkBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::BioChemicalBloodResearch_checkBox_CheckedChanged);
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label11->Location = System::Drawing::Point(3, 0);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(117, 20);
            this->label11->TabIndex = 0;
            this->label11->Text = L"Заболевание*";
            // 
            // panel2
            // 
            this->panel2->AutoSize = true;
            this->panel2->Controls->Add(this->F4_button);
            this->panel2->Controls->Add(this->groupBox20);
            this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panel2->Location = System::Drawing::Point(624, 3);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(681, 488);
            this->panel2->TabIndex = 3;
            // 
            // F4_button
            // 
            this->F4_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->F4_button->FlatAppearance->BorderSize = 0;
            this->F4_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->F4_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->F4_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->F4_button->Location = System::Drawing::Point(254, 161);
            this->F4_button->Name = L"F4_button";
            this->F4_button->Size = System::Drawing::Size(173, 37);
            this->F4_button->TabIndex = 15;
            this->F4_button->Text = L"Продолжить";
            this->F4_button->UseVisualStyleBackColor = true;
            this->F4_button->Click += gcnew System::EventHandler(this, &MainWindow::F3_button_Click);
            // 
            // groupBox20
            // 
            this->groupBox20->Controls->Add(this->Anamnesis_textBox);
            this->groupBox20->Dock = System::Windows::Forms::DockStyle::Top;
            this->groupBox20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox20->Location = System::Drawing::Point(0, 0);
            this->groupBox20->Name = L"groupBox20";
            this->groupBox20->Size = System::Drawing::Size(681, 139);
            this->groupBox20->TabIndex = 2;
            this->groupBox20->TabStop = false;
            this->groupBox20->Text = L"Анамнез (Ctlr+S)";
            // 
            // Anamnesis_textBox
            // 
            this->Anamnesis_textBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->Anamnesis_textBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Anamnesis_textBox->Location = System::Drawing::Point(3, 22);
            this->Anamnesis_textBox->Multiline = true;
            this->Anamnesis_textBox->Name = L"Anamnesis_textBox";
            this->Anamnesis_textBox->Size = System::Drawing::Size(675, 114);
            this->Anamnesis_textBox->TabIndex = 1;
            this->Anamnesis_textBox->Text = L"\r\n";
            // 
            // AnalysisResults_panel
            // 
            this->AnalysisResults_panel->AutoSize = true;
            this->AnalysisResults_panel->Controls->Add(this->F5_button);
            this->AnalysisResults_panel->Controls->Add(this->AnalysisResults_groupBox);
            this->AnalysisResults_panel->Location = System::Drawing::Point(2, 159);
            this->AnalysisResults_panel->Name = L"AnalysisResults_panel";
            this->AnalysisResults_panel->Size = System::Drawing::Size(1308, 354);
            this->AnalysisResults_panel->TabIndex = 8;
            this->AnalysisResults_panel->Visible = false;
            // 
            // F5_button
            // 
            this->F5_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->F5_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->F5_button->FlatAppearance->BorderSize = 0;
            this->F5_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->F5_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->F5_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->F5_button->Location = System::Drawing::Point(569, 79);
            this->F5_button->Name = L"F5_button";
            this->F5_button->Size = System::Drawing::Size(173, 37);
            this->F5_button->TabIndex = 16;
            this->F5_button->Text = L"Продолжить";
            this->F5_button->UseVisualStyleBackColor = true;
            this->F5_button->Click += gcnew System::EventHandler(this, &MainWindow::F5_button_Click);
            // 
            // AnalysisResults_groupBox
            // 
            this->AnalysisResults_groupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->AnalysisResults_groupBox->AutoSize = true;
            this->AnalysisResults_groupBox->Controls->Add(this->comboBox10);
            this->AnalysisResults_groupBox->Location = System::Drawing::Point(5, 6);
            this->AnalysisResults_groupBox->Name = L"AnalysisResults_groupBox";
            this->AnalysisResults_groupBox->Size = System::Drawing::Size(1240, 46);
            this->AnalysisResults_groupBox->TabIndex = 1;
            this->AnalysisResults_groupBox->TabStop = false;
            // 
            // comboBox10
            // 
            this->comboBox10->Cursor = System::Windows::Forms::Cursors::Hand;
            this->comboBox10->Dock = System::Windows::Forms::DockStyle::Fill;
            this->comboBox10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->comboBox10->FormattingEnabled = true;
            this->comboBox10->Location = System::Drawing::Point(3, 16);
            this->comboBox10->Name = L"comboBox10";
            this->comboBox10->Size = System::Drawing::Size(1234, 21);
            this->comboBox10->TabIndex = 0;
            // 
            // AddingInfo_panel
            // 
            this->AddingInfo_panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->AddingInfo_panel->AutoSize = true;
            this->AddingInfo_panel->Controls->Add(this->tableLayoutPanel15);
            this->AddingInfo_panel->Controls->Add(this->tableLayoutPanel13);
            this->AddingInfo_panel->Location = System::Drawing::Point(2, 161);
            this->AddingInfo_panel->Name = L"AddingInfo_panel";
            this->AddingInfo_panel->Size = System::Drawing::Size(1311, 331);
            this->AddingInfo_panel->TabIndex = 9;
            // 
            // tableLayoutPanel15
            // 
            this->tableLayoutPanel15->AutoSize = true;
            this->tableLayoutPanel15->ColumnCount = 1;
            this->tableLayoutPanel15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel15->Controls->Add(this->groupBox, 0, 0);
            this->tableLayoutPanel15->Controls->Add(this->groupBox23, 0, 1);
            this->tableLayoutPanel15->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel15->Location = System::Drawing::Point(669, 0);
            this->tableLayoutPanel15->Name = L"tableLayoutPanel15";
            this->tableLayoutPanel15->RowCount = 3;
            this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tableLayoutPanel15->Size = System::Drawing::Size(642, 331);
            this->tableLayoutPanel15->TabIndex = 4;
            // 
            // groupBox
            // 
            this->groupBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->groupBox->AutoSize = true;
            this->groupBox->Controls->Add(this->textBox2);
            this->groupBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox->Location = System::Drawing::Point(4, 3);
            this->groupBox->MinimumSize = System::Drawing::Size(633, 39);
            this->groupBox->Name = L"groupBox";
            this->groupBox->Size = System::Drawing::Size(633, 72);
            this->groupBox->TabIndex = 2;
            this->groupBox->TabStop = false;
            this->groupBox->Text = L"Лечение";
            // 
            // textBox2
            // 
            this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox2->Dock = System::Windows::Forms::DockStyle::Top;
            this->textBox2->Location = System::Drawing::Point(3, 18);
            this->textBox2->MinimumSize = System::Drawing::Size(628, 18);
            this->textBox2->Multiline = true;
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(628, 51);
            this->textBox2->TabIndex = 0;
            // 
            // groupBox23
            // 
            this->groupBox23->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->groupBox23->AutoSize = true;
            this->groupBox23->Controls->Add(this->textBox3);
            this->groupBox23->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox23->Location = System::Drawing::Point(4, 81);
            this->groupBox23->MinimumSize = System::Drawing::Size(633, 39);
            this->groupBox23->Name = L"groupBox23";
            this->groupBox23->Size = System::Drawing::Size(633, 76);
            this->groupBox23->TabIndex = 3;
            this->groupBox23->TabStop = false;
            this->groupBox23->Text = L"Осмотрен";
            // 
            // textBox3
            // 
            this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox3->Dock = System::Windows::Forms::DockStyle::Top;
            this->textBox3->Location = System::Drawing::Point(3, 18);
            this->textBox3->MinimumSize = System::Drawing::Size(628, 18);
            this->textBox3->Multiline = true;
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(628, 55);
            this->textBox3->TabIndex = 0;
            // 
            // tableLayoutPanel13
            // 
            this->tableLayoutPanel13->ColumnCount = 1;
            this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel13->Controls->Add(this->F6_button, 0, 4);
            this->tableLayoutPanel13->Controls->Add(this->DoctorLook_groupBox, 0, 3);
            this->tableLayoutPanel13->Controls->Add(this->Mouth_checkBox, 0, 0);
            this->tableLayoutPanel13->Controls->Add(this->Mouth_groupBox, 0, 1);
            this->tableLayoutPanel13->Controls->Add(this->groupBox22, 0, 2);
            this->tableLayoutPanel13->Dock = System::Windows::Forms::DockStyle::Left;
            this->tableLayoutPanel13->Location = System::Drawing::Point(0, 0);
            this->tableLayoutPanel13->Name = L"tableLayoutPanel13";
            this->tableLayoutPanel13->RowCount = 5;
            this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tableLayoutPanel13->Size = System::Drawing::Size(669, 331);
            this->tableLayoutPanel13->TabIndex = 0;
            // 
            // F6_button
            // 
            this->F6_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->F6_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->F6_button->FlatAppearance->BorderSize = 0;
            this->F6_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->F6_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->F6_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->F6_button->Location = System::Drawing::Point(248, 198);
            this->F6_button->Name = L"F6_button";
            this->F6_button->Size = System::Drawing::Size(173, 37);
            this->F6_button->TabIndex = 15;
            this->F6_button->Text = L"Продолжить";
            this->F6_button->UseVisualStyleBackColor = true;
            this->F6_button->Click += gcnew System::EventHandler(this, &MainWindow::F6_button_Click);
            // 
            // DoctorLook_groupBox
            // 
            this->DoctorLook_groupBox->Controls->Add(this->DoctorLook_comboBox);
            this->DoctorLook_groupBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->DoctorLook_groupBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->DoctorLook_groupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->DoctorLook_groupBox->Location = System::Drawing::Point(3, 139);
            this->DoctorLook_groupBox->Name = L"DoctorLook_groupBox";
            this->DoctorLook_groupBox->Size = System::Drawing::Size(663, 53);
            this->DoctorLook_groupBox->TabIndex = 3;
            this->DoctorLook_groupBox->TabStop = false;
            this->DoctorLook_groupBox->Text = L"Осмотрен*";
            // 
            // DoctorLook_comboBox
            // 
            this->DoctorLook_comboBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->DoctorLook_comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->DoctorLook_comboBox->FormattingEnabled = true;
            this->DoctorLook_comboBox->Location = System::Drawing::Point(3, 18);
            this->DoctorLook_comboBox->Name = L"DoctorLook_comboBox";
            this->DoctorLook_comboBox->Size = System::Drawing::Size(657, 24);
            this->DoctorLook_comboBox->TabIndex = 0;
            // 
            // Mouth_checkBox
            // 
            this->Mouth_checkBox->AutoSize = true;
            this->Mouth_checkBox->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Mouth_checkBox->FlatAppearance->BorderSize = 0;
            this->Mouth_checkBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Mouth_checkBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Mouth_checkBox->Location = System::Drawing::Point(3, 3);
            this->Mouth_checkBox->Name = L"Mouth_checkBox";
            this->Mouth_checkBox->Size = System::Drawing::Size(122, 24);
            this->Mouth_checkBox->TabIndex = 0;
            this->Mouth_checkBox->Text = L"Полость рта";
            this->Mouth_checkBox->UseVisualStyleBackColor = true;
            this->Mouth_checkBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::Mouth_checkBox_CheckedChanged);
            // 
            // Mouth_groupBox
            // 
            this->Mouth_groupBox->AutoSize = true;
            this->Mouth_groupBox->Controls->Add(this->textBox1);
            this->Mouth_groupBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->Mouth_groupBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Mouth_groupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Mouth_groupBox->Location = System::Drawing::Point(3, 33);
            this->Mouth_groupBox->Name = L"Mouth_groupBox";
            this->Mouth_groupBox->Size = System::Drawing::Size(663, 41);
            this->Mouth_groupBox->TabIndex = 1;
            this->Mouth_groupBox->TabStop = false;
            this->Mouth_groupBox->Text = L"Полость рта*";
            this->Mouth_groupBox->Visible = false;
            // 
            // textBox1
            // 
            this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox1->Dock = System::Windows::Forms::DockStyle::Top;
            this->textBox1->Location = System::Drawing::Point(3, 18);
            this->textBox1->Multiline = true;
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(657, 20);
            this->textBox1->TabIndex = 0;
            this->textBox1->Text = L"санирована";
            // 
            // groupBox22
            // 
            this->groupBox22->Controls->Add(this->comboBox11);
            this->groupBox22->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox22->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox22->Location = System::Drawing::Point(3, 80);
            this->groupBox22->Name = L"groupBox22";
            this->groupBox22->Size = System::Drawing::Size(663, 53);
            this->groupBox22->TabIndex = 2;
            this->groupBox22->TabStop = false;
            this->groupBox22->Text = L"Лечение*";
            // 
            // comboBox11
            // 
            this->comboBox11->Dock = System::Windows::Forms::DockStyle::Fill;
            this->comboBox11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->comboBox11->FormattingEnabled = true;
            this->comboBox11->Location = System::Drawing::Point(3, 18);
            this->comboBox11->Name = L"comboBox11";
            this->comboBox11->Size = System::Drawing::Size(657, 24);
            this->comboBox11->TabIndex = 0;
            // 
            // Recomendations_panel
            // 
            this->Recomendations_panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Recomendations_panel->Controls->Add(this->tableLayoutPanel19);
            this->Recomendations_panel->Controls->Add(this->tableLayoutPanel17);
            this->Recomendations_panel->Controls->Add(this->tableLayoutPanel16);
            this->Recomendations_panel->Location = System::Drawing::Point(0, 159);
            this->Recomendations_panel->Name = L"Recomendations_panel";
            this->Recomendations_panel->Size = System::Drawing::Size(1313, 500);
            this->Recomendations_panel->TabIndex = 0;
            // 
            // tableLayoutPanel19
            // 
            this->tableLayoutPanel19->AutoSize = true;
            this->tableLayoutPanel19->ColumnCount = 1;
            this->tableLayoutPanel19->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel19->Controls->Add(this->F8_button, 0, 1);
            this->tableLayoutPanel19->Location = System::Drawing::Point(337, 0);
            this->tableLayoutPanel19->Name = L"tableLayoutPanel19";
            this->tableLayoutPanel19->RowCount = 2;
            this->tableLayoutPanel19->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                100)));
            this->tableLayoutPanel19->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel19->Size = System::Drawing::Size(976, 143);
            this->tableLayoutPanel19->TabIndex = 18;
            // 
            // F8_button
            // 
            this->F8_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->F8_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->F8_button->FlatAppearance->BorderSize = 0;
            this->F8_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->F8_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->F8_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->F8_button->Location = System::Drawing::Point(401, 103);
            this->F8_button->Name = L"F8_button";
            this->F8_button->Size = System::Drawing::Size(173, 37);
            this->F8_button->TabIndex = 17;
            this->F8_button->Text = L"Продолжить";
            this->F8_button->UseVisualStyleBackColor = true;
            this->F8_button->Click += gcnew System::EventHandler(this, &MainWindow::F8_button_Click);
            // 
            // tableLayoutPanel17
            // 
            this->tableLayoutPanel17->AutoSize = true;
            this->tableLayoutPanel17->ColumnCount = 1;
            this->tableLayoutPanel17->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel17->Controls->Add(this->groupBox21, 0, 1);
            this->tableLayoutPanel17->Controls->Add(this->label17, 0, 0);
            this->tableLayoutPanel17->Controls->Add(this->button7, 0, 2);
            this->tableLayoutPanel17->Controls->Add(this->button8, 0, 3);
            this->tableLayoutPanel17->Location = System::Drawing::Point(5, 132);
            this->tableLayoutPanel17->Name = L"tableLayoutPanel17";
            this->tableLayoutPanel17->RowCount = 4;
            this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                36)));
            this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tableLayoutPanel17->Size = System::Drawing::Size(305, 140);
            this->tableLayoutPanel17->TabIndex = 4;
            // 
            // groupBox21
            // 
            this->groupBox21->Controls->Add(this->comboBox12);
            this->groupBox21->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox21->Location = System::Drawing::Point(3, 23);
            this->groupBox21->Name = L"groupBox21";
            this->groupBox21->Size = System::Drawing::Size(299, 42);
            this->groupBox21->TabIndex = 5;
            this->groupBox21->TabStop = false;
            this->groupBox21->Text = L"Рекомендации";
            // 
            // comboBox12
            // 
            this->comboBox12->Dock = System::Windows::Forms::DockStyle::Fill;
            this->comboBox12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->comboBox12->FormattingEnabled = true;
            this->comboBox12->Location = System::Drawing::Point(3, 16);
            this->comboBox12->Name = L"comboBox12";
            this->comboBox12->Size = System::Drawing::Size(293, 21);
            this->comboBox12->TabIndex = 1;
            // 
            // label17
            // 
            this->label17->AutoSize = true;
            this->label17->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label17->Location = System::Drawing::Point(3, 0);
            this->label17->Name = L"label17";
            this->label17->Size = System::Drawing::Size(299, 20);
            this->label17->TabIndex = 0;
            this->label17->Text = L"Или";
            this->label17->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // button7
            // 
            this->button7->AutoSize = true;
            this->button7->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button7->FlatAppearance->BorderSize = 0;
            this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button7->Location = System::Drawing::Point(3, 71);
            this->button7->Name = L"button7";
            this->button7->Size = System::Drawing::Size(299, 30);
            this->button7->TabIndex = 6;
            this->button7->Text = L"Редактировать";
            this->button7->UseVisualStyleBackColor = true;
            // 
            // button8
            // 
            this->button8->AutoSize = true;
            this->button8->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button8->FlatAppearance->BorderSize = 0;
            this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button8->Location = System::Drawing::Point(3, 107);
            this->button8->Name = L"button8";
            this->button8->Size = System::Drawing::Size(299, 30);
            this->button8->TabIndex = 7;
            this->button8->Text = L"Вставить";
            this->button8->UseVisualStyleBackColor = true;
            // 
            // tableLayoutPanel16
            // 
            this->tableLayoutPanel16->AutoSize = true;
            this->tableLayoutPanel16->ColumnCount = 1;
            this->tableLayoutPanel16->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel16->Controls->Add(this->button4, 0, 0);
            this->tableLayoutPanel16->Controls->Add(this->button6, 0, 2);
            this->tableLayoutPanel16->Controls->Add(this->button5, 0, 1);
            this->tableLayoutPanel16->Location = System::Drawing::Point(5, 6);
            this->tableLayoutPanel16->Name = L"tableLayoutPanel16";
            this->tableLayoutPanel16->RowCount = 3;
            this->tableLayoutPanel16->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel16->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel16->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel16->Size = System::Drawing::Size(200, 120);
            this->tableLayoutPanel16->TabIndex = 3;
            // 
            // button4
            // 
            this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button4->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button4->FlatAppearance->BorderSize = 0;
            this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button4->Location = System::Drawing::Point(3, 3);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(194, 34);
            this->button4->TabIndex = 0;
            this->button4->Text = L"Астения";
            this->button4->UseVisualStyleBackColor = true;
            // 
            // button6
            // 
            this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button6->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button6->FlatAppearance->BorderSize = 0;
            this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button6->Location = System::Drawing::Point(3, 83);
            this->button6->Name = L"button6";
            this->button6->Size = System::Drawing::Size(194, 34);
            this->button6->TabIndex = 2;
            this->button6->Text = L"Пневмония";
            this->button6->UseVisualStyleBackColor = true;
            // 
            // button5
            // 
            this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button5->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button5->FlatAppearance->BorderSize = 0;
            this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button5->Location = System::Drawing::Point(3, 43);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(194, 34);
            this->button5->TabIndex = 1;
            this->button5->Text = L"Бронхит";
            this->button5->UseVisualStyleBackColor = true;
            // 
            // UnworkableList_panel
            // 
            this->UnworkableList_panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->UnworkableList_panel->Controls->Add(this->tableLayoutPanel18);
            this->UnworkableList_panel->Controls->Add(this->radioButton1);
            this->UnworkableList_panel->Controls->Add(this->radioButton3);
            this->UnworkableList_panel->Controls->Add(this->radioButton2);
            this->UnworkableList_panel->Location = System::Drawing::Point(0, 161);
            this->UnworkableList_panel->Name = L"UnworkableList_panel";
            this->UnworkableList_panel->Size = System::Drawing::Size(1313, 498);
            this->UnworkableList_panel->TabIndex = 0;
            // 
            // tableLayoutPanel18
            // 
            this->tableLayoutPanel18->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutPanel18->ColumnCount = 1;
            this->tableLayoutPanel18->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel18->Controls->Add(this->F9_button, 0, 1);
            this->tableLayoutPanel18->Location = System::Drawing::Point(0, 32);
            this->tableLayoutPanel18->Name = L"tableLayoutPanel18";
            this->tableLayoutPanel18->RowCount = 2;
            this->tableLayoutPanel18->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel18->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel18->Size = System::Drawing::Size(1313, 115);
            this->tableLayoutPanel18->TabIndex = 17;
            // 
            // F9_button
            // 
            this->F9_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->F9_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->F9_button->FlatAppearance->BorderSize = 0;
            this->F9_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->F9_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->F9_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->F9_button->Location = System::Drawing::Point(570, 3);
            this->F9_button->Name = L"F9_button";
            this->F9_button->Size = System::Drawing::Size(173, 37);
            this->F9_button->TabIndex = 16;
            this->F9_button->Text = L"Продолжить";
            this->F9_button->UseVisualStyleBackColor = true;
            this->F9_button->Click += gcnew System::EventHandler(this, &MainWindow::F9_button_Click);
            // 
            // radioButton1
            // 
            this->radioButton1->AutoSize = true;
            this->radioButton1->Cursor = System::Windows::Forms::Cursors::Hand;
            this->radioButton1->FlatAppearance->BorderSize = 0;
            this->radioButton1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->radioButton1->Location = System::Drawing::Point(7, 6);
            this->radioButton1->Name = L"radioButton1";
            this->radioButton1->Size = System::Drawing::Size(49, 20);
            this->radioButton1->TabIndex = 0;
            this->radioButton1->TabStop = true;
            this->radioButton1->Text = L"Нет";
            this->radioButton1->UseVisualStyleBackColor = true;
            // 
            // radioButton3
            // 
            this->radioButton3->AutoSize = true;
            this->radioButton3->Cursor = System::Windows::Forms::Cursors::Hand;
            this->radioButton3->FlatAppearance->BorderSize = 0;
            this->radioButton3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->radioButton3->Location = System::Drawing::Point(312, 6);
            this->radioButton3->Name = L"radioButton3";
            this->radioButton3->Size = System::Drawing::Size(295, 20);
            this->radioButton3->TabIndex = 2;
            this->radioButton3->TabStop = true;
            this->radioButton3->Text = L"От листа нетрудоспособности отказался";
            this->radioButton3->UseVisualStyleBackColor = true;
            // 
            // radioButton2
            // 
            this->radioButton2->AutoSize = true;
            this->radioButton2->Cursor = System::Windows::Forms::Cursors::Hand;
            this->radioButton2->FlatAppearance->BorderSize = 0;
            this->radioButton2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->radioButton2->Location = System::Drawing::Point(62, 7);
            this->radioButton2->Name = L"radioButton2";
            this->radioButton2->Size = System::Drawing::Size(241, 20);
            this->radioButton2->TabIndex = 1;
            this->radioButton2->TabStop = true;
            this->radioButton2->Text = L"Выдан лист нетрудоспособности";
            this->radioButton2->UseVisualStyleBackColor = true;
            // 
            // Stamp_panel
            // 
            this->Stamp_panel->Location = System::Drawing::Point(600, 79);
            this->Stamp_panel->Name = L"Stamp_panel";
            this->Stamp_panel->Size = System::Drawing::Size(200, 100);
            this->Stamp_panel->TabIndex = 0;
            // 
            // MainWindow
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->AutoScroll = true;
            this->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->ClientSize = System::Drawing::Size(1313, 742);
            this->Controls->Add(this->Epicrisis_panel);
            this->Controls->Add(this->Home_panel);
            this->HelpButton = true;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"MainWindow";
            this->Text = L"MainWindow";
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
            this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
            this->Home_panel->ResumeLayout(false);
            this->tableLayoutPanel12->ResumeLayout(false);
            this->tableLayoutPanel12->PerformLayout();
            this->tableLayoutPanel1->ResumeLayout(false);
            this->tableLayoutPanel1->PerformLayout();
            this->tableLayoutPanel2->ResumeLayout(false);
            this->tableLayoutPanel2->PerformLayout();
            this->tableLayoutPanel7->ResumeLayout(false);
            this->groupBox5->ResumeLayout(false);
            this->groupBox5->PerformLayout();
            this->groupBox4->ResumeLayout(false);
            this->groupBox4->PerformLayout();
            this->tableLayoutPanel6->ResumeLayout(false);
            this->groupBox3->ResumeLayout(false);
            this->groupBox3->PerformLayout();
            this->tableLayoutPanel3->ResumeLayout(false);
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            this->tableLayoutPanel4->ResumeLayout(false);
            this->DoctorsNotes_tableLayoutPanel->ResumeLayout(false);
            this->ReportDir_groupBox->ResumeLayout(false);
            this->ReportDir_groupBox->PerformLayout();
            this->tableLayoutPanel5->ResumeLayout(false);
            this->groupBox2->ResumeLayout(false);
            this->groupBox2->PerformLayout();
            this->tableLayoutPanel8->ResumeLayout(false);
            this->Epicrisis_panel->ResumeLayout(false);
            this->Epicrisis_panel->PerformLayout();
            this->EpiricisisTabMenu_tableLayoutPanel->ResumeLayout(false);
            this->EpiricisisTabMenu_tableLayoutPanel->PerformLayout();
            this->tableLayoutPanel10->ResumeLayout(false);
            this->groupBox11->ResumeLayout(false);
            this->groupBox10->ResumeLayout(false);
            this->groupBox9->ResumeLayout(false);
            this->groupBox8->ResumeLayout(false);
            this->groupBox7->ResumeLayout(false);
            this->groupBox6->ResumeLayout(false);
            this->SideInfo_panel->ResumeLayout(false);
            this->SideInfo_groupBox->ResumeLayout(false);
            this->tableLayoutPanel9->ResumeLayout(false);
            this->tableLayoutPanel9->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
            this->flowLayoutPanel1->ResumeLayout(false);
            this->flowLayoutPanel1->PerformLayout();
            this->Ill_History_panel->ResumeLayout(false);
            this->Ill_History_panel->PerformLayout();
            this->groupBox15->ResumeLayout(false);
            this->groupBox16->ResumeLayout(false);
            this->MKB_groupBox->ResumeLayout(false);
            this->groupBox14->ResumeLayout(false);
            this->groupBox13->ResumeLayout(false);
            this->groupBox12->ResumeLayout(false);
            this->Anamnesis_panel->ResumeLayout(false);
            this->tableLayoutPanel14->ResumeLayout(false);
            this->tableLayoutPanel14->PerformLayout();
            this->panel3->ResumeLayout(false);
            this->panel3->PerformLayout();
            this->tableLayoutPanel11->ResumeLayout(false);
            this->tableLayoutPanel11->PerformLayout();
            this->NapravlenV_tableLayoutPanel->ResumeLayout(false);
            this->NapravlenV_tableLayoutPanel->PerformLayout();
            this->flowLayoutPanel5->ResumeLayout(false);
            this->flowLayoutPanel5->PerformLayout();
            this->NapravlenieVGospital_tableLayoutPanel->ResumeLayout(false);
            this->NapravlenieVGospital_tableLayoutPanel->PerformLayout();
            this->NapravlenVpolyclonic_panel->ResumeLayout(false);
            this->NapravlenVpolyclonic_panel->PerformLayout();
            this->RepeatCheck_groupBox->ResumeLayout(false);
            this->RepeatCheck_groupBox->PerformLayout();
            this->NapravlenVLazaret_panel->ResumeLayout(false);
            this->GospitalSentDate_groupBox->ResumeLayout(false);
            this->GospitalSentDate_groupBox->PerformLayout();
            this->groupBox19->ResumeLayout(false);
            this->groupBox18->ResumeLayout(false);
            this->flowLayoutPanel3->ResumeLayout(false);
            this->flowLayoutPanel3->PerformLayout();
            this->groupBox17->ResumeLayout(false);
            this->flowLayoutPanel2->ResumeLayout(false);
            this->flowLayoutPanel2->PerformLayout();
            this->panel2->ResumeLayout(false);
            this->groupBox20->ResumeLayout(false);
            this->groupBox20->PerformLayout();
            this->AnalysisResults_panel->ResumeLayout(false);
            this->AnalysisResults_panel->PerformLayout();
            this->AnalysisResults_groupBox->ResumeLayout(false);
            this->AddingInfo_panel->ResumeLayout(false);
            this->AddingInfo_panel->PerformLayout();
            this->tableLayoutPanel15->ResumeLayout(false);
            this->tableLayoutPanel15->PerformLayout();
            this->groupBox->ResumeLayout(false);
            this->groupBox->PerformLayout();
            this->groupBox23->ResumeLayout(false);
            this->groupBox23->PerformLayout();
            this->tableLayoutPanel13->ResumeLayout(false);
            this->tableLayoutPanel13->PerformLayout();
            this->DoctorLook_groupBox->ResumeLayout(false);
            this->Mouth_groupBox->ResumeLayout(false);
            this->Mouth_groupBox->PerformLayout();
            this->groupBox22->ResumeLayout(false);
            this->Recomendations_panel->ResumeLayout(false);
            this->Recomendations_panel->PerformLayout();
            this->tableLayoutPanel19->ResumeLayout(false);
            this->tableLayoutPanel17->ResumeLayout(false);
            this->tableLayoutPanel17->PerformLayout();
            this->groupBox21->ResumeLayout(false);
            this->tableLayoutPanel16->ResumeLayout(false);
            this->UnworkableList_panel->ResumeLayout(false);
            this->UnworkableList_panel->PerformLayout();
            this->tableLayoutPanel18->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion


private: void ShowPanel(Panel^ panel) {
    String ^name = panel->Name;
    Home_panel->Visible = false;
    Anamnesis_panel->Visible = false;
    Ill_History_panel->Visible = false;
    AnalysisResults_panel->Visible = false;
    AddingInfo_panel->Visible = false;
    Stamp_panel->Visible = false;
    UnworkableList_panel->Visible = false;
    SideInfo_panel->Visible = false;
    Recomendations_panel->Visible = false;
    if (panel->Name == Epicrisis_panel->Name) {
        Ill_History_panel->Visible = true;
        Ill_History_label->BackColor = Color::FromArgb(10, 80, 255);
        //lastLabel = Ill_History_label;
    }
    if (name == Anamnesis_panel->Name || name == Ill_History_panel->Name || name == AnalysisResults_panel->Name
        || name == AddingInfo_panel->Name || name == SideInfo_panel->Name || name == Recomendations_panel->Name
        || name == Stamp_panel->Name || name == UnworkableList_panel->Name) {
        Epicrisis_panel->Visible = true;
    }
    else Epicrisis_panel->Visible = false;
    panel->Visible = true;
}
      
private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void epicrisis_button_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowPanel(Epicrisis_panel);
    CleanEpicrisisTabLastLabel();
    Ill_History_label->BackColor = Color::FromArgb(10, 80, 255);
    lastLabel = Ill_History_label;
}
private: System::Void BackToHome_button_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowPanel(Home_panel);
    CleanEpicrisisTabLastLabel();
    this->BackToHome_label->BackColor = Color::FromArgb(10, 80, 255);
    lastLabel = BackToHome_label;
}
private: System::Void CleanEpicrisisTabLastLabel() {
    if (lastLabel) {
        lastLabel->Name;
        this->lastLabel->BackColor = Color::White;
    }
}
private: System::Void IllHistory_button_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowPanel(Ill_History_panel);
    CleanEpicrisisTabLastLabel();
    SetTabMenuLabelBottomLine(Ill_History_label);
}

private: System::Void Anamnesis_button_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowPanel(Anamnesis_panel);
    CleanEpicrisisTabLastLabel();
    SetTabMenuLabelBottomLine(Anamnesis_label);
    if (!counter) {
        IllBeginingDate = this->IllBegining_dateTimePicker->Value.ToShortDateString();
        ResponseDate = this->ResponseDate_dateTimePicker->Value.ToShortDateString();
        Desease = this->Pnevmonia_radioButton->Text->ToLower();
        MedOrganizationToResponse = this->ResponseMedstation_radioButton->Text->ToLower();
        MedOrganizationToSend = this->SentToGospital_radioButton->Text->ToLower();
        MedicalResearchDate = this->ResearchDate_dateTimePicker->Value.ToShortDateString();
        ResearchType = this->FOGK_checkBox->Text;
        counter++;
        AnamnesisTextBox();
    }
}
private: System::Void AnalysisResults_button_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowPanel(AnalysisResults_panel);
    CleanEpicrisisTabLastLabel();
    SetTabMenuLabelBottomLine(AnalysisResults_label);
}
private: System::Void AddingInfo_button_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowPanel(AddingInfo_panel);
    CleanEpicrisisTabLastLabel();
    SetTabMenuLabelBottomLine(AddingInfo_label);
}
private: System::Void SideInfo_button_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowPanel(SideInfo_panel);
    CleanEpicrisisTabLastLabel();
    SetTabMenuLabelBottomLine(SideInfo_label);
}
private: System::Void Recomendations_button_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowPanel(Recomendations_panel);
    CleanEpicrisisTabLastLabel();
    SetTabMenuLabelBottomLine(Recomendations_label);
}
private: System::Void Stamp_button_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowPanel(Stamp_panel);
    CleanEpicrisisTabLastLabel();
    SetTabMenuLabelBottomLine(Stamp_label);
}
private: System::Void UnworkableList_button_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowPanel(UnworkableList_panel);
    CleanEpicrisisTabLastLabel();
    SetTabMenuLabelBottomLine(UnworkableList_label);
}




private: System::Void AnamnesisTextBox() {

    if (Astenia_radioButton->Checked) {
        Anamnesis_textBox->Text = "Переболел пневмонией в текущем месяце.";
        return;
    }

    if (MedOrganizationToResponse == "медпункт") {

        if (MedOrganizationToSend == "госпиталь") {
            Anamnesis_textBox->Text = "Со слов болен с " + IllBeginingDate + ". " +
                ResponseDate + " обратился в медпункт, направлен в госпиталь. ";
            //return;
        }
        else if (MedOrganizationToSend == "лазарет") {
            Anamnesis_textBox->Text = "Со слов болен с " + IllBeginingDate + ". " +
                ResponseDate + " обратился в медпункт, помещен в лазарет. "
                + GospitalSentDate + " направлен в госпиталь. ";
            //return;
        }
        else if (MedOrganizationToSend == "поликлинику") {
            if (Gospitalization) {
                Anamnesis_textBox->Text = "Со слов болен с " + IllBeginingDate + ". " +
                    ResponseDate +
                    " обратился в медпункт, направлен в поликлинику, назначена госпитализация. ";
                //return;
            }
            else {
                Anamnesis_textBox->Text = "Со слов болен с " + IllBeginingDate + ". " +
                    ResponseDate + " обратился в медпункт, направлен в поликлинику, назначено амбулаторное лечение. "
                    + RepeatCheckDate + " повторно осмотрен терапевтом поликлиники и направлен в госпиталь. ";
                //return;
            }
        }
    }
    else if (MedOrganizationToResponse == "госпиталь") {
        Anamnesis_textBox->Text = "Со слов болен с " + IllBeginingDate + ". " +
            ResponseDate + " обратился в госпиталь. ";
        //return;
    }
    else if (MedOrganizationToResponse == "поликлинику") {
        if (Gospitalization) {
            Anamnesis_textBox->Text = "Со слов болен с " + IllBeginingDate + ". " +
                ResponseDate +
                " обратился в поликлинику, назначена госпитализация. ";
            //return;
        }
        else {
            Anamnesis_textBox->Text = "Со слов болен с " + IllBeginingDate + ". " +
                ResponseDate + " обратился в поликлинику, назначено амбулаторное лечение. "
                + RepeatCheckDate + " повторно осмотрен терапевтом поликлиники и направлен в госпиталь. ";
            //return;
        }
    }
    if (researchCounter == 1) {
        Anamnesis_textBox->Text += MedicalResearchDate + " направлен на: " + ResearchType + ".";
    }
    else if (researchCounter > 1) {
        Anamnesis_textBox->Text += MedicalResearchDate + " выполнены обследования: " + ResearchType + ".";
    }
}
private: System::Void Pnevmonia_radioButton_Click(System::Object^ sender, System::EventArgs^ e) {
    if (this->Pnevmonia_radioButton->Checked) {
        groupBox17->Visible = true;
        label12->Visible = true;
        flowLayoutPanel3->Visible = true;
        groupBox18->Visible = true;
        label13->Visible = true;
        NapravlenV_tableLayoutPanel->Visible = true;
        Desease = Pnevmonia_radioButton->Text->ToLower();
        AnamnesisTextBox();
    }
}
private: System::Void Astenia_radioButton_Click(System::Object^ sender, System::EventArgs^ e) {
    if (this->Astenia_radioButton->Checked) {
        groupBox17->Visible = false;
        label12->Visible = false;
        flowLayoutPanel3->Visible = false;
        groupBox18->Visible = false;
        label13->Visible = false;
        NapravlenV_tableLayoutPanel->Visible = false;
        Desease = Astenia_radioButton->Text->ToLower();
        Anamnesis_textBox->Text = "Переболел пневмонией в текущем месяце.";
    }
    else {
        groupBox17->Visible = true;
        label12->Visible = true;
        flowLayoutPanel3->Visible = true;
        groupBox18->Visible = true;
        label13->Visible = true;
        NapravlenV_tableLayoutPanel->Visible = true;
    }
}
private: System::Void IllBegining_dateTimePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    IllBeginingDate = IllBegining_dateTimePicker->Value.ToShortDateString();
    AnamnesisTextBox();
}
private: System::Void ResponseMedstation_radioButton_Click(System::Object^ sender, System::EventArgs^ e) {
    if (this->ResponseMedstation_radioButton->Checked) {
        label13->Visible = true;
        NapravlenV_tableLayoutPanel->Visible = true;
        flowLayoutPanel5->Visible = true;
        NapravlenieVGospital_tableLayoutPanel->Visible = false;
        MedOrganizationToResponse = ResponseMedstation_radioButton->Text->ToLower();
        AnamnesisTextBox();
    }
}
private: System::Void ResponseGospital_radioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (ResponseGospital_radioButton->Checked) {
        label13->Visible = false;
        NapravlenV_tableLayoutPanel->Visible = false;
        MedOrganizationToResponse = ResponseGospital_radioButton->Text->ToLower();
        AnamnesisTextBox();
    }
}
private: System::Void ResponsePolyclinic_radioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (ResponsePolyclinic_radioButton->Checked) {
        label13->Visible = false;
        NapravlenV_tableLayoutPanel->Visible = true;
        flowLayoutPanel5->Visible = false;
        NapravlenieVGospital_tableLayoutPanel->Visible = true;
        NapravlenVLazaret_panel->Visible = false;
        NapravlenVpolyclonic_panel->Visible = true;
        MedOrganizationToResponse = ResponsePolyclinic_radioButton->Text->ToLower();
        AnamnesisTextBox();
    }
}
private: System::Void ResponseDate_dateTimePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    ResponseDate = ResponseDate_dateTimePicker->Value.ToShortDateString();
    AnamnesisTextBox();
}
private: System::Void SentToLazaret_radioButton_Click(System::Object^ sender, System::EventArgs^ e) {
    if (SentToLazaret_radioButton->Checked) {
        GospitalSentDate = GospitalSentDate_dateTimePicker->Value.ToShortDateString();
        NapravlenieVGospital_tableLayoutPanel->Visible = true;
        NapravlenVLazaret_panel->Visible = true;
        NapravlenVpolyclonic_panel->Visible = false;
        MedOrganizationToSend = SentToLazaret_radioButton->Text->ToLower();
        AnamnesisTextBox();
    }
}
private: System::Void SentToGospital_radioButton_Click(System::Object^ sender, System::EventArgs^ e) {
    if (SentToGospital_radioButton->Checked) {
        NapravlenieVGospital_tableLayoutPanel->Visible = false;
        MedOrganizationToSend = SentToGospital_radioButton->Text->ToLower();
        AnamnesisTextBox();
    }
}
private: System::Void SentToPolyclinic_radioButton_Click(System::Object^ sender, System::EventArgs^ e) {
    if (SentToPolyclinic_radioButton->Checked) {
        NapravlenieVGospital_tableLayoutPanel->Visible = true;
        NapravlenVLazaret_panel->Visible = false;
        NapravlenVpolyclonic_panel->Visible = true;
        MedOrganizationToSend = SentToPolyclinic_radioButton->Text->ToLower();
        AnamnesisTextBox();
    }
}
private: System::Void ResearchDate_dateTimePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    MedicalResearchDate = ResearchDate_dateTimePicker->Value.ToShortDateString();
    AnamnesisTextBox();
}

private: System::Void CheckBoxChangeValue(CheckBox^ box) {
    int index;
    if (box->Checked) {
        ResearchType += (", " + box->Text);
        researchCounter++;
    }
    else if (box->Checked && ResearchType == "") {
        ResearchType += (box->Text);
    }
    else {
        if ((index = ResearchType->IndexOf(box->Text)) >= 0)
        ResearchType = ResearchType->Remove(index, box->Text->Length);
        researchCounter--;
    }
    if (ResearchType->EndsWith(", ")) {
        ResearchType = ResearchType->Remove(ResearchType->Length - 2, 2);
    }
    else if (ResearchType->StartsWith(", ")) {
        ResearchType = ResearchType->Remove(0, 2);
    }
    AnamnesisTextBox();
}
private: System::Void FOGK_checkBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    CheckBoxChangeValue(static_cast<CheckBox^>(sender));
}
private: System::Void RgOGK_checkBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    CheckBoxChangeValue(static_cast<CheckBox^>(sender));
}
private: System::Void KT_OGK_checkBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    CheckBoxChangeValue(static_cast<CheckBox^>(sender));
}
private: System::Void OAK_checkBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    CheckBoxChangeValue(static_cast<CheckBox^>(sender));
}
private: System::Void OAM_checkBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    CheckBoxChangeValue(static_cast<CheckBox^>(sender));
}
private: System::Void BioChemicalBloodResearch_checkBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    CheckBoxChangeValue(static_cast<CheckBox^>(sender));
}
private: System::Void GospitalSentDate_dateTimePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    GospitalSentDate = GospitalSentDate_dateTimePicker->Value.ToShortDateString();
    AnamnesisTextBox();
}
private: System::Void AmbulanceHealing_radioButton_Click(System::Object^ sender, System::EventArgs^ e) {
    if (AmbulanceHealing_radioButton->Checked) {
        RepeatCheckDate = RepeatCheck_dateTimePicker->Value.ToShortDateString();
        Gospitalization = false;
        RepeatCheck_groupBox->Visible = true;
    }
    AnamnesisTextBox();
}
private: System::Void Gospitalization_radioButton_Click(System::Object^ sender, System::EventArgs^ e) {
    if (Gospitalization_radioButton->Checked) {
        Gospitalization = true;
        RepeatCheck_groupBox->Visible = false;
    }
    AnamnesisTextBox();
}
private: System::Void RepeatCheck_dateTimePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    RepeatCheckDate = RepeatCheck_dateTimePicker->Value.ToShortDateString();
    AnamnesisTextBox();
}
private: System::Void F3_button_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowPanel(AnalysisResults_panel);
    CleanEpicrisisTabLastLabel();
    SetTabMenuLabelBottomLine(AnalysisResults_label);
}
private: System::Void SetTabMenuLabelBottomLine(Label^ label) {
    label->BackColor = Color::FromArgb(10, 80, 255);
    lastLabel = label;
}
private: System::Void F2_button_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowPanel(Anamnesis_panel);
    CleanEpicrisisTabLastLabel();
    SetTabMenuLabelBottomLine(Anamnesis_label);
    if (!counter) {
        IllBeginingDate = this->IllBegining_dateTimePicker->Value.ToShortDateString();
        ResponseDate = this->ResponseDate_dateTimePicker->Value.ToShortDateString();
        Desease = this->Pnevmonia_radioButton->Text->ToLower();
        MedOrganizationToResponse = this->ResponseMedstation_radioButton->Text->ToLower();
        MedOrganizationToSend = this->SentToGospital_radioButton->Text->ToLower();
        MedicalResearchDate = this->ResearchDate_dateTimePicker->Value.ToShortDateString();
        ResearchType = this->FOGK_checkBox->Text;
        counter++;
        AnamnesisTextBox();
    }
}
private: System::Void Mouth_checkBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (Mouth_checkBox->Checked) {
        Mouth_groupBox->Visible = true;
        SanaciyaPolostyRta = "санирована";
    }
    else {
        Mouth_groupBox->Visible = false;
    }
}
private: System::Void F5_button_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowPanel(AddingInfo_panel);
    CleanEpicrisisTabLastLabel();
    SetTabMenuLabelBottomLine(AddingInfo_label);
}

private: System::Void F6_button_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowPanel(SideInfo_panel);
    CleanEpicrisisTabLastLabel();
    SetTabMenuLabelBottomLine(SideInfo_label);
}
private: System::Void F7_button_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowPanel(Recomendations_panel);
    CleanEpicrisisTabLastLabel();
    SetTabMenuLabelBottomLine(Recomendations_label);
}
private: System::Void F9_button_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowPanel(Stamp_panel);
    CleanEpicrisisTabLastLabel();
    SetTabMenuLabelBottomLine(Stamp_label);
}
private: System::Void F8_button_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowPanel(UnworkableList_panel);
    CleanEpicrisisTabLastLabel();
    SetTabMenuLabelBottomLine(UnworkableList_label);
}
private: Void FillComboBox(ComboBox^ box, String^ table, String^ column) {
    //List<String^>^ items = dbHelperWrapper->PopulateComboBox(table, column);
    //for each (String ^ item in items) {
    //    box->Items->Add(item);
    //}
}
private: Void InitializeData() {

}
};
}