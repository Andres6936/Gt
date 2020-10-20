// Joan Andrés (@Andres6936) Github.

#ifndef GT_FILETABLEWIDGET_HPP
#define GT_FILETABLEWIDGET_HPP

#include <QWidget>
#include <QTabWidget>

#include "TableModel.hpp"

namespace Gt
{
	class FileTableWidget : public QTabWidget
	{

		Q_OBJECT

	private:

		TableModel *table {};

	public:

		explicit FileTableWidget(QWidget* parent = nullptr) noexcept;

	};
}

#endif //GT_FILETABLEWIDGET_HPP
