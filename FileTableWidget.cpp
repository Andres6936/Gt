// Joan Andrés (@Andres6936) Github.

#include "FileTableWidget.hpp"

using namespace Gt;

FileTableWidget::FileTableWidget(QWidget* parent) noexcept
	: QTableView(parent), table(new TableModel(this))
{
	this->setModel(table);
}