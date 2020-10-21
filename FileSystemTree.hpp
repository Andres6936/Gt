// Joan Andrés (@Andres6936) Github.

#ifndef GT_FILESYSTEMTREE_HPP
#define GT_FILESYSTEMTREE_HPP

#include <QWidget>
#include <QTreeView>
#include <QFileSystemModel>

namespace Gt
{
	class FileSystemTree : public QTreeView
	{

		Q_OBJECT

	private:

		QFileSystemModel *fileSystem {};

	public:

		explicit FileSystemTree(QWidget* parent = nullptr) noexcept;

		void addEntry(const QString& name, const QString& path) const noexcept;

	signals:

	};
}

#endif //GT_FILESYSTEMTREE_HPP
