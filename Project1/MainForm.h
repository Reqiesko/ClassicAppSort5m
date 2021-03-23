#pragma once
#include "NumberClass.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ saveAs;
	protected:













	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem1;


	private: System::Windows::Forms::GroupBox^ sortingOrderGroup;
	private: System::Windows::Forms::RadioButton^ cOrder;


	private: System::Windows::Forms::RadioButton^ dOrder;

	private: System::Windows::Forms::RadioButton^ aOrder;


	private: System::Windows::Forms::GroupBox^ sortingMethodGroup;
	private: System::Windows::Forms::RadioButton^ aSort;
	private: System::Windows::Forms::RadioButton^ seSort;



	private: System::Windows::Forms::RadioButton^ qSort;

	private: System::Windows::Forms::RadioButton^ mSort;

	private: System::Windows::Forms::RadioButton^ bSort;
	private: System::Windows::Forms::Button^ applyButton;


	private: System::Windows::Forms::DataGridView^ numberTable;
	private: System::Windows::Forms::OpenFileDialog^ fileDialogue;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownCells;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RadioButton^ sSort;

	private: System::Windows::Forms::RadioButton^ aaOrder;
	private: System::Windows::Forms::RadioButton^ adOrder;


	private: System::Windows::Forms::SaveFileDialog^ saveFileDialogue;
	private: System::Windows::Forms::StatusStrip^ statusStrip;
	private: System::Windows::Forms::ToolStripStatusLabel^ stepsLabel;
	private: System::Windows::Forms::ToolStripStatusLabel^ conditionsLabel;
	private: System::Windows::Forms::ToolStripStatusLabel^ timeLabel;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ToolStripStatusLabel^ sortLabel;

	private: System::Windows::Forms::FlowLayoutPanel^ outputLayout;
	private: System::Windows::Forms::Button^ clearButton;









	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->saveAs = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sortingOrderGroup = (gcnew System::Windows::Forms::GroupBox());
			this->aaOrder = (gcnew System::Windows::Forms::RadioButton());
			this->adOrder = (gcnew System::Windows::Forms::RadioButton());
			this->cOrder = (gcnew System::Windows::Forms::RadioButton());
			this->dOrder = (gcnew System::Windows::Forms::RadioButton());
			this->aOrder = (gcnew System::Windows::Forms::RadioButton());
			this->sortingMethodGroup = (gcnew System::Windows::Forms::GroupBox());
			this->sSort = (gcnew System::Windows::Forms::RadioButton());
			this->aSort = (gcnew System::Windows::Forms::RadioButton());
			this->seSort = (gcnew System::Windows::Forms::RadioButton());
			this->qSort = (gcnew System::Windows::Forms::RadioButton());
			this->mSort = (gcnew System::Windows::Forms::RadioButton());
			this->bSort = (gcnew System::Windows::Forms::RadioButton());
			this->applyButton = (gcnew System::Windows::Forms::Button());
			this->numberTable = (gcnew System::Windows::Forms::DataGridView());
			this->fileDialogue = (gcnew System::Windows::Forms::OpenFileDialog());
			this->numericUpDownCells = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialogue = (gcnew System::Windows::Forms::SaveFileDialog());
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->sortLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->stepsLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->conditionsLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->timeLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->outputLayout = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->sortingOrderGroup->SuspendLayout();
			this->sortingMethodGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numberTable))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCells))->BeginInit();
			this->statusStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Linen;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->saveAs, this->exitToolStripMenuItem1 });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(13, 4, 0, 4);
			this->menuStrip1->Size = System::Drawing::Size(1364, 31);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// saveAs
			// 
			this->saveAs->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->saveAs->Name = L"saveAs";
			this->saveAs->Size = System::Drawing::Size(131, 23);
			this->saveAs->Text = L"Сохранить как...";
			this->saveAs->Click += gcnew System::EventHandler(this, &MainForm::ChooseSaveArray);
			// 
			// exitToolStripMenuItem1
			// 
			this->exitToolStripMenuItem1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->exitToolStripMenuItem1->Name = L"exitToolStripMenuItem1";
			this->exitToolStripMenuItem1->Size = System::Drawing::Size(67, 23);
			this->exitToolStripMenuItem1->Text = L"Выйти";
			this->exitToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::Exit);
			// 
			// sortingOrderGroup
			// 
			this->sortingOrderGroup->Controls->Add(this->aaOrder);
			this->sortingOrderGroup->Controls->Add(this->adOrder);
			this->sortingOrderGroup->Controls->Add(this->cOrder);
			this->sortingOrderGroup->Controls->Add(this->dOrder);
			this->sortingOrderGroup->Controls->Add(this->aOrder);
			this->sortingOrderGroup->Enabled = false;
			this->sortingOrderGroup->Location = System::Drawing::Point(375, 54);
			this->sortingOrderGroup->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->sortingOrderGroup->Name = L"sortingOrderGroup";
			this->sortingOrderGroup->Padding = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->sortingOrderGroup->Size = System::Drawing::Size(351, 199);
			this->sortingOrderGroup->TabIndex = 2;
			this->sortingOrderGroup->TabStop = false;
			this->sortingOrderGroup->Text = L"Порядок сортировки";
			// 
			// aaOrder
			// 
			this->aaOrder->AutoSize = true;
			this->aaOrder->Location = System::Drawing::Point(14, 66);
			this->aaOrder->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->aaOrder->Name = L"aaOrder";
			this->aaOrder->Size = System::Drawing::Size(313, 30);
			this->aaOrder->TabIndex = 4;
			this->aaOrder->Tag = L"2";
			this->aaOrder->Text = L"по возрастанию (по модулю)";
			this->aaOrder->UseVisualStyleBackColor = true;
			this->aaOrder->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckedRadioButtonOrder);
			// 
			// adOrder
			// 
			this->adOrder->AutoSize = true;
			this->adOrder->Location = System::Drawing::Point(14, 133);
			this->adOrder->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->adOrder->Name = L"adOrder";
			this->adOrder->Size = System::Drawing::Size(288, 30);
			this->adOrder->TabIndex = 3;
			this->adOrder->Tag = L"3";
			this->adOrder->Text = L"по убыванию (по модулю)";
			this->adOrder->UseVisualStyleBackColor = true;
			this->adOrder->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckedRadioButtonOrder);
			// 
			// cOrder
			// 
			this->cOrder->AutoSize = true;
			this->cOrder->Checked = true;
			this->cOrder->Location = System::Drawing::Point(1000, 29);
			this->cOrder->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->cOrder->Name = L"cOrder";
			this->cOrder->Size = System::Drawing::Size(318, 30);
			this->cOrder->TabIndex = 2;
			this->cOrder->TabStop = true;
			this->cOrder->Tag = L"4";
			this->cOrder->Text = L"беспорядок (без сортировки)";
			this->cOrder->UseVisualStyleBackColor = true;
			this->cOrder->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckedRadioButtonOrder);
			// 
			// dOrder
			// 
			this->dOrder->AutoSize = true;
			this->dOrder->Location = System::Drawing::Point(14, 100);
			this->dOrder->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->dOrder->Name = L"dOrder";
			this->dOrder->Size = System::Drawing::Size(160, 30);
			this->dOrder->TabIndex = 1;
			this->dOrder->Tag = L"1";
			this->dOrder->Text = L"по убыванию";
			this->dOrder->UseVisualStyleBackColor = true;
			this->dOrder->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckedRadioButtonOrder);
			// 
			// aOrder
			// 
			this->aOrder->AutoSize = true;
			this->aOrder->Location = System::Drawing::Point(14, 29);
			this->aOrder->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->aOrder->Name = L"aOrder";
			this->aOrder->Size = System::Drawing::Size(185, 30);
			this->aOrder->TabIndex = 0;
			this->aOrder->Tag = L"0";
			this->aOrder->Text = L"по возрастанию";
			this->aOrder->UseVisualStyleBackColor = true;
			this->aOrder->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckedRadioButtonOrder);
			// 
			// sortingMethodGroup
			// 
			this->sortingMethodGroup->Controls->Add(this->sSort);
			this->sortingMethodGroup->Controls->Add(this->aSort);
			this->sortingMethodGroup->Controls->Add(this->seSort);
			this->sortingMethodGroup->Controls->Add(this->qSort);
			this->sortingMethodGroup->Controls->Add(this->mSort);
			this->sortingMethodGroup->Controls->Add(this->bSort);
			this->sortingMethodGroup->Enabled = false;
			this->sortingMethodGroup->Location = System::Drawing::Point(736, 54);
			this->sortingMethodGroup->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->sortingMethodGroup->Name = L"sortingMethodGroup";
			this->sortingMethodGroup->Padding = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->sortingMethodGroup->Size = System::Drawing::Size(428, 199);
			this->sortingMethodGroup->TabIndex = 4;
			this->sortingMethodGroup->TabStop = false;
			this->sortingMethodGroup->Text = L"Метод сортировки";
			// 
			// sSort
			// 
			this->sSort->AutoSize = true;
			this->sSort->Location = System::Drawing::Point(13, 133);
			this->sSort->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->sSort->Name = L"sSort";
			this->sSort->Size = System::Drawing::Size(93, 30);
			this->sSort->TabIndex = 5;
			this->sSort->Tag = L"5";
			this->sSort->Text = L"Шелла";
			this->sSort->UseVisualStyleBackColor = true;
			this->sSort->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckedRadioButtonMethod);
			// 
			// aSort
			// 
			this->aSort->AutoSize = true;
			this->aSort->Checked = true;
			this->aSort->Location = System::Drawing::Point(13, 30);
			this->aSort->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->aSort->Name = L"aSort";
			this->aSort->Size = System::Drawing::Size(401, 30);
			this->aSort->TabIndex = 4;
			this->aSort->TabStop = true;
			this->aSort->Tag = L"0";
			this->aSort->Text = L"автоматический (наилучший вариант)";
			this->aSort->UseVisualStyleBackColor = true;
			this->aSort->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckedRadioButtonMethod);
			// 
			// seSort
			// 
			this->seSort->AutoSize = true;
			this->seSort->Location = System::Drawing::Point(184, 66);
			this->seSort->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->seSort->Name = L"seSort";
			this->seSort->Size = System::Drawing::Size(119, 30);
			this->seSort->TabIndex = 3;
			this->seSort->Tag = L"4";
			this->seSort->Text = L"выбором";
			this->seSort->UseVisualStyleBackColor = true;
			this->seSort->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckedRadioButtonMethod);
			// 
			// qSort
			// 
			this->qSort->AutoSize = true;
			this->qSort->Location = System::Drawing::Point(184, 100);
			this->qSort->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->qSort->Name = L"qSort";
			this->qSort->Size = System::Drawing::Size(110, 30);
			this->qSort->TabIndex = 2;
			this->qSort->Tag = L"3";
			this->qSort->Text = L"быстрая";
			this->qSort->UseVisualStyleBackColor = true;
			this->qSort->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckedRadioButtonMethod);
			// 
			// mSort
			// 
			this->mSort->AutoSize = true;
			this->mSort->Location = System::Drawing::Point(13, 100);
			this->mSort->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->mSort->Name = L"mSort";
			this->mSort->Size = System::Drawing::Size(123, 30);
			this->mSort->TabIndex = 1;
			this->mSort->Tag = L"2";
			this->mSort->Text = L"слиянием";
			this->mSort->UseVisualStyleBackColor = true;
			this->mSort->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckedRadioButtonMethod);
			// 
			// bSort
			// 
			this->bSort->AutoSize = true;
			this->bSort->Location = System::Drawing::Point(13, 66);
			this->bSort->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->bSort->Name = L"bSort";
			this->bSort->Size = System::Drawing::Size(136, 30);
			this->bSort->TabIndex = 0;
			this->bSort->Tag = L"1";
			this->bSort->Text = L"пузырьком";
			this->bSort->UseVisualStyleBackColor = true;
			this->bSort->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckedRadioButtonMethod);
			// 
			// applyButton
			// 
			this->applyButton->BackColor = System::Drawing::Color::Linen;
			this->applyButton->Enabled = false;
			this->applyButton->Location = System::Drawing::Point(1189, 68);
			this->applyButton->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->applyButton->Name = L"applyButton";
			this->applyButton->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->applyButton->Size = System::Drawing::Size(161, 45);
			this->applyButton->TabIndex = 5;
			this->applyButton->Text = L"Применить";
			this->applyButton->UseVisualStyleBackColor = false;
			this->applyButton->Click += gcnew System::EventHandler(this, &MainForm::ClickApplySort);
			// 
			// numberTable
			// 
			this->numberTable->AllowUserToAddRows = false;
			this->numberTable->AllowUserToDeleteRows = false;
			this->numberTable->BackgroundColor = System::Drawing::Color::SeaShell;
			this->numberTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->numberTable->ColumnHeadersVisible = false;
			this->numberTable->Enabled = false;
			this->numberTable->EnableHeadersVisualStyles = false;
			this->numberTable->Location = System::Drawing::Point(15, 315);
			this->numberTable->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->numberTable->Name = L"numberTable";
			this->numberTable->ReadOnly = true;
			this->numberTable->RowHeadersVisible = false;
			this->numberTable->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->numberTable->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->numberTable->Size = System::Drawing::Size(1339, 72);
			this->numberTable->TabIndex = 6;
			this->numberTable->Visible = false;
			// 
			// fileDialogue
			// 
			this->fileDialogue->Filter = L"Text Files (*.txt)|*.txt";
			this->fileDialogue->ShowHelp = true;
			// 
			// numericUpDownCells
			// 
			this->numericUpDownCells->Location = System::Drawing::Point(269, 267);
			this->numericUpDownCells->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->numericUpDownCells->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 650, 0, 0, 0 });
			this->numericUpDownCells->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownCells->Name = L"numericUpDownCells";
			this->numericUpDownCells->Size = System::Drawing::Size(203, 34);
			this->numericUpDownCells->TabIndex = 7;
			this->numericUpDownCells->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numericUpDownCells->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDownCells->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::ChangeUpDownMouse);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(35, 269);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(187, 26);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Количество ячеек";
			// 
			// saveFileDialogue
			// 
			this->saveFileDialogue->DefaultExt = L"txt";
			this->saveFileDialogue->Filter = L"Text Files (*.txt)|*.txt";
			this->saveFileDialogue->RestoreDirectory = true;
			this->saveFileDialogue->ShowHelp = true;
			this->saveFileDialogue->SupportMultiDottedExtensions = true;
			// 
			// statusStrip
			// 
			this->statusStrip->BackColor = System::Drawing::Color::Linen;
			this->statusStrip->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->sortLabel, this->stepsLabel,
					this->conditionsLabel, this->timeLabel
			});
			this->statusStrip->Location = System::Drawing::Point(0, 618);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Padding = System::Windows::Forms::Padding(2, 0, 30, 0);
			this->statusStrip->Size = System::Drawing::Size(1364, 28);
			this->statusStrip->TabIndex = 9;
			this->statusStrip->Text = L"statusStrip1";
			// 
			// sortLabel
			// 
			this->sortLabel->Name = L"sortLabel";
			this->sortLabel->Size = System::Drawing::Size(0, 23);
			// 
			// stepsLabel
			// 
			this->stepsLabel->Name = L"stepsLabel";
			this->stepsLabel->Size = System::Drawing::Size(62, 23);
			this->stepsLabel->Text = L"Steps:";
			// 
			// conditionsLabel
			// 
			this->conditionsLabel->Name = L"conditionsLabel";
			this->conditionsLabel->Size = System::Drawing::Size(112, 23);
			this->conditionsLabel->Text = L"Conditions:";
			// 
			// timeLabel
			// 
			this->timeLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->timeLabel->Name = L"timeLabel";
			this->timeLabel->Size = System::Drawing::Size(58, 23);
			this->timeLabel->Text = L"Time:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 54);
			this->button1->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(334, 45);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Ввести с клавиатуры";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::ChooseUseKeyboard);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(15, 172);
			this->button2->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(334, 45);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Открыть файл";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::ChooseUseFile);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(15, 113);
			this->button3->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(334, 45);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Сгенерировать случайные числа";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::ChooseUseRandom);
			// 
			// outputLayout
			// 
			this->outputLayout->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->outputLayout->AutoScroll = true;
			this->outputLayout->BackColor = System::Drawing::Color::SeaShell;
			this->outputLayout->FlowDirection = System::Windows::Forms::FlowDirection::BottomUp;
			this->outputLayout->Location = System::Drawing::Point(15, 398);
			this->outputLayout->Margin = System::Windows::Forms::Padding(4);
			this->outputLayout->Name = L"outputLayout";
			this->outputLayout->Size = System::Drawing::Size(1339, 203);
			this->outputLayout->TabIndex = 14;
			this->outputLayout->WrapContents = false;
			// 
			// clearButton
			// 
			this->clearButton->BackColor = System::Drawing::Color::Linen;
			this->clearButton->Enabled = false;
			this->clearButton->Location = System::Drawing::Point(1189, 127);
			this->clearButton->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->clearButton->Name = L"clearButton";
			this->clearButton->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->clearButton->Size = System::Drawing::Size(161, 45);
			this->clearButton->TabIndex = 15;
			this->clearButton->Text = L"Сбросить";
			this->clearButton->UseVisualStyleBackColor = false;
			this->clearButton->Visible = false;
			this->clearButton->Click += gcnew System::EventHandler(this, &MainForm::ClickClear);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 26);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SeaShell;
			this->ClientSize = System::Drawing::Size(1364, 646);
			this->Controls->Add(this->clearButton);
			this->Controls->Add(this->outputLayout);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->statusStrip);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDownCells);
			this->Controls->Add(this->numberTable);
			this->Controls->Add(this->applyButton);
			this->Controls->Add(this->sortingMethodGroup);
			this->Controls->Add(this->sortingOrderGroup);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 17));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->MaximumSize = System::Drawing::Size(1380, 685);
			this->MinimumSize = System::Drawing::Size(1380, 685);
			this->Name = L"MainForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная работа №1. Работа с массивами и сортировкой";
			this->Load += gcnew System::EventHandler(this, &MainForm::LoadWindow);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->sortingOrderGroup->ResumeLayout(false);
			this->sortingOrderGroup->PerformLayout();
			this->sortingMethodGroup->ResumeLayout(false);
			this->sortingMethodGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numberTable))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCells))->EndInit();
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Void ChooseUseFile(Object^ sender, EventArgs^ e);
	private: Void ChooseUseRandom(Object^ sender, EventArgs^ e);
	private: Void ChooseUseKeyboard(Object^ sender, EventArgs^ e);
	private: Void ClickApplySort(Object^ sender, EventArgs^ e);
	private: Void Exit(Object^ sender, EventArgs^ e);
	private: Void ChangeUpDownMouse(Object^ sender, MouseEventArgs^ e);
	private: Void ChooseSaveArray(Object^ sender, EventArgs^ e);
	private: Void GetDataFormat(int numberOfColumns);
	private: Void CheckedRadioButtonOrder(Object^ sender, EventArgs^ e);
	private: Void CheckedRadioButtonMethod(Object^ sender, EventArgs^ e);
	private: int GetNumericValue();
	private: Void LoadWindow(Object^ sender, EventArgs^ e);
	private: String^ WriteStatistics(int, int, int, bool);
	private: DataGridView^ AddNewTable(ArrayIssue::Array);
	private: Label^ AddADescription(int, String^);
	private: Void ClickClear(Object^ sender, EventArgs^ e);
	};
}