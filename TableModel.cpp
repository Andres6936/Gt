// Joan Andrés (@Andres6936) Github.

#include "TableModel.hpp"

using namespace Gt;

Gt::TableModel::TableModel(QObject* parent) noexcept : QAbstractTableModel(parent)
{

}

TableModel::TableModel(const QVector<File>& files, QObject* parent) noexcept
	: QAbstractTableModel(parent), files(files)
{

}

int TableModel::rowCount(const QModelIndex& parent) const
{
	return parent.isValid() ? 0 : files.size();
}

int TableModel::columnCount(const QModelIndex& parent) const
{
	// Value is always 2 because we only need space for the Name and Path columns.
	return parent.isValid() ? 0 : 2;
}

bool TableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	return QAbstractItemModel::setData(index, value, role);
}

bool TableModel::insertRows(int row, int count, const QModelIndex& parent)
{
	return QAbstractItemModel::insertRows(row, count, parent);
}

bool TableModel::removeRows(int row, int count, const QModelIndex& parent)
{
	return QAbstractItemModel::removeRows(row, count, parent);
}

/**
 * The data() function returns either a Name or Path, based on the contents of
 * 	the model index supplied.
 *
 * The row number stored in the model index is used to reference an item in the
 * 	list of contacts. Selection is handled by the QItemSelectionModel, which
 * 	will be explained with more later.
 */
QVariant TableModel::data(const QModelIndex& index, int role) const
{
	if (not index.isValid())
	{
		return QVariant{};
	}

	if (index.row() >= files.size() or index.row() < 0)
	{
		return QVariant{};
	}

	if (role == Qt::DisplayRole)
	{
		const File& file = files.at(index.row());

		switch (index.column())
		{
		case 0:
			return file.name;
		case 1:
			return file.path;
		default:
			break;
		}
	}

	return QVariant{};
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role not_eq Qt::DisplayRole)
	{
		return QVariant{};
	}

	if (orientation == Qt::Horizontal)
	{
		switch (section)
		{
		case 0:
			return tr("Name");
		case 1:
			return tr("Path");
		default:
			break;
		}
	}

	return QVariant{};
}

Qt::ItemFlags TableModel::flags(const QModelIndex& index) const
{
	return QAbstractTableModel::flags(index);
}

const QVector<File>& TableModel::getFiles() const noexcept
{
	return files;
}
