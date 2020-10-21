// Joan Andrés (@Andres6936) Github.

#ifndef GT_FILETABLEWIDGET_HPP
#define GT_FILETABLEWIDGET_HPP

#include <QWidget>
#include <QTreeView>
#include <QFileSystemModel>

namespace Gt
{
	class FileTableWidget : public QTreeView
	{

		Q_OBJECT

	private:

		QFileSystemModel *table {};

	public:

		explicit FileTableWidget(QWidget* parent = nullptr) noexcept;

		void addEntry(const QString& name, const QString& path) const noexcept;

	signals:

	};
}

#endif //GT_FILETABLEWIDGET_HPP
