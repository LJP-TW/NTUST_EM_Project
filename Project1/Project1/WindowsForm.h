#pragma once
#include"DataManager.h"
#include"DotNetUtilities.h"

enum Mode {VECTOR_MODE, MATRIX_MODE};

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// WindowsForm ���K�n
	/// </summary>
	public ref class WindowsForm : public System::Windows::Forms::Form
	{
	public:
		WindowsForm(void)
		{
			InitializeComponent();
			dataManager = new DataManager();
			nowMode = VECTOR_MODE;
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~WindowsForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  FileToolStripMenuItem;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ToolStripMenuItem^  LoadVectorToolStripMenuItem;

	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::Label^  OutputLabel;
	private: System::Windows::Forms::TextBox^  Output;

	private: System::Windows::Forms::Label^  InputLabel;
	private: System::Windows::Forms::TextBox^  Input;
	private: System::Windows::Forms::Label^  VectorLabel;
	private: System::Windows::Forms::ListBox^  VectorList;
	private: System::Windows::Forms::OpenFileDialog^  openVectorFileDialog;



	private:
		DataManager* dataManager;
		String^ userInput;
		Mode nowMode;
	private: System::Windows::Forms::ToolStripMenuItem^  loadMatrixToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openMatrixFileDialog;

			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LoadVectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadMatrixToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->InputLabel = (gcnew System::Windows::Forms::Label());
			this->Input = (gcnew System::Windows::Forms::TextBox());
			this->VectorLabel = (gcnew System::Windows::Forms::Label());
			this->VectorList = (gcnew System::Windows::Forms::ListBox());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->OutputLabel = (gcnew System::Windows::Forms::Label());
			this->Output = (gcnew System::Windows::Forms::TextBox());
			this->openVectorFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openMatrixFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip2->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip2
			// 
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->FileToolStripMenuItem });
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(384, 24);
			this->menuStrip2->TabIndex = 1;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// FileToolStripMenuItem
			// 
			this->FileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->LoadVectorToolStripMenuItem,
					this->loadMatrixToolStripMenuItem
			});
			this->FileToolStripMenuItem->Name = L"FileToolStripMenuItem";
			this->FileToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->FileToolStripMenuItem->Text = L"File";
			// 
			// LoadVectorToolStripMenuItem
			// 
			this->LoadVectorToolStripMenuItem->Name = L"LoadVectorToolStripMenuItem";
			this->LoadVectorToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->LoadVectorToolStripMenuItem->Text = L"Load Vector";
			this->LoadVectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::LoadVectorToolStripMenuItem_Click);
			// 
			// loadMatrixToolStripMenuItem
			// 
			this->loadMatrixToolStripMenuItem->Name = L"loadMatrixToolStripMenuItem";
			this->loadMatrixToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->loadMatrixToolStripMenuItem->Text = L"Load Matrix";
			this->loadMatrixToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::LoadMatrixToolStripMenuItem_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 24);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(384, 338);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->InputLabel);
			this->flowLayoutPanel1->Controls->Add(this->Input);
			this->flowLayoutPanel1->Controls->Add(this->VectorLabel);
			this->flowLayoutPanel1->Controls->Add(this->VectorList);
			this->flowLayoutPanel1->Location = System::Drawing::Point(195, 3);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(186, 332);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// InputLabel
			// 
			this->InputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->InputLabel->AutoSize = true;
			this->InputLabel->Font = (gcnew System::Drawing::Font(L"�L�n������", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->InputLabel->Location = System::Drawing::Point(3, 0);
			this->InputLabel->Name = L"InputLabel";
			this->InputLabel->Size = System::Drawing::Size(41, 16);
			this->InputLabel->TabIndex = 0;
			this->InputLabel->Text = L"Input";
			// 
			// Input
			// 
			this->Input->Location = System::Drawing::Point(3, 19);
			this->Input->Multiline = true;
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(180, 158);
			this->Input->TabIndex = 1;
			this->Input->TextChanged += gcnew System::EventHandler(this, &WindowsForm::Input_TextChanged_Vector);
			this->Input->TextChanged += gcnew System::EventHandler(this, &WindowsForm::Input_TextChanged_Matrix);
			// 
			// VectorLabel
			// 
			this->VectorLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->VectorLabel->AutoSize = true;
			this->VectorLabel->Font = (gcnew System::Drawing::Font(L"�L�n������", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->VectorLabel->Location = System::Drawing::Point(3, 180);
			this->VectorLabel->Name = L"VectorLabel";
			this->VectorLabel->Size = System::Drawing::Size(47, 16);
			this->VectorLabel->TabIndex = 2;
			this->VectorLabel->Text = L"Vector";
			// 
			// VectorList
			// 
			this->VectorList->FormattingEnabled = true;
			this->VectorList->ItemHeight = 12;
			this->VectorList->Location = System::Drawing::Point(3, 199);
			this->VectorList->Name = L"VectorList";
			this->VectorList->Size = System::Drawing::Size(180, 124);
			this->VectorList->TabIndex = 3;
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->OutputLabel);
			this->flowLayoutPanel2->Controls->Add(this->Output);
			this->flowLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(186, 332);
			this->flowLayoutPanel2->TabIndex = 1;
			// 
			// OutputLabel
			// 
			this->OutputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OutputLabel->AutoSize = true;
			this->OutputLabel->Font = (gcnew System::Drawing::Font(L"�L�n������", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->OutputLabel->Location = System::Drawing::Point(3, 0);
			this->OutputLabel->Name = L"OutputLabel";
			this->OutputLabel->Size = System::Drawing::Size(52, 16);
			this->OutputLabel->TabIndex = 0;
			this->OutputLabel->Text = L"Output";
			// 
			// Output
			// 
			this->Output->Font = (gcnew System::Drawing::Font(L"�s�ө���", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Output->Location = System::Drawing::Point(3, 19);
			this->Output->Multiline = true;
			this->Output->Name = L"Output";
			this->Output->ReadOnly = true;
			this->Output->Size = System::Drawing::Size(183, 313);
			this->Output->TabIndex = 1;
			// 
			// openVectorFileDialog
			// 
			this->openVectorFileDialog->FileName = L"openVectorFileDialog";
			this->openVectorFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &WindowsForm::openVectorFileDialog_FileOk);
			// 
			// openMatrixFileDialog
			// 
			this->openMatrixFileDialog->FileName = L"openMatrixFileDialog";
			this->openMatrixFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &WindowsForm::openMatrixFileDialog_FileOk);
			// 
			// WindowsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 362);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip2);
			this->Name = L"WindowsForm";
			this->Text = L"VectorExample";
			this->Load += gcnew System::EventHandler(this, &WindowsForm::WindowsForm_Load);
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void WindowsForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
	private: System::Void LoadVectorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//�}��Dialog
		nowMode = VECTOR_MODE;
		openVectorFileDialog->ShowDialog();
	}
	private: System::Void LoadMatrixToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//�}��Dialog
		nowMode = MATRIX_MODE;
		openMatrixFileDialog->ShowDialog();
	}
	private: System::Void Input_TextChanged_Vector(System::Object^  sender, System::EventArgs^  e)
	{
		if (nowMode != VECTOR_MODE)
			return;

		// �� File ��� Load Vector ��, this->Input->TextChanged �ƥ�|���榹 function
		//��Input textbox������J���ܮɡA�K�|�i�J���禡
		//�P�_��J�ۤ���'\n'�A�è������r��-1��m
		if (Input->Text->Length - 1 >= 0 && Input->Text[Input->Text->Length - 1] == '\n')
		{
			//���o�V�q���
			std::vector<Vector> vectors = dataManager->GetVectors();
			//�w�N��X�Ȧs	
			String^ outputTemp = "";
			//�N�ϥΪ̿�J�r��(�buserInput��)�A�̲Ĥ@�Ӫťդ��Φ���Ӥl�r��
			array<Char>^ delims = { ' ' };
			array<String^> ^userCommand = userInput->Split(delims, 2);
			//�r�����A�Y���O��"print"�����p
			try
			{
				if (userCommand[0] == "print")
				{
					//�浹DataManager�B�z
					Vector result = dataManager->Calculate(userCommand[1]);
					//��X
					outputTemp += "[";
					for (unsigned int i = 0; i < result.Data.size(); ++i)
					{
						outputTemp += result.Data[i].ToString();
						if (i != result.Data.size() - 1)
							outputTemp += ",";
					}
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "norm")
				{
					//���浹DataManager�B�z�̭�
					Vector temp = dataManager->Calculate(userCommand[1]);
					//��X
					outputTemp += "[";
					outputTemp += gcnew String(std::to_string(temp.norm()).c_str());
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "normal")
				{
					//���浹DataManager�B�z�̭�
					Vector temp = dataManager->Calculate(userCommand[1]);
					//��X
					outputTemp += "[";
					outputTemp += gcnew String(std::to_string(temp.normal()).c_str());
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "cross")
				{
					// cross(A, B)
					// ���� A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B ���O�浹DataManager�B�z
					Vector variable_a = dataManager->Calculate(variables[0]);
					Vector variable_b = dataManager->Calculate(variables[1]);
					//��X
					outputTemp += "[";
					Vector result = cross(variable_a, variable_b);
					for (unsigned int i = 0; i < result.Data.size(); ++i)
					{
						outputTemp += result.Data[i].ToString();
						if (i != result.Data.size() - 1)
							outputTemp += ",";
					}
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "com")
				{
					// com(A, B)
					// ���� A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B ���O�浹DataManager�B�z
					Vector variable_a = dataManager->Calculate(variables[0]);
					Vector variable_b = dataManager->Calculate(variables[1]);
					//��X
					outputTemp += "[";
					outputTemp += gcnew String(std::to_string(com(variable_a, variable_b)).c_str());
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "proj")
				{
					// proj(A, B)
					// ���� A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B ���O�浹DataManager�B�z
					Vector variable_a = dataManager->Calculate(variables[0]);
					Vector variable_b = dataManager->Calculate(variables[1]);
					//��X
					outputTemp += "[";
					Vector result = proj(variable_a, variable_b);
					for (unsigned int i = 0; i < result.Data.size(); ++i)
					{
						outputTemp += result.Data[i].ToString();
						if (i != result.Data.size() - 1)
							outputTemp += ",";
					}
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "area")
				{
					// area(A, B)
					// ���� A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B ���O�浹DataManager�B�z
					Vector variable_a = dataManager->Calculate(variables[0]);
					Vector variable_b = dataManager->Calculate(variables[1]);
					//��X
					outputTemp += "[";
					outputTemp += gcnew String(std::to_string(area(variable_a, variable_b)).c_str());
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "isparallel")
				{
					// isparallel(A, B)
					// ���� A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B ���O�浹DataManager�B�z
					Vector variable_a = dataManager->Calculate(variables[0]);
					Vector variable_b = dataManager->Calculate(variables[1]);
					//��X
					if (isparallel(variable_a, variable_b))
					{
						outputTemp += "Yes";
					}
					else
					{
						outputTemp += "No";
					}
					outputTemp += Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "isorthogonal")
				{
					// isorthogonal(A, B)
					// ���� A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B ���O�浹DataManager�B�z
					Vector variable_a = dataManager->Calculate(variables[0]);
					Vector variable_b = dataManager->Calculate(variables[1]);
					//��X
					if (isorthogonal(variable_a, variable_b))
					{
						outputTemp += "Yes";
					}
					else
					{
						outputTemp += "No";
					}
					outputTemp += Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "angle")
				{
					// angle(A, B)
					// ���� A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B ���O�浹DataManager�B�z
					Vector variable_a = dataManager->Calculate(variables[0]);
					Vector variable_b = dataManager->Calculate(variables[1]);
					//��X
					outputTemp += "theta = ";
					outputTemp += gcnew String(std::to_string(angle(variable_a, variable_b)).c_str());
					outputTemp += Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "pn")
				{
					// pn(A, B)
					// ���� A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B ���O�浹DataManager�B�z
					Vector variable_a = dataManager->Calculate(variables[0]);
					Vector variable_b = dataManager->Calculate(variables[1]);
					//��X
					outputTemp += "[";
					Vector result = pn(variable_a, variable_b);
					for (unsigned int i = 0; i < result.Data.size(); ++i)
					{
						outputTemp += result.Data[i].ToString();
						if (i != result.Data.size() - 1)
							outputTemp += ",";
					}
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "isli")
				{
					// isli(A, B)
					// ���� A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B ���O�浹DataManager�B�z
					Vector variable_a = dataManager->Calculate(variables[0]);
					Vector variable_b = dataManager->Calculate(variables[1]);
					//��X
					if (isln(variable_a, variable_b))
					{
						outputTemp += "Y";
					}
					else
					{
						outputTemp += "N";
					}
					outputTemp += Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "ob")
				{
					// ob(A, B, ....)
					// �̾� ',' ����
					std::vector<Vector> vectors, result;
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims);
					// �Ҧ� variable ���O�浹 DataManager �B�z
					for (unsigned int i = 0; i < variables->Length; ++i)
					{
						vectors.push_back(dataManager->Calculate(variables[i]));
					}
					result = ob(vectors);
					//��X
					outputTemp += "normal " + result.size().ToString() + Environment::NewLine;
					for (unsigned int i = 0; i < result.size(); ++i)
					{
						outputTemp += "[";
						for (unsigned int j = 0; j < result[i].Data.size(); ++j)
						{
							outputTemp += result[i].Data[j].ToString();
							if (j != result[i].Data.size() - 1)
								outputTemp += ",";
						}
						outputTemp += "]" + Environment::NewLine;
					}
					outputTemp += Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				//���S�� �h�P�_�䤣����O
				else
				{
					Output->AppendText("-Command not found-" + Environment::NewLine);
				}
			}
			catch (VECTOR_ERROR e)
			{
				switch (e)
				{
				case VECTOR_ERROR::DIMENSION_NON_EQUIVALENT:
					Output->AppendText("Error: Dimension non equivalent.");
					break;
				}
			}
			userInput = "";
		}
		else
		{
			//�N�ϥΪ̿�J�r��(�bText box��)�A��'\n'�@����
			array<String^> ^userCommand = Input->Text->Split('\n');
			//�ñN�̫�@��A�@���ثe�ϥΪ̿�J���O
			userInput = userCommand[userCommand->Length - 1];
		}

	}
	private: System::Void Input_TextChanged_Matrix(System::Object^  sender, System::EventArgs^  e) 
	{
		if (nowMode != MATRIX_MODE)
			return;
		// �� File ��� Load Matrix ��, this->Input->TextChanged �ƥ�|���榹 function
	}
	private: System::Void openVectorFileDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
	{
		//�bDialog���UOK�K�|�i�J���禡
		//�r�����string^ to string
		std::string tempFileName;
		MarshalString(openVectorFileDialog->FileName, tempFileName);
		//�N�ɮ׸��|�W�ٶǤJdataManager
		dataManager->SetFileName(tempFileName);
		//�qŪ��Ū���V�q���
		if (dataManager->LoadVectorData())
		{
			//�NVectorList�����إ����M��
			VectorList->Items->Clear();
			//���o�Ҧ��V�q���
			std::vector<Vector> vectors = dataManager->GetVectors();

			for (unsigned int i = 0; i < vectors.size(); i++)
			{
				//���خ榡:
				// name(dimension) [data1, data2, ...]

				//�N�ɮצW�٦s�J�Ȧs
				std::string tempString = vectors[i].Name;
				//�N��X�榡�s�J�Ȧs
				tempString += "(";
				//�N�V�q���צs�J�Ȧs
				tempString += std::to_string(vectors[i].Data.size());
				//�N��X�榡�s�J�Ȧs
				tempString += ") [";
				//�N�V�q��Ʀs�J�Ȧs
				for (unsigned int j = 0; j < vectors[i].Data.size(); j++)
				{
					std::string scalarString = std::to_string(vectors[i].Data[j]);
					tempString += scalarString.substr(0, scalarString.size() - 5);
					if (j != vectors[i].Data.size() - 1)
						tempString += ",";
				}
				//�N��X�榡�s�J�Ȧs
				tempString += "]";
				//�N���إ[�JVectorList��
				VectorList->Items->Add(gcnew String(tempString.c_str()));
			}
			Output->AppendText("-Vector datas have been loaded-" + Environment::NewLine);
		}
	}
	private: System::Void openMatrixFileDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}
};
}
