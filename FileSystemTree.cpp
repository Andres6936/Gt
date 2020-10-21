// Joan Andrés (@Andres6936) Github.

#include <QHeaderView>

#include "FileSystemTree.hpp"

using namespace Gt;

FileSystemTree::FileSystemTree(QWidget* parent) noexcept
	: QTreeView(parent), fileSystem(new QFileSystemModel())
{
	fileSystem->setRootPath(QDir::currentPath());

	this->setModel(fileSystem);
	this->setSelectionBehavior(QAbstractItemView::SelectRows);
	this->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->setSelectionMode(QAbstractItemView::SingleSelection);
	this->setSortingEnabled(false);

	connect(this->selectionModel(), &QItemSelectionModel::selectionChanged,
			this, &FileSystemTree::selectionChanged);
}

void FileSystemTree::addEntry(const QString& name, const QString& path) const noexcept
{
	fileSystem->insertRows(0, 1, QModelIndex{});

	QModelIndex index = fileSystem->index(0, 0, QModelIndex{});
	fileSystem->setData(index, name, Qt::EditRole);

	index = fileSystem->index(0, 1, QModelIndex{});
	fileSystem->setData(index, path, Qt::EditRole);
}
