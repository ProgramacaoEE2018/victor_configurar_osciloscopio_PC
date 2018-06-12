#include "osciloscopio.h"
#include "ui_osciloscopio.h"


Osciloscopio::Osciloscopio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Osciloscopio)
{
    ui->setupUi(this);
    int d=1;
    for (int i; i<8; i++)
    {
        if(i<3)
        {
            float k=0.002;
            ui->escala1->addItem(QString::number(k*d));
            ui->escala2->addItem(QString::number(k*d));
            ui->offset1->addItem(QString::number(k*d));
            ui->offset2->addItem(QString::number(k*d));
        }
        d=d*5;
        if(i==3)
        {
            ui->escala1->addItem("0,1");
            ui->escala2->addItem("0,1");
            ui->offset1->addItem("0,1");
            ui->offset2->addItem("0,1");
        }
        if(i==4)
        {
            ui->escala1->addItem("0,5");
            ui->escala2->addItem("0,5");
            ui->offset1->addItem("0,5");
            ui->offset2->addItem("0,5");
        }
        if(i==5)
        {
            ui->escala1->addItem("1");
            ui->escala2->addItem("1");
            ui->offset1->addItem("1");
            ui->offset2->addItem("1");
        }
        if(i==6)
        {
            ui->escala1->addItem("5");
            ui->escala2->addItem("5");
            ui->offset1->addItem("5");
            ui->offset2->addItem("5");
        }
        if(i==7)
        {
            ui->escala1->addItem("10");
            ui->escala2->addItem("10");
            ui->offset1->addItem("10");
            ui->offset2->addItem("10");
        }
    }
    for(i=1; i<250; i++)
    {
        ui->x1->addItem(QString::number(i));
        ui->x2->addItem(QString::number(i));
    }
    for(i=1; i<200; i++)
    {
        ui->y1->addItem(QString::number(i));
        ui->y2->addItem(QString::number(i));
    }
}

void Osciloscopio::autoset()
{
    //Manda pro oscilospio a função ':autoset pro osciloscopio'
}

void Osciloscopio::canal1(bool)
{

    //Liga ou desliga o canal
    // Manda a função ':channel1:display<a>'
}

void Osciloscopio::canal2(bool)
{

    //Liga ou desliga o canal
    // Manda a função ':channel<2>:display<a>'
}

void Osciloscopio::escala(int, long)
{
    //Recebe o canal e seta a escala, mandando a função ':channel<ch>:scale<esc>'
}

void Osciloscopio::offset(int, long)
{
    //Recebe o canal e seta o offset, mandando a função ':channel<ch>:offset<esc>'
}

void Osciloscopio::eixo_x(int, int)
{
    //Recebe o canal e seta o ponto coordenada escolhida no eixo x entre 1 e 249
    // Função ':cursor:x<ch>position <x>'
}

void Osciloscopio::eixo_y(int, int)
{
    //Recebe o canal e seta o ponto coordenada escolhida no eixo x entre 1 e 249
    // Função ':cursor:y<ch>position <y>'
}

Osciloscopio::~Osciloscopio()
{
    delete ui;
}

void Osciloscopio::on_pushButton_clicked()
{
       Osciloscopio::autoset();
}


void Osciloscopio::on_canal1_clicked()
{
   if( ui->canal1->isChecked())
   {
       Osciloscopio::canal1(1);
   }
   else
   {
       Osciloscopio::canal1(0);
   }
}


void Osciloscopio::on_canal2_clicked()
{
    if( ui->canal2->isChecked())
    {
        Osciloscopio::canal2(1);
    }
    else
    {
        Osciloscopio::canal2(0);
    }
}


void Osciloscopio::on_ok_clicked()
{
    if(ui->canal1->clicked())
        ch = 1;
    if(ui->canal2->clicked())
        ch=2;
   //Agora precisaria pegar os valores do Qcombobox para setar a nova configuração
}
