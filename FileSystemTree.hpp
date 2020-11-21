// Joan Andrés (@Andres6936) Github.

#ifndef GT_FILESYSTEMTREE_HPP
#define GT_FILESYSTEMTREE_HPP

#include <QWidget>
#include <QString>
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

		// Construct

		explicit FileSystemTree(QWidget* parent = nullptr) noexcept;

		// Methods

		/**
		 * Display the content of particular directory.
		 *
		 * @param path to new directory to show.
		 */
		void openDirectory(const QString& path) noexcept;

		// Methods Const

		void addEntry(const QString& name, const QString& path) const noexcept;

	signals:

	};
}

#endif //GT_FILESYSTEMTREE_HPP
