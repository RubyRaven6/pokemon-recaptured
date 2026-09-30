#!/bin/bash

# Searches PRs on a remote for Discord contact info,
# and builds a mailmap file based on their last associated email.
# See https://git-scm.com/docs/gitmailmap
# Use like:
# ./make_discord_mailmap.sh <remote> > discord.mailmap

# Requires the GitHub CLI: https://cli.github.com/

set -e # exit on (e)

# Set up aliases;
# Search for commits by discord username with: `git disclog --author username`
# (trace within subshell)
(set -x; git config alias.disclog '!git -c mailmap.file=discord.mailmap log --mailmap $@')
(set -x; git config alias.disclol '!git -c mailmap.file=discord.mailmap lol --mailmap $@')

[[ -f discord.mailmap ]] && echo "discord.mailmap already exists; exiting" && exit 0

REMOTE_NAME=${1:-upstream}
[[ "$REMOTE_NAME" != "upstream" ]] && shift
FETCH_URL=$(git remote get-url --no-push "$REMOTE_NAME")
# Find upstream repository
REPO=$(echo "$FETCH_URL" | sed -E -e 's#.*github.com:(.+)\.git#\1#')

# See https://jqlang.org/manual/#regular-expressions
PR_AUTHORS=$(gh search prs --repo "$REPO" --limit 1000 $@ --json body,author --jq \
'.[] | [.author.id, .author.login, (.body | match("Discord\\s+contact(\\s+info)?\\r?\\n\\s*@?(\\S+)"; "i")).captures[1].string] | @csv'
)
# sort Unique by Key 1 only
U_PR_AUTHORS=$(echo "$PR_AUTHORS" | sort -u -k 1,1)
# Generate mailmap lines
while read -r line; do
    IFS=',' read -r id gh_username discord <<< "$line"
    # See https://cli.github.com/manual/gh_search_commits
    author_email=$(gh search commits --author "${gh_username//\"/}" --json commit --jq '.[0] | .commit.author.email')
    # process Escape sequences, remove " from vars
    echo -e "# ${gh_username//\"/}\n${discord//\"/} <$author_email>"
done <<< "$U_PR_AUTHORS"

set +x
