#!/bin/bash

# Script to search upstream PRs since a merge base for strings
# Requires the GitHub CLI: https://cli.github.com/
# Use like:
# ./find_prs.sh 'FOO' upstream
# export MERGE_BASE=HEAD~10
# ./find_prs.sh 'BAR' custom-remote -w # Extra args passed to gh CLI
# Author: aarant

set -e # exit on (e)rror
# set -x

SEARCH_STRING="$1"
shift
REMOTE_NAME=${1:-upstream}
[[ "$REMOTE_NAME" != "upstream" ]] && shift
FETCH_URL=$(git remote get-url --no-push "$REMOTE_NAME")
# Find upstream repository
REPO=$(echo "$FETCH_URL" | sed -E -e 's#.*github.com:(.+)\.git#\1#')

UPSTREAM_DEFAULT=$(git rev-parse --abbrev-ref "$REMOTE_NAME/HEAD")
# Allow custom merge base
[[ -z "$MERGE_BASE" ]] && MERGE_BASE=$(git merge-base @ "$UPSTREAM_DEFAULT")

# %cs = (c)ommitted date, (s)hort
SINCE=$(git log -1 --format='%cs' "$MERGE_BASE")
echo "Merge base:"
git log -1 "$MERGE_BASE"

# See https://cli.github.com/manual/gh_search_prs
# Trace e(x)ecution
(set -x; gh search prs "$SEARCH_STRING" --repo "$REPO" --created=">=$SINCE" --sort created $@)

set +x
