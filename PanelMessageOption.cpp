// Joan Andrés (@Andres6936) Github.

#include "PanelMessageOption.hpp"

#include <QHBoxLayout>
#include <QPushButton>

using namespace Gt;

PanelMessageOption::PanelMessageOption(QWidget* parent) noexcept : QWidget(parent)
{
	auto mainLayout = new QHBoxLayout(this);
	auto commitButton = new QPushButton("Commit", this);

	mainLayout->addWidget(commitButton);

	this->setLayout(mainLayout);
}
