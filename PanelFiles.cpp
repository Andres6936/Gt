// Joan Andrés (@Andres6936) Github.

#include <git2.h>
#include <qdebug.h>

#include "PanelFiles.hpp"

using namespace Gt;

PanelFiles::PanelFiles(QWidget *parent) noexcept : QWidget(parent)
{
	mainLayout = new QVBoxLayout(this);
	fileSystem = new FileSystemTree(this);

	mainLayout->addWidget(fileSystem);

	this->setLayout(mainLayout);

	git_repository* repository = nullptr;

	if (const int status = git_repository_init(&repository, "./Test/Curriculum", false))
	{
		const git_error* error = git_error_last();
		qWarning() << "Not is possible init the directory.";
	}

	git_status_options options = GIT_STATUS_OPTIONS_INIT;
	options.show = GIT_STATUS_SHOW_INDEX_AND_WORKDIR;
	options.flags = GIT_STATUS_OPT_INCLUDE_UNTRACKED;
	options.flags |= GIT_STATUS_OPT_RENAMES_HEAD_TO_INDEX;
	options.flags |= GIT_STATUS_OPT_SORT_CASE_SENSITIVELY;

	git_status_list* statusList = nullptr;

	if (const int status = git_status_list_new(&statusList, repository, &options))
	{
		qWarning() << "Not is possible get the status of repository.";
	}

	const std::size_t MAXIMUM_INDEX = git_status_list_entrycount(statusList);

	for (std::size_t index = 0; index < MAXIMUM_INDEX; ++index)
	{
		const git_status_entry* entry = git_status_byindex(statusList, index);

		if (entry->status == GIT_STATUS_CURRENT) continue;

		if (entry->status & GIT_STATUS_INDEX_NEW)
		{
			qWarning() << "New file: ";
		}

		if (entry->status & GIT_STATUS_INDEX_MODIFIED)
		{
			qWarning() << "Modified: ";
		}

		if (entry->status & GIT_STATUS_INDEX_DELETED)
		{
			qWarning() << "Deleted: ";
		}

		if (entry->status & GIT_STATUS_INDEX_RENAMED)
		{
			qWarning() << "Renamed: ";
		}

		if (entry->status & GIT_STATUS_INDEX_TYPECHANGE)
		{
			qWarning() << "Type Change: ";
		}

		// Print untracked files.
		if (entry->status == GIT_STATUS_WT_NEW)
		{
			qWarning() << entry->index_to_workdir->old_file.path;
		}
	}

	git_status_list_free(statusList);
	git_repository_free(repository);
}
