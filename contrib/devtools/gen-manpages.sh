#!/usr/bin/env bash
# Copyright (c) 2016-2020 The C1pzo Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

C1PZOD=${C1PZOD:-$BINDIR/c1pzod}
C1PZOCLI=${C1PZOCLI:-$BINDIR/c1pzo-cli}
C1PZOTX=${C1PZOTX:-$BINDIR/c1pzo-tx}
WALLET_TOOL=${WALLET_TOOL:-$BINDIR/c1pzo-wallet}
C1PZOUTIL=${C1PZOQT:-$BINDIR/c1pzo-util}
C1PZOQT=${C1PZOQT:-$BINDIR/qt/c1pzo-qt}

[ ! -x $C1PZOD ] && echo "$C1PZOD not found or not executable." && exit 1

# Don't allow man pages to be generated for binaries built from a dirty tree
DIRTY=""
for cmd in $C1PZOD $C1PZOCLI $C1PZOTX $WALLET_TOOL $C1PZOUTIL $C1PZOQT; do
  VERSION_OUTPUT=$($cmd --version)
  if [[ $VERSION_OUTPUT == *"dirty"* ]]; then
    DIRTY="${DIRTY}${cmd}\n"
  fi
done
if [ -n "$DIRTY" ]
then
  echo -e "WARNING: the following binaries were built from a dirty tree:\n"
  echo -e $DIRTY
  echo "man pages generated from dirty binaries should NOT be committed."
  echo "To properly generate man pages, please commit your changes to the above binaries, rebuild them, then run this script again."
fi

# The autodetected version git tag can screw up manpage output a little bit
read -r -a PZOVER <<< "$($C1PZOCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }')"

# Create a footer file with copyright content.
# This gets autodetected fine for c1pzod if --version-string is not set,
# but has different outcomes for c1pzo-qt and c1pzo-cli.
echo "[COPYRIGHT]" > footer.h2m
$C1PZOD --version | sed -n '1!p' >> footer.h2m

for cmd in $C1PZOD $C1PZOCLI $C1PZOTX $WALLET_TOOL $C1PZOUTIL $C1PZOQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${PZOVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${PZOVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
