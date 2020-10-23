// Joan Andrés (@Andres6936) Github.

#include "PanelMessageOption.hpp"

#include <QMenu>
#include <QHBoxLayout>
#include <QPushButton>

using namespace Gt;

PanelMessageOption::PanelMessageOption(QWidget* parent) noexcept : QWidget(parent)
{
	auto mainLayout = new QHBoxLayout(this);
	auto commitButton = new QPushButton("Commit", this);
	auto commitAndPush = new QMenu( this);
	commitAndPush->addAction("Commit and Push");

	commitButton->setMenu(commitAndPush);

	mainLayout->addWidget(commitButton);

	this->setLayout(mainLayout);
}
