// Joan Andrés (@Andres6936) Github.

#ifndef GT_TABLEMODEL_HPP
#define GT_TABLEMODEL_HPP

#include <QObject>
#include <QVector>
#include <QVariant>
#include <QModelIndex>
#include <QAbstractTableModel>

#include "File.hpp"

namespace Gt
{
	class TableModel : public QAbstractTableModel
	{

		Q_OBJECT

	private:

		QVector<File> files;

	public:

		explicit TableModel(QObject *parent = nullptr) noexcept;

		explicit TableModel(const QVector<File>& files, QObject *parent = nullptr) noexcept;

		int rowCount(const QModelIndex& parent) const override;

		int columnCount(const QModelIndex& parent) const override;

		bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

		bool insertRows(int position, int rows, const QModelIndex& parent = QModelIndex{}) override;

		bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex{}) override;

		QVariant data(const QModelIndex& index, int role) const override;

		QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

		Qt::ItemFlags flags(const QModelIndex& index) const override;

		const QVector<File>& getFiles() const noexcept;

	};
}


#endif //GT_TABLEMODEL_HPP
