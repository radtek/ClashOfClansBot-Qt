#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ClashOfClansBot.h"

class ClashOfClansBot : public QMainWindow
{
	Q_OBJECT

public:
	ClashOfClansBot(QWidget *parent = Q_NULLPTR);

private:
	Ui::ClashOfClansBotClass ui;
};
