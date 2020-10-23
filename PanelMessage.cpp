// Joan Andrés (@Andres6936) Github.

#include "PanelMessage.hpp"
#include "PanelMessageOption.hpp"

#include <QTextEdit>
#include <QVBoxLayout>

using namespace Gt;

PanelMessage::PanelMessage(QWidget* parent) noexcept : QWidget(parent)
{
	auto panelOptions = new PanelMessageOption(this);
	auto mainLayout = new QVBoxLayout(this);
	auto message = new QTextEdit(this);
	message->setPlaceholderText("Commit Message");

	mainLayout->addWidget(message);
	mainLayout->addWidget(panelOptions);

	this->setLayout(mainLayout);
}
