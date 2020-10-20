// Joan Andrés (@Andres6936) Github.

#include <QHeaderView>

#include "FileTableWidget.hpp"

using namespace Gt;

FileTableWidget::FileTableWidget(QWidget* parent) noexcept
	: QTableView(parent), table(new TableModel(this))
{
	this->setModel(table);
	this->setSelectionBehavior(QAbstractItemView::SelectRows);
	this->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->setSelectionMode(QAbstractItemView::SingleSelection);
	this->setSortingEnabled(false);

	setupTableStyle();

	connect(this->selectionModel(), &QItemSelectionModel::selectionChanged,
			this, &FileTableWidget::selectionChanged);
}

void FileTableWidget::setupTableStyle() const noexcept
{
	this->horizontalHeader()->setStretchLastSection(true);
}

void FileTableWidget::addEntry(const QString& name, const QString& path) const noexcept
{
	table->insertRows(0, 1, QModelIndex{});

	QModelIndex index = table->index(0, 0, QModelIndex{});
	table->setData(index, name, Qt::EditRole);

	index = table->index(0, 1, QModelIndex{});
	table->setData(index, path, Qt::EditRole);
}
