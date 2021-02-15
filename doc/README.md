C1pzo Core
=============

Setup
---------------------
C1pzo Core is the original C1pzo client and it builds the backbone of the network. It downloads and, by default, stores the entire history of C1pzo transactions, which requires a few hundred gigabytes of disk space. Depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more.

To download C1pzo Core, visit [c1pzocore.org](https://c1pzocore.org/en/download/).

Running
---------------------
The following are some helpful notes on how to run C1pzo Core on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/c1pzo-qt` (GUI) or
- `bin/c1pzod` (headless)

### Windows

Unpack the files into a directory, and then run c1pzo-qt.exe.

### macOS

Drag C1pzo Core to your applications folder, and then run C1pzo Core.

### Need Help?

* See the documentation at the [C1pzo Wiki](https://en.c1pzo.it/wiki/Main_Page)
for help and more information.
* Ask for help on [#c1pzo](https://webchat.freenode.net/#c1pzo) on Freenode. If you don't have an IRC client, use [webchat here](https://webchat.freenode.net/#c1pzo).
* Ask for help on the [C1pzoTalk](https://c1pzotalk.org/) forums, in the [Technical Support board](https://c1pzotalk.org/index.php?board=4.0).

Building
---------------------
The following are developer notes on how to build C1pzo Core on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [Dependencies](dependencies.md)
- [macOS Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [FreeBSD Build Notes](build-freebsd.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [NetBSD Build Notes](build-netbsd.md)
- [Gitian Building Guide (External Link)](https://github.com/c1pzo-core/docs/blob/master/gitian-building.md)

Development
---------------------
The C1pzo repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Productivity Notes](productivity.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://doxygen.c1pzocore.org/)
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [JSON-RPC Interface](JSON-RPC-interface.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)
- [Benchmarking](benchmarking.md)

### Resources
* Discuss on the [C1pzoTalk](https://c1pzotalk.org/) forums, in the [Development & Technical Discussion board](https://c1pzotalk.org/index.php?board=6.0).
* Discuss project-specific development on #c1pzo-core-dev on Freenode. If you don't have an IRC client, use [webchat here](https://webchat.freenode.net/#c1pzo-core-dev).
* Discuss general C1pzo development on #c1pzo-dev on Freenode. If you don't have an IRC client, use [webchat here](https://webchat.freenode.net/#c1pzo-dev).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [c1pzo.conf Configuration File](c1pzo-conf.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [Reduce Memory](reduce-memory.md)
- [Reduce Traffic](reduce-traffic.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)
- [ZMQ](zmq.md)
- [PSBT support](psbt.md)

License
---------------------
Distributed under the [MIT software license](/COPYING).
