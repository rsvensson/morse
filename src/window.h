#ifndef WINDOW_H
#define WINDOW_H

#include "translator.h"
#include <QMainWindow>
#include <QLineEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void textToMorse();
    void morseToText();

private:
    Translator *m_translator;
    QLineEdit *m_morseEdit;
    QLineEdit *m_textEdit;

    void setWindowLayout();
};

#endif
