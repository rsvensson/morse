#include "window.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_morseEdit(new QLineEdit),
    m_textEdit(new QLineEdit)
{
    setWindowLayout();

    connect(m_textEdit, &QLineEdit::textChanged,
	    this, &MainWindow::textToMorse);
    connect(m_morseEdit, &QLineEdit::textChanged,
	    this, &MainWindow::morseToText);

    this->show();
}

void MainWindow::setWindowLayout()
{
    QWidget *mainWidget = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(new QLabel("Text"));
    mainLayout->addWidget(m_textEdit);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(new QLabel("Morse"));
    mainLayout->addWidget(m_morseEdit);
    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);
    this->setMinimumWidth(320);
}

void MainWindow::textToMorse()
{
    if (m_textEdit->hasFocus()) {
	QString text = m_textEdit->text();
	QString morse;

	try {
	    morse = QString::fromStdString(lettersToMorse(text.toStdString()));
	} catch (int e) {
	    m_morseEdit->setText("Invalid text input (Only A-Z and 0-9 allowed)");
	    return;
	}

	m_morseEdit->setText(morse);
    }

}

void MainWindow::morseToText()
{
    if (m_morseEdit->hasFocus()) {
	QString morse = m_morseEdit->text();
	QString text;

	try {
	    text = QString::fromStdString(morseToLetters(morse.toStdString()));
	} catch (int e) {
	    m_textEdit->setText("Invalid morse code input (Only '.', '-', and ' ' allowed)");
	    return;
	}

	m_textEdit->setText(text);
    }
}
