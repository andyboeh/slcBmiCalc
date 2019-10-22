#ifndef SLCCALCGUI_H
#define SLCCALCGUI_H

#include <QtGui>
#include <QtCore>
#include <QMap>
#include "ui_slcCalcGui.h"


/**
 * @brief Simple BMI Calculator GUI
 * @author Andreas Böhler
 * @date 2015/05/02
 */
 
/*
 * Simple BMI Calculator for demonstration purposes only.
 * (c) 2015 - Andreas Böhler, R'n'B Medical Software Consulting GmbH
 * For lecture use only.
 * Normal values are taken from bmi-rechner.net
 *
 * License: WTFPL
 *
 */
 
class slcCalcGui : public QWidget
{
    Q_OBJECT
public:
    slcCalcGui(QWidget *parent = NULL);
    ~slcCalcGui();

private slots:
    /**
      * Called whenver the "calculate" button is clicked. It does the
      * GUI logic behind the scenes.
      */
    void onCalcButtonClicked();
    /**
      * Called whenever the current index of the calculation type combo-box
      * changes. Used to update the GUI based on the selected calculation type.
      * @param idx The new index
      */
    void onCmbCalcTypeIndexChanged(int idx);
private:
    Ui::slcCalcGui* m_Ui; ///< Holds a reference to the current user interface
    QList<QString> m_ComboBoxItems; ///< A QStringList with the combo box items


};

#endif //SLCCALCGUI_H
