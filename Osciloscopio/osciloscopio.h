#ifndef OSCILOSCOPIO_H
#define OSCILOSCOPIO_H

#include <QMainWindow>

namespace Ui {
class Osciloscopio;
}

class Osciloscopio : public QMainWindow
{
    Q_OBJECT

public:
    explicit Osciloscopio(QWidget *parent = 0);
    ~Osciloscopio();

    int  ch1 , ch2, ch;
    long off, esc, x, y;
    bool a;
    void autoset();
    void canal1(bool);
    void canal2(bool);
    void escala(int,long);
    void eixo_x(int,int);
    void eixo_y(int, int y);
    void offset(int,long);

private slots:
    void on_pushButton_clicked();

    void on_canal1_clicked();

    void on_canal2_clicked();

    void on_ok_clicked();

private:
    Ui::Osciloscopio *ui;

};

#endif // OSCILOSCOPIO_H
 /* AUToset
  * CHANnel<X>:DISPlay
  * CHANnel<X>:OFFSet
  * CHANnel<X>:SCALe
  * CURSor:X<X>Position
  * CURSor:Y<X>Position
  */
