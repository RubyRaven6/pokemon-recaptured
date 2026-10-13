# Friend Safari Design Notes

This document details the decisions made to keep this fork (https://github.com/friend-safari/pokeemerald-expansion) as organic as possible, for maximum transparency.

Any potentially objectionable code that's been retained is detailed here.

## 1.16.3

- [10415](https://github.com/rh-hideout/pokeemerald-expansion/pull/10415) was disclosed as being assisted by Claude Code.
However the change is a bugfix that is trivial/irreducible; it removes more lines than it adds, and the only material change is to the bounds of a `for` loop.

Because of this, it's been included as-is, rather than reimplementing it.