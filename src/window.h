#ifndef WINDOW_H
#define WINDOW_H

#include "translator.h"
#include <QMainWindow>
#include <QLineEdit>

class MainWindow : public QMainWindow, Translator
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void textToMorse();
    void morseToText();

private:
    QLineEdit *m_morseEdit;
    QLineEdit *m_textEdit;

    void setWindowLayout();
};

#endif
