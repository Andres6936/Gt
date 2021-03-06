// Joan Andrés (@Andres6936) Github.

#include <iostream>

#include "Status.hpp"

using namespace Gt;

// Construct

Status::Status(git_repository* _repository)
{
	// The documentation allow initialize the object with
	// GIT_STATUS_OPTIONS_INIT or the method git_status_options_init
	git_status_options options = GIT_STATUS_OPTIONS_INIT;

	options.show = GIT_STATUS_SHOW_INDEX_AND_WORKDIR;
	options.flags = GIT_STATUS_OPT_INCLUDE_UNTRACKED;
	options.flags |= GIT_STATUS_OPT_RENAMES_HEAD_TO_INDEX;
	options.flags |= GIT_STATUS_OPT_SORT_CASE_SENSITIVELY;

	// Gather file status information and populate the git_status_list.
	if (const int state = git_status_list_new(&status, _repository, &options); state not_eq 0)
	{
		std::cerr << "Not is possible get the status of repository.\n";
	}
}

// Destructor

Status::~Status()
{
	git_status_list_free(status);
}

// Methods

std::vector<std::string> Status::getUntrackedFiles()
{
	std::vector<std::string> results;

	// If there are no changes in status (at least according the options given
	// when the status list was created), this can return 0.
	const std::size_t MAXIMUM_INDEX = git_status_list_entrycount(status);

	for (std::size_t index = 0; index < MAXIMUM_INDEX; ++index)
	{
		// The entry is not modifiable and should not be freed.
		const git_status_entry* entry = git_status_byindex(status, index);

		if (entry->status == GIT_STATUS_CURRENT) continue;

		// Print untracked files.
		if (entry->status == GIT_STATUS_WT_NEW)
		{
			results.push_back(entry->index_to_workdir->old_file.path);
		}
	}

	return results;
}
