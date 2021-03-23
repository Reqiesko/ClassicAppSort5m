#include "MainForm.h"
#include "FileInfo.h"
#include "FileDeals.h"
#include "DesignArt.h"
#include <msclr/gcroot.h>
#include <msclr/marshal_cppstd.h>
#include <list>

using namespace std;
using namespace System::Windows::Forms;

namespace Project1
{
	ArrayIssue::Array::SortingMethods ChosenSortingMethod = ArrayIssue::Array::SortingMethods::Auto;
	SortingOrders ChosenSortingOrder = SortingOrders::Chaos;
	int actionN = 0;

	list<FileInfo::FileInformation*>* fileInfoList;

	[STAThread]
	void main()
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Application::Run(gcnew MainForm());
	}

	Void MainForm::LoadWindow(Object^ sender, EventArgs^ e)
	{
		numberTable->AutoGenerateColumns = true;
		numberTable->ColumnCount = GetNumericValue();
		numberTable->Rows->Add(1);
		numberTable->AllowUserToAddRows = false;
	}

	Void MainForm::GetDataFormat(int numberOfColumns)
	{
		cOrder->Checked = true;
		aSort->Checked = true;
		sortingMethodGroup->Visible = true;
		sortingOrderGroup->Visible = true;
		numberTable->Enabled = true;
		numberTable->ReadOnly = false;
		numberTable->Visible = true;
		numericUpDownCells->Value = numberOfColumns;
		sortingMethodGroup->Enabled = true;
		sortingOrderGroup->Enabled = true;
		applyButton->Enabled = true;
		numericUpDownCells->Enabled = true;
		outputLayout->Controls->Clear();
		fileInfoList = new list<FileInfo::FileInformation*>();
		clearButton->Enabled = true;
		clearButton->Visible = true;
		saveAs->Enabled = true;
		actionN = 0;
	}

	Void MainForm::ChooseUseFile(Object^ sender, EventArgs^ e)
	{
		if (fileDialogue->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			ArrayIssue::Array* dArray = new ArrayIssue::Array();
			ifstream* file = OpenFile(msclr::interop::marshal_as<string>(fileDialogue->FileName));
			ReadFileErrors fileError = GetArray(file, *dArray);
			if (fileError == ReadFileErrors::CorrectFormat && dArray->countN > 0)
			{
				FillTable(*dArray, numberTable);
				GetDataFormat(dArray->countN);
				numberTable->ReadOnly = true;
				numericUpDownCells->Enabled = false;
			}
			else
				if (fileError == ReadFileErrors::IncorrectFormat)
					MessageBox::Show("Ошибка ввода. Неверный формат", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
				else
					MessageBox::Show("Ошибка ввода. Файл пустой", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
			CloseFile(file);
		}
	}

	Void MainForm::ChooseUseKeyboard(Object^ sender, EventArgs^ e)
	{
		GetDataFormat(GetNumericValue());
	}

	Void MainForm::ClickClear(Object^ sender, EventArgs^ e)
	{
		EmptyTable(numberTable, GetNumericValue());
		GetDataFormat(GetNumericValue());
		numberTable->Enabled = false;
		numberTable->Visible = false;
		clearButton->Enabled = false;
		clearButton->Visible = false;
		saveAs->Enabled = false;
	}

	Void MainForm::ChooseUseRandom(Object^ sender, EventArgs^ e)
	{
		ArrayIssue::Array* dArray = new ArrayIssue::Array(GetNumericValue());
		GetDataFormat(dArray->countN);
		FillTable(*dArray, numberTable);
		numberTable->ReadOnly = true;
	}

	Void MainForm::ChooseSaveArray(Object^ sender, EventArgs^ e)
	{
		if (saveFileDialogue->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			if (!saveFileDialogue->FileName->EndsWith(".txt")) saveFileDialogue->FileName += ".txt";
			FileInfo::FileInformation* fileInfo = new FileInfo::FileInformation(GetTable(numberTable).arrayDouble, numberTable->ColumnCount, "Начальный массив");
			fileInfoList->push_back(fileInfo);
			ofstream* file = OpenSaveFile(msclr::interop::marshal_as<string>(saveFileDialogue->FileName));
			SaveArray(file, *fileInfoList);
			CloseFile(file);
			MessageBox::Show("Все данные были успешно сохранены!", "Успешное сохранение", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	Void MainForm::ClickApplySort(Object^ sender, EventArgs^ e)
	{
		try
		{
			numberTable->ReadOnly = true;
			ArrayIssue::Array* dArray = new ArrayIssue::Array(GetTable(numberTable));
			bool wasAuto = false;
			dArray->method = (ChosenSortingOrder == SortingOrders::AbsoluteAscending || ChosenSortingOrder == SortingOrders::AbsoluteDescending);
			if (ChosenSortingOrder != SortingOrders::Chaos)
				switch (ChosenSortingMethod)
			{
				case ArrayIssue::Array::SortingMethods::Bubble: dArray->SortingCheck(ChosenSortingMethod); break;
				case ArrayIssue::Array::SortingMethods::Merge: dArray->SortingCheck(ChosenSortingMethod); break;
				case ArrayIssue::Array::SortingMethods::Quick: dArray->SortingCheck(ChosenSortingMethod); break;
				case ArrayIssue::Array::SortingMethods::Selection: dArray->SortingCheck(ChosenSortingMethod); break;
				case ArrayIssue::Array::SortingMethods::Shell: dArray->SortingCheck(ChosenSortingMethod); break;
				default: ChosenSortingMethod = dArray->Statistics(); wasAuto = true; break;
			}
			else
				dArray->SortChaosSort();
			if (ChosenSortingOrder == SortingOrders::Descending || ChosenSortingOrder == SortingOrders::AbsoluteDescending)
				dArray->ReverseArray();
			String^ info = WriteStatistics(dArray->comparisons, dArray->operations, dArray->seconds, ChosenSortingOrder == SortingOrders::Chaos);
			FileInfo::FileInformation* fileInfoElement = new FileInfo::FileInformation(dArray->arrayDouble, dArray->countN, msclr::interop::marshal_as<string>(info));
			fileInfoList->push_front(fileInfoElement);
			AddNewTable(*dArray);
			AddADescription(++actionN, info);
			if (wasAuto) ChosenSortingMethod = ArrayIssue::Array::SortingMethods::Auto;
		}
		catch (bool error)
		{
			error = true;
			MessageBox::Show("Возникла ошибка. Пожалуйста, проверьте введённые данные!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	String^ MainForm::WriteStatistics(int comparisons, int operations, int time, bool chaos)
	{
		sortLabel->Text = "";
		if (!chaos) sortLabel->Text = GetMethod(ChosenSortingMethod) + " ";
		sortLabel->Text += GetOrder(ChosenSortingOrder) + "; ";
		stepsLabel->Text = "Сравнения: " + comparisons + "; ";
		conditionsLabel->Text = "Замены: " + operations + "; ";
		timeLabel->Text = "Время: " + time + " мс.";
		return sortLabel->Text + stepsLabel->Text + conditionsLabel->Text + timeLabel->Text;
	}

	DataGridView^ MainForm::AddNewTable(ArrayIssue::Array arrayD)
	{
		DataGridView^ data = gcnew DataGridView();
		data->Width = outputLayout->Width;
		data->Height = numberTable->Height;
		data->BackgroundColor = Color::NavajoWhite;
		data->AllowUserToAddRows = false;
		data->ColumnHeadersVisible = false;
		data->RowCount = 1;
		data->ColumnCount = arrayD.countN;
		data->ReadOnly = true;
		FillTable(arrayD, data);
		outputLayout->Controls->Add(data);
		return data;
	}

	Label^ MainForm::AddADescription(int number, String^ info)
	{
		Label^ label = gcnew Label();
		label->AutoSize = true;
		label->Text = "Действие №" + number + ".\n" + info + "\n";
		outputLayout->Controls->Add(label);
		return label;
	}

	Void MainForm::ChangeUpDownMouse(Object^ sender, MouseEventArgs^ e)
	{
		numberTable->ColumnCount = ConvertationToInt(numericUpDownCells->Text);
	}

	Void MainForm::Exit(Object^ sender, EventArgs^ e)
	{
		if (System::Windows::Forms::DialogResult::Yes == MessageBox::Show("Вы уверены, что хотите закрыть приложение?", "Выход", MessageBoxButtons::YesNo, MessageBoxIcon::Question))
			Application::Exit();
	}

	Void MainForm::CheckedRadioButtonOrder(Object^ sender, EventArgs^ e)
	{
		ChosenSortingOrder = (SortingOrders)ConvertationToInt(((RadioButton^)sender)->Tag);
	}

	Void MainForm::CheckedRadioButtonMethod(Object^ sender, EventArgs^ e)
	{
		ChosenSortingMethod = (ArrayIssue::Array::SortingMethods)ConvertationToInt(((RadioButton^)sender)->Tag);
	}

	int MainForm::GetNumericValue()
	{
		return ConvertationToInt(numericUpDownCells->Value);
	}
}