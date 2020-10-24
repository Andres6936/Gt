// Joan Andrés (@Andres6936) Github.

#include "PanelMessageOption.hpp"

#include <QMenu>
#include <QEvent>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QToolButton>

#include <qdebug.h>

using namespace Gt;

PanelMessageOption::PanelMessageOption(QWidget* parent) noexcept : QWidget(parent)
{
	auto mainLayout = new QHBoxLayout(this);

	auto commitAndPush = new QMenu( this);
	commitAndPush->addAction("Commit and Push");

	commitButton = new QPushButton("Commit", this);
	commitButton->setMenu(commitAndPush);

	auto amendCheckBox = new QCheckBox("Amend", this);

	auto commitMessageHistory = new QToolButton(this);
	auto showCommitOptions = new QToolButton(this);

	mainLayout->addWidget(commitButton);
	mainLayout->addWidget(amendCheckBox);
	mainLayout->addWidget(commitMessageHistory);
	mainLayout->addWidget(showCommitOptions);

	this->setLayout(mainLayout);
	this->installEventFilter(this);
}

bool PanelMessageOption::eventFilter(QObject* _object, QEvent* _event)
{
	if (_object == this)
	{
		if (_event->type() == QEvent::Enter)
		{
			commitButton->setStyleSheet("background-color: #4B97D9; color: white; font-weight: bold;");
		}
	}

	return false;
}
