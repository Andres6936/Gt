// Joan Andrés (@Andres6936) Github.

#include <iostream>
#include <stdexcept>
#include "Repository.hpp"

using namespace Gt;

// Construct

Repository::Repository(std::string_view path)
{
	if (const int status = git_repository_open(&repository, path.data()))
	{
		std::cerr << "Not is possible open the directory.\n";
	}
}

// Destructor

Gt::Repository::~Repository()
{
	git_repository_free(repository);
}

// Methods

std::vector<std::string> Repository::getUntrackedFiles()
{
	std::vector<std::string> results;

	git_status_options options = GIT_STATUS_OPTIONS_INIT;
	options.show = GIT_STATUS_SHOW_INDEX_AND_WORKDIR;
	options.flags = GIT_STATUS_OPT_INCLUDE_UNTRACKED;
	options.flags |= GIT_STATUS_OPT_RENAMES_HEAD_TO_INDEX;
	options.flags |= GIT_STATUS_OPT_SORT_CASE_SENSITIVELY;

	git_status_list* statusList = nullptr;

	if (const int status = git_status_list_new(&statusList, repository, &options))
	{
		throw std::runtime_error("Not is possible get the status of repository.");
	}

	const std::size_t MAXIMUM_INDEX = git_status_list_entrycount(statusList);

	for (std::size_t index = 0; index < MAXIMUM_INDEX; ++index)
	{
		const git_status_entry* entry = git_status_byindex(statusList, index);

		if (entry->status == GIT_STATUS_CURRENT) continue;

		// Print untracked files.
		if (entry->status == GIT_STATUS_WT_NEW)
		{
			results.push_back(entry->index_to_workdir->old_file.path);
		}
	}

	git_status_list_free(statusList);
	return results;
}
