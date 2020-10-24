// Joan Andrés (@Andres6936) Github.

#include "PanelMessageOption.hpp"

#include <QMenu>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QToolButton>

using namespace Gt;

PanelMessageOption::PanelMessageOption(QWidget* parent) noexcept : QWidget(parent)
{
	auto mainLayout = new QHBoxLayout(this);

	auto commitAndPush = new QMenu( this);
	commitAndPush->addAction("Commit and Push");

	auto commitButton = new QPushButton("Commit", this);
	commitButton->setMenu(commitAndPush);

	auto amendCheckBox = new QCheckBox("Amend", this);

	auto commitMessageHistory = new QToolButton(this);
	auto showCommitOptions = new QToolButton(this);

	mainLayout->addWidget(commitButton);
	mainLayout->addWidget(amendCheckBox);
	mainLayout->addWidget(commitMessageHistory);
	mainLayout->addWidget(showCommitOptions);

	this->setLayout(mainLayout);
}
