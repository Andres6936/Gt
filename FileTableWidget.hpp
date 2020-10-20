// Joan Andrés (@Andres6936) Github.

#ifndef GT_FILETABLEWIDGET_HPP
#define GT_FILETABLEWIDGET_HPP

#include <QWidget>
#include <QTableView>

#include "TableModel.hpp"

namespace Gt
{
	class FileTableWidget : public QTableView
	{

		Q_OBJECT

	private:

		TableModel *table {};

		void setupTableStyle() const noexcept;

	public:

		explicit FileTableWidget(QWidget* parent = nullptr) noexcept;

	signals:

	};
}

#endif //GT_FILETABLEWIDGET_HPP
