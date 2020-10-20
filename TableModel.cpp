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
	// Value is always 2 because we only need space for the Name and Path
	// 	columns.
	return parent.isValid() ? 0 : 2;
}

bool TableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	return QAbstractItemModel::setData(index, value, role);
}

/**
 * The insertRows() function is called before new data is added, otherwise the
 * 	data will not be displayed.
 */
bool TableModel::insertRows(int position, int rows, const QModelIndex& parent)
{
	beginInsertRows(QModelIndex{}, position, position + rows - 1);

	for (int row = 0; row < rows; ++row)
	{
		files.insert(position, {QString{}, QString{}});
	}

	endInsertRows();
	return true;
}

/**
 * The removeRows() function is called to remove data. Again, beginRemoveRows()
 * 	and endRemoveRows() are called to ensure all connected views are aware of
 * 	the changes.
 */
bool TableModel::removeRows(int position, int rows, const QModelIndex& parent)
{
	beginRemoveRows(QModelIndex{}, position, position + rows - 1);

	for (int row = 0; row < rows; ++row)
	{
		files.removeAt(position);
	}

	endRemoveRows();
	return true;
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
