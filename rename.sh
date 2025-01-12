#!/bin/sh
 
git filter-branch --env-filter '
 
OLD_EMAIL="r.alvarez@RAlvarezs-iMac.local"
CORRECT_NAME="RubyRaven6"
CORRECT_EMAIL="swampertspawner@gmail.com"

if [ "$GIT_COMMITTER_EMAIL" = "$OLD_EMAIL" ]
then
    export GIT_COMMITTER_NAME="$CORRECT_NAME"
    export GIT_COMMITTER_EMAIL="$CORRECT_EMAIL"
fi
if [ "$GIT_AUTHOR_EMAIL" = "$OLD_EMAIL" ]
then
    export GIT_AUTHOR_NAME="$CORRECT_NAME"
    export GIT_AUTHOR_EMAIL="$CORRECT_EMAIL"
fi
' --tag-name-filter cat -- --branches --tags 0c8526b707b1f2069417223470f7bec0a374bbaa..HEAD