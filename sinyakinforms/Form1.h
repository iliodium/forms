#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <iostream>
#include <fstream>
/*
#include <clocale>
#include <string>  
#include "stdafx.h"
#include <conio.h>
*/
int NC;

struct z{
	char name[20];
	long summa;
	long reiting;
	char date_start[20];
	char date_end[20];
	char tarif[20];
} *clients;

struct sp {
	char fio[20];
	long summa;
	char namesam[20];
	struct sp* sled;	
} *spisok;

struct sp_obr {
	char fio_obr[20];
	long summa_obr;
	struct sp_obr* sled_obr;
		} *spisok_obr;

void vstavka(struct z* client,char* fio)
{
	int i;
	struct sp *nov,*nt,*z=0;
	for(nt=spisok; nt!=0 && strcmp(nt->fio,fio)<0; z=nt, nt=nt->sled);
	if(nt && strcmp(nt->fio,fio)==0) return;
	nov=(struct sp *) malloc(sizeof(struct sp));
	strcpy(nov->fio,fio);
	nov->sled=nt;
	nov->summa=0;
	for(i=0;i<NC;i++){
		if(strcmp(client[i].name,fio)==0)
			nov->summa+=client[i].summa;
	}
	if(!z) spisok=nov;
	else z->sled=nov;
	return;
}


void vstavka_obr(struct z* client,char* fio_obr)
{
	int i;
	struct sp_obr *nov_obr,*nt_obr,*z=0;
	for(nt_obr=spisok_obr; nt_obr!=0 && strcmp(nt_obr->fio_obr,fio_obr)>0; z=nt_obr, nt_obr=nt_obr->sled_obr);
	if(nt_obr && strcmp(nt_obr->fio_obr,fio_obr)==0) return;
	nov_obr=(struct sp_obr *) malloc(sizeof(struct sp_obr));
	strcpy(nov_obr->fio_obr,fio_obr);
	nov_obr->sled_obr=nt_obr;
	nov_obr->summa_obr=0;
	for(i=0;i<NC;i++){
		if(strcmp(client[i].name,fio_obr)==0)
			nov_obr->summa_obr+=client[i].summa;
	}
	if(!z) spisok_obr=nov_obr;
	else z->sled_obr=nov_obr;
	return;
}
void text_data(char *s,char *sd)
{
int N_month;
char s0[3],month[12][9]={
"января","февраля","марта","апреля","мая","июня",
"июля","августа","сентября","октября","ноября","декабря"
		};
strcpy(s,sd+8);
strcat(s," ");
strncpy(s0,sd+5,2);
s0[2]=0;
sscanf(s0,"%d",&N_month);
strcat(s,month[N_month-1]);
strcat(s," ");
strncat(s,sd,4);
return;
}

namespace sinyakinforms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  открытьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  вопросыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  максимальнаяСуммаАрендыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  алфавитныйПорядокToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  самаяПерваяАрендаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  расширенныйТарифСОдинаковойСуммойToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  диаграммаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  обратныйАлфавитныйПорядокToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  самаяПоследняяАредаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  худшийРейтингToolStripMenuItem;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вопросыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->максимальнаяСуммаАрендыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->алфавитныйПорядокToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->самаяПерваяАрендаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->расширенныйТарифСОдинаковойСуммойToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->диаграммаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->обратныйАлфавитныйПорядокToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->самаяПоследняяАредаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->худшийРейтингToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->файлToolStripMenuItem, 
				this->вопросыToolStripMenuItem, this->выходToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(622, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->открытьToolStripMenuItem});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// открытьToolStripMenuItem
			// 
			this->открытьToolStripMenuItem->Name = L"открытьToolStripMenuItem";
			this->открытьToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->открытьToolStripMenuItem->Text = L"Открыть";
			this->открытьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::открытьToolStripMenuItem_Click);
			// 
			// вопросыToolStripMenuItem
			// 
			this->вопросыToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->максимальнаяСуммаАрендыToolStripMenuItem, 
				this->алфавитныйПорядокToolStripMenuItem, this->самаяПерваяАрендаToolStripMenuItem, this->расширенныйТарифСОдинаковойСуммойToolStripMenuItem, 
				this->диаграммаToolStripMenuItem, this->обратныйАлфавитныйПорядокToolStripMenuItem, this->самаяПоследняяАредаToolStripMenuItem, 
				this->худшийРейтингToolStripMenuItem});
			this->вопросыToolStripMenuItem->Enabled = false;
			this->вопросыToolStripMenuItem->Name = L"вопросыToolStripMenuItem";
			this->вопросыToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->вопросыToolStripMenuItem->Text = L"Вопросы";
			// 
			// максимальнаяСуммаАрендыToolStripMenuItem
			// 
			this->максимальнаяСуммаАрендыToolStripMenuItem->Name = L"максимальнаяСуммаАрендыToolStripMenuItem";
			this->максимальнаяСуммаАрендыToolStripMenuItem->Size = System::Drawing::Size(316, 22);
			this->максимальнаяСуммаАрендыToolStripMenuItem->Text = L"Максимальная сумма аренды";
			this->максимальнаяСуммаАрендыToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::максимальнаяСуммаАрендыToolStripMenuItem_Click);
			// 
			// алфавитныйПорядокToolStripMenuItem
			// 
			this->алфавитныйПорядокToolStripMenuItem->Name = L"алфавитныйПорядокToolStripMenuItem";
			this->алфавитныйПорядокToolStripMenuItem->Size = System::Drawing::Size(316, 22);
			this->алфавитныйПорядокToolStripMenuItem->Text = L"Алфавитный порядок";
			this->алфавитныйПорядокToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::алфавитныйПорядокToolStripMenuItem_Click);
			this->алфавитныйПорядокToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::обратныйАлфавитныйПорядокToolStripMenuItem_Click);
			
			// 
			// самаяПерваяАрендаToolStripMenuItem
			// 
			this->самаяПерваяАрендаToolStripMenuItem->Name = L"самаяПерваяАрендаToolStripMenuItem";
			this->самаяПерваяАрендаToolStripMenuItem->Size = System::Drawing::Size(316, 22);
			this->самаяПерваяАрендаToolStripMenuItem->Text = L"Самая первая аренда";
			this->самаяПерваяАрендаToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::самаяПерваяАрендаToolStripMenuItem_Click);
			// 
			// расширенныйТарифСОдинаковойСуммойToolStripMenuItem
			// 
			this->расширенныйТарифСОдинаковойСуммойToolStripMenuItem->Name = L"расширенныйТарифСОдинаковойСуммойToolStripMenuItem";
			this->расширенныйТарифСОдинаковойСуммойToolStripMenuItem->Size = System::Drawing::Size(316, 22);
			this->расширенныйТарифСОдинаковойСуммойToolStripMenuItem->Text = L"Расширенный тариф с одинаковой суммой";
			this->расширенныйТарифСОдинаковойСуммойToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::расширенныйТарифСОдинаковойСуммойToolStripMenuItem_Click);
			// 
			// диаграммаToolStripMenuItem
			// 
			this->диаграммаToolStripMenuItem->Name = L"диаграммаToolStripMenuItem";
			this->диаграммаToolStripMenuItem->Size = System::Drawing::Size(316, 22);
			this->диаграммаToolStripMenuItem->Text = L"Диаграмма";
			this->диаграммаToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::диаграммаToolStripMenuItem_Click);
			// 
			// обратныйАлфавитныйПорядокToolStripMenuItem
			// 
			this->обратныйАлфавитныйПорядокToolStripMenuItem->Name = L"обратныйАлфавитныйПорядокToolStripMenuItem";
			this->обратныйАлфавитныйПорядокToolStripMenuItem->Size = System::Drawing::Size(316, 22);
			this->обратныйАлфавитныйПорядокToolStripMenuItem->Text = L"Обратный алфавитный порядок";
			this->обратныйАлфавитныйПорядокToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::алфавитныйПорядокToolStripMenuItem_Click);
			this->обратныйАлфавитныйПорядокToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::обратныйАлфавитныйПорядокToolStripMenuItem_Click);
			
			// 
			// самаяПоследняяАредаToolStripMenuItem
			// 
			this->самаяПоследняяАредаToolStripMenuItem->Name = L"самаяПоследняяАредаToolStripMenuItem";
			this->самаяПоследняяАредаToolStripMenuItem->Size = System::Drawing::Size(316, 22);
			this->самаяПоследняяАредаToolStripMenuItem->Text = L"Самая последняя ареда";
			this->самаяПоследняяАредаToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::самаяПоследняяАредаToolStripMenuItem_Click);
			// 
			// худшийРейтингToolStripMenuItem
			// 
			this->худшийРейтингToolStripMenuItem->Name = L"худшийРейтингToolStripMenuItem";
			this->худшийРейтингToolStripMenuItem->Size = System::Drawing::Size(316, 22);
			this->худшийРейтингToolStripMenuItem->Text = L"Худший рейтинг";
			this->худшийРейтингToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::худшийРейтингToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::выходToolStripMenuItem_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->tabControl1->Location = System::Drawing::Point(13, 28);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(597, 405);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(589, 379);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Исходные данные";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 14;
			this->listBox1->Location = System::Drawing::Point(0, -1);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(589, 368);
			this->listBox1->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->richTextBox2);
			this->tabPage2->Controls->Add(this->richTextBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 23);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(589, 378);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Список";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(280, 3);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(309, 376);
			this->richTextBox2->TabIndex = 1;
			this->richTextBox2->Text = L"";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(0, 3);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(274, 380);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(589, 379);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Диаграмма";
			this->tabPage3->UseVisualStyleBackColor = true;
			this->tabPage3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::tabPage3_Paint);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(622, 445);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Курсовая";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void выходToolStripMenuItem_Click
	(
	System::Object^ sender,
	System::EventArgs^ e
	)
		{
		this->Close();
		}

private: System::Void открытьToolStripMenuItem_Click
	(
	System::Object^ sender,
	System::EventArgs^ e
	)
{
FILE *in;
int i;
char ctemp[200];
String ^s;
if ((in=fopen("client_info.dat","r"))==NULL)
	{
	MessageBox::Show("Файл не открыт!",
					"Ошибка!",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
	return;
	}

вопросыToolStripMenuItem->Enabled=true;
listBox1->Items->Clear();
fscanf(in,"%d",&NC);
clients = new z[NC];


for(i=0;i<NC;i++)
	{
	fscanf(in,"%s%ld%ld%s%s%s",clients[i].name, &clients[i].summa,
			&clients[i].reiting, clients[i].date_start, clients[i].date_end, clients[i].tarif);
	sprintf(ctemp,"%-15s %-8ld %-3ld %15s %15s %15s",clients[i].name, clients[i].summa,
			clients[i].reiting, clients[i].date_start, clients[i].date_end, clients[i].tarif);
	s=gcnew String(ctemp);
	listBox1->Items->Add(s);
	}
fclose(in);
}

		 
private: System::Void алфавитныйПорядокToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
			 {
	int i;
	struct sp* nt;
	char ss[80];
	String ^s;
	tabControl1->SelectTab(1); // переходим на вкладку "СПИСОК"
	if(!spisok)
		{
		for(i=0;i<NC;i++)
			vstavka(clients,clients[i].name);
		}
	richTextBox1->ReadOnly=1;
	richTextBox1->Clear();
	richTextBox1->Text ="\nАлфавитный список\n======================\n";
	for(nt=spisok; nt!=0; nt=nt->sled)
		{
		sprintf(ss,"%-15s %8ld",nt->fio,nt->summa);
		s=gcnew String(ss,0,31);
		richTextBox1->Text = richTextBox1->Text+"\n"+s;
		}
	}

private: System::Void обратныйАлфавитныйПорядокToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
			 {
	int i;
	struct sp_obr* nt_obr;
	char ss[80];
	String ^s;
	tabControl1->SelectTab(1); // переходим на вкладку "СПИСОК"
	if(!spisok_obr)
		{
		for(i=0;i<NC;i++)
			vstavka_obr(clients,clients[i].name);
		}
	richTextBox2->ReadOnly=1;
	richTextBox2->Clear();
	richTextBox2->Text ="\nОбратный алфавитный список\n==========================\n";
	for(nt_obr=spisok_obr; nt_obr!=0; nt_obr=nt_obr->sled_obr)
		{
		sprintf(ss,"%-15s %8ld",nt_obr->fio_obr,nt_obr->summa_obr);
		s=gcnew String(ss,0,31);
		richTextBox2->Text = richTextBox2->Text+"\n"+s;
		}
	}
private: System::Void максимальнаяСуммаАрендыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
	int i=0;
	struct z best;
	char ss[80];
	String ^s;
	strcpy(best.name,clients[0].name);
	best.summa=clients[0].summa;
	for(i=1;i<NC;i++)
	if (clients[i].summa>best.summa)
	{
	strcpy(best.name,clients[i].name);
	best.summa=clients[i].summa;
	}
	sprintf(ss,"%s\n %ld рублей",best.name,best.summa);
	s=gcnew String(ss);
	MessageBox::Show(s,"Максимальная сумма аренды");
	}



private: System::Void худшийРейтингToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
	int i=0;
	struct z best;
	char ss[80];
	String ^s;
	strcpy(best.name,clients[0].name);
	best.reiting=clients[0].reiting;
	for(i=1;i<NC;i++)
		if (clients[i].reiting<best.reiting)
		{
			strcpy(best.name,clients[i].name);
			best.reiting=clients[i].reiting;
		}
	sprintf(ss,"%s\n %ld / 100",best.name,best.reiting);
	s=gcnew String(ss);
	MessageBox::Show(s,"Худший рейтинг");
	}

private: System::Void расширенныйТарифСОдинаковойСуммойToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		 {
	int i=0,j=0, flag=0;
	struct z best;
	struct z best2;
	char ss[80];
	String ^s;
	best.reiting=clients[0].reiting;
	for(i=0;i<NC-1;i++)
		for(j=i+1;j<NC;j++)
		if (strcmp(clients[i].tarif,"Расширенный")==0 && strcmp(clients[j].tarif,"Расширенный")==0 && clients[i].summa==clients[j].summa)
		{
			strcpy(best.name,clients[i].name);
			strcpy(best2.name,clients[j].name);
			best.summa=clients[i].summa;
			flag=1;
			break;
		}
		if (flag==1){
			sprintf(ss,"Есть:\n%s\n%s\nСумма: %ld",best.name,best2.name,best.summa);
			s=gcnew String(ss);
			MessageBox::Show(s,"Ответ");
		}
		else{
			sprintf(ss,"Нет");
			s=gcnew String(ss);
			MessageBox::Show(s,"Ответ");
		}
		}

private: System::Void самаяПерваяАрендаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
int i;
char sd[17];
char ss[80];
String ^s;
struct z* best=clients;
for(i=1;i<NC;i++)
if (strcmp(clients[i].date_start,best->date_start)<0) best=&clients[i];
text_data(sd,best->date_start);
sprintf(ss,"%s\n%s\n%ld Сумма\nОткрыт %s",
best->name,best->tarif, best->summa,sd);
s=gcnew String(ss);
MessageBox::Show(s,"Самая первая аренда");
}

private: System::Void самаяПоследняяАредаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
int i;
char sd[17];
char ss[80];
String ^s;
struct z* best=clients;
for(i=1;i<NC;i++)
if (strcmp(clients[i].date_end,best->date_end)>0) best=&clients[i];
text_data(sd,best->date_end);
sprintf(ss,"%s\n%s\n%ld Сумма\nОткрыт %s",
best->name,best->tarif, best->summa,sd);
s=gcnew String(ss);
MessageBox::Show(s,"Самая поздняя аренда");
}




private: System::Void диаграммаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{	
tabControl1->SelectTab(2);
}

private: System::Void tabPage3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{

Pen ^myPen= gcnew Pen(System::Drawing::Color::Black,3);
SolidBrush ^myBrush= gcnew SolidBrush(Color::FromArgb(196,0,0,0));
System::Drawing::Font^ myFont=gcnew System::Drawing::Font("Arial",8);
int i,K;
int iRed,iGreen,iBlue;
int aStart,aEnd;
long Sum;
float xPos,yPos;
struct sp *nt;
Graphics ^g=tabPage3->CreateGraphics();
g->Clear(System::Drawing::Color::White);

if(!spisok)
	{
	for(i=0;i<NC;i++)
		vstavka(clients,clients[i].name);
	}
K=0; 
Sum=0;
for(nt=spisok; nt!=0; nt=nt->sled)
	{
	K++;
	Sum+=nt->summa;
	}
g->DrawEllipse(myPen,25,25,185,185);
aEnd=0;
for(nt=spisok,i=0; nt!=0; nt=nt->sled,i++)
	{
	iRed=(((i+1)&4)>0)*255/(i/8+1);
	iGreen=(((i+1)&2)>0)*255/(i/8+1);
	iBlue=(((i+1)&1)>0)*255/(i/8+1);
	aStart=aEnd;
	aEnd+=nt->summa*360/Sum;
	if(i==K-1)aEnd=360;
	myBrush->Color::set(Color::FromArgb(196,iRed,iGreen,iBlue));
	g->FillPie(myBrush,25,25,185,185,aStart,aEnd-aStart);
	g->FillRectangle(myBrush,300,50+(i-1)*20,20,20);
	myBrush->Color::set(Color::FromArgb(196,0,0,0));
	xPos=30+(185-25)/2+(185-25)/1.5*Math::Cos(Math::PI*(aStart+aEnd)/360);
	yPos=30+(185-25)/2+(185-25)/1.5*Math::Sin(Math::PI*(aStart+aEnd)/360);
	g->DrawString(gcnew String(nt->fio),myFont,myBrush,320,55+(i-1)*20);
	g->DrawString(Convert::ToString(nt->summa*100/Sum)+"%",
	myFont,myBrush,xPos,yPos);
	}
}


	};
}

