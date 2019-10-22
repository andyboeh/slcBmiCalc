#include <QtCore>
#include <QtGui>
#include <QApplication>
#include <QMessageBox>
#include "slcCalcGui.h"
#include "slcBmiCalc.h"
#include "slcBmiMfCalc.h"
#include "slcBmiAgeCalc.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    slcCalcGui g;

    return app.exec();
}


slcCalcGui::slcCalcGui(QWidget *parent) : QWidget(parent), m_Ui(new Ui::slcCalcGui)
{
    m_Ui->setupUi(this);
    setWindowTitle("SLC Calculator");
    m_ComboBoxItems.clear();
    m_ComboBoxItems.append("BMI Standard");
    m_ComboBoxItems.append("BMI m/f");
    m_ComboBoxItems.append("BMI age");
    m_Ui->cmbCalcType->clear();
    m_Ui->cmbCalcType->addItems(m_ComboBoxItems);
    m_Ui->cmbCalcType->setCurrentIndex(0);
    // Build the combo box here
    m_Ui->spinHeight->setMinimum(0.0);
    m_Ui->spinHeight->setMaximum(2.5);
    m_Ui->spinWeight->setMinimum(0.0);
    m_Ui->spinWeight->setMaximum(300.0);
    m_Ui->spinAge->setMinimum(1);
    m_Ui->spinAge->setMaximum(130);
    m_Ui->spinAge->setEnabled(false);
    QStringList genderItems;
    genderItems.append("male");
    genderItems.append("female");
    m_Ui->cmbGender->clear();
    m_Ui->cmbGender->addItems(genderItems);
    m_Ui->cmbGender->setEnabled(false);
    connect(m_Ui->btnCalc, SIGNAL(clicked(bool)), this, SLOT(onCalcButtonClicked()));
    connect(m_Ui->cmbCalcType, SIGNAL(currentIndexChanged(int)), this, SLOT(onCmbCalcTypeIndexChanged(int)));
    show();
}

void slcCalcGui::onCmbCalcTypeIndexChanged(int idx)
{
    switch(idx)
    {
    case 0:   // BMI Standard
        m_Ui->spinAge->setEnabled(false);
        m_Ui->cmbGender->setEnabled(false);
        break;
    case 1:   // BMI m/f
        m_Ui->spinAge->setEnabled(false);
        m_Ui->cmbGender->setEnabled(true);
        break;
    case 2:   // BMI Age
        m_Ui->spinAge->setEnabled(true);
        m_Ui->cmbGender->setEnabled(false);
        break;
    default:
        m_Ui->spinAge->setEnabled(false);
        m_Ui->cmbGender->setEnabled(false);

    }
}

void slcCalcGui::onCalcButtonClicked()
{
    QString calcType = m_Ui->cmbCalcType->currentText();
    float weight = m_Ui->spinWeight->value();
    float height = m_Ui->spinHeight->value();

    if(weight <= 0 || height <= 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Weight and Height must be greater than 0");
        msgBox.setInformativeText("Enter correct values.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }

    if(calcType == "BMI Standard")
    {
        slcBmiCalc calc;
        float ret = calc.calcBmi(weight, height);
        QMessageBox msgBox;
        msgBox.setText("Results");
        msgBox.setInformativeText("The BMI was calculated as " + QString::number(ret));
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
    else if(calcType == "BMI m/f")
    {
        slcBmiMfCalc calc;
        float ret = calc.calcBmi(weight, height);
        int gender = m_Ui->cmbGender->currentIndex();
        if(gender == 0)
            calc.setGender(slcBmiMfCalc::GENDER_MALE);
        else
            calc.setGender(slcBmiMfCalc::GENDER_FEMALE);
        QString res = calc.getTextForResult();
        QMessageBox msgBox;
        msgBox.setText("Results");
        msgBox.setInformativeText("The BMI was calculated as " + QString::number(ret) + "\n" +
                                  "This is considered " + res);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
    else if(calcType == "BMI age")
    {
        slcBmiAgeCalc calc;
        float ret = calc.calcBmi(weight, height);
        int age = m_Ui->spinAge->value();
        calc.setAge(age);
        QString res = calc.getTextForResult();
        QMessageBox msgBox;
        msgBox.setText("Results");
        msgBox.setInformativeText("The BMI was calculated as " + QString::number(ret) + "\n" +
                                  "This is considered " + res);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Select valid calculation type");
        msgBox.setInformativeText("Select a valid calculation type and re-try the calculation");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
}

slcCalcGui::~slcCalcGui()
{

}
