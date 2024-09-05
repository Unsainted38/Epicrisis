#pragma once
#include <vcclr.h>
#include "DB_Helper.h"
#include "Word_Helper.h"
#include "RtfTableCreator.h"
#include "RtfTest.h"



namespace unsaintedWinApp {
    using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace System::Collections::Generic;
    
    namespace DevExp = DevExpress;
    namespace XtraEditors = DevExp::XtraEditors;

    public enum class PathTypes {
        DB = 0,
        Templates = 1,
        Epicriz = 2,
        DocNotes = 3,
        FirstList = 4
    };
    public enum class TabIndexedComboBoxes {
        HistoryNumber,
        HistoryYear,
        Surname,
        Name,
        Patronymic,
        Rank,
        MilitaryUnit,
        Birthday,
        IncomeDate,
        OutcomeDate,
        Diagnos,
        Mkb,
        RelatedDiagnos,
        Complications,
    };

	/// <summary>
	/// Сводка для MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{

	public:
		MainWindow(void)
		{
			InitializeComponent();
            
            InitializeData();

            InitializeComboBox();

            InitializeInterface();

            InitializePagesPanels();
			//
			//TODO: добавьте код конструктора
			//           

		}

	protected:

        virtual bool ProcessCmdKey(Message% msg, Keys keyData) override
        {
            // Проверяем, если нажата комбинация Shift + Enter
            if (keyData == (Keys::Enter | Keys::Shift))
            {
                // Обрабатываем Shift + Enter как отдельное событие (например, добавляем новую строку в RichTextBox)
                
                NextPagePanel();
                

                // Возвращаем true, чтобы остановить дальнейшую обработку (например, предотвратить активацию кнопки)
                return true;
            }
            // Если просто нажата клавиша Enter, возвращаем false, чтобы продолжить нормальную обработку
            return Form::ProcessCmdKey(msg, keyData);
        }
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
        String^ templatesPath;
        String^ epicrizPath;
        DB_Helper^ dbHelper;
        Word_Helper^ wordHelper;

        
        
    public:    
        // Поля для хранения значений для эпикриза
        String^ HistoryNumber;
        String^ HistoryYear;
        String^ Name;
        String^ Surname;
        String^ Patronymic;
        String^ Rank;
        String^ MilitaryUnit;
        String^ Birthday;
        String^ IncomeDate;
        String^ OutcomeDate;
        String^ Mkb;
        String^ Diagnosis;
        String^ RelatedDiagnosis;
        String^ Complications;
        String^ AnamnesisJson;
        String^ AnamnesisText;
        String^ Analyzes;
        String^ AdditionalData;
        String^ Therapy;
        String^ DoctorsLooked;
        String^ SideData;
        String^ Recommendations;
        String^ UnworkableList;
        // Поля для хранения значений для эпикриза

        Decimal^ id;
        Dictionary<Panel^,Label^>^ ChangePanelDict;
        Panel^ currentPanel;
        Panel^ previousPanel;
        List<Panel^>^ PagePanelList;
        ComboBox^ previousComboBox;
        ComboBox^ currentComboBox;
        List<ComboBox^>^ ComboBoxList;
        List<String^>^ epicrizDiagnosesList;
        List<String^>^ RecommendationsList;
        TabIndexedComboBoxes comboBox;
        PathTypes PathType;
        String^ IllBeginingDate;
        String^ ResponseDate;
        String^ GospitalSentDate;
        String^ PolyclinicSentDate;
        bool IsLazaretaVGospital = true;
        bool IsLazaretaVPolyclinic = false;
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
private: System::Windows::Forms::TableLayoutPanel^ UpperHat_tableLayoutPanel;

    private: System::Windows::Forms::NumericUpDown^ id_numericUpDown;
    private: System::Windows::Forms::NumericUpDown^ year_numericUpDown;


    private: System::Windows::Forms::Label^ ID_label;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Button^ Clear_button;
private: System::Windows::Forms::TableLayoutPanel^ Hat_tableLayoutPanel;

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
    private: System::Windows::Forms::DateTimePicker^ income_dateTimePicker;

    private: System::Windows::Forms::GroupBox^ groupBox13;
    private: System::Windows::Forms::GroupBox^ groupBox12;
    private: System::Windows::Forms::DateTimePicker^ outcome_dateTimePicker;

    private: System::Windows::Forms::GroupBox^ MKB_groupBox;
    private: System::Windows::Forms::GroupBox^ groupBox14;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::GroupBox^ groupBox16;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::GroupBox^ groupBox15;
    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::Button^ F3_button;
    private: System::Windows::Forms::DateTimePicker^ birthday_dateTimePicker;
private: System::Windows::Forms::ComboBox^ related_comboBox;
private: System::Windows::Forms::ComboBox^ mkb_comboBox;
private: System::Windows::Forms::ComboBox^ epicrizdiagnoses_comboBox;








private: System::Windows::Forms::ComboBox^ complications_comboBox;





private: System::Windows::Forms::ComboBox^ militaryUnit_comboBox;


private: System::Windows::Forms::ComboBox^ rank_comboBox;
private: System::Windows::Forms::ComboBox^ Patronymic_comboBox;



private: System::Windows::Forms::ComboBox^ Names_comboBox;
private: System::Windows::Forms::ComboBox^ Surname_comboBox;


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
private: System::Windows::Forms::Button^ epicrizPathChange_button;

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
private: System::Windows::Forms::GroupBox^ IsLazaretaVGospital_groupBox;



private: System::Windows::Forms::DateTimePicker^ IsLazaretaVGospital_dateTimePicker;


    private: System::Windows::Forms::Panel^ NapravlenVpolyclonic_panel;
    private: System::Windows::Forms::RadioButton^ AmbulanceHealing_radioButton;
    private: System::Windows::Forms::RadioButton^ Gospitalization_radioButton;
    private: System::Windows::Forms::Label^ label10;
    private: System::Windows::Forms::Panel^ panel2;
    private: System::Windows::Forms::GroupBox^ RepeatCheck_groupBox;
    private: System::Windows::Forms::DateTimePicker^ RepeatCheck_dateTimePicker;

    private: System::Windows::Forms::TableLayoutPanel^ NapravlenieVGospital_tableLayoutPanel;
    private: System::Windows::Forms::Panel^ panel3;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel14;
    private: System::Windows::Forms::Button^ F4_button;
    private: System::Windows::Forms::Panel^ AnalysisResults_panel;
    private: System::Windows::Forms::GroupBox^ AnalysisResults_groupBox;
private: System::Windows::Forms::ComboBox^ AnalyzesResults_comboBox;

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

    private: System::Windows::Forms::Button^ F7_button;
private: System::Windows::Forms::Button^ PnevmoRec_button;

private: System::Windows::Forms::Button^ BronhitRec_button;

private: System::Windows::Forms::Button^ AsteniaRec_button;

    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel16;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel17;
    private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::GroupBox^ Recommendations_groupBox;

private: System::Windows::Forms::Button^ EditRec_button;
private: System::Windows::Forms::Button^ Paste_button;




    private: System::Windows::Forms::RadioButton^ radioButton3;
    private: System::Windows::Forms::RadioButton^ radioButton2;
    private: System::Windows::Forms::RadioButton^ radioButton1;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel18;
    private: System::Windows::Forms::Button^ F9_button;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel19;
    private: System::Windows::Forms::Button^ F8_button;
private: System::Windows::Forms::OpenFileDialog^ PathChanger_openFileDialog;

private: System::Windows::Forms::Label^ dbPath_label;
private: System::Windows::Forms::Label^ tamplatesPath_label;
private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::Label^ epicrizPath_label;

private: System::Windows::Forms::TextBox^ textBox5;
private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::TextBox^ textBox4;
private: System::Windows::Forms::CheckedListBox^ Recommendations_checkedListBox;






























private: System::Windows::Forms::GroupBox^ IsLazaretaVPolyclinic_groupBox;
private: System::Windows::Forms::DateTimePicker^ IsLazaretaVPolyclinic_dateTimePicker;



private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel21;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel6;
private: System::Windows::Forms::RadioButton^ IsLazaretaVGospital_radioButton;

private: System::Windows::Forms::RadioButton^ IsLazaretaVPolyclinic_radioButton;

































private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel9;
private: System::Windows::Forms::Button^ button2;

private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel10;
private: System::Windows::Forms::TableLayoutPanel^ TextMiniEditor_tableLayoutPanel;
private: System::Windows::Forms::RichTextBox^ richTextBox;
private: System::Windows::Forms::FlowLayoutPanel^ TextMiniEditor_flowLayoutPanel;
private: System::Windows::Forms::NumericUpDown^ Fontsize_numericUpDown;
private: DevExpress::XtraEditors::SeparatorControl^ separatorControl1;
private: System::Windows::Forms::Button^ Bold_button;
private: System::Windows::Forms::Button^ Italic_button;
private: System::Windows::Forms::Button^ Underline_button;
private: System::Windows::Forms::Button^ Uppercase_button;
private: System::Windows::Forms::Button^ Lowercase_button;
private: System::Windows::Forms::Button^ Unker_button;
private: System::Windows::Forms::Button^ NumList_button;
private: System::Windows::Forms::Button^ DotList_button;
private: System::Windows::Forms::Button^ CleanFormat_button;
private: DevExpress::XtraEditors::SeparatorControl^ separatorControl3;
private: System::Windows::Forms::Button^ LeftAlign_button;
private: System::Windows::Forms::Button^ CenterAlign_button;
private: System::Windows::Forms::Button^ RightAlign_button;
private: System::Windows::Forms::Button^ WideAlign_button;
private: DevExpress::XtraEditors::SeparatorControl^ separatorControl2;
private: System::Windows::Forms::Button^ Date_button;
private: System::Windows::Forms::Button^ DropDownMenu_button;
private: System::Windows::Forms::Button^ Table_button;
private: System::Windows::Forms::FlowLayoutPanel^ CheckBoxes_flowLayoutPanel;

































































































































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
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->Hitory_button = (gcnew System::Windows::Forms::Button());
            this->epicrisis_button = (gcnew System::Windows::Forms::Button());
            this->doctors_notes_button = (gcnew System::Windows::Forms::Button());
            this->f1_button = (gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
            this->epicrizPath_label = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->epicrizPathChange_button = (gcnew System::Windows::Forms::Button());
            this->Epicrisis_label = (gcnew System::Windows::Forms::Label());
            this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
            this->textBox5 = (gcnew System::Windows::Forms::TextBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
            this->label20 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->Settings_label = (gcnew System::Windows::Forms::Label());
            this->SettingsApplication_label = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->TemplatesChange_button = (gcnew System::Windows::Forms::Button());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->tamplatesPath_label = (gcnew System::Windows::Forms::Label());
            this->Template_label = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->DB_create_button = (gcnew System::Windows::Forms::Button());
            this->DB_change_button = (gcnew System::Windows::Forms::Button());
            this->DB_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->dbPath_label = (gcnew System::Windows::Forms::Label());
            this->DoctorsNotes_tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->ReportDir_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->label18 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->ReportSave_button = (gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
            this->textBox4 = (gcnew System::Windows::Forms::TextBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->DoctorsNotes_label = (gcnew System::Windows::Forms::Label());
            this->FirstList_label = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->Recovery_button = (gcnew System::Windows::Forms::Button());
            this->SaveSettings_button = (gcnew System::Windows::Forms::Button());
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
            this->Hat_tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
            this->birthday_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
            this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
            this->militaryUnit_comboBox = (gcnew System::Windows::Forms::ComboBox());
            this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
            this->rank_comboBox = (gcnew System::Windows::Forms::ComboBox());
            this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
            this->Patronymic_comboBox = (gcnew System::Windows::Forms::ComboBox());
            this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
            this->Names_comboBox = (gcnew System::Windows::Forms::ComboBox());
            this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
            this->Surname_comboBox = (gcnew System::Windows::Forms::ComboBox());
            this->UpperHat_tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->id_numericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
            this->year_numericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
            this->ID_label = (gcnew System::Windows::Forms::Label());
            this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->Clear_button = (gcnew System::Windows::Forms::Button());
            this->SideInfo_panel = (gcnew System::Windows::Forms::Panel());
            this->tableLayoutPanel10 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->SideInfo_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->CheckBoxes_flowLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->TextMiniEditor_tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->richTextBox = (gcnew System::Windows::Forms::RichTextBox());
            this->TextMiniEditor_flowLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->Fontsize_numericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
            this->separatorControl1 = (gcnew DevExpress::XtraEditors::SeparatorControl());
            this->Bold_button = (gcnew System::Windows::Forms::Button());
            this->Italic_button = (gcnew System::Windows::Forms::Button());
            this->Underline_button = (gcnew System::Windows::Forms::Button());
            this->Uppercase_button = (gcnew System::Windows::Forms::Button());
            this->Lowercase_button = (gcnew System::Windows::Forms::Button());
            this->Unker_button = (gcnew System::Windows::Forms::Button());
            this->NumList_button = (gcnew System::Windows::Forms::Button());
            this->DotList_button = (gcnew System::Windows::Forms::Button());
            this->CleanFormat_button = (gcnew System::Windows::Forms::Button());
            this->separatorControl3 = (gcnew DevExpress::XtraEditors::SeparatorControl());
            this->LeftAlign_button = (gcnew System::Windows::Forms::Button());
            this->CenterAlign_button = (gcnew System::Windows::Forms::Button());
            this->RightAlign_button = (gcnew System::Windows::Forms::Button());
            this->WideAlign_button = (gcnew System::Windows::Forms::Button());
            this->separatorControl2 = (gcnew DevExpress::XtraEditors::SeparatorControl());
            this->Date_button = (gcnew System::Windows::Forms::Button());
            this->DropDownMenu_button = (gcnew System::Windows::Forms::Button());
            this->Table_button = (gcnew System::Windows::Forms::Button());
            this->F7_button = (gcnew System::Windows::Forms::Button());
            this->Recomendations_panel = (gcnew System::Windows::Forms::Panel());
            this->tableLayoutPanel19 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->F8_button = (gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel17 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->Recommendations_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->Recommendations_checkedListBox = (gcnew System::Windows::Forms::CheckedListBox());
            this->label17 = (gcnew System::Windows::Forms::Label());
            this->EditRec_button = (gcnew System::Windows::Forms::Button());
            this->Paste_button = (gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel16 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->AsteniaRec_button = (gcnew System::Windows::Forms::Button());
            this->PnevmoRec_button = (gcnew System::Windows::Forms::Button());
            this->BronhitRec_button = (gcnew System::Windows::Forms::Button());
            this->AnalysisResults_panel = (gcnew System::Windows::Forms::Panel());
            this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->AnalysisResults_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->AnalyzesResults_comboBox = (gcnew System::Windows::Forms::ComboBox());
            this->F5_button = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->Anamnesis_panel = (gcnew System::Windows::Forms::Panel());
            this->tableLayoutPanel14 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->tableLayoutPanel11 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->Pnevmonia_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->Astenia_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->groupBox17 = (gcnew System::Windows::Forms::GroupBox());
            this->IllBegining_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->ResponseMedstation_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->ResponseGospital_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->ResponsePolyclinic_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->groupBox18 = (gcnew System::Windows::Forms::GroupBox());
            this->ResponseDate_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->NapravlenV_tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->flowLayoutPanel5 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->SentToGospital_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->SentToLazaret_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->SentToPolyclinic_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->NapravlenieVGospital_tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->NapravlenVpolyclonic_panel = (gcnew System::Windows::Forms::Panel());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->Gospitalization_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->AmbulanceHealing_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->RepeatCheck_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->RepeatCheck_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
            this->NapravlenVLazaret_panel = (gcnew System::Windows::Forms::Panel());
            this->tableLayoutPanel21 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->label16 = (gcnew System::Windows::Forms::Label());
            this->flowLayoutPanel6 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->IsLazaretaVGospital_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->IsLazaretaVPolyclinic_radioButton = (gcnew System::Windows::Forms::RadioButton());
            this->IsLazaretaVPolyclinic_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->IsLazaretaVPolyclinic_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
            this->IsLazaretaVGospital_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->IsLazaretaVGospital_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->groupBox19 = (gcnew System::Windows::Forms::GroupBox());
            this->ResearchDate_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->FOGK_checkBox = (gcnew System::Windows::Forms::CheckBox());
            this->RgOGK_checkBox = (gcnew System::Windows::Forms::CheckBox());
            this->KT_OGK_checkBox = (gcnew System::Windows::Forms::CheckBox());
            this->OAK_checkBox = (gcnew System::Windows::Forms::CheckBox());
            this->OAM_checkBox = (gcnew System::Windows::Forms::CheckBox());
            this->BioChemicalBloodResearch_checkBox = (gcnew System::Windows::Forms::CheckBox());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->groupBox20 = (gcnew System::Windows::Forms::GroupBox());
            this->Anamnesis_textBox = (gcnew System::Windows::Forms::TextBox());
            this->F4_button = (gcnew System::Windows::Forms::Button());
            this->Stamp_panel = (gcnew System::Windows::Forms::Panel());
            this->Ill_History_panel = (gcnew System::Windows::Forms::Panel());
            this->F3_button = (gcnew System::Windows::Forms::Button());
            this->groupBox15 = (gcnew System::Windows::Forms::GroupBox());
            this->complications_comboBox = (gcnew System::Windows::Forms::ComboBox());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->groupBox16 = (gcnew System::Windows::Forms::GroupBox());
            this->related_comboBox = (gcnew System::Windows::Forms::ComboBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->MKB_groupBox = (gcnew System::Windows::Forms::GroupBox());
            this->mkb_comboBox = (gcnew System::Windows::Forms::ComboBox());
            this->groupBox14 = (gcnew System::Windows::Forms::GroupBox());
            this->epicrizdiagnoses_comboBox = (gcnew System::Windows::Forms::ComboBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->groupBox13 = (gcnew System::Windows::Forms::GroupBox());
            this->outcome_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
            this->groupBox12 = (gcnew System::Windows::Forms::GroupBox());
            this->income_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
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
            this->UnworkableList_panel = (gcnew System::Windows::Forms::Panel());
            this->tableLayoutPanel18 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->F9_button = (gcnew System::Windows::Forms::Button());
            this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
            this->PathChanger_openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
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
            this->DB_groupBox->SuspendLayout();
            this->DoctorsNotes_tableLayoutPanel->SuspendLayout();
            this->ReportDir_groupBox->SuspendLayout();
            this->tableLayoutPanel5->SuspendLayout();
            this->groupBox2->SuspendLayout();
            this->tableLayoutPanel8->SuspendLayout();
            this->Epicrisis_panel->SuspendLayout();
            this->EpiricisisTabMenu_tableLayoutPanel->SuspendLayout();
            this->Hat_tableLayoutPanel->SuspendLayout();
            this->groupBox11->SuspendLayout();
            this->groupBox10->SuspendLayout();
            this->groupBox9->SuspendLayout();
            this->groupBox8->SuspendLayout();
            this->groupBox7->SuspendLayout();
            this->groupBox6->SuspendLayout();
            this->UpperHat_tableLayoutPanel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->id_numericUpDown))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->year_numericUpDown))->BeginInit();
            this->flowLayoutPanel1->SuspendLayout();
            this->SideInfo_panel->SuspendLayout();
            this->tableLayoutPanel10->SuspendLayout();
            this->SideInfo_groupBox->SuspendLayout();
            this->TextMiniEditor_tableLayoutPanel->SuspendLayout();
            this->TextMiniEditor_flowLayoutPanel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Fontsize_numericUpDown))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->separatorControl1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->separatorControl3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->separatorControl2))->BeginInit();
            this->Recomendations_panel->SuspendLayout();
            this->tableLayoutPanel19->SuspendLayout();
            this->tableLayoutPanel17->SuspendLayout();
            this->Recommendations_groupBox->SuspendLayout();
            this->tableLayoutPanel16->SuspendLayout();
            this->AnalysisResults_panel->SuspendLayout();
            this->tableLayoutPanel9->SuspendLayout();
            this->AnalysisResults_groupBox->SuspendLayout();
            this->Anamnesis_panel->SuspendLayout();
            this->tableLayoutPanel14->SuspendLayout();
            this->panel3->SuspendLayout();
            this->tableLayoutPanel11->SuspendLayout();
            this->flowLayoutPanel2->SuspendLayout();
            this->groupBox17->SuspendLayout();
            this->flowLayoutPanel3->SuspendLayout();
            this->groupBox18->SuspendLayout();
            this->NapravlenV_tableLayoutPanel->SuspendLayout();
            this->flowLayoutPanel5->SuspendLayout();
            this->NapravlenieVGospital_tableLayoutPanel->SuspendLayout();
            this->NapravlenVpolyclonic_panel->SuspendLayout();
            this->RepeatCheck_groupBox->SuspendLayout();
            this->NapravlenVLazaret_panel->SuspendLayout();
            this->tableLayoutPanel21->SuspendLayout();
            this->flowLayoutPanel6->SuspendLayout();
            this->IsLazaretaVPolyclinic_groupBox->SuspendLayout();
            this->IsLazaretaVGospital_groupBox->SuspendLayout();
            this->groupBox19->SuspendLayout();
            this->panel2->SuspendLayout();
            this->groupBox20->SuspendLayout();
            this->Ill_History_panel->SuspendLayout();
            this->groupBox15->SuspendLayout();
            this->groupBox16->SuspendLayout();
            this->MKB_groupBox->SuspendLayout();
            this->groupBox14->SuspendLayout();
            this->groupBox13->SuspendLayout();
            this->groupBox12->SuspendLayout();
            this->AddingInfo_panel->SuspendLayout();
            this->tableLayoutPanel15->SuspendLayout();
            this->groupBox->SuspendLayout();
            this->groupBox23->SuspendLayout();
            this->tableLayoutPanel13->SuspendLayout();
            this->DoctorLook_groupBox->SuspendLayout();
            this->Mouth_groupBox->SuspendLayout();
            this->groupBox22->SuspendLayout();
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
            this->Home_panel->Size = System::Drawing::Size(1329, 742);
            this->Home_panel->TabIndex = 5;
            this->Home_panel->TabStop = true;
            // 
            // tableLayoutPanel12
            // 
            this->tableLayoutPanel12->ColumnCount = 1;
            this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel12->Controls->Add(this->label1, 0, 0);
            this->tableLayoutPanel12->Controls->Add(this->tableLayoutPanel1, 0, 1);
            this->tableLayoutPanel12->Controls->Add(this->tableLayoutPanel2, 0, 3);
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
            this->tableLayoutPanel12->Size = System::Drawing::Size(1312, 1383);
            this->tableLayoutPanel12->TabIndex = 11;
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
            this->tableLayoutPanel1->Size = System::Drawing::Size(1306, 218);
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
            this->Hitory_button->Size = System::Drawing::Size(1306, 48);
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
            this->epicrisis_button->Size = System::Drawing::Size(1306, 48);
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
            this->doctors_notes_button->Size = System::Drawing::Size(1306, 48);
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
            this->f1_button->Size = System::Drawing::Size(1306, 50);
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
            this->tableLayoutPanel2->Size = System::Drawing::Size(1306, 728);
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
            this->tableLayoutPanel7->Controls->Add(this->epicrizPathChange_button, 1, 0);
            this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel7->Location = System::Drawing::Point(3, 617);
            this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
            this->tableLayoutPanel7->RowCount = 1;
            this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->tableLayoutPanel7->Size = System::Drawing::Size(1300, 62);
            this->tableLayoutPanel7->TabIndex = 12;
            // 
            // groupBox5
            // 
            this->groupBox5->Controls->Add(this->epicrizPath_label);
            this->groupBox5->Controls->Add(this->label8);
            this->groupBox5->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox5->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox5->ForeColor = System::Drawing::SystemColors::WindowText;
            this->groupBox5->Location = System::Drawing::Point(3, 3);
            this->groupBox5->Name = L"groupBox5";
            this->groupBox5->Size = System::Drawing::Size(1168, 56);
            this->groupBox5->TabIndex = 8;
            this->groupBox5->TabStop = false;
            this->groupBox5->Text = L"Путь сохранения отчета";
            // 
            // epicrizPath_label
            // 
            this->epicrizPath_label->Dock = System::Windows::Forms::DockStyle::Fill;
            this->epicrizPath_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->epicrizPath_label->ForeColor = System::Drawing::SystemColors::ControlText;
            this->epicrizPath_label->Location = System::Drawing::Point(3, 18);
            this->epicrizPath_label->Name = L"epicrizPath_label";
            this->epicrizPath_label->Size = System::Drawing::Size(1162, 35);
            this->epicrizPath_label->TabIndex = 3;
            this->epicrizPath_label->Text = L"C:\\Users\\user\\Documents\\Записи лечащего врача";
            this->epicrizPath_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
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
            // epicrizPathChange_button
            // 
            this->epicrizPathChange_button->BackColor = System::Drawing::Color::White;
            this->epicrizPathChange_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->epicrizPathChange_button->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->epicrizPathChange_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->epicrizPathChange_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)),
                static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->epicrizPathChange_button->Location = System::Drawing::Point(1177, 10);
            this->epicrizPathChange_button->Name = L"epicrizPathChange_button";
            this->epicrizPathChange_button->Size = System::Drawing::Size(120, 49);
            this->epicrizPathChange_button->TabIndex = 7;
            this->epicrizPathChange_button->TabStop = false;
            this->epicrizPathChange_button->Text = L"Изменить";
            this->epicrizPathChange_button->UseVisualStyleBackColor = false;
            this->epicrizPathChange_button->Click += gcnew System::EventHandler(this, &MainWindow::epicrizPathChange_button_Click);
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
            this->groupBox4->Controls->Add(this->textBox5);
            this->groupBox4->Controls->Add(this->label6);
            this->groupBox4->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox4->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox4->ForeColor = System::Drawing::SystemColors::WindowText;
            this->groupBox4->Location = System::Drawing::Point(3, 512);
            this->groupBox4->Name = L"groupBox4";
            this->groupBox4->Size = System::Drawing::Size(1300, 62);
            this->groupBox4->TabIndex = 10;
            this->groupBox4->TabStop = false;
            this->groupBox4->Text = L"Префикс имени файла отчета";
            // 
            // textBox5
            // 
            this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox5->Dock = System::Windows::Forms::DockStyle::Fill;
            this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->textBox5->Location = System::Drawing::Point(3, 18);
            this->textBox5->Name = L"textBox5";
            this->textBox5->Size = System::Drawing::Size(1294, 19);
            this->textBox5->TabIndex = 2;
            this->textBox5->TabStop = false;
            this->textBox5->Text = L"Первый лист";
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
            this->tableLayoutPanel6->Size = System::Drawing::Size(1300, 62);
            this->tableLayoutPanel6->TabIndex = 9;
            // 
            // groupBox3
            // 
            this->groupBox3->Controls->Add(this->label20);
            this->groupBox3->Controls->Add(this->label5);
            this->groupBox3->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox3->ForeColor = System::Drawing::SystemColors::WindowText;
            this->groupBox3->Location = System::Drawing::Point(3, 3);
            this->groupBox3->Name = L"groupBox3";
            this->groupBox3->Size = System::Drawing::Size(1168, 56);
            this->groupBox3->TabIndex = 8;
            this->groupBox3->TabStop = false;
            this->groupBox3->Text = L"Путь сохранения отчета";
            // 
            // label20
            // 
            this->label20->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label20->ForeColor = System::Drawing::SystemColors::ControlText;
            this->label20->Location = System::Drawing::Point(3, 18);
            this->label20->Name = L"label20";
            this->label20->Size = System::Drawing::Size(1162, 35);
            this->label20->TabIndex = 3;
            this->label20->Text = L"C:\\Users\\user\\Documents\\Записи лечащего врача";
            this->label20->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
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
            this->button1->Location = System::Drawing::Point(1177, 10);
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
            this->tableLayoutPanel3->Size = System::Drawing::Size(1300, 62);
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
            this->TemplatesChange_button->Location = System::Drawing::Point(1177, 10);
            this->TemplatesChange_button->Name = L"TemplatesChange_button";
            this->TemplatesChange_button->Size = System::Drawing::Size(120, 49);
            this->TemplatesChange_button->TabIndex = 0;
            this->TemplatesChange_button->TabStop = false;
            this->TemplatesChange_button->Text = L"Изменить";
            this->TemplatesChange_button->UseVisualStyleBackColor = false;
            this->TemplatesChange_button->Click += gcnew System::EventHandler(this, &MainWindow::TemplatesChange_button_Click);
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->tamplatesPath_label);
            this->groupBox1->Controls->Add(this->Template_label);
            this->groupBox1->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox1->ForeColor = System::Drawing::SystemColors::WindowText;
            this->groupBox1->Location = System::Drawing::Point(3, 3);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(1168, 56);
            this->groupBox1->TabIndex = 1;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Папка с шаблонами";
            // 
            // tamplatesPath_label
            // 
            this->tamplatesPath_label->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tamplatesPath_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->tamplatesPath_label->ForeColor = System::Drawing::SystemColors::ControlText;
            this->tamplatesPath_label->Location = System::Drawing::Point(3, 18);
            this->tamplatesPath_label->Name = L"tamplatesPath_label";
            this->tamplatesPath_label->Size = System::Drawing::Size(1162, 35);
            this->tamplatesPath_label->TabIndex = 1;
            this->tamplatesPath_label->Text = L"C:\\Users\\erik\\develop\\host\\project\\unsaintedWinApp\\Templates\\";
            this->tamplatesPath_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
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
            this->tableLayoutPanel4->Size = System::Drawing::Size(1300, 62);
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
            this->DB_create_button->Location = System::Drawing::Point(1177, 10);
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
            this->DB_change_button->Location = System::Drawing::Point(1051, 10);
            this->DB_change_button->Name = L"DB_change_button";
            this->DB_change_button->Size = System::Drawing::Size(120, 49);
            this->DB_change_button->TabIndex = 1;
            this->DB_change_button->TabStop = false;
            this->DB_change_button->Text = L"Изменить";
            this->DB_change_button->UseVisualStyleBackColor = false;
            this->DB_change_button->Click += gcnew System::EventHandler(this, &MainWindow::DB_change_button_Click);
            // 
            // DB_groupBox
            // 
            this->DB_groupBox->Controls->Add(this->dbPath_label);
            this->DB_groupBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->DB_groupBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->DB_groupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->DB_groupBox->Location = System::Drawing::Point(3, 3);
            this->DB_groupBox->Name = L"DB_groupBox";
            this->DB_groupBox->Size = System::Drawing::Size(1042, 56);
            this->DB_groupBox->TabIndex = 0;
            this->DB_groupBox->TabStop = false;
            this->DB_groupBox->Text = L"Файл базы данных";
            // 
            // dbPath_label
            // 
            this->dbPath_label->Dock = System::Windows::Forms::DockStyle::Fill;
            this->dbPath_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->dbPath_label->ForeColor = System::Drawing::SystemColors::ControlText;
            this->dbPath_label->Location = System::Drawing::Point(3, 18);
            this->dbPath_label->Name = L"dbPath_label";
            this->dbPath_label->Size = System::Drawing::Size(1036, 35);
            this->dbPath_label->TabIndex = 0;
            this->dbPath_label->Text = L"C:\\Users\\erik\\develop\\host\\projects\\unsaintedWinApp\\prod.db";
            this->dbPath_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
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
            this->DoctorsNotes_tableLayoutPanel->Size = System::Drawing::Size(1300, 62);
            this->DoctorsNotes_tableLayoutPanel->TabIndex = 6;
            // 
            // ReportDir_groupBox
            // 
            this->ReportDir_groupBox->Controls->Add(this->label18);
            this->ReportDir_groupBox->Controls->Add(this->label2);
            this->ReportDir_groupBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->ReportDir_groupBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ReportDir_groupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->ReportDir_groupBox->ForeColor = System::Drawing::SystemColors::WindowText;
            this->ReportDir_groupBox->Location = System::Drawing::Point(3, 3);
            this->ReportDir_groupBox->Name = L"ReportDir_groupBox";
            this->ReportDir_groupBox->Size = System::Drawing::Size(1168, 56);
            this->ReportDir_groupBox->TabIndex = 8;
            this->ReportDir_groupBox->TabStop = false;
            this->ReportDir_groupBox->Text = L"Путь сохранения отчета";
            // 
            // label18
            // 
            this->label18->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label18->ForeColor = System::Drawing::SystemColors::ControlText;
            this->label18->Location = System::Drawing::Point(3, 18);
            this->label18->Name = L"label18";
            this->label18->Size = System::Drawing::Size(1162, 35);
            this->label18->TabIndex = 2;
            this->label18->Text = L"C:\\Users\\user\\Documents\\Записи лечащего врача";
            this->label18->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
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
            this->ReportSave_button->Location = System::Drawing::Point(1177, 10);
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
            this->tableLayoutPanel5->Size = System::Drawing::Size(1300, 62);
            this->tableLayoutPanel5->TabIndex = 7;
            // 
            // groupBox2
            // 
            this->groupBox2->Controls->Add(this->textBox4);
            this->groupBox2->Controls->Add(this->label3);
            this->groupBox2->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox2->ForeColor = System::Drawing::SystemColors::WindowText;
            this->groupBox2->Location = System::Drawing::Point(3, 3);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = System::Drawing::Size(1294, 56);
            this->groupBox2->TabIndex = 9;
            this->groupBox2->TabStop = false;
            this->groupBox2->Text = L"Префикс имени файла отчета";
            // 
            // textBox4
            // 
            this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox4->Dock = System::Windows::Forms::DockStyle::Fill;
            this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->textBox4->Location = System::Drawing::Point(3, 18);
            this->textBox4->Name = L"textBox4";
            this->textBox4->Size = System::Drawing::Size(1288, 19);
            this->textBox4->TabIndex = 1;
            this->textBox4->TabStop = false;
            this->textBox4->Text = L"Лист первичного осмотра";
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
            this->tableLayoutPanel8->Size = System::Drawing::Size(1300, 40);
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
            this->Recovery_button->Location = System::Drawing::Point(493, 3);
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
            this->SaveSettings_button->Location = System::Drawing::Point(653, 3);
            this->SaveSettings_button->Name = L"SaveSettings_button";
            this->SaveSettings_button->Size = System::Drawing::Size(117, 34);
            this->SaveSettings_button->TabIndex = 1;
            this->SaveSettings_button->TabStop = false;
            this->SaveSettings_button->Text = L"Сохранить";
            this->SaveSettings_button->UseVisualStyleBackColor = false;
            // 
            // Epicrisis_panel
            // 
            this->Epicrisis_panel->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->Epicrisis_panel->Controls->Add(this->EpiricisisTabMenu_tableLayoutPanel);
            this->Epicrisis_panel->Controls->Add(this->Hat_tableLayoutPanel);
            this->Epicrisis_panel->Controls->Add(this->UpperHat_tableLayoutPanel);
            this->Epicrisis_panel->Controls->Add(this->SideInfo_panel);
            this->Epicrisis_panel->Controls->Add(this->Recomendations_panel);
            this->Epicrisis_panel->Controls->Add(this->AnalysisResults_panel);
            this->Epicrisis_panel->Controls->Add(this->Anamnesis_panel);
            this->Epicrisis_panel->Controls->Add(this->Stamp_panel);
            this->Epicrisis_panel->Controls->Add(this->Ill_History_panel);
            this->Epicrisis_panel->Controls->Add(this->AddingInfo_panel);
            this->Epicrisis_panel->Controls->Add(this->UnworkableList_panel);
            this->Epicrisis_panel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Epicrisis_panel->Location = System::Drawing::Point(0, 0);
            this->Epicrisis_panel->Name = L"Epicrisis_panel";
            this->Epicrisis_panel->Size = System::Drawing::Size(1329, 742);
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
            this->EpiricisisTabMenu_tableLayoutPanel->RowCount = 3;
            this->EpiricisisTabMenu_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                58)));
            this->EpiricisisTabMenu_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                30)));
            this->EpiricisisTabMenu_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->EpiricisisTabMenu_tableLayoutPanel->Size = System::Drawing::Size(1329, 64);
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
            this->Stamp_button->Size = System::Drawing::Size(106, 54);
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
            this->Stamp_label->Size = System::Drawing::Size(104, 13);
            this->Stamp_label->TabIndex = 21;
            // 
            // Hat_tableLayoutPanel
            // 
            this->Hat_tableLayoutPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->Hat_tableLayoutPanel->ColumnCount = 3;
            this->Hat_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                33.33333F)));
            this->Hat_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                33.33334F)));
            this->Hat_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                33.33334F)));
            this->Hat_tableLayoutPanel->Controls->Add(this->groupBox11, 2, 1);
            this->Hat_tableLayoutPanel->Controls->Add(this->groupBox10, 1, 1);
            this->Hat_tableLayoutPanel->Controls->Add(this->groupBox9, 0, 1);
            this->Hat_tableLayoutPanel->Controls->Add(this->groupBox8, 2, 0);
            this->Hat_tableLayoutPanel->Controls->Add(this->groupBox7, 1, 0);
            this->Hat_tableLayoutPanel->Controls->Add(this->groupBox6, 0, 0);
            this->Hat_tableLayoutPanel->Location = System::Drawing::Point(2, 51);
            this->Hat_tableLayoutPanel->Name = L"Hat_tableLayoutPanel";
            this->Hat_tableLayoutPanel->RowCount = 3;
            this->Hat_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->Hat_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->Hat_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->Hat_tableLayoutPanel->Size = System::Drawing::Size(1324, 100);
            this->Hat_tableLayoutPanel->TabIndex = 5;
            // 
            // groupBox11
            // 
            this->groupBox11->Controls->Add(this->birthday_dateTimePicker);
            this->groupBox11->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox11->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox11->Location = System::Drawing::Point(885, 53);
            this->groupBox11->Name = L"groupBox11";
            this->groupBox11->Size = System::Drawing::Size(436, 44);
            this->groupBox11->TabIndex = 5;
            this->groupBox11->TabStop = false;
            this->groupBox11->Text = L"Дата рождения*";
            // 
            // birthday_dateTimePicker
            // 
            this->birthday_dateTimePicker->Dock = System::Windows::Forms::DockStyle::Fill;
            this->birthday_dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->birthday_dateTimePicker->Location = System::Drawing::Point(3, 16);
            this->birthday_dateTimePicker->Name = L"birthday_dateTimePicker";
            this->birthday_dateTimePicker->Size = System::Drawing::Size(430, 20);
            this->birthday_dateTimePicker->TabIndex = 8;
            this->birthday_dateTimePicker->Leave += gcnew System::EventHandler(this, &MainWindow::birthday_dateTimePicker_Leave);
            // 
            // groupBox10
            // 
            this->groupBox10->Controls->Add(this->militaryUnit_comboBox);
            this->groupBox10->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox10->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox10->Location = System::Drawing::Point(444, 53);
            this->groupBox10->Name = L"groupBox10";
            this->groupBox10->Size = System::Drawing::Size(435, 44);
            this->groupBox10->TabIndex = 4;
            this->groupBox10->TabStop = false;
            this->groupBox10->Text = L"Воинская часть*";
            // 
            // militaryUnit_comboBox
            // 
            this->militaryUnit_comboBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->militaryUnit_comboBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->militaryUnit_comboBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->militaryUnit_comboBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->militaryUnit_comboBox->DropDownHeight = 150;
            this->militaryUnit_comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->militaryUnit_comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->militaryUnit_comboBox->FormattingEnabled = true;
            this->militaryUnit_comboBox->IntegralHeight = false;
            this->militaryUnit_comboBox->Location = System::Drawing::Point(3, 16);
            this->militaryUnit_comboBox->MaxDropDownItems = 10;
            this->militaryUnit_comboBox->Name = L"militaryUnit_comboBox";
            this->militaryUnit_comboBox->Size = System::Drawing::Size(429, 24);
            this->militaryUnit_comboBox->TabIndex = 7;
            this->militaryUnit_comboBox->Click += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->militaryUnit_comboBox->Enter += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->militaryUnit_comboBox->Leave += gcnew System::EventHandler(this, &MainWindow::militaryUnit_comboBox_Leave);
            // 
            // groupBox9
            // 
            this->groupBox9->Controls->Add(this->rank_comboBox);
            this->groupBox9->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox9->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox9->Location = System::Drawing::Point(3, 53);
            this->groupBox9->Name = L"groupBox9";
            this->groupBox9->Size = System::Drawing::Size(435, 44);
            this->groupBox9->TabIndex = 3;
            this->groupBox9->TabStop = false;
            this->groupBox9->Text = L"Звание*";
            // 
            // rank_comboBox
            // 
            this->rank_comboBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->rank_comboBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->rank_comboBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->rank_comboBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->rank_comboBox->DropDownHeight = 150;
            this->rank_comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->rank_comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->rank_comboBox->FormattingEnabled = true;
            this->rank_comboBox->IntegralHeight = false;
            this->rank_comboBox->Location = System::Drawing::Point(3, 16);
            this->rank_comboBox->MaxDropDownItems = 10;
            this->rank_comboBox->Name = L"rank_comboBox";
            this->rank_comboBox->Size = System::Drawing::Size(429, 24);
            this->rank_comboBox->TabIndex = 6;
            this->rank_comboBox->Text = L"Рядовой";
            this->rank_comboBox->Click += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->rank_comboBox->Enter += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->rank_comboBox->Leave += gcnew System::EventHandler(this, &MainWindow::rank_comboBox_Leave);
            // 
            // groupBox8
            // 
            this->groupBox8->Controls->Add(this->Patronymic_comboBox);
            this->groupBox8->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox8->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox8->Location = System::Drawing::Point(885, 3);
            this->groupBox8->Name = L"groupBox8";
            this->groupBox8->Size = System::Drawing::Size(436, 44);
            this->groupBox8->TabIndex = 2;
            this->groupBox8->TabStop = false;
            this->groupBox8->Text = L"Отчество";
            // 
            // Patronymic_comboBox
            // 
            this->Patronymic_comboBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->Patronymic_comboBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->Patronymic_comboBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->Patronymic_comboBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Patronymic_comboBox->DropDownHeight = 150;
            this->Patronymic_comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Patronymic_comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->Patronymic_comboBox->FormattingEnabled = true;
            this->Patronymic_comboBox->IntegralHeight = false;
            this->Patronymic_comboBox->Location = System::Drawing::Point(3, 16);
            this->Patronymic_comboBox->MaxDropDownItems = 10;
            this->Patronymic_comboBox->Name = L"Patronymic_comboBox";
            this->Patronymic_comboBox->Size = System::Drawing::Size(430, 24);
            this->Patronymic_comboBox->TabIndex = 5;
            this->Patronymic_comboBox->Click += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->Patronymic_comboBox->Enter += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->Patronymic_comboBox->Leave += gcnew System::EventHandler(this, &MainWindow::Patronymic_comboBox_Leave);
            // 
            // groupBox7
            // 
            this->groupBox7->Controls->Add(this->Names_comboBox);
            this->groupBox7->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox7->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox7->Location = System::Drawing::Point(444, 3);
            this->groupBox7->Name = L"groupBox7";
            this->groupBox7->Size = System::Drawing::Size(435, 44);
            this->groupBox7->TabIndex = 1;
            this->groupBox7->TabStop = false;
            this->groupBox7->Text = L"Имя";
            // 
            // Names_comboBox
            // 
            this->Names_comboBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->Names_comboBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->Names_comboBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->Names_comboBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Names_comboBox->DropDownHeight = 150;
            this->Names_comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Names_comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Names_comboBox->FormattingEnabled = true;
            this->Names_comboBox->IntegralHeight = false;
            this->Names_comboBox->Location = System::Drawing::Point(3, 16);
            this->Names_comboBox->MaxDropDownItems = 10;
            this->Names_comboBox->Name = L"Names_comboBox";
            this->Names_comboBox->Size = System::Drawing::Size(429, 24);
            this->Names_comboBox->TabIndex = 4;
            this->Names_comboBox->Click += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->Names_comboBox->Enter += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->Names_comboBox->Leave += gcnew System::EventHandler(this, &MainWindow::Names_comboBox_Leave);
            // 
            // groupBox6
            // 
            this->groupBox6->Controls->Add(this->Surname_comboBox);
            this->groupBox6->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox6->Dock = System::Windows::Forms::DockStyle::Fill;
            this->groupBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox6->Location = System::Drawing::Point(3, 3);
            this->groupBox6->Name = L"groupBox6";
            this->groupBox6->Size = System::Drawing::Size(435, 44);
            this->groupBox6->TabIndex = 0;
            this->groupBox6->TabStop = false;
            this->groupBox6->Text = L"Фамилия";
            // 
            // Surname_comboBox
            // 
            this->Surname_comboBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->Surname_comboBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->Surname_comboBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->Surname_comboBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Surname_comboBox->DropDownHeight = 150;
            this->Surname_comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Surname_comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->Surname_comboBox->FormattingEnabled = true;
            this->Surname_comboBox->IntegralHeight = false;
            this->Surname_comboBox->Location = System::Drawing::Point(3, 16);
            this->Surname_comboBox->MaxDropDownItems = 10;
            this->Surname_comboBox->Name = L"Surname_comboBox";
            this->Surname_comboBox->Size = System::Drawing::Size(429, 24);
            this->Surname_comboBox->TabIndex = 3;
            this->Surname_comboBox->Click += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->Surname_comboBox->Enter += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->Surname_comboBox->Leave += gcnew System::EventHandler(this, &MainWindow::Surname_comboBox_Leave);
            // 
            // UpperHat_tableLayoutPanel
            // 
            this->UpperHat_tableLayoutPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->UpperHat_tableLayoutPanel->AutoSize = true;
            this->UpperHat_tableLayoutPanel->ColumnCount = 4;
            this->UpperHat_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                237)));
            this->UpperHat_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                145)));
            this->UpperHat_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                136)));
            this->UpperHat_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                163)));
            this->UpperHat_tableLayoutPanel->Controls->Add(this->id_numericUpDown, 0, 0);
            this->UpperHat_tableLayoutPanel->Controls->Add(this->year_numericUpDown, 1, 0);
            this->UpperHat_tableLayoutPanel->Controls->Add(this->ID_label, 0, 0);
            this->UpperHat_tableLayoutPanel->Controls->Add(this->flowLayoutPanel1, 3, 0);
            this->UpperHat_tableLayoutPanel->Location = System::Drawing::Point(0, 0);
            this->UpperHat_tableLayoutPanel->Name = L"UpperHat_tableLayoutPanel";
            this->UpperHat_tableLayoutPanel->RowCount = 2;
            this->UpperHat_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->UpperHat_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->UpperHat_tableLayoutPanel->Size = System::Drawing::Size(1329, 70);
            this->UpperHat_tableLayoutPanel->TabIndex = 4;
            // 
            // id_numericUpDown
            // 
            this->id_numericUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->id_numericUpDown->AutoSize = true;
            this->id_numericUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->id_numericUpDown->Location = System::Drawing::Point(240, 10);
            this->id_numericUpDown->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
            this->id_numericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
            this->id_numericUpDown->Name = L"id_numericUpDown";
            this->id_numericUpDown->Size = System::Drawing::Size(139, 29);
            this->id_numericUpDown->TabIndex = 1;
            this->id_numericUpDown->Enter += gcnew System::EventHandler(this, &MainWindow::id_numericUpDown_Enter);
            this->id_numericUpDown->Leave += gcnew System::EventHandler(this, &MainWindow::id_numericUpDown_Leave);
            // 
            // year_numericUpDown
            // 
            this->year_numericUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->year_numericUpDown->AutoSize = true;
            this->year_numericUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->year_numericUpDown->Location = System::Drawing::Point(385, 10);
            this->year_numericUpDown->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
            this->year_numericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2100, 0, 0, 0 });
            this->year_numericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2024, 0, 0, 0 });
            this->year_numericUpDown->Name = L"year_numericUpDown";
            this->year_numericUpDown->Size = System::Drawing::Size(130, 29);
            this->year_numericUpDown->TabIndex = 2;
            this->year_numericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2024, 0, 0, 0 });
            this->year_numericUpDown->Enter += gcnew System::EventHandler(this, &MainWindow::year_numericUpDown_Enter);
            this->year_numericUpDown->Leave += gcnew System::EventHandler(this, &MainWindow::year_numericUpDown_Leave);
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
            this->flowLayoutPanel1->Size = System::Drawing::Size(805, 46);
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
            this->button3->Location = System::Drawing::Point(678, 1);
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
            this->Clear_button->Location = System::Drawing::Point(548, 1);
            this->Clear_button->Margin = System::Windows::Forms::Padding(0, 1, 3, 3);
            this->Clear_button->Name = L"Clear_button";
            this->Clear_button->Size = System::Drawing::Size(124, 37);
            this->Clear_button->TabIndex = 1;
            this->Clear_button->TabStop = false;
            this->Clear_button->Text = L"Очистить";
            this->Clear_button->UseVisualStyleBackColor = false;
            // 
            // SideInfo_panel
            // 
            this->SideInfo_panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->SideInfo_panel->Controls->Add(this->tableLayoutPanel10);
            this->SideInfo_panel->Location = System::Drawing::Point(0, 180);
            this->SideInfo_panel->Name = L"SideInfo_panel";
            this->SideInfo_panel->Padding = System::Windows::Forms::Padding(5);
            this->SideInfo_panel->Size = System::Drawing::Size(1329, 500);
            this->SideInfo_panel->TabIndex = 4;
            // 
            // tableLayoutPanel10
            // 
            this->tableLayoutPanel10->ColumnCount = 1;
            this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel10->Controls->Add(this->SideInfo_groupBox, 0, 0);
            this->tableLayoutPanel10->Controls->Add(this->TextMiniEditor_tableLayoutPanel, 0, 1);
            this->tableLayoutPanel10->Controls->Add(this->F7_button, 0, 2);
            this->tableLayoutPanel10->Dock = System::Windows::Forms::DockStyle::Top;
            this->tableLayoutPanel10->Location = System::Drawing::Point(5, 5);
            this->tableLayoutPanel10->Name = L"tableLayoutPanel10";
            this->tableLayoutPanel10->RowCount = 3;
            this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel10->Size = System::Drawing::Size(1319, 328);
            this->tableLayoutPanel10->TabIndex = 17;
            // 
            // SideInfo_groupBox
            // 
            this->SideInfo_groupBox->Controls->Add(this->CheckBoxes_flowLayoutPanel);
            this->SideInfo_groupBox->Location = System::Drawing::Point(3, 3);
            this->SideInfo_groupBox->Name = L"SideInfo_groupBox";
            this->SideInfo_groupBox->Size = System::Drawing::Size(1313, 45);
            this->SideInfo_groupBox->TabIndex = 0;
            this->SideInfo_groupBox->TabStop = false;
            // 
            // CheckBoxes_flowLayoutPanel
            // 
            this->CheckBoxes_flowLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->CheckBoxes_flowLayoutPanel->Location = System::Drawing::Point(3, 16);
            this->CheckBoxes_flowLayoutPanel->Name = L"CheckBoxes_flowLayoutPanel";
            this->CheckBoxes_flowLayoutPanel->Padding = System::Windows::Forms::Padding(5, 0, 5, 0);
            this->CheckBoxes_flowLayoutPanel->Size = System::Drawing::Size(1307, 26);
            this->CheckBoxes_flowLayoutPanel->TabIndex = 0;
            this->CheckBoxes_flowLayoutPanel->WrapContents = false;
            // 
            // TextMiniEditor_tableLayoutPanel
            // 
            this->TextMiniEditor_tableLayoutPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->TextMiniEditor_tableLayoutPanel->AutoSize = true;
            this->TextMiniEditor_tableLayoutPanel->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
            this->TextMiniEditor_tableLayoutPanel->ColumnCount = 1;
            this->TextMiniEditor_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->TextMiniEditor_tableLayoutPanel->Controls->Add(this->richTextBox, 0, 1);
            this->TextMiniEditor_tableLayoutPanel->Controls->Add(this->TextMiniEditor_flowLayoutPanel, 0, 0);
            this->TextMiniEditor_tableLayoutPanel->Location = System::Drawing::Point(3, 54);
            this->TextMiniEditor_tableLayoutPanel->Name = L"TextMiniEditor_tableLayoutPanel";
            this->TextMiniEditor_tableLayoutPanel->RowCount = 2;
            this->TextMiniEditor_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->TextMiniEditor_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->TextMiniEditor_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->TextMiniEditor_tableLayoutPanel->Size = System::Drawing::Size(1313, 228);
            this->TextMiniEditor_tableLayoutPanel->TabIndex = 17;
            // 
            // richTextBox
            // 
            this->richTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->richTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->richTextBox->Location = System::Drawing::Point(4, 53);
            this->richTextBox->Name = L"richTextBox";
            this->richTextBox->Size = System::Drawing::Size(1305, 171);
            this->richTextBox->TabIndex = 0;
            this->richTextBox->Text = L"";
            this->richTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::richTextBox_KeyDown);
            // 
            // TextMiniEditor_flowLayoutPanel
            // 
            this->TextMiniEditor_flowLayoutPanel->AutoSize = true;
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->Fontsize_numericUpDown);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->separatorControl1);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->Bold_button);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->Italic_button);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->Underline_button);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->Uppercase_button);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->Lowercase_button);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->Unker_button);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->NumList_button);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->DotList_button);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->CleanFormat_button);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->separatorControl3);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->LeftAlign_button);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->CenterAlign_button);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->RightAlign_button);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->WideAlign_button);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->separatorControl2);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->Date_button);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->DropDownMenu_button);
            this->TextMiniEditor_flowLayoutPanel->Controls->Add(this->Table_button);
            this->TextMiniEditor_flowLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->TextMiniEditor_flowLayoutPanel->Location = System::Drawing::Point(1, 1);
            this->TextMiniEditor_flowLayoutPanel->Margin = System::Windows::Forms::Padding(0);
            this->TextMiniEditor_flowLayoutPanel->Name = L"TextMiniEditor_flowLayoutPanel";
            this->TextMiniEditor_flowLayoutPanel->Size = System::Drawing::Size(1311, 48);
            this->TextMiniEditor_flowLayoutPanel->TabIndex = 1;
            // 
            // Fontsize_numericUpDown
            // 
            this->Fontsize_numericUpDown->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->Fontsize_numericUpDown->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Fontsize_numericUpDown->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->Fontsize_numericUpDown->Location = System::Drawing::Point(6, 10);
            this->Fontsize_numericUpDown->Margin = System::Windows::Forms::Padding(6, 10, 3, 0);
            this->Fontsize_numericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 72, 0, 0, 0 });
            this->Fontsize_numericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->Fontsize_numericUpDown->Name = L"Fontsize_numericUpDown";
            this->Fontsize_numericUpDown->Size = System::Drawing::Size(48, 28);
            this->Fontsize_numericUpDown->TabIndex = 0;
            this->Fontsize_numericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 11, 0, 0, 0 });
            this->Fontsize_numericUpDown->ValueChanged += gcnew System::EventHandler(this, &MainWindow::Fontsize_numericUpDown_ValueChanged);
            // 
            // separatorControl1
            // 
            this->separatorControl1->AutoSizeMode = true;
            this->separatorControl1->BackColor = System::Drawing::SystemColors::ControlDark;
            this->separatorControl1->Dock = System::Windows::Forms::DockStyle::Left;
            this->separatorControl1->LineOrientation = System::Windows::Forms::Orientation::Vertical;
            this->separatorControl1->LineThickness = 2;
            this->separatorControl1->Location = System::Drawing::Point(57, 0);
            this->separatorControl1->Margin = System::Windows::Forms::Padding(0);
            this->separatorControl1->Name = L"separatorControl1";
            this->separatorControl1->Padding = System::Windows::Forms::Padding(0);
            this->separatorControl1->Size = System::Drawing::Size(2, 48);
            this->separatorControl1->TabIndex = 20;
            // 
            // Bold_button
            // 
            this->Bold_button->AutoSize = true;
            this->Bold_button->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->Bold_button->Dock = System::Windows::Forms::DockStyle::Left;
            this->Bold_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->Bold_button->FlatAppearance->BorderSize = 0;
            this->Bold_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Bold_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Bold_button->ForeColor = System::Drawing::Color::Black;
            this->Bold_button->Location = System::Drawing::Point(62, 6);
            this->Bold_button->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
            this->Bold_button->Name = L"Bold_button";
            this->Bold_button->Size = System::Drawing::Size(36, 36);
            this->Bold_button->TabIndex = 2;
            this->Bold_button->TabStop = false;
            this->Bold_button->Text = L"B";
            this->Bold_button->UseVisualStyleBackColor = false;
            this->Bold_button->Click += gcnew System::EventHandler(this, &MainWindow::Bold_button_Click);
            // 
            // Italic_button
            // 
            this->Italic_button->AutoSize = true;
            this->Italic_button->Dock = System::Windows::Forms::DockStyle::Left;
            this->Italic_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->Italic_button->FlatAppearance->BorderSize = 0;
            this->Italic_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Italic_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->Italic_button->Location = System::Drawing::Point(104, 6);
            this->Italic_button->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
            this->Italic_button->Name = L"Italic_button";
            this->Italic_button->Size = System::Drawing::Size(36, 36);
            this->Italic_button->TabIndex = 3;
            this->Italic_button->TabStop = false;
            this->Italic_button->Text = L"I";
            this->Italic_button->UseVisualStyleBackColor = true;
            this->Italic_button->Click += gcnew System::EventHandler(this, &MainWindow::Italic_button_Click);
            this->Italic_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::richTextBox_KeyDown);
            // 
            // Underline_button
            // 
            this->Underline_button->AutoSize = true;
            this->Underline_button->Dock = System::Windows::Forms::DockStyle::Left;
            this->Underline_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->Underline_button->FlatAppearance->BorderSize = 0;
            this->Underline_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Underline_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->Underline_button->Location = System::Drawing::Point(146, 6);
            this->Underline_button->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
            this->Underline_button->Name = L"Underline_button";
            this->Underline_button->Size = System::Drawing::Size(36, 36);
            this->Underline_button->TabIndex = 4;
            this->Underline_button->TabStop = false;
            this->Underline_button->Text = L"U";
            this->Underline_button->UseVisualStyleBackColor = true;
            this->Underline_button->Click += gcnew System::EventHandler(this, &MainWindow::Underline_button_Click);
            this->Underline_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::richTextBox_KeyDown);
            // 
            // Uppercase_button
            // 
            this->Uppercase_button->AutoSize = true;
            this->Uppercase_button->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->Uppercase_button->Dock = System::Windows::Forms::DockStyle::Left;
            this->Uppercase_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->Uppercase_button->FlatAppearance->BorderSize = 0;
            this->Uppercase_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Uppercase_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Uppercase_button->Location = System::Drawing::Point(188, 6);
            this->Uppercase_button->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
            this->Uppercase_button->Name = L"Uppercase_button";
            this->Uppercase_button->Size = System::Drawing::Size(35, 36);
            this->Uppercase_button->TabIndex = 5;
            this->Uppercase_button->TabStop = false;
            this->Uppercase_button->Text = L"X";
            this->Uppercase_button->UseVisualStyleBackColor = false;
            this->Uppercase_button->Click += gcnew System::EventHandler(this, &MainWindow::Uppercase_button_Click);
            this->Uppercase_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::richTextBox_KeyDown);
            // 
            // Lowercase_button
            // 
            this->Lowercase_button->AutoSize = true;
            this->Lowercase_button->Dock = System::Windows::Forms::DockStyle::Left;
            this->Lowercase_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->Lowercase_button->FlatAppearance->BorderSize = 0;
            this->Lowercase_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Lowercase_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Lowercase_button->Location = System::Drawing::Point(229, 6);
            this->Lowercase_button->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
            this->Lowercase_button->Name = L"Lowercase_button";
            this->Lowercase_button->Size = System::Drawing::Size(35, 36);
            this->Lowercase_button->TabIndex = 6;
            this->Lowercase_button->TabStop = false;
            this->Lowercase_button->Text = L"X";
            this->Lowercase_button->UseVisualStyleBackColor = true;
            this->Lowercase_button->Click += gcnew System::EventHandler(this, &MainWindow::Lowercase_button_Click);
            this->Lowercase_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::richTextBox_KeyDown);
            // 
            // Unker_button
            // 
            this->Unker_button->AutoSize = true;
            this->Unker_button->Dock = System::Windows::Forms::DockStyle::Left;
            this->Unker_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->Unker_button->FlatAppearance->BorderSize = 0;
            this->Unker_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Unker_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Unker_button->Location = System::Drawing::Point(270, 6);
            this->Unker_button->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
            this->Unker_button->Name = L"Unker_button";
            this->Unker_button->Size = System::Drawing::Size(36, 36);
            this->Unker_button->TabIndex = 7;
            this->Unker_button->TabStop = false;
            this->Unker_button->Text = L"B";
            this->Unker_button->UseVisualStyleBackColor = true;
            this->Unker_button->Click += gcnew System::EventHandler(this, &MainWindow::Unker_button_Click);
            this->Unker_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::richTextBox_KeyDown);
            // 
            // NumList_button
            // 
            this->NumList_button->AutoSize = true;
            this->NumList_button->Dock = System::Windows::Forms::DockStyle::Left;
            this->NumList_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->NumList_button->FlatAppearance->BorderSize = 0;
            this->NumList_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->NumList_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->NumList_button->Location = System::Drawing::Point(312, 6);
            this->NumList_button->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
            this->NumList_button->Name = L"NumList_button";
            this->NumList_button->Size = System::Drawing::Size(36, 36);
            this->NumList_button->TabIndex = 8;
            this->NumList_button->TabStop = false;
            this->NumList_button->Text = L"B";
            this->NumList_button->UseVisualStyleBackColor = true;
            this->NumList_button->Click += gcnew System::EventHandler(this, &MainWindow::NumList_button_Click);
            this->NumList_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::richTextBox_KeyDown);
            // 
            // DotList_button
            // 
            this->DotList_button->AutoSize = true;
            this->DotList_button->Dock = System::Windows::Forms::DockStyle::Left;
            this->DotList_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->DotList_button->FlatAppearance->BorderSize = 0;
            this->DotList_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->DotList_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->DotList_button->Location = System::Drawing::Point(354, 6);
            this->DotList_button->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
            this->DotList_button->Name = L"DotList_button";
            this->DotList_button->Size = System::Drawing::Size(36, 36);
            this->DotList_button->TabIndex = 9;
            this->DotList_button->TabStop = false;
            this->DotList_button->Text = L"B";
            this->DotList_button->UseVisualStyleBackColor = true;
            this->DotList_button->Click += gcnew System::EventHandler(this, &MainWindow::DotList_button_Click);
            this->DotList_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::richTextBox_KeyDown);
            // 
            // CleanFormat_button
            // 
            this->CleanFormat_button->AutoSize = true;
            this->CleanFormat_button->Dock = System::Windows::Forms::DockStyle::Left;
            this->CleanFormat_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->CleanFormat_button->FlatAppearance->BorderSize = 0;
            this->CleanFormat_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->CleanFormat_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->CleanFormat_button->Location = System::Drawing::Point(396, 6);
            this->CleanFormat_button->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
            this->CleanFormat_button->Name = L"CleanFormat_button";
            this->CleanFormat_button->Size = System::Drawing::Size(36, 36);
            this->CleanFormat_button->TabIndex = 10;
            this->CleanFormat_button->TabStop = false;
            this->CleanFormat_button->Text = L"B";
            this->CleanFormat_button->UseVisualStyleBackColor = true;
            this->CleanFormat_button->Click += gcnew System::EventHandler(this, &MainWindow::CleanFormat_button_Click);
            this->CleanFormat_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::richTextBox_KeyDown);
            // 
            // separatorControl3
            // 
            this->separatorControl3->AutoSizeMode = true;
            this->separatorControl3->BackColor = System::Drawing::SystemColors::ControlDark;
            this->separatorControl3->LineOrientation = System::Windows::Forms::Orientation::Vertical;
            this->separatorControl3->LineThickness = 2;
            this->separatorControl3->Location = System::Drawing::Point(435, 0);
            this->separatorControl3->Margin = System::Windows::Forms::Padding(0);
            this->separatorControl3->Name = L"separatorControl3";
            this->separatorControl3->Padding = System::Windows::Forms::Padding(0);
            this->separatorControl3->Size = System::Drawing::Size(2, 48);
            this->separatorControl3->TabIndex = 22;
            // 
            // LeftAlign_button
            // 
            this->LeftAlign_button->AutoSize = true;
            this->LeftAlign_button->Dock = System::Windows::Forms::DockStyle::Left;
            this->LeftAlign_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->LeftAlign_button->FlatAppearance->BorderSize = 0;
            this->LeftAlign_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->LeftAlign_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->LeftAlign_button->Location = System::Drawing::Point(440, 6);
            this->LeftAlign_button->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
            this->LeftAlign_button->Name = L"LeftAlign_button";
            this->LeftAlign_button->Size = System::Drawing::Size(36, 36);
            this->LeftAlign_button->TabIndex = 12;
            this->LeftAlign_button->TabStop = false;
            this->LeftAlign_button->Text = L"B";
            this->LeftAlign_button->UseVisualStyleBackColor = true;
            this->LeftAlign_button->Click += gcnew System::EventHandler(this, &MainWindow::LeftAlign_button_Click);
            this->LeftAlign_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::richTextBox_KeyDown);
            // 
            // CenterAlign_button
            // 
            this->CenterAlign_button->AutoSize = true;
            this->CenterAlign_button->Dock = System::Windows::Forms::DockStyle::Left;
            this->CenterAlign_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->CenterAlign_button->FlatAppearance->BorderSize = 0;
            this->CenterAlign_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->CenterAlign_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->CenterAlign_button->Location = System::Drawing::Point(482, 6);
            this->CenterAlign_button->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
            this->CenterAlign_button->Name = L"CenterAlign_button";
            this->CenterAlign_button->Size = System::Drawing::Size(36, 36);
            this->CenterAlign_button->TabIndex = 13;
            this->CenterAlign_button->TabStop = false;
            this->CenterAlign_button->Text = L"B";
            this->CenterAlign_button->UseVisualStyleBackColor = true;
            this->CenterAlign_button->Click += gcnew System::EventHandler(this, &MainWindow::CenterAlign_button_Click);
            this->CenterAlign_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::richTextBox_KeyDown);
            // 
            // RightAlign_button
            // 
            this->RightAlign_button->AutoSize = true;
            this->RightAlign_button->Dock = System::Windows::Forms::DockStyle::Left;
            this->RightAlign_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->RightAlign_button->FlatAppearance->BorderSize = 0;
            this->RightAlign_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->RightAlign_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->RightAlign_button->Location = System::Drawing::Point(524, 6);
            this->RightAlign_button->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
            this->RightAlign_button->Name = L"RightAlign_button";
            this->RightAlign_button->Size = System::Drawing::Size(36, 36);
            this->RightAlign_button->TabIndex = 14;
            this->RightAlign_button->TabStop = false;
            this->RightAlign_button->Text = L"B";
            this->RightAlign_button->UseVisualStyleBackColor = true;
            this->RightAlign_button->Click += gcnew System::EventHandler(this, &MainWindow::RightAlign_button_Click);
            this->RightAlign_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::richTextBox_KeyDown);
            // 
            // WideAlign_button
            // 
            this->WideAlign_button->AutoSize = true;
            this->WideAlign_button->Dock = System::Windows::Forms::DockStyle::Left;
            this->WideAlign_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->WideAlign_button->FlatAppearance->BorderSize = 0;
            this->WideAlign_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->WideAlign_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->WideAlign_button->Location = System::Drawing::Point(566, 6);
            this->WideAlign_button->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
            this->WideAlign_button->Name = L"WideAlign_button";
            this->WideAlign_button->Size = System::Drawing::Size(36, 36);
            this->WideAlign_button->TabIndex = 15;
            this->WideAlign_button->TabStop = false;
            this->WideAlign_button->Text = L"B";
            this->WideAlign_button->UseVisualStyleBackColor = true;
            this->WideAlign_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::richTextBox_KeyDown);
            // 
            // separatorControl2
            // 
            this->separatorControl2->AutoSizeMode = true;
            this->separatorControl2->BackColor = System::Drawing::SystemColors::ControlDark;
            this->separatorControl2->LineOrientation = System::Windows::Forms::Orientation::Vertical;
            this->separatorControl2->LineThickness = 2;
            this->separatorControl2->Location = System::Drawing::Point(605, 0);
            this->separatorControl2->Margin = System::Windows::Forms::Padding(0);
            this->separatorControl2->Name = L"separatorControl2";
            this->separatorControl2->Padding = System::Windows::Forms::Padding(0);
            this->separatorControl2->Size = System::Drawing::Size(2, 48);
            this->separatorControl2->TabIndex = 21;
            // 
            // Date_button
            // 
            this->Date_button->AutoSize = true;
            this->Date_button->Dock = System::Windows::Forms::DockStyle::Left;
            this->Date_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->Date_button->FlatAppearance->BorderSize = 0;
            this->Date_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Date_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Date_button->Location = System::Drawing::Point(610, 6);
            this->Date_button->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
            this->Date_button->Name = L"Date_button";
            this->Date_button->Size = System::Drawing::Size(36, 36);
            this->Date_button->TabIndex = 17;
            this->Date_button->TabStop = false;
            this->Date_button->Text = L"B";
            this->Date_button->UseVisualStyleBackColor = true;
            this->Date_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::richTextBox_KeyDown);
            // 
            // DropDownMenu_button
            // 
            this->DropDownMenu_button->AutoSize = true;
            this->DropDownMenu_button->Dock = System::Windows::Forms::DockStyle::Left;
            this->DropDownMenu_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->DropDownMenu_button->FlatAppearance->BorderSize = 0;
            this->DropDownMenu_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->DropDownMenu_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->DropDownMenu_button->Location = System::Drawing::Point(652, 6);
            this->DropDownMenu_button->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
            this->DropDownMenu_button->Name = L"DropDownMenu_button";
            this->DropDownMenu_button->Size = System::Drawing::Size(36, 36);
            this->DropDownMenu_button->TabIndex = 18;
            this->DropDownMenu_button->TabStop = false;
            this->DropDownMenu_button->Text = L"B";
            this->DropDownMenu_button->UseVisualStyleBackColor = true;
            this->DropDownMenu_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::richTextBox_KeyDown);
            // 
            // Table_button
            // 
            this->Table_button->AutoSize = true;
            this->Table_button->Dock = System::Windows::Forms::DockStyle::Left;
            this->Table_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->Table_button->FlatAppearance->BorderSize = 0;
            this->Table_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Table_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Table_button->Location = System::Drawing::Point(694, 6);
            this->Table_button->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
            this->Table_button->Name = L"Table_button";
            this->Table_button->Size = System::Drawing::Size(36, 36);
            this->Table_button->TabIndex = 19;
            this->Table_button->TabStop = false;
            this->Table_button->Text = L"B";
            this->Table_button->UseVisualStyleBackColor = true;
            this->Table_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::richTextBox_KeyDown);
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
            this->F7_button->Location = System::Drawing::Point(573, 288);
            this->F7_button->Name = L"F7_button";
            this->F7_button->Size = System::Drawing::Size(173, 37);
            this->F7_button->TabIndex = 16;
            this->F7_button->Text = L"Продолжить";
            this->F7_button->UseVisualStyleBackColor = true;
            this->F7_button->Click += gcnew System::EventHandler(this, &MainWindow::F7_button_Click);
            // 
            // Recomendations_panel
            // 
            this->Recomendations_panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Recomendations_panel->Controls->Add(this->tableLayoutPanel19);
            this->Recomendations_panel->Controls->Add(this->tableLayoutPanel17);
            this->Recomendations_panel->Controls->Add(this->tableLayoutPanel16);
            this->Recomendations_panel->Location = System::Drawing::Point(0, 192);
            this->Recomendations_panel->Name = L"Recomendations_panel";
            this->Recomendations_panel->Size = System::Drawing::Size(1355, 500);
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
                20)));
            this->tableLayoutPanel19->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel19->Size = System::Drawing::Size(976, 307);
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
            this->F8_button->Location = System::Drawing::Point(401, 23);
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
            this->tableLayoutPanel17->Controls->Add(this->Recommendations_groupBox, 0, 1);
            this->tableLayoutPanel17->Controls->Add(this->label17, 0, 0);
            this->tableLayoutPanel17->Controls->Add(this->EditRec_button, 0, 2);
            this->tableLayoutPanel17->Controls->Add(this->Paste_button, 0, 3);
            this->tableLayoutPanel17->Location = System::Drawing::Point(5, 158);
            this->tableLayoutPanel17->Name = L"tableLayoutPanel17";
            this->tableLayoutPanel17->RowCount = 4;
            this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel17->Size = System::Drawing::Size(307, 215);
            this->tableLayoutPanel17->TabIndex = 4;
            // 
            // Recommendations_groupBox
            // 
            this->Recommendations_groupBox->AutoSize = true;
            this->Recommendations_groupBox->Controls->Add(this->Recommendations_checkedListBox);
            this->Recommendations_groupBox->Location = System::Drawing::Point(3, 23);
            this->Recommendations_groupBox->Name = L"Recommendations_groupBox";
            this->Recommendations_groupBox->Size = System::Drawing::Size(301, 117);
            this->Recommendations_groupBox->TabIndex = 5;
            this->Recommendations_groupBox->TabStop = false;
            this->Recommendations_groupBox->Text = L"Рекомендации";
            // 
            // Recommendations_checkedListBox
            // 
            this->Recommendations_checkedListBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->Recommendations_checkedListBox->CheckOnClick = true;
            this->Recommendations_checkedListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->Recommendations_checkedListBox->FormattingEnabled = true;
            this->Recommendations_checkedListBox->Location = System::Drawing::Point(6, 14);
            this->Recommendations_checkedListBox->Name = L"Recommendations_checkedListBox";
            this->Recommendations_checkedListBox->Size = System::Drawing::Size(289, 84);
            this->Recommendations_checkedListBox->TabIndex = 0;
            this->Recommendations_checkedListBox->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &MainWindow::Recommendations_checkedListBox_ItemCheck);
            // 
            // label17
            // 
            this->label17->AutoSize = true;
            this->label17->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label17->Location = System::Drawing::Point(3, 0);
            this->label17->Name = L"label17";
            this->label17->Size = System::Drawing::Size(301, 20);
            this->label17->TabIndex = 0;
            this->label17->Text = L"Или";
            this->label17->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // EditRec_button
            // 
            this->EditRec_button->AutoSize = true;
            this->EditRec_button->FlatAppearance->BorderSize = 0;
            this->EditRec_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->EditRec_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->EditRec_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->EditRec_button->Location = System::Drawing::Point(3, 146);
            this->EditRec_button->Name = L"EditRec_button";
            this->EditRec_button->Size = System::Drawing::Size(299, 30);
            this->EditRec_button->TabIndex = 6;
            this->EditRec_button->Text = L"Редактировать";
            this->EditRec_button->UseVisualStyleBackColor = true;
            // 
            // Paste_button
            // 
            this->Paste_button->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->Paste_button->FlatAppearance->BorderSize = 0;
            this->Paste_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Paste_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Paste_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->Paste_button->Location = System::Drawing::Point(3, 182);
            this->Paste_button->Name = L"Paste_button";
            this->Paste_button->Size = System::Drawing::Size(299, 30);
            this->Paste_button->TabIndex = 7;
            this->Paste_button->Text = L"Вставить";
            this->Paste_button->UseVisualStyleBackColor = true;
            this->Paste_button->Click += gcnew System::EventHandler(this, &MainWindow::Paste_button_Click);
            // 
            // tableLayoutPanel16
            // 
            this->tableLayoutPanel16->AutoSize = true;
            this->tableLayoutPanel16->ColumnCount = 1;
            this->tableLayoutPanel16->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel16->Controls->Add(this->AsteniaRec_button, 0, 0);
            this->tableLayoutPanel16->Controls->Add(this->PnevmoRec_button, 0, 2);
            this->tableLayoutPanel16->Controls->Add(this->BronhitRec_button, 0, 1);
            this->tableLayoutPanel16->Location = System::Drawing::Point(5, 6);
            this->tableLayoutPanel16->Name = L"tableLayoutPanel16";
            this->tableLayoutPanel16->RowCount = 3;
            this->tableLayoutPanel16->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel16->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel16->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel16->Size = System::Drawing::Size(307, 120);
            this->tableLayoutPanel16->TabIndex = 3;
            // 
            // AsteniaRec_button
            // 
            this->AsteniaRec_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->AsteniaRec_button->Dock = System::Windows::Forms::DockStyle::Fill;
            this->AsteniaRec_button->FlatAppearance->BorderSize = 0;
            this->AsteniaRec_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->AsteniaRec_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->AsteniaRec_button->Location = System::Drawing::Point(3, 3);
            this->AsteniaRec_button->Name = L"AsteniaRec_button";
            this->AsteniaRec_button->Size = System::Drawing::Size(301, 34);
            this->AsteniaRec_button->TabIndex = 0;
            this->AsteniaRec_button->Text = L"Астения";
            this->AsteniaRec_button->UseVisualStyleBackColor = true;
            this->AsteniaRec_button->Click += gcnew System::EventHandler(this, &MainWindow::AsteniaRec_button_Click);
            // 
            // PnevmoRec_button
            // 
            this->PnevmoRec_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->PnevmoRec_button->Dock = System::Windows::Forms::DockStyle::Fill;
            this->PnevmoRec_button->FlatAppearance->BorderSize = 0;
            this->PnevmoRec_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->PnevmoRec_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->PnevmoRec_button->Location = System::Drawing::Point(3, 83);
            this->PnevmoRec_button->Name = L"PnevmoRec_button";
            this->PnevmoRec_button->Size = System::Drawing::Size(301, 34);
            this->PnevmoRec_button->TabIndex = 2;
            this->PnevmoRec_button->Text = L"Пневмония";
            this->PnevmoRec_button->UseVisualStyleBackColor = true;
            this->PnevmoRec_button->Click += gcnew System::EventHandler(this, &MainWindow::PnevmoRec_button_Click);
            // 
            // BronhitRec_button
            // 
            this->BronhitRec_button->Cursor = System::Windows::Forms::Cursors::Hand;
            this->BronhitRec_button->Dock = System::Windows::Forms::DockStyle::Fill;
            this->BronhitRec_button->FlatAppearance->BorderSize = 0;
            this->BronhitRec_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BronhitRec_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->BronhitRec_button->Location = System::Drawing::Point(3, 43);
            this->BronhitRec_button->Name = L"BronhitRec_button";
            this->BronhitRec_button->Size = System::Drawing::Size(301, 34);
            this->BronhitRec_button->TabIndex = 1;
            this->BronhitRec_button->Text = L"Бронхит";
            this->BronhitRec_button->UseVisualStyleBackColor = true;
            this->BronhitRec_button->Click += gcnew System::EventHandler(this, &MainWindow::BronhitRec_button_Click);
            // 
            // AnalysisResults_panel
            // 
            this->AnalysisResults_panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->AnalysisResults_panel->AutoSize = true;
            this->AnalysisResults_panel->Controls->Add(this->tableLayoutPanel9);
            this->AnalysisResults_panel->Location = System::Drawing::Point(2, 159);
            this->AnalysisResults_panel->Name = L"AnalysisResults_panel";
            this->AnalysisResults_panel->Size = System::Drawing::Size(1327, 354);
            this->AnalysisResults_panel->TabIndex = 8;
            this->AnalysisResults_panel->Visible = false;
            // 
            // tableLayoutPanel9
            // 
            this->tableLayoutPanel9->AutoSize = true;
            this->tableLayoutPanel9->ColumnCount = 1;
            this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel9->Controls->Add(this->AnalysisResults_groupBox, 0, 0);
            this->tableLayoutPanel9->Controls->Add(this->F5_button, 0, 2);
            this->tableLayoutPanel9->Controls->Add(this->button2, 0, 3);
            this->tableLayoutPanel9->Dock = System::Windows::Forms::DockStyle::Top;
            this->tableLayoutPanel9->Location = System::Drawing::Point(0, 0);
            this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
            this->tableLayoutPanel9->RowCount = 4;
            this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tableLayoutPanel9->Size = System::Drawing::Size(1327, 120);
            this->tableLayoutPanel9->TabIndex = 11;
            // 
            // AnalysisResults_groupBox
            // 
            this->AnalysisResults_groupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->AnalysisResults_groupBox->AutoSize = true;
            this->AnalysisResults_groupBox->Controls->Add(this->AnalyzesResults_comboBox);
            this->AnalysisResults_groupBox->Location = System::Drawing::Point(3, 3);
            this->AnalysisResults_groupBox->MinimumSize = System::Drawing::Size(0, 51);
            this->AnalysisResults_groupBox->Name = L"AnalysisResults_groupBox";
            this->AnalysisResults_groupBox->Size = System::Drawing::Size(1321, 51);
            this->AnalysisResults_groupBox->TabIndex = 1;
            this->AnalysisResults_groupBox->TabStop = false;
            // 
            // AnalyzesResults_comboBox
            // 
            this->AnalyzesResults_comboBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->AnalyzesResults_comboBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->AnalyzesResults_comboBox->Cursor = System::Windows::Forms::Cursors::Hand;
            this->AnalyzesResults_comboBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->AnalyzesResults_comboBox->DropDownHeight = 400;
            this->AnalyzesResults_comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->AnalyzesResults_comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->AnalyzesResults_comboBox->FormattingEnabled = true;
            this->AnalyzesResults_comboBox->IntegralHeight = false;
            this->AnalyzesResults_comboBox->ItemHeight = 20;
            this->AnalyzesResults_comboBox->Location = System::Drawing::Point(3, 16);
            this->AnalyzesResults_comboBox->Name = L"AnalyzesResults_comboBox";
            this->AnalyzesResults_comboBox->Size = System::Drawing::Size(1315, 28);
            this->AnalyzesResults_comboBox->TabIndex = 0;
            this->AnalyzesResults_comboBox->Click += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->AnalyzesResults_comboBox->Enter += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->AnalyzesResults_comboBox->Leave += gcnew System::EventHandler(this, &MainWindow::AnalyzesResults_comboBox_Leave);
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
            this->F5_button->Location = System::Drawing::Point(577, 60);
            this->F5_button->Name = L"F5_button";
            this->F5_button->Size = System::Drawing::Size(173, 37);
            this->F5_button->TabIndex = 1;
            this->F5_button->Text = L"Продолжить";
            this->F5_button->UseVisualStyleBackColor = true;
            this->F5_button->Click += gcnew System::EventHandler(this, &MainWindow::AddingInfo_button_Click);
            // 
            // button2
            // 
            this->button2->FlatAppearance->BorderSize = 0;
            this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button2->Location = System::Drawing::Point(3, 103);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(75, 14);
            this->button2->TabIndex = 2;
            this->button2->UseVisualStyleBackColor = true;
            // 
            // Anamnesis_panel
            // 
            this->Anamnesis_panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->Anamnesis_panel->AutoSize = true;
            this->Anamnesis_panel->Controls->Add(this->tableLayoutPanel14);
            this->Anamnesis_panel->Location = System::Drawing::Point(2, 159);
            this->Anamnesis_panel->Name = L"Anamnesis_panel";
            this->Anamnesis_panel->Size = System::Drawing::Size(1327, 488);
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
            this->tableLayoutPanel14->Size = System::Drawing::Size(1327, 488);
            this->tableLayoutPanel14->TabIndex = 0;
            // 
            // panel3
            // 
            this->panel3->AutoScroll = true;
            this->panel3->Controls->Add(this->tableLayoutPanel11);
            this->panel3->Location = System::Drawing::Point(3, 3);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(615, 488);
            this->panel3->TabIndex = 0;
            // 
            // tableLayoutPanel11
            // 
            this->tableLayoutPanel11->AutoSize = true;
            this->tableLayoutPanel11->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->tableLayoutPanel11->ColumnCount = 1;
            this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
            this->tableLayoutPanel11->Controls->Add(this->label11, 0, 0);
            this->tableLayoutPanel11->Controls->Add(this->flowLayoutPanel2, 0, 1);
            this->tableLayoutPanel11->Controls->Add(this->groupBox17, 0, 2);
            this->tableLayoutPanel11->Controls->Add(this->label12, 0, 3);
            this->tableLayoutPanel11->Controls->Add(this->flowLayoutPanel3, 0, 4);
            this->tableLayoutPanel11->Controls->Add(this->groupBox18, 0, 5);
            this->tableLayoutPanel11->Controls->Add(this->label13, 0, 6);
            this->tableLayoutPanel11->Controls->Add(this->NapravlenV_tableLayoutPanel, 0, 7);
            this->tableLayoutPanel11->Controls->Add(this->label14, 0, 8);
            this->tableLayoutPanel11->Controls->Add(this->groupBox19, 0, 9);
            this->tableLayoutPanel11->Controls->Add(this->label15, 0, 10);
            this->tableLayoutPanel11->Controls->Add(this->FOGK_checkBox, 0, 11);
            this->tableLayoutPanel11->Controls->Add(this->RgOGK_checkBox, 0, 12);
            this->tableLayoutPanel11->Controls->Add(this->KT_OGK_checkBox, 0, 13);
            this->tableLayoutPanel11->Controls->Add(this->OAK_checkBox, 0, 14);
            this->tableLayoutPanel11->Controls->Add(this->OAM_checkBox, 0, 15);
            this->tableLayoutPanel11->Controls->Add(this->BioChemicalBloodResearch_checkBox, 0, 16);
            this->tableLayoutPanel11->Dock = System::Windows::Forms::DockStyle::Top;
            this->tableLayoutPanel11->Location = System::Drawing::Point(0, 0);
            this->tableLayoutPanel11->Name = L"tableLayoutPanel11";
            this->tableLayoutPanel11->RowCount = 17;
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
            this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tableLayoutPanel11->Size = System::Drawing::Size(598, 799);
            this->tableLayoutPanel11->TabIndex = 0;
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
            this->Astenia_radioButton->TabStop = true;
            this->Astenia_radioButton->Text = L"Астения";
            this->Astenia_radioButton->UseVisualStyleBackColor = true;
            this->Astenia_radioButton->Click += gcnew System::EventHandler(this, &MainWindow::Astenia_radioButton_Click);
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
            this->groupBox17->TabIndex = 2;
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
            this->IllBegining_dateTimePicker->TabIndex = 0;
            this->IllBegining_dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &MainWindow::IllBegining_dateTimePicker_ValueChanged);
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
            this->label12->TabIndex = 3;
            this->label12->Text = L"Обратился в*";
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
            this->flowLayoutPanel3->TabIndex = 4;
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
            this->ResponseGospital_radioButton->TabStop = true;
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
            this->ResponsePolyclinic_radioButton->TabStop = true;
            this->ResponsePolyclinic_radioButton->Text = L"Поликлинику";
            this->ResponsePolyclinic_radioButton->UseVisualStyleBackColor = true;
            this->ResponsePolyclinic_radioButton->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::ResponsePolyclinic_radioButton_CheckedChanged);
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
            this->groupBox18->TabIndex = 5;
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
            this->ResponseDate_dateTimePicker->TabIndex = 0;
            this->ResponseDate_dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &MainWindow::ResponseDate_dateTimePicker_ValueChanged);
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
            this->label13->TabIndex = 6;
            this->label13->Text = L"Направлен в*";
            // 
            // NapravlenV_tableLayoutPanel
            // 
            this->NapravlenV_tableLayoutPanel->AutoSize = true;
            this->NapravlenV_tableLayoutPanel->ColumnCount = 1;
            this->NapravlenV_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->NapravlenV_tableLayoutPanel->Controls->Add(this->flowLayoutPanel5, 0, 0);
            this->NapravlenV_tableLayoutPanel->Controls->Add(this->NapravlenieVGospital_tableLayoutPanel, 0, 1);
            this->NapravlenV_tableLayoutPanel->Controls->Add(this->NapravlenVLazaret_panel, 0, 2);
            this->NapravlenV_tableLayoutPanel->Location = System::Drawing::Point(3, 244);
            this->NapravlenV_tableLayoutPanel->Name = L"NapravlenV_tableLayoutPanel";
            this->NapravlenV_tableLayoutPanel->RowCount = 4;
            this->NapravlenV_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->NapravlenV_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->NapravlenV_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->NapravlenV_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->NapravlenV_tableLayoutPanel->Size = System::Drawing::Size(610, 305);
            this->NapravlenV_tableLayoutPanel->TabIndex = 7;
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
            this->SentToLazaret_radioButton->TabStop = true;
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
            this->SentToPolyclinic_radioButton->TabStop = true;
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
            this->NapravlenieVGospital_tableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->NapravlenieVGospital_tableLayoutPanel->Location = System::Drawing::Point(3, 34);
            this->NapravlenieVGospital_tableLayoutPanel->Name = L"NapravlenieVGospital_tableLayoutPanel";
            this->NapravlenieVGospital_tableLayoutPanel->RowCount = 2;
            this->NapravlenieVGospital_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->NapravlenieVGospital_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->NapravlenieVGospital_tableLayoutPanel->Size = System::Drawing::Size(604, 110);
            this->NapravlenieVGospital_tableLayoutPanel->TabIndex = 1;
            this->NapravlenieVGospital_tableLayoutPanel->Visible = false;
            // 
            // NapravlenVpolyclonic_panel
            // 
            this->NapravlenVpolyclonic_panel->AutoSize = true;
            this->NapravlenVpolyclonic_panel->Controls->Add(this->label10);
            this->NapravlenVpolyclonic_panel->Controls->Add(this->Gospitalization_radioButton);
            this->NapravlenVpolyclonic_panel->Controls->Add(this->AmbulanceHealing_radioButton);
            this->NapravlenVpolyclonic_panel->Controls->Add(this->RepeatCheck_groupBox);
            this->NapravlenVpolyclonic_panel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->NapravlenVpolyclonic_panel->Location = System::Drawing::Point(3, 3);
            this->NapravlenVpolyclonic_panel->Name = L"NapravlenVpolyclonic_panel";
            this->NapravlenVpolyclonic_panel->Size = System::Drawing::Size(598, 104);
            this->NapravlenVpolyclonic_panel->TabIndex = 0;
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
            this->AmbulanceHealing_radioButton->TabStop = true;
            this->AmbulanceHealing_radioButton->Text = L"Амбулаторное лечение";
            this->AmbulanceHealing_radioButton->UseVisualStyleBackColor = true;
            this->AmbulanceHealing_radioButton->Click += gcnew System::EventHandler(this, &MainWindow::AmbulanceHealing_radioButton_Click);
            // 
            // RepeatCheck_groupBox
            // 
            this->RepeatCheck_groupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->RepeatCheck_groupBox->Controls->Add(this->RepeatCheck_dateTimePicker);
            this->RepeatCheck_groupBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->RepeatCheck_groupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->RepeatCheck_groupBox->Location = System::Drawing::Point(9, 55);
            this->RepeatCheck_groupBox->Name = L"RepeatCheck_groupBox";
            this->RepeatCheck_groupBox->Size = System::Drawing::Size(574, 46);
            this->RepeatCheck_groupBox->TabIndex = 3;
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
            this->RepeatCheck_dateTimePicker->TabIndex = 0;
            this->RepeatCheck_dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &MainWindow::RepeatCheck_dateTimePicker_ValueChanged);
            // 
            // NapravlenVLazaret_panel
            // 
            this->NapravlenVLazaret_panel->AutoSize = true;
            this->NapravlenVLazaret_panel->Controls->Add(this->tableLayoutPanel21);
            this->NapravlenVLazaret_panel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->NapravlenVLazaret_panel->Location = System::Drawing::Point(3, 150);
            this->NapravlenVLazaret_panel->Name = L"NapravlenVLazaret_panel";
            this->NapravlenVLazaret_panel->Size = System::Drawing::Size(604, 152);
            this->NapravlenVLazaret_panel->TabIndex = 2;
            this->NapravlenVLazaret_panel->Visible = false;
            // 
            // tableLayoutPanel21
            // 
            this->tableLayoutPanel21->AutoSize = true;
            this->tableLayoutPanel21->ColumnCount = 1;
            this->tableLayoutPanel21->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel21->Controls->Add(this->label16, 0, 0);
            this->tableLayoutPanel21->Controls->Add(this->flowLayoutPanel6, 0, 1);
            this->tableLayoutPanel21->Controls->Add(this->IsLazaretaVPolyclinic_groupBox, 0, 2);
            this->tableLayoutPanel21->Controls->Add(this->IsLazaretaVGospital_groupBox, 0, 3);
            this->tableLayoutPanel21->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel21->Location = System::Drawing::Point(0, 0);
            this->tableLayoutPanel21->Name = L"tableLayoutPanel21";
            this->tableLayoutPanel21->RowCount = 4;
            this->tableLayoutPanel21->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel21->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel21->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel21->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel21->Size = System::Drawing::Size(604, 152);
            this->tableLayoutPanel21->TabIndex = 0;
            // 
            // label16
            // 
            this->label16->AutoSize = true;
            this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label16->Location = System::Drawing::Point(3, 0);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(97, 16);
            this->label16->TabIndex = 0;
            this->label16->Text = L"Направлен в*";
            // 
            // flowLayoutPanel6
            // 
            this->flowLayoutPanel6->AutoSize = true;
            this->flowLayoutPanel6->Controls->Add(this->IsLazaretaVGospital_radioButton);
            this->flowLayoutPanel6->Controls->Add(this->IsLazaretaVPolyclinic_radioButton);
            this->flowLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel6->Location = System::Drawing::Point(3, 19);
            this->flowLayoutPanel6->Name = L"flowLayoutPanel6";
            this->flowLayoutPanel6->Size = System::Drawing::Size(598, 26);
            this->flowLayoutPanel6->TabIndex = 1;
            // 
            // IsLazaretaVGospital_radioButton
            // 
            this->IsLazaretaVGospital_radioButton->AutoSize = true;
            this->IsLazaretaVGospital_radioButton->Checked = true;
            this->IsLazaretaVGospital_radioButton->Cursor = System::Windows::Forms::Cursors::Hand;
            this->IsLazaretaVGospital_radioButton->FlatAppearance->BorderSize = 0;
            this->IsLazaretaVGospital_radioButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->IsLazaretaVGospital_radioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->IsLazaretaVGospital_radioButton->Location = System::Drawing::Point(3, 3);
            this->IsLazaretaVGospital_radioButton->Name = L"IsLazaretaVGospital_radioButton";
            this->IsLazaretaVGospital_radioButton->Size = System::Drawing::Size(92, 20);
            this->IsLazaretaVGospital_radioButton->TabIndex = 0;
            this->IsLazaretaVGospital_radioButton->TabStop = true;
            this->IsLazaretaVGospital_radioButton->Text = L"Госпиталь";
            this->IsLazaretaVGospital_radioButton->UseVisualStyleBackColor = true;
            this->IsLazaretaVGospital_radioButton->Click += gcnew System::EventHandler(this, &MainWindow::IsLazaretaV_radioButton_Click);
            // 
            // IsLazaretaVPolyclinic_radioButton
            // 
            this->IsLazaretaVPolyclinic_radioButton->AutoSize = true;
            this->IsLazaretaVPolyclinic_radioButton->Cursor = System::Windows::Forms::Cursors::Hand;
            this->IsLazaretaVPolyclinic_radioButton->FlatAppearance->BorderSize = 0;
            this->IsLazaretaVPolyclinic_radioButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->IsLazaretaVPolyclinic_radioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->IsLazaretaVPolyclinic_radioButton->Location = System::Drawing::Point(101, 3);
            this->IsLazaretaVPolyclinic_radioButton->Name = L"IsLazaretaVPolyclinic_radioButton";
            this->IsLazaretaVPolyclinic_radioButton->Size = System::Drawing::Size(112, 20);
            this->IsLazaretaVPolyclinic_radioButton->TabIndex = 1;
            this->IsLazaretaVPolyclinic_radioButton->TabStop = true;
            this->IsLazaretaVPolyclinic_radioButton->Text = L"Поликлинику";
            this->IsLazaretaVPolyclinic_radioButton->UseVisualStyleBackColor = true;
            this->IsLazaretaVPolyclinic_radioButton->Click += gcnew System::EventHandler(this, &MainWindow::IsLazaretaV_radioButton_Click);
            // 
            // IsLazaretaVPolyclinic_groupBox
            // 
            this->IsLazaretaVPolyclinic_groupBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->IsLazaretaVPolyclinic_groupBox->Controls->Add(this->IsLazaretaVPolyclinic_dateTimePicker);
            this->IsLazaretaVPolyclinic_groupBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->IsLazaretaVPolyclinic_groupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->IsLazaretaVPolyclinic_groupBox->Location = System::Drawing::Point(15, 51);
            this->IsLazaretaVPolyclinic_groupBox->Name = L"IsLazaretaVPolyclinic_groupBox";
            this->IsLazaretaVPolyclinic_groupBox->Size = System::Drawing::Size(574, 46);
            this->IsLazaretaVPolyclinic_groupBox->TabIndex = 2;
            this->IsLazaretaVPolyclinic_groupBox->TabStop = false;
            this->IsLazaretaVPolyclinic_groupBox->Text = L"Дата направления в поликлинику*";
            this->IsLazaretaVPolyclinic_groupBox->Visible = false;
            // 
            // IsLazaretaVPolyclinic_dateTimePicker
            // 
            this->IsLazaretaVPolyclinic_dateTimePicker->Dock = System::Windows::Forms::DockStyle::Fill;
            this->IsLazaretaVPolyclinic_dateTimePicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->IsLazaretaVPolyclinic_dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->IsLazaretaVPolyclinic_dateTimePicker->Location = System::Drawing::Point(3, 18);
            this->IsLazaretaVPolyclinic_dateTimePicker->Name = L"IsLazaretaVPolyclinic_dateTimePicker";
            this->IsLazaretaVPolyclinic_dateTimePicker->Size = System::Drawing::Size(568, 22);
            this->IsLazaretaVPolyclinic_dateTimePicker->TabIndex = 0;
            this->IsLazaretaVPolyclinic_dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &MainWindow::IsLazaretaVPolyclinic_dateTimePicker_ValueChanged);
            // 
            // IsLazaretaVGospital_groupBox
            // 
            this->IsLazaretaVGospital_groupBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->IsLazaretaVGospital_groupBox->Controls->Add(this->IsLazaretaVGospital_dateTimePicker);
            this->IsLazaretaVGospital_groupBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->IsLazaretaVGospital_groupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->IsLazaretaVGospital_groupBox->Location = System::Drawing::Point(15, 103);
            this->IsLazaretaVGospital_groupBox->Name = L"IsLazaretaVGospital_groupBox";
            this->IsLazaretaVGospital_groupBox->Size = System::Drawing::Size(574, 46);
            this->IsLazaretaVGospital_groupBox->TabIndex = 3;
            this->IsLazaretaVGospital_groupBox->TabStop = false;
            this->IsLazaretaVGospital_groupBox->Text = L"Дата направления в госпиталь*";
            // 
            // IsLazaretaVGospital_dateTimePicker
            // 
            this->IsLazaretaVGospital_dateTimePicker->Dock = System::Windows::Forms::DockStyle::Fill;
            this->IsLazaretaVGospital_dateTimePicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->IsLazaretaVGospital_dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->IsLazaretaVGospital_dateTimePicker->Location = System::Drawing::Point(3, 18);
            this->IsLazaretaVGospital_dateTimePicker->Name = L"IsLazaretaVGospital_dateTimePicker";
            this->IsLazaretaVGospital_dateTimePicker->Size = System::Drawing::Size(568, 22);
            this->IsLazaretaVGospital_dateTimePicker->TabIndex = 0;
            this->IsLazaretaVGospital_dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &MainWindow::IsLazaretaVGospital_dateTimePicker_ValueChanged);
            // 
            // label14
            // 
            this->label14->AutoSize = true;
            this->label14->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->label14->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label14->Location = System::Drawing::Point(3, 552);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(610, 24);
            this->label14->TabIndex = 8;
            this->label14->Text = L"Обследования";
            // 
            // groupBox19
            // 
            this->groupBox19->Controls->Add(this->ResearchDate_dateTimePicker);
            this->groupBox19->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox19->Location = System::Drawing::Point(3, 579);
            this->groupBox19->Name = L"groupBox19";
            this->groupBox19->Size = System::Drawing::Size(589, 45);
            this->groupBox19->TabIndex = 9;
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
            this->ResearchDate_dateTimePicker->TabIndex = 16;
            this->ResearchDate_dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &MainWindow::ResearchDate_dateTimePicker_ValueChanged);
            // 
            // label15
            // 
            this->label15->AutoSize = true;
            this->label15->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label15->Location = System::Drawing::Point(3, 627);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(610, 16);
            this->label15->TabIndex = 10;
            this->label15->Text = L"Обследования*";
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
            this->FOGK_checkBox->Location = System::Drawing::Point(3, 646);
            this->FOGK_checkBox->Name = L"FOGK_checkBox";
            this->FOGK_checkBox->Size = System::Drawing::Size(610, 20);
            this->FOGK_checkBox->TabIndex = 11;
            this->FOGK_checkBox->Text = L"ФОГК";
            this->FOGK_checkBox->UseVisualStyleBackColor = true;
            this->FOGK_checkBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::checkBox_CheckedChanged);
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
            this->RgOGK_checkBox->Location = System::Drawing::Point(3, 672);
            this->RgOGK_checkBox->Name = L"RgOGK_checkBox";
            this->RgOGK_checkBox->Size = System::Drawing::Size(610, 20);
            this->RgOGK_checkBox->TabIndex = 12;
            this->RgOGK_checkBox->Text = L"Rg ОГК";
            this->RgOGK_checkBox->UseVisualStyleBackColor = true;
            this->RgOGK_checkBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::checkBox_CheckedChanged);
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
            this->KT_OGK_checkBox->Location = System::Drawing::Point(3, 698);
            this->KT_OGK_checkBox->Name = L"KT_OGK_checkBox";
            this->KT_OGK_checkBox->Size = System::Drawing::Size(610, 20);
            this->KT_OGK_checkBox->TabIndex = 13;
            this->KT_OGK_checkBox->Text = L"КТ ОГК";
            this->KT_OGK_checkBox->UseVisualStyleBackColor = true;
            this->KT_OGK_checkBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::checkBox_CheckedChanged);
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
            this->OAK_checkBox->Location = System::Drawing::Point(3, 724);
            this->OAK_checkBox->Name = L"OAK_checkBox";
            this->OAK_checkBox->Size = System::Drawing::Size(610, 20);
            this->OAK_checkBox->TabIndex = 14;
            this->OAK_checkBox->Text = L"ОАК";
            this->OAK_checkBox->UseVisualStyleBackColor = true;
            this->OAK_checkBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::checkBox_CheckedChanged);
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
            this->OAM_checkBox->Location = System::Drawing::Point(3, 750);
            this->OAM_checkBox->Name = L"OAM_checkBox";
            this->OAM_checkBox->Size = System::Drawing::Size(610, 20);
            this->OAM_checkBox->TabIndex = 15;
            this->OAM_checkBox->Text = L"ОАМ";
            this->OAM_checkBox->UseVisualStyleBackColor = true;
            this->OAM_checkBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::checkBox_CheckedChanged);
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
            this->BioChemicalBloodResearch_checkBox->Location = System::Drawing::Point(3, 776);
            this->BioChemicalBloodResearch_checkBox->Name = L"BioChemicalBloodResearch_checkBox";
            this->BioChemicalBloodResearch_checkBox->Size = System::Drawing::Size(610, 20);
            this->BioChemicalBloodResearch_checkBox->TabIndex = 16;
            this->BioChemicalBloodResearch_checkBox->Text = L"Биохимическое исследование крови";
            this->BioChemicalBloodResearch_checkBox->UseVisualStyleBackColor = true;
            this->BioChemicalBloodResearch_checkBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::checkBox_CheckedChanged);
            // 
            // panel2
            // 
            this->panel2->AutoSize = true;
            this->panel2->Controls->Add(this->groupBox20);
            this->panel2->Controls->Add(this->F4_button);
            this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panel2->Location = System::Drawing::Point(624, 3);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(700, 488);
            this->panel2->TabIndex = 1;
            // 
            // groupBox20
            // 
            this->groupBox20->Controls->Add(this->Anamnesis_textBox);
            this->groupBox20->Dock = System::Windows::Forms::DockStyle::Top;
            this->groupBox20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox20->Location = System::Drawing::Point(0, 0);
            this->groupBox20->Name = L"groupBox20";
            this->groupBox20->Size = System::Drawing::Size(700, 139);
            this->groupBox20->TabIndex = 0;
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
            this->Anamnesis_textBox->Size = System::Drawing::Size(694, 114);
            this->Anamnesis_textBox->TabIndex = 0;
            this->Anamnesis_textBox->Text = L"\r\n";
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
            this->F4_button->TabIndex = 1;
            this->F4_button->Text = L"Продолжить";
            this->F4_button->UseVisualStyleBackColor = true;
            this->F4_button->Click += gcnew System::EventHandler(this, &MainWindow::F3_button_Click);
            // 
            // Stamp_panel
            // 
            this->Stamp_panel->Location = System::Drawing::Point(0, 156);
            this->Stamp_panel->Name = L"Stamp_panel";
            this->Stamp_panel->Size = System::Drawing::Size(1313, 503);
            this->Stamp_panel->TabIndex = 0;
            // 
            // Ill_History_panel
            // 
            this->Ill_History_panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
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
            this->Ill_History_panel->Size = System::Drawing::Size(1387, 500);
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
            this->groupBox15->Controls->Add(this->complications_comboBox);
            this->groupBox15->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox15->Location = System::Drawing::Point(14, 307);
            this->groupBox15->Name = L"groupBox15";
            this->groupBox15->Size = System::Drawing::Size(1307, 44);
            this->groupBox15->TabIndex = 10;
            this->groupBox15->TabStop = false;
            this->groupBox15->Text = L"Осложнение 1*";
            // 
            // complications_comboBox
            // 
            this->complications_comboBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->complications_comboBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->complications_comboBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->complications_comboBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->complications_comboBox->DropDownHeight = 150;
            this->complications_comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->complications_comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->complications_comboBox->FormattingEnabled = true;
            this->complications_comboBox->IntegralHeight = false;
            this->complications_comboBox->Location = System::Drawing::Point(3, 18);
            this->complications_comboBox->MaxDropDownItems = 10;
            this->complications_comboBox->Name = L"complications_comboBox";
            this->complications_comboBox->Size = System::Drawing::Size(1301, 24);
            this->complications_comboBox->TabIndex = 13;
            this->complications_comboBox->Click += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->complications_comboBox->Enter += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->complications_comboBox->Leave += gcnew System::EventHandler(this, &MainWindow::complications_comboBox_Leave);
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label9->Location = System::Drawing::Point(9, 270);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(124, 24);
            this->label9->TabIndex = 9;
            this->label9->Text = L"Осложнения";
            // 
            // groupBox16
            // 
            this->groupBox16->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox16->Controls->Add(this->related_comboBox);
            this->groupBox16->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox16->Location = System::Drawing::Point(13, 201);
            this->groupBox16->Name = L"groupBox16";
            this->groupBox16->Size = System::Drawing::Size(1307, 44);
            this->groupBox16->TabIndex = 8;
            this->groupBox16->TabStop = false;
            this->groupBox16->Text = L"Сопутствующий 1*";
            // 
            // related_comboBox
            // 
            this->related_comboBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->related_comboBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->related_comboBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->related_comboBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->related_comboBox->DropDownHeight = 150;
            this->related_comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->related_comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->related_comboBox->FormattingEnabled = true;
            this->related_comboBox->IntegralHeight = false;
            this->related_comboBox->Location = System::Drawing::Point(3, 18);
            this->related_comboBox->MaxDropDownItems = 10;
            this->related_comboBox->Name = L"related_comboBox";
            this->related_comboBox->Size = System::Drawing::Size(1301, 24);
            this->related_comboBox->TabIndex = 12;
            this->related_comboBox->Click += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->related_comboBox->Enter += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->related_comboBox->Leave += gcnew System::EventHandler(this, &MainWindow::related_comboBox_Leave);
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
            this->MKB_groupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->MKB_groupBox->Controls->Add(this->mkb_comboBox);
            this->MKB_groupBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->MKB_groupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->MKB_groupBox->Location = System::Drawing::Point(1248, 101);
            this->MKB_groupBox->Name = L"MKB_groupBox";
            this->MKB_groupBox->Size = System::Drawing::Size(72, 44);
            this->MKB_groupBox->TabIndex = 6;
            this->MKB_groupBox->TabStop = false;
            this->MKB_groupBox->Text = L"МКБ*";
            // 
            // mkb_comboBox
            // 
            this->mkb_comboBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->mkb_comboBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->mkb_comboBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->mkb_comboBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->mkb_comboBox->DropDownHeight = 150;
            this->mkb_comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->mkb_comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->mkb_comboBox->FormattingEnabled = true;
            this->mkb_comboBox->IntegralHeight = false;
            this->mkb_comboBox->Location = System::Drawing::Point(3, 18);
            this->mkb_comboBox->MaxDropDownItems = 10;
            this->mkb_comboBox->Name = L"mkb_comboBox";
            this->mkb_comboBox->Size = System::Drawing::Size(66, 24);
            this->mkb_comboBox->TabIndex = 13;
            this->mkb_comboBox->Click += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->mkb_comboBox->Enter += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->mkb_comboBox->Leave += gcnew System::EventHandler(this, &MainWindow::mkb_comboBox_Leave);
            // 
            // groupBox14
            // 
            this->groupBox14->Controls->Add(this->epicrizdiagnoses_comboBox);
            this->groupBox14->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->groupBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->groupBox14->Location = System::Drawing::Point(13, 101);
            this->groupBox14->Name = L"groupBox14";
            this->groupBox14->Size = System::Drawing::Size(1229, 44);
            this->groupBox14->TabIndex = 5;
            this->groupBox14->TabStop = false;
            this->groupBox14->Text = L"Диагноз 1*";
            // 
            // epicrizdiagnoses_comboBox
            // 
            this->epicrizdiagnoses_comboBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->epicrizdiagnoses_comboBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->epicrizdiagnoses_comboBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->epicrizdiagnoses_comboBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->epicrizdiagnoses_comboBox->DropDownHeight = 150;
            this->epicrizdiagnoses_comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->epicrizdiagnoses_comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->epicrizdiagnoses_comboBox->FormattingEnabled = true;
            this->epicrizdiagnoses_comboBox->IntegralHeight = false;
            this->epicrizdiagnoses_comboBox->Location = System::Drawing::Point(3, 18);
            this->epicrizdiagnoses_comboBox->MaxDropDownItems = 10;
            this->epicrizdiagnoses_comboBox->Name = L"epicrizdiagnoses_comboBox";
            this->epicrizdiagnoses_comboBox->Size = System::Drawing::Size(1223, 24);
            this->epicrizdiagnoses_comboBox->TabIndex = 11;
            this->epicrizdiagnoses_comboBox->Click += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->epicrizdiagnoses_comboBox->Enter += gcnew System::EventHandler(this, &MainWindow::TabIndexedComboBox_LeaveEnterClick);
            this->epicrizdiagnoses_comboBox->Leave += gcnew System::EventHandler(this, &MainWindow::epicrizdiagnoses_comboBox_Leave);
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
            this->groupBox13->Controls->Add(this->outcome_dateTimePicker);
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
            // outcome_dateTimePicker
            // 
            this->outcome_dateTimePicker->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->outcome_dateTimePicker->Dock = System::Windows::Forms::DockStyle::Fill;
            this->outcome_dateTimePicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->outcome_dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->outcome_dateTimePicker->Location = System::Drawing::Point(3, 18);
            this->outcome_dateTimePicker->Name = L"outcome_dateTimePicker";
            this->outcome_dateTimePicker->Size = System::Drawing::Size(209, 22);
            this->outcome_dateTimePicker->TabIndex = 10;
            this->outcome_dateTimePicker->Value = System::DateTime(2024, 8, 14, 18, 5, 34, 0);
            this->outcome_dateTimePicker->Leave += gcnew System::EventHandler(this, &MainWindow::outcome_dateTimePicker_Leave);
            // 
            // groupBox12
            // 
            this->groupBox12->Controls->Add(this->income_dateTimePicker);
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
            // income_dateTimePicker
            // 
            this->income_dateTimePicker->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->income_dateTimePicker->Dock = System::Windows::Forms::DockStyle::Fill;
            this->income_dateTimePicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->income_dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->income_dateTimePicker->Location = System::Drawing::Point(3, 18);
            this->income_dateTimePicker->Name = L"income_dateTimePicker";
            this->income_dateTimePicker->Size = System::Drawing::Size(209, 22);
            this->income_dateTimePicker->TabIndex = 9;
            this->income_dateTimePicker->Value = System::DateTime(2024, 8, 14, 18, 5, 14, 0);
            this->income_dateTimePicker->Leave += gcnew System::EventHandler(this, &MainWindow::income_dateTimePicker_Leave);
            // 
            // AddingInfo_panel
            // 
            this->AddingInfo_panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->AddingInfo_panel->AutoSize = true;
            this->AddingInfo_panel->Controls->Add(this->tableLayoutPanel15);
            this->AddingInfo_panel->Controls->Add(this->tableLayoutPanel13);
            this->AddingInfo_panel->Location = System::Drawing::Point(2, 194);
            this->AddingInfo_panel->Name = L"AddingInfo_panel";
            this->AddingInfo_panel->Size = System::Drawing::Size(1353, 331);
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
            this->tableLayoutPanel15->Size = System::Drawing::Size(684, 331);
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
            this->groupBox->Location = System::Drawing::Point(25, 3);
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
            this->groupBox23->Location = System::Drawing::Point(25, 81);
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
            // UnworkableList_panel
            // 
            this->UnworkableList_panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->UnworkableList_panel->Controls->Add(this->tableLayoutPanel18);
            this->UnworkableList_panel->Controls->Add(this->radioButton1);
            this->UnworkableList_panel->Controls->Add(this->radioButton3);
            this->UnworkableList_panel->Controls->Add(this->radioButton2);
            this->UnworkableList_panel->Location = System::Drawing::Point(0, 194);
            this->UnworkableList_panel->Name = L"UnworkableList_panel";
            this->UnworkableList_panel->Size = System::Drawing::Size(1355, 498);
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
            this->tableLayoutPanel18->Size = System::Drawing::Size(1381, 115);
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
            this->F9_button->Location = System::Drawing::Point(604, 3);
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
            // PathChanger_openFileDialog
            // 
            this->PathChanger_openFileDialog->FileName = L"openFileDialog";
            this->PathChanger_openFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MainWindow::PathChanger_openFileDialog_FileOk);
            // 
            // MainWindow
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->AutoScroll = true;
            this->AutoSize = true;
            this->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->ClientSize = System::Drawing::Size(1329, 742);
            this->Controls->Add(this->Epicrisis_panel);
            this->Controls->Add(this->Home_panel);
            this->HelpButton = true;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->KeyPreview = true;
            this->Name = L"MainWindow";
            this->Text = L"MainWindow";
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
            this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::MainWindow_KeyDown);
            this->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &MainWindow::MainWindow_PreviewKeyDown);
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
            this->DB_groupBox->ResumeLayout(false);
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
            this->Hat_tableLayoutPanel->ResumeLayout(false);
            this->groupBox11->ResumeLayout(false);
            this->groupBox10->ResumeLayout(false);
            this->groupBox9->ResumeLayout(false);
            this->groupBox8->ResumeLayout(false);
            this->groupBox7->ResumeLayout(false);
            this->groupBox6->ResumeLayout(false);
            this->UpperHat_tableLayoutPanel->ResumeLayout(false);
            this->UpperHat_tableLayoutPanel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->id_numericUpDown))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->year_numericUpDown))->EndInit();
            this->flowLayoutPanel1->ResumeLayout(false);
            this->flowLayoutPanel1->PerformLayout();
            this->SideInfo_panel->ResumeLayout(false);
            this->tableLayoutPanel10->ResumeLayout(false);
            this->tableLayoutPanel10->PerformLayout();
            this->SideInfo_groupBox->ResumeLayout(false);
            this->TextMiniEditor_tableLayoutPanel->ResumeLayout(false);
            this->TextMiniEditor_tableLayoutPanel->PerformLayout();
            this->TextMiniEditor_flowLayoutPanel->ResumeLayout(false);
            this->TextMiniEditor_flowLayoutPanel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Fontsize_numericUpDown))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->separatorControl1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->separatorControl3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->separatorControl2))->EndInit();
            this->Recomendations_panel->ResumeLayout(false);
            this->Recomendations_panel->PerformLayout();
            this->tableLayoutPanel19->ResumeLayout(false);
            this->tableLayoutPanel17->ResumeLayout(false);
            this->tableLayoutPanel17->PerformLayout();
            this->Recommendations_groupBox->ResumeLayout(false);
            this->tableLayoutPanel16->ResumeLayout(false);
            this->AnalysisResults_panel->ResumeLayout(false);
            this->AnalysisResults_panel->PerformLayout();
            this->tableLayoutPanel9->ResumeLayout(false);
            this->tableLayoutPanel9->PerformLayout();
            this->AnalysisResults_groupBox->ResumeLayout(false);
            this->Anamnesis_panel->ResumeLayout(false);
            this->tableLayoutPanel14->ResumeLayout(false);
            this->tableLayoutPanel14->PerformLayout();
            this->panel3->ResumeLayout(false);
            this->panel3->PerformLayout();
            this->tableLayoutPanel11->ResumeLayout(false);
            this->tableLayoutPanel11->PerformLayout();
            this->flowLayoutPanel2->ResumeLayout(false);
            this->flowLayoutPanel2->PerformLayout();
            this->groupBox17->ResumeLayout(false);
            this->flowLayoutPanel3->ResumeLayout(false);
            this->flowLayoutPanel3->PerformLayout();
            this->groupBox18->ResumeLayout(false);
            this->NapravlenV_tableLayoutPanel->ResumeLayout(false);
            this->NapravlenV_tableLayoutPanel->PerformLayout();
            this->flowLayoutPanel5->ResumeLayout(false);
            this->flowLayoutPanel5->PerformLayout();
            this->NapravlenieVGospital_tableLayoutPanel->ResumeLayout(false);
            this->NapravlenieVGospital_tableLayoutPanel->PerformLayout();
            this->NapravlenVpolyclonic_panel->ResumeLayout(false);
            this->NapravlenVpolyclonic_panel->PerformLayout();
            this->RepeatCheck_groupBox->ResumeLayout(false);
            this->NapravlenVLazaret_panel->ResumeLayout(false);
            this->NapravlenVLazaret_panel->PerformLayout();
            this->tableLayoutPanel21->ResumeLayout(false);
            this->tableLayoutPanel21->PerformLayout();
            this->flowLayoutPanel6->ResumeLayout(false);
            this->flowLayoutPanel6->PerformLayout();
            this->IsLazaretaVPolyclinic_groupBox->ResumeLayout(false);
            this->IsLazaretaVGospital_groupBox->ResumeLayout(false);
            this->groupBox19->ResumeLayout(false);
            this->panel2->ResumeLayout(false);
            this->groupBox20->ResumeLayout(false);
            this->groupBox20->PerformLayout();
            this->Ill_History_panel->ResumeLayout(false);
            this->Ill_History_panel->PerformLayout();
            this->groupBox15->ResumeLayout(false);
            this->groupBox16->ResumeLayout(false);
            this->MKB_groupBox->ResumeLayout(false);
            this->groupBox14->ResumeLayout(false);
            this->groupBox13->ResumeLayout(false);
            this->groupBox12->ResumeLayout(false);
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
            this->UnworkableList_panel->ResumeLayout(false);
            this->UnworkableList_panel->PerformLayout();
            this->tableLayoutPanel18->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion


private: void ShowPanel(Panel^ panel) {
    Home_panel->Visible = false;
    Anamnesis_panel->Visible = false;
    Ill_History_panel->Visible = false;
    AnalysisResults_panel->Visible = false;
    AddingInfo_panel->Visible = false;
    Stamp_panel->Visible = false;
    UnworkableList_panel->Visible = false;
    SideInfo_panel->Visible = false;
    Recomendations_panel->Visible = false;
    if (panel == Epicrisis_panel) {
        Ill_History_panel->Visible = true;
        Ill_History_label->BackColor = Color::FromArgb(10, 80, 255);
        currentPanel = Ill_History_panel;
        id_numericUpDown->Focus();
    }
    if (panel == Anamnesis_panel || panel == Ill_History_panel || panel == AnalysisResults_panel
        || panel == AddingInfo_panel || panel == SideInfo_panel || panel == Recomendations_panel
        || panel == Stamp_panel || panel == UnworkableList_panel) {
        Epicrisis_panel->Visible = true;
        currentPanel = panel;
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
    id_numericUpDown->Focus();
}
private: System::Void BackToHome_button_Click(System::Object^ sender, System::EventArgs^ e) {
    Home();
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
    id_numericUpDown->Focus();
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
    AnamnesisText = Anamnesis_textBox->Text;
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
        Anamnesis_textBox->Text = "Астеническое состояние после перенесенной пневмонии. Медицинская реабилитация.";
        return;
    }

    if (MedOrganizationToResponse == "медпункт") {

        if (MedOrganizationToSend == "госпиталь") {
            Anamnesis_textBox->Text = "Со слов болен с " + IllBeginingDate + ". " +
                ResponseDate + " обратился в медпункт, направлен в госпиталь, по результатам ФОГК госпитализирован. ";
            //return;
        }
        else if (MedOrganizationToSend == "лазарет") {
            if (IsLazaretaVGospital) {
                Anamnesis_textBox->Text = "Со слов болен с " + IllBeginingDate + ". " +
                    ResponseDate + " обратился в медпункт, помещен в лазарет. "
                    + GospitalSentDate + " направлен в госпиталь, по результатам ФОГК госпитализирован. ";
            }
            else if (IsLazaretaVPolyclinic) {
                Anamnesis_textBox->Text = "Со слов болен с " + IllBeginingDate + ". " +
                    ResponseDate + " обратился в медпункт, помещен в лазарет. "
                    + PolyclinicSentDate + " направлен в поликлинику, по результатам ФОГК госпитализирован. ";
            }
            
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
                    + RepeatCheckDate + " повторно осмотрен терапевтом поликлиники и направлен в госпиталь, по результатам ФОГК госпитализирован. ";
                //return;
            }
        }
    }
    else if (MedOrganizationToResponse == "госпиталь") {
        Anamnesis_textBox->Text = "Со слов болен с " + IllBeginingDate + ". " +
            ResponseDate + " обратился в госпиталь, по результатам ФОГК госпитализирован. ";
        //return;
    }
    else if (MedOrganizationToResponse == "поликлинику") {
        if (Gospitalization) {
            Anamnesis_textBox->Text = "Со слов болен с " + IllBeginingDate + ". " +
                ResponseDate +
                " обратился в поликлинику, по результатам ФОГК назначена госпитализация. ";
            //return;
        }
        else {
            Anamnesis_textBox->Text = "Со слов болен с " + IllBeginingDate + ". " +
                ResponseDate + " обратился в поликлинику, назначено амбулаторное лечение. "
                + RepeatCheckDate + " повторно осмотрен терапевтом поликлиники и направлен в госпиталь, по результатам ФОГК госпитализирован. ";
            //return;
        }
    }
    if (researchCounter == 1) {
        Anamnesis_textBox->Text += MedicalResearchDate + " направлен на: " + ResearchType + ".";
    }
    else if (researchCounter > 1) {
        Anamnesis_textBox->Text += MedicalResearchDate + " выполнены обследования: " + ResearchType + ".";
    }
    AnamnesisText = Anamnesis_textBox->Text;
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
        Anamnesis_textBox->Text = "Астеническое состояние после перенесенной пневмонии. Медицинская реабилитация.";
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
        GospitalSentDate = IsLazaretaVGospital_dateTimePicker->Value.ToShortDateString();
        PolyclinicSentDate = IsLazaretaVPolyclinic_dateTimePicker->Value.ToShortDateString();
        NapravlenieVGospital_tableLayoutPanel->Visible = true;
        NapravlenVLazaret_panel->Visible = true;
        NapravlenVpolyclonic_panel->Visible = false;
        IsLazaretaVGospital_groupBox->Visible = true;
        IsLazaretaVPolyclinic_groupBox->Visible = false;
        MedOrganizationToSend = SentToLazaret_radioButton->Text->ToLower();
        AnamnesisTextBox();
    }
}
private: System::Void SentToGospital_radioButton_Click(System::Object^ sender, System::EventArgs^ e) {
    if (SentToGospital_radioButton->Checked) {
        NapravlenieVGospital_tableLayoutPanel->Visible = false;
        NapravlenVLazaret_panel->Visible = false;
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
private: System::Void checkBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    CheckBoxChangeValue(static_cast<CheckBox^>(sender));
}
private: System::Void IsLazaretaVGospital_dateTimePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    GospitalSentDate = IsLazaretaVGospital_dateTimePicker->Value.ToShortDateString();
    AnamnesisTextBox();
}
private: System::Void IsLazaretaVPolyclinic_dateTimePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    PolyclinicSentDate = IsLazaretaVPolyclinic_dateTimePicker->Value.ToShortDateString();
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
    AnalyzesResults_comboBox->TabStop = true;
    AnalyzesResults_comboBox->TabIndex = 0;
    AnamnesisText = Anamnesis_textBox->Text;
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
private: Void FillComboBox(System::Windows::Forms::ComboBox^ box, List<String^>^ items) {
    box->Items->Clear();
    for each (String ^ item in items) {
        box->Items->Add(item);
    }
}
private: Void FillCheckBoxList(String^ table, CheckedListBox^ checklist, List<String^>^ items) {
    checklist->Items->Clear();
    for each (String ^ item in  items) {
        checklist->Items->Add(item);
        checklist->SetItemChecked(checklist->Items->IndexOf(item), (dbHelper->SetQueryByCondition(table, "selectedByDefault", "title", item)[0] == "True"));
    }
}
private: Void FillComboBox(XtraEditors::ComboBoxEdit^ box, List<String^>^ items) {
    box->Properties->Items->Clear();
    for each (String ^ item in items) {
        box->Properties->Items->Add(item);
    }       
}
private: System::Void FillCheckBoxesFlowLayoutPanel(String^ table, FlowLayoutPanel^ panel, List<String^>^ items) {
    panel->Refresh();
    for each (String ^ item in items) {
        CheckBox^ box = gcnew CheckBox();
        box->AutoSize = true;
        box->Text = item;
        box->FlatStyle = FlatStyle::Flat;
        box->Font = gcnew System::Drawing::Font(box->Font->FontFamily, float(11));
        box->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
        box->Checked = dbHelper->SetQueryByCondition(table, "selectedByDefault", "title", item)[0] == "True";
        box->CheckedChanged += gcnew EventHandler(this, &MainWindow::SideInfoCheckBox_CheckedChanged);
        panel->Controls->Add(box);
    }
}
       //
       // TODO Прописать логику обработки события проставления галок в чекбоксах
       //
private: System::Void SideInfoCheckBox_CheckedChanged(Object^ sender, EventArgs^ e) {
    CheckBox^ box = safe_cast<CheckBox^>(sender);
    String^ name = box->Text;
    if (box->Checked) {
        if (name == "Выписывается") {

        }
        else if (name == "Телесные повреждения") {

        }
        else if (name == "Не годен 15 суток") {

        }
        else if (name == "Доп питание") {

        }
        else if (name == "Не годен 10 суток") {

        }
        else if (name == "Санаторий") {

        }
        else if (name == "Доп питание новое") {

        }
    }
}
private: Void InitializeData() {
    dbPath = dbPath_label->Text;
    dbHelper = gcnew DB_Helper(dbPath);
    epicrizDiagnosesList = gcnew List<String^>();
    RecommendationsList = gcnew List<String^>();
    id_numericUpDown->Value = Convert::ToDecimal(dbHelper->GetMinMaxColumnData("epicrises", "historyNumber", MinMax::Max)) + 1;
    epicrizDiagnosesList = dbHelper->GetColumnData("epicrizDiagnoses", "title");
    FillComboBox(Names_comboBox, dbHelper->GetSortedColumnData("firstNames", "value", 1));
    FillComboBox(Surname_comboBox, dbHelper->GetSortedColumnData("lastNames", "value", 1));
    FillComboBox(Patronymic_comboBox, dbHelper->GetSortedColumnData("middleNames", "value", 1));
    FillComboBox(rank_comboBox, dbHelper->GetColumnData("ranks", "value"));
    FillComboBox(militaryUnit_comboBox, dbHelper->GetColumnData("militaryUnits", "value"));
    FillComboBox(epicrizdiagnoses_comboBox, dbHelper->GetColumnData("epicrizDiagnoses", "title"));
    FillComboBox(mkb_comboBox, dbHelper->GetColumnData("epicrizDiagnoses", "mkb"));
    FillComboBox(related_comboBox, dbHelper->GetColumnData("relatedDiagnoses", "value"));
    FillComboBox(complications_comboBox, dbHelper->GetColumnData("complications", "value"));
    FillComboBox(AnalyzesResults_comboBox, dbHelper->GetColumnData("analyzes", "title"));
    FillCheckBoxList("recommendations", Recommendations_checkedListBox, dbHelper->SetQueryByCondition("recommendations", "title", "selectedByDefault", "1"));
    FillCheckBoxesFlowLayoutPanel("additionalInfos", CheckBoxes_flowLayoutPanel, dbHelper->GetColumnData("additionalInfos", "title"));
}
private: System::Void DB_change_button_Click(System::Object^ sender, System::EventArgs^ e) {
    PathType = PathTypes::DB;
    PathChanger_openFileDialog->InitialDirectory = Application::CommonAppDataPath;
    PathChanger_openFileDialog->FileName = "prod.db";
    PathChanger_openFileDialog->Filter = "SQlite DB (*.db)|*.db";
    PathChanger_openFileDialog->ShowDialog();
}
private: System::Void epicrizPathChange_button_Click(System::Object^ sender, System::EventArgs^ e) {
    PathType = PathTypes::Epicriz;
    PathChanger_openFileDialog->InitialDirectory = Application::CommonAppDataPath;
    PathChanger_openFileDialog->FileName = "Эпикризы";
    PathChanger_openFileDialog->Filter = "Папки (*./)|*./";
    PathChanger_openFileDialog->ShowDialog();
}
private: System::Void TemplatesChange_button_Click(System::Object^ sender, System::EventArgs^ e) {
    PathType = PathTypes::Templates;
    PathChanger_openFileDialog->InitialDirectory = Application::CommonAppDataPath;
    PathChanger_openFileDialog->FileName = "Templates";
    PathChanger_openFileDialog->Filter = "Папки (*./)|*./";
    PathChanger_openFileDialog->ShowDialog();
}
private: System::Void PathChanger_openFileDialog_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
    switch (PathType)
    {
    case PathTypes::DB:
        dbPath = PathChanger_openFileDialog->FileName;
        dbPath_label->Text = dbPath;
        dbHelper->~DB_Helper();
        InitializeData();
        break;
    case PathTypes::Templates:
        templatesPath = PathChanger_openFileDialog->FileName;
        tamplatesPath_label->Text = templatesPath;
        break;
    case PathTypes::Epicriz:
        epicrizPath = PathChanger_openFileDialog->FileName;
        epicrizPath_label->Text = epicrizPath;
        break;
    case PathTypes::DocNotes:
        break;
    case PathTypes::FirstList:       
        break;
    default:
        break;
    }
    
}
private: System::Void AnalyzesResults_comboBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    
}
private: System::Void Surname_comboBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    Surname = Surname_comboBox->Text;
    //Surname_comboBox->Text = Surname;
}
private: System::Void Names_comboBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    Name = Names_comboBox->Text;
    //Names_comboBox->Text = Name;
}
private: System::Void Patronymic_comboBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    Patronymic = Patronymic_comboBox->Text;
    //Patronymic_comboBox->Text = Patronymic;
}
private: System::Void rank_comboBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    Rank = rank_comboBox->Text;
    //rank_comboBox->Text = Rank;
}
private: System::Void militaryUnit_comboBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    MilitaryUnit = militaryUnit_comboBox->Text;
    //militaryUnit_comboBox->Text = MilitaryUnit;
}
private: System::Void birthday_dateTimePicker_Leave(System::Object^ sender, System::EventArgs^ e) {
    Birthday = birthday_dateTimePicker->Text;
    //birthday_dateTimePicker->Text = Birthday;
}
private: System::Void income_dateTimePicker_Leave(System::Object^ sender, System::EventArgs^ e) {
    IncomeDate = income_dateTimePicker->Text;
    //income_dateTimePicker->Text = IncomeDate;
}
private: System::Void outcome_dateTimePicker_Leave(System::Object^ sender, System::EventArgs^ e) {
    OutcomeDate = outcome_dateTimePicker->Text;
    //outcome_dateTimePicker->Text = OutcomeDate;
}
private: System::Void epicrizdiagnoses_comboBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    Diagnosis = epicrizdiagnoses_comboBox->Text;
    //int index = String::Substring()
    String^ DiagnosisInMkb = SearchingStringInList(Diagnosis, epicrizDiagnosesList);
    //epicrizdiagnoses_comboBox->Text = Diagnosis;
    if (DiagnosisInMkb != nullptr)
        mkb_comboBox->Text = dbHelper->SetQueryByConditionLike("epicrizDiagnoses", "mkb", "title", DiagnosisInMkb)[0];
}
private: System::String^ SearchingStringInList(String^ str, List<String^>^ Items) {
    List<String^>^ items = gcnew List<String^>(Items);
    List<String^>^ tmp_list = gcnew List<String^>();
    String^ result;
    for (int i = 1; i < str->Length; i++) {
        String^ substr = str->Substring(0, i);
        for each (String^ item in items) {
            if (item->Substring(0, i)->ToLower() == substr->ToLower()) {
                tmp_list->Add(item);
            }
        }
        if (tmp_list->Count == 1) {
            return result = tmp_list[0];
        }
        items->Clear();
        items->AddRange(tmp_list);
        tmp_list->Clear();
    }
    return result;
}
private: System::Void related_comboBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    RelatedDiagnosis = related_comboBox->Text;
    //related_comboBox->Text = RelatedDiagnosis;
}
private: System::Void complications_comboBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    Complications = complications_comboBox->Text;
    //complications_comboBox->Text = Complications;
}
private: System::Void mkb_comboBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    Mkb = mkb_comboBox->Text;
    //mkb_comboBox->Text;
}
private: System::Void id_numericUpDown_Leave(System::Object^ sender, System::EventArgs^ e) {
    HistoryNumber = id_numericUpDown->Text;
    id_numericUpDown->Text = HistoryNumber;
}
private: System::Void year_numericUpDown_Leave(System::Object^ sender, System::EventArgs^ e) {
    HistoryYear = year_numericUpDown->Text;
    year_numericUpDown->Text = HistoryYear; 
}       
private: System::Void TabIndexedComboBox_LeaveEnterClick(System::Object^ sender, System::EventArgs^ e) {
    ComboBox^ box = safe_cast<ComboBox^>(sender);
    String^ name = box->Name;
    NextComboBox(box);
}

private: System::Void InitializeComboBox() {
    ComboBoxList = gcnew List<ComboBox^>();
    ComboBoxList->Add(Surname_comboBox);
    ComboBoxList->Add(Names_comboBox);
    ComboBoxList->Add(Patronymic_comboBox);
    ComboBoxList->Add(rank_comboBox);
    ComboBoxList->Add(militaryUnit_comboBox);
    ComboBoxList->Add(epicrizdiagnoses_comboBox);
    ComboBoxList->Add(related_comboBox);
    ComboBoxList->Add(complications_comboBox);
    ComboBoxList->Add(mkb_comboBox);
    ComboBoxList->Add(AnalyzesResults_comboBox);
}
private: System::Void AddComboBox(ComboBox^ box) {
    ComboBoxList->Add(box);
}
private: System::Void NextComboBox(ComboBox^ box) {
    if (currentComboBox == ComboBoxList[ComboBoxList->IndexOf(box)] && box->DroppedDown == true)
        return;
    String^ boxName = box->Name;
    String^ currName;
    String^ prevName;
    if (ComboBoxList->Count != 0) {
        previousComboBox = currentComboBox;
        currentComboBox = ComboBoxList[ComboBoxList->IndexOf(box)];
        currName = currentComboBox->Name;
        if (previousComboBox != nullptr)
            prevName = previousComboBox->Name;
    }
    ComboBoxDropDownLogic();
}
private: System::Void ComboBoxDropDownLogic() {
    //if (previousComboBox != nullptr)
    //  previousComboBox->DroppedDown = false;
    currentComboBox->Focus();
    currentComboBox->DroppedDown = true;
}
private: System::Void Test_button_Click(System::Object^ sender, System::EventArgs^ e) {
    //GenerateRTFAndDisplay(R"([{"type":"paragraph","children":[{"text":"МОРФОЛОГИЧЕСКИЕ ИССЛЕДОВАНИЯ КРОВИ","bold":true,"underline":true}],"align":"center"},{"type":"table","columns":[{"type":"date","title":"Дата"},{"type":"text","title":"Нв г / л"},{"type":"text","title":"Эр.х10 ^ 12 / л"},{"type":"text","title":"ЦП"},{"type":"text","title":"Л х10 ^ 9 / л"},{"type":"text","title":"СОЭ Мм / ч"},{"type":"text","title":"Ht % "},{"type":"text","title":"Тр х10 ^ 9 / л"},{"type":"text","title":"Ре % "},{"type":"text","title":"t сверт."},{"type":"text","title":"t кров."},{"type":"text","title":"Млц"},{"type":"text","title":"Мтм"},{"type":"text","title":"Пя"},{"type":"text","title":"Ся"},{"type":"text","title":"Эоз"},{"type":"text","title":"Баз"},{"type":"text","title":"Мон"},{"type":"text","title":"Лиф"},{"type":"text","title":"Плз"},{"type":"text","title":"Анз"},{"type":"text","title":"Пйкл"},{"type":"text","title":"Гпхр"},{"type":"text","title":"ТЗН"}],"children":[{"type":"tableRow","children":[{"type":"tableHeaderCell","children":[{"text":"Да"},{"text":"та","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Нв г / л","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Эр.х10 ^ 12 / л","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"ЦП","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Л х10 ^ 9 / л","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"СОЭ Мм / ч","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Ht % ","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Тр х10 ^ 9 / л","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Ре % ","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"t сверт.","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"t кров.","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Млц","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Мтм","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Пя","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Ся","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Эоз","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Баз","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Мон","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Лиф","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Плз","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Анз","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Пйкл","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"Гпхр","fontSize":8}]},{"type":"tableHeaderCell","children":[{"text":"ТЗН","fontSize":8}]}]},{"type":"tableRow","children":[{"type":"tableDataCell","columnType":"date","children":[{"type":"dateInput","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]},{"type":"tableDataCell","columnType":"text","children":[{"type":"paragraph","children":[{"text":""}]}]}]}]},{"type":"paragraph","children":[{"text":""}]}])", richTextBox1);
    //CreateTableInRichTextBox(richTextBox1);
    // Пример JSON
    String^ json = R"({
      "columns": [
        {"width": 2000},
        {"width": 2000},
        {"width": 2000}
      ],
      "rows": [
        ["A1", "B1", "C1"],
        ["A2", "B2", "C2"],
        ["A3", "B3", "C3"]
      ]
    })";

    // Создаем таблицу в RichTextBox по JSON шаблону
    //CreateTableInRichTextBox(richTextBox, json);
}
private: System::Void Toolbar_button_Click(System::Object^ sender, System::EventArgs^ e) {
    Button^ button = safe_cast<Button^>(sender);
    if (button->BackColor != Color::FromKnownColor(KnownColor::AppWorkspace))
        button->BackColor = Color::FromKnownColor(KnownColor::AppWorkspace);
    else
        button->BackColor = Color::FromKnownColor(KnownColor::ControlLightLight);
   
}
private: System::Void IsLazaretaV_radioButton_Click(System::Object^ sender, System::EventArgs^ e) {
    if (IsLazaretaVGospital_radioButton->Checked) {
        IsLazaretaVGospital_groupBox->Visible = true;
        IsLazaretaVPolyclinic_groupBox->Visible = false;
        IsLazaretaVGospital = true;
        IsLazaretaVPolyclinic = false;
    }
    else if (IsLazaretaVPolyclinic_radioButton->Checked) {
        IsLazaretaVGospital_groupBox->Visible = false;
        IsLazaretaVPolyclinic_groupBox->Visible = true;
        IsLazaretaVGospital = false;
        IsLazaretaVPolyclinic = true;
    }
    AnamnesisTextBox();
}
private: System::Void InitializeInterface() {
    id = id_numericUpDown->Value;
    HistoryNumber = id_numericUpDown->Value.ToString();
    birthday_dateTimePicker->Value = DateTime::Now.AddYears(-18);
    income_dateTimePicker->Value = DateTime::Now.AddDays(-12);
    outcome_dateTimePicker->Value = DateTime::Now.AddDays(1);
    IllBegining_dateTimePicker->Value = income_dateTimePicker->Value.AddDays(-3);
}
private: System::Void id_numericUpDown_Enter(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ numericTextBox = safe_cast<TextBox^>(id_numericUpDown->Controls[1]);
    numericTextBox->SelectAll();
}
private: System::Void year_numericUpDown_Enter(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ numericTextBox = safe_cast<TextBox^>(year_numericUpDown->Controls[1]);
    numericTextBox->SelectAll();
}
private: System::Void AsteniaRec_button_Click(System::Object^ sender, System::EventArgs^ e) {
    //Recommendations_richTextBox->Text = R"(1) Избегать переохлаждений; 2) ДДН согласно Методическим рекомендациям от 22.03.2021 "Профилактика осложнений новой коронавирусной инфекции(COVID - 19) в Вооруженных силах Российской Федерации", Приложению к Приказу Министра обороны Российской Федерации от « 6 » июля 2021 г. №395 «Об утверждении Особенностей проведения диспансерного наблюдения за военнослужащими Вооруженных Сил Российской Федерации и гражданами, призванными на военные сборы, проводимые в Вооруженных Силах Российской Федерации, и перечня исследований, включаемых в диспансерное наблюдение за военнослужащими Вооруженных Сил Российской Федерации и гражданами, призванными на военные сборы, проводимые в Вооруженных Силах Российской Федерации».)";
    //Recommendations = Recommendations_richTextBox->Text;
}
private: System::Void BronhitRec_button_Click(System::Object^ sender, System::EventArgs^ e) {
    //Recommendations_richTextBox->Text = R"(1) Освободить от служебных обязанностей на 3е суток; 2) Избегать переохлаждений.)";
    //Recommendations = Recommendations_richTextBox->Text;
}
private: System::Void PnevmoRec_button_Click(System::Object^ sender, System::EventArgs^ e) {
    //Recommendations_richTextBox->Text = R"(1) Реализовать решение ВВК, медицинскую реабилитацию провести в ; 2) Выполнить через 9 дней контрольную ФОГК (прям.+ . бок) с осмотром пульмонолога; 3) Исключить переохлаждения. 4) ДДН согласно Методическим рекомендациям от 22.03.2021 "Профилактика осложнений новой коронавирусной инфекции (COVID-19) в Вооруженных силах Российской Федерации", Приложению к Приказу Министра обороны Российской Федерации от « 6 » июля 2021 г. №395 «Об утверждении Особенностей проведения диспансерного наблюдения за военнослужащими Вооруженных Сил Российской Федерации и гражданами, призванными на военные сборы, проводимые в Вооруженных Силах Российской Федерации, и перечня исследований, включаемых в диспансерное наблюдение за военнослужащими Вооруженных Сил Российской Федерации и гражданами, призванными на военные сборы, проводимые в Вооруженных Силах Российской Федерации».)";
    //Recommendations = Recommendations_richTextBox->Text;
}
private: System::Void Recommendations_checkedListBox_ItemCheck(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e) {
    // Получаем индекс измененного элемента
    int index = e->Index;

    // Получаем текущее состояние элемента
    bool isChecked = (e->NewValue == CheckState::Checked);

    // Делаем что-то в зависимости от того, выбран элемент или нет
    if (isChecked) {
        switch (index) {
        case 0:
            RecommendationsList->Add(R"(Реализовать решение ВВК, медицинскую реабилитацию провести в терапевтическом отделении госпиталя)");
            break;
        case 1:
            RecommendationsList->Add(R"(Освободить от строевой подготовки, физических занятий на 1 месяц)");
            break;
        case 2:
            RecommendationsList->Add(R"(ДДН согласно приказу министра обороны №800 от 18 июня 2011 года)");
            break;
        }
    }
    else {
        switch (index) {
        case 0:
            RecommendationsList->Remove(R"(Реализовать решение ВВК, медицинскую реабилитацию провести в терапевтическом отделении госпиталя)");
            break;
        case 1:
            RecommendationsList->Remove(R"(Освободить от строевой подготовки, физических занятий на 1 месяц)");
            break;
        case 2:
            RecommendationsList->Remove(R"(ДДН согласно приказу министра обороны №800 от 18 июня 2011 года)");
            break;
        }
    }
    Recommendations = nullptr;
    for (int i = 0; i < RecommendationsList->Count; i++) {
        Recommendations += (i+1) + ") " + RecommendationsList[i] + " ";
    }
}
private: System::Void Paste_button_Click(System::Object^ sender, System::EventArgs^ e) {
    //Recommendations_richTextBox->Text = Recommendations;
}
private: System::Void InitializeRichTextPanel(Panel^ panel) {
    /*Control::ControlCollection^ PanelControls = gcnew Control::ControlCollection(panel);
    TableLayoutPanel^ tablepanel = safe_cast<TableLayoutPanel^>(PanelControls[0]);
    Control::ControlCollection^ TableControls = gcnew Control::ControlCollection(tablepanel);
    RichTextBox^ rtb = safe_cast<RichTextBox^>(TableControls[1]);
    FlowLayoutPanel^ flowpanel = safe_cast<FlowLayoutPanel^>(TableControls[0]);
    Control::ControlCollection^ FlowControls = gcnew Control::ControlCollection(flowpanel);
    NumericUpDown^ FontSize = safe_cast<NumericUpDown^>(FlowControls[0]);
    Button^ Bold = safe_cast<Button^>(FlowControls[1]);
    Button^ Italic = safe_cast<Button^>(FlowControls[2]);
    Button^ Underlined = safe_cast<Button^>(FlowControls[3]);
    Button^ Uppercase = safe_cast<Button^>(FlowControls[4]);
    Button^ Lowercase = safe_cast<Button^>(FlowControls[5]);
    Button^ Unker = safe_cast<Button^>(FlowControls[6]);
    Button^ NumList = safe_cast<Button^>(FlowControls[7]);
    Button^ DotList = safe_cast<Button^>(FlowControls[8]);
    Button^ CleanFormat = safe_cast<Button^>(FlowControls[9]);
    Button^ LeftAlign = safe_cast<Button^>(FlowControls[10]);
    Button^ CenterAlign = safe_cast<Button^>(FlowControls[11]);
    Button^ RightAlign = safe_cast<Button^>(FlowControls[12]);
    Button^ WideAlign = safe_cast<Button^>(FlowControls[13]);
    Button^ Date = safe_cast<Button^>(FlowControls[14]);
    Button^ DropDownMenu = safe_cast<Button^>(FlowControls[15]);
    Button^ Table = safe_cast<Button^>(FlowControls[16]);*/
}
private: System::Void ShiftEnterHotKey() {
    NextPagePanel();
}
private: System::Void InitializePagesPanels() {
    PagePanelList = gcnew List<Panel^>();    
    AddPagePanel(Ill_History_panel);
    AddPagePanel(Anamnesis_panel);
    AddPagePanel(AnalysisResults_panel);
    AddPagePanel(AddingInfo_panel);
    AddPagePanel(SideInfo_panel);
    AddPagePanel(Recomendations_panel);
    AddPagePanel(UnworkableList_panel);
    AddPagePanel(Stamp_panel);
    ChangePanelDict = gcnew Dictionary<Panel^, Label^>();
    ChangePanelDict->Add(Ill_History_panel, Ill_History_label);
    ChangePanelDict->Add(Anamnesis_panel, Anamnesis_label);
    ChangePanelDict->Add(AnalysisResults_panel, AnalysisResults_label);
    ChangePanelDict->Add(AddingInfo_panel, AddingInfo_label);
    ChangePanelDict->Add(SideInfo_panel, SideInfo_label);
    ChangePanelDict->Add(Recomendations_panel, Recomendations_label);
    ChangePanelDict->Add(UnworkableList_panel, UnworkableList_label);
    ChangePanelDict->Add(Stamp_panel, Stamp_label);
}
private: System::Void AddPagePanel(Panel^ panel) {
    PagePanelList->Add(panel);
}
private: System::Void NextPagePanel() {
    String^ currName;
    if (Epicrisis_panel->Visible == false) return;
    if (currentPanel == nullptr)
        currentPanel = Ill_History_panel;
    if (PagePanelList->Count != 0) {
        int currentPanelIndex = PagePanelList->IndexOf(currentPanel);
        if (currentPanelIndex < PagePanelList->Count - 1) {
            currentPanel = PagePanelList[PagePanelList->IndexOf(currentPanel) + 1];
            currName = currentPanel->Name;
        }
        else {
            currentPanel = PagePanelList[0];
            currName = currentPanel->Name;
        }
    }
    PanelChangeLogic();
}
private: System::Void PanelChangeLogic() {
    ShowPanel(currentPanel);
    CleanEpicrisisTabLastLabel();
    SetTabMenuLabelBottomLine(ChangePanelDict[currentPanel]);
    if (!counter && (currentPanel == Anamnesis_panel)) {
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
    currentPanel->Focus();
}
private: System::Void Home() {
    ShowPanel(Home_panel);
    CleanEpicrisisTabLastLabel();
    this->BackToHome_label->BackColor = Color::FromArgb(10, 80, 255);
    lastLabel = BackToHome_label;
}
private: System::Void MainWindow_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

    if (e->KeyCode == Keys::Enter && e->Shift) {
        NextPagePanel();        
    }
    if (e->Control && (e->KeyCode == Keys::H)) {
        Home();
    }
}
private: System::Void MainWindow_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e) {
    
}
void ToggleFontStyle(FontStyle style) {
    System::Drawing::Font^ currentFont = richTextBox->SelectionFont;
    if (currentFont != nullptr)
    {
        FontStyle newStyle;
        if (currentFont->Style.HasFlag(style))
            newStyle = currentFont->Style & ~style;
        else
            newStyle = currentFont->Style | style;

        richTextBox->SelectionFont = gcnew System::Drawing::Font(currentFont, newStyle);
    }

}
private: System::Void Bold_button_Click(System::Object^ sender, System::EventArgs^ e) {
    Toolbar_button_Click(sender);
    ToggleFontStyle(FontStyle::Bold);
}
private: System::Void Italic_button_Click(System::Object^ sender, System::EventArgs^ e) {
    Toolbar_button_Click(sender);
    ToggleFontStyle(FontStyle::Italic);
}
private: System::Void Underline_button_Click(System::Object^ sender, System::EventArgs^ e) {
    Toolbar_button_Click(sender);
    ToggleFontStyle(FontStyle::Underline);
}
private: System::Void Uppercase_button_Click(System::Object^ sender, System::EventArgs^ e) {
    Toolbar_button_Click(sender);
    if (richTextBox->SelectionCharOffset == 0) {
        richTextBox->SelectionCharOffset = 10;
    }
    else
        richTextBox->SelectionCharOffset = 0;
}
private: System::Void Lowercase_button_Click(System::Object^ sender, System::EventArgs^ e) {
    Toolbar_button_Click(sender);
    if (richTextBox->SelectionCharOffset == 0)
        richTextBox->SelectionCharOffset = -10;
    else
        richTextBox->SelectionCharOffset = 0;
}
private: System::Void Unker_button_Click(System::Object^ sender, System::EventArgs^ e) {
    Toolbar_button_Click(sender);

}
private: System::Void NumList_button_Click(System::Object^ sender, System::EventArgs^ e) {
    Toolbar_button_Click(sender);
}
private: System::Void DotList_button_Click(System::Object^ sender, System::EventArgs^ e) {
    Toolbar_button_Click(sender);
}
private: System::Void CleanFormat_button_Click(System::Object^ sender, System::EventArgs^ e) {
    richTextBox->SelectionFont = gcnew System::Drawing::Font(richTextBox->SelectionFont, FontStyle::Regular);
    richTextBox->SelectionCharOffset = 0;
}
private: System::Void LeftAlign_button_Click(System::Object^ sender, System::EventArgs^ e) {
    Toolbar_button_Click(sender);
    CenterAlign_button->BackColor = Color::FromKnownColor(KnownColor::ControlLightLight);
    RightAlign_button->BackColor = Color::FromKnownColor(KnownColor::ControlLightLight);
    WideAlign_button->BackColor = Color::FromKnownColor(KnownColor::ControlLightLight);
    richTextBox->SelectionAlignment = HorizontalAlignment::Left;
}
private: System::Void CenterAlign_button_Click(System::Object^ sender, System::EventArgs^ e) {
    Toolbar_button_Click(sender);
    RightAlign_button->BackColor = Color::FromKnownColor(KnownColor::ControlLightLight);
    LeftAlign_button->BackColor = Color::FromKnownColor(KnownColor::ControlLightLight);
    WideAlign_button->BackColor = Color::FromKnownColor(KnownColor::ControlLightLight);
    richTextBox->SelectionAlignment = HorizontalAlignment::Center;
}
private: System::Void RightAlign_button_Click(System::Object^ sender, System::EventArgs^ e) {
    Toolbar_button_Click(sender);
    CenterAlign_button->BackColor = Color::FromKnownColor(KnownColor::ControlLightLight);
    LeftAlign_button->BackColor = Color::FromKnownColor(KnownColor::ControlLightLight);
    WideAlign_button->BackColor = Color::FromKnownColor(KnownColor::ControlLightLight);
    richTextBox->SelectionAlignment = HorizontalAlignment::Right;
}
private: System::Void WideAlign_button_Click(System::Object^ sender, System::EventArgs^ e) {
    Toolbar_button_Click(sender);
    CenterAlign_button->BackColor = Color::FromKnownColor(KnownColor::ControlLightLight);
    LeftAlign_button->BackColor = Color::FromKnownColor(KnownColor::ControlLightLight);
    RightAlign_button->BackColor = Color::FromKnownColor(KnownColor::ControlLightLight);
    //richTextBox. = System::Windows::TextAlignment::Justify;
}
private: System::Void Date_button_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void DropDownMenu_button_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Table_button_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Toolbar_button_Click(System::Object^ sender) {
    Button^ button = safe_cast<Button^>(sender);
    if (button->BackColor != Color::FromKnownColor(KnownColor::AppWorkspace))
        button->BackColor = Color::FromKnownColor(KnownColor::AppWorkspace);
    else
        button->BackColor = Color::FromKnownColor(KnownColor::ControlLightLight);
    richTextBox->Focus();
}
private: System::Void Fontsize_numericUpDown_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    int previousSelectionStart = richTextBox->SelectionStart;
    // Проверяем, есть ли выделенный текст
    if (richTextBox->SelectionLength > 0)
    {
        // Сохраняем текущую позицию каретки
        

        // Изменяем шрифт только для выделенного текста
        richTextBox->SelectionFont = gcnew System::Drawing::Font(richTextBox->SelectionFont->FontFamily,
            (float)Fontsize_numericUpDown->Value,
            richTextBox->SelectionFont->Style);

        // Возвращаем фокус на RichTextBox

        // Возвращаем каретку в прежнее положение
        
    }
    else // Нет выделенного текста, изменяем шрифт для дальнейшего ввода
    {
        // Меняем шрифт только для текущей позиции каретки
        richTextBox->SelectionFont = gcnew System::Drawing::Font(richTextBox->Font->FontFamily,
            (float)Fontsize_numericUpDown->Value,
            richTextBox->Font->Style);
        richTextBox->SelectionStart = previousSelectionStart;
        richTextBox->SelectionLength = 0;
    }
    richTextBox->Focus();
    
}
private: System::Void richTextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
    if (e->Control && (e->KeyCode == Keys::B)) {
        Toolbar_button_Click(Bold_button);
        ToggleFontStyle(FontStyle::Bold);
    }
    if (e->Control && (e->KeyCode == Keys::I)) {
        e->SuppressKeyPress = true;
        Toolbar_button_Click(Italic_button);
        ToggleFontStyle(FontStyle::Italic);
    }
    if (e->Control && (e->KeyCode == Keys::U)) {
        Toolbar_button_Click(Underline_button);
        ToggleFontStyle(FontStyle::Underline);
    }
}
};
}