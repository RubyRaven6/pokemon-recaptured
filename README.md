# <project name>

This is an [organic](https://github.com/friend-safari) fork of the upstream project at <upstream>,
modified to have only human contributions.

See [PEOPLE.md](PEOPLE.md) for a list of human contributors.

## Templating

```bash
set -e # exit on (e)rror
# Find and replace origin repo URL
ORIGIN_NAME=origin
PUSH_URL=$(git remote get-url --push "$ORIGIN_NAME")
PUSH_REPO=$(echo "$PUSH_URL" | sed -E -e 's#.*github.com:(.+)\.git#\1#')
sed -E -i -e "s#<origin>#[$PUSH_REPO](https://github.com/$PUSH_REPO)#g" *.md
sed -E -i -e "s#<issues>#[Issues](https://github.com/$PUSH_REPO/issues)#g" *.md

# Find and replace upstream URL
UPSTREAM_NAME=upstream
FETCH_URL=$(git remote get-url --no-push "$UPSTREAM_NAME")
UPSTREAM_REPO=$(echo "$FETCH_URL" | sed -E -e 's#.*github.com:(.+)\.git#\1#')
sed -E -i -e "s#<upstream>#[$UPSTREAM_REPO](https://github.com/$UPSTREAM_REPO)#g" *.md

# List any other to-be-replaced tags
grep -P '<\w+>' *.md

# Remove any 'Templating' Markdown sections
sed -Ezi -e 's/## Templat[^#]+//' *.md
```

## Contributing

See [CONTRIBUTING.md]

## Contact

- **Discord**: [discord.gg/Mc94Zs8DXK](https://discord.gg/Mc94Zs8DXK)